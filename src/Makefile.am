## Process this file with automake to generate Makefile.in.

lib_LTLIBRARIES = libdime.la

libdime_la_LIBADD = \
	classes/libclasses.la entities/libentities.la objects/libobjects.la \
	records/librecords.la sections/libsections.la tables/libtables.la \
	util/libutil.la convert/libconvert.la

SUBDIRS = classes entities objects records sections tables util convert .

INCLUDES = -I$(top_srcdir)/include

## All source files from the base directory used when building the
## library, including all headers.

libdime_la_SOURCES = \
	Base.cpp Base.h \
	Basic.cpp Basic.h \
	Input.cpp Input.h \
	Layer.cpp Layer.h \
	Model.cpp Model.h \
	Output.cpp Output.h \
	RecordHolder.cpp RecordHolder.h \
	State.cpp State.h

## Installation information.

libdimeincdir = $(includedir)/dime

libdime_la_LDFLAGS = \
	-version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE)

libdimeinc_HEADERS = \
	$(top_srcdir)/include/dime/Base.h \
	$(top_srcdir)/include/dime/Basic.h \
	$(top_srcdir)/include/dime/Input.h \
	$(top_srcdir)/include/dime/Layer.h \
	$(top_srcdir)/include/dime/Model.h \
	$(top_srcdir)/include/dime/Output.h \
	$(top_srcdir)/include/dime/RecordHolder.h \
	$(top_srcdir)/include/dime/State.h


## FIXME: this is a temporary workaround for a bug in Automake. The
## bug is fixed in the latest Automake CVS, but not in any "official"
## release (?). Last checked with Automake 1.4a. 19990912 mortene.

install-libdimeincHEADERS: $(libdimeinc_HEADERS)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(libdimeincdir)
	@list='$(libdimeinc_HEADERS)'; for p in $$list; do \
	  if test -f "$$p"; then d= ; else d="$(srcdir)/"; fi; \
	  f="`echo $$p | sed -e 's|^.*/||'`"; \
	  echo " $(INSTALL_DATA) $$d$$p $(DESTDIR)$(libdimeincdir)/$$f"; \
	  $(INSTALL_DATA) $$d$$p $(DESTDIR)$(libdimeincdir)/$$f; \
	done

uninstall-libdimeincHEADERS:
	@$(NORMAL_UNINSTALL)
	@list='$(libdimeinc_HEADERS)'; for p in $$list; do \
	  f="`echo $$p | sed -e 's|^.*/||'`"; \
	  echo " rm -f $(DESTDIR)$(libdimeincdir)/$$f"; \
	  rm -f $(DESTDIR)$(libdimeincdir)/$$f; \
	done

