## Process this file with automake to generate Makefile.in.

noinst_LTLIBRARIES = librecords.la

## Remove any linklibraries detected by configure, as they are not
## needed in the submodules -- only in the toplevel libdime build.
LIBS = 

INCLUDES = -I$(top_srcdir)/include

## All source files used when building this submodule, including all
## headers.

librecords_la_SOURCES = \
	DoubleRecord.cpp DoubleRecord.h \
	FloatRecord.cpp FloatRecord.h \
	HexRecord.cpp HexRecord.h \
	Int16Record.cpp Int16Record.h \
	Int32Record.cpp Int32Record.h \
	Int8Record.cpp Int8Record.h \
	Record.cpp Record.h \
	StringRecord.cpp StringRecord.h

## Installation information.

librecordsincdir = $(includedir)/dime/records

librecordsinc_HEADERS = \
	$(top_srcdir)/include/dime/records/DoubleRecord.h \
	$(top_srcdir)/include/dime/records/FloatRecord.h \
	$(top_srcdir)/include/dime/records/HexRecord.h \
	$(top_srcdir)/include/dime/records/Int16Record.h \
	$(top_srcdir)/include/dime/records/Int32Record.h \
	$(top_srcdir)/include/dime/records/Int8Record.h \
	$(top_srcdir)/include/dime/records/Record.h \
	$(top_srcdir)/include/dime/records/StringRecord.h


## FIXME: this is a temporary workaround for a bug in Automake. The
## bug is fixed in the latest Automake CVS, but not in any "official"
## release (?). Last checked with Automake 1.4a. 19990912 mortene.

install-librecordsincHEADERS: $(librecordsinc_HEADERS)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(librecordsincdir)
	@list='$(librecordsinc_HEADERS)'; for p in $$list; do \
	  if test -f "$$p"; then d= ; else d="$(srcdir)/"; fi; \
	  f="`echo $$p | sed -e 's|^.*/||'`"; \
	  echo " $(INSTALL_DATA) $$d$$p $(DESTDIR)$(librecordsincdir)/$$f"; \
	  $(INSTALL_DATA) $$d$$p $(DESTDIR)$(librecordsincdir)/$$f; \
	done

uninstall-librecordsincHEADERS:
	@$(NORMAL_UNINSTALL)
	@list='$(librecordsinc_HEADERS)'; for p in $$list; do \
	  f="`echo $$p | sed -e 's|^.*/||'`"; \
	  echo " rm -f $(DESTDIR)$(librecordsincdir)/$$f"; \
	  rm -f $(DESTDIR)$(librecordsincdir)/$$f; \
	done
