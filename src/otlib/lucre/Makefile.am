noinst_LTLIBRARIES = liblucre.la

## For now we build locally and statically link to this library as a convenience library

AM_CPPFLAGS		= 	$(AC_CXXFLAGS)
AM_CXXFLAGS		=	$(AC_CXXFLAGS)

lucre_headers_dir	=	$(top_srcdir)/include/lucre

lucre_headers		=	$(lucre_headers_dir)/bank.h

lucre_sources		=	bankimp.cpp

liblucre_la_SOURCES	=	$(lucre_sources) $(lucre_headers)
liblucre_la_CXXFLAGS	=	-I$(lucre_headers_dir) $(DEPS_CFLAGS) -fpic
liblucre_la_LDFLAGS	=	-static
