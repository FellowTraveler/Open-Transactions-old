# -*- fill-column: 72 -*-
AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = -I build-aux/m4
EXTRA_DIST = docs/GETTING-STARTED.txt docs/INSTALL-Android.txt		\
             docs/INSTALL-Fedora.txt docs/INSTALL-Ubuntu.txt		\
             docs/INSTALL-OSX-Homebrew.txt docs/INSTALL-Windows.txt	\
             docs/LICENSE-AND-CREDITS.txt PUBKEY-FellowTraveler.asc	\
             README.md docs/SSL-NOTES.txt docs/WIPE-USERS-ACCOUNTS.txt	\
             VERSION
otincdir = $(top_srcdir)/include
common_includes = -I$(otincdir) -I$(otincdir)/otlib -I$(otincdir)/simpleini
lib_LTLIBRARIES = libOTLib.la
bin_PROGRAMS = ot ot_server otcreatemint signcontract
AM_CPPFLAGS = $(DEPS_CFLAGS) $(BOOST_CPPFLAGS)
libOTLib_la_CPPFLAGS = $(common_includes) -I$(otincdir)/bigint	\
                       -I$(otincdir)/lucre -I$(otincdir)/irrxml
libOTLib_la_LIBADD = $(DEPS_LIBS) $(BOOST_LDFLAGS) $(BOOST_THREAD_LIB)
client_ldadd = $(DEPS_LIBS) libOTLib.la $(BOOST_LDFLAGS) $(BOOST_THREAD_LIB)
ot_CPPFLAGS = $(common_includes) -I$(otincdir)/otapi -I$(otincdir)/ssl-example
ot_LDADD = $(client_ldadd)
ot_server_CPPFLAGS = $(common_includes) -I$(otincdir)/otserver	\
                     -I$(otincdir)/ssl-example
ot_server_LDADD = $(client_ldadd)
otcreatemint_CPPFLAGS = $(common_includes)
otcreatemint_LDADD = $(client_ldadd)
signcontract_CPPFLAGS = $(common_includes)
signcontract_LDADD = $(client_ldadd)
if TRANSPORT_ZMQ
transport_client_api = src/otapi/xmlrpcxx_client.cpp
transport_server_api = src/otserver/xmlrpcxx_server.cpp
ot_CXXFLAGS = -DOT_ZMQ_MODE
endif

if TRANSPORT_TESTCLIENT
transport_client_api = src/otapi/testclient.cpp
transport_server_api = src/otserver/testserver.cpp
endif

ot_SOURCES = src/otapi/OpenTransactions.cpp src/otapi/OTAPI.cpp		\
             src/otapi/OTAPI_Wrapper.cpp				\
             src/otapi/OTServerConnection.cpp src/otapi/OTClient.cpp	\
             src/ssl-example/SFSocket.c $(transport_client_api)

EXTRA_ot_SOURCES = src/otapi/xmlrpcxx_client.cpp	\
                   src/otapi/testclient.cpp

ot_server_SOURCES = src/otserver/OTClientConnection.cpp			\
                    src/otserver/OTServer.cpp				\
                    src/ssl-example/SFSocket.c $(transport_server_api)

EXTRA_ot_server_SOURCES = src/otserver/xmlrpcxx_server.cpp	\
                          src/otserver/testserver.cpp

otcreatemint_SOURCES = util/otcreatemint/main.cpp
signcontract_SOURCES = util/signcontract/main.cpp

bigintsources = src/bigint/BigUnsigned.cc src/bigint/BigInteger.cc	\
                src/bigint/BigIntegerAlgorithms.cc			\
                src/bigint/BigUnsignedInABase.cc			\
                src/bigint/BigIntegerUtils.cc

lucresources = src/lucre/bankimp.cpp
irrxmlsources = src/irrxml/irrXML.cpp

libOTLib_la_SOURCES = $(bigintsources) $(lucresources) $(irrxmlsources)	\
                      src/otlib/OTData.cpp src/otlib/OTString.cpp		\
                      src/otlib/OTStringXML.cpp src/otlib/OTASCIIArmor.cpp	\
                      src/otlib/OTContract.cpp src/otlib/OTSmartContract.cpp	\
                      src/otlib/OTWallet.cpp src/otlib/OTSignedFile.cpp		\
                      src/otlib/OTPseudonym.cpp src/otlib/OTMint.cpp		\
                      src/otlib/OTInstrument.cpp src/otlib/OTCheque.cpp		\
                      src/otlib/OTPurse.cpp src/otlib/OTLog.cpp			\
                      src/otlib/OTToken.cpp src/otlib/OTTransactionType.cpp	\
                      src/otlib/OTItem.cpp src/otlib/OTBasket.cpp		\
                      src/otlib/OTTransaction.cpp src/otlib/OTLedger.cpp	\
                      src/otlib/OTAccount.cpp src/otlib/OTEnvelope.cpp		\
                      src/otlib/OTAssetContract.cpp				\
                      src/otlib/OTServerContract.cpp src/otlib/OTOffer.cpp	\
                      src/otlib/OTAgreement.cpp src/otlib/OTTrackable.cpp	\
                      src/otlib/OTCron.cpp src/otlib/OTCronItem.cpp		\
                      src/otlib/OTTrade.cpp src/otlib/OTPaymentPlan.cpp		\
                      src/otlib/OTMarket.cpp src/otlib/OTPayload.cpp		\
                      src/otlib/OTMessage.cpp src/otlib/OTMessageBuffer.cpp	\
                      src/otlib/OTIdentifier.cpp src/otlib/OTAsymmetricKey.cpp	\
                      src/otlib/OTSignature.cpp src/otlib/OTScript.cpp		\
                      src/otlib/OTScriptable.cpp src/otlib/OTBylaw.cpp		\
                      src/otlib/OTStorage.cpp src/otlib/OTDataCheck.cpp		\
                      src/otlib/Generics.pb.cpp src/otlib/Markets.pb.cpp	\
                      src/otlib/Bitcoin.pb.cpp src/otlib/Moneychanger.pb.cpp	\
                      src/otlib/anyoption.cpp src/otlib/Timer.cpp		\
                      src/otlib/OTPassword.cpp					\
                      src/otlib/easyzlib.c src/otlib/mkcert.c			\
                      src/simpleini/ConvertUTF.c

