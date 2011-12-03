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
#include <dime/entities/Line.h>
#include <dime/util/Linear.h>
#include <dime/State.h>

void 
convert_line(const dimeEntity *entity, const dimeState *state, 
	     dxfLayerData *layerData, dxfConverter *)
{
  dimeLine *line = (dimeLine*)entity;
  
  dxfdouble thickness;
  dimeVec3f v0, v1;

  dimeMatrix matrix;
  state->getMatrix(matrix);
 
  v0 = line->getCoords(0);
  v1 = line->getCoords(1);

  dimeParam param;
  if (line->getRecord(38, param)) {
    v0[2] = param.double_data;
    v1[2] = param.double_data;
  }

  thickness = line->getThickness();

  if (thickness != 0.0) {
    dimeVec3f v2, v3;
    dimeVec3f e = line->getExtrusionDir();
    v2 = v0 + e * thickness;
    v3 = v1 + e * thickness;

    layerData->addQuad(v0, v1, v3, v2, &matrix);
  }
  else {
    layerData->addLine(v0, v1, &matrix);
  }
}
