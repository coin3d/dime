/**************************************************************************\
 * 
 *  FILE: FaceEntity.h
 *
 *  This source file is part of DIME.
 *  Copyright (C) 1998-1999 by Systems In Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License, version 2, as
 *  published by the Free Software Foundation.  DO NOT MISTAKE THIS LICENSE
 *  FOR THE GNU LGPL LICENSE.
 *
 *  This library is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License (the accompanying file named COPYING) for more
 *  details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 **************************************************************************
 *
 *  If you need DIME for commercial purposes, you can contact Systems In
 *  Motion about acquiring a commercial license.
 *
 *  Systems In Motion                                   http://www.sim.no/
 *  Prof. Brochs gate 6                                       sales@sim.no
 *  N-7030 Trondheim                                   Voice: +47 22114160
 *  NORWAY                                               Fax: +47 67172912
 *
\**************************************************************************/

#ifndef DIME_FACEENTITY_H
#define DIME_FACEENTITY_H

#include <dime/Basic.h>
#include <dime/entities/Entity.h>
#include <dime/util/Linear.h>

class dimeFaceEntity : public dimeEntity 
{
public:
  bool isQuad() const;
  
  virtual bool getRecord(const int groupcode,
			 dimeParam &param,
			 const int index = 0) const;
  
  void setVertex(const int idx, const dimeVec3f &v);
  void setTriangle(const dimeVec3f &v0, const dimeVec3f &v1,
		   const dimeVec3f &v2);
  void setQuad(const dimeVec3f &v0, const dimeVec3f &v1,
	       const dimeVec3f &v2, const dimeVec3f &v3);
  const dimeVec3f &getVertex(const int idx) const;
  void getVertices(dimeVec3f &v0, dimeVec3f &v1,
		   dimeVec3f &v2, dimeVec3f &v3) const;
  
  virtual dxfdouble getThickness() const;
  virtual void getExtrusionDir(dimeVec3f &ed) const;
  
  GeometryType extractGeometry(dimeArray <dimeVec3f> &verts,
			       dimeArray <int> &indices,
			       dimeVec3f &extrusionDir,
			       float &thickness);
  
  virtual int typeId() const;
  virtual bool isOfType(const int thetypeid) const;
  virtual int countRecords() const;

protected:

  virtual bool swapQuadCoords() const;
  
  virtual bool handleRecord(const int groupcode, 
			    const dimeParam &param,
			    dimeMemHandler * const memhandler);
  void copyCoords(const dimeFaceEntity * const entity);
  bool writeCoords(dimeOutput * const file);
  
  dimeFaceEntity();
  dimeVec3f coords[4];

}; // class dimeFaceEntity

inline const dimeVec3f &
dimeFaceEntity::getVertex(const int idx) const
{
  assert(idx >= 0 && idx < 4);
  return this->coords[idx]; 
}

inline bool
dimeFaceEntity::isQuad() const
{
  return (coords[2] != coords[3]);
}

inline void 
dimeFaceEntity::setVertex(const int idx, const dimeVec3f &v)
{
  assert(idx >= 0 && idx < 4);
  this->coords[idx] = v;
}

#endif // ! DIME_FACEENTITY_H

