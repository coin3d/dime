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

#ifndef DIME_TABLE_H
#define DIME_TABLE_H

#include <dime/Base.h>
#include <dime/util/Array.h>

class dimeInput;
class dimeModel;
class dimeOutput;
class dimeTableEntry;
class dimeRecord;

class DIME_DLL_API dimeTable : public dimeBase
{
public:
  dimeTable(dimeMemHandler * const memhandler);
  virtual ~dimeTable();
  
  bool read(dimeInput * const in);
  bool write(dimeOutput * const out);
  dimeTable *copy(dimeModel * const model) const;
  int typeId() const;
  int countRecords() const;
  int tableType() const;

  void setTableName(const char * name);
  const char * tableName() const;
  
  int getNumTableEntries() const;
  dimeTableEntry *getTableEntry(const int idx);
  void insertTableEntry(dimeTableEntry * const tableEntry, const int idx = -1);
  void removeTableEntry(const int idx);

  int getNumTableRecords() const;
  dimeRecord *getTableRecord(const int idx);
  void insertTableRecord(dimeRecord * const record, const int idx = -1);
  void removeTableRecord(const int idx);

private:
  int16 maxEntries; // dummy variable read from file
  char * tablename;
  dimeArray <dimeTableEntry*> tableEntries;
  dimeArray <dimeRecord*> records;
  dimeMemHandler *memHandler;
}; // class dimeTable

#endif // ! DIME_TABLE_H

