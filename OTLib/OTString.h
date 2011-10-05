/************************************************************************************
 *    
 *  OTString.h
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
 *  Copyright (C) 2010-2011 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net --- SEE PGP KEY BELOW.
 *  F3llowTraveler@gmail.com --- (not preferred.)
 *  
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT:
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  http://wiki.github.com/FellowTraveler/Open-Transactions/wiki 
 *  http://wiki.github.com/FellowTraveler/Moneychanger/wiki 
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
 Version: GnuPG v1.4.10 (Darwin)
 
 iQIcBAEBCAAGBQJNsV9NAAoJEAMIAO35UbuOB3IP/12THBedTYrR2F2hkhYKK+0H
 YlVwRJyFnX3uKjDkYx2fpB2yNaMPPyiQRFpQBpiUxB2wSMHelM+m4YxVegx7h15s
 nD+jMLeVnlhgfKYsVZZiCKT58HXVsuGDc/iycXBBIQYBjCzbeCCG0vyEapR+sCwF
 eGR5l7yGbcMWaVqjPawqSMe/5Ie0wstWMrNAkLlWHRn/ISXb8vMusaxCe9kSeUX8
 7ZSZ0ojy3gLTZnUHFFZ2RaMepVB9jVoMSdVG89mEHX383foTuaxedjI2Wsw6J8YR
 D7PFp6PLGhm1eqArmotCj5NeV9lleULdnvR7T4QwzOZjI65kMwi/e1W6GyvzT3RZ
 RrLaZwiagcyKTXyEX5qSBQfSVNwC761rgNTG0fCBrBmDbQxet4A6Y+ZMxZmE0QXb
 Xch/g4g9Lki0TrSOx0zSAAcpLCIrqdvGX2jcmmJ/Ex4ZhzVhMvtkGfui9bUaY2bU
 bdu1GY0CfmElZ7+wXh2AutkMscRtnu62VSdGjrqry3KJMBWbtxNA9Q+U+NipWnYN
 yisBlQBADkXNtkL3EXEqX6OnjGfHNZ3G1bwuELcZjoOL+K0aQKCojRf8Ii5DW0A3
 niqzq/dwpt45VaQ+uYSG7Sg19FNvADg+WILdFcyszfS8Wks6BsKYzHUc5zbf3SFc
 JaOXLV9Ss58mj57JpNp8
 =VjLJ
 -----END PGP SIGNATURE-----
 **************************************************************/


#ifndef  __STRING_H__
#define  __STRING_H__

// #include "whatever.h" -- all necessary #includes go here.
// Be sure to use 'extern "C" {   }' as a wrapper for straight 'C' headers.


#include <cstdio>
#include <cstdarg>
#include <cstring>

#include <string>

#include <algorithm>

extern "C" {
#include <stdint.h>
}

#include <iostream>
#include <sstream>
#include <fstream>

//#ifdef _WIN32
//#define MAX_STRING_LENGTH   631072
//#else
#define MAX_STRING_LENGTH   1262144
//#endif // _WIN32


// If you've already strlen'd the string,
// you can pass the length to str_hsh or str_dup
// and save it the trouble.
char *str_dup1(const char *str);
char *str_dup2(const char *str, uint32_t length);
int len_cmp(char *s1, char *s2);


template <class T>
inline std::string to_string (const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}


// =======================================================================
/*
 * strlcpy and strlcat
 *
 * Copyright (c) 1998 Todd C. Miller <Todd.Miller@courtesan.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * Copy src to string dst of size siz.  At most siz-1 characters
 * will be copied.  Always NUL terminates (unless siz == 0).
 * Returns strlen(src); if retval >= siz, truncation occurred.
 */
inline size_t strlcpy(char *dst, const char *src, size_t siz)
{
    char *d = dst;
    const char *s = src;
    size_t n = siz;
	
    /* Copy as many bytes as will fit */
    if (n != 0)
    {
        while (--n != 0)
        {
            if ((*d++ = *s++) == '\0')
                break;
        }
    }
	
    /* Not enough room in dst, add NUL and traverse rest of src */
    if (n == 0)
    {
        if (siz != 0)
            *d = '\0';  /* NUL-terminate dst */
        while (*s++)
            ;
    }
	
    return(s - src - 1); /* count does not include NUL */
}
/*
 * Appends src to string dst of size siz (unlike strncat, siz is the
 * full size of dst, not space left).  At most siz-1 characters
 * will be copied.  Always NUL terminates (unless siz <= strlen(dst)).
 * Returns strlen(src) + MIN(siz, strlen(initial dst)).
 * If retval >= siz, truncation occurred.
 */
