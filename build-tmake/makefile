#***************************************************************************
#
# Makefile for DIME: Dxf Import, Manipulation, and Export Library
#
# Usage:
#       make 			Makes Dime release version
#	make shared		Makes Dime development version
#
#***************************************************************************

COPY = cp
SYMLINK = ln -sf

#***************************************************************************

all:: dime

screen:
	@echo -e "\033[34m\n" \
	"\t****************************************************************\n" \
	"\t*                       Compiling DIME                         *\n" \
	"\t****************************************************************\n" \
	"\033[0m";

dime: static

static: makefile.release .release

shared: makefile.dime .dime

objects:
	mkdir $@

releaseobjects:
	mkdir $@

.dime: objects
	@$(MAKE) -f makefile.dime

makefile.dime: dime.pro common.pro
	tmake -o makefile.dime -p common.pro dime.pro

.release: releaseobjects
	@$(MAKE) -f makefile.release

makefile.release: release.pro
	tmake -o makefile.release -p common.pro release.pro

clean: makefile.dime makefile.release
	@$(MAKE) -f makefile.dime clean
	@$(MAKE) -f makefile.release clean

veryclean: clean
	rm makefile.dime makefile.release
	rm -rf objects releaseobjects

