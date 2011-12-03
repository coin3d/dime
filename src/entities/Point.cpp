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
			  dxfdouble &thickness)
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

