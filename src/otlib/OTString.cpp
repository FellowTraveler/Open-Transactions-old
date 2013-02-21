/************************************************************************************
 *    
 *  OTString.cpp
 *  
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



//#include <cstdarg> // moved to header for va_list
#include <cstdio>
#include <cstring> // The C one 
#include <cstdlib>
#include <cctype>

#include <string> // The C++ one 
#include <fstream> // The C++ one
#include <iostream>
#include <sstream>

#include <cstdarg>

//#include <map>


#ifndef _WIN32
#include <wordexp.h>
#endif



#include "OTStorage.h"

#include "OTString.h"
#include "OTASCIIArmor.h"
#include "OTPassword.h"
#include "OTIdentifier.h"
#include "OTContract.h"
#include "OTPseudonym.h"

#include "OTLog.h"








/*
 int vsnprintf(char *str, size_t size, const char *format, va_list ap);

       Upon successful return, these functions return the number of characters
       printed  (not  including  the  trailing  '\0'  used  to  end  output to
       strings).  The functions snprintf() and vsnprintf() do not  write  more
       than size bytes (including the trailing '\0').  If the output was trun-
       cated due to this limit then the return value is the number of  charac-
       ters (not including the trailing '\0') which would have been written to
       the final string if enough space had been  available.  Thus,  a  return
       value  of  size  or more means that the output was truncated. (See also
       below under NOTES.)  If an output  error  is  encountered,  a  negative
       value is returned.
 
 -- Therefore if size was 500, and it printed 100 characters (indices 0..99),  
    then it will return 100, even though the actual bytes used are 101 (indices 0..100), 
    with the null terminator stored in the 101st byte (at index 100.) size (500)
    is not <= nsize (100) so we never enter the 'if' block in vformat.
 
 -- vsnprintf does not write more than size bytes, INCLUDING the null terminator.
    So this is actually the buffer size we are giving it (not the fmt string size.)
 
 -- If output was truncated then the return value is the number of characters which
    WOULD have been written, IF space had been available (NOT including the null
    terminator.) So if size is 80, but the final output would have been 90 in length
    (without terminator--91 with terminator), then it will return 90.
 
 */
//inline bool vformat(const char * fmt, va_list vl, std::string & str_output)
//static
bool OTString::vformat(const char * fmt, va_list * pvl, std::string & str_Output)
{
    OT_ASSERT(NULL != fmt);
    OT_ASSERT(NULL != pvl);
    // ------------------
	int size=0;
	int nsize=0;
	char * buffer = NULL;
	va_list args;

#ifdef _WIN32
	va_list args_2 = *pvl;  //windows only.

	args = *pvl;
	size = _vscprintf(fmt,args) + 1;
#else
	va_copy(args, *pvl);
	size = 512;
#endif

    // ------------------------------------    
	buffer = new char[size+100];
	OT_ASSERT(NULL != buffer);
	OTPassword::zeroMemory(buffer, size+100);
    // ------------------------------------    

#ifdef _WIN32
	nsize = vsnprintf_s(buffer,size,size,fmt,args_2);
#else
	nsize = vsnprintf(buffer,size,fmt,args);
	va_end(args);
#endif

	OT_ASSERT(nsize >= 0);

    // fail -- delete buffer and try again
    // If nsize was 1024 bytes, then that would mean that it printed 1024 characters,
    // even though the actual string must be 1025 in length (to have room for the null
    // terminator.)
    // If size, the ACTUAL buffer, was 1024 (that is, if size <= nsize) then size would
    // LACK the necessary space to store the 1025th byte containing the null terminator.
    // Therefore we are forced to delete the buffer and make one that is nsize+1, so that
    // it will be 1025 bytes and thus have the necessary space for the terminator
    //
    if (size <= nsize) 
    {
	size  = nsize+1;
	delete buffer; buffer = NULL;
	buffer = new char[size+100];
	OT_ASSERT(NULL != buffer);
	OTPassword::zeroMemory(buffer, size+100);
	// ------------------------------------
#ifdef _WIN32
	nsize = vsnprintf_s(buffer,size,size,fmt,*pvl);
	va_end(args);
	va_end(args_2);
#else
	nsize = vsnprintf(buffer,size,fmt,*pvl);
#endif
	// ------------------------------------
	OT_ASSERT( nsize >= 0    );
    }
    OT_ASSERT(  size >  nsize);
    // ------------------------------------
    str_Output = buffer;
    delete buffer; buffer = NULL;
    return true;
}

// -----------------------------------------------------------

// I've greped the code for strnlen, it seems like that we are not using it.
//  This is not the correct solution for strnlen being insecure on windows.
// The correct solution is to us the 'strnlen_s' function on windows.

//#ifndef __linux__
//extern "C" { 
//  size_t strnlen(const char *s, size_t max) 
//   {
//       register const char *p;
//       for(p = s; *p && max--; ++p);
//       return(p - s);
//   }
//}
//#endif

// ---------------------------------------------------------


// TODO  Make sure I follow this advice.

