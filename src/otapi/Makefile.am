##############################
## Open Transactions API Lib #
##############################

##SUBDIRS = java python perl5 php

lib_LTLIBRARIES = libotapi.la

### Common variables, flags ###

opentxs_include_dir	=	$(top_srcdir)/include
opentxs_swig_dir	=	$(top_srcdir)/swig

common_includes		=	-I$(opentxs_include_dir)		\
				-I$(opentxs_include_dir)/otlib		\
				-I$(opentxs_include_dir)/otapi		\
				$(DEPS_CFLAGS)

AM_CXXFLAGS		= 	$(common_includes) $(AC_CXXFLAGS)

########################

libotapi_la_SOURCES		=	$(otapi_sources) $(otapi_headers)	\
					$(simpleini_headers)

libotapi_la_CXXFLAGS		=	$(AM_CXXFLAGS) -fpic

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
lib_LTLIBRARIES			+=	libotapi-java.la
endif

libotapi_java_la_SOURCES	=	$(opentxs_swig_dir)/otapi/OTAPI-java.cxx	\
					$(opentxs_swig_dir)/otapi/OTAPI-java.h

libotapi_java_la_CXXFLAGS	=	$(AM_CXXFLAGS) $(JNI_CPPFLAGS)
					
libotapi_java_la_LIBADD 	=	libotapi.la ../otlib/libot.la $(DEPS_LIBS)
libotapi_java_la_DEPENDENCIES	=	libotapi.la ../otlib/libot.la
libotapi_java_la_LDFLAGS 	=	--no-undefined

if TRANSPORT_ZMQ
libotapi_java_la_CXXFLAGS 	+=	-DOT_ZMQ_MODE
endif



#### OT API PERL5

if WANT_PERL5
lib_LTLIBRARIES 		+=	libotapi-perl5.la
endif

libotapi_perl5_la_SOURCES	=	$(opentxs_swig_dir)/otapi/OTAPI-perl5.cxx
libotapi_perl5_la_CXXFLAGS	=	$(AM_CXXFLAGS)			\
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
lib_LTLIBRARIES			+=	libotapi-php.la
endif

libotapi_php_la_SOURCES		=	$(opentxs_swig_dir)/otapi/OTAPI-php.cpp	\
					$(opentxs_swig_dir)/otapi/OTAPI-php.h
libotapi_php_la_CXXFLAGS	=	$(AM_CXXFLAGS)				\
					-I$(opentxs_swig_dir)/glue/php		\
					$(PHP_INCLUDES)
libotapi_php_la_LIBADD		=	libotapi.la ../otlib/libot.la $(DEPS_LIBS)
libotapi_php_la_DEPENDENCIES	=	libotapi.la ../otlib/libot.la
libotapi_php_la_LDFLAGS		=	$(PHP_LDFLAGS) --no-undefined

if TRANSPORT_ZMQ
libotapi_php_la_CXXFLAGS	+=	-DOT_ZMQ_MODE
endif

#### OT API PYTHON

if WANT_PYTHON
lib_LTLIBRARIES			+=	_otapi.la
endif

_otapi_la_SOURCES		=	$(opentxs_swig_dir)/otapi/OTAPI-python.cxx	\
					$(opentxs_swig_dir)/otapi/OTAPI-python.h

_otapi_la_CXXFLAGS		= 	$(AM_CXXFLAGS)  -fpic				\
					$(PYTHON_CPPFLAGS)				\
					$(PYTHON_EXTRA_LIBS)
_otapi_la_LIBADD		=	libotapi.la ../otlib/libot.la $(DEPS_LIBS)
_otapi_la_DEPENDENCIES		= 	libotapi.la ../otlib/libot.la
_otapi_la_LDFLAGS		=	--no-undefined                  \
					-module -avoid-version          \
					$(PYTHON_LDFLAGS)               \
					$(PYTHON_EXTRA_LDFLAGS)

if TRANSPORT_ZMQ
_otapi_la_CXXFLAGS		+=	-DOT_ZMQ_MODE
endif

########################

####	Simple Ini

simpleini_headers_dir	=	$(opentxs_include_dir)/simpleini

simpleini_headers	=	$(simpleini_headers_dir)/ConvertUTF.h		\
				$(simpleini_headers_dir)/SimpleIni.h
####  OTAPI

otapi_headers_dir	=	$(opentxs_include_dir)/otapi

otapi_headers		=	$(otapi_headers_dir)/main.h			\
				$(otapi_headers_dir)/OpenTransactions.h		\
				$(otapi_headers_dir)/OTAPI.h			\
				$(otapi_headers_dir)/OTAPI_funcdef.h		\
				$(otapi_headers_dir)/OTAPI_Wrapper.h		\
				$(otapi_headers_dir)/OTClient.h			\
				$(otapi_headers_dir)/OTServerConnection.h

otapi_sources_dir	= 	$(top_srcdir)/src/otapi

otapi_sources		=	OpenTransactions.cpp		\
				OTAPI.cpp			\
				OTAPI_Wrapper.cpp		\
				OTClient.cpp			\
				OTServerConnection.cpp

