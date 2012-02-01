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

#ifndef __OT_STORAGE_H__
#define __OT_STORAGE_H__

#include <typeinfo>

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <map>

// credit:stlplus library.
#include "containers/simple_ptr.hpp"

// Use Win or Posix
// IF I need this while porting, then uncomment it.
#ifdef _WIN32
#include <windows.h>
//#else
//#ifndef POSIX
//#warning POSIX will be used (but you did not define it)
//#endif
//#include <unistd.h>
#endif


extern "C" 
{
	
#ifdef _WIN32
#include <direct.h>
#include <sys/stat.h>	
#else
#include <sys/stat.h>	
#endif
}

#include "OTData.h"

#include "OTLog.h"



// Which storage mechanism are we building?
// (Option is for both...)
//

#ifndef _WIN32 // Until I get it working on Windows.
#define OTDB_MESSAGE_PACK   1
#endif

#define OTDB_PROTOCOL_BUFFERS 1
//#define OTDB_JSON_PACKING 1 // coming soon.



//#define OTDB_DEFAULT_PACKER		PACK_MESSAGE_PACK
#define OTDB_DEFAULT_PACKER		OTDB::PACK_PROTOCOL_BUFFERS

#define OTDB_DEFAULT_STORAGE	OTDB::STORE_FILESYSTEM


// ----------------------------------------------------
// JAVA-STYLE INTERFACES.
//
// I'm doing some crazy stuff in this file.
// What you see below is a set of preprocessor definitions that
// allow me to use "Java-Style Interfaces" here in C++.
//
// It turns out that Storable needed a normal class hierarchy, AND Java-
// style interfaces, to do everything I wanted it to do.
//
// I will probably create a more general-purpose header file for OT
// and these sorts of #defines will probably end up there long-term.
// Much of OT might be separable out into a more general-purpose utility
// lib, which I will get to whenever it is more important than anything else.
//
#define Interface class

#define DeclareInterface(name) Interface name { \
public: \
virtual ~name() {}

#define DeclareBasedInterface(name, base) class name : public base { \
public: \
virtual ~name() {}

#define EndInterface };

#define implements public
// ----------------------------------------------------

// Foreach with std containers.

#define FOR_EACH_IT(ARG_OT_ONE, ARG_OT_TWO, ARG_OT_THREE)	for(ARG_OT_ONE::iterator ARG_OT_THREE = ARG_OT_TWO.begin(); ARG_OT_THREE != ARG_OT_TWO.end(); ++ ARG_OT_THREE)

#define FOR_EACH(ARG_OT_ONE, ARG_OT_TWO)	for(ARG_OT_ONE::iterator it = ARG_OT_TWO.begin(); it != ARG_OT_TWO.end(); ++ it)

#define FOR_EACH_IT_CONST(ARG_OT_ONE, ARG_OT_TWO, ARG_OT_THREE)	for(ARG_OT_ONE::const_iterator ARG_OT_THREE = ARG_OT_TWO.begin(); ARG_OT_THREE != ARG_OT_TWO.end(); ++ ARG_OT_THREE)

#define FOR_EACH_CONST(ARG_OT_ONE, ARG_OT_TWO)	for(ARG_OT_ONE::const_iterator it = ARG_OT_TWO.begin(); it != ARG_OT_TWO.end(); ++ it)



// ----------------------------------------------------

namespace OTDB
{		
	
	// ENUMS:	PackType, StorageType, and StoredObjectType.
	
	// ---------------------------------------------------
	// Currently supporting MsgPack and Protocol Buffers.  
	// 
	enum PackType // PACKING TYPE
	{
		PACK_MESSAGE_PACK = 0,	// Using MessagePack as packer.
		PACK_PROTOCOL_BUFFERS,	// Using Google Protocol Buffers as packer.
		PACK_TYPE_ERROR			// (Should never be.)
	};
	
	// ------------------------------
	// Currently supporting filesystem, with subclasses possible via API.
	//
	enum StorageType  // STORAGE TYPE
	{
		STORE_FILESYSTEM = 0,	// Filesystem
//		STORE_COUCH_DB,			// Couch DB (not yet supported)
		STORE_TYPE_SUBCLASS		// (Subclass provided by API client via SWIG.)
	};
	
	// -------------------------------------
	// 
	// STORED OBJECT TYPES...
	// 
	extern const char * StoredObjectTypeStrings[];
	
	enum StoredObjectType
	{
		STORED_OBJ_STRING=0,		// Just a string.
		STORED_OBJ_BLOB,			// Used for storing binary data. Bytes of arbitrary length.
		STORED_OBJ_STRING_MAP,		// A StringMap is a list of Key/Value pairs, useful for storing nearly anything.
		STORED_OBJ_WALLET_DATA,		// The GUI wallet's stored data
		STORED_OBJ_BITCOIN_ACCT,	// The GUI wallet's stored data about a Bitcoin acct
		STORED_OBJ_BITCOIN_SERVER,	// The GUI wallet's stored data about a Bitcoin RPC port.
		STORED_OBJ_RIPPLE_SERVER,	// The GUI wallet's stored data about a Ripple server.
		STORED_OBJ_LOOM_SERVER,		// The GUI wallet's stored data about a Loom server.
		STORED_OBJ_SERVER_INFO,		// A Nym has a list of these.
		STORED_OBJ_CONTACT_NYM,		// This is a Nym record inside a contact of your address book.
		STORED_OBJ_CONTACT_ACCT,	// This is an account record inside a contact of your address book.
		STORED_OBJ_CONTACT,			// Your address book has a list of these.
		STORED_OBJ_ADDRESS_BOOK,	// Your address book.
		STORED_OBJ_MARKET_DATA,		// The description data for any given Market ID.
		STORED_OBJ_MARKET_LIST,		// A list of MarketDatas.
		STORED_OBJ_BID_DATA,			// Offer details (doesn't contain private details)
		STORED_OBJ_ASK_DATA,			// Offer details (doesn't contain private details)
		STORED_OBJ_OFFER_LIST_MARKET,	// A list of offer details, for a specific market.
		STORED_OBJ_TRADE_DATA_MARKET,	// Trade details (doesn't contain private data)
		STORED_OBJ_TRADE_LIST_MARKET,	// A list of trade details, for a specific market.
		STORED_OBJ_OFFER_DATA_NYM,		// Private offer details for a particular Nym and Offer.
		STORED_OBJ_OFFER_LIST_NYM,		// A list of private offer details for a particular Nym.
		STORED_OBJ_TRADE_DATA_NYM,		// Private trade details for a particular Nym and Trade.
		STORED_OBJ_TRADE_LIST_NYM,		// A list of private trade details for a particular Nym and Offer.
		STORED_OBJ_ERROR			// (Should never be.)
	};
	
	// ********************************************************************
	
	// OTDB NAMESPACE "CONSTRUCTOR"
	//
	class InitOTDBDetails 
	{
	public:
		InitOTDBDetails();  // See implementation of this in CPP file for namespace construction.
		~InitOTDBDetails(); // Ditto.
	};
	// -------------------------------
	
	
	
	// ABSTRACT BASE CLASSES
	//
	class Storable;		// A storable object
	class OTPacker;		// A packer (Could be MsgPack, or Google Protocol Buffers, or a json lib...)
	class Storage;		// A storage context (database, filesystem, cloud, etc. Swappable.)
	class PackedBuffer;	// A buffer for containing a PACKED STORABLE. (On its way to/from storage.)
	
	// As far as the USERS of the Storage API are concerned, the above classes are nearly everything.
	// (In addition to the "Pure Data" classes such as ContactNym, BitcoinAcct, etc.)
	// Behind the scenes, in OTStorage, there is the IStorable interface, with its progeny, the various
	// subclasses based on specific packers, such as ContactNymMsgpack, or WalletDataProtobuf. But these
	// are hidden, and are not seen outside of OTStorage in its actual USE.
	
	// ------------------------------------------------
	//
	// OTDB Namespace internal typedefs
	//
	// In short:
	// - InstantiateFunc (function pointer type.)
	// - InstantiateFuncKey (based on Pack Type and Stored Object Type.)
	// - mapOfFunctions (type: map of InstantiateFuncs, indexed by InstantiateFuncKeys.)
	//
	// Resulting in: pFunctionMap (Instance of mapOfFunctions, created in the OTDB constructor.)
	//
	typedef Storable * (InstantiateFunc)(); // Each storable has one of these as a static method.
	typedef std::pair<PackType, StoredObjectType> InstantiateFuncKey;	// Those methods are stored as function pointers here, and they are
																		// indexed by Pack Type and Stored Object Type. So if you know "LoomAcct" and
																		// "protocol buffers", those form the KEY for looking up the LoomAcctPB instantiator.
	typedef std::map<InstantiateFuncKey, InstantiateFunc*> mapOfFunctions; //...basically implementing my own vtable, eh?
	
	
	
	// ********************************************************************
	
	// OTDB Namespace PRIVATE MEMBERS
	// this "details" naming is a common C++ idiom for "private" in a namespace.
	//
	namespace details 
	{
		extern OTDB::Storage * s_pStorage;
		
		extern OTDB::mapOfFunctions * pFunctionMap; // This is a pointer so I can control what order it is created in, on startup.
	}
	
	
	
	
	// ----------------------------------------------------
	
	// All of the class hierarchy under Storable is based on OT data design. (Not packing and such implementation details.)
	// So when we need to add custom behavior that's common to groups of the final subclasses,
	// we use **Interfaces** to do it. 
	
	// ===> That way, the Storable hierarchy can focus on DATA, (and form the external interface for OTStorage.)
	// ===> while the IStorable hierarchy focuses on PACKING.   (and is hidden INSIDE OTStorage.)
	// ===> (Things are more elegant this way.)
	
	//
	//
	// Interface:    IStorable
	//
	// Each specific Packer library (MsgPack, Protobuf, etc) must provide an interface
	// derived from IStorable (They're all listed somewhere below.)
	//
	DeclareInterface(IStorable)
		virtual bool onPack(PackedBuffer& theBuffer, Storable& inObj) = 0; // buffer is output, inObj is input.
		virtual bool onUnpack(PackedBuffer& theBuffer, Storable& outObj) = 0; // buffer is input, outObj is output.
		// ------------------------------------------
		virtual void hookBeforePack() {} // This is called just before packing a storable. (Opportunity to copy values...)
		virtual void hookAfterUnpack() {} // This is called just after unpacking a storable. (Opportunity to copy values...)
	EndInterface
	
	
	
	
	// ********************************************************************
	//
	// use this without a semicolon:
	//
#define DEFINE_OT_DYNAMIC_CAST(CLASS_NAME) \
	virtual CLASS_NAME * clone () const { OT_ASSERT(false); std::cout << "********* THIS SHOULD NEVER HAPPEN!!!!! *****************" << std::endl; return NULL; } \
	static CLASS_NAME *			ot_dynamic_cast(		Storable *pObject) { return dynamic_cast<CLASS_NAME *>(pObject); }
//	static const CLASS_NAME	*	ot_dynamic_cast(const	Storable *pObject) { return dynamic_cast<const T *>(pObject); }
	