/*
 

It is not wise to use the ANSI standard strcpy function because of the possibility of 
unchecked buffer overflows. The better strncpy function has the problem that it does not 
properly terminate the string. The following strlcpy and strlcat functions are simple 
implementations that manage the problems of their original ANSI ancestors.

// #include <string.h>

size_t strlcpy(char *d, const char *s, size_t bufsize)
{
	size_t len;
	size_t ret;
	
	if (!d || !s) return 0;
	len = strlen(s);
	ret = len;
	if (bufsize <= 0) return 0;
	if (len >= bufsize) len = bufsize-1;
	memcpy(d, s, len);
	d[len] = 0;
	 
	return ret;
}

size_t strlcat(char *d, const char *s, size_t bufsize)
{
	size_t len1;
	size_t len2;
	size_t ret;
	
	if (!d || !s || bufsize <= 0) return 0;
	
	len1 = strlen(d);
	len2 = strlen(s);
	ret = len1 + len2;
	if (len1+len2 >= bufsize) 
	{
		len2 = bufsize - (len1+1);
	}
	if (len2 > 0) 
	{
		memcpy(d+len1, s, len2);
		d[len1+len2] = 0;
	}
	return ret;
}
 */


// TODO: Security: should change OTString to use size_t and MAX_SIZE instead of whatever it uses now. Safer.


/* 
 WINDOWS:
errno_t strcpy_s(
                 char *strDestination,
                 size_t numberOfElements,   // MAX SIZE of destination.
                 const char *strSource);
 
 UNIX:
 size_t strlcpy(char * restrict dst,
                const char * restrict src,
                size_t size); // MAX SIZE of destination.

 extern "C" size_t strnlen(const char *s, size_t max); // Moved the definition of this function to OTPassword.cpp
 */
// ---------------------------------------------------------

//static
bool OTString::safe_strcpy(char * dest,
                           const
                           char * src,
                           // -----------------
                           size_t dest_size,
                           bool   bZeroSource/*=false*/) // if true, initializes the source buffer to zero after the copying is done.
{
    // Make sure they don't overlap.
    //
    OT_ASSERT_MSG(false == ((src > dest) && (src < (dest + dest_size))), "ASSERT: safe_strcpy: Unexpected memory overlap.\n");
    // ---------------------------------
    bool bSuccess = false;

    const size_t src_length = OTString::safe_strlen(src, MAX_STRING_LENGTH); 
    // ---------------------------------------
    OT_ASSERT_MSG(dest_size > src_length, "OTString::safe_strcpy: ASSERT: src_length must be less than dest_size.\n");
    
#ifdef _WIN32
    bSuccess = (0 == strcpy_s(dest, dest_size, src));
#else
    size_t src_cpy_length = strlcpy(dest, src, dest_size);
    bSuccess = (src_length == src_cpy_length); // If the size it DID copy is equal to the size it TRIED to copy, then it was a succcess.
#endif
    
    // Notice: we don't zero out the source unless we were successful (AND unless we were asked to.)
    //
    if (bSuccess && bZeroSource)
        OTPassword::zeroMemory(const_cast<char *>(src), static_cast<uint32_t> (src_length));
        
    return bSuccess;
}
// ---------------------------------------------------------

//static
size_t OTString::safe_strlen(const char * s, size_t max)
{
    OT_ASSERT_MSG(max <= MAX_STRING_LENGTH, "OT_String::safe_strlen: ASSERT: max length passed in is longer than allowed.\n");
    
    return strnlen(s, max); 
}


// ---------------------------------------------------------

//static
std::string & OTString::trim(std::string& str)
{
	std::string whitespaces (" \t\f\v\n\r");
	// -----------------------------------
    
	size_t found = str.find_first_not_of(whitespaces);
	
	if (found != std::string::npos)
    {
		str.erase(0, found);
    }
	// -----------------------------------
    
	found = str.find_last_not_of(whitespaces);
	
	if (found != std::string::npos)
    {
		str.erase(found+1);
    }
	// -----------------------------------

//	OTLog::vError("(DEBUGGING OTString.cpp) CONTRACT HAS BEEN TRIMMED!!!  RESULT: \n\n***BEGIN TRIM DATA:%s******END TRIM DATA\n\n",
//				  str.c_str()); // todo temp remove
	return str;
}



const std::string OTString::replace_chars(
	const std::string & str,
	const std::string & charsFrom,
	const char & charTo
	)
{
	std::string l_str(str);
	size_t found;

	found=str.find_first_of(charsFrom);
	while (found!=std::string::npos)
	{
		l_str[found]=charTo;
		found=str.find_first_of(charsFrom,found+1);
	}
	return l_str;
}

#ifdef _WIN32

std::wstring OTString::s2ws(const std::string& s)
{
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0); 
    std::wstring r(len, L'\0');
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, &r[0], len);
    return r;
}


std::string OTString::ws2s(const std::wstring& s)
{
    int len;
    int slength = (int)s.length() + 1;
    len = WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, 0, 0, 0, 0); 
    std::string r(len, '\0');
    WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, &r[0], len, 0, 0); 
    return r;
}

#endif

// ----------------------------------------------------------------------


// ------ I cannot vouch for these top four functions, I wrote them so long ago.
// ------ But they can't hurt and I don't think they're being used anyway so I left them in for now.


