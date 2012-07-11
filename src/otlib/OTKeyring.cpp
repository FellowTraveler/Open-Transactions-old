/*************************************************************
 *    
 *  OTKeyring.cpp
 *  
 *  Mac has Keychain, Windows has DPAPI, Linux has Gnome-
 *  Keyring, KWallet, etc. The purpose of this class is to
 *  provide a simple, unified, cross-platform interface to
 *  all of them.
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA256
 
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, and GUI 
 *    
 *    	 -- Anonymous Numbered Accounts.
 *    	 -- Untraceable Digital Cash.
 *    	 -- Triple-Signed Receipts.
 *    	 -- Cheques, Vouchers, Transfers, Inboxes.
 *    	 -- Basket Currencies, Markets, Payment Plans.
 *    	 -- Signed, XML, Ricardian-style Contracts.
 *    
 *  Copyright (C) 2010-2012 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *  
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki 
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *    
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- OTLib.........A class library.......LICENSE:...LAGPLv3 
 *   -- OT-API........A client API..........LICENSE:...LAGPLv3
 *   -- testwallet....Command-line client...LICENSE:...LAGPLv3
 *   -- OT-Server.....Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (livewire_3001@yahoo.com).
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *    
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT-API, then you
 *   don't have to open-source your code--only your changes to
 *   Open Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open Transactions terms remain respected, with regard to
 *   the Open Transactions code itself.
 *    
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/OTLib/Lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *   
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.
 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.11 (Darwin)
 
 iQIcBAEBCAAGBQJOjvvUAAoJEAMIAO35UbuOBlMP/1LX0xJ9CrTOe1G/mgc+VygT
 JPVZDAbQDL/lJXOZMbaPJ/GaLXyEnTViHp97ERrlVuBQz+9uonIKCmPqAGYGVBG1
 MGV2QcscXU2aOUT1VPf2OYEOIul0h8FX2lixfqouH9/OkVsGRLr79Zu8z3zdsO4R
 ktQtjZEU6lnL2t6cmp/cuXlQnbz1xvxd56xNDR11YP07Z4x+CuDB4EAK+P9TfCwn
 tqq5yJmxJM9HtMoi3cUU7kXodKm1n1YZt7O46DOxHqbXqErHChN1ekSK0fXad614
 Gmh+5JfvHjx5XoFWMxb46aAAcUiG8+QpFBcKtSYP2X96k1ylgxMCzrK60ec/MxKV
 BzvP00OJ6PzzrTlcUaCgJ8ZX+0scOMvW0XKioEorozKSWNFvT4Drc4Thhy8u9ET3
 ru1enNFrjdxKjw2+ZTQcKSZjSRx2kMQ2od/dkqUlhe/M1cHGhseH6ls7pItrkykE
 ufZ9GlZoxYE+FRatIBPneT9WwsvFFvH+i6cQ/MM9pbTr19g6VPzVZ4U9E65BbTDB
 czITynH+uMtJLbprtCdQlsI+vqTgYNoY8AUsmnr1qUkp020qGlvwfCJVrooisTmm
 yIh+Yp/KBzySU3inzclaAfv102/t5xi1l+GTyWHiwZxlyt5PBVglKWx/Ust9CIvN
 6h9BYZFTZrh/OwBXCdAv
 =MUfS
 -----END PGP SIGNATURE-----
 **************************************************************/


#ifdef _WIN32
#include <WinsockWrapper.h>
#endif
// -------------------------------------------------------

#include <string>

// ***************************************************************
#if defined(OT_KEYRING_WINDOWS) && defined(_WIN32)
//
// Windows DPAPI
//

#include <cstdio>
extern "C"
{
//#include <stdio.h>
#include <wincrypt.h>
//#define MY_ENCODING_TYPE  (PKCS_7_ASN_ENCODING | X509_ASN_ENCODING)
}

#pragma comment(lib, "crypt32.lib")

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#elif defined(OT_KEYRING_MAC) && defined(__APPLE__)

//
// Mac Keychain
//

