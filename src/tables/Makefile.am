## Process this file with automake to generate Makefile.in.

noinst_LTLIBRARIES = libtables.la

## Remove any linklibraries detected by configure, as they are not
## needed in the submodules -- only in the toplevel libdime build.
LIBS = 

INCLUDES = -I$(top_srcdir)/include

## All source files used when building this submodule, including all
## headers.

libtables_la_SOURCES = \
	LayerTable.cpp LayerTable.h \
	Table.cpp Table.h \
	TableEntry.cpp TableEntry.h \
	UCSTable.cpp UCSTable.h \
	UnknownTable.cpp UnknownTable.h

## Installation information.

libtablesincdir = $(includedir)/dime/tables

libtablesinc_HEADERS = \
	$(top_srcdir)/include/dime/tables/LayerTable.h \
	$(top_srcdir)/include/dime/tables/Table.h \
	$(top_srcdir)/include/dime/tables/TableEntry.h \
	$(top_srcdir)/include/dime/tables/UCSTable.h \
	$(top_srcdir)/include/dime/tables/UnknownTable.h


## FIXME: this is a temporary workaround for a bug in Automake. The
## bug is fixed in the latest Automake CVS, but not in any "official"
## release (?). Last checked with Automake 1.4a. 19990912 mortene.

install-libtablesincHEADERS: $(libtablesinc_HEADERS)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(libtablesincdir)
	@list='$(libtablesinc_HEADERS)'; for p in $$list; do \
	  if test -f "$$p"; then d= ; else d="$(srcdir)/"; fi; \
	  f="`echo $$p | sed -e 's|^.*/||'`"; \
	  echo " $(INSTALL_DATA) $$d$$p $(DESTDIR)$(libtablesincdir)/$$f"; \
	  $(INSTALL_DATA) $$d$$p $(DESTDIR)$(libtablesincdir)/$$f; \
	done

uninstall-libtablesincHEADERS:
	@$(NORMAL_UNINSTALL)
	@list='$(libtablesinc_HEADERS)'; for p in $$list; do \
	  f="`echo $$p | sed -e 's|^.*/||'`"; \
	  echo " rm -f $(DESTDIR)$(libtablesincdir)/$$f"; \
	  rm -f $(DESTDIR)$(libtablesincdir)/$$f; \
	done
