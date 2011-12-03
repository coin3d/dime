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

#include "linesegment.h"
#include <dime/convert/layerdata.h>

#define FLAG_V_CALCULATED 0x1
#define FLAG_CONNECT_CALCULATED 0x2


#ifdef _WIN32
#define M_PI 3.14159265358979323846
#endif

//
// line_intersection. bounds are not checked, 
// just unlimited lines
//
bool 
intersect_line(const dimeVec3f &v0, // first line
	       const dimeVec3f &v1, //    ""	 
	       const dimeVec3f &v2, // second line
	       const dimeVec3f &v3, //    ""
	       dimeVec3f &isect)
{
  dxfdouble x1 = v0[0];
  dxfdouble y1 = v0[1];
  dxfdouble x2 = v1[0];
  dxfdouble y2 = v1[1];
  dxfdouble x3 = v2[0];
  dxfdouble y3 = v2[1];
  dxfdouble x4 = v3[0];
  dxfdouble y4 = v3[1];
  
  dxfdouble Ax,Bx,Cx,Ay,By,Cy,d,f,num;
  
  Ax = x2-x1;
  Bx = x3-x4;
  Ay = y2-y1;
  By = y3-y4;
  Cx = x1-x3;
  Cy = y1-y3;
  d = By*Cx - Bx*Cy;   // alpha numerator
  f = Ay*Bx - Ax*By;   // both denominator

  // compute intersection coordinates
  
  // check if lines are colinear
  if (f==0.0) { // should never happen
    isect = v1; // just set some value 
    return false;
  }
  num = d*Ax;
  isect[0] = x1 + num / f;
  num = d*Ay;
  isect[1] = y1 + num / f;
  isect[2] = v0[2];

  return true;
}

/*!
  \class dxfLineSegment linesegment.h
  \brief The dxfLineSegment class handles lines with width and/or height.
  This class support several connected line segments. The line segments
  will then be converted to a continous mesh, without cracks, as
  specified in the DXF specification.
*/


/*!
  Sets the data for this line segment. \a startwidth is the width at
  \a p0, \a endwidth is the width at \a p1. \a thickness is the height
  of the line segment.
*/

void 
dxfLineSegment::set(const dimeVec3f &p0, const dimeVec3f &p1,
		    const dxfdouble startwidth, const dxfdouble endwidth,
		    const dxfdouble thickness)
{
  this->flags = 0;
  this->p[0] = p0;
  this->p[1] = p1;
  this->w[0] = startwidth;
  this->w[1] = endwidth;
  this->thickness = thickness;
  this->e = dimeVec3f(0,0,1) * thickness;
  this->dir = p[1]-p[0];
  this->dir.normalize();
  this->wdir = dimeVec3f(0,0,1).cross(dir);
  this->wdir.normalize();
}

/*!
  Converts the line segment to geometry, and puts the geometry into
  \a layerData.
 */
void 
dxfLineSegment::convert(dxfLineSegment *prev, dxfLineSegment *next,
			dxfLayerData *layerData, dimeMatrix *matrix)
{  
  this->calculate_v();
  
  if (this->w[0] > 0.0 || this->w[1] > 0.0) {

    /* fixme: check cases where connect[0] != connect[3] ++ */
    dimeVec3f v0,v1,v2,v3;
    if (prev) {
      prev->calculate_connect(this);
      v0 = prev->connect[2];
      v2 = prev->connect[3];
    }
    else {
      v0 = this->v[0];
      v2 = this->v[2];
    }
    if (next) {
      this->calculate_connect(next);
      v1 = this->connect[0];
      v3 = this->connect[1];
    }
    else {
      v1 = this->v[1];
      v3 = this->v[3];
    }
    
    layerData->addQuad(v0, v1, v3, v2, matrix);
    
    if (thickness != 0.0) {   
      layerData->addQuad(v0+e, v1+e, v3+e, v2+e, matrix);
      layerData->addQuad(v0, v1, v1+e, v0+e, matrix); 
      if (!next) layerData->addQuad(v1, v3, v3+e, v1+e, matrix);
      layerData->addQuad(v3, v2, v2+e, v3+e, matrix);
      if (!prev) layerData->addQuad(v2, v0, v0+e, v2+e, matrix);
    }
  }
  else {
    if (thickness != 0.0) {
      layerData->addQuad(p[0], p[1], p[1]+e, p[0]+e, matrix); 
    }
    else {
      layerData->addLine(p[0], p[1], matrix);
    }
  }
}

//
// private method which calculates the 4 resulting points for this
// line segment (considering width).
//
void
dxfLineSegment::calculate_v()
{
  if (!(this->flags & FLAG_V_CALCULATED)) {
    this->v[0] = p[0]; this->v[1] = p[1];
    dimeVec3f vec = dimeVec3f(0,0,1).cross(this->dir);
    vec.normalize();
    this->v[2] = this->v[0] - vec*this->w[0];
    this->v[3] = this->v[1] - vec*this->w[1];
    this->v[0] += vec*this->w[0];
    this->v[1] += vec*this->w[1];
    this->flags |= FLAG_V_CALCULATED;
  }
}

//
// private method that calculates the intersection points between
// line segments.
//
void 
dxfLineSegment::calculate_connect(dxfLineSegment *next)
{
  if (!(this->flags & FLAG_CONNECT_CALCULATED)) {
    this->calculate_v(); /* make sure these are caluclated */
    next->calculate_v();
    
    dxfdouble angle = this->dir.angle(next->dir);

    //
    // from the dxf specification. If angle > 28, use line
    // intersection even if widths are unequal
    //
    if ((this->w[1] == next->w[0]) || (DXFRAD2DEG(angle) > 28)) {
      // connect where lines intersect. common intersection points      
      dimeVec3f isect;
      intersect_line(this->v[0], this->v[1], 
		     next->v[0], next->v[1],
		     isect);
      this->connect[0] = this->connect[2] = isect;

      intersect_line(this->v[2], this->v[3], 
		     next->v[2], next->v[3],
		     isect);
      this->connect[1] = this->connect[3] = isect;
    }
    else {
      dimeVec3f vec = this->wdir + next->wdir + this->p[1];
      
      dimeVec3f isect;
      intersect_line(this->v[0], this->v[1],
		     this->p[1], vec,
		     isect);
      this->connect[0] = isect;
      
      intersect_line(next->v[0], next->v[1],
		     this->p[1], vec,
		     isect);
      this->connect[2] = isect;

      intersect_line(this->v[2], this->v[3],
		     this->p[1], vec,
		     isect);
      this->connect[1] = isect;

      intersect_line(next->v[2], next->v[3],
		     this->p[1], vec,
		     isect);
      this->connect[3] = isect;
    }
    this->flags |= FLAG_CONNECT_CALCULATED;
  }
}


