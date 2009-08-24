/**************************************************************************\
 * 
 *  FILE: Text.cpp
 *
 *  This source file is part of DIME.
 *  Copyright (C) 1998-1999 by Systems In Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License, version 2, as
 *  published by the Free Software Foundation.
 *
 *  This library is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License (the accompanying file named COPYING) for more
 *  details.
 *
 **************************************************************************
 *
 *  If you need DIME for a non-GPL project, contact Systems In Motion
 *  to acquire a Professional Edition License:
 *
 *  Systems In Motion                                   http://www.sim.no/
 *  Prof. Brochs gate 6                                       sales@sim.no
 *  N-7030 Trondheim                                   Voice: +47 22114160
 *  NORWAY                                               Fax: +47 67172912
 *
\**************************************************************************/

/*!
  \class dimeText dime/entities/Text.h
  \brief The dimeText class handles a Text \e entity.
*/

#include <dime/entities/Text.h>
#include <dime/records/Record.h>
#include <dime/Input.h>
#include <dime/Output.h>
#include <dime/util/MemHandler.h>
#include <dime/Model.h>
#include <math.h>
#include <string.h>
#include <stddef.h>

#define CHAR_ASP 0.82

static char entityName[] = "TEXT";

/*!
  Constructor.
*/

dimeText::dimeText() 
  : origin( 0.0, 0.0, 0.0 ), second( 0.0, 0.0, 0.0 ), haveSecond( false ), height( 0.0 ), width( 0.0 ), rotation( 0.0 ), wScale( 0.0 ), hJust(0), vJust(0), text( NULL )
{
}

//!

void dimeText::setTextString(const char* s)
{
  size_t l;
  l = strlen( s );
  char* t = new char[l+1];
  strcpy( t, s );
  this->text = (char*) t;

  // Set new width.
  this->width = this->height * CHAR_ASP * strlen( this->text );
  if( this->wScale != 0.0 ) 
    this->width = this->width * this->wScale;

  //??? Set new origin or second if hJust is set?
}

//!

dimeEntity *
dimeText::copy(dimeModel * const model) const
{
  dimeText *t = new(model->getMemHandler()) dimeText;
  if (!t) return NULL;
  
  if (!this->copyRecords(t, model)) {
    // check if allocated on heap.
    if (!model->getMemHandler()) delete t;
    t = NULL;
  }
  else {
    t->origin = this->origin;
    t->second = this->second;
    t->haveSecond = this->haveSecond;
    t->height = this->height;
    t->width = this->width;
    t->rotation = this->rotation;
    t->wScale = this->wScale;
    t->hJust = this->hJust;
    t->vJust = this->vJust;
    size_t l;
    l = strlen( this->text );
    char* s = new char[l+1];
    strcpy( s, this->text );
    t->text = (char*) s;
    t->copyExtrusionData(this);
  }
  return t;  
}

//!

bool 
dimeText::write(dimeOutput * const file)
{
  this->preWrite(file);
  
  // Write a text subclass before first controlled record.
  file->writeGroupCode(100);
  file->writeString("AcDbText");

  file->writeGroupCode(1);

  file->writeString(this->text);

  file->writeGroupCode(10);
  file->writeDouble(this->origin[0]);
  file->writeGroupCode(20);
  file->writeDouble(this->origin[1]);
  file->writeGroupCode(30);
  file->writeDouble(this->origin[2]);
  
  file->writeGroupCode(40);
  file->writeDouble(this->height);

  if( this->wScale != 0.0 ) {
    file->writeGroupCode(41);
    file->writeDouble(this->wScale);
  }

  if( this->rotation != 0.0 ) {
    file->writeGroupCode(50);
    file->writeDouble(this->rotation);
  }

  if( this->hJust != 0 ) {
    file->writeGroupCode(72);
    file->writeInt16( (int16) this->hJust);
  }

  if( haveSecond ) {
    file->writeGroupCode(11);
    file->writeDouble(this->second[0]);
    file->writeGroupCode(21);
    file->writeDouble(this->second[1]);
    file->writeGroupCode(31);
    file->writeDouble(this->second[2]);

  }

  // For some reason a new subclass record is needed here.
  file->writeGroupCode(100);
  file->writeString("AcDbText");

  // The write order appears to be an issue???
  if( this->vJust != 0 ) {
    file->writeGroupCode(73);
    file->writeInt16( (int16) this->vJust);
  }

  return this->writeExtrusionData(file) && dimeEntity::write(file);
}

//!

int 
dimeText::typeId() const
{
  return dimeBase::dimeTextType;
}

//!

