%module(directors="1") otapi
%{
#include <string>
#include <map>
#include "../OTLib/OTAsymmetricKey.h"
#include "OTAPI_funcdef.h"
#include "../OTLib/OTStorage.h"
%}


%include "std_string.i";
%include "typemaps.i"

// ---------------------------------------------------------------
#ifdef SWIGJAVA

%include "java/enumtypeunsafe.swg";

%typemap("javapackage") OTPassword, OTPassword *, OTPassword & "com.wrapper.core.jni";

%typemap("javapackage") OTCallback, OTCallback *, OTCallback & "com.wrapper.core.jni";
%typemap("javapackage") OTCaller, OTCaller *, OTCaller & "com.wrapper.core.jni";

%typemap("javapackage") Storage, Storage *, Storage & "com.wrapper.core.jni";
%typemap("javapackage") Storable, Storable *, Storable & "com.wrapper.core.jni";

%typemap("javapackage") Blob, Blob *, Blob & "com.wrapper.core.jni";
%typemap("javapackage") StringMap, StringMap *, StringMap & "com.wrapper.core.jni";
%typemap("javapackage") BitcoinAcct, BitcoinAcct *, BitcoinAcct & "com.wrapper.core.jni";
%typemap("javapackage") BitcoinServer, BitcoinServer *, BitcoinServer & "com.wrapper.core.jni";
%typemap("javapackage") RippleServer, RippleServer *, RippleServer & "com.wrapper.core.jni";
%typemap("javapackage") LoomServer, LoomServer *, LoomServer & "com.wrapper.core.jni";
%typemap("javapackage") ServerInfo, ServerInfo *, ServerInfo & "com.wrapper.core.jni";
%typemap("javapackage") ContactNym, ContactNym *, ContactNym & "com.wrapper.core.jni";
%typemap("javapackage") ContactAcct, ContactAcct *, ContactAcct & "com.wrapper.core.jni";
%typemap("javapackage") Contact, Contact *, Contact & "com.wrapper.core.jni";
%typemap("javapackage") AddressBook, AddressBook *, AddressBook & "com.wrapper.core.jni";
%typemap("javapackage") WalletData, WalletData *, WalletData & "com.wrapper.core.jni";

%typemap("javapackage") MarketData, MarketData *, MarketData & "com.wrapper.core.jni";
%typemap("javapackage") MarketList, MarketList *, MarketList & "com.wrapper.core.jni";
%typemap("javapackage") OfferDataMarket, OfferDataMarket *, OfferDataMarket & "com.wrapper.core.jni";
%typemap("javapackage") BidData, BidData *, BidData & "com.wrapper.core.jni";
%typemap("javapackage") AskData, AskData *, AskData & "com.wrapper.core.jni";
%typemap("javapackage") OfferListMarket, OfferListMarket *, OfferListMarket & "com.wrapper.core.jni";
%typemap("javapackage") TradeDataMarket, TradeDataMarket *, TradeDataMarket & "com.wrapper.core.jni";
%typemap("javapackage") TradeListMarket, TradeListMarket *, TradeListMarket & "com.wrapper.core.jni";
%typemap("javapackage") OfferDataNym, OfferDataNym *, OfferDataNym & "com.wrapper.core.jni";
%typemap("javapackage") OfferListNym, OfferListNym *, OfferListNym & "com.wrapper.core.jni";
%typemap("javapackage") TradeDataNym, TradeDataNym *, TradeDataNym & "com.wrapper.core.jni";
%typemap("javapackage") TradeListNym, TradeListNym *, TradeListNym & "com.wrapper.core.jni";

