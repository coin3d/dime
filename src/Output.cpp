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
  \class dimeOutput dime/Output.h
  \brief The dimeOutput class handles writing of DXF and DXB files.
*/

#include <dime/Output.h>
#include <math.h>

/*!
  \fn bool dimeOutput::writeHeader()
  This method does nothing now, but if binary files are supported in the
  future, it must be called.
*/

/*!
  Constructor.
*/

dimeOutput::dimeOutput()
  : fp( NULL ), binary( false ), callback( NULL ), callbackdata( NULL ),
    aborted( false ), didOpenFile(false)
{
}

/*!
  Destructor.
*/

dimeOutput::~dimeOutput()
{
  if (this->fp && this->didOpenFile) fclose(this->fp);
}

/*!
  This method sets a callback function that is called with progress
  information.  The first argument of the callback is a float in the
  range between 0 and 1.  The second argument of the callback is the
  void * \a cbdata argument.
*/

void 
dimeOutput::setCallback(const int num_records, 
		       int (*cb)(float, void *), void *cbdata)
{
  this->callback = cb;
  this->callbackdata = cbdata;
  this->numwrites = 0;
  this->numrecords = num_records;
}

/*!
  Sets the filename for the output file. The file will be opened,
  and \e true is returned if all was ok. The file is closed in
  the destructor.
*/

bool
dimeOutput::setFilename(const char * const filename)
{
  if (this->fp && this->didOpenFile) fclose(this->fp);
  this->fp = fopen(filename, "wb");
  this->didOpenFile = true;
  return (this->fp != NULL);
}

/*!
  Sets the output stream. \fp should be a valid file/stream, and
  it will not be closed in the destructor.
 */
bool 
dimeOutput::setFileHandle(FILE *fp)
{
  if (this->fp && this->didOpenFile) fclose(this->fp);

  assert(fp);
  this->fp = fp;
  this->didOpenFile = false;
  return true;
}

/*!
  Sets binary (DXB) or ASCII (DXF) format. Currently only ASCII
  is supported.
*/

void
dimeOutput::setBinary(const bool state)
{
  this->binary = state;
}

/*!
  Returns if binary or ASCII will be used when writing.
*/

bool
dimeOutput::isBinary() const
{
  return this->binary;
}

/*!
  Writes a record group code to the file.
*/

bool
dimeOutput::writeGroupCode(const int groupcode)
{
  if (this->aborted) return false;
  if (this->callback && this->numrecords) {
    if ((this->numwrites & 255) == 0) {
      float val = float(this->numwrites) / float(this->numrecords);
      if (val > 1.0f) val = 1.0f;
      this->aborted = !(bool) callback(val, this->callbackdata);
    }
    this->numwrites++;
  }
  return fprintf(this->fp, "%3d\n", groupcode) > 0;
}

/*!
  Writes an 8 bit integer to the file.
*/

bool
dimeOutput::writeInt8(const int8 val)
{
  return fprintf(this->fp,"%6d\n", (int)val) > 0;
}

/*!
  Writes a 16 bit integer to the file.
*/

bool
dimeOutput::writeInt16(const int16 val)
{
  return fprintf(this->fp,"%6d\n", (int)val) > 0;
}

/*!
  Writes a 32 bit integer to the file.
*/

bool
dimeOutput::writeInt32(const int32 val)
{
  return fprintf(this->fp,"%6d\n", val) > 0;
}

/*!
  Writes a single precision floating point number to the file.
*/

bool
dimeOutput::writeFloat(const float val)
{
  // Check for integer value, force decimal and one zero.
  if( fabsf( val ) < 1000000.0 && floorf( val ) == val ) {
    return fprintf(this->fp, "%.1f\n", val);
  }
  else {
    return fprintf(this->fp, "%g\n", val);
//    return fprintf(this->fp, "%#f\n", val);
  }
}

/*!
  Writes a double precision floating point number to the file.  
*/

bool
dimeOutput::writeDouble(const dxfdouble val)
{
  // Check for integer value, force decimal and one zero.
  if( fabs( val ) < 1000000.0 && floor( val ) == val ) {
    return fprintf(this->fp, "%.1f\n", val);
  }
  else {
    return fprintf(this->fp,"%g\n", val) > 0;
//    return fprintf(this->fp,"%#f\n", val) > 0;
  }
}

/*!
  Writes a nul-terminated string to the file. 
*/

bool
dimeOutput::writeString(const char * const str)
{
  return fprintf(this->fp, "%s\n", str) > 0;
}

int
dimeOutput::getUniqueHandleId()
{
  // FIXME
  return 1;
}

