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

#ifndef DIME_BLOCKSSECTION_H
#define DIME_BLOCKSSECTION_H

#include <dime/sections/Section.h>
#include <dime/util/Array.h>

class DIME_DLL_API dimeBlocksSection : public dimeSection 
{
public:
  dimeBlocksSection(dimeMemHandler * const memhandler = NULL);
  virtual ~dimeBlocksSection();
  
  virtual const char *getSectionName() const;
  virtual dimeSection *copy(dimeModel * const model) const;
  
public:
  virtual bool read(dimeInput * const file);
  virtual bool write(dimeOutput * const file);
  virtual int typeId() const;
  virtual int countRecords() const;

  void fixReferences(dimeModel * const model);
  
  int getNumBlocks() const;
  class dimeBlock *getBlock(const int idx);
  void removeBlock(const int idx);
  void insertBlock(dimeBlock * const block, const int idx = -1); 

private:
  dimeArray <dimeBlock*> blocks;

}; // class dimeBlocksSection

#endif // ! DIME_BLOCKSSECTION_H

