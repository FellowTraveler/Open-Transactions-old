


#ifndef __OT_ENTITY_H__
#define __OT_ENTITY_H__

#include "OTOwner.h"

#include "OTIdentifier.h"

#include "OTDepartment.h"

typedef std::map<std::string, OTVotingGroup*> mapOfVotingGroups;


class OTEntity : public OTOwner // will be CONTAINED in an activating smart contract. (Will not DERIVE from OTSmartContract)
{
    // ------------------------------------------
    OTIdentifier      m_entityID;
    // ------------------------------------------
    mapOfVotingGroups m_mapVotingGroups; // These have various ownership rights in the entity. "shareholders", "members", "board" etc.
    mapOfDepartments  m_mapDepartments;  // These have various management powers/duties in the entity. "managers", "officers", etc.
    // ------------------------------------------

public:
    // All of these virtuals are from OTOwner.
// ------------------------------------------
EXPORT	virtual bool CompareID(const OTIdentifier & theIdentifier) const;
EXPORT  virtual bool CompareID(const OTOwner & RHS) const;
// ------------------------------------------
EXPORT	virtual const OTIdentifier & GetConstID() const; // CONST VERSION
// ------------------------------------------	
EXPORT	virtual void GetIdentifier(OTIdentifier & theIdentifier) const;  // BINARY VERSION
EXPORT	virtual void SetIdentifier(const OTIdentifier & theIdentifier);
	
EXPORT	virtual void GetIdentifier(OTString & theIdentifier) const; // STRING VERSION
EXPORT	virtual void SetIdentifier(const OTString & theIdentifier);
// ------------------------------------------
EXPORT  virtual bool LoadSignedFile(OTPseudonym & SIGNER_NYM);
EXPORT  virtual bool SaveSignedFile(OTPseudonym & SIGNER_NYM);
// ------------------------------------------
EXPORT  bool SaveToString(OTString & strEntity);
EXPORT  bool LoadFromString(const OTString & strEntity);
// ------------------------------------------
EXPORT  OTEntity();
EXPORT  OTEntity(const OTIdentifier & theID);
EXPORT	OTEntity(const OTString & strID);
EXPORT  virtual ~OTEntity();
// ------------------------------------------
};




#endif // __OT_ENTITY_H__
