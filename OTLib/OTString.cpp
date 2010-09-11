/************************************************************************************
 *    
 *  OTString.cpp
 *  
 *		Open Transactions:  Library, Protocol, Server, and Test Client
 *    
 *    			-- Anonymous Numbered Accounts
 *    			-- Untraceable Digital Cash
 *    			-- Triple-Signed Receipts
 *    			-- Basket Currencies
 *    			-- Signed XML Contracts
 *    
 *    Copyright (C) 2010 by "Fellow Traveler" (A pseudonym)
 *    
 *    EMAIL:
 *    F3llowTraveler@gmail.com --- SEE PGP PUBLIC KEY IN CREDITS FILE.
 *    
 *    KEY FINGERPRINT:
 *    9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *    
 *    WEBSITE:
 *    http://www.OpenTransactions.org
 *    
 *    OFFICIAL PROJECT WIKI:
 *    http://wiki.github.com/FellowTraveler/Open-Transactions/
 *    
 *     ----------------------------------------------------------------
 *    
 *    Open Transactions was written including these libraries:
 *    
 *       Lucre          --- Copyright (C) 1999-2009 Ben Laurie.
 *                          http://anoncvs.aldigital.co.uk/lucre/
 *       irrXML         --- Copyright (C) 2002-2005 Nikolaus Gebhardt
 *                          http://irrlicht.sourceforge.net/author.html	
 *       easyzlib       --- Copyright (C) 2008 First Objective Software, Inc.
 *                          Used with permission. http://www.firstobject.com/
 *       PGP to OpenSSL --- Copyright (c) 2010 Mounir IDRASSI 
 *                          Used with permission. http://www.idrix.fr
 *       SFSocket       --- Copyright (C) 2009 Matteo Bertozzi
 *                          Used with permission. http://th30z.netsons.org/
 *    
 *     ----------------------------------------------------------------
 *
 *    Open Transactions links to these libraries:
 *    
 *       OpenSSL        --- (Version 1.0.0a at time of writing.) 
 *                          http://openssl.org/about/
 *       zlib           --- Copyright (C) 1995-2004 Jean-loup Gailly and Mark Adler
 *    
 *     ----------------------------------------------------------------
 *
 *    LICENSE:
 *        This program is free software: you can redistribute it and/or modify
 *        it under the terms of the GNU Affero General Public License as
 *        published by the Free Software Foundation, either version 3 of the
 *        License, or (at your option) any later version.
 *    
 *        You should have received a copy of the GNU Affero General Public License
 *        along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *    	
 *    	  If you would like to use this software outside of the free software
 *    	  license, please contact FellowTraveler.
 *   
 *        This library is also "dual-license", meaning that Ben Laurie's license
 *        must also be included and respected, since the code for Lucre is also
 *        included with Open Transactions.
 *        The Laurie requirements are light, but if there is any problem with his
 *        license, simply remove the Lucre code. Although there are no other blind
 *        token algorithms in Open Transactions (yet), the other functionality will
 *        continue to operate .
 *    
 *    OpenSSL WAIVER:
 *        This program is released under the AGPL with the additional exemption 
 *    	  that compiling, linking, and/or using OpenSSL is allowed.
 *    
 *    DISCLAIMER:
 *        This program is distributed in the hope that it will be useful,
 *        but WITHOUT ANY WARRANTY; without even the implied warranty of
 *        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *        GNU Affero General Public License for more details.
 *    	
 ************************************************************************************/



#include <cstdarg>
#include <cstdio>
#include <cstring> // The C one 
#include <cstdlib>
#include <cctype>

#include <string> // The C++ one 

#include "OTString.h"
#include "OTIdentifier.h"
#include "OTContract.h"
#include "OTPseudonym.h"



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


// ------ I cannot vouch for these top four functions, I wrote them so long ago.
// ------ But they can't hurt and I don't think they're being used anyway so I left them in for now.
//
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


// ***** Construction -- Destruction ***** ------------------------------
OTString::~OTString()
{
	Release();
}


OTString::OTString()
{
	Initialize();
}

// This constructor gets the string version of the ID passed in,
// and sets that string on this object. (For when you need a string
// version of an ID.)
OTString::OTString(const OTIdentifier & theValue)
{
	Initialize();
	
	theValue.GetString(*this);
}

OTString::OTString(const OTContract & theValue)
{
	Initialize();
	
	((OTContract &)theValue).SaveContract(*this);	
}



// This version base64-DECODES the ascii-armored string passed in,
// and then sets the decoded plaintext string onto this object.
OTString::OTString(const OTASCIIArmor & strValue)
{
	Initialize();
	
	strValue.GetString(*this);
}