inline size_t strlcat(char *dst, const char *src, size_t siz)
{
    char *d = dst;
    const char *s = src;
    size_t n = siz;
    size_t dlen;
	
    /* Find the end of dst and adjust bytes left but don't go past end */
    while (n-- != 0 && *d != '\0')
        d++;
    dlen = d - dst;
    n = siz - dlen;
	
    if (n == 0)
        return(dlen + strlen(s));
    while (*s != '\0')
    {
        if (n != 1)
        {
            *d++ = *s;
            n--;
        }
        s++;
    }
    *d = '\0';
	
    return(dlen + (s - src)); /* count does not include NUL */
}
// (End of the Todd Miller code.)
// =======================================================================




class OTIdentifier;
class OTContract;
class OTASCIIArmor;
class OTSignature;
class OTPseudonym;
class OTPayload;

class OTString
{
   // Construction -- Destruction
public:
	OTString();
	OTString(const OTString & strValue);
	OTString(const OTASCIIArmor & strValue);
	OTString(const OTSignature & strValue);
	OTString(const OTContract & theValue);
	OTString(const OTIdentifier & theValue);
	OTString(OTPseudonym & theValue);
	OTString(const char * new_string);
	OTString(const char * new_string, size_t sizeLength);
	OTString(const std::string & new_string);
   
	virtual ~OTString();

   void Initialize();

	OTString& operator=(OTString rhs);
//	OTString& operator=(const char * new_string);
//	OTString& operator=(const std::string & strValue);

	void swap(OTString & rhs);
	
   bool operator >(const OTString &s2) const;
   bool operator <(const OTString &s2) const;
   bool operator <=(const OTString &s2) const;
   bool operator >=(const OTString &s2) const;
   bool operator ==(const OTString &s2) const;

   // Attributes
public:

	// Implementation
private:
	// You better have called Initialize() or Release() before you dare call this.
	void LowLevelSetStr(const OTString & strBuf);
	
	// Only call this right after calling Initialize() or Release().
	// Also, this function ASSUMES the new_string pointer is good.
	void LowLevelSet(const char * new_string, uint32_t nEnforcedMaxLength);
	
	// Operations
public:	
	bool At(uint32_t lIndex, char &c);
	
	bool Exists(void) const;
   
	uint32_t GetLength(void) const;

	bool Compare(const char * strCompare) const;
	bool Compare(const OTString& strCompare) const;
	
	bool Contains(const char * strCompare) const;
	bool Contains(const OTString& strCompare) const;
	
	const char * Get(void) const;
	
	// ----------------------------
	void Set(const char * new_string, uint32_t nEnforcedMaxLength=0);
	
	// new_string MUST be at least nEnforcedMaxLength in size if nEnforcedMaxLength is passed in at all.
	// That's because this function forces the null terminator at that length of the string minus 1.
	void Set(const OTString & strBuf);
	// ----------------------------

//	void   Concatenate(const char *arg);
	void   Concatenate(const char *arg, ...);
	void   Concatenate(const OTString & strBuf);
	
	void   Truncate(uint32_t lAt);
	
	void   Format(const char *arg, ...);
   
	void ConvertToLowerCase();
	void ConvertToUpperCase();
	
	void OTfgets(std::istream & ofs);
//	void OTfgets(FILE * fl);

	// true  == there are more lines to read.
	// false == this is the last line. Like EOF.
	bool sgets(char * szBuffer, unsigned nBufSize);
	
   char sgetc(void);
   void sungetc(void);
   void reset(void);

	void WriteToFile(std::ostream & ofs) const;
//	void WriteToFile(FILE * fl = NULL) const;

   virtual void Release(void);

   // Internal properties
protected:
   uint32_t  m_lLength;
   uint32_t  m_lPosition;
   char * m_strBuffer;
};

bool operator >(const OTString& s1, const OTString& s2);
bool operator <(const OTString& s1, const OTString& s2);
bool operator >=(const OTString &s1, const OTString& s2);
bool operator <=(const OTString &s1, const OTString& s2);

#endif    // __STRING_H__
