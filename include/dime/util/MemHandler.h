/**************************************************************************\
 * 
 *  FILE: MemHandler.h
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

#ifndef DIME_MEMHANDLER_H
#define DIME_MEMHANDLER_H

#include <dime/Basic.h>

class dimeMemHandler
{
public:
  dimeMemHandler();
  ~dimeMemHandler();

  bool initOk() const;

  char *stringAlloc(const char * const string);
  void *allocMem(const int size, const int alignment = 4);
  
private:

  class dimeMemNode *bigmemnode; // linked list of big memory chunks 
  class dimeMemNode *memnode;   // linked list of memory nodes.

}; // class dimeMemHandler

#endif // ! DIME_MEMHANDLER_H

