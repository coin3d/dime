/**************************************************************************\
 * 
 *  FILE: LWPolyline.h
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

#ifndef DIME_LWPOLYLINE_H
#define DIME_LWPOLYLINE_H

#include <dime/entities/ExtrusionEntity.h>

class dimeLWPolyline : public dimeExtrusionEntity
{
public:
  dimeLWPolyline();
  virtual ~dimeLWPolyline();

  virtual dimeEntity *copy(dimeModel * const model) const;
  virtual bool getRecord(const int groupcode,
			 dimeParam &param,
			 const int index) const;
  virtual const char *getEntityName() const;

  virtual void print() const;
  virtual bool write(dimeOutput * const out);
  virtual int typeId() const;
  virtual int countRecords() const;
  
  virtual GeometryType extractGeometry(dimeArray <dimeVec3f> &verts,
				       dimeArray <int> &indices,
				       dimeVec3f &extrusionDir,
				       float &thickness);
  int getNumVertices() const;
  const dxfdouble *getXCoords() const;
  const dxfdouble *getYCoords() const;
  const dxfdouble *getStartingWidths() const;
  const dxfdouble *getEndWidths() const;
  const dxfdouble *getBulges() const;

  dxfdouble getElevation() const;
  dxfdouble getConstantWidth() const;
  int16 getFlags() const;
 
protected:
  virtual bool handleRecord(const int groupcode,
			    const dimeParam &param,
                            dimeMemHandler * const memhandler);

private:
  dxfdouble constantWidth;
  dxfdouble elevation;
  int16 flags;
  int32 numVertices;
  int16 tmpCounter; // used during loading only
  int16 tmpFlags;   //     ""
  dxfdouble *xcoord;
  dxfdouble *ycoord;
  dxfdouble *startingWidth;
  dxfdouble *endWidth;
  dxfdouble *bulge;

}; // class dimeLWPolyLine


inline int 
dimeLWPolyline::getNumVertices() const
{
  return this->numVertices;
}

inline const dxfdouble *
dimeLWPolyline::getXCoords() const
{
  return this->xcoord;
}
inline const dxfdouble *
dimeLWPolyline::getYCoords() const
{
  return this->ycoord;
}

inline const dxfdouble *
dimeLWPolyline::getStartingWidths() const
{
  return this->startingWidth;

}

inline const dxfdouble *
dimeLWPolyline::getEndWidths() const
{
  return this->endWidth;
}

inline const dxfdouble *
dimeLWPolyline::getBulges() const
{
  return this->bulge;
}

inline dxfdouble 
dimeLWPolyline::getElevation() const
{
  return this->elevation;
}

inline dxfdouble 
dimeLWPolyline::getConstantWidth() const
{
  return this->constantWidth;
}

inline int16 
dimeLWPolyline::getFlags() const
{
  return this->flags;
}


#endif // ! DIME_LWPOLYLINE_H

