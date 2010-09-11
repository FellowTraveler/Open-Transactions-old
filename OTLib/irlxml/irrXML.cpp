// Copyright (C) 2002-2005 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine" and the "irrXML" project.
// For conditions of distribution and use, see copyright notice in irrlicht.h and/or irrXML.h

#include <cstdio>

#include "irrXML.h"
#include "irrString.h"
#include "irrArray.h"
#include "fast_atof.h"
#include "CXMLReaderImpl.h"

namespace irr
{
namespace io
{

//! Implementation of the file read callback for ordinary files
class CFileReadCallBack : public IFileReadCallBack
{
public:

	//! construct from filename
	CFileReadCallBack(const char* filename)
		: File(0), Size(0), Close(true)
	{
		// open file
#ifdef _WIN32
		errno_t err = fopen_s(&File, filename, "rb");
#else
		File = fopen(filename, "rb");
#endif

		if (File)
			getFileSize();
	}

	//! construct from FILE pointer
	CFileReadCallBack(FILE* file)
		: File(file), Size(0), Close(false)
	{
		if (File)
			getFileSize();
	}

	//! destructor
	virtual ~CFileReadCallBack()
	{
		if (Close && File)
//#ifdef _WIN32
//			fclose_s(File);
//#else
			fclose(File);
//#endif
	}

	//! Reads an amount of bytes from the file.
	virtual int read(void* buffer, unsigned sizeToRead)
	{
		if (!File)
			return 0;

#ifdef _WIN32 // dest buf, dest size, element size, count, file
		return (int)fread_s(buffer, sizeToRead+1, 1, sizeToRead, File);
#else
		return (int)fread(buffer, 1, sizeToRead, File);
#endif
	}

	//! Returns size of file in bytes
	virtual int getSize()
	{
		return Size;
	}

private:

	//! retrieves the file size of the open file
	void getFileSize()
	{
//#ifdef _WIN32
//		fseek_s(File, 0, SEEK_END);
//#else
		fseek(File, 0, SEEK_END);
//#endif
		
		Size = ftell(File);
//#ifdef _WIN32
//		fseek_s(File, 0, SEEK_SET);
//#else
		fseek(File, 0, SEEK_SET);
//#endif
	}

	FILE* File;
	int Size;
	bool Close;

}; // end class CFileReadCallBack



// FACTORY FUNCTIONS:


//! Creates an instance of an UFT-8 or ASCII character xml parser. 
IrrXMLReader* createIrrXMLReader(const char* filename)
{
	return new CXMLReaderImpl<char, IXMLBase>(new CFileReadCallBack(filename)); 
}


//! Creates an instance of an UFT-8 or ASCII character xml parser. 
IrrXMLReader* createIrrXMLReader(FILE* file)
{
	return new CXMLReaderImpl<char, IXMLBase>(new CFileReadCallBack(file)); 
}


//! Creates an instance of an UFT-8 or ASCII character xml parser. 
IrrXMLReader* createIrrXMLReader(IFileReadCallBack* callback)
{
	return new CXMLReaderImpl<char, IXMLBase>(callback, false); 
}


//! Creates an instance of an UTF-16 xml parser. 
IrrXMLReaderUTF16* createIrrXMLReaderUTF16(const char* filename)
{
	return new CXMLReaderImpl<char16, IXMLBase>(new CFileReadCallBack(filename)); 
}


//! Creates an instance of an UTF-16 xml parser. 
IrrXMLReaderUTF16* createIrrXMLReaderUTF16(FILE* file)
{
	return new CXMLReaderImpl<char16, IXMLBase>(new CFileReadCallBack(file)); 
}


//! Creates an instance of an UTF-16 xml parser. 
IrrXMLReaderUTF16* createIrrXMLReaderUTF16(IFileReadCallBack* callback)
{
	return new CXMLReaderImpl<char16, IXMLBase>(callback, false); 
}


//! Creates an instance of an UTF-32 xml parser. 
IrrXMLReaderUTF32* createIrrXMLReaderUTF32(const char* filename)
{
	return new CXMLReaderImpl<char32, IXMLBase>(new CFileReadCallBack(filename)); 
}


//! Creates an instance of an UTF-32 xml parser. 
IrrXMLReaderUTF32* createIrrXMLReaderUTF32(FILE* file)
{
	return new CXMLReaderImpl<char32, IXMLBase>(new CFileReadCallBack(file)); 
}


//! Creates an instance of an UTF-32 xml parser. 
IrrXMLReaderUTF32* createIrrXMLReaderUTF32(IFileReadCallBack* callback)
{
	return new CXMLReaderImpl<char32, IXMLBase>(callback, false); 
}


} // end namespace io
} // end namespace irr
