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
  \class dimeStringRecord dime/records/StringRecord.h
  \brief The dimeStringRecord class is a container class for string records.
*/

#include <dime/records/StringRecord.h>
#include <dime/Input.h>
#include <dime/Output.h>
#include <dime/util/MemHandler.h>
#include <string.h>

/*! 
  Constructor.
*/

dimeStringRecord::dimeStringRecord(const int group_code)
  : dimeRecord(group_code)
{
  this->string = NULL;
}

/*!
  Destructor.
*/

dimeStringRecord::~dimeStringRecord()
{
  delete[] this->string;
}

//!

dimeRecord *
dimeStringRecord::copy(dimeMemHandler * const mh) const
{
  dimeStringRecord *s= new(mh) dimeStringRecord(this->groupCode);
  if (s) {
    s->setString(this->string, mh);
  }
  return s;
}

/*!
  Will store a copy of string \a s. If \a memhandler != NULL, it
  will be used to allocate the needed memory. If \a memhandler == NULL,
  the memory will be allocated from the heap.
*/

bool
dimeStringRecord::setString(const char * const s, 
			   dimeMemHandler * const memhandler)
{
  DXF_STRCPY(memhandler, this->string, s);
  return this->string != NULL;
}

/*!  
  Sets the objects string pointer to point to 's'. Be aware that if
  the destructor is called for this object, the object will attempt to
  delete the string. \sa dimeStringRecord::setString().  
*/

void
dimeStringRecord::setStringPointer(char * const s)
{
  this->string = s;
}

/*!
  Returns a pointer to the string.
*/

char *
dimeStringRecord::getString()
{
  return string;
}

//!

bool
dimeStringRecord::isEndOfSectionRecord() const
{
  return (this->groupCode == 0) && !strcmp(string, "ENDSEC");
}

//!

bool
dimeStringRecord::isEndOfFileRecord() const
{
  return (this->groupCode == 0) && !strcmp(string, "EOF");
}

//!

int 
dimeStringRecord::typeId() const
{
  return dimeBase::dimeStringRecordType;
}

//!

bool 
dimeStringRecord::read(dimeInput * const in)
{
  this->string = NULL;
  const char *ptr = in->readString();
  if (ptr) return this->setString(ptr, in->getMemHandler());
  else return false;
}

//!

bool 
dimeStringRecord::write(dimeOutput * const out)
{
  if (dimeRecord::write(out)) { // write group code
    return out->writeString(this->string);
  }
  return false;
}

//!

void 
dimeStringRecord::setValue(const dimeParam &param, dimeMemHandler * const memhandler)
{
  if (memhandler) {
    this->string = memhandler->stringAlloc(param.string_data);
  }
  else {
    this->string = new char[strlen(param.string_data)+1];
    if (this->string) strcpy(this->string, param.string_data);
  }
}

//!

void 
dimeStringRecord::getValue(dimeParam &param) const
{
  param.string_data = this->string;
}

