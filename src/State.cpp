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
  \class dimeState dime/State.h
  \brief The dimeState class manages various state variables while the
  model is traversed.
*/

#include <dime/State.h>

/*!
  Constructor.
*/

dimeState::dimeState(const bool traversePolylineVertices,
		   const bool explodeInserts) 
{
  this->matrix.makeIdentity();
  this->invmatrix.makeIdentity();
  this->currentInsert = NULL;
  this->flags = 0;
  if (traversePolylineVertices) {
    this->flags |= TRAVERSE_POLYLINE_VERTICES;
  }
  if (explodeInserts) {
    this->flags |= EXPLODE_INSERTS;
  }
}

/*!
  Constructor.
*/

dimeState::dimeState(const dimeState &st) 
{
  this->matrix = st.matrix;
  this->invmatrix = st.invmatrix;
  this->flags = st.flags;
  this->currentInsert = st.currentInsert;
}

void 
dimeState::setMatrix(const dimeMatrix &m)
{
  this->matrix = m;
  this->flags |= INVMATRIX_DIRTY;
}


const dimeMatrix &
dimeState::getInvMatrix() const 
{
  if (this->flags & INVMATRIX_DIRTY) {
    dimeState *thisp = (dimeState*)this;
    thisp->invmatrix = thisp->matrix;
    thisp->invmatrix.inverse();
    thisp->flags ^= INVMATRIX_DIRTY;
  }
  return this->invmatrix;
}

void 
dimeState::getMatrix(dimeMatrix &m) const 
{
  m = this->matrix;
}

