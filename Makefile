
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

MAJOR_VERSION = $(shell cat VERSION | sed -E 's~^([^\.]+)\..*~\1~')
VERSION := $(shell cat VERSION)

OT_PLATFORM := ___OT_UNKNOWN_PLATFORM___

OT_SERVER_DIR := $(PWD)/transaction
TESTWALLET_DIR := $(PWD)/testwallet


# ---------------------------------------------------------------------

ECHO = @echo -e

NO_COLOR=\x1b[0m
INFO_COLOR=\x1b[34;01m
OK_COLOR=\x1b[32;01m
ERROR_COLOR=\x1b[31;01m
WARN_COLOR=\x1b[33;01m

OK_STRING=$(OK_COLOR)[OK]$(NO_COLOR)
ERROR_STRING=$(ERROR_COLOR)[ERRORS]$(NO_COLOR)
WARN_STRING=$(WARN_COLOR)[WARNINGS]$(NO_COLOR)

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


ifeq ($(OT_TEST_PASSWORD), 1)
FT_FLAGS += OT_TEST_PASSWORD=1
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

all: test_wallet
	@$(ECHO) '$(OK_COLOR)Done!$(NO_COLOR)'

extra_tools:
	@$(ECHO) '$(INFO_COLOR)Making OT Tools...$(NO_COLOR)'
	$(EXTRA_RPC_TARGETS1)
	$(EXTRA_RPC_TARGETS2)

otlib:
	@$(ECHO) '$(INFO_COLOR)Making OTLib...$(NO_COLOR)'
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS)

otlib_dynamic:
	@$(ECHO) '$(INFO_COLOR)Making OTLib...$(NO_COLOR)'
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS)  $(DYNAMIC_FLAG)

server_alone:
	@$(ECHO) '$(INFO_COLOR)Make OT Server$(NO_COLOR)'
	cd $(OT_SERVER_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ

server:
	@$(ECHO) '$(INFO_COLOR)Making OTLib...$(NO_COLOR)'
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS)
	@$(ECHO) '$(INFO_COLOR)Make OT Server$(NO_COLOR)'
	cd $(OT_SERVER_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ
	@$(ECHO) '$(INFO_COLOR)Making OT Tools...$(NO_COLOR)'
	$(EXTRA_RPC_TARGETS1)
	$(EXTRA_RPC_TARGETS2)

test_wallet:
	@$(ECHO) '$(INFO_COLOR)Making OTLib...$(NO_COLOR)'
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS)
	@$(ECHO) '$(INFO_COLOR)Make OT Server$(NO_COLOR)'
	cd $(OT_SERVER_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ
	@$(ECHO) '$(INFO_COLOR)Make TestWallet with ZMQ$(NO_COLOR)'
	cd $(TESTWALLET_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ
	@$(ECHO) '$(INFO_COLOR)Making OT Tools...$(NO_COLOR)'
	$(EXTRA_RPC_TARGETS1)
	$(EXTRA_RPC_TARGETS2)

lisp:
	@$(ECHO) '$(INFO_COLOR)Making OTLib...$(NO_COLOR)'
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS)  $(DYNAMIC_FLAG)
	@$(ECHO) '$(INFO_COLOR)Make OT Server$(NO_COLOR)'
	cd $(OT_SERVER_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ
	@$(ECHO) '$(ERROR_COLOR)Not Making Lisp API... Not-Implemented$(NO_COLOR)'
	@$(ECHO) '$(INFO_COLOR)Making OT Tools...$(NO_COLOR)'
	$(EXTRA_RPC_TARGETS1)
	$(EXTRA_RPC_TARGETS2)
#	@$(ECHO) '$(INFO_COLOR)Making Lisp API...$(NO_COLOR)'
#	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=lisp clean
#	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=lisp

csharp:
	@$(ECHO) '$(INFO_COLOR)Making OTLib...$(NO_COLOR)'
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS)  $(DYNAMIC_FLAG)
	@$(ECHO) '$(INFO_COLOR)Make OT Server$(NO_COLOR)'
	cd $(OT_SERVER_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ
	@$(ECHO) '$(INFO_COLOR)Making C-Sharp API...$(NO_COLOR)'
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=c clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=java clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=csharp clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=csharp
	@$(ECHO) '$(INFO_COLOR)Making OT Tools...$(NO_COLOR)'
	$(EXTRA_RPC_TARGETS1)
	$(EXTRA_RPC_TARGETS2)

d:
	@$(ECHO) '$(INFO_COLOR)Making OTLib...$(NO_COLOR)'
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS)  $(DYNAMIC_FLAG)
	@$(ECHO) '$(INFO_COLOR)Make OT Server$(NO_COLOR)'
	cd $(OT_SERVER_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ
	@$(ECHO) '$(ERROR_COLOR)Not Making D API... Not-Implemented$(NO_COLOR)'
	@$(ECHO) '$(INFO_COLOR)Making OT Tools...$(NO_COLOR)'
	$(EXTRA_RPC_TARGETS1)
	$(EXTRA_RPC_TARGETS2)
#	@$(ECHO) '$(INFO_COLOR)Making D API...$(NO_COLOR)'
#	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=d clean
#	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=d

java:
	@$(ECHO) '$(INFO_COLOR)Making OTLib...$(NO_COLOR)'
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS)  $(DYNAMIC_FLAG)
	@$(ECHO) '$(INFO_COLOR)Make OT Server$(NO_COLOR)'
	cd $(OT_SERVER_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ
	@$(ECHO) '$(INFO_COLOR)Making Java API...$(NO_COLOR)'
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=c clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=java clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=java
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=java installjava
	@$(ECHO) '$(INFO_COLOR)Making OT Tools...$(NO_COLOR)'
	$(EXTRA_RPC_TARGETS1)
	$(EXTRA_RPC_TARGETS2)

perl5:
	@$(ECHO) '$(INFO_COLOR)Making OTLib...$(NO_COLOR)'
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS)  $(DYNAMIC_FLAG)
	@$(ECHO) '$(INFO_COLOR)Make OT Server$(NO_COLOR)'
	cd $(OT_SERVER_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ
	@$(ECHO) '$(INFO_COLOR)Making Perl API...$(NO_COLOR)'
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=c clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=java clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=perl5 clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=perl5
	@$(ECHO) '$(INFO_COLOR)Making OT Tools...$(NO_COLOR)'
	$(EXTRA_RPC_TARGETS1)
	$(EXTRA_RPC_TARGETS2)

python:
	@$(ECHO) '$(INFO_COLOR)Making OTLib...$(NO_COLOR)'
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS)  $(DYNAMIC_FLAG)
	@$(ECHO) '$(INFO_COLOR)Make OT Server$(NO_COLOR)'
	cd $(OT_SERVER_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ
	@$(ECHO) '$(INFO_COLOR)Making Python API...$(NO_COLOR)'
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=c clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=ruby clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=java clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=python clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=python
	@$(ECHO) '$(INFO_COLOR)Making OT Tools...$(NO_COLOR)'
	$(EXTRA_RPC_TARGETS1)
	$(EXTRA_RPC_TARGETS2)

php5:
	@$(ECHO) '$(INFO_COLOR)Making OTLib...$(NO_COLOR)'
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS)  $(DYNAMIC_FLAG)
	@$(ECHO) '$(INFO_COLOR)Make OT Server$(NO_COLOR)'
	cd $(OT_SERVER_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ
	@$(ECHO) '$(INFO_COLOR)Making PHP API...$(NO_COLOR)'
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=c clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=php5 clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=python clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=ruby clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=java clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=php5
	@$(ECHO) '$(INFO_COLOR)Making OT Tools...$(NO_COLOR)'
	$(EXTRA_RPC_TARGETS1)
	$(EXTRA_RPC_TARGETS2)

ruby:
	@$(ECHO) '$(INFO_COLOR)Making OTLib...$(NO_COLOR)'
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS)  $(DYNAMIC_FLAG)
	@$(ECHO) '$(INFO_COLOR)Make OT Server$(NO_COLOR)'
	cd $(OT_SERVER_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ
	@$(ECHO) '$(INFO_COLOR)Making Ruby API...$(NO_COLOR)'
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=c clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=python clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=java clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=ruby clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=ruby
	@$(ECHO) '$(INFO_COLOR)Making OT Tools...$(NO_COLOR)'
	$(EXTRA_RPC_TARGETS1)
	$(EXTRA_RPC_TARGETS2)

tcl:
	@$(ECHO) '$(INFO_COLOR)Making OTLib...$(NO_COLOR)'
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS)  $(DYNAMIC_FLAG)
	@$(ECHO) '$(INFO_COLOR)Make OT Server$(NO_COLOR)'
	cd $(OT_SERVER_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ
	@$(ECHO) '$(INFO_COLOR)Making OT Tools...$(NO_COLOR)'
	$(EXTRA_RPC_TARGETS1)
	$(EXTRA_RPC_TARGETS2)
	@$(ECHO) '$(ERROR_COLOR)Not Making TCL API... Not-Implemented$(NO_COLOR)'
#	@$(ECHO) '$(INFO_COLOR)Making TCL API...$(NO_COLOR)'
#	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=tcl clean
#	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=tcl

c:
	@$(ECHO) '$(INFO_COLOR)Making OTLib...$(NO_COLOR)'
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS)  $(DYNAMIC_FLAG)
	@$(ECHO) '$(INFO_COLOR)Make OT Server$(NO_COLOR)'
	cd $(OT_SERVER_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ
	@$(ECHO) '$(INFO_COLOR)Making C API...$(NO_COLOR)'
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=c clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=java clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=c
	@$(ECHO) '$(INFO_COLOR)Making OT Tools...$(NO_COLOR)'
	$(EXTRA_RPC_TARGETS1)
	$(EXTRA_RPC_TARGETS2)

debug:
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS)  debug
	cd $(OT_SERVER_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ debug
	cd $(TESTWALLET_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS)   TRANSPORT=ZMQ debug
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=c debug
	$(EXTRA_DEBUGRPC_TARGETS1)
	$(EXTRA_DEBUGRPC_TARGETS2)

javadebug:
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS) $(DYNAMIC_FLAG) debug
	cd $(OT_SERVER_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ debug
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=c clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API $(DYNAMIC_FLAG) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=java clean
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API $(DYNAMIC_FLAG) PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) TRANSPORT=ZMQ LANGUAGE=java debug
	$(EXTRA_DEBUG_TARGETS1)
	$(EXTRA_DEBUG_TARGETS1)

tcp:
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS)   
	cd $(OT_SERVER_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS) 
	cd $(TESTWALLET_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS) 
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) LANGUAGE=c
	$(EXTRA_TARGETS1)
	$(EXTRA_TARGETS2)

debugtcp:
	cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS)  debug
	cd $(OT_SERVER_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS)  debug
	cd $(TESTWALLET_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS)  debug
	cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) LANGUAGE=c debug
	$(EXTRA_DEBUG_TARGETS1)
	$(EXTRA_DEBUG_TARGETS2)