// This version base64-DECODES the ascii-armored signature that's passed in,
// and then sets the decoded plaintext signature onto this object.
// You would only do this when the signature, decoded, is normally in ASII
// form. Actually, that is regularly NOT the case--signatures are usually in
// binary form.
// But Lucre signatures, as used in this library, ARE in text form, so I
// provided this constructor to easily base64-decode them to prepare for
// loading into a bio and then a Lucre object.
OTString::OTString(const OTSignature & strValue)
{
	Initialize();
	
	strValue.GetString(*this);
}


OTString::OTString(OTPseudonym & theValue)
{
	Initialize();
	
	theValue.SavePseudonym(*this);
}

OTString::OTString(const OTString & strValue)
{
	Initialize();
	Set(strValue);
}

OTString::OTString(const char * new_string)
{
	Initialize();
	Set(new_string);
}

void OTString::Initialize()
{
  m_lLength   = 0;
  m_lPosition = 0;
  m_strBuffer  = NULL;
}

void OTString::Release(void)
{
	if (m_strBuffer)
	{
		// for security purposes.
		memset(m_strBuffer, 0, m_lLength);
		delete [] m_strBuffer;
	}
	m_strBuffer = NULL;
	m_lPosition = 0;
	m_lLength  = 0;
}

bool OTString::Exists(void) const
{
	return m_strBuffer ? true : false;
}

uint32_t OTString::GetLength(void) const
{
	return m_lLength;
}




OTString& OTString::operator=(const OTString& rhs)
{
   Set(rhs);
   return *this;
}

OTString& OTString::operator=(const char * new_string)
{
	Set(new_string);
	return *this;
}



// 
bool OTString::operator ==(const OTString &s2) const
{
	// If they are not the same length, return false
	if (m_lLength != s2.m_lLength) {
	  return(false);
	}
	
	// At this point we know they are at least the same length.
	// Next--are they both 0? If they are both 0, return true
	if (m_lLength == 0 && s2.m_lLength == 0) {
	  return(true);
	}

	// At this point we have 2 identical-length strings.
	// Now we call strcmp and convert it to true or false.
	if (strcmp(m_strBuffer, s2.m_strBuffer) == 0) {
	  return(true);
	}
	return(false);
}


// ***** Operations ***** ------------------------------

