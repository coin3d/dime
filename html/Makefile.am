# NOTES:
#   This Makefile.am relies on $(htmldir) being AC_SUBST'ed into place...

if BUILD_HTMLPAGES

# **************************************************************************
# build trickery

$(top_builddir)/docs/dime.doxygen: $(top_srcdir)/docs/dime.doxygen.in $(top_builddir)/config.status
	@( cd $(top_builddir); $(MAKE) docs/dime.doxygen )

index.html: $(top_builddir)/docs/dime.doxygen
	@( cd ..; \
	echo " $(sim_ac_doxygen_exe) docs/dime.doxygen"; \
	"$(sim_ac_doxygen_exe)" docs/dime.doxygen )

filelist.txt: index.html
	@if cmp -s $(top_srcdir)/docs/doxygen/Coin_logo.png Coin_logo.png; then :; else \
	  echo  " cp $(top_srcdir)/docs/doxygen/Coin_logo.png ."; \
	  cp $(top_srcdir)/docs/doxygen/Coin_logo.png .; \
	fi
	@ls -1 | egrep '(\.html|\.png|\.gif|\.css|\.tag)$$' >filelist.txt

all-local: filelist.txt

install-data-local: install-html

uninstall-local: uninstall-html

endif