AC_INIT([Open-Transactions], [0.77.0], [Fellow-Traveler], [Open-Transactions], [https://github.com/FellowTraveler/Open-Transactions])
AC_PREREQ(2.61)
LT_PREREQ([2.2.4])
AC_CONFIG_AUX_DIR(build-aux)
AM_INIT_AUTOMAKE([1.10 foreign])
m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])

LT_INIT([dlopen])
AC_CONFIG_MACRO_DIR([build-aux/m4])
AC_CONFIG_HEADERS([config.h])

PKG_PROG_PKG_CONFIG([0.25])
AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_CXX
AX_BOOST_BASE([1.25.0])
AX_BOOST_THREAD

AC_ARG_WITH([transport],
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
AS_IF([test "$with_transport" == zmq],
   [PKG_CHECK_MODULES([DEPS], [protobuf openssl >= 1.0.0
                               chaiscript >= 3.1.0 libzmq])],
   [PKG_CHECK_MODULES([DEPS], [protobuf openssl >= 1.0.0
                               chaiscript ])])

AC_CONFIG_SRCDIR([src/otlib])

AC_CHECK_HEADERS([msgpack.h], [],
                [AC_MSG_ERROR([No header files for libmsgpack found.])])
AC_CHECK_LIB(msgpack, msgpack_unpack)

AC_ARG_WITH([java],
         [AS_HELP_STRING([--with-java],
             [build Java JNI wrapper])], [])
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

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
