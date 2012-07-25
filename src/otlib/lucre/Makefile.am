lib_LTLIBRARIES = liblucre.la

AM_CPPFLAGS		= 	$(AC_CXXFLAGS)
AM_CXXFLAGS		=	$(AC_CXXFLAGS)

lucre_headers_dir	=	$(top_srcdir)/include/lucre

lucre_headers		=	$(lucre_headers_dir)/bank.h

lucre_sources		=	bankdemo.cpp			\
				bankimp.cpp			\
				bank-new.cpp			\
				bank-sign.cpp			\
				bank-verify.cpp			\
				coin-request.cpp		\
				coin-unblind.cpp

liblucre_la_SOURCES	=	$(lucre_sources) $(lucre_headers)
liblucre_la_CXXFLAGS	=	-I$(lucre_headers_dir) $(DEPS_CFLAGS) -fpic
liblucre_la_LDFLAGS	=	-static
