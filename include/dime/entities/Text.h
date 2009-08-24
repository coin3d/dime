/**************************************************************************\
 * 
 *  FILE: Text.h
 *
 *  This source file is part of DIME.
 *  Copyright (C) 1998-1999 by Systems In Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License, version 2, as
 *  published by the Free Software Foundation.
 *
 *  This library is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License (the accompanying file named COPYING) for more
 *  details.
 *
 **************************************************************************
 *
 *  If you need DIME for a non-GPL project, contact Systems In Motion
 *  to acquire a Professional Edition License:
 *
 *  Systems In Motion                                   http://www.sim.no/
 *  Prof. Brochs gate 6                                       sales@sim.no
 *  N-7030 Trondheim                                   Voice: +47 22114160
 *  NORWAY                                               Fax: +47 67172912
 *
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