bool OTString::operator >(const OTString &s2) const 
{
	if(s2.m_lLength == 0) {
		return(true);
	}
	if(m_lLength == 0) {
		return(false);
	}
	if(strcmp(m_strBuffer, s2.m_strBuffer) <= 0)  {
		return(false);
	}
	return(true);
}

// ----------------------------------------------------------------------

bool OTString::operator <(const OTString &s2)  const 
{
	if(m_lLength == 0) {
		return(true);
	}
	if(s2.m_lLength == 0) {
		return(false);
	}
	if(strcmp(m_strBuffer, s2.m_strBuffer) >= 0) {
		return(false);
	}
	return(true);
}
// ----------------------------------------------------------------------

bool OTString::operator <=(const OTString &s2)  const
{
	if(m_lLength == 0) {
		return(true);
	}
	if(s2.m_lLength == 0) {
		return(false);
	}
	if(strcmp(m_strBuffer, s2.m_strBuffer) > 0) {
		return(false);
	}
	return(true);
}
// ----------------------------------------------------------------------


bool OTString::operator >=(const OTString &s2)  const
{
	if(s2.m_lLength == 0) {
		return(true);
	}
	if(m_lLength == 0) {
		return(false);
	}
	if(strcmp(m_strBuffer, s2.m_strBuffer) < 0) {
		return(false);
	}
	return(true);
}

// ----------------------------------------------------------------------

void fwrite_string(std::ostream & ofs, const char *str)
{
	char * pchar;
	
	pchar  = (char *)str;
	
	if(str)
		while(*pchar) {
			if(*pchar != '\r')
				ofs << *pchar;
			pchar++;
		}	
}
// ----------------------------------------------------------------------

/*
void fwrite_string(FILE *fl, const char *str)
{
	char * pchar;
	
	pchar  = (char *)str;
	
	if(str)
		while(*pchar) {
			if(*pchar != '\r')
				fputc(*pchar, fl);
			pchar++;
		}
}
*/
// ----------------------------------------------------------------------

// Note: UNIX-only (for now.)
//
bool OTString::TokenizeIntoKeyValuePairs(std::map<std::string, std::string> & mapOutput) const
{
#ifndef _WIN32
	if (!Exists())
		return true;
	// --------------
	wordexp_t exp_result;
    
    exp_result.we_wordc = 0;
    exp_result.we_wordv = NULL;
    exp_result.we_offs  = 0;

	if (wordexp(Get(), &exp_result, 0)) // non-zero == failure.
	{
		OTLog::vError("OTString::TokenizeIntoKeyValuePairs: Error calling wordexp() "
                      "(to expand user-defined script args.)\nData: %s\n", Get());
//		wordfree(&exp_result); 
		return false;
	}
	// ----------------------------
	
    if ((exp_result.we_wordc > 0) && (NULL != exp_result.we_wordv))
    {
        // wordexp tokenizes by space (as well as expands, which is why I'm using it.)
        // Therefore we need to iterate through the tokens, and create a single string
        // with spaces between the tokens.
        //
        for (unsigned int i = 0; 
             (i < (exp_result.we_wordc - 1))      && 
             (exp_result.we_wordv[i]   != NULL)   && 
             (exp_result.we_wordv[i+1] != NULL); // odd man out. Only PAIRS of strings are processed!
             i += 2)
        {
            const std::string str_key = exp_result.we_wordv[i];
            const std::string str_val = exp_result.we_wordv[i+1];
            
            mapOutput.insert(std::pair<std::string, std::string>(str_key, str_val));		
        }
        
        wordfree(&exp_result); 
    }
	// --------------
	return true;
#else
	return false;
#endif
}
// ----------------------------------------------------------------------


// 
/*
 WCHAR szPassword[MAX_PATH];
 
 // Retrieve the password
 if (GetPasswordFromUser(szPassword, MAX_PATH))    
 
 UsePassword(szPassword); // <===========
 
 // WINDOWS MEMORY ZEROING CODE:
 SecureZeroMemory(szPassword, sizeof(szPassword));
 
 
 // NEED to get linux / etc versions as well, and use them in OTString
 // as well as anywhere that std::string is used! Todo security!
 // Can probably write a custom deallocator for the std::string and then
 // zero it out similarly.
 */
// ----------------------------------------------------------------------

void OTString::zeroMemory()
{
   	if (NULL != m_strBuffer)
	{
        OTPassword::zeroMemory(m_strBuffer, m_lLength);
    } 
}
// ----------------------------------------------------------------------

void OTString::Release_String(void)
{
	if (NULL != m_strBuffer)
	{
		// for security purposes. 
        //
        OTPassword::zeroMemory(m_strBuffer, m_lLength);
//		memset(m_strBuffer, 0, m_lLength);
		delete [] m_strBuffer;
	}
	m_strBuffer = NULL;
	m_lPosition = 0;
	m_lLength   = 0;
}

// ----------------------------------------------------------------------

void OTString::Release(void)
{
	Release_String();
    
    // no need to use ot_super here, since OTString is a "base class."
}

// ----------------------------------------------------------------------


// ***** Construction -- Destruction ***** ------------------------------

OTString::~OTString()
{
	Release_String();
}


// ----------------------------------------------------------------------

