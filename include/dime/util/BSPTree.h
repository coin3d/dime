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

#ifndef DIME_BSPTREE_H
#define DIME_BSPTREE_H

#include <dime/Basic.h>
#include <dime/util/Array.h>
#include <dime/util/Linear.h>

class dimeBox;
class dime_bspnode;

class DIME_DLL_API dimeBSPTree
{
public:
  dimeBSPTree(const int maxnodepts = 64, const int initsize = 4);
  ~dimeBSPTree();
  
  int numPoints() const;
  void getPoint(const int idx, dimeVec3f &pt);
  void *getUserData(const int idx) const;
  
  void setUserData(const int idx, void * const data);
  
  int addPoint(const dimeVec3f &pt, void * const userdata = NULL);
  int removePoint(const dimeVec3f &pt);
  void removePoint(const int idx);
  int findPoint(const dimeVec3f &pos) const;
  void clear(const int initsize = 4);
  
  const dimeBox *getBBox() const;
  
private:
  friend class dime_bspnode;
  dimeArray <dimeVec3f> pointsArray;
  dimeArray <void*> userdataArray;
  dime_bspnode *topnode;
  int maxnodepoints;
  dimeBox *boundingBox;
}; // class dimeBSPTree

#endif // ! DIME_BSPTREE_H

