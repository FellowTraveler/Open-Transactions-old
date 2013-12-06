SUBDIRS                 =   otlib otapi

opentxs_include_dir     =   $(top_srcdir)/include
opentxs_source_dir      =   $(top_srcdir)/src

common_includes         =   $(AM_CXXFLAGS) \
			    -I$(top_builddir)/include/otlib \
                            -I$(opentxs_include_dir)  \
                            -I$(opentxs_include_dir)/otlib

## Open Transactions Bin Build  ##

bin_PROGRAMS            =   ot otserver createmint

#### OT

ot_SOURCES              =  $(ot_sources) $(otapi_headers)

ot_CXXFLAGS             =  $(common_includes) -I$(otapi_headers_dir)

ot_LDADD                =  otapi/libotapi.la otlib/libot.la
ot_DEPENDENCIES         =  otapi/libotapi.la otlib/libot.la


#### OT Server

otserver_SOURCES        =   $(otserver_sources) $(otserver_headers)

otserver_CXXFLAGS       =   $(common_includes) -I$(otserver_headers_dir)

otserver_LDADD          =   otlib/libot.la
otserver_DEPENDENCIES   =   otlib/libot.la


#### Createmint  (includes files from OT Server)

createmint_SOURCES      =   $(createmint_sources) $(otserver_sources) $(otserver_headers)

createmint_CXXFLAGS     =   $(common_includes) -I$(otserver_headers_dir)

createmint_LDADD        =   otlib/libot.la
createmint_DEPENDENCIES =   otlib/libot.la


#### Transport ZMQ 'option'

if TRANSPORT_ZMQ

ot_CXXFLAGS            +=   -DOT_ZMQ_MODE

otserver_SOURCES       +=   ots/xmlrpcxx_server.cpp
otserver_CXXFLAGS      +=   -DOT_ZMQ_MODE

createmint_CXXFLAGS    +=   -DOT_ZMQ_MODE
endif


#### OT

ot_sources              =   otd/main.cpp

otapi_headers_dir       =   $(opentxs_include_dir)/otapi

otapi_headers           =   $(otapi_headers_dir)/main.h             \
                            $(otapi_headers_dir)/OpenTransactions.h \
                            $(otapi_headers_dir)/OTAPI.h            \
                            $(otapi_headers_dir)/OT_ME.h            \
                            $(otapi_headers_dir)/OTClient.h         \
                            $(otapi_headers_dir)/OTServerConnection.h

#### OT Server

otserver_sources        =   ots/OTClientConnection.cpp  \
                            ots/OTServer.cpp

otserver_headers_dir    =   $(opentxs_include_dir)/ots

otserver_headers        =   $(otserver_headers_dir)/main.h   \
                            $(otserver_headers_dir)/OTClientConnection.h \
                            $(otserver_headers_dir)/OTServer.h

#### OT Create Mint

createmint_sources      =   otmint/main.cpp