if WANT_JAVA
lib_LTLIBRARIES += libotapi.jnilib.la
endif

libotapi_jnilib_la_SOURCES = $(ot_SOURCES) swig/otapi/OTAPI_java.cxx
libotapi_jnilib_la_CPPFLAGS = $(common_includes) -I$(otincdir)/otapi -I$(otincdir)/ssl-example $(JNI_CPPFLAGS)
libotapi_jnilib_la_CXXFLAGS = -DOT_ZMQ_MODE
include_HEADERS = include/irrxml/CXMLReaderImpl.h			\
                  include/irrxml/fast_atof.h include/irrxml/heapsort.h	\
                  include/irrxml/irrArray.h include/irrxml/irrString.h	\
                  include/irrxml/irrTypes.h include/irrxml/irrXML.h	\
                  include/lucre/bank.h include/otapi/main.h		\
                  include/otapi/OpenTransactions.h			\
                  include/otapi/OTAPI_funcdef.h include/otapi/OTAPI.h	\
                  swig/otapi/OTAPI_csharp.h swig/otapi/OTAPI_java.h	\
                  swig/otapi/OTAPI_php.h swig/otapi/OTAPI_python.h	\
                  swig/otapi/OTAPI_ruby.h include/otapi/OTAPI_Wrapper.h	\
                  include/otapi/OTClient.h				\
                  include/otapi/OTServerConnection.h			\
                  include/otlib/anyoption.h include/otlib/inttypes.h	\
                  include/otlib/Bitcoin.pb.h include/otlib/easyzlib.h	\
                  include/otlib/Generics.pb.h				\
                  include/otlib/Markets.pb.h				\
                  include/otlib/Moneychanger.pb.h			\
                  include/otlib/OTAccount.h include/otlib/OTAgreement.h	\
                  include/otlib/OTASCIIArmor.h				\
                  include/otlib/OTAssetContract.h			\
                  include/otlib/OTAsymmetricKey.h			\
                  include/otlib/OTBasket.h include/otlib/OTBylaw.h	\
                  include/otlib/OTCheque.h include/otlib/OTContract.h	\
                  include/otlib/OTCron.h include/otlib/OTCronItem.h	\
                  include/otlib/OTDataCheck.h include/otlib/OTData.h	\
                  include/otlib/OTEnvelope.h include/otlib/OTglobal.h	\
                  include/otlib/OTIdentifier.h				\
                  include/otlib/OTInstrument.h include/otlib/OTItem.h	\
                  include/otlib/OTLedger.h include/otlib/OTLib.h	\
                  include/otlib/OTLibPriv.h include/otlib/OTLog.h	\
                  include/otlib/OTMarket.h				\
                  include/otlib/OTMessageBuffer.h			\
                  include/otlib/OTMessage.h include/otlib/OTMint.h	\
                  include/otlib/OTOffer.h include/otlib/OTPayload.h	\
                  include/otlib/OTPaymentPlan.h				\
                  include/otlib/OTPseudonym.h include/otlib/OTPurse.h	\
                  include/otlib/OTPassword.h				\
                  include/otlib/OTScriptable.h include/otlib/OTScript.h	\
                  include/otlib/OTServerContract.h			\
                  include/otlib/OTSignature.h				\
                  include/otlib/OTSignedFile.h				\
                  include/otlib/OTSmartContract.h			\
                  include/otlib/OTStorage.h include/otlib/OTString.h	\
                  include/otlib/OTStringXML.h include/otlib/OTToken.h	\
                  include/otlib/OTTrackable.h include/otlib/OTTrade.h	\
                  include/otlib/OTTransaction.h				\
                  include/otlib/OTTransactionType.h			\
                  include/otlib/OTWallet.h include/otlib/stacktrace.h	\
                  include/otlib/Timer.h include/otserver/main.h		\
                  include/otserver/OTClientConnection.h			\
                  include/otserver/OTServer.h				\
                  include/simpleini/ConvertUTF.h			\
                  include/simpleini/SimpleIni.h				\
                  include/ssl-example/SFSocket.h			\
                  include/bigint/BigUnsigned.h				\
                  include/bigint/BigInteger.h				\
                  include/bigint/BigUnsignedInABase.h			\
                  include/bigint/BigIntegerUtils.h			\
                  include/bigint/BigIntegerLibrary.h			\
                  include/bigint/NumberlikeArray.h			\
                  include/bigint/BigIntegerAlgorithms.h			\
                  include/irrxml/irrXML.h include/lucre/bank.h          \
                  include/containers/simple_ptr.hpp                     \
                  include/containers/simple_ptr.tpp                     \
                  include/containers/containers_fixes.hpp               \
                  include/containers/exceptions.hpp                     \
                  include/containers/copy_functors.hpp

