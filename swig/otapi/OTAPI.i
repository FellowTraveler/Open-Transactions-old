%module(directors="1") otapi
%{
#include <string>
#include <map>
#include "../../include/otlib/OTAsymmetricKey.h"
#include "../../include/otapi/OTAPI_Basic.h"
#include "../../include/otapi/OTMadeEasy.h"
#include "../../include/otlib/OTStorage.h"
%}


%include "std_string.i";
%include "typemaps.i"



// -----------------------------------------------------------
// -----------------------------------------------------------
// -----------------------------------------------------------
// JAVA


// ---------------------------------------------------------------
#ifdef SWIGJAVA

// this is generaly not a good thing to include (typesafe enums are good), however I need to investigate more if we can safely remove it.
// the main benifit from including this directive is that enums can be used in a switch statement, (however in later java I think that this is no-longer an issue).
%include "java/enumtypeunsafe.swg";

//
// ------------------------------------------------------------
// Put this: inside the %typemap (javacode) for the class that you want to have equals().
//
/*
%define OT_SUPPORT_EQUALS
#ifdef SWIGJAVA
public boolean equals(Object obj) {
    boolean equal = false;
    if (obj instanceof $javaclassname)
		equal = ((($javaclassname)obj).swigCPtr == this.swigCPtr);  // Look at this cast! I am using polymorphism, I can't cast like this....
    return equal;
}
public int hashCode() {
	return (int)getPointer();
}
#endif
%enddef
*/

// -------------------------------------------------------------------------------
// Put a list of these ABOVE the class definitions below.
// ALL objects, containers AND elements, are OT Storable objects.
//
// These two blocks enable the object to dynamic cast back
// to its true type, after factory construction.
//
// TODO: Fix this since "this" doesn't work at static level.
// (Anyway, doesn't it already have a pointer to its container?)
%define OT_BEFORE_STORABLE_TYPE(STORABLE_TYPE_A)
//%typemap(javaout) STORABLE_TYPE_A * ot_dynamic_cast { 
//    long cPtr = $jnicall; 
//    $javaclassname ret = null; 
//    if (cPtr != 0) { 
//		ret = new $javaclassname(cPtr, $owner);
//		ret.addReference(this); 
//    } 
//    return ret; 
//}
%enddef

// Todo: add mapping to Java destruct process, so that when the proxy
// goes out of scope, it is smart enough to remove itself from the reference list.
// Why is it being added in the first place? Because it is pointing to a certain
// object -- therefore according to Java it should have a reference to that object.
// Otherwise it will end up pointing to bad memory, when that object gets cleaned
// up by the garbage collector (who THOUGHT no one was referencing it.)
//
// -------------------------------------------------------------------------------

// Put this: inside the %typemap(javacode) for the CONTAINER_TYPE (near the top of it.)
//
// Any container stores a list of references to its elements,
// where a reference is added each time you use the "Add" method, so
// that none of its elements are erased out from under it by the Java Garbage Collector.
//
%define OT_CONTAINER_TYPE_MEMBERS 
	private List elementList = new ArrayList();
%enddef

