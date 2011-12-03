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

#ifndef DIME_ENTITY_H
#define DIME_ENTITY_H

#include <dime/Base.h>
#include <dime/Basic.h>
#include <dime/util/Array.h>
#include <dime/util/Linear.h>
#include <dime/RecordHolder.h>


// misc flag values used in entityFlags.
#define FLAG_DELETED          0x0001 // used by dimeEntity
#define FLAG_TMP_BUFFER_SET   0x0002 // see dimeEntity::read()
#define FLAG_VERTICES_FOLLOW  0x0004 // used by dimePolyline
#define FLAG_TAGGED           0x0008 // used by dimeEntity
#define FLAG_COLOR_NUMBER     0x0010 // signals a color number was read 
#define FLAG_SUBCLASS_MARKER  0x0020 // will subclass marker need to be written
#define FLAG_HANDLE           0x0040 // entity has handle in RecordHolder
#define FLAG_ACAD_REACTORS    0x0080 // ACAD reactors in entity
#define FLAG_ACAD_XDICTIONARY 0x0100 // ACAD xdictionary in entity
#define FLAG_PAPERSPACE       0x0200 // entity is in paperspace
#define FLAG_LINETYPE         0x0400 // linetype specified in entity
#define FLAG_FIRST_FREE       0x0800 // use this if you want to define your own flags

class dimeLayer;
class dimeModel;

class DIME_DLL_API dimeEntity : public dimeRecordHolder
{
  friend class dimeEntitiesSection;
  friend class dimeModel;
  friend class dimePolyline;
  friend class dimeBlock;
  friend class dimeInsert;

public:
  dimeEntity();
  virtual ~dimeEntity();

  int16 getEntityFlags() const;
  void setEntityFlags(const int16 flags);

  int16 getColorNumber() const;
  void setColorNumber(const int16 c);

  virtual void setLayer(const dimeLayer * const layer);
  virtual const char *getEntityName() const = 0;
  
  const dimeLayer *getLayer() const; 
  const char *getLayerName() const;
  
  virtual dimeEntity *copy(dimeModel * const model) const = 0; 
  virtual bool read(dimeInput * const in);
  virtual bool write(dimeOutput * const out);
  virtual bool isOfType(const int thetypeid) const;
  virtual int countRecords() const;
  virtual void print() const {}
  
  
  bool isDeleted() const;
  void setDeleted(const bool onOff = true);

  bool isTagged() const;
  void setTagged(const bool onOff = true);

  virtual bool getRecord(const int groupcode,
			 dimeParam &param,
			 const int index = 0) const;
  
  enum GeometryType {
    NONE,
    POLYGONS,
    LINES,
    POINTS
  };
  
  virtual GeometryType extractGeometry(dimeArray <dimeVec3f> &verts,
				       dimeArray <int> &indices,
				       dimeVec3f &extrusionDir,
				       dxfdouble &thickness);
protected:

  bool preWrite(dimeOutput * const file);

  virtual bool traverse(const dimeState * const state, 
			dimeCallback callback,
			void *userdata);
  
  virtual void fixReferences(dimeModel * const model);
  virtual bool handleRecord(const int groupcode,
			    const dimeParam &param,
			    dimeMemHandler * const memhandler);
  virtual bool shouldWriteRecord(const int groupcode) const;
  
public:
  static dimeEntity *createEntity(const char * const name,
				 dimeMemHandler * const memhandler = NULL);
  static bool readEntities(dimeInput * const file, 
			   dimeArray <dimeEntity*> &array, 
			   const char * const stopat);
  
  static bool copyEntityArray(const dimeEntity *const*const array, 
			      const int nument,
			      dimeModel * const model,
			      dimeArray <dimeEntity*> &destarray);  
  static dimeEntity **copyEntityArray(const dimeEntity *const*const array, 
                                     int &nument,
                                     dimeModel * const model);  
  
  static void arbitraryAxis(const dimeVec3f &givenaxis, dimeVec3f &newaxis);
  static void generateUCS(const dimeVec3f &givenaxis, dimeMatrix &m);
  
protected:
  bool copyRecords(dimeEntity * const entity, dimeModel * const model) const;

private:
  const dimeLayer *layer;
  int16 entityFlags;
  int16 colorNumber;
}; // class dimeEntity

inline const dimeLayer *
dimeEntity::getLayer() const
{
  return this->layer;
}

inline int16 
dimeEntity::getColorNumber() const
{
  return this->colorNumber;
}

inline void 
dimeEntity::setColorNumber(const int16 c)
{
  this->colorNumber = c;
}

inline int16 
dimeEntity::getEntityFlags() const
{
  return this->entityFlags;
}

inline void 
dimeEntity::setEntityFlags(const int16 flags)
{
  this->entityFlags = flags;
}



#endif // ! DIME_ENTITY_H

