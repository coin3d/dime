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

#ifndef DIME_DICT_H
#define DIME_DICT_H

#include <dime/Basic.h>
#include <string.h>

class DIME_DLL_API dimeDictEntry
{
  friend class dimeDict;

private:
  dimeDictEntry *next;
  dimeDictEntry(const char * const k, void *v) {key = strdup(k); value = v; };
  ~dimeDictEntry() {free(key);} 
  char *key;
  void *value;

}; // class dimeDictEntry

class DIME_DLL_API dimeDict
{
public:
  dimeDict(const int entries = 17989);
  ~dimeDict();
  void clear();

  bool enter(const char * const key, char *&ptr, void *value);
  const char *enter(const char * const key, void *value);
  const char *find(const char * const key) const;
  bool find(const char * const key, void *&value) const;
  bool remove(const char * const key);
  void dump(void);

private:
  int tableSize;
  dimeDictEntry **buckets;
  dimeDictEntry *&findEntry(const char * const key) const;
  unsigned int bucketNr(const char *key) const;

public:
  void print_info();
  
}; // class dimeDict

#endif // ! DIME_DICT_H

