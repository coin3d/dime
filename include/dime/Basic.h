/**************************************************************************\
 * 
 *  FILE: Basic.h
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

#ifndef DIME_BASIC_H
#define DIME_BASIC_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>
#include <math.h>

// we prefer to use floats to save mem. Applications needing
// scientific calculations should typedef this to double
typedef float dxfdouble;

#define DXFABS(x) ((x)<0?-(x):(x))
#define DXFMAX(x,y) ((x)>(y)?(x):(y))
#define DXFMIN(x,y) ((x)<(y)?(x):(y))
#define DXFDEG2RAD(x) (M_PI*(x)/180.0f)
#define DXFRAD2DEG(x) (180.0f*(x)/M_PI)

#ifdef __sgi
#define bool int
#define true 1
#define false 0
#endif // __sgi

template <class T> inline
T DXFSQR(const T x)
{
  return x*x;
}

#if defined(__BEOS__)
#include <support/SupportDefs.h>
#else // ! defined(__BEOS__)
typedef signed char int8;
typedef unsigned char uint8;
typedef signed short int16;
typedef unsigned short uint16;
#ifdef _WIN32
typedef long int32;
#else // ! defined(_WIN32)
typedef signed int int32;
#endif // ! defined(_WIN32)
typedef unsigned int uint32;
#endif // ! defined(__BEOS__)

#ifdef macintosh
 char* strdup( const char* );
#endif
 
#define ARRAY_NEW(memh, type, num) \
memh ? (type*) memh->allocMem(num*sizeof(type)) : new type[num]

#define DXF_STRCPY(mh, d, s) \
mh ? d = mh->stringAlloc(s) : d = new char[strlen(s)+1]; if (d) strcpy(d,s)

typedef bool dimeCallbackFunc(const class dimeState * const, class dimeEntity *, void *);
typedef dimeCallbackFunc * dimeCallback;

typedef union {
  int8  int8_data;
  int16 int16_data;
  int32 int32_data;
  float float_data;
  dxfdouble double_data;
  const char *string_data;
  const char *hex_data;
} dimeParam;

#endif // ! DIME_BASIC_H

