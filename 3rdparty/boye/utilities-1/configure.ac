#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

# Run as follows for release build:
# ./configure --prefix=$HOME/local [--disable-static --enable-shared] --enable-release
# Run as follows for debug build:
# ./configure --prefix=$HOME/local

# On OSX/Darwin, the --rpath option is not supported, so run as follows for release and debug builds, respectively:
# ./configure --prefix=$HOME/local CXXFLAGS=-I$HOME/local/include LDFLAGS="-L$HOME/local/lib" --disable-static --enable-shared --enable-release
# ./configure --prefix=$HOME/local CXXFLAGS=-I$HOME/local/include LDFLAGS="-L$HOME/local/lib" --disable-static --enable-shared

dnl Autoconf requirements
AC_PREREQ(2.50)
AC_INIT([utilities], [1], [hoversta at idi])

# AC_CONFIG_AUX_DIR must be called before AM_INIT_AUTOMAKE
AC_CONFIG_AUX_DIR([config])

AM_INIT_AUTOMAKE([1.9 foreign])

dnl information on the package
AC_CONFIG_SRCDIR([src/options.cpp])
AC_CONFIG_HEADER([config.h])


dnl Checking to see if we should enable debugging.  Default: yes.
AC_MSG_CHECKING([whether to enable debugging])
AC_ARG_ENABLE([debug], [AC_HELP_STRING([--enable-debug=[no/yes]],
		       [turn on debugging [default=yes]])],, [enable_debug=yes])
if test "x$enable_debug" = "xyes"; then
   AC_MSG_RESULT(yes)
else
   AC_MSG_RESULT(no)
fi


dnl Checking to see if we should build optimized.  Default: no.
AC_MSG_CHECKING([whether to optimize compilation])
AC_ARG_ENABLE([optimized], [AC_HELP_STRING([--enable-optimized=[no/yes]],
		       [turn on optimized compilation [default=no]])],, [enable_optimized=no])
if test "x$enable_optimized" = "xyes"; then
   AC_MSG_RESULT(yes)
else
   AC_MSG_RESULT(no)
fi


dnl Checking to see if we should build for release.  Default: no.
AC_MSG_CHECKING([whether to create a release build])
AC_ARG_ENABLE([release], [AC_HELP_STRING([--enable-release=[no/yes]],
		       [create a release build (identical to --disable-debug --enable-optimized) [default=no]])],, [enable_release=no])
if test "x$enable_release" = "xyes"; then
   AC_MSG_RESULT(yes)
   enable_debug="no"
   enable_optimized="yes"
else
   AC_MSG_RESULT(no)
fi


dnl Checking to see if we should enable profiling.  Default: no.
AC_MSG_CHECKING([whether to enable the profiler])
AC_ARG_ENABLE([profiler], [AC_HELP_STRING([--enable-profiler=[no/yes]],
		       [turn on the profiler [default=no]])],
		       , [enable_profiler=no])

if test "x$enable_profiler" = "xyes"; then
   AC_MSG_RESULT(yes)
else
   AC_MSG_RESULT(no)
fi

dnl checks for programs 

AC_PROG_CC
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_CPP

dnl This macro must come before AC_PROG_LIBTOOL
if test "x$enable_debug" = "xyes"; then
   AC_DISABLE_SHARED
fi
#b Substitute AC_PROG_RANLIB with AC_PROB_LIBTOOL if using libtool
# AC_PROG_RANLIB
AC_PROG_LIBTOOL

for tool in CC CXX INSTALL CPP LIBTOOL; do
   if test -z "${!tool}"; then
      AC_MSG_ERROR([Failed to set $tool. A tool required for compilation is missing.])
   fi
done

dnl checks for libraries

# Check for pthread and enable multithreading.  Remember never to
# put the first AC_CHECK_LIB call in a script inside a condition.
AC_CHECK_LIB([rt], [sched_get_priority_max])
if ( test "x$ac_cv_lib_rt_sched_get_priority_max" != xyes ); then
  AC_MSG_WARN([Failed to detect rt (realtime) library!])
fi

AC_CHECK_LIB([pthread], [pthread_create])
if ( test "x$ac_cv_lib_pthread_pthread_create" != xyes); then
  AC_MSG_ERROR([Failed to detect pthread library!])
fi

dnl Check for debugging settings 
if test "x$enable_debug" = "xyes"; then
   CFLAGS="$CFLAGS -g -DDEBUG -O0"
   CXXFLAGS="$CXXFLAGS -g -DDEBUG -O0"
   CPPFLAGS="$CPPFLAGS -g -DDEBUG -O0"
   if test -z "`$CXX --version |grep Intel`"; then
      CFLAGS="$CFLAGS -Wall"
      CXXFLAGS="$CXXFLAGS -Wall"
   else
      AC_MSG_NOTICE([Not adding -Wall to Intel compiler options due to numerous remarks.])
   fi

   AC_CHECK_LIB([efence], [malloc])
   if ( test "x$ac_cv_lib_efence_malloc" != xyes ); then
      AC_MSG_WARN([Failed to detect efence library])
   fi
fi

if test "x$enable_optimized" = "xyes"; then
    CFLAGS="$CFLAGS -O3"
    CPPFLAGS="$CPPFLAGS -O3"
    CXXFLAGS="$CXXFLAGS -O3"
fi

if test "x$enable_profiler" = "xyes"; then
   CFLAGS="$CFLAGS -pg"
   CPPFLAGS="$CPPFLAGS -pg"
   CXXFLAGS="$CXXFLAGS -pg"
fi

dnl Export CPPFLAGS variable (so Makefile substitutions can be made).
dnl b What does this actually mean?  Ref. Automake manual 26.5 "Flag
dnl Variables Ordering", especially 26.5.1 "Compile Flag Variables".
dnl AC_SUBST(CFLAGS)

dnl checks for header files

dnl checks for types
dnl checks for structures
dnl checks for compiler characteristics
dnl checks for library functions
dnl checks for system services

dnl NB! Remember to update list of subdirs in Makefile.am as well!
AC_CONFIG_FILES([Makefile
		 include/Makefile
		 src/Makefile
		])
AC_OUTPUT

