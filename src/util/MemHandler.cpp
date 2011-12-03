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
  \class dimeMemHandler dime/util/MemHandler.h
  \brief The dimeMemHandler class is a special-purpose memory manager.

  Using this class will give you efficient memory allocation and extremely
  efficient deallocation.  In addition, there is almost \e no overhead on
  the memory allocated.  The drawback is that it is not possible to
  deallocate a block of memory once it is allocated; all the allocated memory
  must be deallocated in one operation.

  If you plan to use DIME in a way that requires lots of dynamic allocation
  / deallocation of for instance entities, you should not use the memory
  manager - the standard new / delete operators should be used instead.
  The most common use of dime is to import and export DXF files, so
  the data structure is just built and then freed up all at once.  For this
  kind of usage, the special-purpose memory manager is far superior to the
  system memory manager.
*/

/*!
  \class dimeMemNode src/util/MemHandler.cpp
  \brief The dimeMemNode class is internal / private.

  Mind your own business ;)
*/

#include <dime/util/MemHandler.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MEMBLOCK_SIZE 65536 // the bigger the value, the less overhead

class dimeMemNode
{
  friend class dimeMemHandler;
public:
  dimeMemNode(const int numbytes, dimeMemNode *next_node) 
    : next( next_node ), currPos( 0 ), size( numbytes )
  {
    this->block = (unsigned char*)malloc(numbytes);
  }
  
  ~dimeMemNode()
  {
    free((void*)this->block);
  }

  bool initOk() const
  {
    return (this->block != NULL);
  }
  
  void *alloc(const int numbytes, const int alignment)
  {
    unsigned int mask = alignment - 1;
    unsigned char *ret = NULL;
    if (alignment > 1) {
      if (this->currPos & mask) 
	this->currPos = (this->currPos & ~mask) + alignment;
    }
    if (this->currPos + numbytes <= this->size) {
      ret = &this->block[currPos];
      this->currPos += numbytes;
    }
    return ret;
  }

private:
  dimeMemNode *next;
  unsigned char *block;
  unsigned int currPos;
  unsigned int size;

}; // class dimeMemNode

/*!
  Constructor. Get ready for fast alloc :-)
*/

dimeMemHandler::dimeMemHandler()
  : bigmemnode( NULL )
{
  this->memnode = new dimeMemNode(MEMBLOCK_SIZE, NULL);
}

/*!
  Frees all memory used.
*/

dimeMemHandler::~dimeMemHandler()
{
  dimeMemNode *curr = this->memnode;
  dimeMemNode *next;
  
  while (curr) {
    next = curr->next;
    delete curr;
    curr = next;
  }

  curr = this->bigmemnode;
  while (curr) {
    next = curr->next;
    delete curr;
    curr = next;
  } 
}

/*!
  Bullshit function.  Can be called right after constructor 
  to test if initial memory was allocated ok.
*/

bool
dimeMemHandler::initOk() const
{
  return this->memnode && this->memnode->initOk();
}

/*!
  Allocates memory for the string, copies string into memory, and
  returns the new string pointer.
*/

char *
dimeMemHandler::stringAlloc(const char * const string)
{
  int len = strlen(string)+1;
  char *ret = (char*)this->allocMem(len, 1);
  if (ret) {
    strcpy(ret, string);
  }
  return ret;
}

/*!
  Allocates a chunk (\a size) of memory. Memory is allocates in big 
  blocks. New blocks of memory is allocated whenever needed, and
  is handled automatically. The returned pointer is aligned according 
  to the \a alignment argument. The default alignment is four bytes, 
  but when compiled on 64 bits systems the default alignment 
  should probably be changed to eight.
*/

void *
dimeMemHandler::allocMem(const int size, const int alignment)
{
  void *ret = NULL;
  if (size > MEMBLOCK_SIZE/2) { // big blocks is allocated separately.
    this->bigmemnode = new dimeMemNode(size, this->bigmemnode);
    if (!this->bigmemnode || !this->bigmemnode->initOk()) return NULL;
    ret = (void*) this->bigmemnode->block;
  }
  else {
    ret = this->memnode->alloc(size, alignment);
    if (ret == NULL) {
      this->memnode = new dimeMemNode(MEMBLOCK_SIZE, this->memnode);
      if (!this->memnode || !this->memnode->initOk()) return NULL;
      ret = this->memnode->alloc(size, alignment);
    }
  }
  return ret;
}

