
# COMMENT: This is set up for Mac OS X, Linux, and FreeBSD. 
# This makefile will build the entire project and all the assorted tools.
#
# For Mac and Linux, just type 'make'. For FreeBSD, type 'gmake'.
#
# RPC is the PREFERRED mode to run the software, since it uses ZMQ over
# http.  'make rpc'
#
# (Both of the above options will also build the API in C.)
#
# If you would like to build the API for python, ruby, perl5, or php5:
#
# make [python|ruby|perl5|php5]
#
# (gmake on FreeBSD)
#

VERSION := $(shell cat VERSION)

OT_PLATFORM := ___OT_UNKNOWN_PLATFORM___

# ---------------------------------------------------------------------


ifeq ($(FELLOW_TRAVELER), 1)
FT_FLAGS = FELLOW_TRAVELER=1
else
FT_FLAGS = #empty
endif


# ---------------------------------------------------------------------

ifeq ($(DSP), 1)
FT_FLAGS += DSP=1
endif

# ---------------------------------------------------------------------



OT_MAKE := make



# Find out what platform we're on.
UNAME := $(shell uname -s)


LINUX_LIBDIR = lib
LBITS := $(shell getconf LONG_BIT)
ifeq ($(LBITS),64)
LINUX_LIBDIR = lib64
endif

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



DYNAMIC_FLAG = # empty



# The SSL libraries are now set in the section below, for various platforms.
# The Makefiles in the subfolders will only set those values (also by platform)
# in the case where they aren't already set.  So you can set them here for the entire
# project  :-)
#
# You can also override them, here or there, on the command line.

# -------------------------------------

ifeq ($(UNAME), Darwin)
OT_PLATFORM := darwin

# For Darwin I use /opt instead of /usr, since OpenSSL 1.0.0a is
# installed to that location by MacPorts.
SSL_INCLUDEDIRS = -I/opt/local/include
SSL_LIBDIRS = -L/opt/local/lib

EXECUTABLE_INSTALL_FOLDER = /usr/local/bin
LIBRARY_INSTALL_FOLDER = /usr/local/lib

endif


# -------------------------------------

ifeq ($(UNAME), Linux)
OT_PLATFORM := linux
DYNAMIC_FLAG = DYNAMIC_OTLIB=1
SSL_INCLUDEDIRS = -I/usr/local/ssl/include
SSL_LIBDIRS = -L/usr/local/ssl/$(LINUX_LIBDIR)

EXECUTABLE_INSTALL_FOLDER = /usr/local/bin
LIBRARY_INSTALL_FOLDER = /usr/local/lib

endif

# -------------------------------------


ifeq ($(UNAME), FreeBSD)
OT_PLATFORM := freebsd

OT_MAKE := gmake

# No extra targets for now on this platform.  Gotta fix those Makefiles first.

SSL_INCLUDEDIRS = -I/usr/local/include
SSL_LIBDIRS = -L/usr/local/lib
#SSL_LIBDIRS = -L/usr/ports/security/openssl/work/openssl-1.0.0c

EXECUTABLE_INSTALL_FOLDER = /usr/local/bin
LIBRARY_INSTALL_FOLDER = /usr/local/lib

endif

# -------------------------------------

OT_UTIL_PLATFORM_INCLUDEDIRS = -I../../openssl/include
OT_UTIL_PLATFORM_LIBDIRS = -L../../openssl


ifeq ($(DSP), 1)
PLATFORM_INCLUDEDIRS = -I../openssl/include
PLATFORM_LIBDIRS = -L../openssl
OT_SSL_INCLUDE_AND_LIBS = $(FT_FLAGS) PLATFORM_INCLUDEDIRS=$(PLATFORM_INCLUDEDIRS) PLATFORM_LIBDIRS=$(PLATFORM_LIBDIRS) OT_UTIL_PLATFORM_INCLUDEDIRS=$(OT_UTIL_PLATFORM_INCLUDEDIRS) OT_UTIL_PLATFORM_LIBDIRS=$(OT_UTIL_PLATFORM_LIBDIRS) SSL_INCLUDEDIRS=$(SSL_INCLUDEDIRS) SSL_LIBDIRS=$(SSL_LIBDIRS)
else
OT_SSL_INCLUDE_AND_LIBS = $(FT_FLAGS)  SSL_INCLUDEDIRS=$(SSL_INCLUDEDIRS) SSL_LIBDIRS=$(SSL_LIBDIRS)
endif

# -------------------------------------




OT_MAKE_PLATFORM_INC_LIBS = $(OT_MAKE) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS)


