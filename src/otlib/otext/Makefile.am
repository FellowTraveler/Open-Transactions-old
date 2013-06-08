noinst_LTLIBRARIES = libotext.la

## For now we build locally and statically link to this library as a convenience library

AM_CPPFLAGS		= 	$(AC_CXXFLAGS)
AM_CXXFLAGS		=	$(AC_CXXFLAGS)

otext_headers_dir	=	$(top_srcdir)/include/otlib

otext_sources     =		easyzlib.c			\
				mkcert.c			\
				anyoption.cpp			\
				tinythread.cpp			\
				Timer.cpp

otext_headers		=	$(otext_headers_dir)/easyzlib.h		\
				$(otext_headers_dir)/anyoption.h	\
				$(otext_headers_dir)/tinythread.h	\
				$(otext_headers_dir)/Timer.h

libotext_la_SOURCES	=	$(otext_sources) $(otext_headers)
libotext_la_CPPFLAGS	=	-I$(otext_headers_dir) $(DEPS_CFLAGS)
libotext_la_LDFLAGS	=	-static --no-undefined


pkginclude_HEADERS	=	$(otext_headers)
