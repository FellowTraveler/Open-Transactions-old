#
# Open-Transactions:  testwallet Makefile
#
# IMPORTANT:  WHEN USING THIS MAKEFILE, YOU *MUST* USE THE OPTIONS.
# EXAMPLE:
#
# make TRANSPORT=ZMQ
# make TRANSPORT=ssltcp debug
# Etc...
#
# Transport is mandatory.
#
# Platform options are darwin, linux and freebsd (these are auto-detected now)
#
# Language options are c, csharp, java, ruby, python, perl5, php5, 
# tcl, and lisp. 
#

PROGRAM = testwallet.exe
DEBUG_PROGRAM = testwallet.debug


# Find out what platform we're on.
UNAME := $(shell uname -s)

OT_PLATFORM := ___OT_PLATFORM_UNKNOWN___

# ---------------------------------------------------------------------

ifeq ($(FELLOW_TRAVELER), 1)
FT_FLAGS = -DFELLOW_TRAVELER
else
FT_FLAGS = #empty
endif

# ---------------------------------------------------------------------

ifeq ($(DSP), 1)
FT_FLAGS += -DDSP
endif

# ---------------------------------------------------------------------


ifeq ($(OT_TEST_PASSWORD), 1)
FT_FLAGS += -DOT_TEST_PASSWORD
endif

# ---------------------------------------------------------------------


# I allow the user the option to force-override the build platform.
# Using make PLATFORM=darwin, for example, you will build in darwin mode
# even if you are on a linux box.
#

ifeq ($(PLATFORM), darwin)
UNAME := Darwin
endif
ifeq ($(PLATFORM), linux)
UNAME := Linux
endif
ifeq ($(PLATFORM), freebsd)
UNAME := FreeBSD
endif

ifeq ($(UNAME), Darwin)
OT_PLATFORM := darwin
endif
ifeq ($(UNAME), Linux)
OT_PLATFORM := linux
endif
ifeq ($(UNAME), FreeBSD)
OT_PLATFORM := freebsd
endif


PLATFORM = $(OT_PLATFORM)


# ---------------------------------------------------------------------


OT_INCLUDEDIRS = \
	-I../OTLib/irrxml \
	-I../OTLib \
	-I./SSL-Example \
	-I../OTLib/simpleini \
	-I.


OT_LIBDIRS = \
	-L../OTLib

API_CSOURCES = SSL-Example/SFSocket.c
API_CXXSOURCES = # empty
API_CFLAGS = # empty
API_LDFLAGS = # empty


C_COMPILER = cc
CPP_COMPILER = g++

# The LIBS macro contains a list of libraries that the the
# executable must be linked against.
API_LIBS =  -lssl -lcrypto  -lOTLib -lssl -lcrypto  -lboost_thread-mt -lOTLib  -lssl -lcrypto -lOTLib  -lssl -lcrypto -lprotobuf -lmsgpack -lzmq -lOTLib
API_DEBUG_LIBS = -lssl -lcrypto -lOTLibd -lssl -lcrypto -lboost_thread-mt -lOTLibd  -lssl -lcrypto -lOTLibd -lssl -lcrypto -lprotobuf -lmsgpack -lzmq -lOTLibd
#
# FT: I tested this. The above version worked on Linux, and the below version did not.
#
#API_LIBS = -lssl  -lcrypto -lOTLib
#API_DEBUG_LIBS =  -lssl -lcrypto  -lOTLibd




LINUX_LIBDIR = lib
LBITS := $(shell getconf LONG_BIT)
ifeq ($(LBITS),64)
LINUX_LIBDIR = lib64
API_CFLAGS = -m64
API_LDFLAGS = -m64
endif

# ---------------------------------------------------------------------
# SSL Folders!

# For Darwin I use /opt instead of /usr, since OpenSSL 1.0.0i is
# installed to that location by MacPorts.
#
ifeq ($(PLATFORM), darwin)
SSL_INCLUDEDIRS = -I/opt/local/include
SSL_LIBDIRS = -L/opt/local/lib
endif

ifeq ($(PLATFORM), linux)
SSL_INCLUDEDIRS = -I/usr/local/ssl/include
SSL_LIBDIRS = -L/usr/local/ssl/$(LINUX_LIBDIR)
endif