EXTRA_TARGETS1 += cd util/otcreatemint && $(OT_MAKE_PLATFORM_INC_LIBS)  && cp ./createmint.exe ../../ot-sample-data/server_data/createmint.exe
EXTRA_TARGETS2 += cd util/signcontract && $(OT_MAKE_PLATFORM_INC_LIBS)  && cp ./signcontract.exe ../../ot-sample-data/client_data/signcontract.exe
EXTRA_DEBUG_TARGETS1 += cd util/otcreatemint && $(OT_MAKE_PLATFORM_INC_LIBS)  debug && cp ./createmint.debug ../../ot-sample-data/server_data/createmint.debug
EXTRA_DEBUG_TARGETS2 += cd util/signcontract && $(OT_MAKE_PLATFORM_INC_LIBS)  debug && cp ./signcontract.debug ../../ot-sample-data/client_data/signcontract.debug
EXTRA_RPC_TARGETS1 += cd util/otcreatemint && $(OT_MAKE_PLATFORM_INC_LIBS)  && cp ./createmint.exe ../../ot-sample-data/server_data/createmint.exe
EXTRA_RPC_TARGETS2 += cd util/signcontract && $(OT_MAKE_PLATFORM_INC_LIBS)  && cp ./signcontract.exe ../../ot-sample-data/client_data/signcontract.exe
EXTRA_DEBUGRPC_TARGETS1 += cd util/otcreatemint && $(OT_MAKE_PLATFORM_INC_LIBS)  debug && cp ./createmint.debug ../../ot-sample-data/server_data/createmint.debug
EXTRA_DEBUGRPC_TARGETS2 += cd util/signcontract && $(OT_MAKE_PLATFORM_INC_LIBS)  debug && cp ./signcontract.debug ../../ot-sample-data/client_data/signcontract.debug
EXTRA_CLEAN_TARGETS1 += cd util/otcreatemint && $(OT_MAKE_PLATFORM_INC_LIBS)  clean && rm -f ../../ot-sample-data/server_data/createmint.*
EXTRA_CLEAN_TARGETS2 += cd util/signcontract && $(OT_MAKE_PLATFORM_INC_LIBS)  clean && rm -f ../../ot-sample-data/client_data/signcontract.*


# -------------------------------------

all:
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS) 
	cd transaction && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ
	cd testwallet && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ
	cd testwallet && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=c
	$(EXTRA_RPC_TARGETS1)
	$(EXTRA_RPC_TARGETS2)

debug:
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS)  debug
	cd transaction && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ debug
	cd testwallet && $(OT_MAKE_PLATFORM_INC_LIBS)   TRANSPORT=ZMQ debug
	cd testwallet && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=c debug
	$(EXTRA_DEBUGRPC_TARGETS1)
	$(EXTRA_DEBUGRPC_TARGETS2)

tcp:
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS)   
	cd transaction && $(OT_MAKE_PLATFORM_INC_LIBS) 
	cd testwallet && $(OT_MAKE_PLATFORM_INC_LIBS) 
	cd testwallet && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) LANGUAGE=c
	$(EXTRA_TARGETS1)
	$(EXTRA_TARGETS2)

debugtcp:
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS)  debug
	cd transaction && $(OT_MAKE_PLATFORM_INC_LIBS)  debug
	cd testwallet && $(OT_MAKE_PLATFORM_INC_LIBS)  debug
	cd testwallet && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) LANGUAGE=c debug
	$(EXTRA_DEBUG_TARGETS1)
	$(EXTRA_DEBUG_TARGETS2)

c:
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS) $(DYNAMIC_FLAG)
	cd transaction && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ
	cd testwallet && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=c clean
	cd testwallet && $(OT_MAKE) -f Makefile.API $(DYNAMIC_FLAG) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=java clean
	cd testwallet && $(OT_MAKE) -f Makefile.API $(DYNAMIC_FLAG) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=ruby clean
	cd testwallet && $(OT_MAKE) -f Makefile.API $(DYNAMIC_FLAG) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=python clean
	cd testwallet && $(OT_MAKE) -f Makefile.API $(DYNAMIC_FLAG) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=perl5 clean
	cd testwallet && $(OT_MAKE) -f Makefile.API $(DYNAMIC_FLAG) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=php5 clean
	cd testwallet && $(OT_MAKE) -f Makefile.API $(DYNAMIC_FLAG) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=c
	$(EXTRA_RPC_TARGETS1)
	$(EXTRA_RPC_TARGETS2)

java:
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS) $(DYNAMIC_FLAG)
	cd transaction && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ
	cd testwallet && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=c clean
	cd testwallet && $(OT_MAKE) -f Makefile.API $(DYNAMIC_FLAG) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=java clean
	cd testwallet && $(OT_MAKE) -f Makefile.API $(DYNAMIC_FLAG) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=java
	$(EXTRA_RPC_TARGETS1)
	$(EXTRA_RPC_TARGETS2)

javadebug:
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS) $(DYNAMIC_FLAG) debug
	cd transaction && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ debug
	cd testwallet && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=c clean
	cd testwallet && $(OT_MAKE) -f Makefile.API $(DYNAMIC_FLAG) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=java clean
	cd testwallet && $(OT_MAKE) -f Makefile.API $(DYNAMIC_FLAG) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=java debug
	$(EXTRA_DEBUG_TARGETS1)
	$(EXTRA_DEBUG_TARGETS1)