// ----------------------------
// If a class is meant to be used as an element inside a container, then use this
// macro to create the necessary typemap for that class's GET method.
//
// Put it: With the rest of the TYPEMAP for the class in question. (Above the class 
// definition itself, and above the container typemaps.)
//
// Swig uses it: Any container that defines a get method for that class based on
// the signature below: THE_ELEMENT_TYPE * Get##THE_ELEMENT_TYPE
//
%define OT_IS_ELEMENT_TYPE(THE_ELEMENT_TYPE_A)
// When the CONTAINER_TYPE's "Get" function is called, this will add a Java
// reference to prevent premature garbage collection and resulting use
// of dangling C++ pointer. Intended for methods that return pointers or
// references to a member variable.
%typemap(javaout,noblock=1) THE_ELEMENT_TYPE_A * Get##THE_ELEMENT_TYPE_A {
    long cPtr = $jnicall;
    $javaclassname ret = null;
    if (cPtr != 0) {
		ret = new $javaclassname(cPtr, $owner);
		ret.addReference(this);
    }
    return ret;
}
// ----
// Swig uses this in every CONTAINER_TYPE's "Add" function, which all
// have a parameter profile matching this typemap.
//
%typemap(javain,noblock=1) THE_ELEMENT_TYPE_A & disownObject { getCPtrAddRef##THE_ELEMENT_TYPE_A($javainput) }

// This is used by CONTAINER_TYPE's "Remove" function. Do not change the
// parameter name nIndex##name or this typemap will stop working...
%typemap(javain,noblock=1) size_t nIndex##THE_ELEMENT_TYPE_A { removeRef##THE_ELEMENT_TYPE_A($javainput) }

%enddef
// ----------------------------------------------------------------------------------


// The STORABLE_TYPE (BitcoinAcct, say) keeps a reference to its CONTAINER_TYPE (WalletData).
//
// Put it: inside the %typemap(javacode) for the ELEMENT_TYPE, for EACH possible container type.
//
%define OT_CAN_BE_CONTAINED_BY(CONTAINER_TYPE_A)
	// Ensure that the GC doesn't collect any OT_CONTAINER instance set from Java
	private CONTAINER_TYPE_A containerRef##CONTAINER_TYPE_A;
	// ----------------	
	protected void addReference(CONTAINER_TYPE_A theContainer) {  // This is Java code
		containerRef##CONTAINER_TYPE_A = theContainer;
	}
	// ----------------
%enddef

// -------------------------------------------------------------------------------

// You might wonder, why did I use THE_ELEMENT_TYPE_A and then THE_ELEMENT_TYPE_B,
// etc?  Because I didn't want to risk one define somehow overlapping another and
// substituting the wrong name because they both happened to use the same token
// for substitution. Therefore I made sure they all had different token naming.
// (FYI.)


// The CONTAINER_TYPE (WalletData) uses this for *EACH* Get/Add/Remove item within.
// So this macro appears multiple times, if there are multiple deques. (Like a contact
// has nyms AND accounts inside of it.)
//
// Put it: inside the %typemap(javacode) for the CONTAINER_TYPE, for EACH ELEMENT_TYPE.
//
// Ensure that the GC doesn't collect any THE_ELEMENT_TYPE set from Java
// as the underlying C++ class stores a shallow copy

// Altered the SWIG example so that we store a list of these references, instead
// of only the latest one. (None of them should go out of scope until this object does.)

%define OT_ADD_ELEMENT(THE_ELEMENT_TYPE_B)  // THIS BLOCK CONTAINS JAVA CODE.
private long removeRef##THE_ELEMENT_TYPE_B(long lIndex) {
	// 
	// loop through the elements in the actual container, in order to find the one
	// at lIndex. Once it is found, then loop through the reference list and remove
	// the corresponding reference for that element.
	//
	THE_ELEMENT_TYPE_B refActualElement = Get##THE_ELEMENT_TYPE_B(lIndex);

	if (refActualElement == null)
		return lIndex; // oh well.
	
	// Loop through the reference list and remove the corresponding reference
	// for the specified element.
	//
	for(int intIndex = 0; intIndex < elementList.size(); intIndex++)
	{
		Object theObject = elementList.get(intIndex);
		
		if ((theObject == null) || !(theObject instanceof THE_ELEMENT_TYPE_B))
			continue;

		THE_ELEMENT_TYPE_B tempRef = (THE_ELEMENT_TYPE_B)(theObject);
		
		if ((THE_ELEMENT_TYPE_B.getCPtr(tempRef) == THE_ELEMENT_TYPE_B.getCPtr(refActualElement)))
		{
			elementList.remove(tempRef);
			break;
		}
	}
	
	return lIndex;
}

