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

#ifndef DIME_LWPOLYLINE_H
#define DIME_LWPOLYLINE_H

#include <dime/entities/ExtrusionEntity.h>

class DIME_DLL_API dimeLWPolyline : public dimeExtrusionEntity
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
				       dxfdouble &thickness);
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

