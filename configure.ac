####### AC-AM Package Preliminaries #######

AC_PREREQ([2.61])
AC_INIT([opentxs],m4_esyscmd(tr -d '\n' <VERSION),[Fellow-Traveler],[opentxs],[https://github.com/FellowTraveler/Open-Transactions])
AC_CONFIG_SRCDIR([src/otd/main.cpp])
AC_CONFIG_HEADERS([config.h])
AX_PREFIX_CONFIG_H(include/otlib/ot_config.h)
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([build-aux/m4])

AM_INIT_AUTOMAKE([1.10 foreign])
m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])

## special prelims
AC_FUNC_STRNLEN

## libtool prelims
LT_PREREQ([2.2.4])
LT_INIT([dlopen])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_CPP
: ${CXXFLAGS=""}
: ${CFLAGS=""}
: ${CPPFLAGS=""}

PKG_PROG_PKG_CONFIG([0.25])

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h float.h limits.h malloc.h memory.h netinet/in.h stddef.h stdint.h stdlib.h string.h sys/time.h sys/timeb.h unistd.h wchar.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT32_T
AC_C_RESTRICT
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_ALLOCA
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_FUNC_STRERROR_R
AC_FUNC_STRTOD
AC_CHECK_FUNCS([getpass gettimeofday mkdir socket strtol strtoul])

###     GCC AND CLANG DETECTION     ###
### (from mesa's configure.ac file) ###

dnl clang is mostly GCC-compatible, but its version is much lower,
dnl so we have to check for it.
AC_MSG_CHECKING([if compiling with clang])

AC_COMPILE_IFELSE(
[AC_LANG_PROGRAM([], [[
#ifndef __clang__
       not clang
#endif
]])],
[acv_ot_clang=yes], [acv_ot_clang=no])

AC_MSG_RESULT([$acv_ot_clang])

dnl If we're using GCC, make sure that it is at least version 4.2.0.  Older
dnl versions are explictly not supported.
if test "x$GCC" = xyes -a "x$acv_ot_clang" = xno; then
    AC_MSG_CHECKING([whether gcc version is sufficient])
    major=0
    minor=0

    GCC_VERSION=`$CC -dumpversion`
    if test $? -eq 0; then
        major=`echo $GCC_VERSION | cut -d. -f1`
        minor=`echo $GCC_VERSION | cut -d. -f2`
    fi

    if test $major -lt 4 -o $major -eq 4 -a $minor -lt 2 ; then
        AC_MSG_RESULT([no])
        AC_MSG_ERROR([If using GCC, version 4.2.0 or later is required.])
    else
        AC_MSG_RESULT([yes])
    fi
fi


######## Prelims end, Custom checks begin #######

##### Dependencies, packages, libs ####
#
## Main packages deps ##

PKG_CHECK_MODULES([PKGS],[protobuf >= 2.4.1 chaiscript >= 3.1.0])

AC_ARG_WITH([protoc],
    [AS_HELP_STRING([--with-protoc=PATH],
        [location of the protoc protocol buffer compiler binary, defaults to protoc])],
    [PROTOC="$withval"],
    [PROTOC='protoc'])
AC_SUBST([PROTOC])

## OpenSSL
# "--with-openssl=DIR" point to optional openssl package headers (for devs)

AX_CHECK_OPENSSL([acv_ot_openssl="yes"])

if test "x$acv_ot_openssl" = xyes; then
    AC_DEFINE([HAVE_OPENSSL], [1], [We have openSSL])
else
    AC_MSG_ERROR([ERROR: Cannot find openssl, please use --with-openssl=openssl_dir])
fi


## BOOST ##

AC_ARG_ENABLE([boost],
	AS_HELP_STRING([--enable-boost],[disable boost, default: yes]),
	[case "${enableval}" in
		yes) boost=true ;;
		no)  boost=false ;;
		*)   AC_MSG_ERROR([bad value ${enableval} for --disable-boost]) ;;
        esac],[boost=true])
AM_CONDITIONAL([WANT_BOOST], [test x"$boost" = x"true"])

if test "x$boost" = xtrue; then
    AX_BOOST_BASE([1.25.0])
    AX_BOOST_THREAD
    AX_BOOST_DATE_TIME
    AX_BOOST_SYSTEM
    AC_SUBST([BOOST_LIB_INCLUDE],["$BOOST_THREAD_LIB $BOOST_DATE_TIME_LIB $BOOST_SYSTEM_LIB"])
    AC_DEFINE([HAVE_BOOST], [1], [We have boost])
fi


## MsgPack ##

