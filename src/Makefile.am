## Process this file with automake to generate Makefile.in.

SUBDIRS = classes entities objects records sections tables util convert .

INCLUDES = -I$(top_srcdir)/include

if BUILD_WITH_MSVC
lib_LIBRARIES = dime@DIME_MAJOR_VERSION@@SUFFIX@.lib
else
lib_LTLIBRARIES = libdime@SUFFIX@.la
endif

DimeSources = \
	Base.cpp Base.h \
	Basic.cpp Basic.h \
	Input.cpp Input.h \
	Layer.cpp Layer.h \
	Model.cpp Model.h \
	Output.cpp Output.h \
	RecordHolder.cpp RecordHolder.h \
	State.cpp State.h

libdime@SUFFIX@_la_LIBADD = \
	classes/libclasses.la entities/libentities.la objects/libobjects.la \
	records/librecords.la sections/libsections.la tables/libtables.la \
	util/libutil.la convert/libconvert.la

libdime@SUFFIX@_la_LDFLAGS = \
	-version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE)

dime@DIME_MAJOR_VERSION@@SUFFIX@_lib_LIBADD = \
	classes/libclasses.lst entities/libentities.lst objects/libobjects.lst \
	records/librecords.lst sections/libsections.lst tables/libtables.lst \
	util/libutil.lst convert/libconvert.lst

## All source files from the base directory used when building the
## library, including all headers.

libdime@SUFFIX@_la_SOURCES = \
	$(DimeSources)

dime@DIME_MAJOR_VERSION@@SUFFIX@_lib_SOURCES = \
	$(DimeSources)

## Installation information.

libdimeincdir = $(includedir)/dime

libdimeinc_HEADERS = \
	../include/dime/Base.h \
	../include/dime/Basic.h \
	../include/dime/Input.h \
	../include/dime/Layer.h \
	../include/dime/Model.h \
	../include/dime/Output.h \
	../include/dime/RecordHolder.h \
	../include/dime/State.h

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

