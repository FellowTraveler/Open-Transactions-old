noinst_LTLIBRARIES = libprotobOT.la

## Build locally and statically link as a private convenience library

AM_CPPFLAGS		= 	$(AC_CXXFLAGS)
AM_CXXFLAGS		=	$(AC_CXXFLAGS)

protobOT_headers_dir	=	$(top_srcdir)/include/otlib
protobOT_source_dir	=	$(top_srcdir)/src/otlib/protobOT

protobOT_sources	=	Bitcoin.proto		\
				Generics.proto		\
				Markets.proto		\
				Moneychanger.proto

libprotobOT_la_SOURCES	=	$(protobOT_sources) $(noinst_libprotobOT_la_SOURCES)
libprotobOT_la_CXXFLAGS	=	-I$(protobOT_headers_dir) $(DEPS_CFLAGS) -fpic
libprotobOT_la_LDFLAGS	=	-static

## Extra rules to handle *.proto as autobuild inputs

noinst_libprotobOT_la_SOURCES=	$(protobOT_headers_dir)/Bitcoin.pb.h		\
				$(protobOT_headers_dir)/Generics.pb.h		\
				$(protobOT_headers_dir)/Markets.pb.h		\
				$(protobOT_headers_dir)/Moneychanger.pb.h

BUILT_SOURCES		=	$(noinst_libprotobOT_la_SOURCES)

CLEANFILES		=	$(noinst_libprotobOT_la_SOURCES)		\
				$(protobOT_build_dir)/*.h $(protobOT_build_dir)/*.cc

protobOT_build_dir	=	$(top_builddir)/src/otlib/protobOT

SUFFIXES		=	.proto

.proto.cc :
	$(PROTOC) --cpp_out=$(protobOT_build_dir) --proto_path=$(protobOT_source_dir) $(protobOT_source_dir)/$(*F).proto
	$(AM_V_at)$(am__mv) $(protobOT_build_dir)/$(*F).pb.cc $(protobOT_build_dir)/$(@F)

%.pb.h :
	$(AM_V_at)$(PROTOC) --cpp_out=$(protobOT_build_dir) --proto_path=$(protobOT_source_dir) $(protobOT_source_dir)/$(*F).proto
	$(AM_V_at)$(am__mv) $(protobOT_build_dir)/$(@F) $@