private long getCPtrAddRef##THE_ELEMENT_TYPE_B(THE_ELEMENT_TYPE_B element) {
	// Whenever adding a reference to the list, I remove it first (if already there.)
	// That way we never store more than one reference per actual contained object.
	//
	for(int intIndex = 0; intIndex < elementList.size(); intIndex++)
	{
		Object theObject = elementList.get(intIndex);

		if ((theObject == null) || !(theObject instanceof THE_ELEMENT_TYPE_B))
			continue;
		
		THE_ELEMENT_TYPE_B tempRef = (THE_ELEMENT_TYPE_B)(theObject);
		
		if ((THE_ELEMENT_TYPE_B.getCPtr(tempRef) == THE_ELEMENT_TYPE_B.getCPtr(element)))
		{
			elementList.remove(tempRef); // It was already there, so let's remove it before adding (below.)
			break;
		}
	}
	// Now we add it...
	//
	THE_ELEMENT_TYPE_B tempLocalRef = element;
	elementList.add(tempLocalRef);
	return THE_ELEMENT_TYPE_B.getCPtr(element);
}	// Hope I get away with overloading this for every type. Otherwise,
%enddef
// hope I can just change the function name to customize it to type.

// ----------------------------------------


OT_BEFORE_STORABLE_TYPE(OTDB::OTDBString)
OT_IS_ELEMENT_TYPE(OTDBString)

%typemap(javacode,noblock=1) OTDB::OTDBString {
	// ------------------------
}

// *******************************


OT_BEFORE_STORABLE_TYPE(OTDB::Blob)
OT_IS_ELEMENT_TYPE(Blob)

%typemap(javacode,noblock=1) OTDB::Blob {
	// ------------------------
}

// *******************************

OT_BEFORE_STORABLE_TYPE(OTDB::StringMap)
OT_IS_ELEMENT_TYPE(StringMap)

%typemap(javacode,noblock=1) OTDB::StringMap {
	// ------------------------
}

// *******************************

OT_BEFORE_STORABLE_TYPE(OTDB::BitcoinAcct)
OT_IS_ELEMENT_TYPE(BitcoinAcct)

%typemap(javacode,noblock=1) OTDB::BitcoinAcct {
	OT_CAN_BE_CONTAINED_BY(WalletData)
	// ------------------------
}

// *******************************


OT_BEFORE_STORABLE_TYPE(OTDB::ServerInfo)
OT_IS_ELEMENT_TYPE(ServerInfo)

%typemap(javacode,noblock=1) OTDB::ServerInfo {
	OT_CAN_BE_CONTAINED_BY(ContactNym)
	// ------------------------
}

// *******************************

OT_BEFORE_STORABLE_TYPE(OTDB::BitcoinServer)
OT_IS_ELEMENT_TYPE(BitcoinServer)

%typemap(javacode,noblock=1) OTDB::BitcoinServer {
	OT_CAN_BE_CONTAINED_BY(WalletData)
	// ------------------------
}

// *******************************

OT_BEFORE_STORABLE_TYPE(OTDB::RippleServer)
OT_IS_ELEMENT_TYPE(RippleServer)

%typemap(javacode,noblock=1) OTDB::RippleServer {
	OT_CAN_BE_CONTAINED_BY(WalletData)
	// ------------------------
}

// *******************************

OT_BEFORE_STORABLE_TYPE(OTDB::LoomServer)
OT_IS_ELEMENT_TYPE(LoomServer)

%typemap(javacode,noblock=1) OTDB::LoomServer {
	OT_CAN_BE_CONTAINED_BY(WalletData)
	// ------------------------
}

// *******************************

OT_BEFORE_STORABLE_TYPE(OTDB::ContactNym)
OT_IS_ELEMENT_TYPE(ContactNym)

%typemap(javacode,noblock=1) OTDB::ContactNym {
	OT_CAN_BE_CONTAINED_BY(Contact)
	// ------------------------
	OT_CONTAINER_TYPE_MEMBERS
	OT_ADD_ELEMENT(ServerInfo)
}

// *******************************

OT_BEFORE_STORABLE_TYPE(OTDB::ContactAcct)
OT_IS_ELEMENT_TYPE(ContactAcct)

%typemap(javacode,noblock=1) OTDB::ContactAcct {
	OT_CAN_BE_CONTAINED_BY(Contact)
	// ------------------------
}

// *******************************

