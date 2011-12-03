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

#ifndef DIME_RECORDHOLDER_H
#define DIME_RECORDHOLDER_H

#include <dime/Base.h>

class dimeInput;
class dimeMemHandler;
class dimeOutput;
class dimeRecord;

class DIME_DLL_API dimeRecordHolder : public dimeBase
{
public:
  dimeRecordHolder(const int separator);
  virtual ~dimeRecordHolder();

  void setRecord(const int groupcode, const dimeParam &value, 
		 dimeMemHandler * const memhandler = NULL);
  void setRecords(const int * const groupcodes,
		  const dimeParam * const params,
		  const int numrecords,
		  dimeMemHandler * const memhandler = NULL);
  void setIndexedRecord(const int groupcode, 
                        const dimeParam &value,
                        const int index,
                        dimeMemHandler * const memhandler = NULL);
  
  virtual bool getRecord(const int groupcode,
			 dimeParam &param,
			 const int index = 0) const;
  
  virtual bool read(dimeInput * const in);
  virtual bool write(dimeOutput * const out);
  virtual bool isOfType(const int thetypeid) const;
  virtual int countRecords() const;

  dimeRecord *findRecord(const int groupcode, const int index = 0);

  int getNumRecordsInRecordHolder(void) const;
  dimeRecord * getRecordInRecordHolder(const int idx) const;

protected:
  virtual bool handleRecord(const int groupcode,
			    const dimeParam &param,
			    dimeMemHandler * const memhandler);
  
  bool copyRecords(dimeRecordHolder * const rh, 
		   dimeMemHandler * const memhandler) const;

  virtual bool shouldWriteRecord(const int groupcode) const;

protected:
  dimeRecord **records;
  int numRecords;
  // int separator; // not needed ?

private:
  void setRecordCommon(const int groupcode, const dimeParam &param,
                       const int index, dimeMemHandler * const memhandler);

}; // class dimeRecordHolder

#endif // ! DIME_RECORDHOLDER_H

