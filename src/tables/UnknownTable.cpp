/**************************************************************************\
 * 
 *  FILE: UnknownTable.cpp
 *
 *  This source file is part of DIME.
 *  Copyright (C) 1998-1999 by Systems In Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License, version 2, as
 *  published by the Free Software Foundation.  DO NOT MISTAKE THIS LICENSE
 *  FOR THE GNU LGPL LICENSE.
 *
 *  This library is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License (the accompanying file named COPYING) for more
 *  details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 **************************************************************************
 *
 *  If you need DIME for commercial purposes, you can contact Systems In
 *  Motion about acquiring a commercial license.
 *
 *  Systems In Motion                                   http://www.sim.no/
 *  Prof. Brochs gate 6                                       sales@sim.no
 *  N-7030 Trondheim                                   Voice: +47 22114160
 *  NORWAY                                               Fax: +47 67172912
 *
\**************************************************************************/

/*!
  \class dimeUnknownTable dime/tables/UnknownTable.h
  \brief The dimeUnknownTable class reads and writes undefined tables.
*/

#include <dime/tables/UnknownTable.h>
#include <dime/Input.h>
#include <dime/Output.h>
#include <dime/util/MemHandler.h>
#include <dime/Model.h>
#include <dime/records/Record.h>
#include <string.h>

/*!
  Constructor.
*/

dimeUnknownTable::dimeUnknownTable(const char * const name, 
				 dimeMemHandler * const memhandler)
{
  DXF_STRCPY(memhandler, this->tableName, name);
}

/*!
  Destructor. Should only be called if no memhandler is used.
*/

dimeUnknownTable::~dimeUnknownTable()
{
  delete this->tableName;
}

//!

dimeTableEntry *
dimeUnknownTable::copy(dimeModel * const model) const
{
  dimeMemHandler *memh = model->getMemHandler();
  dimeUnknownTable *u = new(memh) dimeUnknownTable(this->tableName, memh);
  if (!this->copyRecords(u, model)) {
    // check if allocated on heap.
    if (!memh) delete u;
    u = NULL;
  }
  return u;
}

//!

bool 
dimeUnknownTable::write(dimeOutput * const file)
{
  bool ret = dimeTableEntry::preWrite(file);
  if (ret) {
    ret = dimeTableEntry::write(file);
  }
  return ret;
}

//!

int 
dimeUnknownTable::typeId() const
{
  return dimeBase::dimeUnknownTableType;
}

//!

int
dimeUnknownTable::countRecords() const
{
  return 1 + dimeTableEntry::countRecords();
}
  
//!

const char *
dimeUnknownTable::getTableName() const
{
  return this->tableName;
}