	// -------------------
	//
	// STORABLE
	//
	// Abstract base class for OT serializable object types.
	//
	class Storable
	{
		friend class Storage; // for instantiation of storable objects by their storage context.
		
	protected:
		Storable() { m_Type = "Storable"; }
		
		std::string m_Type;
	public:
		virtual ~Storable() {}
		
		// %ignore spam(unsigned short); API users don't need this function, it's for internal purposes.
		static Storable * Create(StoredObjectType eType, PackType thePackType);
		
		DEFINE_OT_DYNAMIC_CAST(Storable)
	};
	
	
	
	// ********************************************************************
	
	// PACKED BUFFER (for storing PACKED DATA)
	//
	// %ignore these classes (I think)
	// 
	
	class PackedBuffer 
	{
	protected:
		PackedBuffer() { } // Only subclasses of this should be instantiated.
	public:
		virtual ~PackedBuffer() {}
		
		virtual bool PackString(std::string& theString)=0;
		virtual bool UnpackString(std::string& theString)=0;
		
		virtual bool ReadFromIStream(std::istream &inStream, long lFilesize)=0;
		virtual bool WriteToOStream(std::ostream &outStream)=0;
		
		virtual const	unsigned char *	GetData()=0;
		virtual			size_t			GetSize()=0;
		
		virtual	void SetData(const unsigned char * pData, size_t theSize)=0;
	};
	
	// --------------------------------
	//
	// SUBCLASSES (the actual declarations are at the bottom of this file.)
	//
	//	typedef PackedBufferSubclass<PackerMsgpack, IStorableMsgpack,	msgpack::sbuffer>	BufferMsgpack;
	//	typedef PackedBufferSubclass<PackerPB,		IStorablePB,		std::string>		BufferPB;
	//
	// Coming soon:
	//	typedef PackedBufferSubclass<PackerJSON,	IStorableJSON,		std::string>		BufferJSON;
	//
	// They're all based on this template:
	//
#define DECLARE_PACKED_BUFFER_SUBCLASS(theNewType, thePackerType, theInterfaceType, theInternalType) \
class theNewType : public PackedBuffer \
{ \
	friend class		thePackerType; \
	friend Interface	theInterfaceType; \
	theInternalType		m_buffer; \
public: \
	theNewType() : PackedBuffer() {} \
	virtual ~theNewType() {} \
	virtual bool PackString(std::string& theString); \
	virtual bool UnpackString(std::string& theString); \
	virtual bool ReadFromIStream(std::istream &inStream, long lFilesize); \
	virtual bool WriteToOStream(std::ostream &outStream); \
	virtual const	unsigned char *	GetData(); \
	virtual			size_t			GetSize(); \
	virtual	void SetData(const unsigned char * pData, size_t theSize); \
	theInternalType & GetBuffer() { return m_buffer; } \
}
	
	// ********************************************************************
	
	
	
	
	
	
	
	
	
	// ********************************************************************
	
	// PACKER (now OTPacker since MsgPack also has a "Packer" in a #define).
	//
	// abstract base class for a packer
	//
	
	// %ignore spam(unsigned short);  (probably for all packers.)
	class OTPacker 
	{
	protected:
		OTPacker() { }  // To instantiate: OTPacker * pPacker = OTPacker::Create(OTDB_DEFAULT_PACKER);
		
	public:
		virtual ~OTPacker() {}
		
		static OTPacker * Create(PackType ePackType); // Factory.
		
		PackType GetType() const;
		
		PackedBuffer *	Pack(Storable& inObj);
		bool			Unpack(PackedBuffer& inBuf, Storable& outObj);
		
		PackedBuffer *	Pack(std::string& inObj);
		bool			Unpack(PackedBuffer& inBuf, std::string& outObj);
		
		virtual PackedBuffer * CreateBuffer()=0;
	};
	
	
	// ----------------------------------------------------
	// For declaring subclasses of OTPacker.
	
	template<class theBufferType>
	class PackerSubclass : public OTPacker
	{
	public:
		PackerSubclass() : OTPacker() {}
		virtual ~PackerSubclass() {}
		
		virtual PackedBuffer * CreateBuffer() { return new theBufferType; }
		
		// You don't see onPack and onUnpack here because they are on IStorable.
	};
	
	// To use:
	// typedef PackerSubclass<theBufferType> theType;
	//
	// ----------------------------------------------------
	
	// SUBCLASSES:
	//
	// (Actual declarations are at the bottom of the file.)
	//
	//	typedef PackerSubclass<BufferMsgpack>	PackerMsgpack;
	//	typedef PackerSubclass<BufferPB>		PackerPB;
	//
	// Coming soon:
	//	typedef PackerSubclass<BufferJSON>		PackerJSON;
	//
	// ********************************************************************
	
	
	
	
	
	
	
	
	// ********************************************************************
	//
	// STORAGE  -- abstract base class
	//
	//
	class Storage
	{
	private:
		OTPacker * m_pPacker;
		
	protected:
		Storage() : m_pPacker(NULL) {}
		
		Storage(const Storage & rhs) : m_pPacker(NULL) { } // We don't want to copy the pointer. Let it create its own.
				
		// This is called once, in the factory.
		void SetPacker(OTPacker & thePacker) { OT_ASSERT(NULL == m_pPacker); m_pPacker =  &thePacker; }
		
		// ********************************************************
		// OVERRIDABLES
		//
		// If you wish to MAKE YOUR OWN subclass of Storage (to provide your own storage system)
		// then just subclass OTDB::Storage, and override the below methods. For an example of how
		// it's done, see StorageFS (filesystem), which is included below and in OTStorage.cpp.
		//
		// NOTE: This should be possible even in other languages! I'm using SWIG directors, meaning
		// that you can make a Java subclass of OTDB::Storage, or a Python subclass, etc. This isn't
		// possible with the other classes in OTStorage (yet), which must be subclassed in C++. But
		// for this class, it is.
		//
		virtual bool onStorePackedBuffer(PackedBuffer & theBuffer, std::string strFolder, std::string oneStr="", 
										 std::string twoStr="", std::string threeStr="")=0;
		
		virtual bool onQueryPackedBuffer(PackedBuffer & theBuffer, std::string strFolder, std::string oneStr="",
										 std::string twoStr="", std::string threeStr="")=0;
		
		virtual bool onStorePlainString(std::string & theBuffer, std::string strFolder, std::string oneStr="", 
										std::string twoStr="", std::string threeStr="")=0;
		
		virtual bool onQueryPlainString(std::string & theBuffer, std::string strFolder, std::string oneStr="",
										std::string twoStr="", std::string threeStr="")=0;
		
        virtual bool onEraseValueByKey(std::string strFolder, std::string oneStr="",
                                       std::string twoStr="", std::string threeStr="")=0;
        
		// -------------------------------------
		
	public:
		// Use GetPacker() to access the Packer, throughout duration of this Storage object.
		// If it doesn't exist yet, this function will create it on the first call. (The 
		// parameter allows you the choose what type will be created, other than default.)
		//
		// This way, whenever using an OT Storage, you KNOW the packer is always the right
		// one, and that you don't have to fiddle with it at all. You can also therefore use
		// it for creating instances of various Storables and PackedBuffers, and knowing
		// that the right types will be instantiated automatically, with the buffer being
		// the appropriate subclass for the packer.
		//
		OTPacker * GetPacker(PackType ePackType = OTDB_DEFAULT_PACKER);

		
		virtual bool Init(std::string oneStr="", std::string twoStr="", std::string threeStr="", 
						  std::string fourStr="", std::string fiveStr="", std::string sixStr="")=0;
		
		// -----------------------------------------
		// See if the file is there.
		virtual bool Exists(std::string strFolder, 
							std::string oneStr="", std::string twoStr="", std::string threeStr="")=0;
		
		// ********************************************************
		
		virtual ~Storage() { if (NULL != m_pPacker) delete m_pPacker; m_pPacker = NULL; }
		
		// -----------------------------------------
		// Store/Retrieve a string.
		
		bool StoreString(std::string strContents, std::string strFolder, 
						 std::string oneStr="", std::string twoStr="", std::string threeStr="");
		
		std::string QueryString(std::string strFolder, std::string oneStr="",
								std::string twoStr="", std::string threeStr="");
		
		bool StorePlainString(std::string strContents, std::string strFolder, 
							  std::string oneStr="", std::string twoStr="", std::string threeStr="");
		
		std::string QueryPlainString(std::string strFolder, std::string oneStr="",
									 std::string twoStr="", std::string threeStr="");
		
		// -----------------------------------------
		// Store/Retrieve an object. (Storable.)
		
		bool StoreObject(Storable & theContents, std::string strFolder, 
						 std::string oneStr="", std::string twoStr="", std::string threeStr="");
		
		// Use %newobject OTDB::Storage::QueryObject();
		Storable * QueryObject(StoredObjectType theObjectType,
							   std::string strFolder, std::string oneStr="",
							   std::string twoStr="", std::string threeStr="");
		// -----------------------------------------
		// Store/Retrieve a Storable object inside an OTASCIIArmor object.
		
		std::string EncodeObject(Storable & theContents);
		
		// Use %newobject OTDB::Storage::DecodeObject();
		Storable * DecodeObject(StoredObjectType theObjectType, std::string strInput);
		
		// -----------------------------------------
		// Erase any value based on its location.
		
		bool EraseValueByKey(std::string strFolder, 
                             std::string oneStr="", std::string twoStr="", std::string threeStr="");
		
		// --------------------------
		// Note:
		// Make sure to use: %newobject Factory::createObj();  IN OTAPI.i file!
		//
		// That way, Java garbage cleanup will handle object after this.
		// (Instead of leaking because it thinks C++ will clean it up.)
		//
		// Factory for Storable objects.   %newobject Factory::createObj();
		Storable * CreateObject(StoredObjectType eType);
		
		// --------------------------
		
		// Factory for Storage itself.  %ignore this in OTAPI.i  (It's accessed through 
		// a namespace-level function, whereas this is for internal purposes.)
		//
		static Storage * Create(StorageType eStorageType, PackType ePackType); // FACTORY
		
