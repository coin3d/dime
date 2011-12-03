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
  \class dimeDict dime/util/Dict.h
  \brief The dimeDict class is internal / private.

  It offers quick (hashing) lookup for strings.
*/

/*!
  \class dimeDictEntry dime/util/Dict.h
  \brief The dimeDictEntry class is internal / private.
*/

#include <dime/util/Dict.h>
#include <stdio.h>

/*!
  Constructor.  Creates \a entries buckets.
*/

dimeDict::dimeDict(const int entries)
{
  this->tableSize = entries;
  this->buckets = new dimeDictEntry *[tableSize];
  for (int i = 0; i < tableSize; i++)
    buckets[i] = NULL;
}

/*!
  Destructor.
*/

dimeDict::~dimeDict()
{
  clear();
  delete [] buckets;
}

/*!
  Clear all entries in the dictionary.  
*/

void
dimeDict::clear()
{
  int i;
  dimeDictEntry *entry, *nextEntry;

  for(i = 0; i < tableSize; i++) {
    for(entry = buckets[i]; entry != NULL; entry = nextEntry) {
      nextEntry = entry->next;
      delete entry;
    }
    buckets[i] = NULL;
  }
}

/*!
  Insert a new string \a key in the dictionary, and associates a
  id (= \a value) to it. Returns a pointer
  to the string. If the string is already in the dictionary, the
  old id is replaced with \a value;
*/

const char *
dimeDict::enter(const char * const key, void *value)
{
  dimeDictEntry *&entry = findEntry(key);
  
  if(entry == NULL) {
    entry = new dimeDictEntry(key, value);
    if (entry == NULL) return NULL;
    entry->next = NULL;
    return entry->key;
  }
  else {
    entry->value = value;
    return entry->key;
  }
}

/*!
  Inserts a new string \a key in the dictionary. This function
  returns \e true if the string was not already in the dictionary,
  \e false otherwise. The string pointer is returned in \a ptr.
*/

bool 
dimeDict::enter(const char * const key, char *&ptr, void *value)
{
  dimeDictEntry *&entry = findEntry(key);
  
  if(entry == NULL) {
    entry = new dimeDictEntry(key, value);
    if (entry == NULL) {
      ptr = NULL;
      return false;
    }
    entry->next = NULL;
    ptr = entry->key;
    return true;
  }
  else {
    entry->value = value;
    ptr = entry->key;
    return false;
  }
}

/*!
  Finds if \a key is in the dictionary. Returns the string pointer
  if found, NULL otherwise.  
*/

const char *
dimeDict::find(const char * const key) const
{
  dimeDictEntry *&entry = findEntry(key);
  if (entry) 
    return entry->key;
  return NULL;
}

/*!
  Finds if \a key is in the dictionary. Returns true if found.
*/

bool
dimeDict::find(const char * const key, void *&value) const
{
  dimeDictEntry *&entry = findEntry(key);

  if(entry == NULL) {
    value = NULL;
    return false;
  }
  else {
    value = entry->value;
    return true;
  }
}

/*!
  Remove \a key from the dictionary.
*/

bool
dimeDict::remove(const char * const key)
{
  dimeDictEntry *&entry = findEntry(key);
  dimeDictEntry *tmp;

  if(entry == NULL)
    return false;
  else {
    tmp = entry;
    entry = entry->next;
    delete tmp;
    return true;
  }
}

// private funcs

dimeDictEntry *&
dimeDict::findEntry(const char * const key) const
{
  dimeDictEntry **entry;

  entry = &buckets[bucketNr(key) % tableSize];
  
  while(*entry != NULL) {
    if(strcmp((*entry)->key, key) == 0) break;
    entry = &(*entry)->next;
  }
  return *entry;
}

unsigned int
dimeDict::bucketNr(const char *s) const
{
  unsigned int total, shift;
  total = shift = 0;
  while (*s) {
    total = total ^ ((*s) << shift);
    shift+=5;
    if (shift>24) shift -= 24;
    s++;
  }
  return total % tableSize;
}

/*
  For debugging
*/

void
dimeDict::dump(void)
{
  int i;
  dimeDictEntry *entry, *nextEntry;

  for(i = 0; i < tableSize; i++) {
    for(entry = buckets[i]; entry != NULL; entry = nextEntry) {
      nextEntry = entry->next;
      printf("entry: '%s' %p\n", entry->key, entry->value);
    }
  }
}

void 
dimeDict::print_info()
{
  int i, cnt;
  dimeDictEntry *entry;

  printf("---------- dict info ------------------\n");

  for (i = 0; i < tableSize; i++) {
    entry = buckets[i];
    cnt = 0;
    while(entry) {
      entry = entry->next;
      cnt++;
    }
    printf(" bucket: %d, cnt: %d\n",i, cnt);
  }
  printf("\n\n\n");
}