csharp:
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS) $(DYNAMIC_FLAG)
	cd transaction && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ
	cd testwallet && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=c clean
	cd testwallet && $(OT_MAKE) -f Makefile.API $(DYNAMIC_FLAG) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=csharp clean
	cd testwallet && $(OT_MAKE) -f Makefile.API $(DYNAMIC_FLAG) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=csharp
	$(EXTRA_RPC_TARGETS1)
	$(EXTRA_RPC_TARGETS2)

ruby:
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS) $(DYNAMIC_FLAG)
	cd transaction && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ
	cd testwallet && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=c clean
	cd testwallet && $(OT_MAKE) -f Makefile.API $(DYNAMIC_FLAG) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=ruby clean
	cd testwallet && $(OT_MAKE) -f Makefile.API $(DYNAMIC_FLAG) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=ruby
	$(EXTRA_RPC_TARGETS1)
	$(EXTRA_RPC_TARGETS2)

perl5:
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS) $(DYNAMIC_FLAG)
	cd transaction && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ
	cd testwallet && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=c clean
	cd testwallet && $(OT_MAKE) -f Makefile.API $(DYNAMIC_FLAG) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=perl5 clean
	cd testwallet && $(OT_MAKE) -f Makefile.API $(DYNAMIC_FLAG) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=perl5
	$(EXTRA_RPC_TARGETS1)
	$(EXTRA_RPC_TARGETS2)

python:
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS) $(DYNAMIC_FLAG)
	cd transaction && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ
	cd testwallet && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=c clean
	cd testwallet && $(OT_MAKE) -f Makefile.API $(DYNAMIC_FLAG) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=ruby clean
	cd testwallet && $(OT_MAKE) -f Makefile.API $(DYNAMIC_FLAG) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=python clean
	cd testwallet && $(OT_MAKE) -f Makefile.API $(DYNAMIC_FLAG) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=python
	$(EXTRA_RPC_TARGETS1)
	$(EXTRA_RPC_TARGETS2)

php5:
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS) $(DYNAMIC_FLAG)
	cd transaction && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ
	cd testwallet && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=c clean
	cd testwallet && $(OT_MAKE) -f Makefile.API $(DYNAMIC_FLAG) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=php5 clean
	cd testwallet && $(OT_MAKE) -f Makefile.API $(DYNAMIC_FLAG) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=php5
	$(EXTRA_RPC_TARGETS1)
	$(EXTRA_RPC_TARGETS2)

install:
	mkdir -p $(EXECUTABLE_INSTALL_FOLDER)
	rm -f $(EXECUTABLE_INSTALL_FOLDER)/ot_server && cp ./transaction/transaction.exe $(EXECUTABLE_INSTALL_FOLDER)/ot_server
	rm -f $(EXECUTABLE_INSTALL_FOLDER)/ot &&  cp ./testwallet/testwallet.exe $(EXECUTABLE_INSTALL_FOLDER)/ot
	mkdir -p $(LIBRARY_INSTALL_FOLDER)
	cd testwallet && ls -d *.so | sed 's/\(.*\)$/cp "&" "\1.$(VERSION)"/' | sh
	cd testwallet && mv *.$(VERSION) $(LIBRARY_INSTALL_FOLDER)
	ldconfig -n $(LIBRARY_INSTALL_FOLDER)

local:
	mkdir ~/.ot && cp -r ./ot-sample-data/* ~/.ot && chown -R $(USER) ~/.ot

uninstall:
	rm -f $(EXECUTABLE_INSTALL_FOLDER)/ot_server
	rm -f $(EXECUTABLE_INSTALL_FOLDER)/ot

remove_local:
	rm -f ~/$(SUDO_USER)_OT_BACKUP_2.tgz
	touch ~/$(SUDO_USER)_OT_BACKUP.tgz
	mv ~/$(SUDO_USER)_OT_BACKUP.tgz ~/$(SUDO_USER)_OT_BACKUP_2.tgz
	tar -czvf ~/$(SUDO_USER)_OT_BACKUP.tgz ~/.ot
	rm -rf ~/.ot

clean:
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS)  clean
	cd transaction && $(OT_MAKE_PLATFORM_INC_LIBS)  clean
	cd transaction && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ clean
	cd testwallet && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) LANGUAGE=c clean
	cd testwallet && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) LANGUAGE=ruby clean
	cd testwallet && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) LANGUAGE=python clean
	cd testwallet && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) LANGUAGE=perl5 clean
	cd testwallet && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) LANGUAGE=php5 clean
	cd testwallet && $(OT_MAKE_PLATFORM_INC_LIBS)  clean
	cd testwallet && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ clean
	$(EXTRA_CLEAN_TARGETS1)
	$(EXTRA_CLEAN_TARGETS2)