%typemap("javapackage") InitDefaultStorage "com.wrapper.core.jni";
%typemap("javapackage") GetDefaultStorage "com.wrapper.core.jni";
%typemap("javapackage") CreateStorageContext "com.wrapper.core.jni";
%typemap("javapackage") CreateObject "com.wrapper.core.jni";
%typemap("javapackage") Exists "com.wrapper.core.jni";
%typemap("javapackage") StoreString "com.wrapper.core.jni";
%typemap("javapackage") QueryString "com.wrapper.core.jni";
%typemap("javapackage") StorePlainString "com.wrapper.core.jni";
%typemap("javapackage") QueryPlainString "com.wrapper.core.jni";
%typemap("javapackage") StoreObject "com.wrapper.core.jni";
%typemap("javapackage") QueryObject "com.wrapper.core.jni";
%typemap("javapackage") EncodeObject "com.wrapper.core.jni";
%typemap("javapackage") DecodeObject "com.wrapper.core.jni";
%typemap("javapackage") EraseValueByKey "com.wrapper.core.jni";

%typemap("javapackage") PackType "com.wrapper.core.jni";
%typemap("javapackage") StorageType "com.wrapper.core.jni";
%typemap("javapackage") StoredObjectType "com.wrapper.core.jni";


// I found this GEM in the Berekeley DB code!
//
%define JAVA_TYPEMAP(_ctype, _jtype, _jnitype)
%typemap(jstype) _ctype #_jtype
%typemap(jtype) _ctype #_jtype
%typemap(jni) _ctype #_jnitype
%typemap(out) _ctype %{ $result = (_jnitype)$1; %}
%typemap(javain) _ctype "$javainput"
%typemap(javaout) _ctype { return $jnicall; }
%enddef

// Uses the above macro.
//
JAVA_TYPEMAP(size_t, long, jlong)

#endif
// ---------------------------------------------------------------

/*
 SAMPLE CODE:
 
 %typemap(jni) time_t "jlong"
 %typemap(jtype) time_t "long"
 %typemap(jstype) time_t "long"
 
 %typemap(out) time_t %{ $result = (jlong)$1; %}
 %typemap(in) time_t "(time_t)$input"
 
 */

%feature("director") OTCallback;


//%typemap(javain) std::string & SBUF "$javainput"



// The Callback definitions here, must appear BELOW the above SWIG directives that apply to them.
// The actual HEADER these definitions come from (OTStorage.h) must be included ABOVE THAT so that
// the SWIG directives will know what the hell we are talking about. Then those directives are actually
// applied here.
// Even below this section, you will see MORE SWIG directives, and then the definitions below those
// that THEY apply to.
//


%include "../OTLib/OTPassword.h"



bool OT_API_Set_PasswordCallback(OTCaller & theCaller);



//%apply int *INPUT {int *x, int *y};
//%apply SWIGTYPE *INPUT {int *x, int *y};

%ignore clone;

%ignore Storable::Create(StoredObjectType eType, PackType thePackType);

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

// -------------------------------------------

// So there aren't memory leaks from passing the objects back and forth.

//%apply SWIGTYPE & DISOWN { SWIGTYPE & disownObject };

// //
//%apply SWIGTYPE * DISOWN {wxCaret* caret};

//DEFAULT REFERENCE HANDLING
//%typemap(in) SWIGTYPE & { ... default reference handling ...};

//%typemap(in) SWIGTYPE & DISOWN { SWIGTYPE & disownObject };
//
//%typemap(in) SWIGTYPE *DISOWN { BitcoinAcct & disownObject };
//
//%typemap(in) SWIGTYPE *DISOWN { BitcoinServer & disownObject };
//
//%typemap(in) SWIGTYPE *DISOWN { RippleServer & disownObject };
//
//%typemap(in) SWIGTYPE *DISOWN { LoomServer & disownObject };
//
//%typemap(in) SWIGTYPE *DISOWN { ServerInfo & disownObject };
//
//%typemap(in) SWIGTYPE *DISOWN { ContactNym & disownObject };
//
//%typemap(in) SWIGTYPE *DISOWN { ContactAcct & disownObject };
//
//%typemap(in) SWIGTYPE *DISOWN { Contact & disownObject };


 
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

// ----------------------------------------------------

// Use this inside the class definition itself, farther down below.
// (Wherever you want to have a list of elements inside a container.)
//
%define OT_SWIG_DECLARE_GET_ADD_REMOVE(name)
	protected:
	std::deque< stlplus::simple_ptr_clone<name> > list_##name##s;
public:
	size_t Get##name##Count();
	name * Get##name(size_t nIndex);
	bool Remove##name(size_t nIndex##name);
	bool Add##name(name & disownObject)	
