lib_LTLIBRARIES = libbigint.la

AM_CPPFLAGS		= 	$(AC_CXXFLAGS)
AM_CXXFLAGS		=	$(AC_CXXFLAGS)

bigint_headers_dir	=	$(top_srcdir)/include/bigint

bigint_headers		=	$(bigint_headers_dir)/BigInteger.h		\
				$(bigint_headers_dir)/BigIntegerAlgorithms.h	\
				$(bigint_headers_dir)/BigIntegerLibrary.h	\
				$(bigint_headers_dir)/BigIntegerUtils.h		\
				$(bigint_headers_dir)/BigUnsigned.h		\
				$(bigint_headers_dir)/BigUnsignedInABase.h	\
				$(bigint_headers_dir)/NumberlikeArray.h

bigint_sources		=	BigInteger.cc			\
				BigIntegerAlgorithms.cc		\
				BigIntegerUtils.cc		\
				BigUnsigned.cc			\
				BigUnsignedInABase.cc


libbigint_la_SOURCES	=	$(bigint_sources) $(bigint_headers)
libbigint_la_CXXFLAGS	=	-I$(bigint_headers_dir) $(DEPS_CFLAGS) -fpic
libbigint_la_LDFLAGS	=	-static