ifeq ($(PLATFORM), freebsd)
SSL_INCLUDEDIRS = -I/usr/local/include
SSL_LIBDIRS = -L/usr/local/lib
#SSL_LIBDIRS = -L/usr/ports/security/openssl/work/openssl-1.0.0i
endif

# ---------------------------------------------------------------------


ifeq ($(DSP), 1)
PLATFORM_LIBDIRS = -L../openssl
PLATFORM_INCLUDEDIRS = -I../openssl/include 
else
PLATFORM_LIBDIRS = #empty
PLATFORM_INCLUDEDIRS = #empty
endif

# ---------------------------------------------------------------------


#
# Eventually more platform stuff can go below here, like 64-bit, etc.
#
# ---------------------------------------------------------------------

# --- DARWIN
#
ifeq ($(PLATFORM), darwin)

#CPP_COMPILER = clang++
#C_COMPILER = clang
CPP_COMPILER = g++
C_COMPILER = cc

endif
# End DARWIN -------------------------------------------------------------



ifeq ($(PLATFORM), linux)

API_LDFLAGS += -ldl -lpthread

C_COMPILER = gcc
CPP_COMPILER = g++

endif
# End LINUX -------------------------------------------------------------




# --- FreeBSD ----

ifeq ($(PLATFORM), freebsd)

endif
# End FreeBSD -------------------------------------------------------------





# ---------------------------------------------------------------------

# --- TRANSPORT

# This is not a target, but a command-line option.
#
# So you have to do: make PLATFORM=linux TRANSPORT=ZMQ
#                OR: make PLATFORM=darwin TRANSPORT=ZMQ debug
#                OR: make PLATFORM=freebsd TRANSPORT=ZMQ
# 		Etc...
#

#XMLRPCPP_INCLUDEDIR = -I../xmlrpcpp/src
#XMLRPCPP_LIBDIR = -L../xmlrpcpp/

ifeq ($(TRANSPORT), ZMQ)
API_CFLAGS += -DOT_ZMQ_MODE
API_CXXSOURCES += xmlrpcxx_client.cpp
else
API_CXXSOURCES += testclient.cpp
endif





INCLUDEDIRS = $(PLATFORM_INCLUDEDIRS)  $(SSL_INCLUDEDIRS) $(OT_INCLUDEDIRS)

LIBDIRS = $(PLATFORM_LIBDIRS)  $(SSL_LIBDIRS) $(OT_LIBDIRS)


CSOURCES = $(API_CSOURCES)

CXXSOURCES = \
                         OpenTransactions.cpp \
                         OTAPI.cpp \
                         OTAPI_Wrapper.cpp \
                         OTServerConnection.cpp \
                         OTClient.cpp \
                         $(API_CXXSOURCES)

CXXOBJECTS = $(CXXSOURCES:.cpp=.o)  # expands to list of object files
COBJECTS   = $(CSOURCES:.c=.o)

# The code will automatically accept the entire inbox, if compiled
# in TEST_CLIENT mode.  But if it's compiled in API mode, then you
# have to manually go through the inbox items and allow your user
# the opportunity to accept or reject them.
#
#CFLAGS     = $(INCLUDEDIRS) $(API_CFLAGS) $(FT_FLAGS) -DTEST_CLIENT -c -Wall -O -Wextra -Wwrite-strings -Winit-self -Wcast-align -Wcast-qual -Wold-style-cast -Wpointer-arith -Wstrict-aliasing -Wformat=2 -Wuninitialized -Woverloaded-virtual -Wnon-virtual-dtor -Wctor-dtor-privacy -Wno-long-long

#CFLAGS     = $(INCLUDEDIRS) $(API_CFLAGS) $(FT_FLAGS) -DTEST_CLIENT -c -O1 -fstack-protector-all -Wsign-compare -Wstack-protector -Wpointer-arith -Waddress -Wuninitialized -Wconversion

CFLAGS     = $(INCLUDEDIRS) $(API_CFLAGS) $(FT_FLAGS) -DTEST_CLIENT -D_FORTIFY_SOURCE=2 -fstack-protector-all -fstack-check -Wstack-protector -c -Wall


DEBUG_FLAGS = -g3 -ggdb -rdynamic -O0 -Wshadow -Wglobal-constructors -Waddress -Woverloaded-virtual -Wshadow -Wconversion -Wshorten-64-to-32 --param ssp-buffer-size=4

CXX = $(CPP_COMPILER)
CC = $(C_COMPILER)

