#!/bin/sh

# Author: Morten Eriksen, <mortene@sim.no>. Loosely based on Ralph
# Levien's script for Gnome.

DIE=false

PROJECT=Dime

# Autoconf snapshot from ftp://alpha.gnu.org/gnu/autoconf/autoconf-2.49a.tar.gz
AUTOCONF_VER=2.52
AUTOMAKE_VER=1.5    # CVS development version
LIBTOOL_VER=1.4.2

if test -z "`autoconf --version | grep \" $AUTOCONF_VER\" 2> /dev/null`"; then
  cat <<EOF

  Invalid Version of Autoconf
  ---------------------------
  You must use the CVS development version of autoconf ($AUTOCONF_VER)
  to generate configure information and Makefiles for $PROJECT.
  You can find the pre-release snapshot at:

  ftp://alpha.gnu.org/gnu/autoconf/autoconf-2.49a.tar.gz

EOF
  DIE=true
fi

if test -z "`automake --version | grep \" $AUTOMAKE_VER\" 2> /dev/null`"; then
  cat <<EOF

  Invalid Version of Automake
  ---------------------------
  You must use the CVS development version of automake to ($AUTOMAKE_VER)
  to generate configure information and Makefiles for $PROJECT.

  The CVS automake repository can be fetched by running the following
  set of commands:

  $ cvs -d :pserver:anoncvs@anoncvs.cygnus.com:/cvs/automake login
  $ cvs -d :pserver:anoncvs@anoncvs.cygnus.com:/cvs/automake co automake

EOF
  DIE=true
fi

if test -z "`libtool --version | grep \" $LIBTOOL_VER \" 2> /dev/null`"; then
  cat <<EOF

  Invalid Version of Libtool
  --------------------------
  You must have libtool version $LIBTOOL_VER installed to generate
  configure information and Makefiles for $PROJECT.

  Get ftp://ftp.gnu.org/pub/gnu/libtool/libtool-1.3.5.tar.gz

EOF
  DIE=true
fi


$DIE && exit 1

echo "Running aclocal"
aclocal

echo "Running autoheader"
autoheader

echo "Running automake..."
automake

echo "Running autoconf"
autoconf

echo "Now type './configure' and 'make' to compile $PROJECT."
