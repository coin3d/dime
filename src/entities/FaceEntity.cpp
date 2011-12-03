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

/*!
  \class dimeFaceEntity dime/entities/FaceEntity.h
  \brief The dimeFaceEntity class is an abstract class that handles one-face \e entity classes.
*/

#include <dime/entities/FaceEntity.h>
#include <dime/Output.h>

dimeFaceEntity::dimeFaceEntity()
{
  for (int i = 0; i < 4; i++)
    this->coords[i].setValue(0.0, 0.0, 0.0);
}

/*!
  Sets vertices to create a triangle.
*/

void 
dimeFaceEntity::setTriangle(const dimeVec3f &v0, const dimeVec3f &v1,
		       const dimeVec3f &v2)
{
  this->coords[0] = v0;
  this->coords[1] = v1;
  this->coords[2] = coords[3] = v2;
}

/*!
  Sets vertices to create a quad.
*/

void 
dimeFaceEntity::setQuad(const dimeVec3f &v0, const dimeVec3f &v1,
		   const dimeVec3f &v2, const dimeVec3f &v3)
{
  this->coords[0] = v0;
  this->coords[1] = v1;
  this->coords[2] = v2;
  this->coords[3] = v3;
}

/*!
  \fn const dimeVec3f &dimeFaceEntity::getVertex(const int idx) const
  Returns vertex nr \a idx.
*/

/*!
  Returns all four vertices.
*/

void 
dimeFaceEntity::getVertices(dimeVec3f &v0, dimeVec3f &v1,
		       dimeVec3f &v2, dimeVec3f &v3) const
{
  v0 = this->coords[0];
  v1 = this->coords[1];
  v2 = this->coords[2];
  v3 = this->coords[3];
}

/*!
  Copies the coordinates from \a entity.
*/

void 
dimeFaceEntity::copyCoords(const dimeFaceEntity * const entity)
{
  this->coords[0] = entity->coords[0];
  this->coords[1] = entity->coords[1];
  this->coords[2] = entity->coords[2];
  this->coords[3] = entity->coords[3];
}

//!

int 
dimeFaceEntity::typeId() const
{
  return dimeFaceEntityType;
}

//!

bool
dimeFaceEntity::isOfType(const int thetypeid) const
{
  return thetypeid == dimeFaceEntityType ||
    dimeEntity::isOfType(thetypeid);
}

//!

int 
dimeFaceEntity::countRecords() const
{
  return 12 + dimeEntity::countRecords();
}

/*!
  Will write the coordinate data to \a out. Should be called by 
  subclasses at some time during write.
*/

bool 
dimeFaceEntity::writeCoords(dimeOutput * const file)
{
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      file->writeGroupCode((j+1)*10+i);
      file->writeDouble(coords[i][j]);
    }
  }
  return true; // bah, who cares...
}

//!

bool 
dimeFaceEntity::handleRecord(const int groupcode, 
			    const dimeParam &param,
			    dimeMemHandler * const memhandler)
{
  if (groupcode == 10 ||
      groupcode == 11 ||
      groupcode == 12 ||
      groupcode == 13 ||
      groupcode == 20 ||
      groupcode == 21 ||
      groupcode == 22 ||
      groupcode == 23 ||
      groupcode == 30 ||
      groupcode == 31 ||
      groupcode == 32 ||
      groupcode == 33) {
    this->coords[groupcode % 10][groupcode / 10 - 1] = param.double_data;
    return true;
  }
  return dimeEntity::handleRecord(groupcode, param, memhandler);
}

//!

bool 
dimeFaceEntity::getRecord(const int groupcode,
			 dimeParam &param,
			 const int index) const
{
  if (groupcode == 10 ||
      groupcode == 11 ||
      groupcode == 12 ||
      groupcode == 13 ||
      groupcode == 20 ||
      groupcode == 21 ||
      groupcode == 22 ||
      groupcode == 23 ||
      groupcode == 30 ||
      groupcode == 31 ||
      groupcode == 32 ||
      groupcode == 33) {
    param.double_data = 
      this->coords[groupcode % 10][groupcode / 10 - 1];
    return true;
  }
  return dimeEntity::getRecord(groupcode, param, index);
}

//!

dimeEntity::GeometryType 
dimeFaceEntity::extractGeometry(dimeArray <dimeVec3f> &verts,
			       dimeArray <int> &indices,
			       dimeVec3f &extrusionDir,
			       dxfdouble &thickness)
{
  verts.setCount(0);
  indices.setCount(0);
  
  verts.append(this->coords[0]);
  verts.append(this->coords[1]);
  if (this->isQuad()) {
    if (this->swapQuadCoords()) {
      verts.append(this->coords[3]);
      verts.append(this->coords[2]);
    }
    else {
      verts.append(this->coords[2]);
      verts.append(this->coords[3]);
    }
  }
  else {
    verts.append(this->coords[2]);
  }
  
  thickness = getThickness();
  getExtrusionDir(extrusionDir);

  return dimeEntity::POLYGONS;
}  

/*!
  Default method return 0.0. Should be overloaded if this is not
  correct for all cases.
*/

dxfdouble 
dimeFaceEntity::getThickness() const
{
  return 0.0f;
}

/*!
  Default method returns (0,0,1). Should be overloaded if this is not
  correct for all cases.
*/

void 
dimeFaceEntity::getExtrusionDir(dimeVec3f &ed) const
{
  ed.setValue(0,0,1);
}

/*!
  Default function returns \e false. If \e true is returned, the last
  two vertices will be swapped before returning geometry in 
  extractGeometry().
*/

bool 
dimeFaceEntity::swapQuadCoords() const
{
  return false;
}

