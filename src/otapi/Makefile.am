###############################
## Open Transactions API Libs #
###############################

##SUBDIRS = java python perl5 php d ruby lisp ... coming soon?

lib_LTLIBRARIES = libotapi.la

### Common variables, flags ###

opentxs_include_dir	=	$(top_srcdir)/include
opentxs_swig_dir	=	$(top_srcdir)/swig

otlib_build_dir		=	$(top_builddir)/src/otlib

common_includes		=	$(AM_CXXFLAGS)          \
                -I$(opentxs_include_dir)		\
				-I$(opentxs_include_dir)/otlib	\
				-I$(opentxs_include_dir)/otapi



########################

libotapi_la_SOURCES		=	$(otapi_sources) $(otapi_headers)	\
                            $(simpleini_headers)

libotapi_la_CXXFLAGS		=	$(common_includes)

libotapi_la_LIBADD		=	$(otlib_build_dir)/libot.la
libotapi_la_DEPENDENCIES	=	$(otlib_build_dir)/libot.la

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

libotapi_java_la_CXXFLAGS	=	$(common_includes) $(JNI_CPPFLAGS)

libotapi_java_la_LIBADD 	=	libotapi.la $(otlib_build_dir)/libot.la
libotapi_java_la_DEPENDENCIES	=	libotapi.la $(otlib_build_dir)/libot.la
libotapi_java_la_LDFLAGS 	=	--no-undefined

if TRANSPORT_ZMQ
libotapi_java_la_CXXFLAGS 	+=	-DOT_ZMQ_MODE
endif

#### OT API PERL5

if WANT_PERL5
lib_LTLIBRARIES 		+=	libotapi-perl5.la
endif

libotapi_perl5_la_SOURCES	=	$(opentxs_swig_dir)/otapi/OTAPI-perl5.cxx
libotapi_perl5_la_CXXFLAGS	=	$(common_includes)			\
					$(PERL_EXT_CPPFLAGS)			\
					-I$(PERL_EXT_INC)
libotapi_perl5_la_LIBADD	=	libotapi.la $(otlib_build_dir)/libot.la
libotapi_perl5_la_DEPENDENCIES =	libotapi.la $(otlib_build_dir)/libot.la
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
libotapi_php_la_CXXFLAGS	=	$(common_includes)			\
					-I$(opentxs_swig_dir)/glue/php		\
					$(PHP_INCLUDES)
libotapi_php_la_LIBADD		=	libotapi.la $(otlib_build_dir)/libot.la
libotapi_php_la_DEPENDENCIES	=	libotapi.la $(otlib_build_dir)/libot.la
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

_otapi_la_CXXFLAGS		= 	$(common_includes)				\
					$(PYTHON_CPPFLAGS)				\
					$(PYTHON_EXTRA_LIBS)
_otapi_la_LIBADD		=	libotapi.la $(otlib_build_dir)/libot.la
_otapi_la_DEPENDENCIES		= 	libotapi.la $(otlib_build_dir)/libot.la
_otapi_la_LDFLAGS		=	--no-undefined                  \
					-module -avoid-version          \
					$(PYTHON_LDFLAGS)               \
					$(PYTHON_EXTRA_LDFLAGS)

if TRANSPORT_ZMQ
_otapi_la_CXXFLAGS		+=	-DOT_ZMQ_MODE
endif

#### OT API RUBY

if WANT_RUBY
lib_LTLIBRARIES			+=	libotapi-ruby.la
endif

libotapi_ruby_la_SOURCES	=	$(opentxs_swig_dir)/otapi/OTAPI-ruby.cxx	\
					$(opentxs_swig_dir)/otapi/OTAPI-ruby.h
libotapi_ruby_la_CXXFLAGS	=	$(common_includes)				\
					$(RUBY_CPPFLAGS)				\
					$(RUBY_EXTRA_LIBS)
libotapi_ruby_la_LIBADD		=	libotapi.la $(otlib_build_dir)/libot.la
libotapi_ruby_la_DEPENDENCIES	=	libotapi.la $(otlib_build_dir)/libot.la
libotapi_ruby_la_LDFLAGS	=	$(RUBY_LDFLAGS) --no-undefined

if TRANSPORT_ZMQ
libotapi_ruby_la_CXXFLAGS	+=	-DOT_ZMQ_MODE
endif

#### OT API TCL

if WANT_TCL
lib_LTLIBRARIES			+=	libotapi-tcl.la
endif

