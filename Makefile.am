## Process this file with automake to generate Makefile.in.

if BUILD_HTMLPAGES
HTMLDIR = html
else
HTMLDIR =
endif

DXF2VRMLDIR = dxf2vrml
DXFSPHEREDIR = dxfsphere

if BUILD_WITH_MSVC
EXAMPLEPROGDIRS =
else
EXAMPLEPROGDIRS = $(DXF2VRMLDIR) $(DXFSPHEREDIR)
endif

if BUILD_LIBRARY
SRCDIRS = src $(EXAMPLEPROGDIRS)
else
SRCDIRS =
endif

SUBDIRS = $(HTMLDIR) $(SRCDIRS)

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA= dime.pc

EXTRA_DIST = \
        dime.pc.in \
	cfg/errors.txt \
	cfg/gendsp.pl.in \
	cfg/ltconfig \
	cfg/wrapmsvc.exe \
	cfg/csubst.exe \
	cfg/doxy4win.pl \
        docs/dime.doxygen.in \
	docs/doxygen/header.html \
	docs/doxygen/footer.html \
	docs/doxygen/stylesheet.css \
	docs/doxygen/Coin_logo.png

DISTCLEANFILES = \
	dime.pc \
	docs/dime.doxygen

docs/dime.doxygen: $(srcdir)/docs/dime.doxygen.in config.status
	@if test -d docs; then :; else mkdir docs; fi
	@./config.status --file=$@:$@.in
	@$(srcdir)/cfg/doxy4win.pl docs/dime.doxygen

doxygen-doc: built-sources
	if test x"@DIME_DOC_HTML@" = x"YES"; then \
	  mkdir -p "@dime_html_dir@"; \
	else :; fi
	@sim_ac_doxygen_exe@ $(top_builddir)/docs/dime.doxygen

doxygen-docs: built-sources
	if test x"@DIME_DOC_HTML@" = x"YES"; then \
	  mkdir -p "@dime_html_dir@"; \
	else :; fi
	@sim_ac_doxygen_exe@ $(top_builddir)/docs/dime.doxygen
