#
# OTLib
#
# Open Transactions by Fellow Traveler
#
# This is the Open Transactions library itself, minus the API and socket code
# (those can be found in the OTAPI library, which must be linked with this one.)
#
# See copyright notice that came with this distribution.
# Distributed as open-source under the AGPL.

OTLIB_PATH := $(call my-dir)
 
# OpenSSL 0.9.8
OPENSSL_MAKE := external/openssl/Android.mk
OPENSSL_DIR := external/openssl
OPENSSL_INCLUDE_DIR := external/openssl/include

# OpenSSL 1.0.0a
#OPENSSL_MAKE := sources/openssl/Android.mk
#OPENSSL_DIR := sources/openssl
#OPENSSL_INCLUDE_DIR := sources/openssl/include

include $(OPENSSL_MAKE)

include $(CLEAR_VARS)

LOCAL_PATH := $(OTLIB_PATH)

LOCAL_MODULE    := libOTLib

LOCAL_C_INCLUDES += $(OPENSSL_DIR) $(OPENSSL_INCLUDE_DIR) $(LOCAL_PATH) $(LOCAL_PATH)/irrxml $(LOCAL_PATH)/Lucre

LOCAL_SRC_FILES := easyzlib.c Lucre/bankimp.cpp irrxml/irrXML.cpp OTData.cpp OTString.cpp OTStringXML.cpp OTASCIIArmor.cpp OTContract.cpp OTWallet.cpp OTSignedFile.cpp OTPseudonym.cpp OTMint.cpp OTInstrument.cpp OTCheque.cpp OTPurse.cpp OTToken.cpp OTTransactionType.cpp OTItem.cpp OTBasket.cpp OTTransaction.cpp OTLedger.cpp OTAccount.cpp OTEnvelope.cpp OTAssetContract.cpp OTServerContract.cpp OTPayload.cpp OTMessage.cpp OTMessageBuffer.cpp OTIdentifier.cpp OTAsymmetricKey.cpp OTSignature.cpp OTDataCheck.cpp OTLog.cpp OTOffer.cpp OTAgreement.cpp OTTrackable.cpp OTCron.cpp OTCronItem.cpp OTTrade.cpp OTPaymentPlan.cpp OTMarket.cpp

LOCAL_LDLIBS += -ldl -lz -llog

LOCAL_STATIC_LIBRARIES := libssl libcrypto

include $(BUILD_STATIC_LIBRARY)