libotapi_tcl_la_SOURCES		=	$(opentxs_swig_dir)/otapi/OTAPI-tcl.cxx
libotapi_tcl_la_CXXFLAGS	=	$(common_includes)
libotapi_tcl_la_LIBADD		=	libotapi.la $(otlib_build_dir)/libot.la
libotapi_tcl_la_DEPENDENCIES	=	libotapi.la $(otlib_build_dir)/libot.la
libotapi_tcl_la_LDFLAGS		=	--no-undefined

if TRANSPORT_ZMQ
libotapi_tcl_la_CXXFLAGS	+=	-DOT_ZMQ_MODE
endif

#### OT API CSHARP

if WANT_CSHARP
lib_LTLIBRARIES                 +=      libotapi-csharp.la
endif

libotapi_csharp_la_SOURCES      =       $(opentxs_swig_dir)/otapi/OTAPI-csharp.cxx      \
                                        $(opentxs_swig_dir)/otapi/OTAPI-csharp.h
libotapi_csharp_la_CXXFLAGS     =       $(common_includes)
libotapi_csharp_la_LIBADD       =       libotapi.la $(otlib_build_dir)/libot.la
libotapi_csharp_la_DEPENDENCIES =       libotapi.la $(otlib_build_dir)/libot.la
libotapi_csharp_la_LDFLAGS      =       --no-undefined

if TRANSPORT_ZMQ
libotapi_csharp_la_CXXFLAGS     +=      -DOT_ZMQ_MODE
endif

#### OT API D

if WANT_D
lib_LTLIBRARIES                 +=      libotapi-d.la
endif

libotapi_d_la_SOURCES		=	$(opentxs_swig_dir)/otapi/OTAPI-d.cxx		\
					$(opentxs_swig_dir)/otapi/OTAPI-d.h
libotapi_d_la_CXXFLAGS		=	$(common_includes)
libotapi_d_la_LIBADD		=	libotapi.la $(otlib_build_dir)/libot.la
libotapi_d_la_DEPENDENCIES	=	libotapi.la $(otlib_build_dir)/libot.la
libotapi_d_la_LDFLAGS		=	--no-undefined

if TRANSPORT_ZMQ
libotapi_d_la_CXXFLAGS		+=	-DOT_ZMQ_MODE
endif

#### OT API GO

if WANT_GO
lib_LTLIBRARIES		+=	libotapi-go.la
endif

libotapi_go_la_SOURCES		=	$(opentxs_swig_dir)/otapi/OTAPI-go.cxx
	\				$(opentxs_swig_dir)/otapi/OTAPI-go.h
libotapi_go_la_CXXFLAGS		=	$(common_includes)
libotapi_go_la_LIBADD		=	libotapi.la $(otlib_build_dir)/libot.la
libotapi_go_la_DEPENDENCIES	=	libotapi.la $(otlib_build_dir)/libot.la
libotapi_go_la_LDFLAGS		=	--no-undefined

if TRANSPORT_ZMQ
libotapi_go_la_CXXFLAGS		+=	-DOT_ZMQ_MODE
endif

########################

####	Simple Ini

simpleini_headers_dir	=	$(opentxs_include_dir)/simpleini

simpleini_headers	=	$(simpleini_headers_dir)/ConvertUTF.h		\
                        $(simpleini_headers_dir)/SimpleIni.h

simpleini_sources_dir	= 	$(opentxs_source_dir)/simpleini

simpleini_sources	=	$(simpleini_sources_dir)/ConvertUTF.cpp		\
                        $(simpleini_sources_dir)/snippets.cpp

####  OTAPI

otapi_sources_dir	= 	$(top_srcdir)/src/otapi

otapi_sources		=	OpenTransactions.cpp		\
				OTAPI.cpp           		\
				OT_ME.cpp           		\
				OTAPI_Basic.cpp			\
				OTMadeEasy.cpp			\
				OTClient.cpp			\
				OTServerConnection.cpp


otapi_headers_dir	=	$(opentxs_include_dir)/otapi

otapi_headers		=	$(otapi_headers_dir)/main.h		\
				$(otapi_headers_dir)/OTClient.h		\
				$(otapi_headers_dir)/OTServerConnection.h\
				$(otapi_headers_ext)

otapi_headers_ext	=	$(otapi_headers_dir)/OpenTransactions.h	\
				$(otapi_headers_dir)/OTAPI.h		\
				$(otapi_headers_dir)/OTAPI_Basic.h	\
				$(otapi_headers_dir)/OTMadeEasy.h	\
				$(otapi_headers_dir)/OT_ME.h

pkginclude_HEADERS	=	$(otapi_headers_ext)
