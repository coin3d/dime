/**************************************************************************\
 * 
 *  FILE: Entity.h
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

#ifndef DIME_ENTITY_H
#define DIME_ENTITY_H

#include <dime/Base.h>
#include <dime/Basic.h>
#include <dime/util/Array.h>
#include <dime/util/Linear.h>
#include <dime/RecordHolder.h>


// misc flag values used in entityFlags.
#define FLAG_DELETED         0x0001 // used by dimeEntity
#define FLAG_TMP_BUFFER_SET  0x0002 // see dimeEntity::read()
#define FLAG_VERTICES_FOLLOW 0x0004 // used by dimePolyline
#define FLAG_TAGGED          0x0008 // used by dimeEntity
#define FLAG_COLOR_NUMBER    0x0010 // signals a color number was read 

#define FLAG_FIRST_FREE      0x0020 // use this if you want to define your own flags

class dimeLayer;

class dimeEntity : public dimeRecordHolder
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
				       float &thickness);
protected:

  bool preWrite(dimeOutput * const file);
  
  virtual bool traverse(const dimeState * const state, 
			dimeCallback callback,
			void *userdata);
  
  virtual void fixReferences(dimeModel * const model);
  virtual bool handleRecord(const int groupcode,
			    const dimeParam &param,
			    dimeMemHandler * const memhandler);
  
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

