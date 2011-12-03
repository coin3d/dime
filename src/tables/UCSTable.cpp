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
  \class dimeUCSTable dime/tables/UCSTable.h
  \brief The dimeUCSTable class reads and writes UCS tables.
*/

#include <dime/tables/UCSTable.h>
#include <dime/Input.h>
#include <dime/Output.h>
#include <dime/util/MemHandler.h>
#include <dime/Model.h>
#include <dime/records/Record.h>
#include <string.h>

static const char tableName[] = "UCS";

/*!
  Constructor.
*/

dimeUCSTable::dimeUCSTable()
  : origin(0,0,0), xaxis(1,0,0), yaxis(0,1,0)
{
}

//!

dimeTableEntry *
dimeUCSTable::copy(dimeModel * const model) const
{
  dimeMemHandler *memh = model->getMemHandler();
  dimeUCSTable *u = new(memh) dimeUCSTable;
  u->xaxis = this->xaxis;
  u->yaxis = this->yaxis;
  u->origin = this->origin;
  if (!this->copyRecords(u, model)) {
    // check if allocated on heap.
    if (!memh) delete u;
    u = NULL;
  }
  return u;
}

//!

const char *
dimeUCSTable::getTableName() const
{
  return tableName;
}

//!

bool 
dimeUCSTable::write(dimeOutput * const file)
{
  bool ret = true;
  file->writeGroupCode(0);
  file->writeString(tableName);
  file->writeGroupCode(10);
  file->writeDouble(this->origin[0]);
  file->writeGroupCode(20);
  file->writeDouble(this->origin[1]);
  file->writeGroupCode(30);
  file->writeDouble(this->origin[2]);

  file->writeGroupCode(11);
  file->writeDouble(this->xaxis[0]);
  file->writeGroupCode(21);
  file->writeDouble(this->xaxis[1]);
  file->writeGroupCode(31);
  file->writeDouble(this->xaxis[2]);

  file->writeGroupCode(12);
  file->writeDouble(this->yaxis[0]);
  file->writeGroupCode(22);
  file->writeDouble(this->yaxis[1]);
  file->writeGroupCode(32);
  file->writeDouble(this->yaxis[2]);
  
  ret = dimeTableEntry::write(file);
  return ret;
}

//!

int 
dimeUCSTable::typeId() const
{
  return dimeBase::dimeUCSTableType;
}

//!

bool 
dimeUCSTable::handleRecord(const int groupcode,
			  const dimeParam &param,
			  dimeMemHandler * const memhandler)
{
  switch(groupcode) {
  case 10:
  case 20:
  case 30:
    this->origin[(groupcode/10)-1] = param.double_data;
    return true;
  case 11:
  case 21:
  case 31:
    this->xaxis[(groupcode/10)-1] = param.double_data;
    return true;
  case 12:
  case 22:
  case 32:
    this->yaxis[(groupcode/10)-1] = param.double_data;
    return true;
  }
  return dimeTableEntry::handleRecord(groupcode, param, memhandler);
}

//!

int
dimeUCSTable::countRecords() const
{
  int cnt = 1 + 3 + 3 + 3; // header + origin + xaxis + yaxis
  return cnt + dimeTableEntry::countRecords();
}