		StorageType GetType() const;
	};
	
	
	// ********************************************************************
	//
	// OTDB Namespace PUBLIC INTERFACE
	//
	//
	
	bool InitDefaultStorage(StorageType eStoreType, PackType ePackType,
							std::string oneStr="", std::string twoStr="", std::string threeStr="", 
							std::string fourStr="", std::string fiveStr="", std::string sixStr="");
	
	// Default Storage instance:
	Storage * GetDefaultStorage();
	
	// %newobject Factory::createObj();
	Storage * CreateStorageContext(StorageType eStoreType, PackType ePackType=OTDB_DEFAULT_PACKER);
	
	Storable * CreateObject(StoredObjectType eType);
	
	// bool bSuccess = OTDB::StoreString(strInbox, "inbox", "lkjsdf908w345ljkvd");
	// bool bSuccess = OTDB::StoreString(strMint,  "mints", SERVER_ID, ASSET_ID);
	// bool bSuccess = OTDB::StoreString(strPurse, "purse", SERVER_ID, USER_ID, ASSET_ID);
	
	// BELOW FUNCTIONS use the DEFAULT Storage context for the OTDB Namespace
	
	// --------
	// See if the file is there.
	//
	bool Exists(std::string strFolder, 
				std::string oneStr="", std::string twoStr="", std::string threeStr="");
	
	// --------
	// Store/Retrieve a string.
	//
	bool StoreString(std::string strContents, std::string strFolder, 
					 std::string oneStr="", std::string twoStr="", std::string threeStr="");
	
	std::string QueryString(std::string strFolder, std::string oneStr="",
							std::string twoStr="", std::string threeStr="");
	
	bool StorePlainString(std::string strContents, std::string strFolder, 
						  std::string oneStr="", std::string twoStr="", std::string threeStr="");
	
	std::string QueryPlainString(std::string strFolder, std::string oneStr="",
								 std::string twoStr="", std::string threeStr="");
	
	// --------
	// Store/Retrieve an object. (Storable.)
	//
	bool StoreObject(Storable & theContents, std::string strFolder, 
					 std::string oneStr="", std::string twoStr="", std::string threeStr="");
	
	// Use %newobject OTDB::Storage::Query();
	Storable * QueryObject(StoredObjectType theObjectType,
						   std::string strFolder, std::string oneStr="",
						   std::string twoStr="", std::string threeStr="");		
	// -----------------------------------------
	// Store/Retrieve a Storable object inside an OTASCIIArmor object.
	
	std::string EncodeObject(Storable & theContents);
	
	// Use %newobject OTDB::Storage::DecodeObject();
	Storable * DecodeObject(StoredObjectType theObjectType, std::string strInput);
	
	// -----------------------------------------
    // Erase any value based on its location.
    
    bool EraseValueByKey(std::string strFolder, 
                         std::string oneStr="", std::string twoStr="", std::string threeStr="");

	// ********************************************************************
	/*
	typedef template<class T>
	T * OT_DYNAMIC_CAST(Storable * pObject)
	{
		return dynamic_cast<T *>(pObject);
	}
	template<class T>
	const T * OT_DYNAMIC_CONST_CAST(const Storable * pObject)
	{
		return dynamic_cast<const T *>(pObject);
	}
	*/




#define DECLARE_GET_ADD_REMOVE(name) \
protected: \
	std::deque< stlplus::simple_ptr_clone<name> > list_##name##s; \
public: \
	size_t Get##name##Count(); \
	name * Get##name(size_t nIndex); \
	bool Remove##name(size_t nIndex##name); \
	bool Add##name(name & disownObject)
	
	
	
	// Serialized types...
	//
	// Here the entire hierarchy focuses on the OT data itself.
	// Later, subclasses are made providing the final implementation,
	// based on the packer type. (Same for buffers.)
	
	class OTDBString : public Storable
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through the factory.
	protected:
		OTDBString() : Storable() { m_Type = "OTDBString"; }
		OTDBString(const std::string& rhs) : Storable(), m_string(rhs) { m_Type = "OTDBString"; } // This is an abstract base class...so will this call ever actually happen?
		
	public:
		virtual ~OTDBString() { }
		
		std::string m_string;
		
		DEFINE_OT_DYNAMIC_CAST(OTDBString)
	};
	
	// ------------------------------------------------
	
	
	class Blob : public Storable
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through the factory.
	protected:
		Blob() : Storable() { m_Type = "Blob"; }
		
	public:
		virtual ~Blob() { }
		
		std::vector<unsigned char> m_memBuffer; // Where the actual binary data is stored, before packing.
		
		DEFINE_OT_DYNAMIC_CAST(Blob)
	};
	
	// ------------------------------------------------
	
	
	// The most useful generic data object... a map of strings, key/value pairs.
	//
	class StringMap : public Storable
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through the factory.
	protected:
		StringMap() : Storable() { m_Type = "StringMap"; }
		
	public:
		virtual ~StringMap() { }
		
		std::map<std::string, std::string> the_map;  // all strings, key/value pairs.
		
		void SetValue(const std::string& strKey, const std::string& strValue)
		{ std::map<std::string, std::string>::iterator ii = the_map.find(strKey);
			if (ii != the_map.end()) the_map.erase(ii); the_map[strKey] = strValue; }
		
		std::string GetValue(const std::string& strKey)
		{ std::string ret_val(""); std::map<std::string, std::string>::iterator ii = the_map.find(strKey);
			if (ii != the_map.end()) ret_val = (*ii).second; return ret_val; }

		DEFINE_OT_DYNAMIC_CAST(StringMap)
	};
	
	// ------------------------------------------------
	
	class Displayable : public Storable
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through the factory.
	protected:
		Displayable() : Storable() { m_Type = "Displayable"; }
		
	public:
		virtual ~Displayable() { }
		
		std::string gui_label;  // The label that appears in the GUI

		DEFINE_OT_DYNAMIC_CAST(Displayable)
	};
	
	// *************************************************
	
	class MarketData : public Displayable
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		MarketData() : Displayable(), 
			scale("0"), total_assets("0"), number_bids("0"), last_sale_price("0"),
			current_bid("0"), current_ask("0"), 
			volume_trades("0"), volume_assets("0"), volume_currency("0"),
			recent_highest_bid("0"), recent_lowest_ask("0")
			{ m_Type = "MarketData"; }
		
	public:
		virtual ~MarketData() { }
		
		using Displayable::gui_label;  // The label that appears in the GUI
		
		std::string server_id;
		std::string market_id;

		std::string asset_type_id;
		std::string currency_type_id;
		
		std::string scale;	// the Market scale. (A trade in any particular asset is measured in X units of SCALE.)
                            // IOW, if the scale is 5000 on the gold market, that means "3 units" is 15000 gold
				
		std::string total_assets;		// total amount of assets available on market for purchase.
		
		std::string number_bids;		// number of bids that are currently on the market.
		std::string number_asks;		// number of asks that are currently on the market.
		
		std::string last_sale_price;	// The price at which the most recent trade occurred on this market.
		std::string current_bid;		// The highest bid currently on the market.
		std::string current_ask;		// The lowest ask price currently available on the market.
		
		std::string volume_trades;		// 24-hour period, number of trades.
		
		std::string volume_assets;		// 24-hour volume, amount of assets traded.
		std::string volume_currency;	// 24-hour volume, amount of currency paid for assets traded.
		
		std::string recent_highest_bid; // in a 24hour period, the highest bid to hit the market.
		std::string recent_lowest_ask;	// in a 24hour period, the lowest ask to hit the market.
		
		DEFINE_OT_DYNAMIC_CAST(MarketData)
	};

	// ------------------------------------------------------

	class MarketList : public Storable {
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		MarketList() : Storable() { m_Type = "MarketList"; }
		
	public:
		virtual ~MarketList() {}
		
		DECLARE_GET_ADD_REMOVE(MarketData);
		
		DEFINE_OT_DYNAMIC_CAST(MarketList)
	};
	
	
	// ******************************************************
	
	class OfferDataMarket : public Displayable
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		OfferDataMarket() : Displayable(), 
		transaction_id("0"), price_per_scale("1"), available_assets("0"), minimum_increment("1")
		{ m_Type = "OfferDataMarket"; }
		
	public:
		virtual ~OfferDataMarket() { }
		
		using Displayable::gui_label;  // The label that appears in the GUI
				
		std::string transaction_id;
		std::string price_per_scale;
		
