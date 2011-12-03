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
  \class dimeInt16Record dime/records/Int16Record.h
  \brief The dimeInt16Record class is a container class for 16-bit integer records.
*/

#include <dime/records/Int16Record.h>
#include <dime/Input.h>
#include <dime/Output.h>
#include <dime/util/MemHandler.h>

/*!
  Constructor
*/

dimeInt16Record::dimeInt16Record(const int group_code, const int16 val)
  :dimeRecord(group_code)
{
  this->setValue(val);
}

//!

dimeRecord *
dimeInt16Record::copy(dimeMemHandler * const mh) const
{
  return new(mh) dimeInt16Record(this->groupCode, this->value);
}

/*!
  Sets the int16 value.
*/

void 
dimeInt16Record::setValue(const int16 val)
{
  this->value = val;
}

/*!
  Returns the int16 value.
*/

int16
dimeInt16Record::getValue() const
{
  return this->value;
}

//!

int 
dimeInt16Record::typeId() const
{
  return dimeBase::dimeInt16RecordType;
}

//!

bool 
dimeInt16Record::read(dimeInput * const in)
{
  return in->readInt16(this->value);
}

//!

bool 
dimeInt16Record::write(dimeOutput * const out)
{
  if (dimeRecord::write(out)) {
    return out->writeInt16(this->value);
  }
  return false;
}

//!

void 
dimeInt16Record::setValue(const dimeParam &param, dimeMemHandler * const )
{
  this->value = param.int16_data;
}

//!

void 
dimeInt16Record::getValue(dimeParam &param) const
{
  param.int16_data = this->value;
}

