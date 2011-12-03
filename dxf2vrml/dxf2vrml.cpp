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

#include <dime/Input.h>
#include <dime/Output.h>
#include <dime/Model.h>
#include <dime/State.h>
#include <stdio.h>
#include <dime/convert/convert.h>

#ifdef macintosh
#include "console.h"
#include "unix.h"
#include "SIOUX.h"
#endif // macintosh

static int 
usage(char *progname)
{
  fprintf(stderr,
	  "Usage: %s [infile] [-o outfile] [-e maxerr] [-f] [-l]\n"
	  "(default infile is stdin, default outfile is stdout)\n\n"
	  "Options:\n"
	  "-e <maxerr>  Maximum error when tessellating curves\n"
          "-s <numsub>  Number of subdivisions for a curve (full circle)\n"
	  "-f           Respect the $FILLMODE header variable\n"
          "-vrml2       Write as vrml2. Default is vrml1\n"
          "-2d          Set z-coordinate to 0 for all vertices\n"
	  "-l           Use layer color, ignore the color index\n\n",
	  progname);
  return -1;
}

int 
main(int argc, char **argv)
{
#ifdef macintosh
  SIOUXSettings.asktosaveonclose = 0;
  argc = ccommand(&argv);
  _fcreator = 'CMPL';
  _ftype = 'TEXT';
#endif // macintosh

  char *infile, *outfile;
  infile = outfile = NULL;
  float maxerr = 0.1f;
  int sub = -1;  
  int i = 1;
  
  int fillmode = 0;
  int layercol = 0;
  bool vrml1 = true;
  bool only2d = false;

  while (i < argc) {
    if (argv[i][0] != '-') {
      if (infile != NULL) return usage(argv[0]);
      infile = argv[i];
      i++;
    }
    else {
      switch (argv[i][1]) {
      case 'o':
	i++;
	if (i >= argc || outfile != NULL) return usage(argv[0]);
	outfile = argv[i];
	i++;
	break;
      case 'e':
	i++;
	if (i >= argc) return usage(argv[0]);
	maxerr = atof(argv[i]);
	i++;
	break;
      case 's':
	i++;
	if (i >= argc) return usage(argv[0]);
	sub = atoi(argv[i]);
	i++;
	break;
      case 'f':
	i++;
	fillmode = 1;
	break;
      case 'l':
	i++;
	layercol = 1;
	break;
      case 'v':
        i++;
        vrml1 = false;
        break;
      case 'h':
	return usage(argv[0]);
      case '2':
        i++;
        only2d = true;
        break;
      default:
	return usage(argv[0]);
      }
    }
  }

  dimeInput in;

  //
  // open file for reading (or use stdin) 
  //
  
  if (infile == NULL) {
    if (!in.setFileHandle(stdin)) {
      fprintf(stderr,"Unexpected error opening file from stdin\n");
      return -1;
    }
  }
  else {
    if (!in.setFile(infile)) {
      fprintf(stderr,"Error opening file for reading: %s\n", infile);
      return -1;
    }
  }
  
  //
  // try reading the file
  //
  dimeModel model;

  if (!model.read(&in)) {
    fprintf(stderr,"DXF read error in line: %d\n", in.getFilePosition());
    return -1;
  }

  //
  // open output file (or use stdout)
  //
  FILE *out = stdout;
  if (outfile != NULL) {
    out = fopen(outfile, "wb");
    if (!out) {
      fprintf(stderr,"Error opening file for writing: %s\n", outfile);
      return -1;
    }
  }
  
  dxfConverter converter;
  converter.findHeaderVariables(model);
  converter.setMaxerr(maxerr);
  if (sub > 0) converter.setNumSub(sub);

  //
  // override $FILLMODE header variable unless user tells us not to.
  // The $FILLMODE variable just specifies if AutoCAD was in fillmode 
  // when the user saved the DXF file, and may therefore not be what
  // we want when converting files.
  //
  if (fillmode == 0) converter.setFillmode(true);

  if (layercol) converter.setLayercol(true);
    
  if (!converter.doConvert(model)) {
    fprintf(stderr,"Error during conversion\n");
    if (out && out != stdout) fclose(out);
    return -1;
  }
  
  converter.writeVrml(out, vrml1, only2d);
  
  if (out != stdout) fclose(out);
  return 0; // alles in ordnung :-)
}

