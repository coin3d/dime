## Process this file with automake to generate Makefile.in.

noinst_LTLIBRARIES = libclasses.la

## Remove any linklibraries detected by configure, as they are not
## needed in the submodules -- only in the toplevel libdime build.
LIBS = 

INCLUDES = -I$(top_srcdir)/include

## All source files used when building this submodule, including all
## headers.

libclasses_la_SOURCES = \
	Class.cpp Class.h \
	UnknownClass.cpp UnknownClass.h

## Installation information.

libclassesincdir = $(includedir)/dime/classes

libclassesinc_HEADERS = \
	$(top_srcdir)/include/dime/classes/Class.h \
	$(top_srcdir)/include/dime/classes/UnknownClass.h


## FIXME: this is a temporary workaround for a bug in Automake. The
## bug is fixed in the latest Automake CVS, but not in any "official"
## release (?). Last checked with Automake 1.4a. 19990912 mortene.

install-libclassesincHEADERS: $(libclassesinc_HEADERS)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(libclassesincdir)
	@list='$(libclassesinc_HEADERS)'; for p in $$list; do \
	  if test -f "$$p"; then d= ; else d="$(srcdir)/"; fi; \
	  f="`echo $$p | sed -e 's|^.*/||'`"; \
	  echo " $(INSTALL_DATA) $$d$$p $(DESTDIR)$(libclassesincdir)/$$f"; \
	  $(INSTALL_DATA) $$d$$p $(DESTDIR)$(libclassesincdir)/$$f; \
	done

uninstall-libclassesincHEADERS:
	@$(NORMAL_UNINSTALL)
	@list='$(libclassesinc_HEADERS)'; for p in $$list; do \
	  f="`echo $$p | sed -e 's|^.*/||'`"; \
	  echo " rm -f $(DESTDIR)$(libclassesincdir)/$$f"; \
	  rm -f $(DESTDIR)$(libclassesincdir)/$$f; \
	done
