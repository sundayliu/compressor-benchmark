#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([benchmark], [0.0.1], [sundayliu@aliyun.com])
AC_CONFIG_SRCDIR([src/benchmark.cc])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE
# Checks for programs.
AC_PROG_CXX



# Checks for libraries.

# Other compression libraries
UNITTEST_LIBS=""
AC_DEFUN([CHECK_EXT_COMPRESSION_LIB],[
	AH_CHECK_LIB([$1])
	AC_CHECK_LIB([$1],
	[$2],
	[
		AC_DEFINE_UNQUOTED(AS_TR_CPP(HAVE_LIB$1))
		UNITTEST_LIBS="-l$1 $UNITTEST_LIBS"
	],
	[true]
	)
])
CHECK_EXT_COMPRESSION_LIB([lzf],[lzf_compress])
AC_SUBST([UNITTEST_LIBS])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
