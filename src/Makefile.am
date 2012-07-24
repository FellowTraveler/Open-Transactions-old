opentxs_include_dir =		$(top_srcdir)/include
opentxs_source_dir =		$(top_srcdir)/src

common_includes =		-I$(opentxs_include_dir)			\
				$(DEPS_CFLAGS)

## COMMON FLAGS ###

AM_CXXFLAGS = 		$(common_includes)				\
				-g3						\
				-ggdb						\
				-rdynamic					\
				-O0						\
				--param ssp-buffer-size=4

AM_LDFLAGS = 			$(DEPS_LDFLAGS)

## WARNING FLAGS ###

if WARNINGS
AM_CXXFLAGS +=			-Waddress				\
				-Woverloaded-virtual				\
				-Wshadow					\
				-Wconversion
endif

## RELEASE FLAGS ###

if RELEASE
AM_CXXFLAGS +=			-Wall					\
				-D_FORTIFY_SOURCE=2				\
				-fstack-protector-all				\
				-fstack-check					\
				-Wstack-protector
endif

############################
##  Libraries build call  ##

SUBDIRS = otlib otapi


####	OT

ot_sources_dir = 		$(opentxs_source_dir)/ot
ot_sources =			ot/main.cpp

otapi_headers_dir =		$(opentxs_include_dir)/otapi
otapi_headers =			main.h				\
				OpenTransactions.h		\
				OTAPI.h				\
				OTAPI_funcdef.h			\
				OTAPI_Wrapper.h			\
				OTClient.h			\
				OTServerConnection.h

####	OT Server

otserver_headers_dir	=	$(opentxs_include_dir)/otserver

otserver_headers	= 	main.h				\
				OTClientConnection.h		\
				OTServer.h

otserver_sources_dir	=	$(opentxs_source_dir)/otserver

otserver_sources	=	otserver/OTClientConnection.cpp		\
				otserver/OTServer.cpp

####	OT Create Mint

createmint_sources_dir	=	$(opentxs_source_dir)/createmint

createmint_sources	=	createmint/main.cpp


##########################
## Open Transactions Bin #
##########################

bin_PROGRAMS	=	ot			\
				otserver		\
				createmint	

####	OT

ot_SOURCES		=	$(ot_sources) $(otapi_headers)
ot_CXXFLAGS		=	-I$(otapi_headers_dir) $(AM_CXXFLAGS) -fpic
ot_LDADD		=	otapi/libotapi.la otlib/libot.la $(DEPS_LIBS)
ot_DEPENDENCIES	=	otapi/libotapi.la otlib/libot.la



####	OT Server

otserver_SOURCES	=	$(otserver_sources) $(otserver_headers)
otserver_CXXFLAGS	=	-I$(otserver_headers_dir) $(AM_CXXFLAGS)
otserver_LDADD		=	otlib/libot.la $(DEPS_LIBS)
otserver_DEPENDENCIES	=	otlib/libot.la


####	Createmint  (includes files from OT Server)

createmint_SOURCES	=	$(createmint_sources)			\
				$(otserver_sources) $(otserver_headers)
createmint_CXXFLAGS	=	-I$(otserver_headers_dir) $(AM_CXXFLAGS)
createmint_LDADD	=	otlib/libot.la $(DEPS_LIBS)
createmint_DEPENDENCIES =	otlib/libot.la


####################################
## Open Transactions Build Options #
####################################

#### Transport ZMQ

if TRANSPORT_ZMQ

ot_CXXFLAGS			+=	-DOT_ZMQ_MODE

otserver_SOURCES		+=	otserver/xmlrpcxx_server.cpp
otserver_CXXFLAGS		+=	-DOT_ZMQ_MODE

createmint_CXXFLAGS		+=	-DOT_ZMQ_MODE
endif

