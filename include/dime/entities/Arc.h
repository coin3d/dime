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

#ifndef DIME_ARC_H
#define DIME_ARC_H
  
#include <dime/Basic.h>
#include <dime/entities/ExtrusionEntity.h>
#include <dime/util/Linear.h>

class DIME_DLL_API dimeArc : public dimeExtrusionEntity
{
public:
  dimeArc();

  void setCenter(const dimeVec3f &c);
  void getCenter(dimeVec3f &c) const;
  void setRadius(const dxfdouble r);
  dxfdouble getRadius() const;
  void setStartAngle(const dxfdouble a);
  dxfdouble getStartAngle() const;
  void setEndAngle(const dxfdouble a);
  dxfdouble getEndAngle() const;
  
  virtual bool getRecord(const int groupcode,
			 dimeParam &param,
			 const int index = 0) const;
  virtual const char *getEntityName() const;

  virtual dimeEntity *copy(dimeModel * const model) const;
  
  virtual void print() const;
  virtual bool write(dimeOutput * const out);
  virtual int typeId() const;
  virtual int countRecords() const;
  
  virtual GeometryType extractGeometry(dimeArray <dimeVec3f> &verts,
				       dimeArray <int> &indices,
				       dimeVec3f &extrusionDir,
				       dxfdouble &thickness);
  
protected:
  virtual bool handleRecord(const int groupcode, 
			    const dimeParam &param,
                            dimeMemHandler * const memhandler);
    
private:
  dimeVec3f center;
  dxfdouble radius;
  dxfdouble startAngle;
  dxfdouble endAngle;

}; // class dimeArc

//
// inline methods
//

inline void 
dimeArc::setCenter(const dimeVec3f &c)
{
  this->center = c;
}

inline void 
dimeArc::getCenter(dimeVec3f &c) const
{
  c = this->center;
}

inline void 
dimeArc::setRadius(const dxfdouble r)
{
  this->radius = r;
}

inline dxfdouble 
dimeArc::getRadius() const
{
  return this->radius;
}

inline void 
dimeArc::setStartAngle(const dxfdouble a)
{
  this->startAngle = a;
}

inline dxfdouble 
dimeArc::getStartAngle() const
{
  return this->startAngle;
}

inline void 
dimeArc::setEndAngle(const dxfdouble a)
{
  this->endAngle = a;
}

inline dxfdouble 
dimeArc::getEndAngle() const
{
  return this->endAngle;
}
 
#endif // ! DIME_ARC_H

