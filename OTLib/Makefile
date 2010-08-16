#
# The PROGRAM macro defines the name of the program or project.  It
# allows the program name to be changed by editing in only one
# location
#

PROGRAM = libOTLib.a 

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
	-I./irlxml \
	-I./Lucre \
	-I./


LIBDIRS = \
	-L./


LIBS = -lssl -lcrypto

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

LUCRESOURCES = Lucre/bankimp.cpp

IRRXMLSOURCES = irlxml/irrXML.cpp      

CSOURCES = easyzlib.c

CXXSOURCES = $(LUCRESOURCES) $(IRRXMLSOURCES) \
			 OTData.cpp \
			 OTString.cpp \
			 OTStringXML.cpp \
			 OTASCIIArmor.cpp \
			 OTContract.cpp \
			 OTSignedFile.cpp \
			 OTPseudonym.cpp \
			 OTMint.cpp \
			 OTInstrument.cpp \
			 OTCheque.cpp \
			 OTPurse.cpp \
			 OTToken.cpp \
			 OTTransactionType.cpp \
			 OTItem.cpp \
			 OTBasket.cpp \
			 OTTransaction.cpp \
			 OTLedger.cpp \
			 OTAccount.cpp \
		     	OTEnvelope.cpp \
			 OTAssetContract.cpp \
			 OTServerContract.cpp \
			 OTPayload.cpp \
			 OTMessage.cpp \
			 OTIdentifier.cpp \
			 OTAsymmetricKey.cpp \
			 OTSignature.cpp \
			 OTDataCheck.cpp
			 
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
	ar rc $(PROGRAM) $(CXXOBJECTS) $(COBJECTS)

#
# Object targets: rules that define objects, their dependencies, and
# a list of commands for compilation.
#

easyzlib.o: easyzlib.c easyzlib.h
	$(CC) $(CFLAGS) -c -o easyzlib.o easyzlib.c 

irlxml/irrXML.o: irlxml/irrXML.cpp irlxml/irrXML.h
	$(CXX) $(CXXFLAGS) -c -o irlxml/irrXML.o irlxml/irrXML.cpp

bankimp.o: Lucre/bankimp.cpp Lucre/bank.h
	$(CXX) $(CXXFLAGS) -c -o Lucre/bankimp.o Lucre/bankimp.cpp

OTData.o: OTData.cpp OTData.h
	$(CXX) $(CXXFLAGS) -c -o OTData.o OTData.cpp
OTString.o: OTString.cpp OTString.h
	$(CXX) $(CXXFLAGS) -c -o OTString.o OTString.cpp
OTStringXML.o: OTStringXML.cpp OTStringXML.h
	$(CXX) $(CXXFLAGS) -c -o OTStringXML.o OTStringXML.cpp
OTIdentifier.o: OTIdentifier.cpp OTIdentifier.h
	$(CXX) $(CXXFLAGS) -c -o OTIdentifier.o OTIdentifier.cpp
OTASCIIArmor.o: OTASCIIArmor.cpp OTASCIIArmor.h
	$(CXX) $(CXXFLAGS) -c -o OTASCIIArmor.o OTASCIIArmor.cpp
OTSignature.o: OTSignature.cpp OTSignature.h
	$(CXX) $(CXXFLAGS) -c -o OTSignature.o OTSignature.cpp
OTPseudonym.o: OTPseudonym.cpp OTPseudonym.h
	$(CXX) $(CXXFLAGS) -c -o OTPseudonym.o OTPseudonym.cpp
OTContract.o: OTContract.cpp OTContract.h
	$(CXX) $(CXXFLAGS) -c -o OTContract.o OTContract.cpp
OTSignedFile.o: OTSignedFile.cpp OTSignedFile.h
	$(CXX) $(CXXFLAGS) -c -o OTSignedFile.o OTSignedFile.cpp
OTInstrument.o: OTInstrument.cpp OTInstrument.h
	$(CXX) $(CXXFLAGS) -c -o OTInstrument.o OTInstrument.cpp
OTCheque.o: OTCheque.cpp OTCheque.h
	$(CXX) $(CXXFLAGS) -c -o OTCheque.o OTCheque.cpp
OTToken.o: OTToken.cpp OTToken.h
	$(CXX) $(CXXFLAGS) -c -o OTToken.o OTToken.cpp
OTPurse.o: OTPurse.cpp OTPurse.h
	$(CXX) $(CXXFLAGS) -c -o OTPurse.o OTPurse.cpp
OTMint.o: OTMint.cpp OTMint.h
	$(CXX) $(CXXFLAGS) -c -o OTMint.o OTMint.cpp
OTTransactionType.o: OTTransactionType.cpp OTTransactionType.h
	$(CXX) $(CXXFLAGS) -c -o OTTransactionType.o OTTransactionType.cpp
OTItem.o: OTItem.cpp OTItem.h
	$(CXX) $(CXXFLAGS) -c -o OTItem.o OTItem.cpp
OTBasket.o: OTBasket.cpp OTBasket.h
	$(CXX) $(CXXFLAGS) -c -o OTBasket.o OTBasket.cpp
OTTransaction.o: OTTransaction.cpp OTTransaction.h
	$(CXX) $(CXXFLAGS) -c -o OTTransaction.o OTTransaction.cpp
OTLedger.o: OTLedger.cpp OTLedger.h
	$(CXX) $(CXXFLAGS) -c -o OTLedger.o OTLedger.cpp
OTAccount.o: OTAccount.cpp OTAccount.h
	$(CXX) $(CXXFLAGS) -c -o OTAccount.o OTAccount.cpp
OTEnvelope.o: OTEnvelope.cpp OTEnvelope.h
	$(CXX) $(CXXFLAGS) -c -o OTEnvelope.o OTEnvelope.cpp
OTAssetContract.o: OTAssetContract.cpp OTAssetContract.h
	$(CXX) $(CXXFLAGS) -c -o OTAssetContract.o OTAssetContract.cpp
OTServerContract.o: OTServerContract.cpp OTServerContract.h
	$(CXX) $(CXXFLAGS) -c -o OTServerContract.o OTServerContract.cpp
OTPayload.o: OTPayload.cpp OTPayload.h
	$(CXX) $(CXXFLAGS) -c -o OTPayload.o OTPayload.cpp
OTMessage.o: OTMessage.cpp OTMessage.h
	$(CXX) $(CXXFLAGS) -c -o OTMessage.o OTMessage.cpp
OTAsymmetricKey.o: OTAsymmetricKey.cpp OTAsymmetricKey.h
	$(CXX) $(CXXFLAGS) -c -o OTAsymmetricKey.o OTAsymmetricKey.cpp
OTDataCheck.o: OTDataCheck.cpp OTDataCheck.h
	$(CXX) $(CXXFLAGS) -c -o OTDataCheck.o OTDataCheck.cpp


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
