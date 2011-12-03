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

#ifndef DIME_INPUT_H
#define DIME_INPUT_H

#include <dime/Basic.h>
#include <dime/util/Array.h>

#define DXF_MAXLINELEN 4096

class DIME_DLL_API dimeInput
{
public:
  dimeInput();
  ~dimeInput();
  
  bool setFileHandle(FILE *fp);
  bool setFile(const char * const filename);
  bool setFilePointer(const int fd);
  bool eof() const;
  void setCallback(int (*cb)(float, void *), void *cbdata);
  float relativePosition();

  void putBackGroupCode(const int32 code);
  bool readGroupCode(int32 &code);
  bool readInt8(int8 &val);
  bool readInt16(int16 &val);
  bool readInt32(int32 &val);
  bool readFloat(float &val);
  bool readDouble(dxfdouble &val);
  const char *readString();
  const char *readStringNoSkip();

  class dimeModel *getModel();
  class dimeMemHandler *getMemHandler();
    
  int getFilePosition() const;
  
  bool isBinary() const;
  int getVersion() const;
  bool isAborted() const;
  
private:
  friend class dimeModel;
  dimeModel *model;              // set by the dimeModel class.
  int filePosition;
  bool binary;
  bool binary16bit;
  int version;

  int fd;
#ifdef USE_GZFILE
  void *gzfp; // gzip file pointer
  bool gzeof;
#else // ! USE_GZFILE
  FILE *fp;
  bool fpeof;
#endif // ! USE_GZFILE
  long filesize;
  char *readbuf;
  int readbufIndex;
  int readbufLen;
  
  dimeArray <char> backBuf;
  int backBufIndex; 

  char lineBuf[DXF_MAXLINELEN];
  int32 putBackCode;
  bool hasPutBack;
  int (*callback)(float, void*);
  void *callbackdata;
  float prevposition;
  int cbcnt;
  bool aborted;
  bool prevwashandle;
  bool didOpenFile;
  bool endianSwap;

private:
  bool init();
  bool doBufferRead();
  void putBack(const char c);
  void putBack(const char * const string);
  bool get(char &c);
  bool read(char &c);
  bool skipWhiteSpace();
  bool nextLine();
  bool readInteger(long &l);
  bool readUnsignedInteger(unsigned long &l);
  bool readUnsignedIntegerString(char * const str);
  int readDigits(char * const string);
  int readHexDigits(char * const string);
  int readChar(char * const string, char charToRead);
  bool readReal(dxfdouble &d);
  bool checkBinary();
}; // class dimeInput

#endif // ! DIME_INPUT_H

