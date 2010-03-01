## Process this file with automake to generate Makefile.in.

DXF2VRMLDIR = dxf2vrml
DXFSPHEREDIR = dxfsphere

if BUILD_WITH_MSVC
EXAMPLEPROGDIRS =
else
EXAMPLEPROGDIRS = $(DXF2VRMLDIR) $(DXFSPHEREDIR)
endif

SUBDIRS = src $(EXAMPLEPROGDIRS)

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA= dime.pc

EXTRA_DIST = \
        dime.pc.in

DISTCLEANFILES = \
	dime.pc
