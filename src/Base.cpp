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
  \mainpage

  %Dime is a C++ class library for reading, constructing,
  manipulating, and writing DXF file data. The name is an acronym for
  DXF Import, Manipulation, and Export library.

  The library is portable to any platform with a C++ compiler. It has
  no external dependencies. Dime is known to compile on Win32, Linux,
  IRIX, HP- UX, Solaris, BeOS and MacOS.

  \b Features:

  \li loading DXF files into a Dime object hierarchy containing the
  DXF data
  \li building Dime object hierarchies from scratch
  \li extracting geometry data from Dime object hierarchies
  \li manipulating Dime object hierarchies
  \li traversing the Dime object hierarchies while performing various
  tasks saving dime object hierarchies as files conforming to the DXF
  file format

  %Dime is designed to support all past and future versions of the DXF
  file format. Internally we have tested dime with DXF version 10
  through 14, and we've had customers that have used the library to
  handle AutoCAD 2000 DXF files.

  The intended purpose of %Dime is to import and export DXF files. For
  this kind of usage, special memory management techniques has been
  implemented, that can be used to boost the performance
  significantly.

  An example program is included to demonstrate how to use %Dime. The
  program, dxf2vrml, converts dxf to VRML files.
*/


/*!
  \class dimeBase dime/Base.h
  \brief The dimeBase class is the superclass for most classes in Dime.

  dimeBase implements the \e new operator to enable use of the special-purpose
  memory manager class, dimeMemHandler.  It also implements a simple run-time
  type checking system.
*/

#include <dime/Base.h>
#include <dime/util/MemHandler.h>
#include <stdio.h>

/*!
  \fn int dimeBase::typeId() const
  Must be implemented by all subclasses, and should return an unique id
  for that class.
*/

/*!
  Constructor.
*/
dimeBase::dimeBase(void)
{
}

/*!
  virtual destructor.
*/
dimeBase::~dimeBase()
{
}


/*!
  Returns \e true if the object is of type \a typeid or is inherited 
  from it. Function in base class checks whether \a thetypeid 
  equals the virtual dimeBase::typeId() value or equals \e dimeBaseType.
  Must be implemented by all subclasses that are superclasses of other
  classes, and should check if \a thetypeid equals its typeId,
  and then call its parent's isOfType function.  Leaf-classes
  do not have to implement this method.
*/

bool 
dimeBase::isOfType(const int thetypeid) const
{
  return this->typeId() == thetypeid ||
    thetypeid == dimeBaseType;
}

void *
dimeBase::operator new(size_t size, dimeMemHandler *memhandler, 
		      const int alignment)
{
  if (memhandler)
    return memhandler->allocMem(size, alignment);
  else return ::operator new(size);
}

void 
dimeBase::operator delete(void * ptr)
{
  // will only get here if we don't use a memory handler
  ::operator delete(ptr);
}