void OTString::Initialize()
{
	m_lLength   = 0;
	m_lPosition = 0;
	m_strBuffer  = NULL;
}
// ----------------------------------------------------------------------


OTString::OTString() : m_lLength(0), m_lPosition(0), m_strBuffer(NULL)
{
//	Initialize();
}
// ----------------------------------------------------------------------

// This constructor gets the string version of the ID passed in,
// and sets that string on this object. (For when you need a string
// version of an ID.)
OTString::OTString(const OTIdentifier & theValue) : m_lLength(0), m_lPosition(0), m_strBuffer(NULL)
{
//	Initialize();
	
	if (theValue.GetSize() > 0)
		theValue.GetString(*this);
}
// ----------------------------------------------------------------------

OTString::OTString(const OTContract & theValue) : m_lLength(0), m_lPosition(0), m_strBuffer(NULL)
{
//	Initialize();
	
	((OTContract &)theValue).SaveContractRaw(*this);	
}

// ----------------------------------------------------------------------


// This version base64-DECODES the ascii-armored string passed in,
// and then sets the decoded plaintext string onto this object.
OTString::OTString(const OTASCIIArmor & strValue) : m_lLength(0), m_lPosition(0), m_strBuffer(NULL)
{
//	Initialize();
	
	if (strValue.Exists())
		strValue.GetString(*this);
}

// ----------------------------------------------------------------------

// This version base64-DECODES the ascii-armored signature that's passed in,
// and then sets the decoded plaintext signature onto this object.
// You would only do this when the signature, decoded, is normally in ASII
// form. Actually, that is regularly NOT the case--signatures are usually in
// binary form.
// But Lucre signatures, as used in this library, ARE in text form, so I
// provided this constructor to easily base64-decode them to prepare for
// loading into a bio and then a Lucre object.
OTString::OTString(const OTSignature & strValue) : m_lLength(0), m_lPosition(0), m_strBuffer(NULL)
{
//	Initialize();
	
	if (strValue.Exists())
		strValue.GetString(*this);
}

// ----------------------------------------------------------------------

OTString::OTString(OTPseudonym & theValue) : m_lLength(0), m_lPosition(0), m_strBuffer(NULL)
{
//	Initialize();
	
	theValue.SavePseudonym(*this);
}

// ----------------------------------------------------------------------


OTString::OTString(const OTString & strValue) : m_lLength(0), m_lPosition(0), m_strBuffer(NULL)
{
//	Initialize();
	LowLevelSetStr(strValue);
}

// ----------------------------------------------------------------------


OTString::OTString(const char * new_string) : m_lLength(0), m_lPosition(0), m_strBuffer(NULL)
{
//	Initialize();
	LowLevelSet(new_string, 0);
}

// ----------------------------------------------------------------------


OTString::OTString(const char * new_string, size_t sizeLength) : m_lLength(0), m_lPosition(0), m_strBuffer(NULL)
{
//	Initialize();
	LowLevelSet(new_string, static_cast<uint32_t> (sizeLength));
}

// ----------------------------------------------------------------------


OTString::OTString(const std::string& new_string) : m_lLength(0), m_lPosition(0), m_strBuffer(NULL)
{
//	Initialize();
	LowLevelSet(new_string.c_str(), static_cast<uint32_t> (new_string.length()));
}
// ----------------------------------------------------------------------



// ----------------------------------------------------------------------


// If 10 is passed in, then 11 will be allocated,
// then the data is copied, and then the result[10] (11th element)
// is set to 0. This way the original 10-length string is untouched.
//
char *str_dup2(const char *str, uint32_t length) // length doesn't/shouldn't include the byte for the terminating 0.
{
	char * str_new = new char [length + 1]; // CREATE EXTRA BYTE OF SPACE FOR \0 (NOT PART OF LENGTH)
	OT_ASSERT(NULL != str_new);
	
#ifdef _WIN32
	strncpy_s(str_new, length+1, str, length);
#else
	strncpy(str_new, str, length);
#endif
	
	// INITIALIZE EXTRA BYTE OF SPACE
	//
	// If length is 10, then buffer is created with 11 elements, 
	// indexed from 0 (first element) through 10 (11th element).
	// 
	// Therefore str_new[length==10] is the 11th element, which was
	// the extra one created on our buffer, to store the \0 null terminator.
	//
	// This way I know I'm never cutting off data that was in the string itself.
	// Rather, I am only setting to 0 an EXTRA byte that I created myself, AFTER
	// the string's length itself.
	//
	str_new[length] = '\0'; 
	
	return str_new;
}

// ----------------------------------------------------------------------

void OTString::LowLevelSetStr(const OTString & strBuf)
{ 
	OT_ASSERT(NULL == m_strBuffer); // otherwise memory leak.
	
	if (strBuf.Exists()) 
	{ 
		m_lLength = (MAX_STRING_LENGTH > strBuf.m_lLength) ?
			strBuf.m_lLength
		  : 
			(MAX_STRING_LENGTH-1); 
		
        OT_ASSERT_MSG(m_lLength < (MAX_STRING_LENGTH-10), "ASSERT: OTString::LowLevelSetStr: Exceeded MAX_STRING_LENGTH! (String would not have fully fit anyway--it would have been truncated here, potentially causing data corruption.)"); // 10 being a buffer.
        
		m_strBuffer = str_dup2(strBuf.m_strBuffer, m_lLength); 
	} 
}

