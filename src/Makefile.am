## Process this file with automake to generate Makefile.in.

CLEANFILES = \
        dime@DIME_MAJOR_VERSION@@SUFFIX@.dll \
        dime@DIME_MAJOR_VERSION@@SUFFIX@.pdb \
        dime@DIME_MAJOR_VERSION@@SUFFIX@.exp

DISTCLEANFILES = \
        ii_files/*.ii

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
	classes/classes.lst entities/entities.lst objects/objects.lst \
	records/records.lst sections/sections.lst tables/tables.lst \
	util/util.lst convert/convert.lst

## All source files from the base directory used when building the
## library, including all headers.

libdime@SUFFIX@_la_SOURCES = \
	$(DimeSources)

dime@DIME_MAJOR_VERSION@@SUFFIX@_lib_SOURCES = \
	$(DimeSources)

# Custom rule for linking a Visual C++ (MS Windows) library.

dime@DIME_MAJOR_VERSION@@SUFFIX@.lib: Makefile \
  $(dime@DIME_MAJOR_VERSION@@SUFFIX@_lib_OBJECTS) \
  $(dime@DIME_MAJOR_VERSION@@SUFFIX@_lib_DEPENDENCIES)
	@basename="dime@DIME_MAJOR_VERSION@@SUFFIX@"; \
	rm -f "$$basename.dll" "$$basename.lib"; \
	echo "Linking $$basename.lib..."; \
	echo $(CC) $(LDFLAGS) $(LIBFLAGS) \
	  $(dime@DIME_MAJOR_VERSION@@SUFFIX@_lib_OBJECTS) \
	  $(dime@DIME_MAJOR_VERSION@@SUFFIX@_lib_LIBADD) $(LIBS); \
	$(CC) $(LDFLAGS) $(LIBFLAGS) \
	  $(dime@DIME_MAJOR_VERSION@@SUFFIX@_lib_OBJECTS) \
	  $(dime@DIME_MAJOR_VERSION@@SUFFIX@_lib_LIBADD) $(LIBS);

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