install:
	mkdir -p $(EXECUTABLE_INSTALL_FOLDER)
	rm -f $(EXECUTABLE_INSTALL_FOLDER)/ot_server && cp ./transaction/transaction.exe $(EXECUTABLE_INSTALL_FOLDER)/ot_server
	rm -f $(EXECUTABLE_INSTALL_FOLDER)/ot &&  cp ./testwallet/testwallet.exe $(EXECUTABLE_INSTALL_FOLDER)/ot
	mkdir ~$(SUDO_USER)/.ot && cp -r ./ot-sample-data/* ~$(SUDO_USER)/.ot && chown -R $(SUDO_USER):$(SUDO_GROUP) ~$(SUDO_USER)/.ot
#
#	@$(ECHO) '$(OK_COLOR)Installing...$(NO_COLOR)'
#	@mkdir -p $(EXECUTABLE_INSTALL_FOLDER)
#	@$(ECHO) '$(INFO_COLOR)...OT Server (if compiled)$(NO_COLOR)'
#	@find $(OT_SERVER_DIR) -type f -wholename "*\transaction.exe" | sed 's~.*~rm -f "$(EXECUTABLE_INSTALL_FOLDER)/ot_server"~' 
#	@find $(OT_SERVER_DIR) -type f -wholename "*\transaction.exe" | sed 's~.*~rm -f "$(EXECUTABLE_INSTALL_FOLDER)/ot_server"~' | sh
#	@find $(OT_SERVER_DIR) -type f -wholename "*\transaction.exe" | sed 's~.*~cp "&" "$(EXECUTABLE_INSTALL_FOLDER)/ot_server"~'
#	@find $(OT_SERVER_DIR) -type f -wholename "*\transaction.exe" | sed 's~.*~cp "&" "$(EXECUTABLE_INSTALL_FOLDER)/ot_server"~' | sh
#	@find $(OT_SERVER_DIR) -type f -wholename "*\transaction.exe" | sed 's~.*~chown root:staff "$(EXECUTABLE_INSTALL_FOLDER)/ot_server"~'
#	@find $(OT_SERVER_DIR) -type f -wholename "*\transaction.exe" | sed 's~.*~chown root:staff "$(EXECUTABLE_INSTALL_FOLDER)/ot_server"~' | sh
#	@find $(OT_SERVER_DIR) -type f -wholename "*\transaction.exe" | sed 's~.*~chmod 775 "$(EXECUTABLE_INSTALL_FOLDER)/ot_server"~'
#	@find $(OT_SERVER_DIR) -type f -wholename "*\transaction.exe" | sed 's~.*~chmod 775 "$(EXECUTABLE_INSTALL_FOLDER)/ot_server"~' | sh
#	@$(ECHO) '$(INFO_COLOR)...OT TestWallet  (if compiled)$(NO_COLOR)'
#	@find $(TESTWALLET_DIR) -type f -wholename "*\testwallet.exe" | sed 's~.*~rm -f "$(EXECUTABLE_INSTALL_FOLDER)/ot"~' 
#	@find $(TESTWALLET_DIR) -type f -wholename "*\testwallet.exe" | sed 's~.*~rm -f "$(EXECUTABLE_INSTALL_FOLDER)/ot"~' | sh
#	@find $(TESTWALLET_DIR) -type f -wholename "*\testwallet.exe" | sed 's~.*~cp "&" "$(EXECUTABLE_INSTALL_FOLDER)/ot"~'
#	@find $(TESTWALLET_DIR) -type f -wholename "*\testwallet.exe" | sed 's~.*~cp "&" "$(EXECUTABLE_INSTALL_FOLDER)/ot"~' | sh
#	@find $(TESTWALLET_DIR) -type f -wholename "*\testwallet.exe" | sed 's~.*~chown root:staff "$(EXECUTABLE_INSTALL_FOLDER)/ot"~'
#	@find $(TESTWALLET_DIR) -type f -wholename "*\testwallet.exe" | sed 's~.*~chown root:staff "$(EXECUTABLE_INSTALL_FOLDER)/ot"~' | sh
#	@find $(TESTWALLET_DIR) -type f -wholename "*\testwallet.exe" | sed 's~.*~chmod 775 "$(EXECUTABLE_INSTALL_FOLDER)/ot"~'
#	@find $(TESTWALLET_DIR) -type f -wholename "*\testwallet.exe" | sed 's~.*~chmod 775 "$(EXECUTABLE_INSTALL_FOLDER)/ot"~' | sh
#	@$(ECHO) '$(INFO_COLOR)...libOTAPI (if compiled)$(NO_COLOR)'
#	@mkdir -p $(LIBRARY_INSTALL_FOLDER)
#	@cd $(TESTWALLET_DIR) && rm -f libotapi*.so.$(VERSION)
#	@cd $(TESTWALLET_DIR) && find ./ -type f -name "*\libotapi*.so" | sed 's~.*/~~' | sed 's~.*~rm -f "$(LIBRARY_INSTALL_FOLDER)/&" "$(LIBRARY_INSTALL_FOLDER)/&.$(MAJOR_VERSION)" "$(LIBRARY_INSTALL_FOLDER)/&.$(VERSION)"~'| sh
#	@cd $(TESTWALLET_DIR) && find ./ -type f -name "*\libotapi*.so" | sed 's~.*/~~' | sed 's~.*~cp "&" "&.$(VERSION)"~' | sh
#	@cd $(TESTWALLET_DIR) && find ./ -type f -name "*\libotapi*.so.$(VERSION)" | sed 's~.*/~~' | sed 's~.*~mv "&" "$(LIBRARY_INSTALL_FOLDER)/&"~'| sh
#	@cd $(LIBRARY_INSTALL_FOLDER) && find $(TESTWALLET_DIR) -type f -name "*\libotapi*.so" | sed 's~.*/~~' | sed -E 's~^([^\.]+)\..*~ln -s "&.$(VERSION)" "\1.so.$(MAJOR_VERSION)"~' | sh
#	@cd $(LIBRARY_INSTALL_FOLDER) && find $(TESTWALLET_DIR) -type f -name "*\libotapi*.so" | sed 's~.*/~~' | sed -E 's~^([^\.]+)\..*~ln -s "&.$(MAJOR_VERSION)" "\1.so"~' | sh
#	@cd $(LIBRARY_INSTALL_FOLDER) && find $(TESTWALLET_DIR) -type f -name "*\libotapi*.so" | sed 's~.*/~~' | sed 's~.*~chown root:staff "&" "&.$(MAJOR_VERSION)" "&.$(VERSION)"~' | sh
#	@cd $(LIBRARY_INSTALL_FOLDER) && find $(TESTWALLET_DIR) -type f -name "*\libotapi*.so" | sed 's~.*/~~' | sed 's~.*~chmod 664 "&" "&.$(MAJOR_VERSION)" "&.$(VERSION)"~' | sh
#	@ldconfig -n -v $(LIBRARY_INSTALL_FOLDER)
#	@$(ECHO) '$(OK_COLOR)Done!$(NO_COLOR)'