//		uint64_t total_assets;
//		uint64_t finished_so_far;
		std::string available_assets;

		// Each sale or purchase against (total_assets - finished_so_far) must be in minimum increments.
		// Minimum Increment must be evenly divisible by scale. 
		// (This effectively becomes a "FILL OR KILL" order if set to the same value as total_assets. Also, MUST be 1
		// or greater. CANNOT be zero. Enforce this at class level. You cannot sell something in minimum increments of 0.)
		
		std::string minimum_increment;  	
		
		DEFINE_OT_DYNAMIC_CAST(OfferDataMarket)
	};
	
	// ------------------------------------------------------
	
	class BidData : public OfferDataMarket
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		BidData() : OfferDataMarket()
		{ m_Type = "BidData"; }
		
	public:
		virtual ~BidData() { }
		
		using Displayable::gui_label;  // The label that appears in the GUI
		
		using OfferDataMarket::transaction_id;
		using OfferDataMarket::price_per_scale;
		using OfferDataMarket::available_assets;
		using OfferDataMarket::minimum_increment;  	
		
		DEFINE_OT_DYNAMIC_CAST(BidData)
	};
	
	// ------------------------------------------------------
	
	class AskData : public OfferDataMarket
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		AskData() : OfferDataMarket()
		{ m_Type = "AskData"; }
		
	public:
		virtual ~AskData() { }
		
		using Displayable::gui_label;  // The label that appears in the GUI
		
		using OfferDataMarket::transaction_id;
		using OfferDataMarket::price_per_scale;
		using OfferDataMarket::available_assets;
		using OfferDataMarket::minimum_increment;  	
		
		DEFINE_OT_DYNAMIC_CAST(AskData)
	};
		
	// ------------------------------------------------------

	class OfferListMarket : public Storable {
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		OfferListMarket() : Storable() { m_Type = "OfferListMarket"; }
		
	public:
		virtual ~OfferListMarket() {}
		
		DECLARE_GET_ADD_REMOVE(BidData);
		DECLARE_GET_ADD_REMOVE(AskData);
		
		DEFINE_OT_DYNAMIC_CAST(OfferListMarket)
	};
	
	// ******************************************************
	
	class TradeDataMarket : public Displayable
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		TradeDataMarket() : Displayable(), 
		transaction_id("0"), date("0"), 
		price("0"), amount_sold("0")
		{ m_Type = "TradeDataMarket"; }
		
	public:
		virtual ~TradeDataMarket() { }
		
		using Displayable::gui_label;  // The label that appears in the GUI
		
		std::string transaction_id;	// (transaction number for this trade.)
		std::string date;				// (The date of this trade's execution)
		std::string price;				// (The price this trade executed at.)
		std::string amount_sold;		// (Amount of asset sold for that price.)	
		
		DEFINE_OT_DYNAMIC_CAST(TradeDataMarket)
	};
	
	// ------------------------------------------------------
	
	class TradeListMarket : public Storable {
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		TradeListMarket() : Storable() { m_Type = "TradeListMarket"; }
		
	public:
		virtual ~TradeListMarket() {}
		
		DECLARE_GET_ADD_REMOVE(TradeDataMarket);
		
		DEFINE_OT_DYNAMIC_CAST(TradeListMarket)
	};
	
	// ******************************************************
	
	class OfferDataNym : public Displayable
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		OfferDataNym() : Displayable(), 
		valid_from("0"), valid_to("0"), 
		selling(false), scale("1"), price_per_scale("1"),
		transaction_id("0"), 
		total_assets("1"), finished_so_far("0"), 
		minimum_increment("1"), stop_price("0")
		{ m_Type = "OfferDataNym"; }
		
	public:
		virtual ~OfferDataNym() { }
		
		using Displayable::gui_label;  // The label that appears in the GUI
		
		std::string valid_from;
		std::string valid_to;
		
		std::string server_id;
		std::string asset_type_id;		// the asset type on offer.
		std::string asset_acct_id;		// the account where the asset is.
		std::string currency_type_id;	// the currency being used to purchase the asset.
		std::string currency_acct_id;	// the account where currency is.
		
		bool selling;			// true for ask, false for bid.
		
		std::string scale;	// 1oz market? 100oz market? 10,000oz market? This determines size and granularity.
		std::string price_per_scale;
		
		std::string transaction_id;
		
		std::string total_assets;
		std::string finished_so_far;
		
		
		// Each sale or purchase against (total_assets - finished_so_far) must be in minimum increments.
		// Minimum Increment must be evenly divisible by scale. 
		// (This effectively becomes a "FILL OR KILL" order if set to the same value as total_assets. Also, MUST be 1
		// or greater. CANNOT be zero. Enforce this at class level. You cannot sell something in minimum increments of 0.)
		
		std::string minimum_increment;  	
		
		std::string stop_sign;  // If this is a stop order, this will contain '<' or '>'.
		std::string stop_price;	// The price at which the stop order activates (less than X or greater than X, based on sign.)
		
		DEFINE_OT_DYNAMIC_CAST(OfferDataNym)
	};
		
	// ------------------------------------------------------
	
	class OfferListNym : public Storable {
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		OfferListNym() : Storable() { m_Type = "OfferListNym"; }
		
	public:
		virtual ~OfferListNym() {}
		
		DECLARE_GET_ADD_REMOVE(OfferDataNym);
		
		DEFINE_OT_DYNAMIC_CAST(OfferListNym)
	};
		
	// ******************************************************
	
	class TradeDataNym : public Displayable
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		TradeDataNym() : Displayable(), 
		transaction_id("0"),
		completed_count("0"), date("0"), 
		price("0"), amount_sold("0")
		{ m_Type = "TradeDataNym"; }
		
	public:
		virtual ~TradeDataNym() { }
		
		using Displayable::gui_label;  // The label that appears in the GUI
		
		std::string transaction_id;	// (transaction number for this trade.)

		std::string completed_count;	// (How many trades have processed for the associated offer? We keep count for each trade.)
		std::string date;				// (The date of this trade's execution)
		std::string price;				// (The price this trade executed at.)
		std::string amount_sold;		// (Amount of asset sold for that price.)	
		
		DEFINE_OT_DYNAMIC_CAST(TradeDataNym)
	};
	
	// ------------------------------------------------------
	
	class TradeListNym : public Storable {
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		TradeListNym() : Storable() { m_Type = "TradeListNym"; }
		
	public:
		virtual ~TradeListNym() {}
		
		DECLARE_GET_ADD_REMOVE(TradeDataNym);
		
		DEFINE_OT_DYNAMIC_CAST(TradeListNym)
	};
	
	// *************************************************
	
	// ACCOUNT (GUI local storage about my own accounts, in my wallet.)
	
	class Acct : public Displayable
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		Acct() : Displayable() { m_Type = "Acct"; }
		
	public:
		virtual ~Acct() { }
		
		using Displayable::gui_label;  // The label that appears in the GUI
		
		std::string acct_id;
		std::string server_id;
		
		DEFINE_OT_DYNAMIC_CAST(Acct)
	};
	
	// ----------------------------
	
	class BitcoinAcct : public Acct
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		BitcoinAcct() : Acct() {  m_Type = "BitcoinAcct"; }
		
	public:
		virtual ~BitcoinAcct() { }
		
		using Displayable::gui_label;  // The label that appears in the GUI
		
		using Acct::acct_id;
		using Acct::server_id;
		
		std::string bitcoin_acct_name;
		
		DEFINE_OT_DYNAMIC_CAST(BitcoinAcct)
	};
	
	// **************************************************
	
	// SERVER (GUI local storage about servers.)
	
	class ServerInfo : public Displayable
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		ServerInfo() : Displayable() { m_Type = "ServerInfo"; }
		
	public:
		virtual ~ServerInfo() { }
		
		using Displayable::gui_label;  // The label that appears in the GUI
		
		std::string server_id;
		std::string server_type;
		
		DEFINE_OT_DYNAMIC_CAST(ServerInfo)
	};
	
	// ----------------------------
	
	class Server : public ServerInfo
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		Server() : ServerInfo() { m_Type = "Server"; }
		
	public:
		virtual ~Server() { }
		
		using Displayable::gui_label;  // The label that appears in the GUI
		
		using ServerInfo::server_id;   // in base class
		using ServerInfo::server_type; // in base class
		
		std::string server_host;
		std::string server_port;
		
		DEFINE_OT_DYNAMIC_CAST(Server)
	};
	
	// ----------------------------
	
	class BitcoinServer : public Server
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		BitcoinServer() : Server() {  m_Type = "BitcoinServer";  }
		
	public:
		virtual ~BitcoinServer() {  }
		
		using Displayable::gui_label;  // The label that appears in the GUI
		
		using ServerInfo::server_id;   // in base class
		using ServerInfo::server_type; // in base class
		
		using Server::server_host;   // in base class
		using Server::server_port; // in base class
		
		std::string bitcoin_username;
		std::string bitcoin_password;
		
		DEFINE_OT_DYNAMIC_CAST(BitcoinServer)
	};
	
	// ----------------------------
	
	class RippleServer : public Server
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		RippleServer() : Server() {  m_Type = "RippleServer";  }
		
	public:
		virtual ~RippleServer() {  }
		
		using Displayable::gui_label;  // The label that appears in the GUI
		
		using ServerInfo::server_id;   // in base class
		using ServerInfo::server_type; // in base class
		
		using Server::server_host;   // in base class
		using Server::server_port; // in base class
		
		std::string ripple_username;
		std::string ripple_password;
		
		std::string namefield_id;
		std::string passfield_id;
		
		DEFINE_OT_DYNAMIC_CAST(RippleServer)
	};
	
	// ----------------------------
	
	class LoomServer : public Server
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		LoomServer() : Server() {  m_Type = "LoomServer";  }
		
	public:
		virtual ~LoomServer() {  }
		
		using Displayable::gui_label;  // The label that appears in the GUI
		
		using ServerInfo::server_id;   // in base class
		using ServerInfo::server_type; // in base class
		
		using Server::server_host;   // in base class
		using Server::server_port; // in base class
		
		std::string loom_username;
		
		std::string namefield_id;
		
		DEFINE_OT_DYNAMIC_CAST(LoomServer)
	};
	
	// ----------------------------
	
	class ContactNym : public Displayable
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		ContactNym() : Displayable() {  m_Type = "ContactNym"; }
		
	public:
		virtual ~ContactNym();
		
		using Displayable::gui_label;  // The label that appears in the GUI
		
		std::string nym_type;
		std::string nym_id;
		std::string public_key;
		std::string memo;
		
		DECLARE_GET_ADD_REMOVE(ServerInfo);
		
		DEFINE_OT_DYNAMIC_CAST(ContactNym)
	};
	
	
	// ------------------------------------------------
	
	class WalletData : public Storable
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		WalletData() : Storable() { m_Type = "WalletData"; }
		
	public:
		virtual ~WalletData() {  std::cout << "WalletData destructor" << std::endl; }
		
		// List of Bitcoin servers
		// List of Bitcoin accounts
		// Loom, etc.
		
		DECLARE_GET_ADD_REMOVE(BitcoinServer);
		DECLARE_GET_ADD_REMOVE(BitcoinAcct);
		
		DECLARE_GET_ADD_REMOVE(RippleServer);
		DECLARE_GET_ADD_REMOVE(LoomServer);

		DEFINE_OT_DYNAMIC_CAST(WalletData)
	};
	
	// ----------------------------
	
	class ContactAcct : public Displayable {
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		ContactAcct() : Displayable() { m_Type = "ContactAcct"; }
		
	public:
		virtual ~ContactAcct() { }
		
		using Displayable::gui_label;  // The label that appears in the GUI
		
		std::string server_type;
		std::string server_id;
		std::string asset_type_id;
		std::string acct_id;
		std::string nym_id;
		std::string memo;
		std::string public_key;
		
		DEFINE_OT_DYNAMIC_CAST(ContactAcct)
	};
	
	// ----------------------------
	
	
	class Contact : public Displayable {
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		Contact() : Displayable() { m_Type = "Contact"; }
		
	public:
		virtual ~Contact();
		
		using Displayable::gui_label;  // The label that appears in the GUI
		
		std::string contact_id;
		std::string email;
		std::string memo;
		std::string public_key;
		
		DECLARE_GET_ADD_REMOVE(ContactNym);
		DECLARE_GET_ADD_REMOVE(ContactAcct);
		
		DEFINE_OT_DYNAMIC_CAST(Contact)
	};
	
	// ----------------------------
	
	class AddressBook : public Storable {
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		AddressBook() : Storable() { m_Type = "AddressBook"; }
		
	public:
		virtual ~AddressBook();
		
		DECLARE_GET_ADD_REMOVE(Contact);
		
		DEFINE_OT_DYNAMIC_CAST(AddressBook)
	};
} // Namespace OTDB

