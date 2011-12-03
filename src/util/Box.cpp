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
#include <dime/util/Box.h>
#include <float.h>

template <class Type>
inline Type SIMSQR(const Type val) 
{
  return val*val;
}


dimeBox::dimeBox() 
{
  makeEmpty();
}

dimeBox::dimeBox(const dxfdouble x0, const dxfdouble y0, const dxfdouble z0, 
	       const dxfdouble x1, const dxfdouble y1, const dxfdouble z1) 
{
  this->min.setValue(x0, y0, z0);
  this->max.setValue(x1, y1, z1);
}

void 
dimeBox::set(const dxfdouble x0, const dxfdouble y0, const dxfdouble z0, 
	    const dxfdouble x1, const dxfdouble y1, const dxfdouble z1) 
{
  this->min.setValue(x0, y0, z0);
  this->max.setValue(x1, y1, z1);
}

void 
dimeBox::get(dxfdouble &x0, dxfdouble &y0, dxfdouble &z0,
	    dxfdouble &x1, dxfdouble &y1, dxfdouble &z1) const 
{
  this->min.getValue(x0, y0, z0);
  this->max.getValue(x1, y1, z1);
}

bool 
dimeBox::operator & (const dimeBox &box) const 
{
  return ! (box.min[0] >= this->max[0] || box.max[0] < this->min[0] || 
	    box.min[1] >= this->max[1] || box.max[1] < this->min[1] ||
	    box.min[2] >= this->max[2] || box.max[2] < this->min[2]);
}

void 
dimeBox::grow(const dimeVec3f &pt) 
{
  if (min[0] > pt[0]) min[0] = pt[0];
  if (max[0] < pt[0]) max[0] = pt[0];
  if (min[1] > pt[1]) min[1] = pt[1];
  if (max[1] < pt[1]) max[1] = pt[1];
  if (min[2] > pt[2]) min[2] = pt[2];
  if (max[2] < pt[2]) max[2] = pt[2];
}

dxfdouble 
dimeBox::size() const 
{
  dxfdouble dx = max[0] - min[0];
  dxfdouble dy = max[1] - min[1];
  dxfdouble dz = max[2] - min[2];
  return (dxfdouble) sqrt(dx*dx+dy*dy+dz*dz); 
}

bool 
dimeBox::hasExtent() const 
{
  return !(min[0] == FLT_MAX || min[1] == FLT_MAX || min[2] == FLT_MAX ||
	   max[0] == -FLT_MAX || max[1] == -FLT_MAX || max[2] == -FLT_MAX);
}


void 
dimeBox::makeEmpty()
{
  this->min.setValue(FLT_MAX, FLT_MAX, FLT_MAX);
  this->max.setValue(-FLT_MAX, -FLT_MAX, -FLT_MAX);  
}
