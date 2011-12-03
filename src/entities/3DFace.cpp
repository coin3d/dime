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
  \class dime3DFace dime/entities/3DFace.h
  \brief The dime3DFace class handles a 3DFACE \e entity.
*/

#include <dime/entities/3DFace.h>
#include <dime/records/Record.h>
#include <dime/Input.h>
#include <dime/Output.h>
#include <dime/util/MemHandler.h>
#include <dime/Model.h>

static char entityName[] = "3DFACE";

/*!
  Constructor.
*/

dime3DFace::dime3DFace()
  : flags( 0 )
{
#ifndef NO_RR_DATA
  this->block = NULL;
#endif
}

//!

dimeEntity *
dime3DFace::copy(dimeModel * const model) const
{
  dime3DFace *f = new(model->getMemHandler()) dime3DFace;
  if (!f) return NULL;
  
  f->copyCoords(this);
  f->flags = this->flags;
  
  if (!this->copyRecords(f, model)) {
    // check if allocated on heap.
    if (!model->getMemHandler()) delete f;
    f = NULL;
  }
  return f;
}

//!

const char *
dime3DFace::getEntityName() const
{
  return entityName;
}

//!

bool 
dime3DFace::write(dimeOutput * const file)
{
  bool ret = true;
  if (!this->isDeleted()) {
    this->preWrite(file);
    this->writeCoords(file);
    if (flags != 0) {
      file->writeGroupCode(70);
      file->writeInt16(flags);
    }
    ret = dimeEntity::write(file);
  }
  return ret;
}

//!

int 
dime3DFace::typeId() const
{
  return dimeBase::dime3DFaceType;
}

//!

bool 
dime3DFace::handleRecord(const int groupcode, 
			const dimeParam &param,
			dimeMemHandler * const memhandler)
{
  if (groupcode == 70) {
    this->flags = param.int16_data;
    return true;
  }
  else {
    return dimeFaceEntity::handleRecord(groupcode, param, memhandler);
  }
}

//!

bool 
dime3DFace::getRecord(const int groupcode,
		     dimeParam &param,
		     const int index) const
{
  if (groupcode == 70) {
    param.int16_data = this->flags;
    return true;
  }
  return dimeFaceEntity::getRecord(groupcode, param, index);
}

//!

void
dime3DFace::print() const
{
  fprintf(stderr,"3DFACE:\n");
  int stop = this->isQuad() ? 4 : 3;
  for (int i = 0; i < stop; i++) { 
    fprintf(stderr,"coord: %f %f %f\n", coords[i][0], 
	    coords[i][1], coords[i][2]); 
    
  } 
}

//!

int
dime3DFace::countRecords() const
{
  int cnt = 0;
  if (!this->isDeleted()) {
    cnt++; // header
    if (this->flags != 0) cnt++;
    cnt += dimeFaceEntity::countRecords();
  }
  return cnt;   
}

void 
dime3DFace::setFlags(const int16 flags)
{
  this->flags = flags;
}

int16 
dime3DFace::getFlags() const
{
  return this->flags;
}

