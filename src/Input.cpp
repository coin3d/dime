/**************************************************************************\
 * 
 *  FILE: Input.cpp
 *
 *  This source file is part of DIME.
 *  Copyright (C) 1998-1999 by Systems In Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License, version 2, as
 *  published by the Free Software Foundation.  DO NOT MISTAKE THIS LICENSE
 *  FOR THE GNU LGPL LICENSE.
 *
 *  This library is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License (the accompanying file named COPYING) for more
 *  details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 **************************************************************************
 *
 *  If you need DIME for commercial purposes, you can contact Systems In
 *  Motion about acquiring a commercial license.
 *
 *  Systems In Motion                                   http://www.sim.no/
 *  Prof. Brochs gate 6                                       sales@sim.no
 *  N-7030 Trondheim                                   Voice: +47 22114160
 *  NORWAY                                               Fax: +47 67172912
 *
\**************************************************************************/

/*!
  \class dimeInput dime/Input.h
  \brief The dimeInput class offers transparent file I/O for DXF and DXB
*/

#ifdef _WIN32
#include <io.h>
#else
#include <unistd.h>
#endif
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>
#include <float.h>
#include <stdio.h>

#ifdef macintosh
#include "unix.h"
#endif

#ifdef USE_GZFILE
#include <zlib.h>
#endif

#include <dime/Input.h>
#include <dime/Model.h>

#define READBUFSIZE 65536

#define TMPBUFSIZE 512 // temporary buffer used to read floats or integers

/*!
  Constructor.
*/

dimeInput::dimeInput()
  : model( NULL ), version( 12 ), fd( -1 ), readbuf( NULL ),
    callback( NULL ), callbackdata( NULL )
{
#ifdef USE_GZFILE
  this->gzfp = NULL;
#else
  this->fp = NULL;
#endif
  this->prevwashandle = false;
}

/*!
  Destructor.
*/

dimeInput::~dimeInput()
{
  delete [] this->readbuf;
#ifdef USE_GZFILE
  if (this->gzfp) gzclose(this->gzfp);
#else
  if (this->fp) fclose(this->fp);
#endif
}

bool
dimeInput::init()
{
  this->aborted = false;
  this->hasPutBack = false;
  this->putBackCode = 0;
  this->filePosition = 0;
  this->binary = false;

  this->fd = -1;
#ifdef USE_GZFILE
  if (this->gzfp) gzclose(this->gzfp);
  this->gzfp = NULL;
  this->gzeof = true;
#else
  if (this->fp) fclose(this->fp);
  this->fp = NULL;
  this->fpeof = true;
#endif
  this->filesize = 0;
  if (this->readbuf == NULL) {
    this->readbuf = new char[READBUFSIZE]; // create buffer
    if (!this->readbuf) return false;
  }
  this->readbufIndex = 0;
  this->readbufLen = 0;
  this->backBufIndex = -1;
  this->backBuf.setCount(0);
  this->prevposition = 0.0f;
  this->cbcnt = 0;
  this->prevwashandle = false;
  return true;
}

/*!
  This method returns wether file input was aborted or not.
*/

bool 
dimeInput::isAborted() const
{
  return this->aborted;
}

/*!
  This method sets a progress callback that will be called with a
  float in the range between 0 and 1, and void * \a cbdata as arguments.
*/

void 
dimeInput::setCallback(int (*cb)(float, void *), void *cbdata)
{
  this->callback = cb;
  this->callbackdata = cbdata;
  this->prevposition = 0.0f;
  this->cbcnt = 0;
}

/*!
  Returns the relative file position. 0.0 means beginning of file,
  1.0 is at end of file.
*/

float
dimeInput::relativePosition()
{
  if (!this->filesize) return 0.0f;
  return (((float)(lseek(this->fd, 0, SEEK_CUR)-(readbufLen-readbufIndex)))/
	  ((float)(this->filesize)));
}

/*!
  Opens the file 'filename' for reading. True is returned if the file
  is opened correctly.
*/

bool
dimeInput::setFile(const char * const filename)
{
#ifdef _WIN32
  int fd = open(filename, O_RDONLY | O_BINARY);
#else
  int fd = open(filename, O_RDONLY);
#endif
  if (fd < 0) {
    return false;
  }
  return setFilePointer(fd);
}

/*!
  Sets the file pointer for this instance. \a newfd is a file opened 
  with the unistd open() function.
*/

bool 
dimeInput::setFilePointer(const int newfd)
{
  if (!this->init()) return false;
  this->fd = newfd;
#if USE_GZFILE
  this->gzfp = gzdopen(this->fd, "rb");
  this->gzeof = false; 
#else
  this->fp = fdopen(this->fd, "rb");
  this->fpeof = false;
#endif
  long startpos = lseek(fd, 0, SEEK_CUR);
  this->filesize = lseek(fd, 0, SEEK_END);
  lseek(fd, startpos, SEEK_SET);
  return this->filesize > 0;
}

/*!
  Returns true if end of file is encountered.
*/

