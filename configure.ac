AC_INIT([opentxs], m4_esyscmd([tr -d '\n' <VERSION]), [Fellow-Traveler], [opentxs], [https://github.com/FellowTraveler/Open-Transactions])
AC_PREREQ(2.61)
LT_PREREQ([2.2.4])
AC_CONFIG_AUX_DIR(build-aux)
AM_INIT_AUTOMAKE([1.10 foreign])

m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])

LT_INIT([dlopen])
AC_CONFIG_MACRO_DIR([build-aux/m4])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([src/ot/main.cpp])

: ${CXXFLAGS=""}
: ${CFLAGS=""}

AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_CXX

PKG_PROG_PKG_CONFIG([0.25])

##### Dependencies, packages, libs ####
#
## Main deps ##

PKG_CHECK_MODULES([DEPS],[protobuf >= 2.4.1 openssl >= 1.0.0 chaiscript >= 3.1.0])

## boost_thread lib ##

AX_BOOST_BASE([1.25.0])
AX_BOOST_THREAD

AC_SUBST( DEPS_CFLAGS,	["$DEPS_CFLAGS $BOOST_CPPFLAGS"])
AC_SUBST( DEPS_LIBS,	["$DEPS_LIBS $BOOST_LDFLAGS $BOOST_THREAD_LIB"])

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
	[
	PKG_CHECK_MODULES([ZMQDEP],[libzmq >= 2.1.9])
	AC_LANG_PUSH([C++])
		AC_CHECK_HEADERS([zmq.hpp],
			[],
			[AC_MSG_ERROR([Header files for libzmq not found or incompatible.])],
			[])
	AC_LANG_POP
	AC_SUBST(DEPS_CFLAGS,	["$DEPS_CFLAGS $ZMQDEP_CFLAGS"])
	AC_SUBST(DEPS_LIBS,	["$DEPS_LIBS $ZMQDEP_LIBS"])
	])

## MsgPack ##

AC_CHECK_HEADERS(
	[msgpack.h],
	[],
	[AC_MSG_ERROR([No header files for libmsgpack found.])]
	)

AC_CHECK_LIB(msgpack, msgpack_unpack)


#### Configure Options ####

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

AM_CONDITIONAL(OT_SIGNAL_HANDLING, test x"$sighandler" = x"true")

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

AM_CONDITIONAL(WARNINGS, test x"$warnings" = x"true")

## (Option) Build In Release Mode ##

AC_ARG_ENABLE(
	release,
	AS_HELP_STRING(
		[--enable-release],
		[enable releasemode, default: no]),
	[case "${enableval}" in
		yes) release=true ;;
		no)  release=false ;;
		*)   AC_MSG_ERROR([bad value ${enableval} for --enable-release]) ;;
		esac],
	[release=false])

AM_CONDITIONAL(RELEASE, test x"$release" = x"true")

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

	AC_SUBST(JNI_CPPFLAGS, $JNI_CPPFLAGS)
fi

## (Option) Add SWIG PERL5 ##

AC_ARG_WITH(
	[perl5],
	[AS_HELP_STRING([--with-perl5], [build Perl5 SWIG wrapper])]
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

	AX_PYTHON_DEVEL
fi

## Keyring Options ##

AC_ARG_WITH(	[keyring],
		[AS_HELP_STRING([--with-keyring@<:@=ARG@:>@],
		[Choose a keyring ARG from: windows, mac, gnome, kwallet])],
		[case "${withval}" in
			windows) true ;;
			mac) true ;;
			gnome) true ;;
			kwallet) true ;;
			*) AC_MSG_ERROR([bad value ${withval} for --with-keyring]) ;;
			esac],
		[])

AM_CONDITIONAL(	[KEYRING_WINDOWS],	[test "$with_keyring" == windows])
AM_CONDITIONAL(	[KEYRING_MAC],		[test "$with_keyring" == mac])
AM_CONDITIONAL(	[KEYRING_GNOME],	[test "$with_keyring" == gnome])
AM_CONDITIONAL(	[KEYRING_KWALLET],	[test "$with_keyring" == kwallet])

AS_IF(	[test "$with_keyring" == windows],
	[
	AC_SUBST(DEPS_CFLAGS,	["$DEPS_CFLAGS"])
	AC_SUBST(DEPS_LIBS,	["$DEPS_LIBS"])
	])

## Extra WINDOWS flags might be needed here ##

AS_IF(	[test "$with_keyring" == mac],
	[
	AC_SUBST(DEPS_CFLAGS,	["$DEPS_CFLAGS"]) 
	AC_SUBST(DEPS_LIBS,	["$DEPS_LIBS"])
	])
## Extra MAC flags are needed here ##


AS_IF(	[test "$with_keyring" == gnome],
	[
	PKG_CHECK_MODULES([GKRDEP],[glib-2.0 >= 2.28.6 gnome-keyring-1])
	AC_SUBST(DEPS_CFLAGS,	["$DEPS_CFLAGS $GKRDEP_CFLAGS"])
	AC_SUBST(DEPS_LIBS,	["$DEPS_LIBS $GKRDEP_LIBS"])
	])

AS_IF(	[test "$with_keyring" == kwallet],
	[
	AC_SUBST(DEPS_CFLAGS,	["$DEPS_CFLAGS -I/usr/include/kde"])
	AC_SUBST(DEPS_LIBS,	["$DEPS_LIBS -L/usr/lib -lkwalletclient"])
	])

##### Options END #####

AC_SUBST(DEPS_CFLAGS)
AC_SUBST(DEPS_LIBS)

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
