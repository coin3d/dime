/**************************************************************************\
 * 
 *  FILE: UnknownClass.cpp
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
  \class dimeUnknownClass dime/classes/UnknownClass.h
  \brief The dimeUnknownClass class reads and writes undefined classes.
*/

#include <dime/classes/UnknownClass.h>
#include <dime/Input.h>
#include <dime/Output.h>
#include <dime/util/MemHandler.h>
#include <dime/Model.h>
#include <string.h>

/*!
  Constructor.
*/

dimeUnknownClass::dimeUnknownClass(const char * const name, 
				 dimeMemHandler * const memhandler)
{
  DXF_STRCPY(memhandler, this->dxfClassName, name);
}

/*!
  Destructor. Should only be called if no memhandler is used.
*/

dimeUnknownClass::~dimeUnknownClass()
{
  delete this->dxfClassName;
}

//!

dimeClass *
dimeUnknownClass::copy(dimeModel * const model) const
{
  dimeMemHandler *memh = model->getMemHandler();
  dimeUnknownClass *u = new(memh) dimeUnknownClass(this->dxfClassName, memh);
  if (!this->copyRecords(u, model)) { // check if allocated on heap.
    if (!memh) delete u;
    u = NULL;
  }
  return u;
}

//!

bool 
dimeUnknownClass::write(dimeOutput * const file)
{
  if (file->writeGroupCode(9) && file->writeString(this->dxfClassName))
    return dimeClass::write(file);
  return false;
}

//!

int 
dimeUnknownClass::typeId() const
{
  return dimeBase::dimeUnknownClassType;
}

//!

int
dimeUnknownClass::countRecords() const
{
  return 1 + dimeClass::countRecords();
}

//!

const char *
dimeUnknownClass::getDxfClassName() const
{
  return this->dxfClassName;
}