%enddef

// Use this inside the class definition itself, farther down below.
//
%define DEFINE_OT_SWIG_DYNAMIC_CAST(CLASS_NAME_A)
	CLASS_NAME_A * clone () const { return NULL; std::cerr << "********* THIS SHOULD NEVER HAPPEN!!!!! *****************" << std::endl;}
	static CLASS_NAME_A *		ot_dynamic_cast(		Storable *pObject) { return dynamic_cast<CLASS_NAME_A *>(pObject); }
//	static const CLASS_NAME_A*	ot_dynamic_cast(const	Storable *pObject) { return dynamic_cast<const CLASS_NAME_A *>(pObject); }
%enddef



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

/*%exception STORABLE_TYPE::dynamic_cast(Storable * pObject) {  // Java code
	$action
	if (!$result) {
		jclass excep = jenv->FindClass("java/lang/ClassCastException");
		if (excep) {
			jenv->ThrowNew(excep, "dynamic_cast exception");
		}
	}
}
*/
 

/*
%typemap(out) Storable * OT_SWIG_DYNAMIC_CAST {
    STORABLE_TYPE *downcast = dynamic_cast<STORABLE_TYPE *>($1);
    *(STORABLE_TYPE **)&$result = downcast;
}

%typemap(javaout) Storable * OT_DYNAMIC_CAST {
    return new STORABLE_TYPE($jnicall, $owner);
}
*/
// Todo: add mapping to Java destruct process, so that when the proxy
// goes out of scope, it is smart enough to remove itself from the reference list.
// Why is it being added in the first place? Because it is pointing to a certain
// object -- therefore according to Java it should have a reference to that object.
// Otherwise it will end up pointing to bad memory, when that object gets cleaned
// up by the garbage collector (who THOUGHT no one was referencing it.)
//



// -------------------------------------------------------------------------------

// This code is now added in the classes themselves, since it's presumed useful.

%define OT_AFTER_STORABLE_TYPE(STORABLE_TYPE_B) // C++ CODE
//%extend OTDB::STORABLE_TYPE_B {
//	static STORABLE_TYPE_B * dynamic_cast(Storable * pObject) {  // C++ CODE
//		return dynamic_cast<STORABLE_TYPE_B *>(pObject);
//	}
//}
%enddef




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





#ifdef SWIGJAVA
//
// ------------------------------------------------------------

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
#endif






// ------------------------------------------------


/* Parse the header file to generate wrappers */
%include "OTAPI_funcdef.h"



namespace OTDB { 
	
	
	
	enum PackType // PACKING TYPE
	{
		PACK_MESSAGE_PACK = 0,	// Using MessagePack as packer.
		PACK_PROTOCOL_BUFFERS,	// Using Google Protocol Buffers as packer.
		PACK_TYPE_ERROR		// (Should never be.)
	};
	
	enum StorageType  // STORAGE TYPE
	{
		STORE_FILESYSTEM = 0,	// Filesystem
//		STORE_COUCH_DB,			// Couch DB (not yet supported)
		STORE_TYPE_SUBCLASS		// (Subclass provided by API client via SWIG.)
	};
	
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
	
	// ----------------------------------------------------
	
	// Since Storable is the common base for the "pure data" hierarchy,
	// IStorable serves as the common base for the Packing infrastructure.
	// There are subclasses for the various packers (IStorableMsgpack, IStorablePB, etc)
	// Although external users of this will only see, for example, a "WalletData" object,
	// They are actually using, behind the scenes, a WalletDataPB object, which subclasses
	// WalletData, AND implements IStorablePB.
	// The API user doesn't care about all this -- it happens behind the scenes automatically
	// based on whatever storage/packer system is chosen. He just knows that he wants to
	// Store or Query a WalletData, and no more.
	
	class IStorable; // This forward declaration is all we see of this implementation detail
	// -------------------------------
	
	class Storable // <===== Storable is the actual interface that coders using the OT API will care about.
	{
		friend class Storage; // for instantiation of storable objects by their storage context.
		