bool 
dimeText::handleRecord(const int groupcode,
		     const dimeParam &param,
		     dimeMemHandler * const memhandler)
{

  char subclass[80];

  switch(groupcode) {
  case 1:
    this->setTextString( param.string_data );
    if( this->height != 0.0 ) 
      this->width = this->height * CHAR_ASP * strlen( this->text );
    if( wScale != 0.0 ) 
      this->width = this->width * wScale;
    return true;
  case 10:
  case 20:
  case 30:
    this->origin[( groupcode / 10 ) - 1] = param.double_data;
    return true;
  case 11:
  case 21:
  case 31:
    this->second[( ( groupcode - 1 ) / 10 ) - 1] = param.double_data;
    this->haveSecond = true;
    return true;
  case 40:
    this->height = param.double_data;
    if( this->text != NULL ) 
      this->width = this->height * CHAR_ASP * strlen( this->text );
    if( wScale != 0.0 ) 
      this->width = this->width * wScale;
    return true;
  case 41:
    wScale = param.double_data;
    if( this->width != 0.0 ) 
      this->width = this->width * wScale;
    return true;
  case 50:
    this->rotation = param.double_data;
    return true;
  case 72:
    this->hJust = param.int32_data;
    return true;
  case 73:
    this->vJust = param.int32_data;
    return true;
  case 100:
    // Eat AcDbText records, leave others.
    if( strcmp( param.string_data, "AcDbText" ) == 0 ) {
      return true;
    }
    else {
      return dimeExtrusionEntity::handleRecord(groupcode, param, memhandler);
    }
  }
  return dimeExtrusionEntity::handleRecord(groupcode, param, memhandler);
}

//!

const char *
dimeText::getEntityName() const
{
  return entityName;
}

//!

bool 
dimeText::getRecord(const int groupcode,
		  dimeParam &param,
		  const int index) const
{
  switch(groupcode) {
  case 1:
    param.string_data = this->text;
    return true;
  case 10:
  case 20:
  case 30:
    param.double_data = this->origin[groupcode / 10 - 1];
    return true;
  case 11:
  case 21:
  case 31:
    param.double_data = this->second[( groupcode - 1 ) / 10 - 1];
    return true;
  case 40:
    param.double_data = this->height;
    return true;
  case 41:
    if( this->wScale == 0 ) return false;
    param.double_data = this->wScale;
    return true;
  case 50:
    param.double_data = this->rotation;
    return true;
  case 72:
    param.int32_data = this->hJust;
    return true;
  case 73:
    param.int32_data = this->vJust;
    return true;
  }
  return dimeExtrusionEntity::getRecord(groupcode, param, index);
}

//!

void
dimeText::print() const
{
  fprintf(stderr,"Text:\n");
  fprintf(stderr, " origin: %.3f %.3f %.3f\n", 
	  origin[0], origin[1], origin[2]);
  if( haveSecond ) {
    fprintf(stderr, " second: %.3f %.3f %.3f\n", 
	    second[0], second[1], second[2]);
  }
  fprintf(stderr, " height: %f\n", height);
  fprintf(stderr, " rotation: %f\n", rotation);
  fprintf(stderr, " horizJust: %d\n", hJust);
  fprintf(stderr, " vertJust: %d\n", vJust);
  fprintf(stderr, " text: %s\n", text);
  fprintf(stderr, " extrusionDir: %f %f %f\n", 
	  extrusionDir[0], extrusionDir[1], extrusionDir[2]);
  fprintf(stderr, " thickness: %f\n", thickness);
}

//!

dimeEntity::GeometryType 
dimeText::extractGeometry(dimeArray <dimeVec3f> &verts,
			dimeArray <int> &indices,
			dimeVec3f &extrusionDir,
			dxfdouble &thickness)
{

  thickness = this->thickness;
  extrusionDir = this->extrusionDir;

  // find points at corners of box around text.
  verts.append(origin);
  verts.append( dimeVec3f(this->origin.x + this->width, this->origin.y, 0.0) );
  verts.append( dimeVec3f(this->origin.x + this->width, this->origin.y + this->height, 0.0) );
  verts.append( dimeVec3f(this->origin.x, this->origin.y + this->height, 0.0) );

  // close loop with first point.
  verts.append(origin);

  if (this->thickness == 0.0) return dimeEntity::LINES;
  else return dimeEntity::POLYGONS;
}

//!

int
dimeText::countRecords() const
{
  int cnt = 1 + 3 + 3 + 1 + 1 + 1 + 1 + 1 + 1 + 1; // header + origin + second + haveSecond + height + rotation + wScale + hJust + vJust + text
  
  return cnt + dimeExtrusionEntity::countRecords();
}