// ********************************************************************









// *******************************************************************************************
//
// StorageFS -- FILE-SYSTEM Storage Context
//
//
namespace OTDB 
{
	// --------------------------------------------------------------------------
	//
	// StorageFS means "Storage on Filesystem."
	// 
	// This is the first subclass of OTDB::Storage -- but it won't be the last!
	//
	class StorageFS : public Storage 
	{
		std::string m_strFullPath;
		std::string m_strWalletFile;
		
	protected:
		StorageFS();// You have to use the factory to instantiate (so it can create the Packer also.)
					// But from there, however you Init, Store, Query, etc is entirely up to you.
		
		long ConstructAndConfirmPath(std::string & strOutput,
									 const std::string& strFolder, const std::string& oneStr="",  
									 const std::string& twoStr="",  const std::string& threeStr="");
		
		// **********************************************************

		// If you wish to make your own subclass of OTDB::Storage, then use StorageFS as an example.
		// The below 6 methods are the only overrides you need to copy.
		//
		virtual bool onStorePackedBuffer(PackedBuffer & theBuffer, std::string strFolder, std::string oneStr="", 
										 std::string twoStr="", std::string threeStr="");
		
		virtual bool onQueryPackedBuffer(PackedBuffer & theBuffer, std::string strFolder, std::string oneStr="",
										 std::string twoStr="", std::string threeStr="");
		
		virtual bool onStorePlainString(std::string & theBuffer, std::string strFolder, std::string oneStr="", 
										std::string twoStr="", std::string threeStr="");
		
		virtual bool onQueryPlainString(std::string & theBuffer, std::string strFolder, std::string oneStr="",
										std::string twoStr="", std::string threeStr="");
		
		virtual bool onEraseValueByKey(std::string strFolder, std::string oneStr="",
										std::string twoStr="", std::string threeStr="");
		
		// -----------------------------------------------------
		
	public:
		virtual bool Init(std::string oneStr="", std::string twoStr="", std::string threeStr="", 
						  std::string fourStr="", std::string fiveStr="", std::string sixStr="");
		
		// -----------------------------------------
		// See if the file is there.
		virtual bool Exists(std::string strFolder, 
							std::string oneStr="", std::string twoStr="", std::string threeStr="");
		
		// **********************************************************
		
		static StorageFS * Instantiate() { return new StorageFS; }
		
		virtual ~StorageFS();
		
		// -----------------------------------------
		// lower level calls.
		
		bool ConfirmOrCreateFolder(const char * szFolderName, struct stat *pst=NULL); // local to data_folder
		bool ConfirmFile(const char * szFileName, struct stat *pst=NULL); // local to data_folder
		
		const char * GetFullPath() { return m_strFullPath.c_str(); }  // path to data_folder
		const char * GetWalletFile() { return m_strWalletFile.c_str(); } // wallet filename
		
		const char * PathSeparator();
		
		/*
		 IN BASE CLASS:
		 
		 // -----------------------------------------
		 // Store/Retrieve a string.
		 
		 bool StoreString(std::string strContents, std::string strFolder, 
			std::string oneStr="", std::string twoStr="", std::string threeStr="");
		 
		 std::string QueryString(std::string strFolder, std::string oneStr="",
			std::string twoStr="", std::string threeStr="");
		 
		 bool StorePlainString(std::string strContents, std::string strFolder, 
			std::string oneStr="", std::string twoStr="", std::string threeStr="");
		 
		 std::string QueryPlainString(std::string strFolder, std::string oneStr="",
			std::string twoStr="", std::string threeStr="");
		 
		 // -----------------------------------------
		 // Store/Retrieve an object. (Storable.)
		 
		 bool StoreObject(Storable & theContents, std::string strFolder, 
			 std::string oneStr="", std::string twoStr="", std::string threeStr="");
		 
		 // Use %newobject OTDB::Storage::Query();
		 Storable * QueryObject(StoredObjectType theObjectType,
			 std::string strFolder, std::string oneStr="",
			 std::string twoStr="", std::string threeStr="");
		 */
	};
	
	// Other storage subclasses may go here, for storing in SQL lite,
	// or couchDB, mongoDB, distributed DB, etc...	
	
	// class StorageCouchDB
	// class CloudMagic
	// class SQL-LITE
	//
	// Etc.
	
	// Also, coders using the API should be able to subclass Storage in their own language via SWIG.
	
} // namespace OTDB
// *******************************************************************************************






// IStorable-derived types...
//
//
// BELOW are the SUBCLASSES of the storable objects that actually get INSTANTIATED,
// based on WHICH PACKER is being used.

// If you are adding a new DATA OBJECT, then you probably want to add lines below
// for EACH of the different packer types (MsgPack, Protocol Buffers, JSON, etc.)
//

#define OT_USING_ISTORABLE_HOOKS \
	using IStorable::hookBeforePack; \
	using IStorable::hookAfterUnpack







// *******************************************************************************************

// JSON will be the next packer that I add

#if defined (OTDB_JSON_PACKING)
//#include "JSON - LIBRARY . h"   // coming soon.
#endif // defined (OTDB_JSON_PACKING)
// *******************************************************************************************







// *******************************************************************************************
#if defined (OTDB_MESSAGE_PACK)
#include <msgpack.hpp>
//
// To declare MsgPack-packed OT objects (IStorableMsgpack):
/*
 OT_MSGPACK_BEGIN(BitcoinAcctMsgpack, BitcoinAcct)
 MSGPACK_DEFINE(acct_id, server_id, bitcoin_acct_name, gui_label);
 OT_MSGPACK_END;
 */
// Where BitcoinAcctMsgpack is the new class being declared (for that packer),
// BitcoinAcct is the OT Data object that it serializes, and where bitcoin_address,
// bitcoin_acct_name, and gui_label are being used as examples for the data members
// being serialized.
//
// DON'T use a semicolon after the first macro. (OT_MSGPACK_BEGIN.)
// But DO put semicolons after the MSGPACK_DEFINE and OT_MSGPACK_END macros.
//
// The idea is that the data members themselves (in the above example, 
// bitcoin_address, bitcoin_acct_name, and gui_label) are actually implemented
// by BitcoinAcct (the base), and any other packer library could similarly
// be subclassing that base as we are here with BitcoinAcctMsgPack.
//
// To cap it all off, MsgPack-specific functionality (which we may also need
// in 30 other MsgPack classes like BitcoinServerMsgpack, LoomAcctMsgpack,
// etc) can be added to all of the msgPack objects via the IStorableMsgpack
// interface, even though they all have different base classes (oriented around
// their data, and not their packing.)
//


// ----------------------------------------------
#define OT_MSGPACK_BEGIN(theType, theBaseType, theObjectType) \
class theType : public theBaseType, implements IStorableMsgpack \
{		\
protected: \
	std::string m_Type; \
public: \
	static Storable * Instantiate() { return dynamic_cast<Storable *>(new theType); } \
\
	theType() : theBaseType(), IStorableMsgpack() { m_Type = StoredObjectTypeStrings[static_cast<int>(theObjectType)]; m_Type += "Msgpack"; \
	} \
\
	theType(const theType & rhs) : theBaseType(), IStorableMsgpack() { m_Type = StoredObjectTypeStrings[static_cast<int>(theObjectType)]; m_Type += "Msgpack"; \
	(const_cast<theType &>(rhs)).CopyToObject(const_cast<theType&>(*this)); } \
\
	void CopyToObject(theType & theNewStorable) const { \
		OTPacker * pPacker = OTPacker::Create(PACK_MESSAGE_PACK); \
		OT_ASSERT(NULL != pPacker); PackedBuffer * pBuffer = pPacker->Pack(const_cast<theType&>(*this)); \
		OT_ASSERT(NULL != pBuffer); \
		OT_ASSERT(pPacker->Unpack(*pBuffer, theNewStorable)); delete pPacker; delete pBuffer; } \
\
	theType & operator=(const theType & rhs) { \
		const_cast<theType &>(rhs).CopyToObject(const_cast<theType&>(*this)); \
		return *this; } \
\
	virtual theBaseType *clone(void) const { \
		return dynamic_cast<theBaseType *>(do_clone()); } \
\
	IStorable * do_clone(void) const {  Storable * pNewStorable = Storable::Create(theObjectType, PACK_MESSAGE_PACK); \
		OT_ASSERT(NULL != pNewStorable); (const_cast<theType&>(*this)).CopyToObject(dynamic_cast<theType&>(*pNewStorable)); \
		return dynamic_cast<IStorable *>(pNewStorable); } \
\
virtual ~theType() { } \
	virtual bool PerformPack(BufferMsgpack& theBuffer) { msgpack::pack(theBuffer.GetBuffer(), *this); return true; } \
	virtual bool PerformUnpack(BufferMsgpack& theBuffer) { msgpack::zone z; msgpack::object obj; msgpack::unpack_return ret = \
		msgpack::unpack(theBuffer.GetBuffer().data(), theBuffer.GetBuffer().size(), NULL, &z, &obj); if (msgpack::UNPACK_SUCCESS == ret) \
		{ obj.convert(const_cast<theType*>(this)); return true; } return false; }

#define OT_MSGPACK_END  } 

// ----- Next go these:
//	OT_USING_ISTORABLE_HOOKS;
//	MSGPACK_DEFINE(gui_label, server_id, server_type, asset_type_id, acct_id, nym_id, memo, public_key);

// ----- Sometimes looks more like this:
//	virtual void hookBeforePack(); // This is called just before packing a storable. (Opportunity to copy values...)
//	virtual void hookAfterUnpack(); // This is called just after unpacking a storable. (Opportunity to copy values...)
//	std::deque<BitcoinServerMsgpack>	deque_BitcoinServers;
//	std::deque<BitcoinAcctMsgpack>		deque_BitcoinAccts;
//	MSGPACK_DEFINE(deque_BitcoinServers, deque_BitcoinAccts);

// -----------------------------------------------------------
// This part is commented out. Why? Because I think it's unnecessary. Operator= is not inherited.
// That means when I copy these objects, only the WalletDataMsgpack data members are being copied,
// not the 

// Deprecated:
// !!!!! This bottom part MUST be directly before the OT_MSGPACK_END!!!!!!!!!
// Notice I declare an op=, so the compiler won't define a default one. Why?
// Because the default one will call the base class op= as well, and copy over the
// pointer lists that are in the data portion. (I don't want that.) I want to only copy
// the basic members and the deques, NOT the pointers. So I declare op= and do so.
// NO semicolon after this one...
/*
 #define OT_MSGPACK_BEGIN_SWAP(theType) \
 public: \
 theType & operator=(theType rhs) { \
 this->swap(rhs); \
 return *this; \
 } \
 void swap (theType & rhs) {
 
 // semicolon after this one.
 #define OT_MSGPACK_SWAP_MEMBER(theMember) \
 std::swap(theMember, rhs.theMember)
 
 */
//
// You put the actual assignments in like this:
//		OT_MSGPACK_SWAP_MEMBER(theMember);
//		OT_MSGPACK_SWAP_MEMBER(theMember);
//		OT_MSGPACK_SWAP_MEMBER(theMember);


// Finishing with this, and semicolon after.
//#define OT_MSGPACK_END  } }



// ----------------------------------------------


namespace OTDB 
{	
	class BufferMsgpack;
	
