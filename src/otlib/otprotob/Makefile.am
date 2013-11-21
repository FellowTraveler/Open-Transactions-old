noinst_LTLIBRARIES = libotprotob.la

## Build locally and statically link as a private convenience library

otprotob_source_dir     =   $(top_srcdir)/src/otlib/otprotob

otprotob_sources        =   Bitcoin.proto        \
                            Generics.proto       \
                            Markets.proto        \
                            Moneychanger.proto

libotprotob_la_SOURCES  =   $(otprotob_sources)
libotprotob_la_CXXFLAGS =   $(AM_CXXFLAGS) -I$(otprotob_headers_dir)
libotprotob_la_LDFLAGS  =   $(AM_LDFLAGS) -static

## Protobuf headers and packaging

otprotob_headers_dir    =   $(top_srcdir)/include/otlib

otprotob_headers        =   $(otprotob_headers_dir)/Bitcoin.pb.h       \
                            $(otprotob_headers_dir)/Generics.pb.h      \
                            $(otprotob_headers_dir)/Markets.pb.h       \
                            $(otprotob_headers_dir)/Moneychanger.pb.h

BUILT_SOURCES           =   $(otprotob_headers)

pkginclude_HEADERS      =   $(otprotob_headers)


## Extra rules to handle *.proto as autobuild inputs

otprotob_build_dir      =   $(top_builddir)/src/otlib/otprotob

.proto.cc :
	$(AM_V_at)$(PROTOC) --cpp_out=$(otprotob_build_dir) --proto_path=$(otprotob_source_dir) $(otprotob_source_dir)/$(*F).proto
	$(AM_V_at)$(am__mv) $(otprotob_build_dir)/$(*F).pb.cc $(otprotob_build_dir)/$(@F)
	$(AM_V_at)$(am__mv) $(otprotob_build_dir)/$(*F).pb.h $(otprotob_headers_dir)/$(*F).pb.h

%.pb.h :
	$(AM_V_at)$(PROTOC) --cpp_out=$(otprotob_build_dir) --proto_path=$(otprotob_source_dir) $(otprotob_source_dir)/$(*F).proto
	$(AM_V_at)$(am__mv) $(otprotob_build_dir)/$(*F).pb.cc $(otprotob_build_dir)/$(@F)
	$(AM_V_at)$(am__mv) $(otprotob_build_dir)/$(*F).pb.h $(otprotob_headers_dir)/$(*F).pb.h

CLEANFILES              =   $(otprotob_build_dir)/*.h      \
                            $(otprotob_build_dir)/*.cc     \
                            $(otprotob_headers_dir)/*.pb.h
