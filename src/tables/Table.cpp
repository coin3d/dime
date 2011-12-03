/**************************************************************************\
 * Copyright (c) Kongsberg Oil & Gas Technologies AS
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 
 * Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
\**************************************************************************/

/*!
  \class dimeTable dime/tables/Table.h
  \brief The dimeTable class stores table entries.

  This class will not be allocated by the memory handler, but it will
  store a pointer to the memory handler, and it will be used to allocate
  table entries and records.
*/

#include <dime/tables/Table.h>
#include <dime/tables/TableEntry.h>
#include <dime/records/Record.h>
#include <dime/records/StringRecord.h>
#include <dime/Input.h>
#include <dime/Output.h>
#include <dime/util/MemHandler.h>
#include <dime/Model.h>

#include <string.h>

/*!
  Constructor.
*/

dimeTable::dimeTable(dimeMemHandler * const memhandler)
  : maxEntries( 0 ), tablename(NULL), memHandler( memhandler )
{
}

/*!
  Destructor.
*/

dimeTable::~dimeTable()
{
  int i;
  if (!this->memHandler) {
    for (i = 0; i < this->tableEntries.count(); i++) {
      delete this->tableEntries[i];
    }
    for (i = 0; i < this->records.count(); i++) {
      delete this->records[i];
    }
    delete[] this->tablename;
  }
}

//!

dimeTable *
dimeTable::copy(dimeModel * const model) const
{
  dimeMemHandler *memh = model->getMemHandler();
  int i;
  dimeTable * t = new dimeTable(memh);
  int n = this->records.count();
  if (n) {
    t->records.makeEmpty(n);
    for (i = 0; i < n; i++) {
      t->records.append(this->records[i]->copy(memh));
    }
  }
  n = this->tableEntries.count();
  if (n) {
    t->tableEntries.makeEmpty(n);
    for (i = 0; i < n; i++) {
      t->tableEntries.append(this->tableEntries[i]->copy(model));
    }
  }

  if (this->tablename) t->setTableName(this->tablename);

  return t;
}

/*!
  Reads a table.
*/

bool
dimeTable::read(dimeInput * const file)
{
  int32 groupcode;
  dimeRecord *record = NULL;
  bool ok = true;
  dimeMemHandler *memh = file->getMemHandler();
  
  do { 
    if (!file->readGroupCode(groupcode)) {ok = false; break;}
    if (groupcode == 70) {
      if (!file->readInt16(this->maxEntries)) {ok = false; break;}
    }
    else if (groupcode == 2) {
      const char * s = file->readString();
      if (!s) { ok = false; break; }
      this->setTableName(s);
    }
    else if (groupcode != 0) {
      record = dimeRecord::createRecord(groupcode, memh);
      if (!record || !record->read(file)) {ok = false; break;}
      records.append(record);
    }
  } while (groupcode != 0);
  
  if (ok) {
    if (this->maxEntries) this->tableEntries.makeEmpty(this->maxEntries);
    const char *string;
    dimeTableEntry *entry;
    while (ok) {
      if (groupcode != 0) {ok = false; break;}
      string = file->readString();
      if (!string) {ok = false; break;}
      if (!strcmp(string, "ENDTAB")) break; // end of table
      entry = dimeTableEntry::createTableEntry(string, memh);
      if (!entry->read(file)) {ok = false; break;}
      this->tableEntries.append(entry);
      ok = file->readGroupCode(groupcode);
    }
    this->tableEntries.shrinkToFit();
  }
  return ok;
}

/*!
  Writes the table to \a file.
*/

bool 
dimeTable::write(dimeOutput * const file)
{
  bool ret = true;
  file->writeGroupCode(0);
  file->writeString("TABLE");
  int i;

  file->writeGroupCode(2);
  ret = file->writeString(this->tableName());
  
  if (ret) {
    for (i = 0; i < this->records.count(); i++) {
      if (!this->records[i]->write(file)) break;
    }
    if (i < this->records.count()) ret = false;
  }
  if (ret) {
    file->writeGroupCode(70);
    ret = file->writeInt16(this->tableEntries.count());
  }
  if (ret) {
    for (i = 0; i < this->tableEntries.count(); i++) 
      if (!this->tableEntries[i]->write(file)) break;
    if (i < this->tableEntries.count()) ret = false;
    if (ret) {
      file->writeGroupCode(0);
      file->writeString("ENDTAB");
    }
  }
  return ret;
}

