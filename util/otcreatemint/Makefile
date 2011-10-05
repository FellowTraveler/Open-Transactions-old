#
# The PROGRAM macro defines the name of the program or project.  It
# allows the program name to be changed by editing in only one
# location
#

PROGRAM = createmint.exe

DEBUG_PROGRAM = createmint.debug


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



OT_INCLUDEDIRS = \
	-I../../OTLib/irrxml \
	-I../../OTLib/simpleini \
	-I../../OTLib \
	-I./


OT_LIBDIRS = \
	-L../../OTLib


API_CXXSOURCES = # empty
API_CFLAGS = # empty
API_LDFLAGS = # empty


# The LIBS macro contains a list of libraries that the the
# executable must be linked against.
#API_LIBS =  -lssl -lcrypto  -lOTLib -lssl -lcrypto  -lOTLib  -lssl -lcrypto -lOTLib  -lssl -lcrypto -lprotobuf -lmsgpack -lOTLib
#API_DEBUG_LIBS = -lssl -lcrypto -lOTLibd -lssl -lcrypto -lOTLibd  -lssl -lcrypto -lOTLibd -lssl -lcrypto -lprotobuf -lmsgpack -lOTLibd



LINUX_LIBDIR = lib
LBITS := $(shell getconf LONG_BIT)
ifeq ($(LBITS),64)
LINUX_LIBDIR = lib64
endif

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
OT_UTIL_PLATFORM_INCLUDEDIRS = -I../../openssl/include
OT_UTIL_PLATFORM_LIBDIRS = -L../../openssl
else
OT_UTIL_PLATFORM_INCLUDEDIRS = #empty
OT_UTIL_PLATFORM_LIBDIRS = #empty
endif

# ---------------------------------------------------------------------





#
# Eventually more platform stuff can go below here, like 64-bit, etc.
#
# ---------------------------------------------------------------------

# --- DARWIN
#
ifeq ($(PLATFORM), darwin)
API_LIBS = -lssl -lcrypto -lprotobuf -lmsgpack -lOTLib 
API_DEBUG_LIBS =  -lssl -lcrypto -lprotobuf -lmsgpack -lOTLibd 
endif
# End DARWIN -------------------------------------------------------------



ifeq ($(PLATFORM), linux)

API_LDFLAGS += -ldl

API_LIBS = -lOTLib -lssl -lcrypto -lprotobuf -lmsgpack 
API_DEBUG_LIBS =  -lOTLibd -lssl -lcrypto -lprotobuf -lmsgpack 

endif
# End LINUX -------------------------------------------------------------




# --- FreeBSD ----

ifeq ($(PLATFORM), freebsd)
API_LIBS = -lssl  -lcrypto -lprotobuf -lmsgpack -lOTLib 
API_DEBUG_LIBS =  -lssl -lcrypto -lprotobuf -lmsgpack -lOTLibd 
endif
# End FreeBSD -------------------------------------------------------------




INCLUDEDIRS = $(OT_UTIL_PLATFORM_INCLUDEDIRS)  $(SSL_INCLUDEDIRS) $(OT_INCLUDEDIRS)

LIBDIRS = $(OT_UTIL_PLATFORM_LIBDIRS)  $(SSL_LIBDIRS) $(OT_LIBDIRS)


CXXSOURCES = \
			 main.cpp
			 
CXXOBJECTS = $(CXXSOURCES:.cpp=.o)  # expands to list of object files
CXXFLAGS   = $(INCLUDEDIRS) $(API_CFLAGS) $(FT_FLAGS) -c
DEBUG_FLAGS = -g
CXX = g++

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
LINK_COMMAND = $(CXX) $(LDFLAGS) -o $(PROGRAM) $(CXXOBJECTS)
DEBUG_LINK_COMMAND = $(CXX) $(DEBUG_LDFLAGS) -o $(DEBUG_PROGRAM) $(CXXOBJECTS)
endif
# End DARWIN -------------------------------------------------------------

ifeq ($(PLATFORM), linux)
LINK_COMMAND = $(CXX) $(CXXOBJECTS) $(LDFLAGS) -o $(PROGRAM)
DEBUG_LINK_COMMAND = $(CXX)  $(CXXOBJECTS) $(DEBUG_LDFLAGS) -o $(DEBUG_PROGRAM)
endif
# End LINUX -------------------------------------------------------------

# --- FreeBSD ----
ifeq ($(PLATFORM), freebsd)
LINK_COMMAND = $(CXX) $(CXXOBJECTS) $(LDFLAGS) -o $(PROGRAM)
DEBUG_LINK_COMMAND = $(CXX)  $(CXXOBJECTS) $(DEBUG_LDFLAGS) -o $(DEBUG_PROGRAM)
endif
# End FreeBSD -------------------------------------------------------------




# ---------------------------------------------------------------------

# --- TARGETS

#
# Default target: the first target is the default target.
# Just type "make PLATFORM=darwin" to build it.
#

$(PROGRAM): $(CXXOBJECTS)
	$(LINK_COMMAND)

all: $(PROGRAM)

debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: LIBS = $(DEBUG_LIBS)
debug: LDFLAGS = $(DEBUG_LDFLAGS)
debug: $(CXXOBJECTS) $(COBJECTS) 
	$(DEBUG_LINK_COMMAND)



#
# Object targets: rules that define objects, their dependencies, and
# a list of commands for compilation.
#

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c -o main.o main.cpp


#
#
RM=rm

clean:
	$(RM) -f $(CXXOBJECTS) $(PROGRAM) $(DEBUG_PROGRAM)

#
# Run target: "make run" to execute the application
#             You will need to add $(VARIABLE_NAME) for any command line parameters 
#             that you defined earlier in this file.
# 

run:
	./$(PROGRAM) 