#import <Security/Security.h>


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#elif defined (OT_KEYRING_GNOME)
//
// Gnome Keyring
//
extern "C"
{
// "Try: sudo apt-get install libgnome-keyring-dev"
// http://nullroute.eu.org/~grawity/gnome-keyring-autologin.html
// http://harpreet.in/blog/2009/11/30/how-to-unlock-gnome-keyring-automatically/
// http://askubuntu.com/questions/38326/automatic-unlocking-of-keyring
    
#include <gnome-keyring.h>
#include <glib.h>    
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// KDE / KWallet
//
#elif defined (OT_KEYRING_KWALLET)

#include <glib.h>

#ifndef G_GNUC_NULL_TERMINATED
# if __GNUC__ >= 4
#  define G_GNUC_NULL_TERMINATED __attribute__((__sentinel__))
# else
#  define G_GNUC_NULL_TERMINATED
# endif
#endif

#include <kapplication.h>
#include <kaboutdata.h>
#include <kcmdlineargs.h>
#include <kwallet.h>
#include <klocale.h>

// For KWallet, must be compiled with g++, not gcc.
// Requries the header locations for KDE and Qt.
// They are commonly in:
//  /usr/include/kde
//  /usr/lib/qt-3.3/include
// This plugin must link to lkwalletclient.
// When compiling, use the following flags (for example):
//  CC=g++ \
//  CFLAGS="-I/usr/include/kde -I/usr/lib/qt-3.3/include" \
//  LDFLAGS="-lkwalletclient" \
//  kwallet_password.so

#endif
// ***************************************************************


// OPEN-TRANSACTIONS HEADERS...


#include "OTStorage.h"

#include "OTString.h"
#include "OTASCIIArmor.h"
#include "OTEnvelope.h"
#include "OTAsymmetricKey.h"

#include "OTKeyring.h"

#include "OTLog.h"


// ***************************************************************
#if defined(OT_KEYRING_WINDOWS) && defined(_WIN32)

//
// Windows DPAPI
//

//static 
bool OTKeyring::Windows_StoreSecret(const OTString    & strUser, 
                                    const OTPassword  & thePassword,
                                    const std::string & str_display)
{
    OT_ASSERT(strUser.Exists());
    OT_ASSERT(thePassword.getMemorySize() > 0);
    // -----------------------------------------
    const char * szFunc = "OTKeyring::Windows_StoreSecret";
    // ----------------------------------------    
    DATA_BLOB input;
    input.pbData = const_cast<BYTE*>(
                      reinterpret_cast<const BYTE*>(thePassword.getMemory()));
    input.cbData = static_cast<DWORD>(thePassword.getMemorySize());
    // ----------------------------------------
//    CRYPTPROTECT_PROMPTSTRUCT PromptStruct;
//    ZeroMemory(&PromptStruct, sizeof(PromptStruct));
//    PromptStruct.cbSize = sizeof(PromptStruct);
//    PromptStruct.dwPromptFlags = CRYPTPROTECT_PROMPT_ON_PROTECT;
//    PromptStruct.szPrompt = L"This is a user prompt.";
    
    DATA_BLOB output;
    
    BOOL result = CryptProtectData(&input, L"", // description string
                                   NULL, // optional entropy
                                   NULL, // reserved
                                   NULL, //&PromptStruct
                                   0, &output);
    if (!result)
    {
        OTLog::vError("%s: Failed calling Win32: CryptProtectData \n", szFunc);
        return false;
    }
    // ----------------------------------------
    //
    // this does a copy
    //
//    std::string ciphertext;
//    ciphertext.assign(reinterpret_cast<std::string::value_type*>(output.pbData),
//                       output.cbData);
    // --------------------------------
    OTData theOutput;    
    theOutput.Assign(static_cast<void*>   (output.pbData),
                     static_cast<uint32_t>(output.cbData));
    // --------------------------------
    LocalFree(output.pbData); // Note: should have a check for NULL here... ? And above...

    // Success encrypting to ciphertext (std::string or OTData)
    
    // *******************************
    //
    // Write it to local storage.
    //
    if (theOutput.IsEmpty())
    {
        OTLog::vError("%s: Error: Output of Win32 CryptProtectData was empty.\n",
                      szFunc);
    }
    else
    {
        const OTASCIIArmor ascData(theOutput);
        const OTString strFoldername("win32_data"); // todo hardcoding.

        if (ascData.Exists())
            return ascData.WriteArmoredFile(strFoldername, strUser, // this is filename
                                            "WINDOWS KEYRING MASTERKEY");
    }
    // ---------------------------------
    return false;
}


//static 
bool OTKeyring::Windows_RetrieveSecret(const OTString    & strUser, 
                                             OTPassword  & thePassword,
                                       const std::string & str_display)
{
    OT_ASSERT(strUser.Exists());
    // -----------------------------------------
    const char * szFunc = "OTKeyring::Windows_RetrieveSecret";
    // ----------------------------------------    
    const OTString strFoldername("win32_data"); // todo hardcoding.
    OTASCIIArmor ascFileContents;
    bool bLoaded = (OTDB::Exists(strFoldername, strUser) && 
                    ascFileContents.LoadFromFile(strFoldername, strUser) && 
                    ascFileContents.Exists());
    if (!bLoaded)
    {
        OTLog::vOutput(1, "%s: No cached ciphertext of master key loaded during attempted retrieval. "
                       "(However, once one is available, it WILL be cached using DPAPI.) \n", szFunc);
        return false;
    }
    // Below this point, we know for sure the ciphertext of the master 
    // key loaded, and exists.
    //
    const OTPayload theCipherblob(ascFileContents);
    // *******************************
    //
    if (theCipherblob.IsEmpty())
    {
        OTLog::vError("%s: Error: OTPayload is empty after decoding OTASCIIArmor (that wasn't empty.)\n",
                      szFunc);
    }
    else
    {
        DATA_BLOB input;
        input.pbData = const_cast<BYTE*>(
                            reinterpret_cast<const BYTE*>(theCipherblob.GetPayloadPointer()));
        input.cbData = static_cast<DWORD>(theCipherblob.GetSize());
        // ---------------------------------
//      CRYPTPROTECT_PROMPTSTRUCT PromptStruct;
//      ZeroMemory(&PromptStruct, sizeof(PromptStruct));
//      PromptStruct.cbSize = sizeof(PromptStruct);
//      PromptStruct.dwPromptFlags = CRYPTPROTECT_PROMPT_ON_PROTECT;
//      PromptStruct.szPrompt = L"This is a user prompt.";
        
//      LPWSTR pDescrOut = NULL;

        DATA_BLOB output;
        BOOL result = CryptUnprotectData(&input, 
                                         NULL,  // &pDescrOut
                                         NULL,  // optional entropy
                                         NULL,  // reserved
                                         NULL,//&PromptStruct
                                         0, &output);
        if (!result)
        {
            OTLog::vError("%s: Error: Output of Win32 CryptUnprotectData was empty.\n",
                          szFunc);
        }
        else
        {
            thePassword.setMemory(reinterpret_cast<void*>(output.pbData), 
                                    static_cast<uint32_t>(output.cbData)); 
            SecureZeroMemory(output.pbData, output.cbData);
            LocalFree(output.pbData);
//          LocalFree(pDescrOut);
            return true;
        }
    }
    // ---------------------------------
    return false;
}

//static 
bool OTKeyring::Windows_DeleteSecret(const OTString    & strUser,
                                     const std::string & str_display)
{
    OT_ASSERT(strUser.Exists());
    // -----------------------------------------
    const OTString strFoldername("win32_data"); // todo hardcoding.

    const bool bErased = OTDB::EraseValueByKey(strFoldername, strUser);

    if (!bErased)
        OTLog::Error("OTKeyring::Windows_DeleteSecret: Failed attempt to erase file: %s%s%s%s%s \n",
                     OTLog::Path(), OTLog::PathSeparator(), strFoldername.Get(),
                     OTLog::PathSeparator(), strUser.Get());
    
    return bErased;
}



//#endif
// ***************************************************************
#elif defined(OT_KEYRING_MAC) && defined(__APPLE__)

//
// Mac Keychain
//


class OTMacKeychain 
{
public:
    // ------------------------------------------------------------------------------------
    
    OSStatus FindSecret(CFTypeRef keychainOrArray,
                        uint32_t serviceNameLength,
                        const char * serviceName,
                        uint32_t accountNameLength,
                        const char * accountName,
                        uint32_t * passwordLength,
                        void ** passwordData,
                        SecKeychainItemRef * itemRef) const;
    
    // ------------------------------------------------------------------------------------
    
    OSStatus AddSecret(SecKeychainRef keychain,
                       uint32_t serviceNameLength,
                       const char * serviceName,
                       uint32_t accountNameLength,
                       const char * accountName,
                       uint32_t passwordLength,
                       const void * passwordData,
                       SecKeychainItemRef * itemRef) const;
    
    // ------------------------------------------------------------------------------------
    
    OSStatus ItemFreeContent(SecKeychainAttributeList * attrList, void * data) const;
    
    // ------------------------------------------------------------------------------------
    
    OSStatus ItemDelete(SecKeychainItemRef itemRef) const;
    
    OSStatus SearchCreateFromAttributes(CFTypeRef keychainOrArray, 
                                        CFTypeRef SecItemClass, // unused here.
                                        CFTypeRef itemClass,
                                        const 
                                        SecKeychainAttributeList * attrList,
                                        SecKeychainSearchRef     * searchRef) const;
    
    OSStatus SearchCopyNext(SecKeychainSearchRef  searchRef,
                            SecKeychainItemRef  * itemRef) const;
};


// ------------------------------------------------------------------------


OSStatus OTMacKeychain::FindSecret(CFTypeRef    keychainOrArray,
                                   uint32_t     serviceNameLength,
                                   const char * serviceName,
                                   uint32_t     accountNameLength,
                                   const char * accountName,
                                   uint32_t   * passwordLength,
                                   void      ** passwordData,
                                   SecKeychainItemRef * itemRef) const 
{
    return SecKeychainFindGenericPassword(keychainOrArray,
                                          serviceNameLength,
                                          serviceName,
                                          accountNameLength,
                                          accountName,
                                          passwordLength,
                                          passwordData,
                                          itemRef);
}
// ------------------------------------------------------------------------

OSStatus OTMacKeychain::AddSecret(SecKeychainRef keychain,
                                  uint32_t       serviceNameLength,
                                  const char   * serviceName,
                                  uint32_t       accountNameLength,
                                  const char   * accountName,
                                  uint32_t       passwordLength,
                                  const void   * passwordData,
                                  SecKeychainItemRef * itemRef) const 
{
    return SecKeychainAddGenericPassword(keychain,
                                         serviceNameLength,
                                         serviceName,
                                         accountNameLength,
                                         accountName,
                                         passwordLength,
                                         passwordData,
                                         itemRef);
}

// ------------------------------------------------------------------------

OSStatus OTMacKeychain::ItemDelete(SecKeychainItemRef itemRef) const 
{
    return SecKeychainItemDelete(itemRef);
}
// ------------------------------------------------------------------------

OSStatus OTMacKeychain::SearchCreateFromAttributes(CFTypeRef keychainOrArray, 
                                                   CFTypeRef SecItemClass,
                                                   CFTypeRef itemClass,
                                                   const 
                                                   SecKeychainAttributeList * attrList,
                                                   SecKeychainSearchRef     * searchRef) const 
{
    return SecKeychainSearchCreateFromAttributes(keychainOrArray, itemClass,
                                                 attrList,        searchRef);
}
// ------------------------------------------------------------------------

OSStatus OTMacKeychain::SearchCopyNext(SecKeychainSearchRef  searchRef,
                                       SecKeychainItemRef  * itemRef) const 
{
    return SecKeychainSearchCopyNext(searchRef, itemRef);
}
// ------------------------------------------------------------------------

OSStatus OTMacKeychain::ItemFreeContent(SecKeychainAttributeList * attrList, void * data) const 
{
    return SecKeychainItemFreeContent(attrList, data);
}

// ------------------------------------------------------------------------

//static 
bool OTKeyring::Mac_StoreSecret(const OTString    & strUser, 
                                const OTPassword  & thePassword,
                                const std::string & str_display)
{
    OT_ASSERT(strUser.Exists());
    OT_ASSERT(thePassword.getMemorySize() > 0);
    // -----------------------------------------
    const std::string service_name = "opentxs";
    const std::string account_name = strUser.Get();
    // -----------------------------------------
    OTMacKeychain theKeychain;
    void * vData =
        const_cast<void*>(static_cast<const void*>(thePassword.getMemory()));
    
    OSStatus theError = theKeychain.AddSecret(NULL,
                                              service_name.size(),
                                              service_name.data(),
                                              account_name.size(),
                                              account_name.data(),
                                              thePassword.getMemorySize(),
                                              vData, // thePassword.getMemory()
                                              NULL);
    if (theError != noErr) 
    {
        OTLog::Error("OTKeyring::Mac_StoreSecret: Error in theKeychain.AddSecret.\n");
        return false;
    }
    
    return true;
}

//static 
bool OTKeyring::Mac_RetrieveSecret(const OTString    & strUser, 
                                         OTPassword  & thePassword,
                                   const std::string & str_display)
{
    OT_ASSERT(strUser.Exists());
    // -----------------------------------------
    const std::string service_name = "opentxs";
    const std::string account_name = strUser.Get();
    // -----------------------------------------
    
    uint32_t   password_length = 0;
    void     * password_data   = NULL;
    
    OTMacKeychain theKeychain;

    OSStatus theError = theKeychain.FindSecret(NULL,
                                               service_name.size(),
                                               service_name.data(),
                                               account_name.size(),
                                               account_name.data(),
                                               &password_length,    // output.
                                               &password_data,
                                               NULL);
    if (theError == noErr) 
    {
        thePassword.setMemory(password_data, password_length);
        theKeychain.ItemFreeContent(NULL, password_data);
        return true;
    } 
    else 
        OTLog::Error("OTKeyring::Mac_RetrieveSecret: Error in theKeychain.FindSecret.\n");
    
    return false;
}

//static 
bool OTKeyring::Mac_DeleteSecret(const OTString    & strUser,
                                 const std::string & str_display)
{
    OT_ASSERT(strUser.Exists());
    // -----------------------------------------
    const std::string service_name = "opentxs";
    const std::string account_name = strUser.Get();
    // -----------------------------------------
    OTMacKeychain theKeychain;
    // -----------------------------------------
    // Setup the attributes the for the keychain item
    SecKeychainAttribute attrs[] = 
    {
        { kSecServiceItemAttr,      service_name.length(), (char *)service_name.c_str() },
        { kSecAccountItemAttr,      account_name.length(), (char *)account_name.c_str() }
    };
    SecKeychainAttributeList attributes = { sizeof(attrs) / sizeof(attrs[0]), attrs };
    // ---------------------------------------------------------
    SecKeychainItemRef        theItem    = NULL;
    SecKeychainSearchRef      theSearch  = NULL;
    OSStatus                  theStatus  = 0;
    OSErr                     theResult;
    int                       numberOfItemsFound = 0;
    // ---------------------------------------------------------
    theResult = theKeychain.SearchCreateFromAttributes(NULL, 
                                                       NULL, // CFTypeRef SecItemClass, // unused here.
                                                       kSecGenericPasswordItemClass,
                                                       &attributes,
                                                       &theSearch);
    // ---------------------------------------------------------
    bool bReturnVal = false;
    
    if ( errSecSuccess == theResult) // Success searching, now let's iterate the results and count them.
    {
        while (theKeychain.SearchCopyNext(theSearch, &theItem) == noErr) 
        {
            numberOfItemsFound++;
        }
        // -----------------------------------
        if (numberOfItemsFound > 0) 
        {
            theStatus = theKeychain.ItemDelete(theItem);
            
            if (theStatus != 0) 
                OTLog::Error("OTKeyring::Mac_DeleteSecret: Error deleting item from keychain.\n");
            else
                bReturnVal = true;
        }
        // -----------------------------------
        CFRelease(theItem);
        CFRelease(theSearch);
    }
    // ---------------------------------------------------------    
    return bReturnVal;
}

//#endif
// ***************************************************************
#elif defined (OT_KEYRING_GNOME)

//
// Gnome Keyring
//

//The predefined schema is:
//
// GNOME_KEYRING_NETWORK_PASSWORD
//
// With attributes:
//
//        user:       A string for the user login.
//        server:     A string for the server being connected to.
//        protocol:   A string for the protocol used to access the server, such as 'http' or 'smb'.
//        domain:     A string for the realm or domain, such as a Windows login domain.
//        port:       An integer describing the network port to used to connect to the server.
//

//static 
bool OTKeyring::Gnome_StoreSecret(const OTString    & strUser, 
                                  const OTPassword  & thePassword,
                                  const std::string & str_display)
{
    OT_ASSERT(strUser.Exists());
    OT_ASSERT(thePassword.getMemorySize() > 0);
    // -----------------------------------------
    OTData       theData(thePassword.getMemory(), thePassword.getMemorySize());
    OTASCIIArmor ascData(theData);
    theData.zeroMemory(); // security reasons.
    // -----------------------------------------
    OTString strOutput;
    const bool bSuccess = ascData.Exists() && 
                            ascData.WriteArmoredString(strOutput,
                                                       "DERIVED KEY"); // There's no default, to force you to enter the right string.
    ascData.zeroMemory();
    // -----------------------------------------
    if (bSuccess && strOutput.Exists())
    {
        GnomeKeyringResult theResult =
            gnome_keyring_store_password_sync(GNOME_KEYRING_NETWORK_PASSWORD,
                                              GNOME_KEYRING_DEFAULT, //GNOME_KEYRING_SESSION,
                                              str_display.c_str(),
                                              strOutput.Get(),
                                              "user",     strUser.Get(),
                                              "protocol", "opentxs", // todo: hardcoding.
                                              NULL);
        strOutput.zeroMemory();
        // ---------------------------
        if (theResult == GNOME_KEYRING_RESULT_OK)
        {
            return true;
        }
        else 
        {
            OTLog::vError("OTKeyring::Gnome_StoreSecret: "
                          "Failure in gnome_keyring_store_password_sync: %s.\n",
                          gnome_keyring_result_to_message (theResult));
        }
    }
    // -----------------------------------------
    return false;
}


//static 
bool OTKeyring::Gnome_RetrieveSecret(const OTString    & strUser, 
                                           OTPassword  & thePassword,
                                     const std::string & str_display)
{
    OT_ASSERT(strUser.Exists());
    const char * szFunc = "OTKeyring::Gnome_RetrieveSecret";
    // -----------------------------------------
    GnomeKeyringResult theResult = GNOME_KEYRING_RESULT_IO_ERROR;
    gchar * gchar_p_password = NULL;
    
    // if the password exists in the keyring, set it in
    // thePassword (output argument.)
    //
    theResult = 
        gnome_keyring_find_password_sync(GNOME_KEYRING_NETWORK_PASSWORD,
                                         &gchar_p_password, 
                                         "user",     strUser.Get(),
                                         "protocol", "opentxs", // todo: hardcoding.
                                         NULL);
    
    if ((theResult == GNOME_KEYRING_RESULT_OK) && (NULL != gchar_p_password))
    {
        size_t sizePassword = OTString::safe_strlen(gchar_p_password, MAX_STRING_LENGTH);
        // ------------------------------------
        if (sizePassword > 0)
        {
            OTString     strData(gchar_p_password, sizePassword);

            gnome_keyring_free_password(gchar_p_password);
            gchar_p_password = NULL;

            OTASCIIArmor ascData;
            const bool bLoaded = strData.Exists() && ascData.LoadFromString(strData);
            strData.zeroMemory();
            // -----------------------------
            if (!bLoaded)
                OTLog::vError("%s: Failed trying to decode secret from Gnome Keyring contents:\n\n%s\n\n",
                              szFunc, strData.Get());
            else
            {
                OTPayload thePayload(ascData);
                ascData.zeroMemory();
                if (thePayload.IsEmpty())
                    OTLog::vError("%s: Failed trying to decode secret OTPayload from OTASCIIArmor "
                                  "from Gnome Keyring contents:\n\n%s\n\n", szFunc, strData.Get());
                else
                {
                    thePassword.setMemory(thePayload.GetPayloadPointer(), thePayload.GetSize()); 
                    thePayload.zeroMemory(); // for security.
                    return true;
                }
                return false;
            }
        }
    }
    // ----------------------------------------------------------------
    // Not an error: what if it just hasn't been set there yet?
    //
    OTLog::vOutput(1, "OTKeyring::Gnome_RetrieveSecret: "
                  "No secret found: gnome_keyring_find_password_sync: %s.\n",
                  gnome_keyring_result_to_message (theResult));

    return false;
}


//static 
bool OTKeyring::Gnome_DeleteSecret(const OTString    & strUser,
                                   const std::string & str_display)
{
    OT_ASSERT(strUser.Exists());
    // -----------------------------------------
    GnomeKeyringResult theResult =
        gnome_keyring_delete_password_sync(GNOME_KEYRING_NETWORK_PASSWORD,
                                           "user",     strUser.Get(),
                                           "protocol", "opentxs", // todo: hardcoding.
                                           NULL); // Always end with NULL
    
    if (theResult == GNOME_KEYRING_RESULT_OK)
    {
        return true;
    }
    else 
    {
        OTLog::vError("OTKeyring::Gnome_DeleteSecret: "
                      "Failure in gnome_keyring_delete_password_sync: %s.\n",
                      gnome_keyring_result_to_message (theResult));
    }
    
    return false;
}

// ***************************************************************
#elif defined(OT_KEYRING_KWALLET)

//
// KDE / KWallet
//

//static 

KWallet::Wallet * OTKeyring::s_pWallet = NULL;
KApplication    * OTKeyring::s_pApp    = NULL;


bool OTKeyring::InitKApp()
{
	static bool bInitialized = false;
	
	if (! bInitialized)
	{
		if (! KApplication::instance())
		{
			static char kdeAppName[] = "opentxs-kwallet";
			int argc = 1;
			char *argv[2] = { kdeAppName, NULL };
			QByteArray qbApp(kdeAppName);
			KAboutData about(qbApp, qbApp, KLocalizedString(),QByteArray("1.0"));
			KCmdLineArgs::init(argc, argv, &about);
			if (! qApp)
				OTKeyring::s_pApp = new KApplication(true); // todo  cleanup ?
            else
                OTLog::Error("OTKeyring::InitKApp: Error: qApp already existed.\n");
		}
        
		bInitialized = true;
	}
	
	return bInitialized;
}


KWallet::Wallet * OTKeyring::OpenKWallet()
{
	if (OTKeyring::InitKApp())
    {
        OT_ASSERT(NULL != OTKeyring::s_pApp);
        // Below this point, we know OTKeyring::s_pApp is created.
        
        if (NULL == OTKeyring::s_pWallet)
        {
            OTKeyring::s_pWallet = KWallet::Wallet::openWallet(KWallet::Wallet::NetworkWallet(), NULL);
            
            if (NULL == OTKeyring::s_pWallet)
            {
                OTLog::Error("OTKeyring::OpenKWallet: Failed "
                             "calling: KWallet::Wallet::openWallet"
                             "(KWallet::Wallet::NetworkWallet(), NULL)\n");
                return NULL;
            }
        }
        // Below this point, we know OTKeyring::s_pWallet was opened at 
        // some time in the past, and may still be open.
        // ------------------------------------------------------------
        //
        if (!KWallet::Wallet::isOpen(KWallet::Wallet::NetworkWallet()))
        {
            // See if it's still open -- if not, re-open it.
            //
            if (NULL != OTKeyring::s_pWallet)
                delete OTKeyring::s_pWallet;
            OTKeyring::s_pWallet = KWallet::Wallet::openWallet(KWallet::Wallet::NetworkWallet(), NULL);
            
            if (NULL == OTKeyring::s_pWallet)
            {
                OTLog::Error("OTKeyring::OpenKWallet (while re-opening): Failed "
                             "calling: KWallet::Wallet::openWallet"
                             "(KWallet::Wallet::NetworkWallet(), NULL)\n");
                return NULL;
            }
        }
        // Below this point, we know OTKeyring::s_pWallet is currently open.
        // ------------------------------------------------------------------
        //
        if(!OTKeyring::s_pWallet->setFolder(QString::fromAscii("opentxs")))  // todo hardcoding.
        {
            OTKeyring::s_pWallet->createFolder(QString::fromAscii("opentxs"));
            
            if(!OTKeyring::s_pWallet->setFolder(QString::fromAscii("opentxs")))
            {
                OTLog::Error("OTKeyring::OpenKWallet: Failed calling: KWallet::Wallet::setFolder"
                             "(QString::fromAscii(\"opentxs\")) -- Tried creating it, too!\n");
                return NULL;
            }
        }
        // Below this point, we know the folder was properly set to "opentxs".
        // ------------------------------------------------------------------
    }
    
	return OTKeyring::s_pWallet;
}


//bool OTKeyring::DoesPasswordExist(const QString key)
//{
//	KWallet::Wallet * pWallet = OTKeyring::OpenKWallet();
//    
//	if (NULL != pWallet)
//	{
//		if (pWallet->hasEntry(key) == 0)
//			return true;
//		else
//			return false;
//	}
//
//    return false;
//}

// -----------------------

//static 
bool OTKeyring::KWallet_StoreSecret(const OTString    & strUser, 
                                    const OTPassword  & thePassword,
                                    const std::string & str_display)
{
    OT_ASSERT(strUser.Exists());
    OT_ASSERT(thePassword.getMemorySize() > 0);
    // -----------------------------------------
	KWallet::Wallet * pWallet = OTKeyring::OpenKWallet();

	if (NULL != pWallet)
	{
        const QString qstrKey(strUser.Get());

        OTData       theData(thePassword.getMemory(), thePassword.getMemorySize());
        OTASCIIArmor ascData(theData);
        theData.zeroMemory(); // security reasons.
        // -------------------------------------------
        OTString strOutput;
        const bool bSuccess = ascData.Exists() && 
                                ascData.WriteArmoredString(strOutput,
                                                           "DERIVED KEY"); // There's no default, to force you to enter the right string.
        ascData.zeroMemory();
        // -----------------------------------------

		// Set the password
        //
        bool bReturnVal = false;
        
		if (strOutput.Exists() && pWallet->writePassword(qstrKey, QString::fromUtf8(strOutput.Get())) == 0)
			bReturnVal = true;
		else
			OTLog::Error("OTKeyring::KWallet_StoreSecret: Failed trying to store secret into KWallet.\n");
        
        strOutput.zeroMemory();
        
        return bReturnVal;
	}
    
    return false;
}

//static 
bool OTKeyring::KWallet_RetrieveSecret(const OTString    & strUser, 
                                             OTPassword  & thePassword,
                                       const std::string & str_display)
{
    OT_ASSERT(strUser.Exists());
    const char * szFunc = "OTKeyring::KWallet_RetrieveSecret";
    // -----------------------------------------
	KWallet::Wallet * pWallet = OTKeyring::OpenKWallet();
    
	if (NULL != pWallet)
	{
        const 
        QString qstrKey(strUser.Get());
        QString qstrPwd;

		// Get the password
        //
		if (pWallet->readPassword(qstrKey, qstrPwd) == 0)
		{
            const std::string str_password = qstrPwd.toStdString(); // todo security: notice str_password isn't zero'd here.
            
            OTString     strData(str_password);
            OTASCIIArmor ascData;
            
            const bool bLoaded = strData.Exists() && ascData.LoadFromString(strData);
            strData.zeroMemory();
            
            if (!bLoaded)
                OTLog::vError("%s: Failed trying to decode secret from KWallet contents.\n",
                              szFunc);
            else
            {
                OTPayload thePayload(ascData);
                ascData.zeroMemory();
                if (thePayload.IsEmpty())
                    OTLog::vError("%s: Failed trying to decode secret OTPayload from OTASCIIArmor from KWallet contents.\n",
                                  szFunc);
                else
                {
                    thePassword.setMemory(thePayload.GetPayloadPointer(), thePayload.GetSize()); 
                    thePayload.zeroMemory(); // for security.
                    return true;
                }
            }
		}
		else
			OTLog::vError("%s: Failed trying to retrieve secret from KWallet.\n", szFunc);
	}
    
    // ----------------------------------------------------------------
    // Not an error: what if it just hasn't been set there yet?
    //
    OTLog::Output(1, "OTKeyring::KWallet_RetrieveSecret: No secret found.\n");

    return false;
}

//static 
bool OTKeyring::KWallet_DeleteSecret(const OTString    & strUser,
                                     const std::string & str_display)
{
    OT_ASSERT(strUser.Exists());
    // -----------------------------------------
	KWallet::Wallet * pWallet = OTKeyring::OpenKWallet();
    
	if (NULL != pWallet)
	{
        const 
        QString qstrKey(strUser.Get());

		if (pWallet->removeEntry(qstrKey) == 0) // delete the entry
			return true;
		else
			OTLog::Error("OTKeyring::KWallet_DeleteSecret: Failed trying to erase secret from KWallet.\n");
	}

    return false;
}



#endif
// ***************************************************************



//static 
bool OTKeyring::StoreSecret(const OTString    & strUser, 
                            const OTPassword  & thePassword,
                            const std::string & str_display)
{
    if (OTMasterKey::It()->IsUsingSystemKeyring())
    {
#if defined(OT_KEYRING_WINDOWS) && defined(_WIN32)
        return OTKeyring::Windows_StoreSecret(strUser, thePassword, str_display);
#elif defined(OT_KEYRING_MAC) && defined(__APPLE__)
        return OTKeyring::Mac_StoreSecret(strUser, thePassword, str_display);
#elif defined(OT_KEYRING_GNOME)
        return OTKeyring::Gnome_StoreSecret(strUser, thePassword, str_display);
#elif defined(OT_KEYRING_KWALLET)
        return OTKeyring::KWallet_StoreSecret(strUser, thePassword, str_display);
#else
        OTLog::Error("OTKeyring::StoreSecret: WARNING: The OT config file says to use the system keyring, "
                     "but OT wasn't compiled to support any keyrings.\n");
#endif
    }
    return false;
}

//static 
bool OTKeyring::RetrieveSecret(const OTString    & strUser, 
                                     OTPassword  & thePassword,
                               const std::string & str_display)
{
    if (OTMasterKey::It()->IsUsingSystemKeyring())
    {
#if defined(OT_KEYRING_WINDOWS) && defined(_WIN32)
        return OTKeyring::Windows_RetrieveSecret(strUser, thePassword, str_display);
#elif defined(OT_KEYRING_MAC) && defined(__APPLE__)
        return OTKeyring::Mac_RetrieveSecret(strUser, thePassword, str_display);
#elif defined(OT_KEYRING_GNOME)
        return OTKeyring::Gnome_RetrieveSecret(strUser, thePassword, str_display);
#elif defined(OT_KEYRING_KWALLET)
        return OTKeyring::KWallet_RetrieveSecret(strUser, thePassword, str_display);
#else
        OTLog::Error("OTKeyring::RetrieveSecret: WARNING: The OT config file says to use the system keyring, "
                     "but OT wasn't compiled to support any keyrings.\n");
#endif
    }
    return false;
}

//static 
bool OTKeyring::DeleteSecret(const OTString    & strUser,
                             const std::string & str_display)
{
    if (OTMasterKey::It()->IsUsingSystemKeyring())
    {
#if defined(OT_KEYRING_WINDOWS) && defined(_WIN32)
        return OTKeyring::Windows_DeleteSecret(strUser, str_display);
#elif defined(OT_KEYRING_MAC) && defined(__APPLE__)
        return OTKeyring::Mac_DeleteSecret(strUser, str_display);
#elif defined(OT_KEYRING_GNOME)
        return OTKeyring::Gnome_DeleteSecret(strUser, str_display);
#elif defined(OT_KEYRING_KWALLET)
        return OTKeyring::KWallet_DeleteSecret(strUser, str_display);
#else
        OTLog::Error("OTKeyring::DeleteSecret: WARNING: The OT config file says to use the system keyring, "
                     "but OT wasn't compiled to support any keyrings.\n");
#endif
    }
    return false;
}

// -------------------------------------------------------





































































