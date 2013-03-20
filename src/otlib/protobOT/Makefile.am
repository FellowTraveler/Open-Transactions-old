## Build locally and statically link as a private convenience library

noinst_LTLIBRARIES = libprotobOT.la

AM_CPPFLAGS		= 	$(AC_CXXFLAGS)
AM_CXXFLAGS		=	$(AC_CXXFLAGS)

libprotobOT_la_SOURCES	=	$(protobOT_sources) $(protobOT_headers)
libprotobOT_la_CXXFLAGS	=	-I$(protobOT_headers_dir) $(DEPS_CFLAGS) -fpic
libprotobOT_la_LDFLAGS	=	-static

## Generate *.pb.cc and *.pb.h from *.proto

%.pb.cc $(protobOT_headers_dir)/%.pb.h: %.proto
	$(PROTOC) --cpp_out=$(top_srcdir)/src/otlib/protobOT $^
	$(AM_V_at)$(am__mv) $*.pb.h $(protobOT_headers_dir)/$*.pb.h

####################################################################

protobOT_sources	=	Bitcoin.pb.cc		\
				Generics.pb.cc		\
				Markets.pb.cc		\
				Moneychanger.pb.cc

protobOT_headers_dir	=	$(top_srcdir)/include/otlib

protobOT_headers	=	$(protobOT_headers_dir)/Bitcoin.pb.h	\
				$(protobOT_headers_dir)/Generics.pb.h	\
				$(protobOT_headers_dir)/Markets.pb.h	\
				$(protobOT_headers_dir)/Moneychanger.pb.h

clean-local :
	-rm -f *.pb.cc
	-rm -f $(protobOT_headers_dir)/*.pb.h

