## Process this file with automake to generate Makefile.in.

noinst_LTLIBRARIES = libsections.la

## Remove any linklibraries detected by configure, as they are not
## needed in the submodules -- only in the toplevel libdime build.
LIBS = 

INCLUDES = -I$(top_srcdir)/include

## All source files used when building this submodule, including all
## headers.

libsections_la_SOURCES = \
	BlocksSection.cpp BlocksSection.h \
	ClassesSection.cpp ClassesSection.h \
	EntitiesSection.cpp EntitiesSection.h \
	HeaderSection.cpp HeaderSection.h \
	ObjectsSection.cpp ObjectsSection.h \
	Section.cpp Section.h \
	TablesSection.cpp TablesSection.h \
	UnknownSection.cpp UnknownSection.h

## Installation information.

libsectionsincdir = $(includedir)/dime/sections

libsectionsinc_HEADERS = \
	$(top_srcdir)/include/dime/sections/BlocksSection.h \
	$(top_srcdir)/include/dime/sections/ClassesSection.h \
	$(top_srcdir)/include/dime/sections/EntitiesSection.h \
	$(top_srcdir)/include/dime/sections/HeaderSection.h \
	$(top_srcdir)/include/dime/sections/ObjectsSection.h \
	$(top_srcdir)/include/dime/sections/Section.h \
	$(top_srcdir)/include/dime/sections/TablesSection.h \
	$(top_srcdir)/include/dime/sections/UnknownSection.h


## FIXME: this is a temporary workaround for a bug in Automake. The
## bug is fixed in the latest Automake CVS, but not in any "official"
## release (?). Last checked with Automake 1.4a. 19990912 mortene.

install-libsectionsincHEADERS: $(libsectionsinc_HEADERS)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(libsectionsincdir)
	@list='$(libsectionsinc_HEADERS)'; for p in $$list; do \
	  if test -f "$$p"; then d= ; else d="$(srcdir)/"; fi; \
	  f="`echo $$p | sed -e 's|^.*/||'`"; \
	  echo " $(INSTALL_DATA) $$d$$p $(DESTDIR)$(libsectionsincdir)/$$f"; \
	  $(INSTALL_DATA) $$d$$p $(DESTDIR)$(libsectionsincdir)/$$f; \
	done

uninstall-libsectionsincHEADERS:
	@$(NORMAL_UNINSTALL)
	@list='$(libsectionsinc_HEADERS)'; for p in $$list; do \
	  f="`echo $$p | sed -e 's|^.*/||'`"; \
	  echo " rm -f $(DESTDIR)$(libsectionsincdir)/$$f"; \
	  rm -f $(DESTDIR)$(libsectionsincdir)/$$f; \
	done