// Compare is simple.  True if they match, False if they don't match.
bool OTString::Compare(const char * strCompare) const
{
	if (NULL == m_strBuffer || NULL == strCompare) {
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

bool OTString::Compare(const OTString& strCompare) const
{
	if (NULL == m_strBuffer || !strCompare.Exists()) {
		return false;
	}
	
	char * s1 = m_strBuffer;
	const char * s2 = strCompare.Get();
	
	for( ; *s1 && *s1 != ' '; s1++, s2++) 
		if(*s1 != *s2)
			return false;
	
	return true; 
}


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






void OTString::OTfgets(FILE * fl)
{
	// _WIN32
	static char * buffer = NULL;
	
	if (NULL == buffer)
	{
		buffer = new char[MAX_STRING_LENGTH];
	}

	buffer[0] = '\0';
	// _end _WIN32


	if (fgets(buffer, MAX_STRING_LENGTH-1, fl))
	{
		buffer[strlen(buffer)-1] = '\0';
		
		Set(buffer);
	}
		
}

const char * OTString::Get(void) const
{
  return m_strBuffer ? (const char*)m_strBuffer : "";
}

void OTString::ConvertToLowerCase()
{
	if (m_strBuffer == NULL) {
		return;
	}
	
	for(char * s1 = m_strBuffer; *s1; s1++)
		*s1 = tolower(*s1);
}

void OTString::ConvertToUpperCase()
{
	if (m_strBuffer == NULL) {
		return;
	}
	
	for(char * s1 = m_strBuffer; *s1; s1++)
		*s1 = toupper(*s1);
}

void OTString::Truncate(uint32_t lAt)
{
	OTString strTruncated;
	
	strTruncated.Set(this->Get(), lAt);
	
	this->Set(strTruncated);
}

void OTString::Set(const char * new_string, uint32_t nEnforcedMaxLength/*=0*/)
{
	Release();
	
	if (0 == new_string)
		return; 
	
	if (nEnforcedMaxLength)
		((char *)new_string)[nEnforcedMaxLength] = '\0'; // enforce the max length before calling strlen.
	
	// Now this can never be larger than nEnforcedMaxLength
	uint32_t nLength = strlen(new_string);

	// don't bother allocating memory for a 0 length string.
	if (!nLength)
		return;

	m_lLength = nLength;
		
	m_strBuffer = str_dup2(new_string, nLength);
}

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

void OTString::Set(const OTString & strBuf)
{
  Release();
  
  if (strBuf.Exists()) {
	m_lLength = strBuf.m_lLength;
  
	m_strBuffer = str_dup2(strBuf.m_strBuffer, m_lLength);
	}
}

void OTString::Format(const char *arg, ...)
{
   va_list args;

   	// _WIN32
	static char * new_string = NULL;
	
	if (NULL == new_string)
	{
		new_string = new char[MAX_STRING_LENGTH];
	}

	new_string[0] = '\0';
	// _end _WIN32

   va_start(args, arg);

#ifdef _WIN32
	vsprintf_s(new_string, MAX_STRING_LENGTH, arg, args);
#else
	vsprintf(new_string, arg, args);
#endif

   va_end(args);

   Set(new_string);
}


// append a string at the end of the current buffer.
void OTString::Concatenate(const OTString & strBuf)
{
    // _WIN32
	static char * new_string = NULL;
	
	if (NULL == new_string)
	{
		new_string = new char[MAX_STRING_LENGTH];
	}

	new_string[0] = '\0';
	// _end _WIN32

   if (Exists())
#ifdef _WIN32
   {
	   const char * pBuf = strBuf.Get();
      sprintf_s(new_string, MAX_STRING_LENGTH, "%s%s", m_strBuffer, pBuf);
   }
#else
      sprintf(new_string, "%s%s", m_strBuffer, strBuf.Get());
#endif
   else
#ifdef _WIN32
   {
      const char * pBuf = strBuf.Get();
	   strcpy_s(new_string, MAX_STRING_LENGTH, pBuf);
   }
#else
      strcpy(new_string, strBuf.Get());
#endif

   Set(new_string);
}

// append a string at the end of the current buffer.
void OTString::Concatenate(const char *arg, ...)
{
	va_list	args;

	// _WIN32
	static char * new_string = NULL;
	
	if (NULL == new_string)
	{
		new_string = new char[MAX_STRING_LENGTH];
	}

	new_string[0] = '\0';
	// _end _WIN32

	// _WIN32
	static char * arg_string = NULL;
	
	if (NULL == arg_string)
	{
		arg_string = new char[MAX_STRING_LENGTH];
	}

	arg_string[0] = '\0';
	// _end _WIN32

	va_start(args, arg);


#ifdef _WIN32
	vsprintf_s(arg_string, MAX_STRING_LENGTH, arg, args);
#else
	vsprintf(arg_string, arg, args);
#endif

   va_end(args);

	if (Exists())
#ifdef _WIN32
		sprintf_s(new_string, MAX_STRING_LENGTH, "%s%s", m_strBuffer, arg_string);
#else
		sprintf(new_string, "%s%s", m_strBuffer, arg_string);
#endif // _WIN32
	else
#ifdef _WIN32
		strcpy_s(new_string, MAX_STRING_LENGTH, arg_string);
#else
		strcpy(new_string, arg_string);
#endif // _WIN32

	
	Set(new_string);
}

// append a string at the end of the current buffer.
/*
void OTString::Concatenate(const char *arg_string)
{
   char new_string[MAX_STRING_LENGTH];

   if (Exists())
      sprintf(new_string, "%s%s", m_strBuffer, arg_string);
   else
      strcpy(new_string, arg_string);

   Set(new_string);
}
 */




void OTString::WriteToFile(FILE * fl) const
{
   if (fl != NULL)
      fwrite_string(fl, m_strBuffer);
}


// ***** Implementation ***** ------------------------------



// Checks if s2 is the first word in s1.
// s1 ends at the first space character.
// len_cmp("load wallet.xml", "load") returns true
// used for USER INPUT ONLY.  And it's sloppy.
bool len_cmp(const char *s1, const char *s2)
{
  for( ; *s1 && *s2 && *s1 != ' '; s1++, s2++) 
    if(toupper(*s1) != toupper(*s2))
      return false;

	// bug: as long as it's a partial match while the loop continues,
	// this function will for example return true even if the user entered 
	// "c" when the command was "continue"
  return true; 
}


char *str_dup1(const char *str)
{
  char *str_new;

  str_new = new char [strlen(str) + 1];

#ifdef _WIN32
  strcpy_s(str_new, strlen(str), str);
#else
  strcpy(str_new, str);
#endif

  return str_new;
}

char *str_dup2(const char *str, uint32_t length)
{
	char *str_new;

	str_new = new char [length + 1];

#ifdef _WIN32
	strncpy_s(str_new, length+1, str, length);
#else
	strncpy(str_new, str, length);
#endif

	str_new[length] = 0;
  
	return str_new;
}

// true  == there are more lines to read.
// false == this is the last line. Like EOF.
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
	while ( 0 != *pChar && lIndex < (nBufSize-1)) // the -1 leaves room for a forced null terminator.
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
		else {
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

char OTString::sgetc(void)
{
  char answer;

  if (m_lPosition >= m_lLength)
    return EOF;
 
  answer = (char)(*(m_strBuffer + m_lPosition));

  ++m_lPosition;

  return answer;
}

void OTString::sungetc(void)
{
  --m_lPosition;
  
  if(m_lPosition < 0)
    m_lPosition = 0;
}

void OTString::reset(void)
{
  m_lPosition = 0;
}



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


