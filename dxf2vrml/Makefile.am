## Process this file with automake to generate Makefile.in.
noinst_PROGRAMS = dxf2vrml
dxf2vrml_SOURCES = dxf2vrml.cpp

INCLUDES = -I$(top_srcdir)/include

if BUILD_WITH_MSVC
dxf2vrml_LDADD = $(top_builddir)/src/dime0.lib
else
dxf2vrml_LDADD = $(top_builddir)/src/libdime.la
endif