bool 
dimeInput::eof() const
{
#if USE_GZFILE
  return this->gzeof;
#else
  return this->fpeof;
#endif
}

/*!
  Reads a group code from the file. In binary files, group codes
  are represented as a single byte, with the exception of 
  extended data which has 255 as the first byte, and then the
  actual group code following as a 16-bit integer.
*/

bool 
dimeInput::readGroupCode(int32 &code)
{
  bool ret;
  if (this->hasPutBack) {
    this->hasPutBack = false;
    code = this->putBackCode;
    ret = true;
  }
  else {
    if (this->callback && this->cbcnt++ > 100) {
      this->cbcnt = 0;
      float pos = this->relativePosition();
      if (pos > this->prevposition + 0.01f) {
	this->prevposition = pos;
	if (!this->callback(pos, this->callbackdata)) {
	  this->aborted = true;
	  return false;
	}
      }
    }
    ret = readInt32(code);
  }
  if (code == 5) this->prevwashandle = true;
  else this->prevwashandle = false;
  return ret;
}

/*!
  This function is needed when a loader snoops for future group codes.
  It is possible to put back a single group code so that the next time
  dimeInput::readGroupCode() is called, the putback value will be 
  returned.
*/

void 
dimeInput::putBackGroupCode(const int32 code)
{
  this->putBackCode = code;
  this->hasPutBack = true;
}


/*!
  Reads an 8 bit integer from the file.
*/

bool 
dimeInput::readInt8(int8 &val)
{
  long tmp;
  bool ok = skipWhiteSpace();
  if (ok && readInteger(tmp) && tmp >= -128 & tmp <= 127) {
    val = (int8) tmp;
    return nextLine();
  }
  return false;
}

/*!
  Reads a 16 bit integer from the file.
*/

bool 
dimeInput::readInt16(int16 &val)
{
  long tmp;
  bool ok = skipWhiteSpace();
  if (ok && readInteger(tmp) && tmp >= -32768 & tmp <= 32767) {
    val = (int16) tmp;
    return nextLine();
  }
  return false;
}

/*!
  Reads a 32 bit integer from the file. 
*/

bool 
dimeInput::readInt32(int32 &val)
{
  long tmp;
  if (skipWhiteSpace() && readInteger(tmp)) {
    val = tmp;
    return nextLine();
  }
  return false;
}

/*!
  Reads a single precision floating point number from the file. 
*/

bool 
dimeInput::readFloat(float &val)
{
  dxfdouble tmp;
  bool ok = skipWhiteSpace();
  if (ok && readReal(tmp) && tmp >= -FLT_MAX && tmp <= FLT_MAX) {
    val = (float) tmp;
    return nextLine();
  }
  return false;
}

/*!
  Reads a dxfdouble precision floating point number from the file.
*/

bool 
dimeInput::readDouble(dxfdouble &val)
{
  return skipWhiteSpace() && readReal(val) && nextLine();
}

/*!
  Returns a null-terminated string read from the file. The string
  is valid only until the next read operation, so you'd better
  copy it somewhere if you need it.
*/

const char *
dimeInput::readString()
{
  bool ok = skipWhiteSpace();
  if (ok) {
    char c;
    int idx = 0;
    while (get(c) && c != 0xa && c != 0xd && idx < DXF_MAXLINELEN) {
      lineBuf[idx++] = c;
    }
    if (c == 0xa) this->putBack(c);
    else if (c == 0xd) this->putBack(c);
    this->nextLine();
    this->lineBuf[idx] = '\0';

    if (this->prevwashandle) {
      this->prevwashandle = false;
      if (this->model) {
	this->model->registerHandle(this->lineBuf);
      }
    }
    return this->lineBuf;
  }
  return NULL;
}

/*!
  Returns the memory handler used in this model.
*/

dimeMemHandler *
dimeInput::getMemHandler()
{
  if (model) return model->getMemHandler();
  return NULL;
}

/*!
  Returns the model for this file.
*/

dimeModel *
dimeInput::getModel()
{
  return model;
}

/*!
  For ASCII files, it returns the current line number. 
  For binary files the file position is returned.
*/

int 
dimeInput::getFilePosition() const
{
  return filePosition;
}

/*!
  Returns true if this is a binary (DXB) file.
*/

bool 
dimeInput::isBinary() const
{
  return binary;
}

/*!
  Returns the version of this file (10, 12, 13 or 14).
*/

int 
dimeInput::getVersion() const
{
  return version;
}

// private funcs ***********************************************************

//  
//  Reads a relatively big block from the file into local memory.  
//

bool
dimeInput::doBufferRead()
{
#if USE_GZFILE
  if (!this->gzfp) return false;
  int len = gzread(this->gzfp, this->readbuf, READBUFSIZE);
  if (len <= 0) {
    this->gzeof = true;
    this->readbufIndex = 0;
    this->readbufLen = 0;
    return false;
  }
  else {
    this->readbufIndex = 0;
    this->readbufLen = len;
    return true;
  }
#else
  if (!this->fp) return false;
  int len = fread(this->readbuf, 1, READBUFSIZE, this->fp);
  if (len <= 0) {
    this->fpeof = true;
    this->readbufIndex = 0;
    this->readbufLen = 0;
    return false;
  }
  else {
    this->readbufIndex = 0;
    this->readbufLen = len;
    return true;
  }
#endif
}

