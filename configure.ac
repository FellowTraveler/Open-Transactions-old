AC_INIT([Open-Transactions], [0.80.0], [Fellow-Traveler], [Open-Transactions], [https://github.com/FellowTraveler/Open-Transactions])
AC_PREREQ(2.61)
LT_PREREQ([2.2.4])
AC_CONFIG_AUX_DIR(build-aux)
AM_INIT_AUTOMAKE([1.10 foreign])
m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])

LT_INIT([dlopen])
AC_CONFIG_MACRO_DIR([build-aux/m4])
AC_CONFIG_HEADERS([config.h])

: ${CXXFLAGS=""}
: ${CFLAGS=""}

PKG_PROG_PKG_CONFIG([0.25])
AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_CXX
AX_BOOST_BASE([1.25.0])
AX_BOOST_THREAD


## Transport ##

AC_ARG_WITH(
	[transport],
        [AS_HELP_STRING([--with-transport@<:@=zmq@:>@],
	[Choose a transport backend (available: zmq, testclient)])],
	[# using 'case' with empty bodies just to catch invalid values for now.
             case "${withval}" in
		zmq) true ;;
		testclient) true ;;
		*) AC_MSG_ERROR([bad value ${withval} for --with-transport]) ;;
		esac],
	[with_transport=zmq])

AM_CONDITIONAL([TRANSPORT_ZMQ], [test "$with_transport" == zmq])
AM_CONDITIONAL([TRANSPORT_TESTCLIENT], [test "$with_transport" == testclient])

AS_IF(	[test "$with_transport" == zmq],
	[PKG_CHECK_MODULES(
		[DEPS],
		[protobuf >= 2.4.1 openssl >= 1.0.0 chaiscript >= 3.1.0 libzmq])])

AC_CONFIG_SRCDIR([src/otlib])


##### MsgPack #####

AC_CHECK_HEADERS(
	[msgpack.h],
	[],
	[AC_MSG_ERROR([No header files for libmsgpack found.])])

AC_CHECK_LIB(msgpack, msgpack_unpack)


##### (Option) Signal Handler #####

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


##### (Option) Warnings #####

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


##### (Option) Build In Release Mode #####

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



##### (Option) Add SWIG JAvA #####

AC_ARG_WITH(
	[java],
	[AS_HELP_STRING([--with-java],
	[build Java SWIG wrapper])],
	[])

AM_CONDITIONAL([WANT_JAVA], [test "x$with_java" == "xyes"], [])

if (test "x$with_java" == "xyes"); then

	AX_PROG_JAVAC
	AX_JNI_INCLUDE_DIR

	for JNI_INCLUDE_DIR in $JNI_INCLUDE_DIRS
		do
			JNI_CPPFLAGS="$JNI_CPPFLAGS -I$JNI_INCLUDE_DIR"
    		done

	AC_SUBST(JNI_CPPFLAGS, $JNI_CPPFLAGS)
fi

##### (Option) Add SWIG PERL5 #####

AC_ARG_WITH(
	[perl5],
	[AS_HELP_STRING([--with-perl5],
	[build Perl5 SWIG wrapper])],
	[])

AM_CONDITIONAL([WANT_PERL5], [test "x$with_perl5" == "xyes"], [])


##### (Option) Add SWIG PHP #####

AC_ARG_WITH(
	[php],
	[AS_HELP_STRING([--with-php],
	[build PHP SWIG wrapper])],
	[])

AM_CONDITIONAL([WANT_PHP], [test "x$with_php" == "xyes"], [])

if (test "x$with_php" == "xyes"); then
	AX_PHP_DEVEL

fi


##### (Option) Add SWIG PYTHON #####

AC_ARG_WITH(
	[python],
	[AS_HELP_STRING([--with-python],
	[build Python SWIG wrapper])],
	[])

AM_CONDITIONAL([WANT_PYTHON], [test "x$with_python" == "xyes"], [])

if (test "x$with_python" == "xyes"); then
	AX_PYTHON_DEVEL

fi



AC_CONFIG_FILES([Makefile])
AC_OUTPUT