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
  \class dimeTablesSection dime/sections/TablesSection.h
  \brief The dimeTablesSection class handles a TABLES \e section.
*/

#include <dime/sections/TablesSection.h>
#include <dime/tables/Table.h>
#include <dime/Input.h>
#include <dime/Output.h>
#include <dime/util/MemHandler.h>
#include <dime/Model.h>
#include <dime/util/Array.h>

static const char sectionName[] = "TABLES";

/*!
  Constructor.
*/

dimeTablesSection::dimeTablesSection(dimeMemHandler * const memhandler)
  : dimeSection( memhandler )
{
}

/*!
  Destructor.
*/

dimeTablesSection::~dimeTablesSection()
{
  for (int i = 0; i < this->tables.count(); i++)
    delete this->tables[i];
}

//!

dimeSection *
dimeTablesSection::copy(dimeModel * const model) const
{
  dimeMemHandler *memh = model->getMemHandler();
  dimeTablesSection *ts = new dimeTablesSection(memh);
  int n = this->tables.count();
  if (n) {
    int i;
    ts->tables.makeEmpty(n);
    for (i = 0; i < n; i++) {
      dimeTable *cp = this->tables[i]->copy(model);
      if (!cp) break;
      ts->tables.append(cp);
    }
    if (i < n) {
      fprintf(stderr,"Error copying TABLES section.\n");
//      sim_warning("Error copying TABLES section.\n");
      return NULL;
    }
  }
  return ts;
}

/*!
  Will read a dxf TABLES section.
*/

bool 
dimeTablesSection::read(dimeInput * const file)
{
  int32 groupcode;
  const char *string;
  bool ok = true;
  dimeTable *table = NULL;
  dimeMemHandler *memhandler = file->getMemHandler();

//  sim_trace("Reading section: TABLES\n");

  while (true) {
    if (!file->readGroupCode(groupcode) || groupcode != 0) {
      fprintf(stderr,"Error reading groupcode: %d\n", groupcode);
//      sim_warning("Error reading groupcode: %d\n", groupcode);
      ok = false;
      break;
    }
    string = file->readString();
    if (!strcmp(string, "ENDSEC")) break;
    if (strcmp(string, "TABLE")) {
      fprintf(stderr,"unexpected string.\n");
//      sim_warning("unexpected string.\n");
      ok = false;
      break;
    }

    table = new dimeTable(memhandler);
    if (table == NULL) {
      fprintf(stderr,"error creating table: %s\n", string);
//      sim_warning("error creating table: %s\n", string);
      ok = false;
      break;
    }
    if (!table->read(file)) {
      fprintf(stderr,"error reading table: %s.\n", string);
//      sim_warning("error reading table: %s.\n", string);
      ok = false;
      break;
    }
    this->tables.append(table);
  }
  return ok;
}

//!

bool 
dimeTablesSection::write(dimeOutput * const file)
{
  if (file->writeGroupCode(2) && file->writeString(sectionName)) {
    int i, n = this->tables.count();
    for (i = 0; i < n; i++) {
      if (!this->tables[i]->write(file)) break;
    }
    if (i == n) {
      return file->writeGroupCode(0) && file->writeString("ENDSEC");
    }
  }
  return false;
}

//!

int 
dimeTablesSection::typeId() const
{
  return dimeBase::dimeTablesSectionType;
}

//!

int
dimeTablesSection::countRecords() const
{
  int cnt = 0;
  int i, n = this->tables.count();
  for (i = 0; i < n; i++)
    cnt += this->tables[i]->countRecords();
  return cnt + 2; // two records are written in write()
}

//!

const char *
dimeTablesSection::getSectionName() const
{
  return sectionName;
}

/*!
  Returns the number of tables in this section. 
*/

int 
dimeTablesSection::getNumTables() const
{
  return this->tables.count();
}

/*!
  Returns the table at index \a idx.
*/

dimeTable *
dimeTablesSection::getTable(const int idx)
{
  assert(idx >= 0 && idx < this->tables.count());
  return this->tables[idx];
}

/*!
  Removes (and deletes if no memhandler is used) the table at index \a idx.
*/

void 
dimeTablesSection::removeTable(const int idx)
{
  assert(idx >= 0 && idx < this->tables.count());
  if (!this->memHandler) delete this->tables[idx];
  this->tables.removeElem(idx);
}

/*!
  Inserts a new table at index \a idx. If \a idx is negative, the
  table will be inserted at the end of the list of tables.
  Be aware that the order of the tables might be important.
  For instance, the LTYPE table should always precede the LAYER table.
*/

void 
dimeTablesSection::insertTable(dimeTable * const table, const int idx)
{
  if (idx < 0) this->tables.append(table);
  else {
    assert(idx <= this->tables.count());
    this->tables.insertElem(idx, table);
  }
}

