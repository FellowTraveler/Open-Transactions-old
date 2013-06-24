noinst_LTLIBRARIES = libirrxml.la

## For now we build locally and statically link to this library as a convenience library

AM_CPPFLAGS		= 	$(AC_CXXFLAGS)
AM_CXXFLAGS		=	$(AC_CXXFLAGS)


libirrxml_la_SOURCES	=	$(irrxml_sources) $(irrxml_headers)
libirrxml_la_CXXFLAGS	=	-I$(irrxml_headers_dir) $(DEPS_CFLAGS)
libirrxml_la_LDFLAGS	=	-static

irrxml_sources		=	irrXML.cpp

irrxml_headers_dir	=	$(top_srcdir)/include/irrxml

irrxml_headers		=	$(irrxml_headers_dir)/CXMLReaderImpl.h	\
				$(irrxml_headers_dir)/fast_atof.h		\
				$(irrxml_headers_dir)/heapsort.h		\
				$(irrxml_headers_dir)/irrArray.h		\
				$(irrxml_headers_dir)/irrString.h		\
				$(irrxml_headers_dir)/irrTypes.h		\
				$(irrxml_headers_dir)/irrXML.h


pkginclude_irrxmldir	=	$(pkgincludedir)/irrxml

pkginclude_irrxml_HEADERS	=	$(irrxml_headers)
