/**************************************************************************\
 * 
 *  FILE: State.h
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

#ifndef DIME_STATE_H
#define DIME_STATE_H

#include <dime/util/Linear.h>

class dimeInsert;

class dimeState
{
public:
  dimeState(const bool traversePolylineVertices,
	    const bool explodeInserts);
  dimeState(const dimeState &st);
  
  const dimeMatrix &getMatrix() const;
  const dimeMatrix &getInvMatrix() const;
  void getMatrix(dimeMatrix &m) const;
  void setMatrix(const dimeMatrix &matrix);
  
  enum {
    TRAVERSE_POLYLINE_VERTICES = 0x1,
    EXPLODE_INSERTS = 0x2,
    // private flags
    PUBLIC_MASK = 0x7fff,
    PRIVATE_MASK = 0x8000,
    INVMATRIX_DIRTY = 0x8000
  };

  void setFlags(const unsigned int flags);
  unsigned int getFlags() const;

  const dimeInsert *getCurrentInsert() const;

private:
  friend class dimeInsert;
  dimeMatrix matrix;
  dimeMatrix invmatrix; // to speed up things...
  unsigned int flags;
  const dimeInsert *currentInsert;
}; // class dimeState

inline const dimeMatrix &
dimeState::getMatrix() const {
  return this->matrix;
}

inline void 
dimeState::setFlags(const unsigned int flags)
{
  this->flags = (this->flags & PRIVATE_MASK) | flags;
}
 
inline unsigned int 
dimeState::getFlags() const
{
  return (this->flags & PUBLIC_MASK);
}

inline const dimeInsert *
dimeState::getCurrentInsert() const
{
  return this->currentInsert;
}

#endif // ! DIME_STATE_H

