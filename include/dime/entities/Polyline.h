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

#ifndef DIME_POLYLINE_H
#define DIME_POLYLINE_H

#include <dime/Basic.h>
#include <dime/entities/ExtrusionEntity.h>
#include <dime/util/Array.h>
#include <dime/util/Linear.h>


class dimeVertex;

class DIME_DLL_API dimePolyline : public dimeExtrusionEntity
{
public:
  dimePolyline();
  virtual ~dimePolyline();

  enum Type {
    POLYLINE,
    POLYFACE_MESH,
    POLYGON_MESH
  };

  enum Flags {
    CLOSED            = 0x01,
    POLYMESH_CLOSED_M = 0x01,
    CURVE_FIT         = 0x02,
    SPLINE_FIT        = 0x04,
    IS_POLYLINE_3D    = 0x08,
    IS_POLYMESH_3D    = 0x10,
    POLYMESH_CLOSED_N = 0x20,
    IS_POLYFACE_MESH  = 0x40,
    CONTINOUS_PATTERN = 0x80
  };

  enum SurfaceType {
    NONE            = 0,
    QUADRIC_BSPLINE = 5,
    CUBIC_BSPLINE   = 6,
    BEZIER          = 8
  };

  int16 getFlags() const;
  void setFlags(const int16 flags);

  int getType() const;

  const dimeVec3f &getElevation() const;
  void setElevation(const dimeVec3f &e);

  int16 getPolymeshCountN() const;
  int16 getPolymeshCountM() const;
  int16 getSmoothSurfaceMdensity() const;
  int16 getSmoothSurfaceNdensity() const;

  int getNumCoordVertices() const;
  int getNumIndexVertices() const;
  int getNumSplineFrameControlPoints() const;

  int16 getSurfaceType() const;
  void setSurfaceType(const int16 type);

  dimeVertex *getCoordVertex(const int index);
  dimeVertex *getIndexVertex(const int index);
  dimeVertex *getSplineFrameControlPoint(const int index);

  void setCoordVertices(dimeVertex **vertices, const int num,
			dimeMemHandler * const memhandler = NULL);
  void setIndexVertices(dimeVertex **vertices, const int num,
			dimeMemHandler * const memhandler = NULL);
  void setSplineFrameControlPoints(dimeVertex **vertices, const int num,
				   dimeMemHandler * const memhandler = NULL);

  // KRF, 02-16-2006, added to enable ::copy of new polyline
  void setSeqend(const dimeEntity *ent);

  virtual dimeEntity *copy(dimeModel *const model) const;
  virtual bool getRecord(const int groupcode,
			 dimeParam &param,
			 const int index = 0) const;

  virtual void setLayer(const dimeLayer * const layer);
  virtual const char *getEntityName() const;

  virtual bool read(dimeInput * const in);
  virtual bool write(dimeOutput * const out);
  virtual int typeId() const;
  virtual int countRecords() const;
   
  virtual GeometryType extractGeometry(dimeArray <dimeVec3f> &verts,
				       dimeArray <int> &indices,
				       dimeVec3f &extrusionDir,
				       dxfdouble &thickness);

  void clearSurfaceData();
    
protected:
  virtual bool handleRecord(const int groupcode, 
			    const dimeParam &param,
                            dimeMemHandler * const memhandler);
  virtual bool traverse(const dimeState * const state, 
			dimeCallback callback,
			void *userdata);
  
private:

  int numCoordVertices() const;
  int numIndexVertices() const;
 
  int16 flags;

#ifdef DIME_FIXBIG
  int32 countM;
  int32 countN;
  int32 smoothCountM;
  int32 smoothCountN;
#else
  int16 countM; 
  int16 countN; 
  int16 smoothCountM;
  int16 smoothCountN;
#endif

  int16 surfaceType;
  
  int32 coordCnt;  // real # of coordinate vertices
  int32 indexCnt;  // real # of index vertices
  int32 frameCnt; 
  
  dimeVertex **coordVertices;
  dimeVertex **indexVertices;
  dimeVertex **frameVertices;
  dimeEntity *seqend;
  dimeVec3f elevation;
}; // class dimePolyline

inline int16 
dimePolyline::getFlags() const
{
  return this->flags;
}

inline void 
dimePolyline::setFlags(const int16 flags)
{
  this->flags = flags;
}

inline const dimeVec3f &
dimePolyline::getElevation() const
{
  return elevation;
}

inline void 
dimePolyline::setElevation(const dimeVec3f &e)
{
  this->elevation = e;
}

inline int16 
dimePolyline::getPolymeshCountN() const
{
  return this->countN;
}

inline int16 
dimePolyline::getPolymeshCountM() const
{
  return this->countM;
}

inline int16 
dimePolyline::getSmoothSurfaceMdensity() const
{
  return this->smoothCountM;
}

inline int16 
dimePolyline::getSmoothSurfaceNdensity() const
{
  return this->smoothCountN;
}

inline int 
dimePolyline::getNumCoordVertices() const
{
  return this->coordCnt;
}

inline int 
dimePolyline::getNumIndexVertices() const
{
  return this->indexCnt;
}

inline int
dimePolyline::getNumSplineFrameControlPoints() const
{
  return this->frameCnt;
}

inline dimeVertex *
dimePolyline::getCoordVertex(const int index)
{
  return this->coordVertices[index];
}

inline dimeVertex *
dimePolyline::getIndexVertex(const int index)
{
  return this->indexVertices[index];
}

inline dimeVertex *
dimePolyline::getSplineFrameControlPoint(const int index)
{
  return this->frameVertices[index];
}

inline int16 
dimePolyline::getSurfaceType() const
{
  return this->surfaceType;
}

inline void 
dimePolyline::setSurfaceType(const int16 type)
{
  this->surfaceType = type;
}


#endif // ! DIME_POLYLINE_H

