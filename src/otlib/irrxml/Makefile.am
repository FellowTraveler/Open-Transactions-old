lib_LTLIBRARIES = libirrxml.la

irrxml_headers_dir =		$(top_srcdir)/include/irrxml

irrxml_headers =		CXMLReaderImpl.h		\
				fast_atof.h			\
				heapsort.h			\
				irrArray.h			\
				irrString.h			\
				irrTypes.h			\
				irrXML.h

irrxml_sources =		irrXML.cpp

libirrxml_la_SOURCES	=	$(irrxml_sources) $(irrxml_headers)
libirrxml_la_CXXFLAGS	=	-I$(irrxml_headers_dir) -fpic
libirrxml_la_LDFLAGS	=	-static