// ----------------------------------------------------------------------

// if nEnforcedMaxLength is 10, then it will actually enforce a string at 9 length.
// That is, up through index 8 (9th byte) instead of index 9 (10th byte.) This is because
// we are assuming the buffer has no more room than 10 bytes, and thus index 9 (10th byte)
// MUST be reserved for the null terminating '\0'. Therefore, if the string is actually 10
// bytes long, necessitating an 11th byte for the null terminator, then you should pass 11
// here, aka OTString::GetLength()+1. That way the entire string will fit.
//
void OTString::LowLevelSet(const char * new_string, uint32_t nEnforcedMaxLength)
{
	OT_ASSERT(NULL == m_strBuffer); // otherwise memory leak.
	
	if (NULL != new_string)
	{
		uint32_t nLength = (nEnforcedMaxLength > 0) ?
            static_cast<uint32_t> (OTString::safe_strlen(new_string, static_cast<size_t>(nEnforcedMaxLength))) 
 		  : 
			static_cast<uint32_t> (OTString::safe_strlen(new_string, static_cast<size_t>(MAX_STRING_LENGTH-1))); // room for \0

		// don't bother allocating memory for a 0 length string.
		if (0 == nLength)
			return;

        OT_ASSERT_MSG(nLength < (MAX_STRING_LENGTH-10), "ASSERT: OTString::LowLevelSet: Exceeded MAX_STRING_LENGTH! (String would not have fully fit anyway--it would have been truncated here, potentially causing data corruption.)"); // 10 being a buffer.        
        // ------------------------------------------
        // Add null terminator to source string JUST IN CASE...
        // Update: this is const, so we can't change it. However, the strnlen above will only have
        // worked if there was a null terminator, since otherwise we would have hit the above ASSERT.
        // Therefore we should be safe enough without it here...
        //
//      new_string[nLength] = '\0';
        // ------------------------------------------
		m_strBuffer = str_dup2(new_string, nLength);
		
		if (NULL != m_strBuffer)
			m_lLength = nLength;
		else
			m_lLength = 0;
	}
}

// ----------------------------------------------------------------------

// The source is probably NOT null-terminated.
// Size must be exact (not a max.)
//
bool OTString::MemSet(const char * pMem, uint32_t theSize) // if theSize is 10...
{
	Release();
	// -------------------	
	if ((NULL == pMem) || (theSize < 1))
		return true;
	// -------------------
	char * str_new = new char [theSize + 1]; // then we allocate 11 
	OT_ASSERT(NULL != str_new);
	// -------------------	
    OTPassword::zeroMemory(str_new, theSize + 1);
	// -------------------
//  void * OTPassword::safe_memcpy(void   * dest,
//                                 uint32_t dest_size,
//                                 const
//                                 void   * src,
//                                 uint32_t src_length,
//                                 bool     bZeroSource/*=false*/)

    OTPassword::safe_memcpy(static_cast<void*>(str_new),
                            theSize + 1,
                            pMem,
                            theSize);
//	memcpy(static_cast<void*>(str_new), pMem, theSize); // then we copy 10 bytes
	
    // todo optimize: This is probably superfluous due to the zeroMemory above.
    // Then again, we might want to remove that, and then keep this. 
	str_new[theSize] = '\0'; // add null-terminator. (I deliberately made this buffer 1 byte larger so I could put the 0 at the end.) Here the index[10] is the 11th byte, since we're counting from 0.
    // ------------------------------------------    
    // Calculate the length (in case there was a null terminator in the middle...)
    // This way we're guaranteed to have the correct length.
    //
    uint32_t nLength = static_cast<uint32_t> (OTString::safe_strlen(str_new, static_cast<size_t>(theSize)));
	str_new[nLength] = '\0'; // This SHOULD be superfluous as well...
    // ------------------------------------------    
	m_lLength	= nLength; // the length doesn't count the 0.
	m_strBuffer	= str_new;
    // ------------------------------------------
	return true;
}


// ----------------------------------------------------------------------

OTString& OTString::operator=(OTString rhs)
{
	this->swap(rhs);
	return *this;
}

void OTString::swap(OTString & rhs)
{ 
	std::swap(m_lLength, rhs.m_lLength); 
	std::swap(m_lPosition, rhs.m_lPosition); 
	std::swap(m_strBuffer, rhs.m_strBuffer); 
} 
// ----------------------------------------------------------------------

bool OTString::At(uint32_t lIndex, char &c) const
{ 
	if (lIndex < m_lLength)
	{ 
		c = m_strBuffer[lIndex]; 
		return true; 
	} 
	else 
		return false; 
}
// ----------------------------------------------------------------------

bool OTString::Exists(void) const 
{ 
	return (NULL != m_strBuffer) ? true : false; 
}
// ----------------------------------------------------------------------

uint32_t OTString::GetLength(void) const 
{ 
	return m_lLength; 
}
// ----------------------------------------------------------------------

const char * OTString::Get(void) const 
{ 
	return (NULL != m_strBuffer) ? const_cast<const char*>(m_strBuffer) : "";
}


// ----------------------------------------------------------------------

