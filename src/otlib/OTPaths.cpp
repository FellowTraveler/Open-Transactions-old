/*******************************************************************
*    
*  OTPaths.cpp
*  
*/

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1
 
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
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
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
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
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
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
 Version: GnuPG v1.4.9 (Darwin)
 
 iQIcBAEBAgAGBQJRSsfJAAoJEAMIAO35UbuOQT8P/RJbka8etf7wbxdHQNAY+2cC
 vDf8J3X8VI+pwMqv6wgTVy17venMZJa4I4ikXD/MRyWV1XbTG0mBXk/7AZk7Rexk
 KTvL/U1kWiez6+8XXLye+k2JNM6v7eej8xMrqEcO0ZArh/DsLoIn1y8p8qjBI7+m
 aE7lhstDiD0z8mwRRLKFLN2IH5rAFaZZUvj5ERJaoYUKdn4c+RcQVei2YOl4T0FU
 LWND3YLoH8naqJXkaOKEN4UfJINCwxhe5Ke9wyfLWLUO7NamRkWD2T7CJ0xocnD1
 sjAzlVGNgaFDRflfIF4QhBx1Ddl6wwhJfw+d08bjqblSq8aXDkmFA7HeunSFKkdn
 oIEOEgyj+veuOMRJC5pnBJ9vV+7qRdDKQWaCKotynt4sWJDGQ9kWGWm74SsNaduN
 TPMyr9kNmGsfR69Q2Zq/FLcLX/j8ESxU+HYUB4vaARw2xEOu2xwDDv6jt0j3Vqsg
 x7rWv4S/Eh18FDNDkVRChiNoOIilLYLL6c38uMf1pnItBuxP3uhgY6COm59kVaRh
 nyGTYCDYD2TK+fI9o89F1297uDCwEJ62U0Q7iTDp5QuXCoxkPfv8/kX6lS6T3y9G
 M9mqIoLbIQ1EDntFv7/t6fUTS2+46uCrdZWbQ5RjYXdrzjij02nDmJAm2BngnZvd
 kamH0Y/n11lCvo1oQxM+
 =uSzz
 -----END PGP SIGNATURE-----
 **************************************************************/





#include <stdafx.h>

// The long-awaited paths class.

#include <cstdarg>
#include <cstdio>
#include <cstring> // The C one 
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cerrno>

#include <iostream>
#include <exception>
#include <stdexcept>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef S_ISDIR
#define S_ISDIR(mode)  (((mode) & S_IFMT) == S_IFDIR)
#endif

#ifndef S_ISREG
#define S_ISREG(mode)  (((mode) & S_IFMT) == S_IFREG)
#endif

#include <string> // The C++ one 
#include <vector>

#ifdef _WIN32
#include <WinsockWrapper.h>
#include <Shlobj.h>
#include <direct.h>
#else
#include <libgen.h>
#include <unistd.h>
#endif

#ifdef __APPLE__
#include "TargetConditionals.h"
#endif

#ifdef TARGET_OS_MAC
#include <mach-o/dyld.h>
#include <limits.h>
#endif

#ifdef _WIN32
#define OT_APPDATA_DIR "OpenTransactions"
#elif TARGET_OS_IPHONE
#define OT_APPDATA_DIR "Documents"
#else
#define OT_APPDATA_DIR ".ot"
#endif

#ifndef OT_PREFIX_PATH
#ifdef _WIN32
#define OT_PREFIX_PATH OTPaths::AppDataFolder() //windows, set to OT AppData Folder.
#elif TARGET_OS_IPHONE
#define OT_PREFIX_PATH OTPaths::AppDataFolder() //iphone, set to OT AppData Folder.
#else
#define OT_PREFIX_PATH "/usr/local" //default prefix_path unix
#endif
#endif

#define OT_INIT_CONFIG_FILENAME "ot_init.cfg"
#define CONFIG_FILE_EXT ".cfg"
#define OT_HOME_DIR "."
#define OT_CONFIG_DIR "."
#define OT_USER_SCRIPTS_DIR "scripts"
#define DATA_FOLDER_EXT "_data"
#define OT_LIB_DIR "lib"
#define OT_CONFIG_ISRELATIVE "_is_relative"

#ifdef _WIN32
#define OT_SCRIPTS_DIR "scripts/ot"
#else
#define OT_SCRIPTS_DIR "lib/opentxs"
#endif

#include "OTPaths.h"
#include "OTLog.h"


OTSettings OTPaths::s_settings = OTSettings(GlobalConfigFile());

OTString OTPaths::s_strAppBinaryFolder("");
OTString OTPaths::s_strAppDataFolder("");
OTString OTPaths::s_strGlobalConfigFile("");
OTString OTPaths::s_strPrefixFolder("");
OTString OTPaths::s_strScriptsFolder("");


OTPaths::~OTPaths() { }

// --------------------------------------------------------------------

const OTString & OTPaths::AppBinaryFolder()
{
    return OTPaths::s_strAppBinaryFolder;
}

void OTPaths::SetAppBinaryFolder(OTString strLocation)
{
    OTPaths::s_strAppBinaryFolder = strLocation;
}

// --------------------------------------------------------------------

const OTString & OTPaths::AppDataFolder()
{
    if (s_strAppDataFolder.Exists()) return s_strAppDataFolder;  // already got it, just return it.

    OTString strHomeDataFolder(""), strAppDataFolder("");  // eg. /home/user/  (the folder that the OT appdata folder will be in.)

    if(!GetHomeFromSystem(strHomeDataFolder)) { OT_FAIL; }

    // now lets change all the '\' into '/'
    // then check that the path /home/user indeed exists, and is a folder.

    FixPath(strHomeDataFolder,strHomeDataFolder,true);
    if(!PathExists(strHomeDataFolder)) OT_FAIL;

    // ok, we have the HomeData Folder, lets append our OT folder to it.

    if(!AppendFolder(strAppDataFolder, strHomeDataFolder, OT_APPDATA_DIR)) OT_FAIL;

    bool bFolderCreated;
    if(!BuildFolderPath(strAppDataFolder,bFolderCreated)) OT_FAIL;

    s_strAppDataFolder = strAppDataFolder;  // all good lets set it.

    return s_strAppDataFolder;
}

const OTString & OTPaths::GlobalConfigFile()
{
    if (s_strGlobalConfigFile.Exists()) return s_strGlobalConfigFile;  //got it, lets return it.

    OTString strGlobalConfigFile("");

    if(!AppendFile(strGlobalConfigFile,AppDataFolder(),OT_INIT_CONFIG_FILENAME)) OT_FAIL;

    s_strGlobalConfigFile = strGlobalConfigFile;

    return s_strGlobalConfigFile;
}


