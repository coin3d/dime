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

#ifndef DIME_EXTRUSIONENTITY_H
#define DIME_EXTRUSIONENTITY_H

#include <dime/entities/Entity.h>

class DIME_DLL_API dimeExtrusionEntity : public dimeEntity
{
public:
  dimeExtrusionEntity();

  virtual bool getRecord(const int groupcode,
			 dimeParam &param,
			 const int index = 0) const;

  void setExtrusionDir(const dimeVec3f &v);
  const dimeVec3f &getExtrusionDir() const;

  void setThickness(const dxfdouble val);
  dxfdouble getThickness() const;
    
  virtual int typeId() const;
  virtual bool isOfType(const int thtypeid) const;
  virtual int countRecords() const;

protected:

  virtual bool handleRecord(const int groupcode,
			    const dimeParam &param,
			    dimeMemHandler * const memhandler);  

  void copyExtrusionData(const dimeExtrusionEntity * const entity);
  bool writeExtrusionData(dimeOutput * const out);
  
protected: // should be private :-(
  dimeVec3f extrusionDir;
  dxfdouble thickness;

}; // class dimeExtrusionEntity

inline void 
dimeExtrusionEntity::setExtrusionDir(const dimeVec3f &v)
{
  this->extrusionDir = v;
}

inline const dimeVec3f &
dimeExtrusionEntity::getExtrusionDir() const
{
  return this->extrusionDir;
}

inline void 
dimeExtrusionEntity::setThickness(const dxfdouble val)
{
  this->thickness = val;
}

inline dxfdouble 
dimeExtrusionEntity::getThickness() const
{
  return this->thickness;
}

#endif // ! DIME_EXTRUSIONENTITY_H