// new_string MUST be at least nEnforcedMaxLength in size if nEnforcedMaxLength is passed in at all.
// That's because this function forces the null terminator at that length of the string minus 1.

void OTString::Set(const char * new_string, uint32_t nEnforcedMaxLength/*=0*/)
{ 
	Release(); 
	
	if (NULL == new_string) 
		return; 
	
	LowLevelSet(new_string, nEnforcedMaxLength); 
}

// ----------------------------------------------------------------------

void OTString::Set(const OTString & strBuf) 
{ 
	Release();
	
	LowLevelSetStr(strBuf);
}

// ----------------------------------------------------------------------

/*
OTString& OTString::operator=(const char * new_string)
{
	OTString strTemp(new_string);
	
	this->swap(strTemp);
	return *this;
}
*/

/*
OTString& OTString::operator=(const std::string & strValue)
{
	OTString strTemp(strValue.c_str());
	
	this->swap(strTemp);
	return *this;
}
*/
// ----------------------------------------------------------------------


// 
bool OTString::operator ==(const OTString &s2) const
{
	// If they are not the same length, return false
	if (m_lLength != s2.m_lLength) 
    {
	  return(false);
	}
	
	// At this point we know they are at least the same length.
	// Next--are they both 0? If they are both 0, return true
	if (m_lLength == 0 && s2.m_lLength == 0) {
	  return(true);
	}

	// At this point we have 2 identical-length strings.
	// Now we call strcmp and convert it to true or false.
	if (strcmp(m_strBuffer, s2.m_strBuffer) == 0) { // TODO security: use a replacement for strcmp.
	  return(true);
	}
	return(false);
}

// ----------------------------------------------------------------------




// ***** Operations ***** ------------------------------

// Compare is simple.  True if they match, False if they don't match.
bool OTString::Compare(const char * strCompare) const
{
	if (NULL == m_strBuffer || NULL == strCompare) 
    {
		return false;
	}
	
	char * s1 = m_strBuffer;
	char * s2 = (char*)strCompare;
	
	for( ; *s1 && *s2; s1++, s2++) 
		if(*s1 != *s2)
			return false;
	
	if(*s1 != *s2)
		return false;
	
	return true; 
}
// ----------------------------------------------------------------------

bool OTString::Compare(const OTString& strCompare) const
{
	if (NULL == m_strBuffer || !strCompare.Exists()) 
    {
		return false;
	}
	
	char * s1 = m_strBuffer;
	const char * s2 = strCompare.Get();
	
	for( ; *s1 && *s1 != ' '; s1++, s2++) 
		if(*s1 != *s2)
			return false;
	
	return true; 
}

// ----------------------------------------------------------------------

// Contains is like compare.  True if the substring is there, false if not.
// I was going to return the position but then I realized I never needed it.
// Should be easy to modify if the need arises.
bool OTString::Contains(const char * strCompare) const
{
	if (NULL == m_strBuffer || NULL == strCompare) 
	{
		return false;
	}
	
	if (strstr(m_strBuffer, strCompare))
		return true;
	
	return false;
}

// ----------------------------------------------------------------------

bool OTString::Contains(const OTString& strCompare) const
{
	if (NULL == m_strBuffer || !strCompare.Exists()) 
	{
		return false;
	}
	
	if (strstr(m_strBuffer, strCompare.Get()))
		return true;
	
	return false;
}

// ----------------------------------------------------------------------





void OTString::OTfgets(std::istream & ifs)
{

//	// _WIN32
//	static char * buffer = NULL;
//	
//	if (NULL == buffer)
//	{
//        // todo threadsafe: this static var is likely not threadsafe at all.
//        //
//		buffer = new char[MAX_STRING_LENGTH]; // This only happens once. Static var.
//		OT_ASSERT(NULL != buffer);
//	}
//	
//	buffer[0] = '\0';
//	buffer[MAX_STRING_LENGTH-1] = '\0';
//	// _end _WIN32
//
//	if (ifs.getline(buffer, MAX_STRING_LENGTH-1)) // delimiter defaults to '\n'
//	{
//		buffer[strlen(buffer)] = '\0';
//		
//		Set(buffer);
//	}	

    std::stringbuf sb;    
    ifs.get(sb); // delimiter defaults to '\n'
    
	if (ifs.good()) 
	{
        const std::string str_output = sb.str();

		Set(str_output.c_str());
	}	
}


// ----------------------------------------------------------------------

void OTString::ConvertToLowerCase()
{
	if (m_strBuffer == NULL) 
    {
		return;
	}
	
	for(char * s1 = m_strBuffer; *s1; s1++)
		*s1 = static_cast<char>(tolower(*s1));
}

// ----------------------------------------------------------------------

void OTString::ConvertToUpperCase()
{
	if (m_strBuffer == NULL) 
    {
		return;
	}
	
	for(char * s1 = m_strBuffer; *s1; s1++)
		*s1 = static_cast<char>(toupper(*s1));
}
// ----------------------------------------------------------------------

void OTString::Truncate(uint32_t lAt)
{
	OTString strTruncated;
	
	strTruncated.Set(this->Get(), lAt);
	
	this->Set(strTruncated);
}

// ----------------------------------------------------------------------

