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
#include <dime/convert/convert.h>
#include <dime/convert/layerdata.h>
#include <dime/entities/Ellipse.h>
#include <dime/util/Linear.h>
#include <dime/State.h>

//
// find intersection between ellipse and the line x=r-maxerr,
// and return the number of subdivisions necessary
// to respect the maxerr parameter.
//
static int 
calc_num_sub(dxfdouble maxerr, dxfdouble a, dxfdouble b)
{
  dxfdouble minrad = a < b ? a : b;

  if (maxerr >= minrad) maxerr = minrad / 40.0f;

  dxfdouble x,y;
  
  if (a >= b) {
    x = a-maxerr;
    y = sqrt((1.0-(x*x)/(a*a))*b*b);
  }
  else {
    x = b-maxerr;
    y = sqrt((1.0-(x*x)/(b*b))*a*a);
  }
  
  dxfdouble rad = atan(y/x);  
  return int(M_PI/fabs(rad)) + 1;
}


void 
convert_ellipse(const dimeEntity *entity, const dimeState *state, 
		dxfLayerData *layerData, dxfConverter *converter)
{
  dimeEllipse *ellipse = (dimeEllipse*) entity;

  dimeMatrix matrix;
  state->getMatrix(matrix);

  dimeVec3f e = ellipse->getExtrusionDir();
  dxfdouble thickness = ellipse->getThickness();
  
  // According to the DXF Intern, Ellipse has no Element coordinate
  // system, so this code is disabled

//   if (e != dimeVec3f(0,0,1) && e != dimeVec3f(0,0,-1)) {
//     dimeMatrix m;
//     dimeEntity::generateUCS(e, m);
//     matrix.multRight(m);
//   }

  e *= thickness;

  dimeVec3f center = ellipse->getCenter();

  // do some cross product magic to calculate minor axis
  dimeVec3f xaxis = ellipse->getMajorAxisEndpoint();

  dimeParam param;
  if (ellipse->getRecord(38, param)) {
    center[2] = param.double_data;
    xaxis[2] = param.double_data;
  }

  dxfdouble xlen = xaxis.length() * 0.5;
  xaxis.normalize();
  dimeVec3f yaxis = dimeVec3f(0,0,1).cross(xaxis);
  yaxis.normalize();
  dimeVec3f zaxis = xaxis.cross(yaxis);
  zaxis.normalize();
  yaxis = zaxis.cross(xaxis);
  yaxis.normalize();
    
  yaxis *= ellipse->getMinorMajorRatio() * xlen;
  xaxis *= xlen;

  dxfdouble numpts = (dxfdouble) converter->getNumSub();
  if (numpts <= 0.0) { // use maxerr
    numpts = calc_num_sub(converter->getMaxerr(), 
			  xlen, xlen*ellipse->getMinorMajorRatio());
  }
  
  dxfdouble rad = ellipse->getStartParam();
  dxfdouble end = ellipse->getEndParam();

  while (end <= rad) end += M_PI*2.0;
  
  dxfdouble size = (2*M_PI) / (end-rad);
  dxfdouble inc = (end-rad) / (numpts * size);  
  
  int i;
  
  dimeVec3f v;
  dimeVec3f prev(center[0] + xaxis[0] * cos(rad) + yaxis[0] * sin(rad),
		 center[1] + xaxis[1] * cos(rad) + yaxis[1] * sin(rad),
		 center[2] + xaxis[2] * cos(rad) + yaxis[2] * sin(rad));
  rad += inc;
  
  for (; rad < end; rad += inc) {
    v =   dimeVec3f(center[0] + xaxis[0] * cos(rad) + yaxis[0] * sin(rad),
		    center[1] + xaxis[1] * cos(rad) + yaxis[1] * sin(rad),
		    center[2] + xaxis[2] * cos(rad) + yaxis[2] * sin(rad));
    
    if (thickness == 0.0) {
      layerData->addLine(prev, v, &matrix);
    }
    else {
      layerData->addQuad(prev, v, v + e, prev + e,
			 &matrix);
    }
    prev = v;
    rad += inc;
  }

  rad = end;
  v =   dimeVec3f(center[0] + xaxis[0] * cos(rad) + yaxis[0] * sin(rad),
		  center[1] + xaxis[1] * cos(rad) + yaxis[1] * sin(rad),
		  center[2] + xaxis[2] * cos(rad) + yaxis[2] * sin(rad));
  if (thickness == 0.0) {
    layerData->addLine(prev, v, &matrix);
  }
  else {
    layerData->addQuad(prev, v, v + e, prev + e,
                       &matrix);
  }
}
