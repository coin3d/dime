/**************************************************************************\
 * 
 *  FILE: Point.cpp
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
  \class dimePoint dime/entities/Point.h
  \brief The dimePoint class handles a POINT \e entity.
*/

#include <dime/entities/Point.h>
#include <dime/records/Record.h>
#include <dime/Input.h>
#include <dime/Output.h>
#include <dime/util/MemHandler.h>
#include <dime/Model.h>

static char entityName[] = "POINT";

/*!
  Constructor.
*/

dimePoint::dimePoint()
  : coords(0, 0, 0)
{
}

//!

dimeEntity *
dimePoint::copy(dimeModel * const model) const
{
  dimePoint *p = new(model->getMemHandler()) dimePoint;

  p->coords = this->coords;
  p->copyExtrusionData(this);

  if (!this->copyRecords(p, model)) {
    // check if allocated on heap.
    if (!model->getMemHandler()) delete p;
    p = NULL;
  }
  return p;
}

//!

bool 
dimePoint::write(dimeOutput * const file)
{
  bool ret = true;
  if (!this->isDeleted()) {
    this->preWrite(file);

    file->writeGroupCode(10);
    file->writeDouble(this->coords[0]);
    file->writeGroupCode(20);
    file->writeDouble(this->coords[1]);
    file->writeGroupCode(30);
    file->writeDouble(this->coords[2]);
    
    ret = this->writeExtrusionData(file) && dimeEntity::write(file);
  }
  return ret;
}

//!

int 
dimePoint::typeId() const
{
  return dimeBase::dimePointType;
}

//!

bool 
dimePoint::handleRecord(const int groupcode,
		       const dimeParam &param,
		       dimeMemHandler * const memhandler)
{
  switch(groupcode) {
  case 10:
  case 20:
  case 30:
    this->coords[groupcode/10-1] = param.double_data;
    return true;
  }
  return dimeExtrusionEntity::handleRecord(groupcode, param, memhandler); 
}

//!

const char *
dimePoint::getEntityName() const
{
  return entityName;
}

//!

bool 
dimePoint::getRecord(const int groupcode,
		    dimeParam &param,
		    const int index) const
{
  switch(groupcode) {
  case 10:
  case 20:
  case 30:
    param.double_data = this->coords[groupcode/10-1];
    return true;
  }
  return dimeExtrusionEntity::getRecord(groupcode, param, index); 
}

//!

dimeEntity::GeometryType 
dimePoint::extractGeometry(dimeArray <dimeVec3f> &verts,
			  dimeArray <int> &/*indices*/,
			  dimeVec3f &extrusionDir,
			  float &thickness)
{
  thickness = this->thickness;
  extrusionDir = this->extrusionDir;
  verts.append(this->coords);
  return dimeEntity::POINTS;
}

//!

int
dimePoint::countRecords() const
{
  int cnt = 0;
  cnt += 4; // header + coordinates
  return cnt + dimeExtrusionEntity::countRecords();
}

