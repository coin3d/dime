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

#ifndef DIME_ELLIPSE_H
#define DIME_ELLIPSE_H

#include <dime/Basic.h>
#include <dime/entities/ExtrusionEntity.h>
#include <dime/util/Linear.h>

//
// please note that the thickness will always be 0.0 for this entity
//

class DIME_DLL_API dimeEllipse : public dimeExtrusionEntity
{
public:
  dimeEllipse();

  void setCenter(const dimeVec3f &c);
  const dimeVec3f &getCenter() const;

  void setMajorAxisEndpoint(const dimeVec3f &v);
  const dimeVec3f &getMajorAxisEndpoint() const;
  
  void setMinorMajorRatio(const dxfdouble ratio);
  dxfdouble getMinorMajorRatio() const;

  void setStartParam(const dxfdouble p);
  dxfdouble getStartParam() const;

  void setEndParam(const dxfdouble p);
  dxfdouble getEndParam() const;
  
  virtual dimeEntity *copy(dimeModel * const model) const;
  virtual bool getRecord(const int groupcode,
			 dimeParam &param,
			 const int index = 0) const;
  virtual const char *getEntityName() const;
  virtual void print() const;
  virtual bool write(dimeOutput * const out);
  virtual int typeId() const;
  virtual int countRecords() const;

protected:  
  virtual bool handleRecord(const int groupcode,
			    const dimeParam &param,
			    dimeMemHandler * const memhandler);  
private:
  dimeVec3f center;
  dimeVec3f majorAxisEndpoint;
  dxfdouble ratio;
  dxfdouble startParam;
  dxfdouble endParam;

}; // class dimeEllipse

inline const dimeVec3f &
dimeEllipse::getCenter() const
{
  return this->center;
}

inline void 
dimeEllipse::setCenter(const dimeVec3f &c)
{
  this->center = c;
}

inline void
dimeEllipse::setMajorAxisEndpoint(const dimeVec3f &v)
{
  this->majorAxisEndpoint = v;
}

inline const dimeVec3f &
dimeEllipse::getMajorAxisEndpoint() const
{
  return this->majorAxisEndpoint;
}
  
inline void 
dimeEllipse::setMinorMajorRatio(const dxfdouble ratio)
{
  this->ratio = ratio;
}

inline dxfdouble 
dimeEllipse::getMinorMajorRatio() const
{
  return this->ratio;
}

inline void 
dimeEllipse::setStartParam(const dxfdouble p)
{
  this->startParam = p;
}

inline dxfdouble 
dimeEllipse::getStartParam() const
{
  return this->startParam;
}

inline void 
dimeEllipse::setEndParam(const dxfdouble p)
{
  this->endParam = p;
}

inline dxfdouble 
dimeEllipse::getEndParam() const
{
  return this->endParam;
}

#endif // ! DIME_ELLIPSE_H

