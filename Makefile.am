# -*- fill-column: 72 -*-
AUTOMAKE_OPTIONS =		subdir-objects
ACLOCAL_AMFLAGS =		-I build-aux/m4

SUBDIRS			=	src/otlib .


opentxs_include_dir =		$(top_srcdir)/include
opentxs_source_dir =		$(top_srcdir)/src

common_includes =		-I$(opentxs_include_dir)			\
				-I$(opentxs_include_dir)/otlib		\
				$(DEPS_CFLAGS)


## COMMON FLAGS ###

AM_CPPFLAGS = 			$(common_includes)			\
				-g3						\
				-ggdb						\
				-rdynamic					\
				-O0						\
				--param ssp-buffer-size=4

AM_LDFLAGS = 			$(DEPS_LDFLAGS)

## WARNING FLAGS ###

if WARNINGS
AM_CPPFLAGS +=			-Waddress				\
				-Woverloaded-virtual				\
				-Wshadow					\
				-Wconversion
endif

## RELEASE FLAGS ###

if RELEASE
AM_CPPFLAGS +=			-Wall					\
				-D_FORTIFY_SOURCE=2				\
				-fstack-protector-all				\
				-fstack-check					\
				-Wstack-protector
endif

####################################################################

####	Simple Ini

simpleini_headers_dir	=	$(opentxs_include_dir)/simpleini

simpleini_headers	=	include/simpleini/ConvertUTF.h			\
				include/simpleini/SimpleIni.h

####	OT

ot_sources_dir = 		$(opentxs_source_dir)/ot

ot_sources =			src/ot/main.cpp


####	OT API

otapi_headers_dir =		$(opentxs_include_dir)/otapi

otapi_headers =			include/otapi/main.h				\
				include/otapi/OpenTransactions.h		\
				include/otapi/OTAPI.h				\
				include/otapi/OTAPI_funcdef.h			\
				include/otapi/OTAPI_Wrapper.h			\
				include/otapi/OTClient.h			\
				include/otapi/OTServerConnection.h

otapi_sources_dir = 		$(opentxs_source_dir)/otapi

otapi_sources =			src/otapi/OpenTransactions.cpp			\
				src/otapi/OTAPI.cpp				\
				src/otapi/OTAPI_Wrapper.cpp			\
				src/otapi/OTClient.cpp				\
				src/otapi/OTServerConnection.cpp

####	OT Server

otserver_headers_dir	=	$(opentxs_include_dir)/otserver

otserver_headers	= 	include/otserver/main.h				\
				include/otserver/OTClientConnection.h		\
				include/otserver/OTServer.h

otserver_sources_dir	=	$(opentxs_source_dir)/otserver

otserver_sources	=	src/otserver/OTClientConnection.cpp		\
				src/otserver/OTServer.cpp

####	OT Create Mint

createmint_sources_dir	=	$(opentxs_source_dir)/createmint

createmint_sources	=	src/createmint/main.cpp


##########################
## Open Transactions Lib #
##########################

lib_LTLIBRARIES		=	libotapi.la


####	 LIB OT API

libotapi_la_SOURCES	=	$(otapi_sources) $(otapi_headers)	\
				$(simpleini_headers)
libotapi_la_CPPFLAGS	=	-I$(otapi_headers_dir) $(AM_CPPFLAGS) -fpic
libotapi_la_LIBADD	=	src/otlib/libot.la $(DEPS_LIBS)
libotapi_la_DEPENDENCIES=	src/otlib/libot.la
libotapi_la_LDFLAGS	=	--no-undefined


############################
#### OT Optional Libraries #
############################

#### OT API JAVA

if WANT_JAVA
lib_LTLIBRARIES			+=	libotapi-java.la
endif

libotapi_java_la_SOURCES	=	swig/otapi/OTAPI-java.cxx	\
					swig/otapi/OTAPI-java.h
libotapi_java_la_CPPFLAGS	=	$(AM_CPPFLAGS) $(JNI_CPPFLAGS)	\
					-I$(otapi_headers_dir)
libotapi_java_la_LIBADD 	=	libotapi.la src/otlib/libot.la $(DEPS_LIBS)
libotapi_java_la_DEPENDENCIES 	=	libotapi.la src/otlib/libot.la
libotapi_java_la_LDFLAGS 	=	--no-undefined

if TRANSPORT_ZMQ
libotapi_java_la_CPPFLAGS 	+=	-DOT_ZMQ_MODE
endif



#### OT API PERL5

if WANT_PERL5
lib_LTLIBRARIES 		+=	libotapi-perl5.la
endif

libotapi_perl5_la_SOURCES	=	swig/otapi/OTAPI-perl5.cxx
libotapi_perl5_la_CPPFLAGS	=	$(AM_CPPFLAGS)			\
					$(PERL_EXT_CPPFLAGS)		\
					-I$(otapi_headers_dir)		\
					-I$(PERL_EXT_INC)
libotapi_perl5_la_LIBADD	=	libotapi.la libot.la $(DEPS_LIBS)
libotapi_perl5_la_DEPENDENCIES	=	libotapi.la libot.la
libotapi_perl5_la_LDFLAGS	=	$(PERL_EXT_LDFLAGS) --no-undefined

if TRANSPORT_ZMQ
libotapi_perl5_la_CPPFLAGS	+=	-DOT_ZMQ_MODE
endif

#### OT API PHP

if WANT_PHP
lib_LTLIBRARIES			+=	libotapi-php.la
endif

