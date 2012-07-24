lib_LTLIBRARIES = libbigint.la

bigint_headers_dir =		$(top_srcdir)/include/bigint

bigint_headers =		BigInteger.h			\
				BigIntegerAlgorithms.h		\
				BigIntegerLibrary.h		\
				BigIntegerUtils.h		\
				BigUnsigned.h			\
				BigUnsignedInABase.h		\
				NumberlikeArray.h

bigint_sources =		BigInteger.cc			\
				BigIntegerAlgorithms.cc		\
				BigIntegerUtils.cc		\
				BigUnsigned.cc			\
				BigUnsignedInABase.cc


libbigint_la_SOURCES	=	$(bigint_sources) $(bigint_headers)
libbigint_la_CXXFLAGS	=	-I$(bigint_headers_dir) -fpic
libbigint_la_LDFLAGS	=	-static

