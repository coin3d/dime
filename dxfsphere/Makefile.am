## Process this file with automake to generate Makefile.in.
noinst_PROGRAMS = dxfsphere
dxfsphere_SOURCES = dxfsphere.cpp

INCLUDES = -I$(top_srcdir)/include

if BUILD_WITH_MSVC
dxfsphere_LDADD = $(top_builddir)/src/dime.lst
else
dxfsphere_LDADD = $(top_builddir)/src/libdime.la
endif

