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
  \class dimeTrace dime/entities/Trace.h
  \brief The dimeTrace class handles a TRACE \e entity.
*/

#include <dime/entities/Trace.h>
#include <dime/records/Record.h>
#include <dime/Input.h>
#include <dime/Output.h>
#include <dime/util/MemHandler.h>
#include <dime/Model.h>
#include <float.h>

static char entityName[] = "TRACE";

/*!
  Constructor.
*/

dimeTrace::dimeTrace() 
  : extrusionDir( 0, 0, 1 ), thickness( 0 )
{
}

//!

dimeEntity *
dimeTrace::copy(dimeModel * const model) const
{
  dimeTrace *f = new(model->getMemHandler())dimeTrace;
  if (!f) return NULL;
  
  f->copyCoords(this);
  f->thickness = this->thickness;
  f->extrusionDir = this->extrusionDir;
  
  if (!this->copyRecords(f, model)) {
    // check if allocated on heap.
    if (!model->getMemHandler()) delete f;
    f = NULL;
  }
  return f;
}

//!

bool 
dimeTrace::write(dimeOutput * const file)
{
  bool ret = true;
  if (!this->isDeleted()) {
    this->preWrite(file);
    this->writeCoords(file);
    if (this->thickness != 0.0f) {
      file->writeGroupCode(39);
      file->writeDouble(this->thickness);
    }
    if (this->extrusionDir != dimeVec3f(0,0,1)) {
      file->writeGroupCode(210);
      file->writeDouble(this->extrusionDir[0]);
      file->writeGroupCode(220);
      file->writeDouble(this->extrusionDir[1]);
      file->writeGroupCode(230);
      file->writeDouble(this->extrusionDir[2]);

    }
    ret = dimeEntity::write(file);
  }
  return ret;
}

//!

bool 
dimeTrace::handleRecord(const int groupcode, const dimeParam &param,
		       dimeMemHandler * const memhandler)
{
  switch(groupcode) {
  case 210:
  case 220:
  case 230:
    this->extrusionDir[(groupcode-210)/10] = param.double_data;
    return true;
  case 39:
    this->thickness = param.double_data;
    return true;
  }
  return dimeFaceEntity::handleRecord(groupcode, param, memhandler);
}

//!

const char *
dimeTrace::getEntityName() const
{
  return entityName;
}

//!

bool 
dimeTrace::getRecord(const int groupcode,
		    dimeParam &param,
		    const int index) const
{
  switch(groupcode) {
  case 210:
  case 220:
  case 230:
    param.double_data = this->extrusionDir[(groupcode-210)/10];
    return true;
  case 39:
    param.double_data = this->thickness;
    return true;
  }
  return dimeFaceEntity::getRecord(groupcode, param, index);
}

//!

int 
dimeTrace::typeId() const
{
  return dimeBase::dimeTraceType;
}

dxfdouble 
dimeTrace::getThickness() const
{
  return this->thickness;
}

void 
dimeTrace::getExtrusionDir(dimeVec3f &ed) const
{
  ed = this->extrusionDir;
}

bool 
dimeTrace::swapQuadCoords() const
{
  return true;
}

void 
dimeTrace::setThickness(const dxfdouble &thickness)
{
  this->thickness = thickness;
}

void 
dimeTrace::setExtrusionDir(const dimeVec3f &ed)
{
  this->extrusionDir = ed;
}

//!

int 
dimeTrace::countRecords() const
{
  int cnt = 0;
  if (!this->isDeleted()) {
    cnt++; // header
    if (this->thickness != 0.0) cnt++;
    if (this->extrusionDir != dimeVec3f(0,0,1)) cnt += 3; 
    cnt += dimeFaceEntity::countRecords();
  }
  return cnt;
}

