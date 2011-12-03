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
  \class dimeUnknownSection dime/sections/UnknownSection.h
  \brief The dimeUnknownSection class is used to support unknown sections.
*/

#include <dime/sections/UnknownSection.h>
#include <dime/records/Record.h>
#include <dime/Input.h>
#include <dime/Output.h>
#include <dime/util/MemHandler.h>
#include <dime/util/Array.h>
#include <dime/Model.h>

#include <string.h>
#include <stdio.h>

/*!
  Constructor which stores the sectioname.
*/

dimeUnknownSection::dimeUnknownSection(const char * const sectionname,
				       dimeMemHandler *memhandler)
  : dimeSection(memhandler), records( NULL ), numRecords( 0 )
{
  this->sectionName = new char[strlen(sectionname)+1];
  if (this->sectionName) strcpy(this->sectionName, sectionname);
}

/*!
  Destructor.
*/

dimeUnknownSection::~dimeUnknownSection()
{
  delete [] this->sectionName;
  if (!this->memHandler) {
    for (int i = 0; i < this->numRecords; i++)
      delete this->records[i];
    delete [] this->records;
  }
}

//!

dimeSection *
dimeUnknownSection::copy(dimeModel * const model) const
{
  int i;
  dimeMemHandler *memh = model->getMemHandler();
  dimeUnknownSection *us = new dimeUnknownSection(this->sectionName,
						memh);
  bool ok = us != NULL;
  if (ok && this->numRecords) {
    us->records = ARRAY_NEW(memh, dimeRecord*, this->numRecords);
    bool ok = us->records != NULL;
    if (ok) {
      for (i = 0; i < this->numRecords && ok; i++) {
	us->records[i] = this->records[i]->copy(memh);
	ok = us->records[i] != NULL;
      }
      us->numRecords = i;
    }
  }
  if (!ok) {
    if (!memh) delete us;
    us = NULL;
  }
//  sim_trace("unknown section copy: %p\n", us);
  return us;
}

//!

bool 
dimeUnknownSection::read(dimeInput * const file)
{
  dimeRecord *record;
  bool ok = true;
  dimeArray <dimeRecord*> array(512);
  dimeMemHandler *memhandler = file->getMemHandler();
  
  while (true) {
    record = dimeRecord::readRecord(file);
    if (record == NULL) {
      fprintf(stderr,"could not create/read record (dimeUnknownSection.cpp)"
	      "line: %d\n", file->getFilePosition());
      ok = false;
      break;
    } 
    array.append(record);
    if (record->isEndOfSectionRecord()) break;
  }
  if (ok && array.count()) {
    if (memhandler) {
      this->records = (dimeRecord**)
	memhandler->allocMem(array.count()*sizeof(dimeRecord*));
    }
    else {
      this->records = new dimeRecord*[array.count()];
    }
    if (this->records) {
      int n = this->numRecords = array.count();
      for (int i = 0; i < n; i++)
	this->records[i] = array[i];
    }
  }
  return ok;
}

//!

bool 
dimeUnknownSection::write(dimeOutput * const file)
{
  if (file->writeGroupCode(2) && file->writeString(this->sectionName)) {
    int i;
    for (i = 0; i < this->numRecords; i++) {
      if (!this->records[i]->write(file)) break;
    }
    if (i == this->numRecords) return true;
  }
  return false;
}

//!

int 
dimeUnknownSection::typeId() const
{
  return dimeBase::dimeUnknownSectionType;
}

//!

int
dimeUnknownSection::countRecords() const
{
  return this->numRecords + 1; // onw record is written in write()
}

//!

const char *
dimeUnknownSection::getSectionName() const
{
  return this->sectionName;
}