	// Interface:	IStorableMsgpack
	//
	DeclareBasedInterface(IStorableMsgpack, IStorable)
		virtual bool onPack(PackedBuffer& theBuffer, Storable& inObj);
		virtual bool onUnpack(PackedBuffer& theBuffer, Storable& outObj);
		virtual bool PerformPack(BufferMsgpack& theBuffer) = 0;
		virtual bool PerformUnpack(BufferMsgpack& theBuffer) = 0;
	OT_USING_ISTORABLE_HOOKS;
	EndInterface
	
	
	// ---------------------------------
	// BUFFER for MsgPack.
	//
	// typedef PackedBufferSubclass<PackerMsgpack, IStorableMsgpack, msgpack::sbuffer> BufferMsgpack;
	DECLARE_PACKED_BUFFER_SUBCLASS(BufferMsgpack, PackerSubclass<BufferMsgpack>, IStorableMsgpack, msgpack::sbuffer);
	
	// ---------------
	// Msgpack packer.
	//
	typedef PackerSubclass<BufferMsgpack> PackerMsgpack;
	
	// -------------------------------------------------------
	
	
	// Do NOT use a semicolon after the first macro. (OT_MSGPACK_BEGIN.)
	// DO put a semicolon after the MSGPACK_DEFINE macro.
	// DO put a semicolon after the OT_MSGPACK_END macro.
	
	// -------------------------------------------------------
	OT_MSGPACK_BEGIN(BlobMsgpack, Blob, STORED_OBJ_BLOB)
		OT_USING_ISTORABLE_HOOKS;
		MSGPACK_DEFINE(m_memBuffer);
//		OT_MSGPACK_BEGIN_SWAP(BlobMsgpack)
//		OT_MSGPACK_SWAP_MEMBER(m_memBuffer);
	OT_MSGPACK_END;	
	// -------------------------------------------------------
	OT_MSGPACK_BEGIN(StringMsgpack, OTDBString, STORED_OBJ_STRING)
		StringMsgpack(const std::string& rhs) : OTDBString(rhs), IStorableMsgpack() { }
		OT_USING_ISTORABLE_HOOKS;
		MSGPACK_DEFINE(m_string);
//		OT_MSGPACK_BEGIN_SWAP(StringMsgpack)
//		OT_MSGPACK_SWAP_MEMBER(m_string);
	OT_MSGPACK_END;	
	// -------------------------------------------------------
	OT_MSGPACK_BEGIN(StringMapMsgpack, StringMap, STORED_OBJ_STRING_MAP)
		OT_USING_ISTORABLE_HOOKS;
		MSGPACK_DEFINE(the_map);
//		OT_MSGPACK_BEGIN_SWAP(StringMapMsgpack)
//		OT_MSGPACK_SWAP_MEMBER(the_map);
	OT_MSGPACK_END;	
	// -------------------------------------------------------
	OT_MSGPACK_BEGIN(ServerInfoMsgpack, ServerInfo, STORED_OBJ_SERVER_INFO)
		OT_USING_ISTORABLE_HOOKS;
		MSGPACK_DEFINE(gui_label, server_id, server_type);
//		OT_MSGPACK_BEGIN_SWAP(ServerInfoMsgpack)
//		OT_MSGPACK_SWAP_MEMBER(gui_label);
//		OT_MSGPACK_SWAP_MEMBER(server_id);
//		OT_MSGPACK_SWAP_MEMBER(server_type);
	OT_MSGPACK_END;	
	// -------------------------------------------------------
	OT_MSGPACK_BEGIN(BitcoinAcctMsgpack, BitcoinAcct, STORED_OBJ_BITCOIN_ACCT)
		OT_USING_ISTORABLE_HOOKS;
		MSGPACK_DEFINE(gui_label, acct_id, server_id, bitcoin_acct_name);
//		OT_MSGPACK_BEGIN_SWAP(BitcoinAcctMsgpack)
//		OT_MSGPACK_SWAP_MEMBER(gui_label);
//		OT_MSGPACK_SWAP_MEMBER(acct_id);
//		OT_MSGPACK_SWAP_MEMBER(server_id);
//		OT_MSGPACK_SWAP_MEMBER(bitcoin_acct_name);
	OT_MSGPACK_END;
	// -------------------------------------------------------
	OT_MSGPACK_BEGIN(BitcoinServerMsgpack, BitcoinServer, STORED_OBJ_BITCOIN_SERVER)
		OT_USING_ISTORABLE_HOOKS;
		MSGPACK_DEFINE(gui_label, server_id, server_type, server_host, server_port, bitcoin_username, bitcoin_password);
//		OT_MSGPACK_BEGIN_SWAP(BitcoinServerMsgpack)
//		OT_MSGPACK_SWAP_MEMBER(gui_label);
//		OT_MSGPACK_SWAP_MEMBER(server_id);
//		OT_MSGPACK_SWAP_MEMBER(server_type);
//		OT_MSGPACK_SWAP_MEMBER(server_host);
//		OT_MSGPACK_SWAP_MEMBER(server_port);
//		OT_MSGPACK_SWAP_MEMBER(bitcoin_username);
//		OT_MSGPACK_SWAP_MEMBER(bitcoin_password);
	OT_MSGPACK_END;
	// -------------------------------------------------------
	OT_MSGPACK_BEGIN(RippleServerMsgpack, RippleServer, STORED_OBJ_RIPPLE_SERVER)
	OT_USING_ISTORABLE_HOOKS;
	MSGPACK_DEFINE(gui_label, server_id, server_type, server_host, server_port, ripple_username, ripple_password, namefield_id, passfield_id);
//		OT_MSGPACK_BEGIN_SWAP(RippleServerMsgpack)
//		OT_MSGPACK_SWAP_MEMBER(gui_label);
//		OT_MSGPACK_SWAP_MEMBER(server_id);
//		OT_MSGPACK_SWAP_MEMBER(server_type);
//		OT_MSGPACK_SWAP_MEMBER(server_host);
//		OT_MSGPACK_SWAP_MEMBER(server_port);
//		OT_MSGPACK_SWAP_MEMBER(ripple_username);
//		OT_MSGPACK_SWAP_MEMBER(ripple_password);
//		OT_MSGPACK_SWAP_MEMBER(namefield_id);
//		OT_MSGPACK_SWAP_MEMBER(passfield_id);
	OT_MSGPACK_END;
	// -------------------------------------------------------
	OT_MSGPACK_BEGIN(LoomServerMsgpack, LoomServer, STORED_OBJ_LOOM_SERVER)
		OT_USING_ISTORABLE_HOOKS;
		MSGPACK_DEFINE(gui_label, server_id, server_type, server_host, server_port, loom_username, namefield_id);
//		OT_MSGPACK_BEGIN_SWAP(LoomServerMsgpack)
//		OT_MSGPACK_SWAP_MEMBER(gui_label);
//		OT_MSGPACK_SWAP_MEMBER(server_id);
//		OT_MSGPACK_SWAP_MEMBER(server_type);
//		OT_MSGPACK_SWAP_MEMBER(server_host);
//		OT_MSGPACK_SWAP_MEMBER(server_port);
//		OT_MSGPACK_SWAP_MEMBER(loom_username);
//		OT_MSGPACK_SWAP_MEMBER(namefield_id);
	OT_MSGPACK_END;
	// -------------------------------------------------------
	OT_MSGPACK_BEGIN(ContactAcctMsgpack, ContactAcct, STORED_OBJ_CONTACT_ACCT)
		OT_USING_ISTORABLE_HOOKS;
		MSGPACK_DEFINE(gui_label, server_id, server_type, asset_type_id, acct_id, nym_id, memo, public_key);
//		OT_MSGPACK_BEGIN_SWAP(ContactAcctMsgpack)
//		OT_MSGPACK_SWAP_MEMBER(gui_label);
//		OT_MSGPACK_SWAP_MEMBER(server_id);
//		OT_MSGPACK_SWAP_MEMBER(server_type);
//		OT_MSGPACK_SWAP_MEMBER(asset_type_id);
//		OT_MSGPACK_SWAP_MEMBER(acct_id);
//		OT_MSGPACK_SWAP_MEMBER(nym_id);
//		OT_MSGPACK_SWAP_MEMBER(memo);
//		OT_MSGPACK_SWAP_MEMBER(public_key);
	OT_MSGPACK_END;
	// -------------------------------------------------------
	OT_MSGPACK_BEGIN(ContactNymMsgpack, ContactNym, STORED_OBJ_CONTACT_NYM)
		virtual void hookBeforePack(); // This is called just before packing a storable. (Opportunity to copy values...)
		virtual void hookAfterUnpack(); // This is called just after unpacking a storable. (Opportunity to copy values...)
		std::deque<ServerInfoMsgpack>	deque_ServerInfos;
		MSGPACK_DEFINE(gui_label, nym_id, nym_type, public_key, memo, deque_ServerInfos);
//		OT_MSGPACK_BEGIN_SWAP(ContactNymMsgpack)
//		OT_MSGPACK_SWAP_MEMBER(gui_label);
//		OT_MSGPACK_SWAP_MEMBER(nym_id);
//		OT_MSGPACK_SWAP_MEMBER(nym_type);
//		OT_MSGPACK_SWAP_MEMBER(public_key);
//		OT_MSGPACK_SWAP_MEMBER(memo);
//		OT_MSGPACK_SWAP_MEMBER(deque_ServerInfos);
	OT_MSGPACK_END;	
	// -------------------------------------------------------
	OT_MSGPACK_BEGIN(ContactMsgpack, Contact, STORED_OBJ_CONTACT)
		virtual void hookBeforePack(); // This is called just before packing a storable. (Opportunity to copy values...)
		virtual void hookAfterUnpack(); // This is called just after unpacking a storable. (Opportunity to copy values...)
		std::deque<ContactNymMsgpack>	deque_Nyms;
		std::deque<ContactAcctMsgpack>	deque_Accounts;
		MSGPACK_DEFINE(gui_label, contact_id, email, public_key, memo, deque_Nyms, deque_Accounts);
//		OT_MSGPACK_BEGIN_SWAP(ContactMsgpack)
//		OT_MSGPACK_SWAP_MEMBER(gui_label);
//		OT_MSGPACK_SWAP_MEMBER(contact_id);
//		OT_MSGPACK_SWAP_MEMBER(email);
//		OT_MSGPACK_SWAP_MEMBER(public_key);
//		OT_MSGPACK_SWAP_MEMBER(memo);
//		OT_MSGPACK_SWAP_MEMBER(deque_Nyms);
//		OT_MSGPACK_SWAP_MEMBER(deque_Accounts);
	OT_MSGPACK_END;	
	// -------------------------------------------------------
	OT_MSGPACK_BEGIN(AddressBookMsgpack, AddressBook, STORED_OBJ_ADDRESS_BOOK)
		virtual void hookBeforePack(); // This is called just before packing a storable. (Opportunity to copy values...)
		virtual void hookAfterUnpack(); // This is called just after unpacking a storable. (Opportunity to copy values...)
		std::deque<ContactMsgpack>	deque_Contacts;
		MSGPACK_DEFINE(deque_Contacts);
//		OT_MSGPACK_BEGIN_SWAP(AddressBookMsgpack)
//		OT_MSGPACK_SWAP_MEMBER(deque_Contacts);
	OT_MSGPACK_END;	
	// -------------------------------------------------------
	OT_MSGPACK_BEGIN(WalletDataMsgpack, WalletData, STORED_OBJ_WALLET_DATA)
		virtual void hookBeforePack(); // This is called just before packing a storable. (Opportunity to copy values...)
		virtual void hookAfterUnpack(); // This is called just after unpacking a storable. (Opportunity to copy values...)
		std::deque<BitcoinServerMsgpack>	deque_BitcoinServers;
		std::deque<BitcoinAcctMsgpack>		deque_BitcoinAccts;
		std::deque<RippleServerMsgpack>		deque_RippleServers;
		std::deque<LoomServerMsgpack>		deque_LoomServers;
		MSGPACK_DEFINE(deque_BitcoinServers, deque_BitcoinAccts, deque_RippleServers, deque_LoomServers);
//		OT_MSGPACK_BEGIN_SWAP(WalletDataMsgpack)
//		OT_MSGPACK_SWAP_MEMBER(deque_BitcoinServers);
//		OT_MSGPACK_SWAP_MEMBER(deque_BitcoinAccts);
//		OT_MSGPACK_SWAP_MEMBER(deque_RippleServers);
//		OT_MSGPACK_SWAP_MEMBER(deque_LoomServers);
	OT_MSGPACK_END;
	// -------------------------------------------------------