//
// puts a character back in the stream
//

void
dimeInput::putBack(const char c)
{
  if (readbufIndex > 0 && backBufIndex < 0)
    readbufIndex--;
  else
    backBuf[++backBufIndex] = c;
}

//
// puts back a string
//

void
dimeInput::putBack(const char * const string)
{
  int n = strlen(string);
  if (n <= readbufIndex && backBufIndex < 0)
    readbufIndex -= n;
  else {
    for (int i = n - 1; i >= 0; i--) 
      backBuf[++backBufIndex] = string[i];
  }
}

//
// returns the first non white-space char
//

bool
dimeInput::read(char &c)
{
  return (skipWhiteSpace() && get(c));
}

//
// returns the next char in the stream
//

bool
dimeInput::get(char &c)
{  
  if(backBufIndex >= 0) {
    c = backBuf[backBufIndex--];
    return true;
  }

  if (readbufIndex >= readbufLen) {
    if (!doBufferRead()) {
      return false;
    }
  }
  c = readbuf[readbufIndex++];
  return true;
}

//
// skip all white spaces
//

bool
dimeInput::skipWhiteSpace()
{
  char c;
  register bool gotChar;
  register char endline = 0xa;
  register char endline2 = 0xd;
  while((gotChar = get(c)) && isspace(c) && c != endline && c != endline2);
  if (!gotChar) return false;

  // step one char back
  putBack(c);
  return true;
}

bool
dimeInput::nextLine()
{
  char c;
  register bool gotChar;
  register char endline = 0xa;
  register char endline2 = 0xd;
  while((gotChar = get(c)) && c != endline && c != endline2);
  if (!gotChar) return false;
  while (c == endline2) { // try to read one more
    gotChar = get(c);
    if (!gotChar) return false;
  }
  if (c != endline && c != endline2) this->putBack(c);
  this->filePosition++;
  return true;
}

//
// read an integer
//

bool
dimeInput::readInteger(long &l)
{
  char str[TMPBUFSIZE];
  char *s = str;

  if(readChar(s, '-') || readChar(s, '+'))
    s++;

  if(! readUnsignedIntegerString(s))
    return false;

  l = strtol(str, NULL, 0);

  return true;
}

//
// read an unsigned integer
//

bool
dimeInput::readUnsignedInteger(unsigned long &l)
{
  char str[TMPBUFSIZE]; 
  if(! readUnsignedIntegerString(str))
    return false;

  l = strtoul(str, NULL, 0);

  return true;
}

bool
dimeInput::readUnsignedIntegerString(char * const str)
{
  int minSize = 1;
  char *s = str;

  if(readChar(s, '0')) {

    if(readChar(s + 1, 'x')) {
      s += 2 + readHexDigits(s + 2);
      minSize = 3;
    }

    else
      s += 1 + readDigits(s + 1);
  }

  else
    s += readDigits(s);

  if(s - str < minSize)
    return false;

  *s = '\0';

  return true;
}

int
dimeInput::readDigits(char * const string)
{
  char c, *s = string;

  while (get(c)) {
    if(isdigit(c))
      *s++ = c;
    else {
      putBack(c);
      break;
    }
  }
  
  return s - string;
}

//
// check if a character is next in stream. Writes character into
// string if found, puts character back otherwise.
//

int
dimeInput::readChar(char * const string, char charToRead)
{
  char c;
  int ret;

  if(!get(c))
    ret = 0;
  
  else if(c == charToRead) {
    *string = c;
    ret = 1;
  }

  else {
    putBack(c);
    ret = 0;
  }

  return ret;
}

int
dimeInput::readHexDigits(char * const string)
{
  char c, *s = string;

  while (get(c)) {

    if(isxdigit(c))
      *s++ = c;

    else {
      putBack(c);
      break;
    }
  }

  return s - string;
}

//
// reads a floating point number
//

bool
dimeInput::readReal(dxfdouble &d)
{
  char str[TMPBUFSIZE];
  int n;
  char *s = str;
  bool gotNum = false;

  n = readChar(s, '-');
  if(n == 0)
    n = readChar(s, '+');
  s += n;
  
  if((n = readDigits(s)) > 0) {
    gotNum = true;
    s += n;
  }
  
  if(readChar(s, '.') > 0) {
    s++;

    if((n = readDigits(s)) > 0) {
      gotNum = true;
      s += n;
    }
  }

  if(!gotNum)
    return false;

  n = readChar(s, 'e');
  if(n == 0)
    n = readChar(s, 'E');
  
  if(n > 0) {
    s += n;

    n = readChar(s, '-');
    if(n == 0)
      n = readChar(s, '+');
    s += n;
    
    if((n = readDigits(s)) > 0)
      s += n;
    
    else
      return false; 
  }
  
  *s = '\0';
  
  d = atof(str);
  return true;
}

