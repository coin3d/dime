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
#include <dime/entities/Solid.h>
#include <dime/util/Linear.h>
#include <dime/State.h>


void 
convert_solid_data(dimeVec3f *v, dimeVec3f &e, dxfdouble thickness,
		   const dimeState *state,
		   dxfLayerData *layerData)
{
  dimeMatrix matrix;
  state->getMatrix(matrix);

  if (e != dimeVec3f(0,0,1)) {
    dimeMatrix m;
    dimeEntity::generateUCS(e, m);
    matrix.multRight(m);
  }
  e = dimeVec3f(0,0,1) * thickness;
  
  int numunique = 0;
  dimeVec3f u[4];
  
  int i,j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < numunique; j++) {
      if (u[j] == v[i]) break;
    }
    if (j == numunique) {
      u[numunique++] = v[i];
    }
  }

  switch (numunique) {
  case 1:
    if (thickness != 0.0) {
      layerData->addLine(u[0], u[0]+e, &matrix);
    }
    else {
      layerData->addPoint(u[0], &matrix);
    }
    break;
  case 2:
    if (thickness != 0.0) {
      layerData->addQuad(u[0], u[1], u[1]+e, u[0]+e, &matrix);
    }
    else {
      layerData->addLine(u[0], u[1], &matrix);
    }
    break;
  case 3:
    // FIXME: check fillmode
    layerData->addTriangle(u[0], u[1], u[2], &matrix);
    if (thickness != 0.0) {
      layerData->addTriangle(u[0]+e, u[1]+e, u[2]+e, &matrix);
      layerData->addQuad(u[0], u[1], u[1]+e, u[0]+e, &matrix);
      layerData->addQuad(u[1], u[2], u[2]+e, u[1]+e, &matrix);
      layerData->addQuad(u[2], u[0], u[0]+e, u[2]+e, &matrix);
    }
    break;
  case 4:
    // FIXME: check fillmode
    layerData->addQuad(u[0], u[1], u[3], u[2], &matrix);
    if (thickness != 0) {
      layerData->addQuad(u[0]+e, u[1]+e, u[3]+e, u[2]+e, &matrix);
      layerData->addQuad(u[0], u[1], u[1]+e, u[0]+e, &matrix);
      layerData->addQuad(u[1], u[3], u[3]+e, u[1]+e, &matrix);
      layerData->addQuad(u[3], u[2], u[2]+e, u[3]+e, &matrix);
      layerData->addQuad(u[2], u[0], u[0]+e, u[2]+e, &matrix);
    }
    break;
  default:
    fprintf(stderr,"Unexpected error converting SOLID\n");
    break;
  }

}  


void 
convert_solid(const dimeEntity *entity, const dimeState *state, 
	      dxfLayerData *layerData, dxfConverter *converter)
{
  // respect the value in the $FILLMODE header variable
  layerData->setFillmode(converter->getFillmode());

  dimeSolid *solid = (dimeSolid*)entity;
  
  dimeVec3f v[4];
  solid->getVertices(v[0], v[1], v[2], v[3]);

  dimeParam param;
  if (solid->getRecord(38, param)) {
    v[0][2] = param.double_data;
    v[1][2] = param.double_data;
    v[2][2] = param.double_data;
    v[3][2] = param.double_data;
  }

   
  dimeVec3f e;
  solid->getExtrusionDir(e);
  dxfdouble thickness = solid->getThickness();

  convert_solid_data(v, e, thickness, state, layerData);
}