	// You might ask, why did I code the "copy and swap" idiom above, and then comment it out?
	// Because I'm now storing smart pointers instead of regular pointers, in the lists of the
	// objects above. Therefore I'm not so worried about the copy constructor, operator=, etc.
	// The deques will copy over exactly, and the lists will copy the smart pointers, so I don't
	// have to worry about the lists double-deleting anymore.
	
	// -------------------------------------------------------
	OT_MSGPACK_BEGIN(MarketDataMsgpack, MarketData, STORED_OBJ_MARKET_DATA)
		OT_USING_ISTORABLE_HOOKS;
		MSGPACK_DEFINE(gui_label, server_id, market_id, asset_type_id, currency_type_id, 
				   scale, total_assets, number_bids, number_asks, 
				   last_sale_price, current_bid, current_ask, 
				   volume_trades, volume_assets, volume_currency, 
				   recent_highest_bid, recent_lowest_ask);
	OT_MSGPACK_END;
	// -------------------------------------------------------
	OT_MSGPACK_BEGIN(MarketListMsgpack, MarketList, STORED_OBJ_MARKET_LIST)
		virtual void hookBeforePack(); // This is called just before packing a storable. (Opportunity to copy values...)
		virtual void hookAfterUnpack(); // This is called just after unpacking a storable. (Opportunity to copy values...)
		std::deque<MarketDataMsgpack>	deque_Markets;
		MSGPACK_DEFINE(deque_Markets);
	OT_MSGPACK_END;
	// -------------------------------------------------------
	
	OT_MSGPACK_BEGIN(BidDataMsgpack, BidData, STORED_OBJ_BID_DATA)
		OT_USING_ISTORABLE_HOOKS;
		MSGPACK_DEFINE(gui_label, transaction_id, price_per_scale, available_assets, minimum_increment);
	OT_MSGPACK_END;
	// -------------------------------------------------------
	OT_MSGPACK_BEGIN(AskDataMsgpack, AskData, STORED_OBJ_ASK_DATA)
		OT_USING_ISTORABLE_HOOKS;
		MSGPACK_DEFINE(gui_label, transaction_id, price_per_scale, available_assets, minimum_increment);
	OT_MSGPACK_END;
	// -------------------------------------------------------
	
	OT_MSGPACK_BEGIN(OfferListMarketMsgpack, OfferListMarket, STORED_OBJ_OFFER_LIST_MARKET)
		virtual void hookBeforePack(); // This is called just before packing a storable. (Opportunity to copy values...)
		virtual void hookAfterUnpack(); // This is called just after unpacking a storable. (Opportunity to copy values...)
		std::deque<BidDataMsgpack>	deque_Bids;
		std::deque<AskDataMsgpack>	deque_Asks;
	MSGPACK_DEFINE(deque_Bids, deque_Asks);
	OT_MSGPACK_END;
	// -------------------------------------------------------
	
	OT_MSGPACK_BEGIN(TradeDataMarketMsgpack, TradeDataMarket, STORED_OBJ_TRADE_DATA_MARKET)
		OT_USING_ISTORABLE_HOOKS;
		MSGPACK_DEFINE(gui_label, transaction_id, date, price, amount_sold);
	OT_MSGPACK_END;
	// -------------------------------------------------------
	OT_MSGPACK_BEGIN(TradeListMarketMsgpack, TradeListMarket, STORED_OBJ_TRADE_LIST_MARKET)
		virtual void hookBeforePack(); // This is called just before packing a storable. (Opportunity to copy values...)
		virtual void hookAfterUnpack(); // This is called just after unpacking a storable. (Opportunity to copy values...)
		std::deque<TradeDataMarketMsgpack>	deque_Trades;
		MSGPACK_DEFINE(deque_Trades);
	OT_MSGPACK_END;
	// -------------------------------------------------------
	
	OT_MSGPACK_BEGIN(OfferDataNymMsgpack, OfferDataNym, STORED_OBJ_OFFER_DATA_NYM)
	OT_USING_ISTORABLE_HOOKS;
	MSGPACK_DEFINE(gui_label, valid_from, valid_to, server_id, 
				   asset_type_id, asset_acct_id, 
				   currency_type_id, currency_acct_id, 
				   selling, scale, price_per_scale, transaction_id, 
				   total_assets, finished_so_far, minimum_increment, 
				   stop_sign, stop_price);
	OT_MSGPACK_END;
	// -------------------------------------------------------
	OT_MSGPACK_BEGIN(OfferListNymMsgpack, OfferListNym, STORED_OBJ_OFFER_LIST_NYM)
		virtual void hookBeforePack(); // This is called just before packing a storable. (Opportunity to copy values...)
		virtual void hookAfterUnpack(); // This is called just after unpacking a storable. (Opportunity to copy values...)
		std::deque<OfferDataNymMsgpack>	deque_Offers;
		MSGPACK_DEFINE(deque_Offers);
	OT_MSGPACK_END;
	// -------------------------------------------------------

	OT_MSGPACK_BEGIN(TradeDataNymMsgpack, TradeDataNym, STORED_OBJ_TRADE_DATA_NYM)
		OT_USING_ISTORABLE_HOOKS;
		MSGPACK_DEFINE(gui_label, transaction_id, completed_count, date, 
					   price, amount_sold);
	OT_MSGPACK_END;
	// -------------------------------------------------------
	OT_MSGPACK_BEGIN(TradeListNymMsgpack, TradeListNym, STORED_OBJ_TRADE_LIST_NYM)
		virtual void hookBeforePack(); // This is called just before packing a storable. (Opportunity to copy values...)
		virtual void hookAfterUnpack(); // This is called just after unpacking a storable. (Opportunity to copy values...)
		std::deque<TradeDataNymMsgpack>	deque_Trades;
		MSGPACK_DEFINE(deque_Trades);
	OT_MSGPACK_END;
	// -------------------------------------------------------
	
} // namespace OTDB

#endif // defined (OTDB_MESSAGE_PACK)
// *******************************************************************************************












// *******************************************************************************************

#if defined(OTDB_PROTOCOL_BUFFERS)
#include "Generics.pb.h"
#include "Markets.pb.h"
#include "Bitcoin.pb.h"
#include "Moneychanger.pb.h"
// To make subclasses of the various data objects (for Protocol Buffers):
//
// typedef ProtobufSubclass<theBaseType, theInternalType> theType;
//
// Also, REMEMBER for each object type declared, to add the hooks to the CPP file.
// (Instructions are below.)
//
// ----------------------------------------------------
/* 
 REPLACING OT_PROTOBUF_DECLARE() WITH A TEMPLATE FOR NOW...
 
 #define OT_PROTOBUF_DECLARE(theType, theBaseType, theInternalType) \
 class theType : public theBaseType, implements IStorablePB \
 {		\
private: \
	theInternalType __pb_obj; \
 protected: \
	theType() : theBaseType() { } \
 public: \
	::google::protobuf::Message & getPBMessage() { return dynamic_cast<::google::protobuf::Message>(__pb_obj); } \
	static Storable * Instantiate() { return dynamic_cast<Storable *>(new theType()); } \
	virtual ~theType() { } \
	virtual void hookBeforePack(); \
	virtual void hookAfterUnpack(); \
 }
 //	OT_PROTOBUF_DECLARE(BitcoinAcctPB, BitcoinAcct, BitcoinAcct_InternalPB);
 //	OT_PROTOBUF_DECLARE(BitcoinServerPB, BitcoinServer, BitcoinServer_InternalPB);
 
 
 
 #define DECLARE_PACKED_BUFFER_SUBCLASS(theNewType, thePackerType, theInterfaceType, theInternalType) \
 class theNewType : public PackedBuffer \
 { \
	friend class		thePackerType; \
	friend Interface	theInterfaceType; \
	theInternalType		m_buffer; \
 \
 public: \
	theNewType() : PackedBuffer() {} \
	 virtual ~theNewType(); \
	 virtual bool PackString(std::string& theString); \
	 virtual bool UnpackString(std::string& theString); \
	 virtual bool ReadFromIStream(std::istream &inStream, long lFilesize); \
	 virtual bool WriteToOStream(std::ostream &outStream); \
 }
 */




namespace OTDB 
{
	
