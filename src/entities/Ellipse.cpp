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
  \class dimeEllipse dime/entities/Ellipse.h
  \brief The dimeEllipse class handles an ELLIPSE \e entity.
*/

#include <dime/entities/Ellipse.h>
#include <dime/records/Record.h>
#include <dime/Input.h>
#include <dime/Output.h>
#include <dime/util/MemHandler.h>
#include <dime/Model.h>
#include <math.h>

#ifdef _WIN32
#define M_PI 3.14159265357989
#endif

#ifdef macintosh
#define M_PI 3.14159265357989
#endif

/*!
  \fn void dimeEllipse::setCenter(const dimeVec3f &c)
  Sets the center coordinates of the ellipse.
*/

/*!
  \fn const dimeVec3f &dimeEllipse::getCenter() const
  Returns the center coordinates of the ellipse.
*/

/*!
  \fn void dimeEllipse::setMajorAxisEndpoint(const dimeVec3f &v)
  Sets the major axis endpoint of the ellipse. 
  \sa dimeEllipse::setRatio()
*/

/*!
  \fn const dimeVec3f &dimeEllipse::getMajorAxisEndpoint() const
  Returns the major axis endpoint of this ellipse.
*/
  
/*!
  \fn void dimeEllipse::setMinorMajorRatio(const dxfdouble ratio)
  Sets the ratio of the minor axis to the major axis.
*/

/*!
  \fn dxfdouble dimeEllipse::getMinorMajorRatio() const
  Returns the ratio of the minor axis to the major axis.
*/

/*!
  \fn void dimeEllipse::setStartParam(const dxfdouble p)
  Sets the start parameter for this ellipse.
  Possible values range from 0 to 2pi. Default value is
  0.
*/

/*!
  \fn dxfdouble dimeEllipse::getStartParam() const
  Returns the start parameter for this ellipse.
  \sa dimeEllipse::setStartParam()
*/

/*!
  \fn void dimeEllipse::setEndParam(const dxfdouble p)
  Sets the end parameter for this ellipse.
  Possible values range from 0 to 2pi, but this value should
  be bigger than the start parameter. Default value is 2pi.
  \sa dimeEllipse::setStartParam()
*/

/*!
  \fn dxfdouble dimeEllipse::getEndParam() const
  Returns the end parameter for this ellipse.
  \sa dimeEllipse::setEndParam()
*/

static char entityName[] = "ELLIPSE";

// FIXME: should be configurable

#define ELLIPSE_NUMPTS 16

/*!
  Constructor.
*/

dimeEllipse::dimeEllipse() 
  : center(0,0,0), majorAxisEndpoint(0,0,1), ratio(1.0), startParam(0.0),
    endParam(M_PI*2)
{
}

//!

dimeEntity *
dimeEllipse::copy(dimeModel * const model) const
{
  dimeEllipse *e = new(model->getMemHandler()) dimeEllipse;
  if (!e) return NULL;
  
  if (!this->copyRecords(e, model)) {
    // check if allocated on heap.
    if (!model->getMemHandler()) delete e;
    e = NULL;
  }
  else {
    e->copyExtrusionData(this);
    e->center = this->center;
    e->ratio = this->ratio;
    e->majorAxisEndpoint = this->majorAxisEndpoint;
    e->startParam = this->startParam;
    e->endParam = this->endParam;
  }
  return e;  
}

//!

bool 
dimeEllipse::write(dimeOutput * const file)
{
  dimeEntity::preWrite(file);
  
  file->writeGroupCode(10);
  file->writeDouble(this->center[0]);
  file->writeGroupCode(20);
  file->writeDouble(this->center[1]);
  file->writeGroupCode(30);
  file->writeDouble(this->center[2]);

  file->writeGroupCode(11);
  file->writeDouble(this->majorAxisEndpoint[0]);
  file->writeGroupCode(21);
  file->writeDouble(this->majorAxisEndpoint[1]);
  file->writeGroupCode(31);
  file->writeDouble(this->majorAxisEndpoint[2]);
   
  file->writeGroupCode(40);
  file->writeDouble(this->ratio);

  file->writeGroupCode(41);
  file->writeDouble(this->startParam);
  
  file->writeGroupCode(42);
  file->writeDouble(this->endParam);

  this->writeExtrusionData(file);
  
  return dimeExtrusionEntity::write(file);
}

//!

int 
dimeEllipse::typeId() const
{
  return dimeBase::dimeEllipseType;
}

//!

bool 
dimeEllipse::handleRecord(const int groupcode,
			const dimeParam &param,
			dimeMemHandler * const memhandler)
{
  switch(groupcode) {
  case 10:
  case 20:
  case 30:
    this->center[groupcode/10-1] = param.double_data;
    return true;
  case 11:
  case 21:
  case 31:
    this->majorAxisEndpoint[groupcode/10-1] = param.double_data;
    return true;
  case 40:
    this->ratio = param.double_data;
    return true;
  case 41:
    this->startParam = param.double_data;
    return true;
  case 42:
    this->endParam = param.double_data;
    return true;
  }  
  return dimeExtrusionEntity::handleRecord(groupcode, param, memhandler);
}

//!

const char *
dimeEllipse::getEntityName() const
{
  return entityName;
}

//!

bool 
dimeEllipse::getRecord(const int groupcode,
		     dimeParam &param,
		     const int index) const
{
  switch(groupcode) {
  case 10:
  case 20:
  case 30:
    param.double_data = this->center[groupcode/10-1]; 
    return true;
  case 11:
  case 21:
  case 31:
    param.double_data = this->majorAxisEndpoint[groupcode/10-1];
    return true;
  case 40:
    param.double_data = this->ratio;
    return true;
  case 41:
    param.double_data = this->startParam;
    return true;
  case 42:
    param.double_data = this->endParam;
    return true;
  }

  return dimeExtrusionEntity::getRecord(groupcode, param, index);  
}

//!

void
dimeEllipse::print() const
{
  fprintf(stderr,"ELLIPSE:\n");
}

//!

int
dimeEllipse::countRecords() const
{
  // header + center point + major endpoint + ratio + start + end
  return 10 + dimeExtrusionEntity::countRecords();
}

