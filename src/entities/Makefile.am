## Process this file with automake to generate Makefile.in.

noinst_LTLIBRARIES = libentities.la

## Remove any linklibraries detected by configure, as they are not
## needed in the submodules -- only in the toplevel libdime build.
LIBS = 

INCLUDES = -I$(top_srcdir)/include

## All source files used when building this submodule, including all
## headers.

libentities_la_SOURCES = \
	3DFace.cpp 3DFace.h \
	Arc.cpp Arc.h \
	Block.cpp Block.h \
	Circle.cpp Circle.h \
	Ellipse.cpp Ellipse.h \
	Entity.cpp Entity.h \
	ExtrusionEntity.cpp ExtrusionEntity.h \
	FaceEntity.cpp FaceEntity.h \
	Insert.cpp Insert.h \
	LWPolyline.cpp LWPolyline.h \
	Line.cpp Line.h \
	Point.cpp Point.h \
	Polyline.cpp Polyline.h \
	Solid.cpp Solid.h \
	Spline.cpp Spline.h \
	Trace.cpp Trace.h \
	UnknownEntity.cpp UnknownEntity.h \
	Vertex.cpp Vertex.h

## Installation information.

libentitiesincdir = $(includedir)/dime/entities

libentitiesinc_HEADERS = \
	$(top_srcdir)/include/dime/entities/3DFace.h \
	$(top_srcdir)/include/dime/entities/Arc.h \
	$(top_srcdir)/include/dime/entities/Block.h \
	$(top_srcdir)/include/dime/entities/Circle.h \
	$(top_srcdir)/include/dime/entities/Ellipse.h \
	$(top_srcdir)/include/dime/entities/Entity.h \
	$(top_srcdir)/include/dime/entities/ExtrusionEntity.h \
	$(top_srcdir)/include/dime/entities/FaceEntity.h \
	$(top_srcdir)/include/dime/entities/Insert.h \
	$(top_srcdir)/include/dime/entities/LWPolyline.h \
	$(top_srcdir)/include/dime/entities/Line.h \
	$(top_srcdir)/include/dime/entities/Point.h \
	$(top_srcdir)/include/dime/entities/Polyline.h \
	$(top_srcdir)/include/dime/entities/Solid.h \
	$(top_srcdir)/include/dime/entities/Spline.h \
	$(top_srcdir)/include/dime/entities/Trace.h \
	$(top_srcdir)/include/dime/entities/UnknownEntity.h \
	$(top_srcdir)/include/dime/entities/Vertex.h


## FIXME: this is a temporary workaround for a bug in Automake. The
## bug is fixed in the latest Automake CVS, but not in any "official"
## release (?). Last checked with Automake 1.4a. 19990912 mortene.

install-libentitiesincHEADERS: $(libentitiesinc_HEADERS)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(libentitiesincdir)
	@list='$(libentitiesinc_HEADERS)'; for p in $$list; do \
	  if test -f "$$p"; then d= ; else d="$(srcdir)/"; fi; \
	  f="`echo $$p | sed -e 's|^.*/||'`"; \
	  echo " $(INSTALL_DATA) $$d$$p $(DESTDIR)$(libentitiesincdir)/$$f"; \
	  $(INSTALL_DATA) $$d$$p $(DESTDIR)$(libentitiesincdir)/$$f; \
	done

uninstall-libentitiesincHEADERS:
	@$(NORMAL_UNINSTALL)
	@list='$(libentitiesinc_HEADERS)'; for p in $$list; do \
	  f="`echo $$p | sed -e 's|^.*/||'`"; \
	  echo " rm -f $(DESTDIR)$(libentitiesincdir)/$$f"; \
	  rm -f $(DESTDIR)$(libentitiesincdir)/$$f; \
	done
