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

#include "convert_funcs.h"
#include <dime/convert/layerdata.h>
#include "linesegment.h"
#include <dime/entities/LWPolyline.h>
#include <dime/util/Linear.h>
#include <dime/State.h>

void 
convert_lwpolyline(const dimeEntity *entity, const dimeState *state, 
		   dxfLayerData *layerData, dxfConverter *)
{
  dimeLWPolyline *pline = (dimeLWPolyline*)entity;

  dimeMatrix matrix;
  state->getMatrix(matrix);

  dimeVec3f e = pline->getExtrusionDir();
  dxfdouble thickness = pline->getThickness();
  
  if (e != dimeVec3f(0,0,1)) {
    dimeMatrix m;
    dimeEntity::generateUCS(e, m);
    matrix.multRight(m);
  }
  e = dimeVec3f(0,0,1) * thickness;

  float elev = pline->getElevation();
  if (!dime_finite(elev)) elev = 0.0f;
  
  int n = pline->getNumVertices();
  if (n <= 0) return;
  
  dxfdouble constantWidth = pline->getConstantWidth();
  const dxfdouble *x = pline->getXCoords();
  const dxfdouble *y = pline->getYCoords();
  const dxfdouble *sw = pline->getStartingWidths();
  const dxfdouble *ew = pline->getEndWidths();
  dimeVec3f v0, v1;
  
#define SET_SEGMENT(s, i0, i1) \
  s.set(dimeVec3f(x[i0], y[i0], elev), \
        dimeVec3f(x[i1], y[i1], elev), \
        sw ? sw[i0] : constantWidth, \
        ew ? ew[i0] : constantWidth, \
        thickness)

  dxfLineSegment segment, nextseg, prevseg;

  bool closed = pline->getFlags() & 1;
  int stop = closed ? n : n-1;
  int next, next2;

  for (int i = 0; i < stop; i++) {
    next = (i+1) % n;
    
    if (i == 0) {
      SET_SEGMENT(segment, i, next);
      if (closed) {
	SET_SEGMENT(prevseg, n-1, 0);
      }
    }
    
    next2 = (i+2) % n;
    SET_SEGMENT(nextseg, next, next2);
    
    segment.convert(i > 0 || closed ? &prevseg : NULL, 
		    i < (stop-1) ? &nextseg : NULL, 
		    layerData, &matrix);
    
    prevseg = segment;
    segment = nextseg;
  }
#undef SET_SEGMENT
}

