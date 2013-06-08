SUBDIRS = otprotob bigint irrxml lucre

lib_LTLIBRARIES		=	libot.la

opentxs_include_dir =		$(top_srcdir)/include
opentxs_source_dir =		$(top_srcdir)/src

## COMMON FLAGS ###

common_includes		=	-I$(opentxs_include_dir)		\
				-I$(opentxs_include_dir)/otlib		\
				-I$(opentxs_include_dir)/containers	\
				$(DEPS_CFLAGS)				\
				-DOT_PREFIX_PATH="\"${prefix}\""	\
				-DOT_VERSION="\"${VERSION}\""


AM_CPPFLAGS		= 	$(AC_CXXFLAGS)
AM_CXXFLAGS		=	$(AC_CXXFLAGS)

#### Lib OT build calls

libot_la_SOURCES	=	$(otlib_sources)		\
				$(otlib_headers)		\
				$(containers_headers)

libot_la_CPPFLAGS	=	$(common_includes)

libot_la_LIBADD		=	bigint/libbigint.la		\
				irrxml/libirrxml.la		\
				lucre/liblucre.la		\
				otprotob/libotprotob.la		\
				$(DEPS_LIBS)

libot_la_DEPENDENCIES	=	bigint/libbigint.la		\
				irrxml/libirrxml.la		\
				lucre/liblucre.la		\
				otprotob/libotprotob.la

libot_la_LDFLAGS	=	--no-undefined


#### KEYRING Options

if KEYRING_WINDOWS
libot_la_CPPFLAGS		+=	-DOT_KEYRING_WINDOWS
endif

if KEYRING_MAC
libot_la_CPPFLAGS		+=	-DOT_KEYRING_MAC
endif

if KEYRING_GNOME
libot_la_CPPFLAGS		+=	-DOT_KEYRING_GNOME
endif

if KEYRING_KWALLET
libot_la_CPPFLAGS		+=	-DOT_KEYRING_KWALLET
endif

####################################################################

otlib_sources_dir = 		$(opentxs_source_dir)/otlib

otlib_sources     =		easyzlib.c			\
				mkcert.c			\
				anyoption.cpp			\
				tinythread.cpp			\
				Timer.cpp			\
				OTAccount.cpp			\
				OTAgreement.cpp			\
				OTASCIIArmor.cpp		\
				OTAssetContract.cpp		\
				OTAsymmetricKey.cpp		\
				OTBasket.cpp			\
				OTBylaw.cpp			\
				OTCachedKey.cpp			\
				OTCheque.cpp			\
				OTContract.cpp			\
				OTCredential.cpp		\
				OTCron.cpp			\
				OTCronItem.cpp			\
				OTCrypto.cpp			\
				OTData.cpp			\
				OTDataCheck.cpp			\
				OTDigitalCash.cpp		\
				OTEnvelope.cpp			\
				OTKeyring.cpp			\
				OTIdentifier.cpp		\
				OTInstrument.cpp		\
				OTItem.cpp			\
				OTLedger.cpp			\
				OTLog.cpp			\
				OTMarket.cpp			\
				OTMessage.cpp			\
				OTMessageBuffer.cpp		\
				OTMint.cpp			\
				OTOffer.cpp			\
				OTPassword.cpp			\
				OTPaths.cpp			\
				OTPayload.cpp			\
				OTPayment.cpp			\
				OTPaymentPlan.cpp		\
				OTPseudonym.cpp			\
				OTPurse.cpp			\
				OTScript.cpp			\
				OTScriptable.cpp		\
				OTServerContract.cpp		\
				OTSettings.cpp			\
				OTSignature.cpp			\
				OTSignedFile.cpp		\
				OTSmartContract.cpp		\
				OTStorage.cpp			\
				OTString.cpp			\
				OTStringXML.cpp			\
				OTSymmetricKey.cpp		\
				OTToken.cpp			\
				OTTrackable.cpp			\
				OTTrade.cpp			\
				OTTransaction.cpp		\
				OTTransactionType.cpp		\
				OTWallet.cpp

otlib_headers_dir	=	$(opentxs_include_dir)/otlib

otlib_headers		=	$(otlib_headers_dir)/anyoption.h		\
				$(otlib_headers_dir)/fast_mutex.h		\
				$(otlib_headers_dir)/ExportWrapper.h		\
				$(otlib_headers_dir)/WinsockWrapper.h		\
				$(otlib_headers_ext)