// If this string starts with -----BEGIN OT ARMORED...
// Then this function will load it up into an OTASCIIArmor (removing
// the bookends) and then decode it back into this string. This code
// has been repeated around so I'm doing this as a refactoring exercise.
//
// Return value: true  == There is a string in here that is not armored.
//                        (Whether I actually HAD to unarmor it or not... it's unarmored now.)
//               false == There was some error or the string is empty.
//
bool OTString::DecodeIfArmored(bool bEscapedIsAllowed/*=true*/)
{
    if (!this->Exists())
        return false;
    // ----------------------
    bool bArmoredAndALSOescaped = false;    // "- -----BEGIN OT ARMORED"
    bool bArmoredButNOTescaped  = false;    // "-----BEGIN OT ARMORED"
    
    if (this->Contains(OT_BEGIN_ARMORED_escaped)) // check this one first...
    {
        bArmoredAndALSOescaped = true;
        
        if (!bEscapedIsAllowed)
        {
            OTLog::vError("%s: Armored and escaped value passed in, but escaped are forbidden here. "
                          "(Returning.)\n");
            return false;
        }
    }
    else if (this->Contains(OT_BEGIN_ARMORED))
    {
        bArmoredButNOTescaped = true;
    }
    // ----------------------------------------
    const bool bArmored = (bArmoredAndALSOescaped || bArmoredButNOTescaped);
    // ----------------------------------------
    // Whether the string is armored or not, (-----BEGIN OT ARMORED)
    // either way, we'll end up with the decoded version in this variable:
    //
    std::string str_Trim;
    // ------------------------------------------------
    if (bArmored) // it's armored, we have to decode it first.
    {
        OTASCIIArmor ascTemp;
        if (false == (ascTemp.LoadFromString(*this,
                                             bArmoredAndALSOescaped, // if it IS escaped or not, this variable will be true or false to show it.
                                             // The below szOverride sub-string determines where the content starts, when loading.
                                             OT_BEGIN_ARMORED)))     // Default is:       "-----BEGIN"
                                                                    // We're doing this: "-----BEGIN OT ARMORED" (Should worked for escaped as well, here.)
        {
            OTLog::vError("%s: Error loading string contents from ascii-armored encoding. "
                          "Contents: \n%s\n", __FUNCTION__, this->Get());
            return false;
        }
        else // success loading the actual contents out of the ascii-armored version.
        {
            OTString strTemp(ascTemp); // <=== ascii-decoded here.
            std::string str_temp(strTemp.Get(), strTemp.GetLength());
            str_Trim = OTString::trim(str_temp); // This is the std::string for the trim process.
        }
    }
    else
    {
        std::string str_temp(this->Get(), this->GetLength());
        str_Trim = OTString::trim(str_temp); // This is the std::string for the trim process. (Wasn't armored, so here we use it as passed in.)
    }
    // ------------------------------------------------
    // At this point, str_Trim contains the actual contents, whether they
    // were originally ascii-armored OR NOT. (And they are also now trimmed, either way.)
    // ------------------------------------------
    this->Release();
    // ------------------------------------------
    if (str_Trim.size() > 0)
        this->Set(str_Trim.c_str());
    // ------------------------------------------
    return this->Exists();
}


// ----------------------------------------------------------------------


/*
 char *str_dup2(const char *str, int length)
 {
	 char *str_new;
	 
	 str_new = new char [length + 1];
 
	 strncpy(str_new, str, length);

	 str_new[length] = 0;
	 
	 return str_new;
 }
 */


// ----------------------------------------------------------------------

//inline bool vformat(const char * fmt, va_list vl, std::string & str_output)
//{
//    int size      = 512;
//    char * buffer = new char[size];
//    buffer[0]     = '\0';
//    // ------------------------------------    
//    int nsize = vsnprintf(buffer,size,fmt,vl);
//    
//    //fail -- delete buffer and try again
//    if(size <= nsize)
//    {
//        delete buffer; buffer = NULL;
//        buffer = new char[nsize+1]; //+1 for /0
//        nsize = vsnprintf(buffer,nsize,fmt,vl);
//    }
//    // ------------------------------------
//    str_output = buffer;
//    delete buffer;
//    return true;
//}

// ------------------------------------------------------------

void OTString::Format(const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    
    std::string str_output;
    
    const bool bSuccess = OTString::vformat(fmt, &vl, str_output);
    
    va_end(vl);
    
    if (bSuccess)
        Set(str_output.c_str());
}

// ------------------------------------------------------------

// append a string at the end of the current buffer.
void OTString::Concatenate(const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    
    std::string str_output;
    
    const bool bSuccess = OTString::vformat(fmt, &vl, str_output);
    
    va_end(vl);
    
    if (bSuccess)
    {
        const OTString strConcat(str_output);
        
        Concatenate(strConcat);
    }
}

// ------------------------------------------------------------

// append a string at the end of the current buffer.
void OTString::Concatenate(const OTString & strBuf)
{
    std::string str_output;
    
    if ((m_lLength > 0) && (NULL != m_strBuffer))
        str_output += m_strBuffer;
    
    if (strBuf.Exists() && (strBuf.GetLength() > 0))
        str_output += strBuf.Get();
    
    Set(str_output.c_str());
}

