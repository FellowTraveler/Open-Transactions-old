lib_LTLIBRARIES = libirrxml.la

AM_CPPFLAGS		= 	$(AC_CXXFLAGS)
AM_CXXFLAGS		=	$(AC_CXXFLAGS)

irrxml_headers_dir	=	$(top_srcdir)/include/irrxml

irrxml_headers		=	$(irrxml_headers_dir)/CXMLReaderImpl.h		\
				$(irrxml_headers_dir)/fast_atof.h		\
				$(irrxml_headers_dir)/heapsort.h		\
				$(irrxml_headers_dir)/irrArray.h		\
				$(irrxml_headers_dir)/irrString.h		\
				$(irrxml_headers_dir)/irrTypes.h		\
				$(irrxml_headers_dir)/irrXML.h

irrxml_sources		=	irrXML.cpp

libirrxml_la_SOURCES	=	$(irrxml_sources) $(irrxml_headers)
libirrxml_la_CXXFLAGS	=	-I$(irrxml_headers_dir) $(DEPS_CFLAGS) -fpic
libirrxml_la_LDFLAGS	=	-static