AC_CHECK_LIB([msgpack],[msgpack_unpack],
	[MSG_LIBS="-lmsgpack"
	AC_CHECK_HEADERS([msgpack.h],[],
		[AC_MSG_ERROR([No header files for libmsgpack found!])]
		)
	],
	[AC_MSG_RESULT([Warning: libmsgpack not found!])]
	)

## pthread lib ##

AX_PTHREAD

## Transport Options (ZMQ defaut) ##

AC_ARG_WITH(	[transport],
		[AS_HELP_STRING([--with-transport@<:@=zmq@:>@],
		[Choose a transport backend (available: zmq, testclient)])],
		[case "${withval}" in
			zmq) true ;;
			testclient) true ;;
			*) AC_MSG_ERROR([bad value ${withval} for --with-transport]) ;;
			esac],
		[with_transport=zmq])

AM_CONDITIONAL(	[TRANSPORT_ZMQ],	[test "$with_transport" == zmq])
AM_CONDITIONAL(	[TRANSPORT_TESTCLIENT],	[test "$with_transport" == testclient])

AS_IF(	[test "$with_transport" == zmq],
	[PKG_CHECK_MODULES([ZMQ],[libzmq >= 2.1.4],
		[AC_LANG_PUSH([C++])
		AC_CHECK_HEADERS([zmq.hpp],
			[],
			[AC_MSG_ERROR([Header files for libzmq not found or incompatible.])],
			[])
		AC_LANG_POP],
		[AC_MSG_RESULT([Warning: libzmq version >= 2.1.4 not found!])]
		)
	])
    
if test "$with_transport" == zmq; then
    AC_DEFINE([TRANSPORT_ZMQ], [1], [Using ZMQ Transport])
else
    AC_MSG_ERROR([ERROR: Only ZMQ Transport Supported!])
fi

## Keyring Options ##

AC_ARG_WITH(	[keyring],
		[AS_HELP_STRING([--with-keyring@<:@=ARG@:>@],
		[Choose one keyring ARG from: windows, mac, gnome, kwallet])],
		[case "${withval}" in
##			windows) true ;;
			mac) true ;;
			gnome) true ;;
			kwallet) true ;;
			*) AC_MSG_ERROR([bad value ${withval} for --with-keyring]) ;;
			esac],
		[])

AM_CONDITIONAL([KEYRING_WINDOWS],	[test "$with_keyring" == windows])
AM_CONDITIONAL([KEYRING_MAC],		[test "$with_keyring" == mac])
AM_CONDITIONAL([KEYRING_GNOME],		[test "$with_keyring" == gnome])
AM_CONDITIONAL([KEYRING_KWALLET],	[test "$with_keyring" == kwallet])

AS_IF(	[test "$with_keyring" == windows],
	[
	AC_SUBST(KRG_CFLAGS,[""])
	AC_SUBST(KRG_LIBS,[""])
    AC_DEFINE([KEYRING_WINDOWS], [1], [Using Windows Keyring])
	])
##  WINDOWS build flags needed here #

AS_IF(	[test "$with_keyring" == mac],
	[
	AC_SUBST(KRG_CFLAGS,["-isysroot /Developer/SDKs/MacOSX10.6.sdk -arch ppc -arch i386"])
	AC_SUBST(KRG_LIBS,["-syslibroot /Developer/SDKs/MacOSX10.6.sdk -arch ppc -arch i386"])
    AC_DEFINE([KEYRING_MAC], [1], [Using Mac Keyring])
	])

AS_IF(	[test "$with_keyring" == gnome],
	[
	PKG_CHECK_MODULES([KRG],[glib-2.0 >= 2.28.6 gnome-keyring-1])
    AC_DEFINE([KEYRING_GNOME], [1], [Using Gnome Keyring])
	])

AS_IF(	[test "$with_keyring" == kwallet],
	[
	AC_SUBST(KRG_CFLAGS,	["-I/usr/include/kde"])
	AC_SUBST(KRG_LIBS,	["-L/usr/lib -lkwalletclient"])
    AC_DEFINE([KEYRING_KWALLET], [1], [Using KWallet Keyring])
	])


#### More Configure Options ####

## (Option) Signal Handler ##

AC_ARG_ENABLE(
	sighandler,
	AS_HELP_STRING(
		[--enable-sighandler],
		[enable sighandler, default: no]),
	[case "${enableval}" in
		yes)	sighandler=true ;;
		no)	sighandler=false ;;
		*)	AC_MSG_ERROR([bad value ${enableval} for --disable-sighandler]) ;;
		esac],
	[sighandler=false])

