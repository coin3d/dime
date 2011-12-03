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

#ifndef DIME_TEXT_H
#define DIME_TEXT_H
  
#include <dime/Basic.h>
#include <dime/entities/ExtrusionEntity.h>

class DIME_DLL_API dimeText : public dimeExtrusionEntity
{
public:
  dimeText();
//  dimeText(const char* s);

  void setOrigin(const dimeVec3f &o);
  void getOrigin(dimeVec3f &o) const;
  void setSecond(const dimeVec3f &s);
  bool getSecond(dimeVec3f &s) const;
  void setHeight(const dxfdouble h);
  dxfdouble getHeight() const;
  void setWidth(const dxfdouble w);
  dxfdouble getWidth() const;
  void setRotation(const dxfdouble a);
  dxfdouble getRotation() const;
  void setHJust(const int32 h);
  int32 getHJust() const;
  void setVJust(const int32 v);
  int32 getVJust() const;
  void setTextString(const char* s);
  char* getTextString() const;
  
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
  dimeVec3f origin;
  dimeVec3f second;
  bool haveSecond;
  dxfdouble height;
  dxfdouble width;
  dxfdouble rotation;
  dxfdouble wScale;
  int32 hJust;
  int32 vJust;
  char* text;

}; // class dimeText

//
// inline methods
//


inline void 
dimeText::setOrigin(const dimeVec3f &o)
{
  this->origin = o;
}

inline void 
dimeText::getOrigin(dimeVec3f &o) const
{
  o = this->origin;
}

inline void 
dimeText::setSecond(const dimeVec3f &s)
{
  this->second = s;
}

inline bool 
dimeText::getSecond(dimeVec3f &s) const
{
  if( haveSecond ) {
    s = this->second;
    return true;
  }
  else {
    return false;
  }
}

inline void 
dimeText::setHeight(const dxfdouble h)
{
  this->height = h;
}

inline dxfdouble 
dimeText::getHeight() const
{
  return this->height;
}

inline void 
dimeText::setWidth(const dxfdouble w)
{
  this->width = w;
}

inline dxfdouble 
dimeText::getWidth() const
{
  return this->width;
}

inline void 
dimeText::setRotation(const dxfdouble a)
{
  this->rotation = a;
}

inline dxfdouble 
dimeText::getRotation() const
{
  return this->rotation;
}

inline void 
dimeText::setHJust(const int32 h)
{
  this->hJust = h;
}

inline int32 
dimeText::getHJust() const
{
  return this->hJust;
}

inline void 
dimeText::setVJust(const int32 v)
{
  this->vJust = v;
}

inline int32
dimeText::getVJust() const
{
  return this->vJust;
}

//inline void 
//dimeText::setTextString(const char* s)
//{
  //this->text = s;
//}

inline char* 
dimeText::getTextString() const
{
  return this->text;
}
 
#endif // ! DIME_TEXT_H

