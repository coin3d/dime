## Process this file with automake to generate Makefile.in.

INCLUDES = -I$(top_srcdir)/include

if BUILD_WITH_MSVC
else
noinst_PROGRAMS = dxfsphere
dxfsphere_SOURCES = dxfsphere.cpp
dxfsphere_LDADD = $(top_builddir)/src/libdime.la
endif

