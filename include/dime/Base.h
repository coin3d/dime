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

#ifndef DIME_BASE_H
#define DIME_BASE_H

#include <dime/Basic.h>
#include <stddef.h>  // for size_t

class dimeMemHandler;

class DIME_DLL_API dimeBase
{
public:
  enum {
    dimeBaseType = 1,
    dimeRecordType,
    dimeStringRecordType,
    dimeFloatRecordType,
    dimeDoubleRecordType,
    dimeInt8RecordType,
    dimeInt16RecordType,
    dimeInt32RecordType,
    dimeHexRecordType,
    dimeRecordHolderType,
    dimeClassType,
    dimeUnknownClassType,
    dimeObjectType,
    dimeUnknownObjectType,
    dimeEntityType,
    dimeUnknownEntityType,
    dimePolylineType,
    dimeVertexType,
    dimeFaceEntityType,
    dimeExtrusionEntityType,
    dime3DFaceType,
    dimeSolidType,
    dimeTraceType,
    dimeLineType,
    dimeTextType,
    dimePointType,
    dimeBlockType,
    dimeInsertType,
    dimeCircleType,
    dimeArcType,
    dimeLWPolylineType,
    dimeEllipseType,
    dimeSplineType,
    dimeSectionType,
    dimeUnknownSectionType,
    dimeEntitiesSectionType,
    dimeBlocksSectionType,
    dimeTablesSectionType,
    dimeHeaderSectionType,
    dimeClassesSectionType,
    dimeObjectsSectionType,
    dimeTableType,
    dimeTableEntryType,
    dimeUnknownTableType,
    dimeUCSTableType,
    dimeLayerTableType,

    // this should be last
    dimeLastTypeTag
  };
  dimeBase(void);
  virtual ~dimeBase();
  
  virtual int typeId() const = 0;
  virtual bool isOfType(const int thetypeid) const;
public:
  void *operator new(size_t size, dimeMemHandler *memhandler = NULL, 
		     const int alignment = 4);
  void operator delete(void *ptr);

}; // class dimeBase

#endif // ! DIME_BASE_H

