## Process this file with automake to generate Makefile.in.

noinst_LTLIBRARIES = libobjects.la

## Remove any linklibraries detected by configure, as they are not
## needed in the submodules -- only in the toplevel libdime build.
LIBS = 

INCLUDES = -I$(top_srcdir)/include

## All source files used when building this submodule, including all
## headers.

libobjects_la_SOURCES = \
	Object.cpp Object.h \
	UnknownObject.cpp UnknownObject.h

## Installation information.

libobjectsincdir = $(includedir)/dime/objects

libobjectsinc_HEADERS = \
	$(top_srcdir)/include/dime/objects/Object.h \
	$(top_srcdir)/include/dime/objects/UnknownObject.h


## FIXME: this is a temporary workaround for a bug in Automake. The
## bug is fixed in the latest Automake CVS, but not in any "official"
## release (?). Last checked with Automake 1.4a. 19990912 mortene.

install-libobjectsincHEADERS: $(libobjectsinc_HEADERS)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(libobjectsincdir)
	@list='$(libobjectsinc_HEADERS)'; for p in $$list; do \
	  if test -f "$$p"; then d= ; else d="$(srcdir)/"; fi; \
	  f="`echo $$p | sed -e 's|^.*/||'`"; \
	  echo " $(INSTALL_DATA) $$d$$p $(DESTDIR)$(libobjectsincdir)/$$f"; \
	  $(INSTALL_DATA) $$d$$p $(DESTDIR)$(libobjectsincdir)/$$f; \
	done

uninstall-libobjectsincHEADERS:
	@$(NORMAL_UNINSTALL)
	@list='$(libobjectsinc_HEADERS)'; for p in $$list; do \
	  f="`echo $$p | sed -e 's|^.*/||'`"; \
	  echo " rm -f $(DESTDIR)$(libobjectsincdir)/$$f"; \
	  rm -f $(DESTDIR)$(libobjectsincdir)/$$f; \
	done
