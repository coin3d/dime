
m4_define([DIME_MAJOR], [0])
m4_define([DIME_MINOR], [9])
m4_define([DIME_MICRO], [1])
m4_define([DIME_BETA], [])
m4_define([DIME_VERSION_STRING], [DIME_MAJOR.DIME_MINOR.DIME_MICRO[]DIME_BETA])

m4_define([DIME_ABI_VERSION], [0])
m4_define([DIME_ABI_AGE], [0])
m4_define([DIME_ABI_REVISION], [0])

# **************************************************************************

AC_INIT([dime], [DIME_VERSION_STRING], [dime-support@coin3d.org])

AC_CONFIG_SRCDIR([include/dime/Base.h])
AC_CONFIG_AUX_DIR([cfg])

AC_CANONICAL_SYSTEM

AC_SUBST([DIME_MAJOR_VERSION], [DIME_MAJOR])
AC_SUBST([DIME_MINOR_VERSION], [DIME_MINOR])
AC_SUBST([DIME_MICRO_VERSION], [DIME_MICRO])
AC_SUBST([DIME_BETA_VERSION], [DIME_MICRO])
AC_SUBST([DIME_VERSION], [DIME_VERSION_STRING])

VERSION=$DIME_VERSION

AC_SUBST(DIME_INTERFACE_AGE, 0)
AC_SUBST(DIME_BINARY_AGE, 0)

AC_ARG_ENABLE([msvc],
  [AC_HELP_STRING([--disable-msvc], [don't require MS Visual C++ on Cygwin])],
  [case $enableval in
  no | false) sim_ac_try_msvc=false ;;
  *)          sim_ac_try_msvc=true ;;
  esac],
  [sim_ac_try_msvc=true])

if $sim_ac_try_msvc; then
  SIM_AC_SETUP_MSVC_IFELSE([], [
    case $host in
    *-cygwin) SIM_AC_ERROR([no-msvc++]) ;;
    esac])
  if $BUILD_WITH_MSVC; then
    SIM_AC_SETUP_MSVCRT([
      CPPFLAGS="$CPPFLAGS $sim_ac_msvcrt_CPPFLAGS"
      CFLAGS="$CFLAGS $sim_ac_msvcrt_CFLAGS"
      CXXFLAGS="$CXXFLAGS $sim_ac_msvcrt_CXXFLAGS"
      LDFLAGS="$LDFLAGS $sim_ac_msvcrt_LDFLAGS"
      LIBS="$LIBS $sim_ac_msvcrt_LIBS"
      # sim_ac_msvcrt_LIBLIBS is set up at the end
      # sim_ac_msvcrt_LIBLDFLAGS is set up at the end
      AC_SUBST([DIME_MSVC_LIBC], [$sim_ac_msvcrt])
    ])
  fi
fi

dnl  Locate C++ compiler and set C++ as the default compiler to run
dnl  in tests.
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_CXXCPP
AC_LANG([C++])

dnl *******************************************************************
dnl * Library version control.
dnl *******************************************************************

dnl  Making releases:
dnl    DIME_MICRO_VERSION += 1;
dnl    DIME_INTERFACE_AGE += 1;
dnl    DIME_BINARY_AGE += 1;
dnl  if any functions have been added, set DIME_INTERFACE_AGE to 0.
dnl  if backwards compatibility has been broken,
dnl  set DIME_BINARY_AGE _and_ DIME_INTERFACE_AGE to 0.
dnl 

dnl  libtool versioning
LT_RELEASE=$DIME_MAJOR_VERSION.$DIME_MINOR_VERSION
LT_CURRENT=`expr $DIME_MICRO_VERSION - $DIME_INTERFACE_AGE`
LT_REVISION=$DIME_INTERFACE_AGE
LT_AGE=`expr $DIME_BINARY_AGE - $DIME_INTERFACE_AGE`
AC_SUBST(LT_RELEASE)
AC_SUBST(LT_CURRENT)
AC_SUBST(LT_REVISION)
AC_SUBST(LT_AGE)

AC_SUBST([SUFFIX], [])

dnl *******************************************************************
dnl * Miscellaneous options and initializations.
dnl *******************************************************************

AM_INIT_AUTOMAKE(libdime, $VERSION)

dnl  File to cram results from the configure tests into.
AM_CONFIG_HEADER([include/config.h])

dnl  Default to not building a static library.
dnl  Can be overridden by the user with --enable-static.
AM_DISABLE_STATIC

dnl  Turn off default maintainer make-rules -- use ./autogen.sh instead.
AM_MAINTAINER_MODE

if $BUILD_WITH_MSVC; then
  RANLIB=:
  export RANLIB
fi

dnl  Initialize libtool
AC_PROG_LIBTOOL

dnl *******************************************************************
dnl * Enable/disable compilation with debug information.
dnl *******************************************************************

AC_ARG_ENABLE(debug,
  [  --enable-debug          turn on Dime debugging [default=yes]],
  [case "${enableval}" in
    yes) enable_debug=yes ;;
    no)  enable_debug=no ;;
    *) AC_MSG_ERROR(bad value "${enableval}" for --enable-debug) ;;
  esac],
  enable_debug=yes)

if test "x$enable_debug" = "xno"; then
  CXXFLAGS="$CXXFLAGS -DNDEBUG"
fi


dnl *******************************************************************
dnl * Enable/disable compilation with symbol information.
dnl *******************************************************************