OT_BEFORE_STORABLE_TYPE(OTDB::WalletData)
OT_IS_ELEMENT_TYPE(WalletData)

%typemap(javacode,noblock=1) OTDB::WalletData {
	// ------------------------
	OT_CONTAINER_TYPE_MEMBERS
	OT_ADD_ELEMENT(BitcoinServer)
	OT_ADD_ELEMENT(BitcoinAcct)
	OT_ADD_ELEMENT(RippleServer)
	OT_ADD_ELEMENT(LoomServer)
}

// *******************************

OT_BEFORE_STORABLE_TYPE(OTDB::Contact)
OT_IS_ELEMENT_TYPE(Contact)

%typemap(javacode,noblock=1) OTDB::Contact {
	OT_CAN_BE_CONTAINED_BY(AddressBook)
	// ------------------------
	OT_CONTAINER_TYPE_MEMBERS
	OT_ADD_ELEMENT(ContactNym)
	OT_ADD_ELEMENT(ContactAcct)
}

// *******************************

OT_BEFORE_STORABLE_TYPE(OTDB::AddressBook)
OT_IS_ELEMENT_TYPE(AddressBook)

%typemap(javacode,noblock=1) OTDB::AddressBook {
	// ------------------------
	OT_CONTAINER_TYPE_MEMBERS
	OT_ADD_ELEMENT(Contact)
}

// *******************************

OT_BEFORE_STORABLE_TYPE(OTDB::MarketData)
OT_IS_ELEMENT_TYPE(MarketData)

%typemap(javacode,noblock=1) OTDB::MarketData {
	OT_CAN_BE_CONTAINED_BY(MarketList)
	// ------------------------
}

// *******************************

OT_BEFORE_STORABLE_TYPE(OTDB::MarketList)
OT_IS_ELEMENT_TYPE(MarketList)

%typemap(javacode,noblock=1) OTDB::MarketList {
	// ------------------------
	OT_CONTAINER_TYPE_MEMBERS
	OT_ADD_ELEMENT(MarketData)
}

// *******************************

OT_BEFORE_STORABLE_TYPE(OTDB::BidData)
OT_IS_ELEMENT_TYPE(BidData)

%typemap(javacode,noblock=1) OTDB::BidData {
	OT_CAN_BE_CONTAINED_BY(OfferListMarket)
	// ------------------------
}

// *******************************


OT_BEFORE_STORABLE_TYPE(OTDB::AskData)
OT_IS_ELEMENT_TYPE(AskData)

%typemap(javacode,noblock=1) OTDB::AskData {
	OT_CAN_BE_CONTAINED_BY(OfferListMarket)
	// ------------------------
}

// *******************************

OT_BEFORE_STORABLE_TYPE(OTDB::OfferListMarket)
OT_IS_ELEMENT_TYPE(OfferListMarket)

%typemap(javacode,noblock=1) OTDB::OfferListMarket {
	// ------------------------
	OT_CONTAINER_TYPE_MEMBERS
	OT_ADD_ELEMENT(BidData)
	OT_ADD_ELEMENT(AskData)
}


// *******************************

OT_BEFORE_STORABLE_TYPE(OTDB::TradeDataMarket)
OT_IS_ELEMENT_TYPE(TradeDataMarket)

%typemap(javacode,noblock=1) OTDB::TradeDataMarket {
	OT_CAN_BE_CONTAINED_BY(TradeListMarket)
	// ------------------------
}

// *******************************

OT_BEFORE_STORABLE_TYPE(OTDB::TradeListMarket)
OT_IS_ELEMENT_TYPE(TradeListMarket)

%typemap(javacode,noblock=1) OTDB::TradeListMarket {
	// ------------------------
	OT_CONTAINER_TYPE_MEMBERS
	OT_ADD_ELEMENT(TradeDataMarket)
}


// *******************************

OT_BEFORE_STORABLE_TYPE(OTDB::OfferDataNym)
OT_IS_ELEMENT_TYPE(OfferDataNym)

%typemap(javacode,noblock=1) OTDB::OfferDataNym {
	OT_CAN_BE_CONTAINED_BY(OfferListNym)
	// ------------------------
}

