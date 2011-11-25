#
# Open-Transactions server
#
# The PROGRAM macro defines the name of the program or project.  It
# allows the program name to be changed by editing in only one
# location
#

PROGRAM = transaction.exe  

DEBUG_PROGRAM = transaction.debug



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

# The LIBS macro contains a list of libraries that the the
# executable must be linked against.
API_LIBS =  -lssl -lcrypto  -lOTLib -lssl -lcrypto -lboost_thread-mt -lOTLib  -lssl -lcrypto -lOTLib  -lssl -lcrypto -lprotobuf -lmsgpack -lzmq -lOTLib
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
endif

# ---------------------------------------------------------------------
# SSL Folders!

# For Darwin I use /opt instead of /usr, since OpenSSL 1.0.0a is
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
#SSL_LIBDIRS = -L/usr/ports/security/openssl/work/openssl-1.0.0c
endif

# ---------------------------------------------------------------------

ifeq ($(DSP), 1)
PLATFORM_LIBDIRS = -L../openssl
PLATFORM_INCLUDEDIRS = -I../openssl/include
else
PLATFORM_LIBDIRS =  #empty
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
endif
# End DARWIN -------------------------------------------------------------



ifeq ($(PLATFORM), linux)
API_LDFLAGS += -ldl
C_COMPILER = gcc
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
#API_LDFLAGS += -lXmlRpc
#PLATFORM_INCLUDEDIRS += $(XMLRPCPP_INCLUDEDIR)
#PLATFORM_LIBDIRS += $(XMLRPCPP_LIBDIR)
API_CXXSOURCES += xmlrpcxx_server.cpp
else
API_CXXSOURCES += testserver.cpp
endif



INCLUDEDIRS = $(PLATFORM_INCLUDEDIRS) $(SSL_INCLUDEDIRS) $(OT_INCLUDEDIRS)

LIBDIRS = $(PLATFORM_LIBDIRS)  $(SSL_LIBDIRS) $(OT_LIBDIRS)


CSOURCES = $(API_CSOURCES)


CXXSOURCES = \
	OTClientConnection.cpp \
	OTServer.cpp \
	$(API_CXXSOURCES)


CXXOBJECTS = $(CXXSOURCES:.cpp=.o)  # expands to list of object files
COBJECTS   = $(CSOURCES:.c=.o)
CFLAGS     = $(INCLUDEDIRS) $(API_CFLAGS) $(FT_FLAGS) -c 
DEBUG_FLAGS = -g
CXX = g++
CC = $(C_COMPILER)

LIBS = $(API_LIBS)
DEBUG_LIBS = $(API_DEBUG_LIBS)


# --- LDFLAGS
#
LDFLAGS = $(API_LDFLAGS) $(LIBDIRS) $(LIBS)
DEBUG_LDFLAGS =  $(API_LDFLAGS) $(LIBDIRS) $(DEBUG_LIBS)



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


SSL-Example/SFSocket.o: ./SSL-Example/SFSocket.c ./SSL-Example/SFSocket.h
	$(CC) $(CFLAGS) -o ./SSL-Example/SFSocket.o ./SSL-Example/SFSocket.c

OTServer.o: OTServer.cpp OTServer.h
	$(CXX) $(CFLAGS) -o OTServer.o OTServer.cpp
OTClientConnection.o: OTClientConnection.cpp OTClientConnection.h
	$(CXX) $(CFLAGS) -o OTClientConnection.o OTClientConnection.cpp

testserver.o: testserver.cpp
	$(CXX) $(CFLAGS) -o testserver.o testserver.cpp
xmlrpcxx_server.o: xmlrpcxx_server.cpp
	$(CXX) $(CFLAGS) -o xmlrpcxx_server.o xmlrpcxx_server.cpp


#
# Clean target: "make -f Makefile.Linux clean" to remove unwanted objects and executables.
#

RM=rm

clean:
	$(RM) -f $(CXXOBJECTS) $(COBJECTS) $(PROGRAM) $(DEBUG_PROGRAM)

#
# Run target: "make run" to execute the application
#             You will need to add $(VARIABLE_NAME) for any command line parameters 
#             that you defined earlier in this file.
# 

run:
	./$(PROGRAM) 