AM_CONDITIONAL(ENABLE_OT_SIGNAL_HANDLING, test x"$sighandler" = x"true")

if test x"$sighandler" = x"true"; then
    AC_DEFINE([OT_SIGNAL_HANDLING], [1], [Using OT Signal Handling])
fi

## (Option) Warnings ##

AC_ARG_ENABLE(
	warnings,
	AS_HELP_STRING(
		[--enable-warnings],
		[enable warnings, default: no]),
	[case "${enableval}" in
		yes) warnings=true ;;
		no)  warnings=false ;;
		*)   AC_MSG_ERROR([bad value ${enableval} for --enable-warnings]) ;;
		esac],
	[warnings=false])

AM_CONDITIONAL(ENABLE_WARNINGS, test x"$warnings" = x"true")

if (test "x$warnings" == x"true"); then

	AC_SUBST([WARN_CXXFLAGS],
	["-Wall -Waddress -Woverloaded-virtual -Wshadow -Wconversion"])
fi

## (Option) Build In Release Mode ##


AC_ARG_ENABLE([debug],
	AS_HELP_STRING([--enable-debug],[enable debug, default: no]),
	[case "${enableval}" in
		yes) debug=true ;;
		no)  debug=false ;;
		*)   AC_MSG_ERROR([bad value ${enableval} for --enable-debug]) ;;
        esac],[debug=false])
AM_CONDITIONAL([ENALBE_DEBUG], [test x$debug = xtrue])


AC_ARG_ENABLE([release],
	AS_HELP_STRING([--enable-release],[enable release, default: no]),
	[case "${enableval}" in
		yes) release=true ;;
		no)  release=false ;;
		*)   AC_MSG_ERROR([bad value ${enableval} for --enable-release]) ;;
        esac],[release=false])
AM_CONDITIONAL([ENABLE_RELEASE], [test x$release = xtrue])

if (test "x$debug" == x"true" -a "x$release" == x"true"); then
    AC_MSG_ERROR([must not have both release and debug set!])
fi

if (test "x$debug" == x"false" -a "x$release" == x"false"); then
    AC_MSG_RESULT([defaulting to RELEASE mode!])
    release=true
    AM_CONDITIONAL([ENABLE_RELEASE], [test x$release = xtrue])
fi

if (test "x$debug" == x"true"); then

    if (test "x$acv_ot_clang" == "xyes"); then
        AC_SUBST([DBG_CXXFLAGS],["-g3 -O0 -fPIC"])
    else
        AC_SUBST([DBG_CXXFLAGS],["-g3 -O0 -fPIC -DPIC --param ssp-buffer-size=4"])
    fi
    AC_DEFINE([DEBUG], [1], [Building in Debug Mode])
fi

if (test "x$release" == x"true"); then

    if (test "x$acv_ot_clang" == "xyes"); then
        AC_SUBST([REL_CXXFLAGS],["-g0 -O3 -fPIC -D_FORTIFY_SOURCE=2 -fstack-protector-all -Wstack-protector"])
    else
        AC_SUBST([REL_CXXFLAGS],["-g0 -O3 -fPIC -D_FORTIFY_SOURCE=2 -fstack-protector-all -fstack-check -Wstack-protector"])
    fi
    AC_DEFINE([RELEASE], [1], [Building in Release Mode])
fi


## (Option) Build In C++11 Mode ##

AC_ARG_ENABLE([cxx11],
	AS_HELP_STRING([--enable-cxx11],[enable cxx11, default: yes]),
	[case "${enableval}" in
		yes) cxx11=true ;;
		no)  cxx11=false ;;
		*)   AC_MSG_ERROR([bad value ${enableval} for --enable-cxx11]) ;;
        esac],[cxx11=true])
AM_CONDITIONAL([USE_CXX11], [test x$cxx11 = xtrue])

if (test "x$cxx11" == "xtrue"); then

	AC_SUBST([CXX11_FLAGS],["-std=c++11"])
    AC_DEFINE([HAVE_CXX11], [1], [Building with C++11])
fi

## (Option) Add SWIG JAVA ##

AC_ARG_WITH(
	[java],
	[AS_HELP_STRING([--with-java], [build Java SWIG wrapper])],
	[])

AM_CONDITIONAL([WANT_JAVA], [test "x$with_java" == "xyes"])

if (test "x$with_java" == "xyes"); then

	AX_PROG_JAVAC
	AX_JNI_INCLUDE_DIR

	for JNI_INCLUDE_DIR in $JNI_INCLUDE_DIRS
		do
			JNI_CPPFLAGS="$JNI_CPPFLAGS -I$JNI_INCLUDE_DIR"
    		done

	AC_SUBST([JNI_CPPFLAGS],[$JNI_CPPFLAGS])
