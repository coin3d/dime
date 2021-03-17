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
  \class dimeUnknownEntity dime/entities/UnknownEntity.h
  \brief The dimeUnknownEntity class reads and writes undefined \e entity classes.
*/

#include <dime/entities/UnknownEntity.h>
#include <dime/Input.h>
#include <dime/Output.h>
#include <dime/util/MemHandler.h>
#include <dime/Model.h>
#include <dime/records/Record.h>
#include <string.h>

/*!
  Constructor.
*/

dimeUnknownEntity::dimeUnknownEntity(const char * const name,
                                     dimeMemHandler * const memhandler)
{
  DXF_STRCPY(memhandler, this->entityName, name);
}

/*!
  Destructor. Should only be called if no memory handler is used.
*/

dimeUnknownEntity::~dimeUnknownEntity()
{
  delete [] this->entityName;
}

//!

dimeEntity *
dimeUnknownEntity::copy(dimeModel * const model) const
{
  dimeMemHandler *memh = model->getMemHandler();
  dimeUnknownEntity *u = new(memh) dimeUnknownEntity(this->entityName, memh);
  if (!this->copyRecords(u, model)) {
    // check if allocated on heap.
    if (!memh) delete u;
    u = NULL;
  }
  return u;
}

//!

bool
dimeUnknownEntity::write(dimeOutput * const file)
{
  dimeEntity::preWrite(file);
  return dimeEntity::write(file);
}

//!

int
dimeUnknownEntity::typeId() const
{
  return dimeBase::dimeUnknownEntityType;
}

//!

int
dimeUnknownEntity::countRecords() const
{
  return 1 + dimeEntity::countRecords();
}

//!

const char *
dimeUnknownEntity::getEntityName() const
{
  return this->entityName;
}