libotapi_php_la_SOURCES		=	swig/otapi/OTAPI-php.cpp	\
					swig/otapi/OTAPI-php.h
libotapi_php_la_CPPFLAGS	=	$(AM_CPPFLAGS)			\
					-I$(otapi_headers_dir)		\
					-I$(top_srcdir)/swig/glue/php	\
					$(PHP_INCLUDES)
libotapi_php_la_LIBADD		=	libotapi.la libot.la $(DEPS_LIBS)
libotapi_php_la_DEPENDENCIES	=	libotapi.la libot.la
libotapi_php_la_LDFLAGS		=	$(PHP_LDFLAGS) --no-undefined

if TRANSPORT_ZMQ
libotapi_php_la_CPPFLAGS	+=	-DOT_ZMQ_MODE
endif

#### OT API PYTHON

if WANT_PYTHON
lib_LTLIBRARIES			+=	_otapi.la
endif

_otapi_la_SOURCES		=	swig/otapi/OTAPI-python.cxx	\
					swig/otapi/OTAPI-python.h

_otapi_la_CPPFLAGS		= 	$(AM_CPPFLAGS)  -fpic		\
					$(PYTHON_CPPFLAGS)              \
					-I$(otapi_headers_dir)          \
					$(PYTHON_EXTRA_LIBS)
_otapi_la_LIBADD		=	libotapi.la libot.la $(DEPS_LIBS)
_otapi_la_DEPENDENCIES		= 	libotapi.la libot.la
_otapi_la_LDFLAGS		=	--no-undefined                  \
					-module -avoid-version          \
					$(PYTHON_LDFLAGS)               \
					$(PYTHON_EXTRA_LDFLAGS)

if TRANSPORT_ZMQ
_otapi_la_CPPFLAGS		+=	-DOT_ZMQ_MODE
endif


##########################
## Open Transactions Bin #
##########################

bin_PROGRAMS		=	ot				\
				otserver				\
				createmint

####	OT

ot_SOURCES		=	$(ot_sources) $(otapi_headers)
ot_CPPFLAGS		=	-I$(otapi_headers_dir) $(AM_CPPFLAGS) -fpic
ot_LDADD		=	libotapi.la src/otlib/libot.la $(DEPS_LIBS)
ot_DEPENDENCIES	=	libotapi.la src/otlib/libot.la



####	OT Server

otserver_SOURCES	=	$(otserver_sources) $(otserver_headers)
otserver_CPPFLAGS	=	-I$(otserver_headers_dir) $(AM_CPPFLAGS)
otserver_LDADD		=	src/otlib/libot.la $(DEPS_LIBS)
otserver_DEPENDENCIES	=	src/otlib/libot.la


####	Createmint  (includes files from OT Server)

createmint_SOURCES	=	$(createmint_sources)			\
				$(otserver_sources) $(otserver_headers)
createmint_CPPFLAGS	=	-I$(otserver_headers_dir) $(AM_CPPFLAGS)
createmint_LDADD	=	src/otlib/libot.la $(DEPS_LIBS)
createmint_DEPENDENCIES =	src/otlib/libot.la


####################################
## Open Transactions Build Options #
####################################

#### Transport ZMQ

if TRANSPORT_ZMQ

libotapi_la_CPPFLAGS		+=	-DOT_ZMQ_MODE

ot_CPPFLAGS			+=	-DOT_ZMQ_MODE

otserver_SOURCES		+=	src/otserver/xmlrpcxx_server.cpp
otserver_CPPFLAGS		+=	-DOT_ZMQ_MODE

createmint_CPPFLAGS		+=	-DOT_ZMQ_MODE
endif


#######################################
## Open-Transactions Install Extras  ##
#######################################


#### OpenTXS script CLI utility

dist_bin_SCRIPTS		=	scripts/opentxs

#### OT script HEADERS

opentxslibdir			=	$(pkglibdir)

dist_opentxslib_SCRIPTS		=	scripts/ot/ot_commands.ot	\
					scripts/ot/otapi.ot		\
					scripts/ot/ot_made_easy.ot	\
					scripts/ot/ot_utility.ot

#### OT docs, licences, info, etc.

opentxsdocdir			=	$(docdir)

dist_opentxsdoc_DATA		=	docs/GETTING-STARTED.txt	\
					docs/INSTALL-Android.txt	\
					docs/INSTALL-Fedora.txt		\
					docs/INSTALL-Debian_Ubuntu.txt	\
					docs/INSTALL-OSX-Homebrew.txt	\
					docs/INSTALL-Windows.txt	\
					docs/SSL-NOTES.txt		\
					docs/WIPE-USERS-ACCOUNTS.txt	\
					docs/LICENSE-AND-CREDITS.txt	\
					PUBKEY-FellowTraveler.asc	\
					README.md 			\
					VERSION

nobase_dist_opentxsdoc_DATA	=	sample-data/ot-sample-data-clean/ot_init.cfg				\
					sample-data/ot-sample-data-clean/client.cfg				\
					sample-data/ot-sample-data-clean/command-line-ot.opt			\
					sample-data/ot-sample-data-clean/CLIENT-COMMANDS.txt			\
					sample-data/ot-sample-data-clean/client_data/LICENSE-AND-CREDITS.txt	\
					sample-data/ot-sample-data-clean/client_data/wallet.xml			\
					sample-data/ot-sample-data-clean/server.cfg				\
					sample-data/ot-sample-data-clean/server_data/notaryServer.xml

pkgconfigdir			=	$(libdir)/pkgconfig
pkgconfig_DATA			=	src/opentxs.pc