LIBS = $(API_LIBS)
DEBUG_LIBS = $(API_DEBUG_LIBS)


# --- LDFLAGS
#
LDFLAGS = $(LIBDIRS) $(LIBS) $(API_LDFLAGS)
DEBUG_LDFLAGS = $(LIBDIRS) $(DEBUG_LIBS) $(API_LDFLAGS)





# ---------------------------------------------------------------------

# --- DARWIN
#
ifeq ($(PLATFORM), darwin)
LINK_COMMAND = $(CXX) $(LDFLAGS) -o $(PROGRAM) $(CXXOBJECTS) $(COBJECTS)
DEBUG_LINK_COMMAND = $(CXX) $(DEBUG_LDFLAGS) -o $(DEBUG_PROGRAM) $(CXXOBJECTS) $(COBJECTS)
endif
# End DARWIN -------------------------------------------------------------

ifeq ($(PLATFORM), linux)
LINK_COMMAND = $(CXX) $(CXXOBJECTS) $(COBJECTS) $(LDFLAGS) -o $(PROGRAM)
DEBUG_LINK_COMMAND = $(CXX)  $(CXXOBJECTS) $(COBJECTS) $(DEBUG_LDFLAGS) -o $(DEBUG_PROGRAM)
endif
# End LINUX -------------------------------------------------------------

# --- FreeBSD ----
ifeq ($(PLATFORM), freebsd)
LINK_COMMAND = $(CXX) $(CXXOBJECTS) $(COBJECTS) $(LDFLAGS) -o $(PROGRAM)
DEBUG_LINK_COMMAND = $(CXX)  $(CXXOBJECTS) $(COBJECTS) $(DEBUG_LDFLAGS) -o $(DEBUG_PROGRAM)
endif
# End FreeBSD -------------------------------------------------------------




# ---------------------------------------------------------------------

# --- TARGETS

#
# Default target: the first target is the default target.
# Just type "make PLATFORM=darwin" to build it.
#

$(PROGRAM): $(CXXOBJECTS) $(COBJECTS)
	$(LINK_COMMAND)

all: $(PROGRAM)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: LIBS = $(DEBUG_LIBS)
debug: LDFLAGS = $(DEBUG_LDFLAGS)
debug: $(CXXOBJECTS) $(COBJECTS) 
	$(DEBUG_LINK_COMMAND)


# ---------------------------------------------------------------------


#
# Object targets: rules that define objects, their dependencies, and
# a list of commands for compilation.
#

SFSocket.o: ./SSL-Example/SFSocket.c ./SSL-Example/SFSocket.h
	$(CC) $(CFLAGS) -o ./SSL-Example/SFSocket.o ./SSL-Example/SFSocket.c

OTServerConnection.o: OTServerConnection.cpp OTServerConnection.h
	$(CXX) $(CFLAGS) -o OTServerConnection.o OTServerConnection.cpp
OTClient.o: OTClient.cpp OTClient.h
	$(CXX) $(CFLAGS) -o OTClient.o OTClient.cpp
OpenTransactions.o: OpenTransactions.cpp OpenTransactions.h
	$(CXX) $(CFLAGS) -o OpenTransactions.o OpenTransactions.cpp
OTAPI.o: OTAPI.cpp OTAPI.h
	$(CXX) $(CFLAGS) -o OTAPI.o OTAPI.cpp
OTAPI_Wrapper.o: OTAPI_Wrapper.cpp OTAPI_Wrapper.h
	$(CXX) $(CFLAGS) -o OTAPI_Wrapper.o OTAPI_Wrapper.cpp

xmlrpcxx_client.o: xmlrpcxx_client.cpp
	$(CXX) $(CFLAGS) -o xmlrpcxx_client.o xmlrpcxx_client.cpp

testclient.o: testclient.cpp
	$(CXX) $(CFLAGS) -o testclient.o testclient.cpp

#
# Clean target: "make clean" to remove unwanted objects and executables.
#
RM=rm

clean:
	$(RM) -f ot.log $(COBJECTS) $(CXXOBJECTS) $(PROGRAM) $(DEBUG_PROGRAM)


# Run target: "make run" to execute the application
#             You will need to add $(VARIABLE_NAME) for any command line parameters 
#             that you defined earlier in this file.
# 

run:
	./$(PROGRAM) 