	protected:
		Storable() { m_Type = "Storable"; }
		
		std::string m_Type;
	public:
		virtual ~Storable() {}
		
		// %ignore spam(unsigned short); API users don't need this function, it's for internal purposes.
		static Storable * Create(StoredObjectType eType, PackType thePackType);
		
		DEFINE_OT_SWIG_DYNAMIC_CAST(Storable)
	};
	
	// -------------------------------------------------------
	
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
		// it's done, see StorageFS (filesystem), which is included in OTStorage.cpp and .h
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
		// This way, whenever using an OT Storage, you KNOW the packer is always the right
		// one, and that you don't have to fiddle with it at all. You can also therefore use
		// it for creating instances of various Storables and PackedBuffers, and knowing
		// that the right types will be instantiated, with the buffer being the appropriate
		// subclass for the packer.
		//
		OTPacker * GetPacker(PackType ePackType=OTDB_DEFAULT_PACKER);
	
		virtual bool Init(std::string oneStr="", std::string twoStr="", std::string threeStr="", 
						  std::string fourStr="", std::string fiveStr="", std::string sixStr="")=0;
		
		// -----------------------------------------
		// See if the file is there.
		virtual bool Exists(std::string strFolder, 
							std::string oneStr="", std::string twoStr="", std::string threeStr="")=0;
		
		// ********************************************************

		virtual ~Storage() { if (NULL != m_pPacker) delete m_pPacker;  m_pPacker = NULL; }

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
		
		// Use %newobject Storage::Query();
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
		// a namespace-level function.)
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
	
	// bool bSuccess = StoreString(strInbox, "inbox", "lkjsdf908w345ljkvd");
	// bool bSuccess = StoreString(strMint,  "mints", SERVER_ID, ASSET_ID);
	// bool bSuccess = StoreString(strPurse, "purse", SERVER_ID, USER_ID, ASSET_ID);
	
	// BELOW FUNCTIONS will use the DEFAULT Storage context for the OTDB Namespace
	// (If you don't want to specifically create and manage a context, then you just
	// use the default context, which the rest of the OT library will also use.)
	//
	// --------
	// Let's see if the file is there...
	//
	bool Exists(std::string strFolder, 
				std::string oneStr="", std::string twoStr="", std::string threeStr="");
	
	// --------
	// Store/Retrieve a string. (Packing it first.)
	//
	bool StoreString(std::string strContents, std::string strFolder, 
					 std::string oneStr="", std::string twoStr="", std::string threeStr="");
	
	std::string QueryString(std::string strFolder, std::string oneStr="",
							std::string twoStr="", std::string threeStr="");
	
	// ---------------------------------
	// Store/Retrieve a plain string (no packing--the plain string goes directly to storage.)
	// Many existing OT datafiles are this way, so this function is used a lot in the OT lib.
	//
	bool StorePlainString(std::string strContents, std::string strFolder, 
						  std::string oneStr="", std::string twoStr="", std::string threeStr="");
	
	std::string QueryPlainString(std::string strFolder, std::string oneStr="",
								 std::string twoStr="", std::string threeStr="");
	
	// --------
	// Store/Retrieve an object. (Storable.)
	//
	bool StoreObject(Storable & theContents, std::string strFolder, 
					 std::string oneStr="", std::string twoStr="", std::string threeStr="");
	
	// Use %newobject Storage::Query();
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

	// ------------------------------------------------
	
	
	
	
	
	class OTDBString : public Storable
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through the factory.
	protected:
		OTDBString() : Storable() { m_Type = "OTDBString"; }
		OTDBString(const std::string& rhs) : Storable(), m_string(rhs) { m_Type = "OTDBString"; }
		
	public:
		virtual ~OTDBString() { }
		
		std::string m_string;
	
		DEFINE_OT_SWIG_DYNAMIC_CAST(OTDBString)
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
		
