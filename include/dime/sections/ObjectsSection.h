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

#ifndef DIME_OBJECTSSECTION_H
#define DIME_OBJECTSSECTION_H

#include <dime/sections/Section.h>
#include <dime/util/Array.h>

class DIME_DLL_API dimeObjectsSection : public dimeSection
{
  friend class dimeModel;

public:
  dimeObjectsSection(dimeMemHandler * const memhandler = NULL);
  virtual ~dimeObjectsSection();

  virtual const char *getSectionName() const; 
  virtual dimeSection *copy(dimeModel * const model) const;
  
  virtual bool read(dimeInput * const file);
  virtual bool write(dimeOutput * const file);
  virtual int typeId() const;
  virtual int countRecords() const;

  int getNumObjects() const;
  class dimeObject *getObject(const int idx);
  void removeObject(const int idx);
  void insertObject(dimeObject * const object, const int idx = -1); 
  
private:
  dimeArray <dimeObject*> objects;

}; // class dimeObjectsSection

#endif // ! DIME_OBJECTSSECTION_H

