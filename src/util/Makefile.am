## Process this file with automake to generate Makefile.in.

noinst_LTLIBRARIES = libutil.la

## Remove any linklibraries detected by configure, as they are not
## needed in the submodules -- only in the toplevel libdime build.
LIBS = 

INCLUDES = -I$(top_srcdir)/include

## All source files used when building this submodule, including all
## headers.

libutil_la_SOURCES = \
	Array.cpp Array.h \
	BSPTree.cpp BSPTree.h \
	Box.cpp Box.h \
	Dict.cpp Dict.h \
	Linear.cpp Linear.h \
	MemHandler.cpp MemHandler.h

## Installation information.

libutilincdir = $(includedir)/dime/util

libutilinc_HEADERS = \
	$(top_srcdir)/include/dime/util/Array.h \
	$(top_srcdir)/include/dime/util/BSPTree.h \
	$(top_srcdir)/include/dime/util/Box.h \
	$(top_srcdir)/include/dime/util/Dict.h \
	$(top_srcdir)/include/dime/util/Linear.h \
	$(top_srcdir)/include/dime/util/MemHandler.h


## FIXME: this is a temporary workaround for a bug in Automake. The
## bug is fixed in the latest Automake CVS, but not in any "official"
## release (?). Last checked with Automake 1.4a. 19990912 mortene.

install-libutilincHEADERS: $(libutilinc_HEADERS)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(libutilincdir)
	@list='$(libutilinc_HEADERS)'; for p in $$list; do \
	  if test -f "$$p"; then d= ; else d="$(srcdir)/"; fi; \
	  f="`echo $$p | sed -e 's|^.*/||'`"; \
	  echo " $(INSTALL_DATA) $$d$$p $(DESTDIR)$(libutilincdir)/$$f"; \
	  $(INSTALL_DATA) $$d$$p $(DESTDIR)$(libutilincdir)/$$f; \
	done

uninstall-libutilincHEADERS:
	@$(NORMAL_UNINSTALL)
	@list='$(libutilinc_HEADERS)'; for p in $$list; do \
	  f="`echo $$p | sed -e 's|^.*/||'`"; \
	  echo " rm -f $(DESTDIR)$(libutilincdir)/$$f"; \
	  rm -f $(DESTDIR)$(libutilincdir)/$$f; \
	done
