## Process this file with automake to generate Makefile.in.

noinst_LTLIBRARIES = libconvert.la

## Remove any linklibraries detected by configure, as they are not
## needed in the submodules -- only in the toplevel libdime build.
LIBS = 

INCLUDES = -I$(top_srcdir)/include

## All source files used when building this submodule, including all
## headers.

libconvert_la_SOURCES = \
	3dface.cpp \
	arc.cpp \
	circle.cpp \
	convert.cpp \
	convert_funcs.h \
	ellipse.cpp \
	layerdata.cpp \
	line.cpp \
	linesegment.cpp \
	linesegment.h \
	lwpolyline.cpp \
	point.cpp \
	polyline.cpp \
	solid.cpp \
	trace.cpp

## Installation information.

libconvertincdir = $(includedir)/dime/convert

libconvertinc_HEADERS = \
	$(top_srcdir)/include/dime/convert/convert.h \
	$(top_srcdir)/include/dime/convert/layerdata.h


## FIXME: this is a temporary workaround for a bug in Automake. The
## bug is fixed in the latest Automake CVS, but not in any "official"
## release (?). Last checked with Automake 1.4a. 19990912 mortene.

install-libconvertincHEADERS: $(libconvertinc_HEADERS)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(libconvertincdir)
	@list='$(libconvertinc_HEADERS)'; for p in $$list; do \
	  if test -f "$$p"; then d= ; else d="$(srcdir)/"; fi; \
	  f="`echo $$p | sed -e 's|^.*/||'`"; \
	  echo " $(INSTALL_DATA) $$d$$p $(DESTDIR)$(libconvertincdir)/$$f"; \
	  $(INSTALL_DATA) $$d$$p $(DESTDIR)$(libconvertincdir)/$$f; \
	done

uninstall-libconvertincHEADERS:
	@$(NORMAL_UNINSTALL)
	@list='$(libconvertinc_HEADERS)'; for p in $$list; do \
	  f="`echo $$p | sed -e 's|^.*/||'`"; \
	  echo " rm -f $(DESTDIR)$(libconvertincdir)/$$f"; \
	  rm -f $(DESTDIR)$(libconvertincdir)/$$f; \
	done
