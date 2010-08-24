#
# The PROGRAM macro defines the name of the program or project.  It
# allows the program name to be changed by editing in only one
# location
#

PROGRAM = testwallet.exe  

#
# Command line parameters: Edit these parameters so that you can 
# easily run the sample by typing "make -f Makefile.Linux run".
#

#
# The INCLUDEDIRS macro contains a list of include directories
# to pass to the compiler so it can find necessary header files.
#
# The LIBDIRS macro contains a list of library directories
# to pass to the linker so it can find necessary libraries.
#
# The LIBS macro contains a list of libraries that the the
# executable must be linked against.
#

INCLUDEDIRS = \
	-I/usr/local/ssl/include \
	-I../OTLib/irlxml \
	-I../OTLib \
	-I./SSL-Example \
	-I./


LIBDIRS = \
	-L../OTLib


LIBS = $(LIBDIRS) -lssl $(LIBDIRS) -lcrypto $(LIBDIRS) -lOTLib $(LIBDIRS) -lssl $(LIBDIRS) -lcrypto $(LIBDIRS) -lOTLib 

#
# The CXXSOURCES macro contains a list of source files.
#
# The CXXOBJECTS macro converts the CXXSOURCES macro into a list
# of object files.
#
# The CXXFLAGS macro contains a list of options to be passed to
# the compiler.  Adding "-g" to this line will cause the compiler
# to add debugging information to the executable.
#
# The CXX macro defines the C++ compiler.
#
# The LDFLAGS macro contains all of the library and library
# directory information to be passed to the linker.
#

CSOURCES = ./SSL-Example/SFSocket.c

CXXSOURCES = \
			 OTServerConnection.cpp \
			 OTClient.cpp \
			 client.cpp \
			 OTMessageBuffer.cpp \
			 OTWallet.cpp
			 
CXXOBJECTS = $(CXXSOURCES:.cpp=.o)  # expands to list of object files
COBJECTS   = $(CSOURCES:.c=.o)
CXXFLAGS   = $(INCLUDEDIRS)
CFLAGS     = $(INCLUDEDIRS)
CXX = g++
CC = gcc
LDFLAGS = $(LIBDIRS) $(LIBS)

#
# Default target: the first target is the default target.
# Just type "make -f Makefile.Linux" to build it.
#

all: $(PROGRAM)

#
# Link target: automatically builds its object dependencies before
# executing its link command.
#

$(PROGRAM): $(CXXOBJECTS) $(COBJECTS) 
	$(CXX) -ldl $(CXXOBJECTS) $(COBJECTS) $(LIBS) -o $@

#
# Object targets: rules that define objects, their dependencies, and
# a list of commands for compilation.
#

SFSocket.o: ./SSL-Example/SFSocket.c ./SSL-Example/SFSocket.h
	$(CC) $(CFLAGS) -c -o ./SSL-Example/SFSocket.o ./SSL-Example/SFSocket.c

OTServerConnection.o: OTServerConnection.cpp OTServerConnection.h
	$(CXX) $(CXXFLAGS) -c -o OTServerConnection.o OTServerConnection.cpp
OTClient.o: OTClient.cpp OTClient.h
	$(CXX) $(CXXFLAGS) -c -o OTClient.o OTClient.cpp
client.o: client.cpp
	$(CXX) $(CXXFLAGS) -c -o client.o client.cpp
OTMessageBuffer.o: OTMessageBuffer.cpp OTMessageBuffer.h
	$(CXX) $(CXXFLAGS) -c -o OTMessageBuffer.o OTMessageBuffer.cpp
OTWallet.o: OTWallet.cpp
	$(CXX) $(CXXFLAGS) -c -o OTWallet.o OTWallet.cpp


#
# Clean target: "make -f Makefile.Linux clean" to remove unwanted objects and executables.
#

clean:
	$(RM) -f $(CXXOBJECTS) $(COBJECTS) $(PROGRAM)

#
# Run target: "make -f Makefile.Linux run" to execute the application
#             You will need to add $(VARIABLE_NAME) for any command line parameters 
#             that you defined earlier in this file.
# 

run:
	./$(PROGRAM) 
