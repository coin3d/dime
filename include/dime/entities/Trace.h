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

#ifndef DIME_TRACE_H
#define DIME_TRACE_H
  
#include <dime/entities/FaceEntity.h>
#include <dime/util/Linear.h>

class DIME_DLL_API dimeTrace : public dimeFaceEntity
{
public:
  dimeTrace();

  virtual dxfdouble getThickness() const;
  virtual void getExtrusionDir(dimeVec3f &ed) const;
  void setThickness(const dxfdouble &thickness);
  void setExtrusionDir(const dimeVec3f &ed);

  virtual bool write(dimeOutput * const out);
  virtual int typeId() const;
  virtual dimeEntity *copy(dimeModel * const model) const;
  virtual bool getRecord(const int groupcode,
			 dimeParam &param,
			 const int index = 0) const;
  virtual const char *getEntityName() const;
  virtual int countRecords() const;
  
protected:
  virtual bool swapQuadCoords() const;
  
  virtual bool handleRecord(const int groupcode, 
			    const dimeParam &param,
                            dimeMemHandler * const memhandler);
    
private:
  dimeVec3f extrusionDir;
  dxfdouble thickness;

}; // class dimeTrace

#endif // ! DIME_TRACE_H