if test "x$ac_cv_prog_cxx_g" = "xyes"; then
  AC_ARG_ENABLE(symbols,
    [  --enable-symbols        turn on symbol debug information [default=yes]],
    [case "${enableval}" in
      yes) enable_symbols=yes ;;
      no)  enable_symbols=no ;;
      *) AC_MSG_ERROR(bad value "${enableval}" for --enable-symbols) ;;
    esac],
    enable_symbols=yes)

  if test "x$enable_symbols" = "xno"; then
    CXXFLAGS="`echo $CXXFLAGS | sed 's/-g//'`"
  fi
fi


dnl *******************************************************************
dnl * Enable/disable compilation with profiling information
dnl * for parsing by gprof (this is a g++ only option).
dnl *******************************************************************

if test "x$ac_cv_prog_cxx_g" = "xyes"; then
  AC_ARG_ENABLE(profile,
    [  --enable-profile        turn on inclusion of profiling code [default=no]],
    [case "${enableval}" in
      yes) enable_profile=yes ;;
      no)  enable_profile=no ;;
      *) AC_MSG_ERROR(bad value "${enableval}" for --enable-profile) ;;
    esac],
    enable_profile=no)

  if test "x$enable_profile" = "xyes"; then
    CXXFLAGS="$CXXFLAGS -pg"
    LDFLAGS="$LDFLAGS -pg"
  fi
fi


dnl *******************************************************************
dnl * Enable/disable compilation with warnings turned on (g++ only).
dnl *******************************************************************

if test "x$ac_cv_prog_gxx" = "xyes"; then
  AC_ARG_ENABLE(warnings,
    [  --enable-warnings       turn on warnings when compiling [default=no]],
    [case "${enableval}" in
      yes) enable_warnings=yes ;;
      no)  enable_warnings=no ;;
      *) AC_MSG_ERROR(bad value "${enableval}" for --enable-warnings) ;;
    esac],
    enable_warnings=no)

  if test "x$enable_warnings" = "xyes"; then
    CXXFLAGS="$CXXFLAGS -W -Wall"
  fi
fi


AM_CONDITIONAL([BUILD_WITH_MSVC], [$BUILD_WITH_MSVC])

# no DLL setup yet
DIME_STATIC=true
# case $enable_static in
# yes | true)  DIME_STATIC=true ;;
# *)           DIME_STATIC=false ;;
# esac

# case $enable_shared in
# yes | true)  DIME_STATIC=false ;;
# *)           DIME_STATIC=true ;;
# esac

AC_SUBST([LIBFLAGS], [])

if $BUILD_WITH_MSVC; then
  rm -f vc60.pdb
  LIBS="$LIBS $sim_ac_msvcrt_LIBLIBS"
  LIBFLAGS="$LIBFLAGS $sim_ac_msvcrt_LIBLDFLAGS"
  if $DIME_STATIC; then
    DIME_EXTRA_CPPFLAGS="$DIME_EXTRA_CPPFLAGS -DDIME_NOT_DLL"
  else
    CPPFLAGS="-DDIME_MAKE_DLL $CPPFLAGS"
    DIME_EXTRA_CPPFLAGS="$DIME_EXTRA_CPPFLAGS -DDIME_DLL"
  fi

  debugfile="`pwd`/src/dime${DIME_MAJOR_VERSION}${SUFFIX}.pdb"
  debugfile=`cygpath -w "$debugfile" | sed 's,\\\\,\\\\\\\\,g'`

  if $DIME_STATIC; then
    SIM_AC_CONFIGURATION_SETTING([Dime build type], [static .lib])
    LIBFLAGS="-LIB $LIBFLAGS"
    LIBFLAGS="$LIBFLAGS /OUT:dime$DIME_MAJOR_VERSION$SUFFIX.lib"
  else
    LIBFLAGS="-DLL /INCREMENTAL:NO $LIBFLAGS"
    case $enable_symbols in
    no | false)
      SIM_AC_CONFIGURATION_SETTING([Dime build type],
                                   [dynamic .dll, no symbols])
      LIBFLAGS="$LIBFLAGS /RELEASE"
      ;;
    *)
      SIM_AC_CONFIGURATION_SETTING([Dime build type],
                                   [dynamic .dll + .pdb])
      CFLAGS="/Fd$debugfile $CFLAGS"
      CXXFLAGS="/Fd$debugfile $CXXFLAGS"
      LIBFLAGS="$LIBFLAGS /DEBUG /PDB:dime$DIME_MAJOR_VERSION$SUFFIX.pdb"
      ;;
    esac
    LIBFLAGS="$LIBFLAGS /OUT:dime$DIME_MAJOR_VERSION$SUFFIX.dll"
  fi
  SIM_AC_CONFIGURATION_SETTING([C library linkage], [$sim_ac_msvcrt])
  if test -n "$DIME_EXTRA_LIBS"; then
    DIME_EXTRA_LIBS="-ldime${DIME_MAJOR_VERSION}${SUFFIX} $DIME_EXTRA_LIBS"
  else
    DIME_EXTRA_LIBS="-ldime${DIME_MAJOR_VERSION}${SUFFIX}"
  fi
fi

dnl *******************************************************************

AC_OUTPUT([
	Makefile
	src/Makefile
	src/classes/Makefile
	src/entities/Makefile
	src/objects/Makefile
	src/records/Makefile
	src/sections/Makefile
	src/tables/Makefile
	src/util/Makefile
	src/convert/Makefile
	dxf2vrml/Makefile
])
