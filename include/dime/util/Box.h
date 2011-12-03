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

#ifndef DIME_BOX_H
#define DIME_BOX_H

#include <dime/Basic.h>
#include <dime/util/Linear.h>

class DIME_DLL_API dimeBox
{
public:
  dimeVec3f min, max;
public:
  dimeBox();
  dimeBox(const dxfdouble x0, const dxfdouble y0, const dxfdouble z0, 
	 const dxfdouble x1, const dxfdouble y1, const dxfdouble z1);
  
  void set(const dxfdouble x0, const dxfdouble y0, const dxfdouble z0, 
	   const dxfdouble x1, const dxfdouble y1, const dxfdouble z1);

  void get(dxfdouble &x0, dxfdouble &y0, dxfdouble &z0,
	   dxfdouble &x1, dxfdouble &y1, dxfdouble &z1) const;

  bool operator & (const dimeBox &box) const;
  
  bool pointInside(const dimeVec3f &pt) const;

  dimeVec3f center() const;
  
  void makeEmpty();
  void grow(const dimeVec3f &pt);
  dxfdouble size() const;
  bool hasExtent() const;
}; // class dimeBox

inline bool 
dimeBox::pointInside(const dimeVec3f &pt) const 
{
  return ! (pt[0] < this->min[0] || pt[0] >= this->max[0] || 
	    pt[1] < this->min[1] || pt[1] >= this->max[1] ||
	    pt[2] < this->min[2] || pt[2] >= this->max[2]);
}

inline dimeVec3f 
dimeBox::center() const 
{
  return dimeVec3f((min[0]+max[0])*0.5f, 
		   (min[1]+max[1])*0.5f,
		   (min[2]+max[2])*0.5f);
}

#endif // ! DIME_BOX_H