// ------------------------------------------------------------




void OTString::WriteToFile(std::ostream & ofs) const
{
	fwrite_string(ofs, m_strBuffer);
}

/*
void OTString::WriteToFile(FILE * fl) const
{
	if (fl != NULL)
		fwrite_string(fl, m_strBuffer);
}
*/

// ***** Implementation ***** ------------------------------



// Checks if s2 is the first word in s1.
// s1 ends at the first space character.
// len_cmp("load wallet.xml", "load") returns true
// used for USER INPUT ONLY.  And it's sloppy.
bool len_cmp(const char *s1, const char *s2)
{
	OT_ASSERT(NULL != s1);
	OT_ASSERT(NULL != s2);
	
  for( ; *s1 && *s2 && *s1 != ' '; s1++, s2++) 
    if(toupper(*s1) != toupper(*s2))
      return false;

	// bug: as long as it's a partial match while the loop continues,
	// this function will for example return true even if the user entered 
	// "c" when the command was "continue"
  return true; 
}
// ----------------------------------------------------------------------

// Note: this version doesn't take a length for str,
// which is a security problem. todo. 
// (Do we use this anymore anyway?)
//
char *str_dup1(const char *str) 
{
  char * str_new = new char [strlen(str) + 1];

	OT_ASSERT(NULL != str_new);
	
#ifdef _WIN32
  strcpy_s(str_new, strlen(str), str);
#else
  strlcpy(str_new, str, strlen(str));
#endif

  return str_new;
}
// ----------------------------------------------------------------------

// true  == there are more lines to read.
// false == this is the last line. Like EOF.
//
bool OTString::sgets(char * szBuffer, unsigned nBufSize)
{
	if (NULL == szBuffer)
	{
		return false;
	}
	
	if (m_lPosition >= m_lLength)
		return false;

	uint32_t lIndex		= 0;
	char * pChar	= (char *)(m_strBuffer + m_lPosition);
	
	// while *pChar isn't at the end of the source string,
	// and lIndex hasn't reached the end of the destination buffer,
    //
	while ( 0 != *pChar && 
           (m_lPosition < m_lLength) && 
           lIndex < (nBufSize-1)) // the -1 leaves room for a forced null terminator.
	{
		// If the current character isn't a newline, then copy it...
		if ( '\n' != *pChar )
		{
			szBuffer[lIndex]  = *pChar;
			lIndex++; // increment the buffer
			m_lPosition++; // increment the string's internal memory of where it stopped.
			pChar++; // increment this for convenience (could calcuate from position)
		}
		// Until we reach a newline...
		else 
        {
            // IT'S A NEWLINE!
            
			szBuffer[lIndex] = 0;  // destination buffer, this is the end of the line for him.
			m_lPosition++;        // This still moves past the newline, so the next call will get the next
								   // string.
			//lIndex does NOT increment here because we reach the end of this string.
			//neither does pChar. These local variables go away since we are returning.
			
			if (0 == *(pChar+1))
				return false;
			else
				return true; // there was more to read, but we stopped at the newline.
		}
	}
	
	// Need to add the NULL terminator.
	szBuffer[lIndex] = 0;
	
	// We reached the end of the string.
	// EOF. So we return false to tell the caller not to bother calling again.
	if (0 == *pChar)
	{
		return false;
	}
	
	// Obviously if *pChar isn't at the end, then there was more to read,
	// but the buffer was full, so we return true.
	return true;
}
// ----------------------------------------------------------------------

char OTString::sgetc(void)
{
  char answer;

  if (m_lPosition >= m_lLength)
    return EOF;
 
  answer = (char)(*(m_strBuffer + m_lPosition));

  ++m_lPosition;

  return answer;
}
// ----------------------------------------------------------------------

void OTString::sungetc(void)
{
  --m_lPosition;
  
  if(m_lPosition < 0)
    m_lPosition = 0;
}

// ----------------------------------------------------------------------


void OTString::reset(void)
{
  m_lPosition = 0;
}

// ----------------------------------------------------------------------


 /*
// As of now, do not use this.
// We have XML to do these things.
char *fread_string(FILE *fl)
{
    char    buf[MAX_STRING_LENGTH];
    char *  pAlloc;
    char *  pBufLast;
    
    for(pBufLast = buf; pBufLast < &(buf[MAX_STRING_LENGTH - 2]);)
    {
        switch(*pBufLast = getc(fl)) {
            default:
                pBufLast++;
                break;
                
            case EOF:
                perror("fread_string: EOF");
                exit(1);
                break;
                
            case '\n':
                while(pBufLast > buf && isspace(*(pBufLast - 1)))
                    pBufLast--;
                *pBufLast++ = '\n';
                *pBufLast++ = '\r';
                break;
                
            case '~':
                getc(fl);
                if(pBufLast == buf)
                {
                    pAlloc = new char[1];
                    *pAlloc = '\0';
                }
                else {
                    *pBufLast++ = '\0';
                    pAlloc = new char[pBufLast - buf];
                    memcpy(pAlloc, buf, pBufLast - buf);
                }
                return pAlloc;
        }
    }
    
    perror("fread_string: string too long");
    exit(1);
    return(0);
}
*/


