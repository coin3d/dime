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
  \class dimeArray dime/util/Array.h
  \brief The dimeArray class is internal / private.

  The dimeArray class is a container class for a growable array.  Whenever
  the allocated space for the array becomes too small, the array is moved to
  a memory block that is twice as large.  This class is dangerous to use,
  because it does not check for bounds and other things for efficiency
  reasons.  Inspect the source code - don't assume anything...
*/

/*!
  \fn void dimeArray::removeElem( const int index )
  This method removes an element from the array, moving all subsequent
  elements one position up.
*/

/*!
  \fn void dimeArray::removeElemFast( const int index )
  This method removes an element from the array, and moves the last element
  into its place at the same index.  The order of the elements is distorted,
  in other words.
*/

/*!
  \fn void dimeArray::setCount( const int count )
  This method sets the logical size of the array to \a count without
  changing the size of the array.  Do not increase the array size with
  this function!  This method is useful for reusing an array that will
  grow to approximately the same size each time it is used.
*/

/*!
  \fn void dimeArray::makeEmpty( const int initsize = 4 )
  This method makes the logical array empty, and deallocates the memory used
  by it, only allocating space for a small array of size \a initsize.
*/

/*!
  \fn int dimeArray::count() const
  This method returns the number of elements in the array.
*/

/*!
  \fn int dimeArray::allocSize() const
  This method returns the size allocated for the array.
*/

/*!
  \fn void dimeArray::freeMemory()
  This method frees all the memory used by the class.  The dimeArray class
  is probably unusable afterwards.
*/

/*!
  \fn T * dimeArray::arrayPointer()
  This method returns a pointer to the allocated array.
*/

/*!
  \fn const T * dimeArray::constArrayPointer() const
  This method returns a pointer to the allocated array.
*/

/*!
  \fn void dimeArray::shrinkToFit()
  This method moves the array into a memory block exactly the same size of
  the array.  This will free up any overhead caused by the array doubling
  mechanism.
*/