//!

int 
dimeTable::typeId() const
{
  return dimeBase::dimeTableType;
}

//!

int 
dimeTable::tableType() const
{
  if (this->tableEntries.count()) return this->tableEntries[0]->typeId();
  return -1;
}

//!

const char *
dimeTable::tableName() const
{
  if (this->tablename) return this->tablename;
  if (this->tableEntries.count()) return this->tableEntries[0]->getTableName();
  return NULL;
}

void 
dimeTable::setTableName(const char * name)
{
  if (!this->memHandler) {
    delete[] this->tablename;
  }
  DXF_STRCPY(this->memHandler, this->tablename, name);
}

/*!
  Counts the number of records in this table.
*/

int 
dimeTable::countRecords() const
{
  int cnt = 2; // header + maxEntries
  cnt += this->records.count();
  int i, n = this->tableEntries.count();
  for (i = 0; i < n; i++) {
    cnt += this->tableEntries[i]->countRecords();
  }
  cnt++; // ENDTAB
  return cnt;
}

/*!
  Returns the number of table enties in this table. 
*/

int 
dimeTable::getNumTableEntries() const
{
  return this->tableEntries.count();
}

/*!
  Returns the table entry at index \a idx.
*/

dimeTableEntry *
dimeTable::getTableEntry(const int idx)
{
  assert(idx >= 0 && idx < this->tableEntries.count());
  return this->tableEntries[idx];
}

/*!
  Removes (and deletes if no memhandler is used) the table entry at index
  \a idx.
*/

void 
dimeTable::removeTableEntry(const int idx)
{
  assert(idx >= 0 && idx < this->tableEntries.count());
  if (!this->memHandler) delete this->tableEntries[idx];
  this->tableEntries.removeElem(idx);
}

/*!
  Inserts a new table entry at index \a idx. If \a idx is negative, the
  table entry will be inserted at the end of the list of tableEntries.
*/

void 
dimeTable::insertTableEntry(dimeTableEntry * const tableEntry, const int idx)
{
  if (idx < 0)
    this->tableEntries.append(tableEntry);
  else {
    assert(idx <= this->tableEntries.count());
    this->tableEntries.insertElem(idx, tableEntry);
  }
}

/*!
  Returns the number of table records in this table. Table records precedes
  the table entries, and contain som information about this table. 
  The max. entries record (group code 70), is handled automatically by this 
  class, and should not be set by the user.
*/

int 
dimeTable::getNumTableRecords() const
{
  return this->records.count();
}

/*!
  Returns the table record at index \a idx.
*/

dimeRecord *
dimeTable::getTableRecord(const int idx)
{
  assert(idx >= 0 && idx < this->records.count());
  return this->records[idx];
}

/*!
  Removes (and deletes if no memhandler is used) the record at index \a idx.
*/

void 
dimeTable::removeTableRecord(const int idx)
{
  assert(idx >= 0 && idx < this->records.count());
  if (!this->memHandler) delete this->records[idx];
  this->records.removeElem(idx);
}

/*!
  Inserts a new record at index \a idx. If \a idx is negative, the
  record will be inserted at the end of the list of records.
*/

void 
dimeTable::insertTableRecord(dimeRecord * const record, const int idx)
{
  assert(record->getGroupCode() != 70);
  if (record->getGroupCode() == 2) {
    dimeStringRecord * rec = (dimeStringRecord*) record;
    this->setTableName(rec->getString());
  }
  int i = idx >= 0 ? idx : this->records.count();
  assert(i <= this->records.count());
  this->records.insertElem(i, record);
}