		DEFINE_OT_SWIG_DYNAMIC_CAST(Blob)
	};
	
	// ------------------------------------------------
	
	class StringMap : public Storable
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		StringMap() : Storable() { m_Type = "StringMap"; }
		
	public:
		virtual ~StringMap() { }
		
		std::map<std::string, std::string> the_map;  // all strings, key/value pairs.
		
		void SetValue(const std::string& strKey, const std::string& strValue)
		{ the_map[strKey] = strValue; }
		
		std::string GetValue(const std::string& strKey)
		{ std::string ret_val(""); std::map<std::string, std::string>::iterator ii = the_map.find(strKey);
			if (ii != the_map.end()) ret_val = (*ii).second; return ret_val; }
		
		DEFINE_OT_SWIG_DYNAMIC_CAST(StringMap)
	};
	
	
	// ------------------------------------------------
	
	class Displayable : public Storable
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		Displayable() : Storable() { m_Type = "Displayable"; }
		
	public:
		virtual ~Displayable() { }
		
		std::string gui_label;  // The label that appears in the GUI
		
		DEFINE_OT_SWIG_DYNAMIC_CAST(Displayable)
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
		
		DEFINE_OT_SWIG_DYNAMIC_CAST(MarketData)
	};
    
	// ------------------------------------------------------
    
	class MarketList : public Storable {
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		MarketList() : Storable() { m_Type = "MarketList"; }
		
	public:
		virtual ~MarketList() {}
		
		OT_SWIG_DECLARE_GET_ADD_REMOVE(MarketData);
		
		DEFINE_OT_SWIG_DYNAMIC_CAST(MarketList)
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
		
		DEFINE_OT_SWIG_DYNAMIC_CAST(OfferDataMarket)
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
		
		DEFINE_OT_SWIG_DYNAMIC_CAST(BidData)
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
		
		DEFINE_OT_SWIG_DYNAMIC_CAST(AskData)
	};
    
	// ------------------------------------------------------
    
	class OfferListMarket : public Storable {
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		OfferListMarket() : Storable() { m_Type = "OfferListMarket"; }
		
	public:
		virtual ~OfferListMarket() {}
		
		OT_SWIG_DECLARE_GET_ADD_REMOVE(BidData);
		OT_SWIG_DECLARE_GET_ADD_REMOVE(AskData);
		
		DEFINE_OT_SWIG_DYNAMIC_CAST(OfferListMarket)
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
		
		DEFINE_OT_SWIG_DYNAMIC_CAST(TradeDataMarket)
	};
	
	// ------------------------------------------------------
	
	class TradeListMarket : public Storable {
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		TradeListMarket() : Storable() { m_Type = "TradeListMarket"; }
		
	public:
		virtual ~TradeListMarket() {}
		
		OT_SWIG_DECLARE_GET_ADD_REMOVE(TradeDataMarket);
		
		DEFINE_OT_SWIG_DYNAMIC_CAST(TradeListMarket)
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
		
		DEFINE_OT_SWIG_DYNAMIC_CAST(OfferDataNym)
	};
    
	// ------------------------------------------------------
	
	class OfferListNym : public Storable {
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		OfferListNym() : Storable() { m_Type = "OfferListNym"; }
		
	public:
		virtual ~OfferListNym() {}
		
		OT_SWIG_DECLARE_GET_ADD_REMOVE(OfferDataNym);
		
		DEFINE_OT_SWIG_DYNAMIC_CAST(OfferListNym)
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
		
		DEFINE_OT_SWIG_DYNAMIC_CAST(TradeDataNym)
	};
	
	// ------------------------------------------------------
	
	class TradeListNym : public Storable {
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		TradeListNym() : Storable() { m_Type = "TradeListNym"; }
		
	public:
		virtual ~TradeListNym() {}
		
		OT_SWIG_DECLARE_GET_ADD_REMOVE(TradeDataNym);
		
		DEFINE_OT_SWIG_DYNAMIC_CAST(TradeListNym)
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
		
		DEFINE_OT_SWIG_DYNAMIC_CAST(Acct)
	};
	
	// ----------------------------
	
	class BitcoinAcct : public Acct
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		BitcoinAcct() : Acct() {  m_Type = "BitcoinAcct";  }
		
	public:
		virtual ~BitcoinAcct() {  }
		
		using Displayable::gui_label;  // The label that appears in the GUI
		
		using Acct::acct_id;
		using Acct::server_id;
		
		std::string bitcoin_acct_name;
				
		DEFINE_OT_SWIG_DYNAMIC_CAST(BitcoinAcct)
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
				
		DEFINE_OT_SWIG_DYNAMIC_CAST(ServerInfo)
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
		
		DEFINE_OT_SWIG_DYNAMIC_CAST(Server)
	};
	
	// ----------------------------
	
	class BitcoinServer : public Server
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		BitcoinServer() : Server() {  m_Type = "BitcoinServer"; }
		
	public:
		virtual ~BitcoinServer() {  }
		
		using Displayable::gui_label;  // The label that appears in the GUI
		
		using ServerInfo::server_id;   // in base class
		using ServerInfo::server_type; // in base class
		
		using Server::server_host;   // in base class
		using Server::server_port; // in base class
		
		std::string bitcoin_username;
		std::string bitcoin_password;
				
		DEFINE_OT_SWIG_DYNAMIC_CAST(BitcoinServer)
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
		
		DEFINE_OT_SWIG_DYNAMIC_CAST(RippleServer)
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
		
		DEFINE_OT_SWIG_DYNAMIC_CAST(LoomServer)
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
		
		OT_SWIG_DECLARE_GET_ADD_REMOVE(ServerInfo);
				
		DEFINE_OT_SWIG_DYNAMIC_CAST(ContactNym)
	};
	
	
	// ------------------------------------------------
	
	class WalletData : public Storable
	{
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		WalletData() : Storable() { m_Type = "WalletData"; }
		
	public:
		virtual ~WalletData() {  }
		
		// List of Bitcoin servers
		// List of Bitcoin accounts
		// Loom, etc.
		
		OT_SWIG_DECLARE_GET_ADD_REMOVE(BitcoinServer);
		OT_SWIG_DECLARE_GET_ADD_REMOVE(BitcoinAcct);
		OT_SWIG_DECLARE_GET_ADD_REMOVE(RippleServer);
		OT_SWIG_DECLARE_GET_ADD_REMOVE(LoomServer);
		
		DEFINE_OT_SWIG_DYNAMIC_CAST(WalletData)
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
				
		DEFINE_OT_SWIG_DYNAMIC_CAST(ContactAcct)
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
		
		OT_SWIG_DECLARE_GET_ADD_REMOVE(ContactNym);
		OT_SWIG_DECLARE_GET_ADD_REMOVE(ContactAcct);
		
		DEFINE_OT_SWIG_DYNAMIC_CAST(Contact)
	};
	
	// ----------------------------
	
	class AddressBook : public Storable {
		// You never actually get an instance of this, only its subclasses.
		// Therefore, I don't allow you to access the constructor except through factory.
	protected:
		AddressBook() : Storable() { m_Type = "AddressBook"; }
		
	public:
		virtual ~AddressBook();
		
		OT_SWIG_DECLARE_GET_ADD_REMOVE(Contact);
		
		DEFINE_OT_SWIG_DYNAMIC_CAST(AddressBook)
	};
	
	// ----------------------------

} // namespace OTDB 





%feature("director") OTDB::Storage;




%inline %{
	using namespace OTDB;
	%}



// These have to go AFTER the class definitions.
//
/* UNUSED
 
OT_AFTER_STORABLE_TYPE(OTDBString)
OT_AFTER_STORABLE_TYPE(Blob)
OT_AFTER_STORABLE_TYPE(StringMap)
OT_AFTER_STORABLE_TYPE(BitcoinAcct)

OT_AFTER_STORABLE_TYPE(ServerInfo)

OT_AFTER_STORABLE_TYPE(BitcoinServer)
OT_AFTER_STORABLE_TYPE(RippleServer)
OT_AFTER_STORABLE_TYPE(LoomServer)
OT_AFTER_STORABLE_TYPE(ContactNym)
OT_AFTER_STORABLE_TYPE(ContactAcct)
OT_AFTER_STORABLE_TYPE(WalletData)

OT_AFTER_STORABLE_TYPE(Contact)

OT_AFTER_STORABLE_TYPE(AddressBook)
*/





