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

#ifndef DIME_STATE_H
#define DIME_STATE_H

#include <dime/util/Linear.h>

class dimeInsert;

class DIME_DLL_API dimeState
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

