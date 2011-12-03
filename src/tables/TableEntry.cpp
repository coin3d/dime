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
  \class dimeTableEntry dime/tables/TableEntry.h
  \brief The dimeTableEntry class is the superclass for all table classes.
*/

#include <dime/tables/TableEntry.h>
#include <dime/tables/UnknownTable.h>
#include <dime/tables/LayerTable.h>
#include <dime/tables/UCSTable.h>
#include <dime/records/Record.h>
#include <dime/Input.h>
#include <dime/Output.h>
#include <dime/util/MemHandler.h>
#include <dime/Model.h>

#include <string.h>
#include <ctype.h>

/*!
  Constructor.
*/

dimeTableEntry::dimeTableEntry()
  : dimeRecordHolder(0)  // table entries are separated by group code 0
{
}

/*!
  Destructor.
*/

dimeTableEntry::~dimeTableEntry()
{
}

/*!
  Copies the unclassified records.
*/

bool
dimeTableEntry::copyRecords(dimeTableEntry * const table,
                           dimeModel * const model) const
{
  return dimeRecordHolder::copyRecords(table, model->getMemHandler());
}

//!

bool 
dimeTableEntry::write(dimeOutput * const /* file */)
{
  // moved to preWrite()
  //return dimeRecordHolder::write(file);
  return true;
}

//!

bool 
dimeTableEntry::read(dimeInput * const file)
{
  return dimeRecordHolder::read(file);
}

/*!
  Static function that creates a table based on its name. 
*/

dimeTableEntry *
dimeTableEntry::createTableEntry(const char * const name, 
				dimeMemHandler * const memhandler)
{
  if (!strcmp(name, "LAYER")) {
    return new(memhandler) dimeLayerTable;
  }
  //if (!strcmp(name, "UCS")) // UCS is not used for the moment
  //  return new(memhandler) dimeUCSTable;

  return new(memhandler) dimeUnknownTable(name, memhandler);
}

/*!
  Returns the number of records for this table. Tables overloading 
  this function should first count the number of records they will write,
  then add the return value of this function to get the total number
  of records.
*/

int 
dimeTableEntry::countRecords() const
{
  return dimeRecordHolder::countRecords();
}

//!

bool 
dimeTableEntry::handleRecord(const int,
			     const dimeParam &,
			     dimeMemHandler * const)
{
  return false;
}

//!

bool 
dimeTableEntry::isOfType(const int thetypeid) const
{
  return thetypeid == dimeBase::dimeTableEntryType ||
    dimeRecordHolder::isOfType(thetypeid);
}

//!

bool
dimeTableEntry::preWrite(dimeOutput * const file)
{
  return file->writeGroupCode(0) && 
    file->writeString(this->getTableName()) &&
    dimeRecordHolder::write(file);
}

/*!
  \fn const char * dimeTableEntry::getTableName() const = 0
*/

/*!
  \fn dimeTableEntry * dimeTableEntry::copy(dimeModel * const model) const = 0
*/

/*!
  \fn int dimeTableEntry::typeId() const = 0
*/

