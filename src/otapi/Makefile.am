##############################
## Open Transactions API Lib #
##############################

##SUBDIRS = java python perl5 php

lib_LTLIBRARIES = libotapi.la

## COMMON FLAGS ###

AM_CXXFLAGS = 		$(DEPS_CFLAGS)			\
				-g3				\
				-ggdb				\
				-rdynamic			\
				-O0				\
				--param ssp-buffer-size=4

AM_LDFLAGS = 			$(DEPS_LDFLAGS)

otlib_headers_dir =		$(top_srcdir)/include/otlib

####	Simple Ini

simpleini_headers_dir	=	$(top_srcdir)/include/

simpleini_headers	=	ConvertUTF.h			\
				SimpleIni.h
####  OTAPI

otapi_headers_dir =		$(top_srcdir)/include/otapi

otapi_headers =			main.h				\
				OpenTransactions.h		\
				OTAPI.h				\
				OTAPI_funcdef.h			\
				OTAPI_Wrapper.h			\
				OTClient.h			\
				OTServerConnection.h

otapi_sources_dir = 		$(top_srcdir)/src/otapi

otapi_sources =			OpenTransactions.cpp		\
				OTAPI.cpp			\
				OTAPI_Wrapper.cpp		\
				OTClient.cpp			\
				OTServerConnection.cpp

########################

libotapi_la_SOURCES		=	$(otapi_sources) $(otapi_headers)	\
					$(simpleini_headers)
libotapi_la_CXXFLAGS		=	-I$(top_srcdir)/include/		\
					-I$(otapi_headers_dir)		\
					-I$(otlib_headers_dir)		\
					$(AM_CXXFLAGS) -fpic

libotapi_la_LIBADD		=	../otlib/libot.la $(DEPS_LIBS)
libotapi_la_DEPENDENCIES	=	../otlib/libot.la
libotapi_la_LDFLAGS		=	--no-undefined

if TRANSPORT_ZMQ
libotapi_la_CXXFLAGS		+=	-DOT_ZMQ_MODE
endif


############################
#### OT Optional Libraries #
############################


#### OT API JAVA

if WANT_JAVA
lib_LTLIBRARIES		+=	libotapi-java.la
endif

libotapi_java_la_SOURCES	=	$(top_srcdir)/swig/otapi/OTAPI-java.cxx	\
					$(top_srcdir)/swig/otapi/OTAPI-java.h
libotapi_java_la_CXXFLAGS	=	-I$(top_srcdir)/include/			\
					-I$(otapi_headers_dir)			\
					$(AM_CXXFLAGS) $(JNI_CPPFLAGS)
					
libotapi_java_la_LIBADD 	=	libotapi.la ../otlib/libot.la $(DEPS_LIBS)
libotapi_java_la_DEPENDENCIES	=	libotapi.la ../otlib/libot.la
libotapi_java_la_LDFLAGS 	=	--no-undefined

if TRANSPORT_ZMQ
libotapi_java_la_CXXFLAGS 	+=	-DOT_ZMQ_MODE
endif



#### OT API PERL5

if WANT_PERL5
lib_LTLIBRARIES 	+=	libotapi-perl5.la
endif

libotapi_perl5_la_SOURCES	=	$(top_srcdir)/swig/otapi/OTAPI-perl5.cxx
libotapi_perl5_la_CXXFLAGS	=	-I$(otapi_headers_dir)	\
					$(AM_CXXFLAGS)		\
					$(PERL_EXT_CPPFLAGS)		\
					-I$(PERL_EXT_INC)
libotapi_perl5_la_LIBADD	=	libotapi.la ../otlib/libot.la $(DEPS_LIBS)
libotapi_perl5_la_DEPENDENCIES =	libotapi.la ../otlib/libot.la
libotapi_perl5_la_LDFLAGS	=	$(PERL_EXT_LDFLAGS) --no-undefined

if TRANSPORT_ZMQ
libotapi_perl5_la_CXXFLAGS	+=	-DOT_ZMQ_MODE
endif

#### OT API PHP

if WANT_PHP
lib_LTLIBRARIES		+=	libotapi-php.la
endif

libotapi_php_la_SOURCES	=	$(top_srcdir)/swig/otapi/OTAPI-php.cpp\
					$(top_srcdir)/swig/otapi/OTAPI-php.h
libotapi_php_la_CXXFLAGS	=	-I$(otapi_headers_dir)		\
					$(AM_CXXFLAGS)			\
					-I$(top_srcdir)/swig/glue/php		\
					$(PHP_INCLUDES)
libotapi_php_la_LIBADD		=	libotapi.la ../otlib/libot.la $(DEPS_LIBS)
libotapi_php_la_DEPENDENCIES	=	libotapi.la ../otlib/libot.la
libotapi_php_la_LDFLAGS	=	$(PHP_LDFLAGS) --no-undefined

if TRANSPORT_ZMQ
libotapi_php_la_CXXFLAGS	+=	-DOT_ZMQ_MODE
endif

#### OT API PYTHON

if WANT_PYTHON
lib_LTLIBRARIES		+=	_otapi.la
endif

_otapi_la_SOURCES		=	$(top_srcdir)/swig/otapi/OTAPI-python.cxx	\
					$(top_srcdir)/swig/otapi/OTAPI-python.h

_otapi_la_CXXFLAGS		= 	-I$(otapi_headers_dir)			\
					$(AM_CXXFLAGS)  -fpic				\
					$(PYTHON_CPPFLAGS)				\
					$(PYTHON_EXTRA_LIBS)
_otapi_la_LIBADD		=	libotapi.la ../otlib/libot.la $(DEPS_LIBS)
_otapi_la_DEPENDENCIES	= 	libotapi.la ../otlib/libot.la
_otapi_la_LDFLAGS		=	--no-undefined                  \
					-module -avoid-version          \
					$(PYTHON_LDFLAGS)               \
					$(PYTHON_EXTRA_LDFLAGS)

if TRANSPORT_ZMQ
_otapi_la_CXXFLAGS		+=	-DOT_ZMQ_MODE
endif