fi

## (Option) Add SWIG PERL5 ##

AC_ARG_WITH(
	[perl5],
	[AS_HELP_STRING([--with-perl5], [build Perl5 SWIG wrapper])],
	[])

AM_CONDITIONAL([WANT_PERL5], [test "x$with_perl5" == "xyes"])

if (test "x$with_perl5" == "xyes"); then

	AX_PERL_EXT
fi

## (Option) Add SWIG PHP ##

AC_ARG_WITH(
	[php],
	[AS_HELP_STRING([--with-php], [build PHP SWIG wrapper])],
	[])

AM_CONDITIONAL([WANT_PHP], [test "x$with_php" == "xyes"])

if (test "x$with_php" == "xyes"); then

	AX_PHP_DEVEL
fi

## (Option) Add SWIG PYTHON ##

AC_ARG_WITH(
	[python],
	[AS_HELP_STRING([--with-python], [build Python SWIG wrapper])],
	[])

AM_CONDITIONAL([WANT_PYTHON], [test "x$with_python" == "xyes"])

if (test "x$with_python" == "xyes"); then

	AX_PYTHON_DEVEL([>= '2.1.0'])
fi

## (Option) Add SWIG RUBY ##

AC_ARG_WITH(
	[ruby],
	[AS_HELP_STRING([--with-ruby], [build Ruby SWIG wrapper])],
	[])

AM_CONDITIONAL([WANT_RUBY], [test "x$with_ruby" == "xyes"])

if (test "x$with_ruby" == "xyes"); then

	AC_PATH_PROG([RUBY],[ruby])
	AX_RUBY_DEVEL([1.8.7])
fi

## (Option) Add SWIG TCL ##

AC_ARG_WITH(
	[tcl],
	[AS_HELP_STRING([--with-tcl], [build TCL SWIG wrapper])],
	[])

AM_CONDITIONAL([WANT_TCL], [test "x$with_tcl" == "xyes"])

if (test "x$with_tcl" == "xyes"); then

	AX_PROG_TCL([8.0])
fi

## (Option) Add SWIG CSHARP ##

AC_ARG_WITH(
        [csharp],
        [AS_HELP_STRING([--with-csharp], [build Csharp SWIG wrapper])],
        [])

AM_CONDITIONAL([WANT_CSHARP], [test "x$with_csharp" == "xyes"])

if (test "x$with_csharp" == "xyes"); then

	AX_PROG_CSC
fi

## (Option) Add SWIG D ##

AC_ARG_WITH(
        [d],
        [AS_HELP_STRING([--with-d], [build D SWIG wrapper])],
        [])

AM_CONDITIONAL([WANT_D], [test "x$with_d" == "xyes"])

if (test "x$with_d" == "xyes"); then

	AC_PATH_PROG([GDC_PATH],[gdc])
fi

## (Option) Add SWIG Go ##

AC_ARG_WITH(
        [go],
        [AS_HELP_STRING([--with-go], [build Go SWIG wrapper])],
        [])

AM_CONDITIONAL([WANT_GO], [test "x$with_go" == "xyes"])

#####   Output to AM   #####

AC_SUBST([DEPS_FLAGS],["$PTHREAD_CFLAGS $PKGS_CFLAGS $ZMQ_CFLAGS $KRG_CFLAGS $OPENSSL_CFLAGS $OPENSSL_INCLUDES $BOOST_LIB_INCLUDE"])

AC_SUBST([AM_CFLAGS],["$DEPS_FLAGS"])

AC_SUBST([AM_CXXFLAGS],["$DBG_CXXFLAGS $REL_CXXFLAGS $CXX11_FLAGS $WARN_CXXFLAGS $DEPS_FLAGS"])

AC_SUBST([AM_CPPFLAGS],["$BOOST_CPPFLAGS"])

AC_SUBST([AM_LDFLAGS],["$OPENSSL_LDFLAGS $PKGS_LIBS $ZMQ_LIBS $MSG_LIBS $KRG_LIBS $BOOST_LDFLAGS $OPENSSL_LIBS -ldl $PTHREAD_LIBS"])

AC_CONFIG_FILES([Makefile
			src/otlib/otprotob/Makefile
			src/otlib/bigint/Makefile
			src/otlib/irrxml/Makefile
			src/otlib/lucre/Makefile
			src/otlib/otext/Makefile
			src/otlib/Makefile
			src/otapi/Makefile
			src/Makefile
			src/opentxs.pc])

AC_OUTPUT