const OTString & OTPaths::PrefixFolder()
{
    if (s_strPrefixFolder.Exists()) return s_strPrefixFolder;  //got it, lets return it.

    // lets load from the statndard config, or create the entry.
    if(LoadSetPrefixFolder())
        return s_strPrefixFolder;
    else
    {
        OT_FAIL;
    }
}

const OTString & OTPaths::ScriptsFolder()
{
    if (s_strScriptsFolder.Exists()) return s_strScriptsFolder;  //got it, lets return it.

    // load it from config (if we already have it set in the config).
    if(LoadSetScriptsFolder())
        return s_strScriptsFolder;
    else
    {
        OT_FAIL;
    }
}


// The LoadSet Functions will update the static values.
//static
bool OTPaths::LoadSetPrefixFolder    // eg. /usr/local/  
    (    
    OTSettings & config,    //optional
    const OTString & strPrefixFolder                //optional
    //const bool & bIsRelative (cannot be relative);
    )
{
    /*
    The prefix path is special.

    This path is tested if it is different to the
    one that would be automatically selected by this program
    (aka either compiled into, or from the registry, or the default user data directory).

    If the set path is different to what would be supplied and the ‘override path’ value is set.
    Then we will use that path.

    Otherwise, we will update the path in the configuration to link against the updated path.

    Users will need to set the ‘override path’ flag in the configuration,
    if they want to manually set the prefix path.
    */

    const bool bPreLoaded(config.IsLoaded());

    if (!bPreLoaded)
    {
        config.Reset();
        if(!config.Load()) { OT_FAIL; }
    }

    {
        // get default path
        OTString strDefaultPrefixPath(OT_PREFIX_PATH);
        {
            if (!strDefaultPrefixPath.Exists()) { OTLog::sError("%s: Error: OT_PREFIX_PATH is not set!",__FUNCTION__); OT_FAIL; }

#ifdef _WIN32
            OTString strTemp;
            if (OTPaths::Win_GetInstallFolderFromRegistry(strTemp))
            {
                strDefaultPrefixPath = strTemp;
            }
#endif

            if(!ToReal(strDefaultPrefixPath,strDefaultPrefixPath)) { OT_FAIL; }
            if(!FixPath(strDefaultPrefixPath,strDefaultPrefixPath,true)) { OT_FAIL; }
        }

        OTString strLocalPrefixPath = "";
        bool bPrefixPathOverride = false;

        {
            // now check the configuration to see what values we have:
            OTString strConfigPath = "";

            bool bIsNew = false;
            OTString strPrefixPathOverride("prefix_path_override");

            if(!config.CheckSet_str("paths","prefix_path",strDefaultPrefixPath,strConfigPath,bIsNew)) { return false; }
            if(!config.CheckSet_bool("paths",strPrefixPathOverride,false,bPrefixPathOverride,bIsNew,"; This will force the prefix not to change")) {return false; }

            // if the config dosn't have a prefix path set. Lets set the default.
            // if a prefix path was passed in, we will override with that later.
            if (!strConfigPath.Exists() || (3 > strConfigPath.GetLength())) {
                OTLog::sError("%s: Error: Bad %s in config, will reset!",__FUNCTION__,"prefix_path");

                strConfigPath = strDefaultPrefixPath; // set
                bPrefixPathOverride = false;

                // lets set the default path, and reset override
                bool bNewOrUpdate = false;
                if(!config.Set_str("paths","prefix_path",strDefaultPrefixPath,bNewOrUpdate)) { return false; }
                if(!config.Set_bool("paths",strPrefixPathOverride,false,bNewOrUpdate)) { return false; }
            }

            strLocalPrefixPath = strConfigPath;
        }

        {
            if (!bPrefixPathOverride)
            {
                bool bUpdate = false;

                // default
                if (!strLocalPrefixPath.Compare(strDefaultPrefixPath)) {
                    strLocalPrefixPath = strDefaultPrefixPath;
                    bUpdate = true;
                }

                // passed in
                if (strPrefixFolder.Exists() && (3 < strPrefixFolder.GetLength())) {
                    // a prefix folder was passed in... lets use it, and update the config if the override isn't set
                    OTString strTmp = strPrefixFolder;

                    if(!ToReal(strTmp,strTmp)) { OT_FAIL; }
                    if(!FixPath(strTmp,strTmp,true)) { OT_FAIL; }

                    if (!strLocalPrefixPath.Compare(strTmp)) {
                        strLocalPrefixPath = strTmp;
                        bUpdate = true;
                    }
                }

                // we need to update the path in the config
                if (bUpdate) {
                    bool bNewOrUpdate = false;
                    if(!config.Set_str("paths","prefix_path",strLocalPrefixPath,bNewOrUpdate)) { return false; }
                }
            }
        }

        {
            if (!strLocalPrefixPath.Exists()) { OT_FAIL; }

            if(!ToReal(strLocalPrefixPath,strLocalPrefixPath)) { OT_FAIL; }
            if(!FixPath(strLocalPrefixPath,strLocalPrefixPath,true)) { OT_FAIL; }
            s_strPrefixFolder = strLocalPrefixPath;
        }

    }

    if (!bPreLoaded)
    {
        if(!config.Save()) { OT_FAIL; }
        config.Reset();
    }
    return true;
}

//static
bool OTPaths::LoadSetScriptsFolder  // ie. PrefixFolder() + lib/opentxs/
    (
    OTSettings & config, //optional
    const OTString & strScriptsFolder,    //optional
    const bool & bIsRelative            //optional
    )
{
    const bool bPreLoaded(config.IsLoaded());

    if (!bPreLoaded)
    {
        config.Reset();
        if(!config.Load()) { OT_FAIL; }
    }

    OTString strRelativeKey = "";
    strRelativeKey.Format("%s%s","scripts",OT_CONFIG_ISRELATIVE);


    // local vairables.
    bool bConfigIsRelative = false;
    OTString strConfigFolder = "";


    // lets first check what we have in the configuration:
    {
        bool bKeyIsNew = false;

        if (!config.CheckSet_bool("paths",strRelativeKey,true,bConfigIsRelative,bKeyIsNew)) { return false; }
        if (!config.CheckSet_str("paths","scripts",OT_SCRIPTS_DIR,strConfigFolder,bKeyIsNew)) { return false; }
    }

    // lets first test if there was a folder passed in

    if ((strScriptsFolder.Exists()) && (3 < strScriptsFolder.GetLength())) {

        // we have a folder passed in, lets now check if we need to update anything:

        if (bConfigIsRelative != bIsRelative) {

            bConfigIsRelative = bIsRelative;
            bool bNewOrUpdated = false;

            if (!config.Set_bool("paths", strRelativeKey, bConfigIsRelative, bNewOrUpdated)) { return false; }

        }

        if (!strConfigFolder.Compare(strScriptsFolder)) {

            strConfigFolder = strScriptsFolder; // update folder
            bool bNewOrUpdated = false;

            if (!config.Set_str( "paths", "scripts", strConfigFolder, bNewOrUpdated)) { return false; }
        }
    }


    if (bConfigIsRelative)
    {
        if(!FixPath(strConfigFolder,strConfigFolder,true)) { OT_FAIL; }

        OTString strScriptPath = "";
        OTString strScriptPrefix(AppBinaryFolder().Exists() ? AppBinaryFolder() : PrefixFolder());
        
        if (!AppendFolder(strScriptPath, strScriptPrefix, strConfigFolder))
        {
            OT_FAIL;
        }

        s_strScriptsFolder = strScriptPath; // set
    }
    else
    {
        if(!ToReal(strConfigFolder, strConfigFolder)) { OT_FAIL; }
        if(!FixPath(strConfigFolder, strConfigFolder, true)) { OT_FAIL; }
        s_strScriptsFolder = strConfigFolder; // set
    }

    if (!bPreLoaded)
    {
        if(!config.Save()) { OT_FAIL; }
        config.Reset();
    }
    return true;  // success
}


