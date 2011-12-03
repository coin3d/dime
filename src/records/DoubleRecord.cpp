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
  \class dimeDoubleRecord dime/records/DoubleRecord.h
  \brief The dimeDoubleRecord class is a container class for double records.
*/

#include <dime/records/DoubleRecord.h>
#include <dime/Input.h>
#include <dime/Output.h>
#include <dime/util/MemHandler.h>
#include <stdio.h>

/*!
  Constructor.
*/

dimeDoubleRecord::dimeDoubleRecord(const int group_code, const dxfdouble val)
  : dimeRecord(group_code)
{
  this->setValue(val);
}

//!

dimeRecord *
dimeDoubleRecord::copy(dimeMemHandler * const mh) const
{
  return new(mh) dimeDoubleRecord(this->groupCode, this->value);
}

/*!
  Sets the floating point value.
*/

void 
dimeDoubleRecord::setValue(const dxfdouble val)
{
  this->value = val;
}

/*!
  Returns the floating point value of this record.
*/

dxfdouble
dimeDoubleRecord::getValue() const
{
  return this->value;
}

//!

int 
dimeDoubleRecord::typeId() const
{
  return dimeBase::dimeDoubleRecordType;
}

//!

bool 
dimeDoubleRecord::read(dimeInput * const in)
{
  return in->readDouble(this->value);
}

//!

bool 
dimeDoubleRecord::write(dimeOutput * const out)
{
  if (dimeRecord::write(out)) {
    return out->writeDouble(this->value);
  }
  return false;
}

//!

void 
dimeDoubleRecord::setValue(const dimeParam &param, dimeMemHandler * const)
{
  this->value = param.double_data;
}

//!

void 
dimeDoubleRecord::getValue(dimeParam &param) const
{
  param.double_data = this->value;
}