otlib_headers_ext	=	$(otlib_headers_dir)/constants.h		\
				$(otlib_headers_dir)/easyzlib.h			\
				$(otlib_headers_dir)/stacktrace.h		\
				$(otlib_headers_dir)/Timer.h			\
				$(otlib_headers_dir)/tinythread.h		\
				$(otlib_headers_dir)/OTAccount.h		\
				$(otlib_headers_dir)/OTAgreement.h		\
				$(otlib_headers_dir)/OTASCIIArmor.h		\
				$(otlib_headers_dir)/OTAssetContract.h		\
				$(otlib_headers_dir)/OTAsymmetricKey.h		\
				$(otlib_headers_dir)/OTBasket.h			\
				$(otlib_headers_dir)/OTBylaw.h			\
				$(otlib_headers_dir)/OTCachedKey.h		\
				$(otlib_headers_dir)/OTCheque.h			\
				$(otlib_headers_dir)/OTContract.h		\
				$(otlib_headers_dir)/OTCredential.h		\
				$(otlib_headers_dir)/OTCron.h			\
				$(otlib_headers_dir)/OTCronItem.h		\
				$(otlib_headers_dir)/OTCrypto.h         	\
				$(otlib_headers_dir)/OTData.h			\
				$(otlib_headers_dir)/OTDataCheck.h		\
				$(otlib_headers_dir)/OTDigitalCash.h		\
				$(otlib_headers_dir)/OTEnvelope.h		\
				$(otlib_headers_dir)/OTKeyring.h		\
				$(otlib_headers_dir)/OTglobal.h			\
				$(otlib_headers_dir)/OTIdentifier.h		\
				$(otlib_headers_dir)/OTInstrument.h		\
				$(otlib_headers_dir)/OTItem.h			\
				$(otlib_headers_dir)/OTLedger.h			\
				$(otlib_headers_dir)/OTLib.h			\
				$(otlib_headers_dir)/OTLibPriv.h		\
				$(otlib_headers_dir)/OTLog.h			\
				$(otlib_headers_dir)/OTMarket.h			\
				$(otlib_headers_dir)/OTMessage.h		\
				$(otlib_headers_dir)/OTMessageBuffer.h		\
				$(otlib_headers_dir)/OTMint.h			\
				$(otlib_headers_dir)/OTOffer.h			\
				$(otlib_headers_dir)/OTPassword.h		\
				$(otlib_headers_dir)/OTPaths.h			\
				$(otlib_headers_dir)/OTPayload.h		\
				$(otlib_headers_dir)/OTPayment.h		\
				$(otlib_headers_dir)/OTPaymentPlan.h		\
				$(otlib_headers_dir)/OTPseudonym.h		\
				$(otlib_headers_dir)/OTPurse.h			\
				$(otlib_headers_dir)/OTScript.h			\
				$(otlib_headers_dir)/OTScriptable.h		\
				$(otlib_headers_dir)/OTServerContract.h		\
				$(otlib_headers_dir)/OTSettings.h		\
				$(otlib_headers_dir)/OTSignature.h		\
				$(otlib_headers_dir)/OTSignedFile.h		\
				$(otlib_headers_dir)/OTSmartContract.h		\
				$(otlib_headers_dir)/OTStorage.h		\
				$(otlib_headers_dir)/OTString.h			\
				$(otlib_headers_dir)/OTStringXML.h		\
				$(otlib_headers_dir)/OTSymmetricKey.h		\
				$(otlib_headers_dir)/OTToken.h			\
				$(otlib_headers_dir)/OTTrackable.h		\
				$(otlib_headers_dir)/OTTrade.h			\
				$(otlib_headers_dir)/OTTransaction.h		\
				$(otlib_headers_dir)/OTTransactionType.h	\
				$(otlib_headers_dir)/OTWallet.h

####	Global Headers for dist.

pkginclude_HEADERS	=	$(otlib_headers_ext)

####

####   Containers

containers_headers_dir	=	$(opentxs_include_dir)/containers

containers_headers 	=	$(containers_headers_dir)/containers.hpp	\
				$(containers_headers_dir)/containers_fixes.hpp	\
				$(containers_headers_dir)/copy_functors.hpp	\
				$(containers_headers_dir)/digraph.hpp		\
				$(containers_headers_dir)/digraph.tpp		\
				$(containers_headers_dir)/exceptions.hpp	\
				$(containers_headers_dir)/foursome.hpp		\
				$(containers_headers_dir)/foursome.tpp		\
				$(containers_headers_dir)/hash.hpp		\
				$(containers_headers_dir)/hash.tpp		\
				$(containers_headers_dir)/matrix.hpp		\
				$(containers_headers_dir)/matrix.tpp		\
				$(containers_headers_dir)/ntree.hpp		\
				$(containers_headers_dir)/ntree.tpp		\
				$(containers_headers_dir)/safe_iterator.hpp	\
				$(containers_headers_dir)/safe_iterator.tpp	\
				$(containers_headers_dir)/simple_ptr.hpp	\
				$(containers_headers_dir)/simple_ptr.tpp	\
				$(containers_headers_dir)/smart_ptr.hpp		\
				$(containers_headers_dir)/smart_ptr.tpp		\
				$(containers_headers_dir)/triple.hpp		\
				$(containers_headers_dir)/triple.tpp