local:
	@$(ECHO) '$(INFO_COLOR)Installing Local User Data$(NO_COLOR)'
	mkdir ~/.ot && cp -r ./ot-sample-data/* ~/.ot && chown -R $(USER) ~/.ot
	@$(ECHO) '$(INFO_COLOR)Done!$(NO_COLOR)'

uninstall:
	rm -f $(EXECUTABLE_INSTALL_FOLDER)/ot_server
	rm -f $(EXECUTABLE_INSTALL_FOLDER)/ot
	rm -f ~/$(SUDO_USER)_OT_BACKUP_2.tgz
	touch ~/$(SUDO_USER)_OT_BACKUP.tgz
	mv ~/$(SUDO_USER)_OT_BACKUP.tgz ~/$(SUDO_USER)_OT_BACKUP_2.tgz
	tar -czvf ~/$(SUDO_USER)_OT_BACKUP.tgz ~/.ot
	rm -rf ~/.ot
#	@$(ECHO) '$(INFO_COLOR)Cleaning Instaled Binaries$(NO_COLOR)'
#	cd $(EXECUTABLE_INSTALL_FOLDER) && rm -f ot_server ot
#	cd $(LIBRARY_INSTALL_FOLDER) && rm -f *libotapi*.so*
#	@$(ECHO) '$(INFO_COLOR)Done!$(NO_COLOR)'

remove_local:
	@$(ECHO) '$(ERROR_COLOR)Skiping Removing User Data... Not-Implemented$(NO_COLOR)'
#	@$(ECHO) '$(INFO_COLOR)Removing User Data$(NO_COLOR)'
#	rm -f ~/$(SUDO_USER)_OT_BACKUP_2.tgz
#	touch ~/$(SUDO_USER)_OT_BACKUP.tgz
#	mv ~/$(SUDO_USER)_OT_BACKUP.tgz ~/$(SUDO_USER)_OT_BACKUP_2.tgz
#	tar -czvf ~/$(SUDO_USER)_OT_BACKUP.tgz ~/.ot
#	rm -rf ~/.ot

clean:
	@$(ECHO) '$(INFO_COLOR)Cleaning OT Source...$(NO_COLOR)'
	@cd OTLib && $(OT_MAKE_PLATFORM_INC_LIBS)  clean
	@cd $(OT_SERVER_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS)  clean
	@cd $(OT_SERVER_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ clean
	@cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) LANGUAGE=lisp clean
	@cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) LANGUAGE=csharp clean
	@cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) LANGUAGE=d clean
	@cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) LANGUAGE=java clean
	@cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) LANGUAGE=perl5 clean
	@cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) LANGUAGE=python clean
	@cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) LANGUAGE=php5 clean
	@cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) LANGUAGE=ruby clean
	@cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) LANGUAGE=tlc clean
	@cd $(TESTWALLET_DIR) && $(OT_MAKE) -f Makefile.API PLATFORM=$(OT_PLATFORM) $(OT_SSL_INCLUDE_AND_LIBS) LANGUAGE=c clean
	@cd $(TESTWALLET_DIR) && rm -f *.so*
	@cd $(TESTWALLET_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS)  clean
	@cd $(TESTWALLET_DIR) && $(OT_MAKE_PLATFORM_INC_LIBS)  TRANSPORT=ZMQ clean
	@$(EXTRA_CLEAN_TARGETS1)
	@$(EXTRA_CLEAN_TARGETS2)
	@$(ECHO) '$(INFO_COLOR)Done!$(NO_COLOR)'
