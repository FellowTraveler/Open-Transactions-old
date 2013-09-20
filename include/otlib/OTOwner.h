
#ifndef __OT_OWNER_H__
#define __OT_OWNER_H__

class OTIdentifier;
class OTString;
class OTPseudonym;

// Abstract base class for OTPseudonym and OTEntity (corporations...)
//
class OTOwner
{
protected:
    OTString m_strVersion;

public:
// ------------------------------------------    
EXPORT	virtual bool CompareID(const OTIdentifier & theIdentifier) const=0;
EXPORT  virtual bool CompareID(const OTOwner & RHS) const=0;
// ------------------------------------------
EXPORT	virtual const OTIdentifier & GetConstID() const=0; // CONST VERSION
// ------------------------------------------	
EXPORT	virtual void GetIdentifier(OTIdentifier & theIdentifier) const=0;  // BINARY VERSION
EXPORT	virtual void SetIdentifier(const OTIdentifier & theIdentifier)=0;
	
EXPORT	virtual void GetIdentifier(OTString & theIdentifier) const=0; // STRING VERSION
EXPORT	virtual void SetIdentifier(const OTString & theIdentifier)=0;
// ------------------------------------------
EXPORT  virtual bool LoadSignedFile(OTPseudonym & SIGNER_NYM)=0;
EXPORT  virtual bool SaveSignedFile(OTPseudonym & SIGNER_NYM)=0;
// ------------------------------------------
EXPORT  OTOwner();
EXPORT  OTOwner(const OTIdentifier & theID);
EXPORT	OTOwner(const OTString & strID);
EXPORT  virtual ~OTOwner();
};

#endif // __OT_OWNER_H__
