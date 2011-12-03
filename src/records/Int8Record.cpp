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
  \class dimeInt8Record dime/records/Int8Record.h
  \brief The dimeInt8Record class is a container class for 8-bit integer records.
*/

#include <dime/records/Int8Record.h>
#include <dime/Input.h>
#include <dime/Output.h>
#include <dime/util/MemHandler.h>

/*!
  Constructor
*/

dimeInt8Record::dimeInt8Record(const int group_code, const int8 val)
  : dimeRecord(group_code)
{
  this->setValue(val);
}

//!

dimeRecord *
dimeInt8Record::copy(dimeMemHandler * const mh) const
{
  return new(mh) dimeInt8Record(this->groupCode, this->value);
}

/*!
  Sets the value.
*/

void 
dimeInt8Record::setValue(const int8 val)
{
  this->value = val;
}

/*!
  Returns the int8 value.
*/

int8
dimeInt8Record::getValue() const
{
  return this->value;
}

//!

int 
dimeInt8Record::typeId() const
{
  return dimeBase::dimeInt8RecordType;
}

//!

bool 
dimeInt8Record::read(dimeInput * const in)
{
  return in->readInt8(this->value);
}

//!

bool 
dimeInt8Record::write(dimeOutput * const out)
{
  if (dimeRecord::write(out)) {
    return out->writeInt8(this->value);
  }
  return false;
}

//!

void 
dimeInt8Record::setValue(const dimeParam &param, dimeMemHandler * const )
{
  this->value = param.int8_data;
}

//!

void 
dimeInt8Record::getValue(dimeParam &param) const
{
  param.int8_data = this->value;
}