	// Interface:    IStorablePB
	//
	DeclareBasedInterface(IStorablePB, IStorable)
		virtual ::google::protobuf::Message * getPBMessage();
		virtual bool onPack(PackedBuffer& theBuffer, Storable& inObj);
		virtual bool onUnpack(PackedBuffer& theBuffer, Storable& outObj);
	OT_USING_ISTORABLE_HOOKS;
	EndInterface
	
	// ----------------------------------------------------
	// BUFFER for Protocol Buffers.
	// Google's protocol buffers serializes to std::strings and streams. How conveeeeeenient. 
	//
	//typedef PackedBufferSubclass<PackerPB, IStorablePB, std::string> BufferPB;
	DECLARE_PACKED_BUFFER_SUBCLASS(BufferPB, PackerSubclass<BufferPB>, IStorablePB, std::string);
	
	// ---------------
	// Protocol Buffers packer.
	//
	typedef PackerSubclass<BufferPB> PackerPB;
	
	// ----------------------------------------------------
	// Used for subclassing IStorablePB:
	//
	template<class theBaseType, class theInternalType, StoredObjectType theObjectType>
	class ProtobufSubclass : public theBaseType, implements IStorablePB 
	{
	private:
		theInternalType __pb_obj;
		std::string m_Type;
	public: 
		static Storable * Instantiate() 
		{ return dynamic_cast<Storable *>(new ProtobufSubclass<theBaseType, theInternalType, theObjectType>); } 
		
		ProtobufSubclass() : theBaseType(), IStorablePB() { m_Type = StoredObjectTypeStrings[static_cast<int>(theObjectType)]; m_Type += "PB"; 
			/*std::cout << m_Type.c_str() << " -- Constructor" << std::endl;*/ } 
		
		ProtobufSubclass(const ProtobufSubclass<theBaseType,theInternalType,theObjectType> & rhs) : theBaseType(), IStorablePB() 
		{ m_Type = StoredObjectTypeStrings[static_cast<int>(theObjectType)]; m_Type += "PB"; 
			/*std::cout << m_Type.c_str() << " -- Copy Constructor" << std::endl; */ rhs.CopyToObject(*this); } 
		
		ProtobufSubclass<theBaseType,theInternalType,theObjectType> & 
		operator= (const ProtobufSubclass<theBaseType,theInternalType,theObjectType> & rhs)
		{ rhs.CopyToObject(*this); return *this; } 
		
		void CopyToObject(ProtobufSubclass<theBaseType,theInternalType,theObjectType> & theNewStorable) const
		{	OTPacker * pPacker = OTPacker::Create(PACK_PROTOCOL_BUFFERS);
			const OTDB::Storable * pIntermediate = dynamic_cast<const OTDB::Storable *>(this);
			OT_ASSERT(NULL != pPacker); PackedBuffer * pBuffer = pPacker->Pack(*(const_cast<OTDB::Storable*>(pIntermediate))); OT_ASSERT(NULL != pBuffer);
			OT_ASSERT(pPacker->Unpack(*pBuffer, theNewStorable)); delete pPacker; delete pBuffer; }	
		
		virtual ::google::protobuf::Message * getPBMessage(); 
		
//		IStorable * clone(void) const 
//			{return dynamic_cast<IStorable *>(new ProtobufSubclass<theBaseType, theInternalType, theObjectType>(*this));}
		
		virtual theBaseType * clone(void) const 
		{  /*std::cout << "Cloning a " << m_Type.c_str() << std::endl;*/ return dynamic_cast<theBaseType *>(do_clone()); }
		
		IStorable * do_clone(void) const
		{  Storable * pNewStorable = Storable::Create(theObjectType, PACK_PROTOCOL_BUFFERS);
			OT_ASSERT(NULL != pNewStorable); CopyToObject(*(dynamic_cast< ProtobufSubclass<theBaseType,theInternalType,theObjectType> * > (pNewStorable))); return dynamic_cast<IStorable *>(pNewStorable);}
		
		virtual ~ProtobufSubclass() { } 
		OT_USING_ISTORABLE_HOOKS;
		virtual void hookBeforePack();  // <=== Implement this if you subclass.
		virtual void hookAfterUnpack(); // <=== Implement this if you subclass.
	};
	
	
#define DECLARE_PROTOBUF_SUBCLASS(theBaseType, theInternalType, theNewType, theObjectType) \
	template<> void ProtobufSubclass<theBaseType, theInternalType, theObjectType>::hookBeforePack(); \
	template<> void ProtobufSubclass<theBaseType, theInternalType, theObjectType>::hookAfterUnpack(); \
	typedef ProtobufSubclass<theBaseType, theInternalType, theObjectType>	theNewType
	
	// ---------------------------------------------
	// THE ACTUAL SUBCLASSES: 
	
	DECLARE_PROTOBUF_SUBCLASS(OTDBString,	String_InternalPB,			StringPB,			STORED_OBJ_STRING);
	DECLARE_PROTOBUF_SUBCLASS(Blob,			Blob_InternalPB,			BlobPB,				STORED_OBJ_BLOB);
	DECLARE_PROTOBUF_SUBCLASS(StringMap,	StringMap_InternalPB,		StringMapPB,		STORED_OBJ_STRING_MAP);
	DECLARE_PROTOBUF_SUBCLASS(BitcoinAcct,	BitcoinAcct_InternalPB,		BitcoinAcctPB,		STORED_OBJ_BITCOIN_ACCT);
	DECLARE_PROTOBUF_SUBCLASS(BitcoinServer,BitcoinServer_InternalPB,	BitcoinServerPB,	STORED_OBJ_BITCOIN_SERVER);
	DECLARE_PROTOBUF_SUBCLASS(RippleServer,	RippleServer_InternalPB,	RippleServerPB,		STORED_OBJ_RIPPLE_SERVER);
	DECLARE_PROTOBUF_SUBCLASS(LoomServer,	LoomServer_InternalPB,		LoomServerPB,		STORED_OBJ_LOOM_SERVER);
	DECLARE_PROTOBUF_SUBCLASS(ServerInfo,	ServerInfo_InternalPB,		ServerInfoPB,		STORED_OBJ_SERVER_INFO);
	DECLARE_PROTOBUF_SUBCLASS(ContactAcct,	ContactAcct_InternalPB,		ContactAcctPB,		STORED_OBJ_CONTACT_ACCT);
	DECLARE_PROTOBUF_SUBCLASS(ContactNym,	ContactNym_InternalPB,		ContactNymPB,		STORED_OBJ_CONTACT_NYM);
	DECLARE_PROTOBUF_SUBCLASS(Contact,		Contact_InternalPB,			ContactPB,			STORED_OBJ_CONTACT);
	DECLARE_PROTOBUF_SUBCLASS(AddressBook,	AddressBook_InternalPB,		AddressBookPB,		STORED_OBJ_ADDRESS_BOOK);
	DECLARE_PROTOBUF_SUBCLASS(WalletData,	WalletData_InternalPB,		WalletDataPB,		STORED_OBJ_WALLET_DATA);
	DECLARE_PROTOBUF_SUBCLASS(MarketData,	MarketData_InternalPB,		MarketDataPB,		STORED_OBJ_MARKET_DATA);
	DECLARE_PROTOBUF_SUBCLASS(MarketList,	MarketList_InternalPB,		MarketListPB,		STORED_OBJ_MARKET_LIST);
	
	DECLARE_PROTOBUF_SUBCLASS(BidData,			OfferDataMarket_InternalPB,	BidDataPB,			STORED_OBJ_BID_DATA);
	DECLARE_PROTOBUF_SUBCLASS(AskData,			OfferDataMarket_InternalPB,	AskDataPB,			STORED_OBJ_ASK_DATA);
	DECLARE_PROTOBUF_SUBCLASS(OfferListMarket,	OfferListMarket_InternalPB,	OfferListMarketPB,	STORED_OBJ_OFFER_LIST_MARKET);
	DECLARE_PROTOBUF_SUBCLASS(TradeDataMarket,	TradeDataMarket_InternalPB,	TradeDataMarketPB,	STORED_OBJ_TRADE_DATA_MARKET);
	DECLARE_PROTOBUF_SUBCLASS(TradeListMarket,	TradeListMarket_InternalPB,	TradeListMarketPB,	STORED_OBJ_TRADE_LIST_MARKET);
	DECLARE_PROTOBUF_SUBCLASS(OfferDataNym,		OfferDataNym_InternalPB,	OfferDataNymPB,		STORED_OBJ_OFFER_DATA_NYM);
	DECLARE_PROTOBUF_SUBCLASS(OfferListNym,		OfferListNym_InternalPB,	OfferListNymPB,		STORED_OBJ_OFFER_LIST_NYM);
	DECLARE_PROTOBUF_SUBCLASS(TradeDataNym,		TradeDataNym_InternalPB,	TradeDataNymPB,		STORED_OBJ_TRADE_DATA_NYM);
	DECLARE_PROTOBUF_SUBCLASS(TradeListNym,		TradeListNym_InternalPB,	TradeListNymPB,		STORED_OBJ_TRADE_LIST_NYM);

	typedef OfferDataMarket_InternalPB BidData_InternalPB;
	typedef OfferDataMarket_InternalPB AskData_InternalPB;
	
	// !! ALL OF THESE have to provide implementations for hookBeforePack() and hookAfterUnpack().
	// In .cpp file:
	/*
	 void SUBCLASS_HERE::hookBeforePack()
	 {
	 __pb_obj.set_PROPERTY_NAME_GOES_HERE(PROPERTY_NAME_GOES_HERE); 
	 }
	 void SUBCLASS_HERE::hookAfterUnpack()
	 { 
	 PROPERTY_NAME_GOES_HERE	= __pb_obj.PROPERTY_NAME_GOES_HERE();
	 }
	 */
	
	
	
} // namespace OTDB

#endif // defined(OTDB_PROTOCOL_BUFFERS)
// *******************************************************************************************









#endif // __OT_STORAGE_H__