//static
bool OTPaths::Get(
    OTSettings & config,
    const                  OTString      & strSection,
    const                  OTString      & strKey,
    OTString      & out_strVar,
    bool          & out_bIsRelative,
    bool          & out_bKeyExist
    )
{
    if (!strSection.Exists()) { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strSection" ); OT_FAIL; }
    if (!strKey.Exists())     { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strKey"     ); OT_FAIL; }

    out_strVar = "";
    out_bIsRelative = false;
    out_bKeyExist = false;

    const bool bPreLoaded(config.IsLoaded());

    if (!bPreLoaded)
    {
        config.Reset();
        if(!config.Load()) { OT_FAIL; }
    }

    bool bBoolExists(false), bStringExists(false), bIsRelative(false);
    OTString  strRelativeKey(""), strOutFolder("");

    strRelativeKey.Format("%s%s",strKey.Get(),OT_CONFIG_ISRELATIVE);

    if(config.Check_bool(strSection,strRelativeKey,bIsRelative,bBoolExists))
    {
        if(config.Check_str(strSection,strKey,strOutFolder,bStringExists))
        {
            if (bBoolExists && bStringExists)
            {
                if (!bIsRelative) // lets fix the path, so it dosn't matter how people write it in the config.
                {
                    if(!ToReal(strOutFolder,strOutFolder)) { OT_FAIL; }
                    if(!FixPath(strOutFolder,strOutFolder,true)) { OT_FAIL; }
                }

                out_strVar = strOutFolder;
                out_bIsRelative = bIsRelative;
                out_bKeyExist = true;
            }
            else
            {
                out_strVar = "";
                out_bIsRelative = false;
                out_bKeyExist = false;
            }

            if (!bPreLoaded)
            {
                config.Reset();
            }

            return true;
        }
    }
    // if we get here, there has been a error!
    OT_FAIL;
}

//static
bool OTPaths::Set(
    OTSettings & config,
    const                  OTString      & strSection,
    const                  OTString      & strKey,
    const                  OTString      & strValue,
    const                  bool          & bIsRelative,
    bool        & out_bIsNewOrUpdated,
    const                  OTString      & strComment
    )
{
    if (!strSection.Exists()) { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strSection" ); OT_FAIL; }
    if (!strKey.Exists())     { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strKey"     ); OT_FAIL; }

    out_bIsNewOrUpdated = false;

    const bool bPreLoaded(config.IsLoaded());

    if (!bPreLoaded)  // we only need to load, if not already loaded.
    {
        config.Reset();
        if(!config.Load()) { OT_FAIL; }
    }

    bool bBoolIsNew(false), bStringIsNew(false);
    OTString  strRelativeKey("");

    strRelativeKey.Format("%s%s", strKey.Get(), OT_CONFIG_ISRELATIVE);

    if(config.Set_bool(strSection, strRelativeKey, bIsRelative, bBoolIsNew, strComment))
    {
        if(config.Set_str(strSection, strKey, strValue, bStringIsNew))
        {
            if(bBoolIsNew && bStringIsNew) //using existing key
            {
                out_bIsNewOrUpdated = true;
            }

            if (!bPreLoaded)
            {
                if(!config.Save()) { OT_FAIL; }
                config.Reset();
            }

            return true;
        }
    }

    // if we get here, there has been a error!
    OT_FAIL;
}


//static
bool OTPaths::FixPath(const OTString & strPath, OTString & out_strFixedPath, const bool & bIsFolder)
{
    if (!strPath.Exists()) { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strPath"    ); OT_FAIL; }

    std::string l_strPath(strPath.Get());
    // first change all back-slashes to forward slashes:
    std::string l_strPath_noBackslash(OTString::replace_chars(l_strPath,"\\",'/'));

    // now we make sure we have the correct trailing "/".

    if ('/' == *l_strPath_noBackslash.rbegin())
    {
        if (bIsFolder)
        {
            out_strFixedPath.Set(l_strPath_noBackslash.c_str());
            return true;
        }
        else
        {
            out_strFixedPath.Set(l_strPath_noBackslash.substr(0, l_strPath_noBackslash.size()-1).c_str());
            return true;
        }
    }
    else
    {
        if (bIsFolder)
        {
            l_strPath_noBackslash += "/";
            out_strFixedPath.Set(l_strPath_noBackslash.c_str());
            return true;
        }
        else
        {
            out_strFixedPath.Set(l_strPath_noBackslash.c_str());
            return true;
        }
    }
}

//static
bool OTPaths::PathExists(const OTString & strPath)
{
    if (!strPath.Exists()) { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strPath" ); OT_FAIL; }

    // remove trailing backslash for stat
    std::string l_strPath(strPath.Get());
    l_strPath = (OTString::replace_chars(l_strPath,"\\",'/'));  // all \ to /

    //std::string l_strPath_stat = l_strPath;
    std::string l_strPath_stat("");

    // remove last / if it exists (for l_strPath_stat)
    if ('/' == *l_strPath.rbegin())
        l_strPath_stat = l_strPath.substr(0, l_strPath.size()-1);
    else l_strPath_stat = l_strPath;

    struct stat st; 
    memset(&st, 0, sizeof(st));

    if (0 == stat(l_strPath_stat.c_str(), &st)) // good we have at-least on a node
    {
        if ('/' != *l_strPath.rbegin())
        {
            long temp_l=0;
            return FileExists(strPath,temp_l);
        }
        else
        {
            return FolderExists(strPath);
        }
    }
    return false;
}

//static
bool OTPaths::FileExists(const OTString & strFilePath, long & nFileLength)
{
    if (!strFilePath.Exists()) { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strFilePath" ); OT_FAIL; }


    // remove trailing backslash for stat
    std::string l_strPath(strFilePath.Get());
    l_strPath = (OTString::replace_chars(l_strPath,"\\",'/'));  // all \ to /

    //std::string l_strPath_stat = l_strPath;
    std::string l_strPath_stat("");

    // remove last / if it exists (for l_strPath_stat)
    if ('/' == *l_strPath.rbegin())
        l_strPath_stat = l_strPath.substr(0, l_strPath.size()-1);
    else l_strPath_stat = l_strPath;


    if ('/' != *l_strPath.rbegin())
    {
        int status=0; // todo security (this whole block)
#ifdef _WIN32
        struct _stat st_buf;
        memset(&st_buf, 0, sizeof(st_buf));
        char filename[4086];    // not sure about this buffer,
        // on windows paths cannot be longer than 4086,
        // so it should be fine... needs more research.
        strcpy_s(filename,l_strPath_stat.c_str());
        status = _stat(filename, &st_buf );
#else
        struct stat st_buf;
        memset(&st_buf, 0, sizeof(st_buf));
        status = stat (l_strPath.c_str(), &st_buf);
#endif

        // check for file
        if (S_ISREG(st_buf.st_mode))
        {
            // good we have a file.
            size_t lFileLength = st_buf.st_size;
            nFileLength = static_cast<long>(lFileLength);
            return true;
        }
    }
    return false;
}

//static
bool OTPaths::FolderExists(const OTString & strFolderPath)
{
    if (!strFolderPath.Exists()) { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strFolderPath" ); OT_FAIL; }

    // remove trailing backslash for stat
    std::string l_strPath(strFolderPath.Get());
    l_strPath = (OTString::replace_chars(l_strPath,"\\",'/'));  // all \ to /

    //std::string l_strPath_stat = l_strPath;
    std::string l_strPath_stat("");

    // remove last / if it exists (for l_strPath_stat)
    if ('/' == *l_strPath.rbegin())
        l_strPath_stat = l_strPath.substr(0, l_strPath.size()-1);
    else l_strPath_stat = l_strPath;

    if ('/' == *l_strPath.rbegin())
    {

        int status=0; // todo security (this whole block)
#ifdef _WIN32
        struct _stat st_buf;
        memset(&st_buf, 0, sizeof(st_buf));
        char filename[4086]="";    // not sure about this buffer,
        // on windows paths cannot be longer than 4086,
        // so it should be fine... needs more research.
        strcpy_s(filename,l_strPath_stat.c_str());
        status = _stat(filename, &st_buf );
#else
        struct stat st_buf;
        memset(&st_buf, 0, sizeof(st_buf));
        status = stat (l_strPath.c_str(), &st_buf);
#endif

        if (S_ISDIR(st_buf.st_mode))
        {
            // good we have a directory.
            return true;
        }
    }
    return false;
}


//static
bool OTPaths::ConfirmCreateFolder(const OTString & strExactPath, bool & out_Exists, bool & out_IsNew)
{
    const bool bExists = (strExactPath.Exists() && !strExactPath.Compare(""));
    OT_ASSERT_MSG(bExists,"OTPaths::ConfirmCreateFolder: Assert failed: no strFolderName\n");

    std::string l_strExactPath(strExactPath.Get());

    if ('/' != *l_strExactPath.rbegin()) return false; // not a directory.

    // Confirm If Directory Exists Already
    out_Exists = PathExists(strExactPath);

    if (out_Exists)
    {
        out_IsNew = false;
        return true;  // Already Have Folder, lets return true!
    }
    else 
    {
        // It dosn't exist: lets create it.

#ifdef _WIN32
        bool bCreateDirSuccess = (_mkdir(strExactPath.Get()) == 0);
#else
        bool bCreateDirSuccess = (mkdir(strExactPath.Get(), 0700) == 0);
#endif

        if (!bCreateDirSuccess) 
        {
            OTLog::vError("OTPaths::%s: Unable To Confirm "
                "Created Directory %s.\n", __FUNCTION__, strExactPath.Get());
            out_IsNew = false;
            out_Exists = false;
            return false;
        }

        // At this point if the folder still doesn't exist, nothing we can do. We
        // already tried to create the folder, and SUCCEEDED, and then STILL failed 
        // to find it (if this is still false.)

        else 
        {
            bool bCheckDirExist = PathExists(strExactPath);

            if (!bCheckDirExist) 
            {
                OTLog::vError("OTPaths::%s: "
                    "Unable To Confirm Created Directory %s.\n", 
                    __FUNCTION__, strExactPath.Get());
                out_IsNew = false;
                out_Exists = false;
                return false;
            }
            else
            {
                out_IsNew = true;
                out_Exists = false;
                return true;  // We have created and checked the Folder
            }
        }
    }
}


//static
bool OTPaths::ToReal(const OTString & strExactPath, OTString & out_strCanonicalPath)
{
    if (!strExactPath.Exists())        { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strExactPath"); OT_FAIL; }

#ifdef _WIN32
#ifdef _UNICODE    

    const char * szPath = strExactPath.Get();
    size_t newsize = strlen(szPath) + 1;
    wchar_t * wzPath = new wchar_t[newsize];

    size_t convertedChars = 0;
    mbstowcs_s(&convertedChars, wzPath, newsize, szPath,4096);

    wchar_t szBuf[4096]= L"";

    if(GetFullPathName(wzPath,4096,szBuf,NULL))
    {
        out_strCanonicalPath.Set(utf8util::UTF8FromUTF16(szBuf));
        return true;
    }
    else 
    {
        out_strCanonicalPath.Set("");
        return false;
    }

#else
    char_t szBuf[4096]="";
    char_t const * szPath = strRealPath.Get();

    if(GetFullPathName(szPath,4096,szBuf,NULL))
    {
        out_strCanonicalPath.Set(szBuf);
        return true;
    }
    else
    {
        out_strCanonicalPath.Set("");
        return false;
    }

#endif
#else

    long path_max=0;
#ifdef PATH_MAX
    path_max = PATH_MAX;
#else
    path_max = pathconf("/", _PC_PATH_MAX);
    if (path_max <= 0)  path_max = 4096;
#endif

    char actualpath [path_max+1];
    actualpath[0] = '\0';
    char *ptr=NULL;

    if (NULL ==  realpath(strExactPath.Get(), actualpath)) {

        if (errno == ENOTDIR) {
            OTLog::vOutput(1,"Input value to RealPath is not a directory: (Realpath: skipping)\n");
            out_strCanonicalPath.Set(strExactPath);
            return true;
        }

        if (errno == ENOENT) {
            OTLog::vOutput(1,"File doesn't exist: (Realpath: skipping)\n");
            out_strCanonicalPath.Set(strExactPath);
            return true;
        }

        OT_ASSERT_MSG((errno != EACCES),"Error (Realpath: EACCES): Unable to build RealPath: access denied");
        OT_ASSERT_MSG((errno != EINVAL),"Error (RealPath: EINVAL): Input value into RealPath was NULL");
        OT_ASSERT_MSG((errno != ELOOP),"Error (RealPath: ELOOP): Resloving links resulted in a loop.");
        OT_ASSERT_MSG((errno != ENAMETOOLONG),"Error (RealPath: ENAMETOOLONG): Name too long.");
        OT_ASSERT_MSG((errno != ERANGE),"Error (RealPath: ERANGE): Resulting path is too long for the buffer");
        OT_ASSERT_MSG((errno != EIO),"Error (RealPath: EIO): Unable to access path.");

        OT_ASSERT_MSG((false),"Error (RealPath: OTHER): Something bad Happend with 'realpath'.");
    }
    out_strCanonicalPath.Set(actualpath);
    return true;
#endif
}

const bool GetExecutable(OTString & strExecutablePath)
{
#ifdef TARGET_OS_MAC
    char bufPath[PATH_MAX + 1]="";
    uint32_t size = sizeof(bufPath);
    int  bufsize = sizeof(bufPath);
    if (_NSGetExecutablePath(bufPath, &size) == 0)
        strExecutablePath.Set(bufPath);
    else return false;
#elif defined __linux__

    char buff[4096]="";
    ssize_t len = ::readlink("/proc/self/exe", buff, sizeof(buff)-1);
    if (len != -1) {  // good
        buff[len] = '\0';
        strExecutablePath.Set(buff);
    }
    else {  // bad
        strExecutablePath.Set("");
        return false;
    }

#elif defined _WIN32

#ifdef _UNICODE
    TCHAR bufPath[ _MAX_PATH+1 ] = L"";
#else
    TCHAR bufPath[ _MAX_PATH+1 ] = "";
#endif

    GetModuleFileName( NULL , bufPath , sizeof(bufPath)/sizeof(TCHAR) ) ;

#ifdef UNICODE
    strExecutablePath.Set(utf8util::UTF8FromUTF16(bufPath));
#else
    strExecutablePath.Set(bufPath);
#endif
#else
    return false;
#endif
    return true;
}

const bool GetCurrentWorking(OTString & strCurrentWorkingPath)
{

#ifdef _WIN32
    // Windows Common
    TCHAR * szPath = NULL;
#ifdef _UNICODE
    // Windows Unicode
#define GetCurrentDir _wgetcwd
#else
    // Windows No-Unicode
#define GetCurrentDir _getcwd
#endif
#else
    // Unix
#define GetCurrentDir getcwd
    char * szPath = NULL;
#endif

    // All
    bool r = ((szPath = GetCurrentDir(NULL,0)) == 0);
    OT_ASSERT(0 != r);

    OTString result;

#ifdef _WIN32
#ifdef _UNICODE
    // Windows Unicode
    strCurrentWorkingPath.Set(utf8util::UTF8FromUTF16(szPath));
#endif
#else
    // Unix
    strCurrentWorkingPath.Set(szPath);
#endif
    // All
    return true;
}

//static
bool OTPaths::GetHomeFromSystem(OTString & out_strHomeFolder)
{
#ifdef _WIN32
#ifdef _UNICODE
    TCHAR szPath[MAX_PATH]=L"";
#else
    TCHAR szPath[MAX_PATH]="";
#endif

    if(SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA|CSIDL_FLAG_CREATE, NULL, 0, szPath))) {
#ifdef UNICODE
        out_strHomeFolder.Set(utf8util::UTF8FromUTF16(szPath));
#else
        out_strHomeFolder.Set(szPath);
#endif
    }
    else { out_strHomeFolder.Set(""); return false; }
#else
    out_strHomeFolder.Set(getenv("HOME"));
#endif
    return true;
}

#ifdef _WIN32

//static
bool OTPaths::Win_GetInstallFolderFromRegistry(OTString & out_InstallFolderPath)
{
    WindowsRegistryTools windowsRegistryTools;




    HKEY hKey=0;
    LONG lRes = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Open-Transactions", 0, KEY_READ, &hKey);
    bool bExistsAndSuccess (lRes == ERROR_SUCCESS);
    bool bDoesNotExistsSpecifically (lRes == ERROR_FILE_NOT_FOUND);

    std::wstring strValueOfBinDir;
    windowsRegistryTools.GetStringRegKey(hKey, L"Path", strValueOfBinDir, L"bad");

    if (bExistsAndSuccess && !bDoesNotExistsSpecifically)
    {
        std::string strInstallPath(OTString::ws2s(strValueOfBinDir));
        out_InstallFolderPath.Set(strInstallPath.c_str());

        return true;
    }


    return false;
}

#endif


//static
bool OTPaths::AppendFolder(OTString & out_strPath, const OTString & strBasePath, const OTString & strFolderName)
{
    if (!strBasePath.Exists())        { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strBasePath"); OT_FAIL; }
    if (!strFolderName.Exists())    { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strFolderName"); OT_FAIL; }

    OTString l_strBasePath_fix(""), l_strFolderName_fix("");

    if(!FixPath(strBasePath,l_strBasePath_fix,true)) return false;
    if(!FixPath(strFolderName,l_strFolderName_fix,true)) return false;

    std::string l_strBasePath(l_strBasePath_fix.Get()), l_strFolderName(l_strFolderName_fix.Get());

    l_strBasePath.append(l_strFolderName);

    const OTString l_strPath(l_strBasePath);

    out_strPath = l_strPath;
    return true;
}

//static
bool OTPaths::AppendFile(OTString & out_strPath, const OTString & strBasePath, const OTString & strFileName)
{
    if (!strBasePath.Exists())    { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strBasePath"); OT_FAIL; }
    if (!strFileName.Exists())    { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strFileName"); OT_FAIL; }

    OTString l_strBasePath_fix(""), l_strFileName_fix("");

    if(!FixPath(strBasePath,l_strBasePath_fix,true)) return false;
    if(!FixPath(strFileName,l_strFileName_fix,false)) return false;

    std::string l_strBasePath(l_strBasePath_fix.Get()), l_strFileName(l_strFileName_fix.Get());

    l_strBasePath.append(l_strFileName);

    const OTString l_strPath(l_strBasePath);

    out_strPath = l_strPath;
    return true;
}

// this function dosn't change the "strRelativePath" so.  It will only fix the strBasePath.
//static
bool OTPaths::RelativeToCanonical(OTString & out_strCanonicalPath, const OTString & strBasePath, const OTString & strRelativePath)
{
    if (!strBasePath.Exists())       { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strBasePath"    ); OT_FAIL; }
    if (!strRelativePath.Exists()) { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strRelativePath" ); OT_FAIL; }

    OTString l_strBasePath_fix("");
    if(!FixPath(strBasePath,l_strBasePath_fix,true)) return false;

    if(strRelativePath.Compare(".")) { out_strCanonicalPath = strBasePath; return true; }  // if ".", return base path.

    std::string l_strBasePath(l_strBasePath_fix.Get()), l_strRelativePath(strRelativePath.Get());

    l_strBasePath.append(l_strRelativePath);

    OTString l_strPath(l_strBasePath), l_strCanonicalPath("");

    if(!ToReal(l_strPath,l_strCanonicalPath)) return false;

    out_strCanonicalPath = l_strCanonicalPath;

    return true;
}

//static
bool OTPaths::BuildFolderPath(const OTString & strFolderPath, bool & out_bFolderCreated)
{
    out_bFolderCreated = false;

    OTString l_strFolderPath_fix(""), l_strFolderPath_real("");

    if (!ToReal(strFolderPath,l_strFolderPath_real)) return false;  // path to real

    if (!FixPath(l_strFolderPath_real,l_strFolderPath_fix,true)) return false; // real to fixed real

    std::string l_strFolderPath(l_strFolderPath_fix.Get());  // fixed real path.

    std::vector<std::string> vFolders;

    OTString::split_byChar(vFolders,l_strFolderPath,"/",OTString::split::no_empties);

    size_t nSize = vFolders.size();

    std::string l_strPathPart("");
    bool l_FolderExists(false), l_bBuiltFolder(false);

    const bool bLog(OTLog::IsInitialized());

    for (size_t i = 0; i < nSize; i++)
    {
#ifndef _WIN32  // aka UNIX
        if(0 == i) l_strPathPart += "/"; //add annother / for root.
#endif
        l_strPathPart += vFolders[i];
        l_strPathPart += "/";

        if(0 == i) continue; // / or x:/ should be skiped.

        OTString strPathPart(l_strPathPart);

        if(!ConfirmCreateFolder(strPathPart, l_FolderExists, l_bBuiltFolder)) return false;
        if (bLog && l_bBuiltFolder) OTLog::vOutput(0,"%s: Made new folder: %s\n", __FUNCTION__, l_strPathPart.c_str());

        if (!out_bFolderCreated && l_bBuiltFolder) out_bFolderCreated = true;
    }
    return true;
}


//static
bool OTPaths::BuildFilePath(const OTString & strFolderPath, bool & out_bFolderCreated)
{
    out_bFolderCreated = false;

    OTString l_strFilePath_fix(""), l_strFilePath_real("");

    if (!ToReal(strFolderPath, l_strFilePath_real)) return false;  // path to real

    if (!FixPath(l_strFilePath_real, l_strFilePath_fix, false)) return false; // real to fixed real

    std::string l_strFilePath(l_strFilePath_fix.Get());  // fixed real path.

    std::vector<std::string> vFolders;

    OTString::split_byChar(vFolders,l_strFilePath,"/",OTString::split::no_empties);

    size_t nSize = vFolders.size();

    std::string l_strPathPart("");
    bool l_FolderExists(false), l_bBuiltFolder(false);

    const bool bLog(OTLog::IsInitialized());

    for (size_t i = 0; i < nSize; i++)
    {
#ifndef _WIN32  // aka UNIX
        if(0 == i) l_strPathPart += "/"; //add annother / for root.
#endif

        l_strPathPart += vFolders[i];

        if((i +1)  == nSize) continue; // file should be skipped

        l_strPathPart += "/";  // is a folder, so should append /

        if(0 == i) continue; // / or x:/ should be skiped.

        OTString strPathPart(l_strPathPart);
        if(!ConfirmCreateFolder(strPathPart, l_FolderExists, l_bBuiltFolder)) return false;
        if (bLog && l_bBuiltFolder) OTLog::vOutput(0,"%s: Made new folder: %s", __FUNCTION__, l_strPathPart.c_str());

        if (!out_bFolderCreated && l_bBuiltFolder) out_bFolderCreated = true;
    }
    return true;
}


#ifdef _WIN32

LONG WindowsRegistryTools::GetDWORDRegKey(HKEY hKey, const std::wstring &strValueName, DWORD &nValue, DWORD nDefaultValue)
{
    nValue = nDefaultValue;
    DWORD dwBufferSize(sizeof(DWORD));
    DWORD nResult(0);
    LONG nError = ::RegQueryValueExW(hKey,
        strValueName.c_str(),
        0,
        NULL,
        reinterpret_cast<LPBYTE>(&nResult),
        &dwBufferSize);
    if (ERROR_SUCCESS == nError)
    {
        nValue = nResult;
    }
    return nError;
}


LONG WindowsRegistryTools::GetBoolRegKey(HKEY hKey, const std::wstring &strValueName, bool &bValue, bool bDefaultValue)
{
    DWORD nDefValue((bDefaultValue) ? 1 : 0);
    DWORD nResult(nDefValue);
    LONG nError = GetDWORDRegKey(hKey, strValueName.c_str(), nResult, nDefValue);
    if (ERROR_SUCCESS == nError)
    {
        bValue = (nResult != 0) ? true : false;
    }
    return nError;
}


LONG WindowsRegistryTools::GetStringRegKey(HKEY hKey, const std::wstring &strValueName, std::wstring &strValue, const std::wstring &strDefaultValue)
{
    strValue = strDefaultValue;
    WCHAR szBuffer[512];
    DWORD dwBufferSize = sizeof(szBuffer);
    ULONG nError;
    nError = RegQueryValueExW(hKey, strValueName.c_str(), 0, NULL, (LPBYTE)szBuffer, &dwBufferSize);
    if (ERROR_SUCCESS == nError)
    {
        strValue = szBuffer;
    }
    return nError;
}

#endif







#ifndef thread_local
#define thread_local
#endif
OTDataFolder * OTDataFolder::pDataFolder;


// static
bool OTDataFolder::Init(const OTString & strThreadContext)
{
    if (NULL != pDataFolder) return false; // we already have a data dir setup.

    if (!strThreadContext.Exists())       { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strThreadContext"    ); OT_FAIL; }
    if (3 > strThreadContext.GetLength())       { OTLog::sError("%s: Too Short: %s !\n", __FUNCTION__, "strThreadContext"    ); OT_FAIL; }

    pDataFolder = new OTDataFolder;  // make the new instance

    pDataFolder->m_bInitialized = false;

    // setup the config instance.
    OTSettings * pSettings(new OTSettings(OTPaths::GlobalConfigFile()));
    pSettings->Reset();
    if (!pSettings->Load()) return false;

    // setup the RelativeKey
    OTString l_strRelativeKey("");
    l_strRelativeKey.Format("%s%s",strThreadContext.Get(),OT_CONFIG_ISRELATIVE);

    bool l_IsRelative(false), l_Exist(false);
    OTString l_strFolderName(""), l_strDataConifgFilename("");

    // check the config for an existing configuration.
    if(!pSettings->Check_bool("data_path",l_strRelativeKey,l_IsRelative,l_Exist)) { return false; }            // is data folder relative

    if (l_Exist)
    {
        if(!pSettings->Check_str("data_path",strThreadContext,l_strFolderName,l_Exist)) { return false; }    // what is the data folder

        if (l_Exist)
        {
            if(!pSettings->Check_str("data_config",strThreadContext,l_strDataConifgFilename,l_Exist)) { return false; }    // what is config file name

            if (l_Exist)
            {
                if (l_IsRelative) // data folder path
                {
                    if(!OTPaths::AppendFolder(pDataFolder->m_strDataFolderPath, OTPaths::AppDataFolder(), l_strFolderName)) { return false; }
                }
                else
                {
                    pDataFolder->m_strDataFolderPath = l_strFolderName;
                }

                // data config file path.
                if(!OTPaths::AppendFile(pDataFolder->m_strDataConifgFilePath, OTPaths::AppDataFolder(), l_strDataConifgFilename)) { return false; }

                pDataFolder->m_bInitialized = true;
                return true;
            }
        }
    }

    // if we get here we do not have a valid config, lets set one.

    // setup the default conifg file-name;
    l_strFolderName.Format("%s%s",strThreadContext.Get(), DATA_FOLDER_EXT);
    l_strDataConifgFilename.Format("%s%s",strThreadContext.Get(), CONFIG_FILE_EXT);

    if(!pSettings->Set_bool("data_path", l_strRelativeKey, true, l_Exist)) { return false; }
    if(!pSettings->Set_str("data_path", strThreadContext, l_strFolderName,l_Exist)) { return false; }
    if(!pSettings->Set_str("data_config", strThreadContext, l_strDataConifgFilename, l_Exist)) { return false; }

    if(!OTPaths::AppendFolder(pDataFolder->m_strDataFolderPath,OTPaths::AppDataFolder(),l_strFolderName)) { return false; }
    if(!OTPaths::AppendFile(pDataFolder->m_strDataConifgFilePath, OTPaths::AppDataFolder(), l_strDataConifgFilename)) { return false; }

    // save config
    if (!pSettings->Save()) return false;
    pSettings->Reset();

    if (NULL != pSettings) delete pSettings;
    pSettings = NULL;

    // have set the default dir, now returning true;

    pDataFolder->m_bInitialized = true;
    return true;
}

// static
bool OTDataFolder::IsInitialized()
{
    if (NULL == pDataFolder) return false; // we already have a data dir setup.

    return pDataFolder->m_bInitialized;
}

// static
bool OTDataFolder::Cleanup()
{
    if (NULL != pDataFolder)
    {
        delete pDataFolder;
        pDataFolder = NULL;
        return true;
    }
    else
    {
        pDataFolder = NULL;
        return false;
    }
}


// static
const OTString OTDataFolder::Get()
{
    if (!OTDataFolder::IsInitialized()) { OT_FAIL; }

    OTString strDataFolder = "";
    if (OTDataFolder::Get(strDataFolder))
    {
        return strDataFolder;
    }
    else
    {
        strDataFolder = "";
        return strDataFolder;
    }
}


// static
bool OTDataFolder::Get(OTString & strDataFolder)
{
    if (NULL != pDataFolder)
    {
        if (true == pDataFolder->m_bInitialized)
        {
            if (pDataFolder->m_strDataFolderPath.Exists())
            {
                strDataFolder = pDataFolder->m_strDataFolderPath;
                return true;
            }
        }
    }

    return false;
}

// static
bool OTDataFolder::GetConfigFilePath(OTString & strConfigFilePath)
{
    if (NULL != pDataFolder)
    {
        if (true == pDataFolder->m_bInitialized)
        {
            if (pDataFolder->m_strDataConifgFilePath.Exists())
            {
                strConfigFilePath = pDataFolder->m_strDataConifgFilePath;
                return true;
            }
        }
    }

    return false;
}


#define    DEFAULT_ACCOUNT         "accounts"
#define    DEFAULT_CERT            "certs"
#define    DEFAULT_CONTRACT        "contracts"
#define    DEFAULT_CREDENTIAL      "credentials"
#define    DEFAULT_CRON            "cron"
#define    DEFAULT_INBOX           "inbox"
#define    DEFAULT_MARKET          "markets"
#define    DEFAULT_MINT            "mints"
#define    DEFAULT_NYM             "nyms"
#define    DEFAULT_NYMBOX          "nymbox"
#define    DEFAULT_OUTBOX          "outbox"
#define    DEFAULT_PAYMENTINBOX    "paymentInbox"
#define    DEFAULT_PUBCRED         "pubcred"
#define    DEFAULT_PUBKEY          "pubkeys"
#define    DEFAULT_PURSE           "purse"
#define    DEFAULT_RECEIPT         "receipts"
#define    DEFAULT_RECORDBOX       "recordBox"
#define    DEFAULT_EXPIREDBOX      "expiredBox"
#define    DEFAULT_SCRIPT          "scripts"
#define    DEFAULT_SMARTCONTRACTS  "smartcontracts"
#define    DEFAULT_SPENT           "spent"
#define    DEFAULT_USERACCT        "useraccounts"

#define    KEY_ACCOUNT             "account"
#define    KEY_CERT                "cert"
#define    KEY_CONTRACT            "contract"
#define    KEY_CREDENTIAL          "credential"
#define    KEY_CRON                "cron"
#define    KEY_INBOX               "inbox"
#define    KEY_MARKET              "market"
#define    KEY_MINT                "mint"
#define    KEY_NYM                 "nym"
#define    KEY_NYMBOX              "nymbox"
#define    KEY_OUTBOX              "outbox"
#define    KEY_PAYMENTINBOX        "paymentinbox"
#define    KEY_PUBCRED             "pubcred"
#define    KEY_PUBKEY              "pubkey"
#define    KEY_PURSE               "purse"
#define    KEY_RECEIPT             "receipt"
#define    KEY_RECORDBOX           "recordbox"
#define    KEY_EXPIREDBOX          "expiredbox"
#define    KEY_SCRIPT              "script"
#define    KEY_SMARTCONTRACTS      "smartcontracts"
#define    KEY_SPENT               "spent"
#define    KEY_USERACCT            "useracct"



OTString OTFolders::s_strAccount("");
OTString OTFolders::s_strCert("");
OTString OTFolders::s_strContract("");
OTString OTFolders::s_strCredential("");
OTString OTFolders::s_strCron("");
OTString OTFolders::s_strInbox("");
OTString OTFolders::s_strMarket("");
OTString OTFolders::s_strMint("");
OTString OTFolders::s_strNym("");
OTString OTFolders::s_strNymbox("");
OTString OTFolders::s_strOutbox("");
OTString OTFolders::s_strPaymentInbox("");
OTString OTFolders::s_strPubcred("");
OTString OTFolders::s_strPubkey("");
OTString OTFolders::s_strPurse("");
OTString OTFolders::s_strReceipt("");
OTString OTFolders::s_strRecordBox("");
OTString OTFolders::s_strExpiredBox("");
OTString OTFolders::s_strScript("");
OTString OTFolders::s_strSmartContracts("");
OTString OTFolders::s_strSpent("");
OTString OTFolders::s_strUserAcct("");



bool OTFolders::GetSetAll()
{
    OTSettings config = OTSettings(OTPaths::GlobalConfigFile());

    config.Reset();

    if(!config.Load()) return false;

    if(!GetSetFolderName(config,KEY_ACCOUNT,         DEFAULT_ACCOUNT,         s_strAccount         )) return false;
    if(!GetSetFolderName(config,KEY_CERT,            DEFAULT_CERT,            s_strCert            )) return false;
    if(!GetSetFolderName(config,KEY_CONTRACT,        DEFAULT_CONTRACT,        s_strContract        )) return false;
    if(!GetSetFolderName(config,KEY_CREDENTIAL,      DEFAULT_CREDENTIAL,      s_strCredential      )) return false;
    if(!GetSetFolderName(config,KEY_CRON,            DEFAULT_CRON,            s_strCron            )) return false;
    if(!GetSetFolderName(config,KEY_INBOX,           DEFAULT_INBOX,           s_strInbox           )) return false;
    if(!GetSetFolderName(config,KEY_MARKET,          DEFAULT_MARKET,          s_strMarket          )) return false;
    if(!GetSetFolderName(config,KEY_MINT,            DEFAULT_MINT,            s_strMint            )) return false;
    if(!GetSetFolderName(config,KEY_NYM,             DEFAULT_NYM,             s_strNym             )) return false;
    if(!GetSetFolderName(config,KEY_NYMBOX,          DEFAULT_NYMBOX,          s_strNymbox          )) return false;
    if(!GetSetFolderName(config,KEY_OUTBOX,          DEFAULT_OUTBOX,          s_strOutbox          )) return false;
    if(!GetSetFolderName(config,KEY_PAYMENTINBOX,    DEFAULT_PAYMENTINBOX,    s_strPaymentInbox    )) return false;
    if(!GetSetFolderName(config,KEY_PUBCRED,         DEFAULT_PUBCRED,         s_strPubcred         )) return false;
    if(!GetSetFolderName(config,KEY_PUBKEY,          DEFAULT_PUBKEY,          s_strPubkey          )) return false;
    if(!GetSetFolderName(config,KEY_PURSE,           DEFAULT_PURSE,           s_strPurse           )) return false;
    if(!GetSetFolderName(config,KEY_RECEIPT,         DEFAULT_RECEIPT,         s_strReceipt         )) return false;
    if(!GetSetFolderName(config,KEY_RECORDBOX,       DEFAULT_RECORDBOX,       s_strRecordBox       )) return false;
    if(!GetSetFolderName(config,KEY_EXPIREDBOX,      DEFAULT_EXPIREDBOX,      s_strExpiredBox      )) return false;
    if(!GetSetFolderName(config,KEY_SCRIPT,          DEFAULT_SCRIPT,          s_strScript          )) return false;
    if(!GetSetFolderName(config,KEY_SMARTCONTRACTS,  DEFAULT_SMARTCONTRACTS,  s_strSmartContracts  )) return false;
    if(!GetSetFolderName(config,KEY_SPENT,           DEFAULT_SPENT,           s_strSpent           )) return false;
    if(!GetSetFolderName(config,KEY_USERACCT,        DEFAULT_USERACCT,        s_strUserAcct        )) return false;

    if(!config.Save()) return false;

    config.Reset();

    return true;
}

const OTString & OTFolders::Account()         { return GetFolder(s_strAccount         ); }
const OTString & OTFolders::Cert()            { return GetFolder(s_strCert            ); }
const OTString & OTFolders::Contract()        { return GetFolder(s_strContract        ); }
const OTString & OTFolders::Credential()      { return GetFolder(s_strCredential      ); }
const OTString & OTFolders::Cron()            { return GetFolder(s_strCron            ); }
const OTString & OTFolders::Inbox()           { return GetFolder(s_strInbox           ); }
const OTString & OTFolders::Market()          { return GetFolder(s_strMarket          ); }
const OTString & OTFolders::Mint()            { return GetFolder(s_strMint            ); }
const OTString & OTFolders::Nym()             { return GetFolder(s_strNym             ); }
const OTString & OTFolders::Nymbox()          { return GetFolder(s_strNymbox          ); }
const OTString & OTFolders::Outbox()          { return GetFolder(s_strOutbox          ); }
const OTString & OTFolders::PaymentInbox()    { return GetFolder(s_strPaymentInbox    ); }
const OTString & OTFolders::Pubcred()         { return GetFolder(s_strPubcred         ); }
const OTString & OTFolders::Pubkey()          { return GetFolder(s_strPubkey          ); }
const OTString & OTFolders::Purse()           { return GetFolder(s_strPurse           ); }
const OTString & OTFolders::Receipt()         { return GetFolder(s_strReceipt         ); }
const OTString & OTFolders::RecordBox()       { return GetFolder(s_strRecordBox       ); }
const OTString & OTFolders::ExpiredBox()      { return GetFolder(s_strExpiredBox      ); }
const OTString & OTFolders::Script()          { return GetFolder(s_strScript          ); }
const OTString & OTFolders::SmartContracts()  { return GetFolder(s_strSmartContracts  ); }
const OTString & OTFolders::Spent()           { return GetFolder(s_strSpent           ); }
const OTString & OTFolders::UserAcct()        { return GetFolder(s_strUserAcct        ); }