// *******************************

OT_BEFORE_STORABLE_TYPE(OTDB::OfferListNym)
OT_IS_ELEMENT_TYPE(OfferListNym)

%typemap(javacode,noblock=1) OTDB::OfferListNym {
	// ------------------------
	OT_CONTAINER_TYPE_MEMBERS
	OT_ADD_ELEMENT(OfferDataNym)
}

// *******************************

OT_BEFORE_STORABLE_TYPE(OTDB::TradeDataNym)
OT_IS_ELEMENT_TYPE(TradeDataNym)

%typemap(javacode,noblock=1) OTDB::TradeDataNym {
	OT_CAN_BE_CONTAINED_BY(TradeListNym)
	// ------------------------
}

// *******************************

OT_BEFORE_STORABLE_TYPE(OTDB::TradeListNym)
OT_IS_ELEMENT_TYPE(TradeListNym)

%typemap(javacode,noblock=1) OTDB::TradeListNym {
	// ------------------------
	OT_CONTAINER_TYPE_MEMBERS
	OT_ADD_ELEMENT(TradeDataNym)
}

// ------------------------------------------------------------
#endif  // SWIGJAVA





// -----------------------------------------------------------
// -----------------------------------------------------------
// -----------------------------------------------------------
// ALL


 // NOTE: these are supposed to be here, so that the Java garbage collector
 // can clean up any memory it's finished with (from OT.)
 //
 // SWIG people: PLEASE update your documentation a bit. I've had to figure out
 // this crap through trial-and-error. I thought SWIG was supposed to make things easier?
 // If newobject is support, then delobject should be supported to. Especially for JAVA,
 // of all languages!! Also, if I have the custom code handlers for Java, Python, etc then
 // why have SWIG at all?


%newobject CreateObject(StoredObjectType eType);
%newobject QueryObject(StoredObjectType theObjectType, std::string strFolder, std::string oneStr="", std::string twoStr="", std::string threeStr="");
%newobject DecodeObject(StoredObjectType theObjectType, std::string strInput);
%newobject Storage::QueryObject(StoredObjectType theObjectType, std::string strFolder, std::string oneStr="", std::string twoStr="", std::string threeStr="");
%newobject Storage::DecodeObject(StoredObjectType theObjectType, std::string strInput);
%newobject Storage::CreateObject(StoredObjectType eType);
%newobject CreateStorageContext(StorageType eStoreType, PackType ePackType=OTDB_DEFAULT_PACKER);


%ignore OTPassword::operator=(const OTPassword & rhs);
%ignore OTPasswordData;
%ignore clone;
%ignore Storable::Create(StoredObjectType eType, PackType thePackType);
%ignore OTPasswordData;
%ignore PackedBuffer;
%ignore OTPacker;
%ignore PackerSubclass;
%ignore Storage::Create(StorageType eStorageType, PackType ePackType);
%ignore stat;
%ignore std::istream;
%ignore std::ostream;
%ignore msgpack::sbuffer;
%ignore std::map<std::string, std::string>;
%ignore stlplus::simple_ptr_clone;


// The Callback definitions here, must appear BELOW the above SWIG directives that apply to them.
// The actual HEADER these definitions come from (OTStorage.h) must be included ABOVE THAT so that
// the SWIG directives will know what the hell we are talking about. Then those directives are actually
// applied here.
// Even below this section, you will see MORE SWIG directives, and then the definitions below those
// that THEY apply to.
//
%feature("director") OTCallback;


// -----------------------------------------------------------
// -----------------------------------------------------------
// -----------------------------------------------------------
// INCLUDE FILES


/* Parse the header file to generate wrappers */

%include "../../include/otlib/OTPassword.h"
%include "../../include/otapi/OTAPI_Basic.h"
%include "../../include/otapi/OTMadeEasy.h"
%include "../../include/otlib/OTStorage.h"


bool OT_API_Set_PasswordCallback(OTCaller & theCaller);


// add the follwing to every .cxx file.
%inline %{
	using namespace OTDB;
	%}

