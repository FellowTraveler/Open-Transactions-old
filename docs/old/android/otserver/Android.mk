#
# OTAPI
#
# Open Transactions by Fellow Traveler
#
# This is the high-level API and socket code. The rest of the Open Transactions lib
# is found in OTLib, which must be linked with this one (for this one to work.)
#
# See copyright notice that came with this distribution.
# Distributed as open-source under the AGPL.

OTAPI_PATH := $(call my-dir)

# OpenSSL 0.9.8
OPENSSL_DIR := external/openssl
OPENSSL_INCLUDE_DIR := external/openssl/include

# OpenSSL 1.0.0a
#OPENSSL_DIR := sources/openssl
#OPENSSL_INCLUDE_DIR := sources/openssl/include

OTLIB_DIR := sources/Open-Transactions/OTLib

include $(CLEAR_VARS)

LOCAL_PATH := $(OTAPI_PATH)

LOCAL_MODULE    := libOTAPI

LOCAL_LDLIBS += -ldl -lz -llog

LOCAL_C_INCLUDES += $(OPENSSL_DIR) $(OPENSSL_INCLUDE_DIR) $(OTLIB_DIR) $(LOCAL_PATH) $(LOCAL_PATH)/SSL-Example

LOCAL_SRC_FILES := SSL-Example/SFSocket.c OTServerConnection.cpp OTClient.cpp OpenTransactions.cpp OTAPI.cpp OTAPI_java.c

LOCAL_STATIC_LIBRARIES := libssl libcrypto libOTLib libssl libcrypto libOTLib libssl libcrypto 

include $(BUILD_SHARED_LIBRARY)
