
#include "OTEntity.h"

#include "OTIdentifier.h"
#include "OTString.h"




// -----------------------------------------------------------------------------


// Save the Entity to a string.
//
bool OTEntity::SaveToString(OTString & strEntity)
{
	OTString strEntityID;
	this->GetIdentifier(strEntityID);
	// --------------------------------------------------------
	strEntity.Concatenate("<?xml version=\"%s\"?>\n", "1.0");
	
    strEntity.Concatenate("<OTEntity version=\"%s\"\n"
                          " entityID=\"%s\""
                          ">\n\n",
                          m_strVersion.Get(),
                          strEntityID.Get()
                          );

	// -------------------------------------
    // When you delete an entity, it just marks it.
    // Actual deletion occurs during maintenance sweep (targeting marked entities...)
    //
//    if (m_bMarkForDeletion)
//        strEntity.Concatenate("<MARKED_FOR_DELETION>\n"
//                           "%s</MARKED_FOR_DELETION>\n\n",
//                           "THIS NYM HAS BEEN MARKED FOR DELETION AT ITS OWN REQUEST");
	// -------------------------------------
	
	strEntity.Concatenate("</OTEntity>\n");	
	
	return true;
}



// --------------------------------------------------------------


/*
 
 Enumeration for all xml nodes which are parsed by IrrXMLReader.
 
 Enumeration values:
 
 EXN_NONE			No xml node. This is usually the node if you did not read anything yet.
 EXN_ELEMENT		A xml element, like <foo>.
 EXN_ELEMENT_END	End of an xml element, like </foo>.
 EXN_TEXT			Text within a xml element: <foo> this is the text. </foo>.
 EXN_COMMENT		An xml comment like <!-- I am a comment --> or a DTD definition.
 EXN_CDATA			An xml cdata section like <![CDATA[ this is some CDATA ]]>.
 EXN_UNKNOWN		Unknown element.
 
 Definition at line 180 of file irrXML.h.
 
 */

bool OTEntity::LoadFromString(const OTString & strEntity)
{
	bool bSuccess = false;
    // ------------------------------------
	OTStringXML strEntityXML(strEntity); // todo optimize
	IrrXMLReader* xml = createIrrXMLReader(&strEntityXML);
	OT_ASSERT(NULL != xml);
	OTCleanup<IrrXMLReader> theCleanup(*xml);
    // ------------------------------------
	// parse the file until end reached
    //
	while(xml && xml->read())
	{
        
//        switch(xml->getNodeType())
//        {
//            case(EXN_NONE):
//                OTLog::Error("ACK NUMS: EXN_NONE --  No xml node. This is usually the node if you did not read anything yet.\n");
//                break;
//            case(EXN_ELEMENT):
//                OTLog::Error("ACK NUMS: EXN_ELEMENT -- An xml element such as <foo>.\n");
//                break;
//            case(EXN_ELEMENT_END):
//                OTLog::Error("ACK NUMS: EXN_ELEMENT_END -- End of an xml element such as </foo>.\n");
//                break;
//            case(EXN_TEXT):
//                OTLog::Error("ACK NUMS: EXN_TEXT -- Text within an xml element: <foo> this is the text. <foo>.\n");
//                break;
//            case(EXN_COMMENT):
//                OTLog::Error("ACK NUMS: EXN_COMMENT -- An xml comment like <!-- I am a comment --> or a DTD definition.\n");
//                break;
//            case(EXN_CDATA):
//                OTLog::Error("ACK NUMS: EXN_CDATA -- An xml cdata section like <![CDATA[ this is some CDATA ]]>.\n");
//                break;
//            case(EXN_UNKNOWN):
//                OTLog::Error("ACK NUMS: EXN_UNKNOWN -- Unknown element.\n");
//                break;
//            default:
//                OTLog::Error("ACK NUMS: default!! -- SHOULD NEVER HAPPEN...\n");
//                break;
//        }
//        OTLog::vError("OTPseudonym::LoadFromString: NODE DATA: %s\n", xml->getNodeData());

        
		// strings for storing the data that we want to read out of the file		
        //
		switch(xml->getNodeType())
		{
			case EXN_NONE:
			case EXN_TEXT:
			case EXN_COMMENT:
			case EXN_ELEMENT_END:
			case EXN_CDATA:
				// in this xml file, the only text which occurs is the messageText
				//messageText = xml->getNodeData();
                
//            switch(xml->getNodeType())
//            {
//                case(EXN_NONE):
//                    OTLog::Error("SKIPPING: EXN_NONE --  No xml node. This is usually the node if you did not read anything yet.\n");
//                    break;
//                case(EXN_TEXT):
//                    OTLog::Error("SKIPPING: EXN_TEXT -- Text within an xml element: <foo> this is the text. <foo>.\n");
//                    break;
//                case(EXN_COMMENT):
//                    OTLog::Error("SKIPPING: EXN_COMMENT -- An xml comment like <!-- I am a comment --> or a DTD definition.\n");
//                    break;
//                case(EXN_ELEMENT_END):
//                    OTLog::Error("SKIPPING: EXN_ELEMENT_END -- End of an xml element such as </foo>.\n");
//                    break;
//                case(EXN_CDATA):
//                    OTLog::Error("SKIPPING: EXN_CDATA -- An xml cdata section like <![CDATA[ this is some CDATA ]]>.\n");
//                    break;
//                default:
//                    OTLog::Error("SKIPPING: default!! -- SHOULD NEVER HAPPEN...\n");
//                    break;
//            }
                
				break;
			case EXN_ELEMENT:
			{
                const OTString strNodeName = xml->getNodeName();
//              OTLog::vError("PROCESSING EXN_ELEMENT: NODE NAME: %s\n", strNodeName.Get());

				if (strNodeName.Compare("OTEntity"))
				{
                                   m_strVersion  = xml->getAttributeValue("version");
					const OTString strEntityID   = xml->getAttributeValue("entityID");

					if (strEntityID.GetLength() > 0)
						OTLog::vOutput(3, "\nLoading entity, version: %s EntityID:\n%s\n",
                                       m_strVersion.Get(), strEntityID.Get());
					bSuccess = true;
				}
                // ----------------------------------
				else
				{
					// unknown element type
					OTLog::vError("OTEntity::%s: Unknown element type: %s\n", __FUNCTION__, xml->getNodeName());
					bSuccess = false;
				}
				break;
			}
			default:
			{
				OTLog::vOutput(5, "OTEntity::%s: Unknown XML type: %s\n", __FUNCTION__, xml->getNodeName());
				break;	
			}
		} // switch
	} // while

	return bSuccess;
}



// --------------------------------------------------------------------------

//virtual
bool OTEntity::LoadSignedFile(OTPseudonym & SIGNER_NYM)
{
	// Get the Nym's ID in string form
	OTString strID;
	this->GetIdentifier(strID);
    // -----------------------------------
    OTSignedFile * pFile = OTSignedFile::LoadSignedFile(SIGNER_NYM, OTFolders::Entity(), strID); // asserts already.
    OTCleanup<OTSignedFile> theFileAngel(pFile);
    // -----------------------------------
    if (NULL != pFile)
	{
		OTLog::Output(2, "Loaded and verified a signed entity file. Loading from string...\n");
		
        return this->LoadFromString(pFile->GetFilePayload()); // <====== Success...
	}
    // -----------------------------------
	return false;
}


// --------------------------------------------------------------------------

//virtual
bool OTEntity::SaveSignedFile(OTPseudonym & SIGNER_NYM)
{
	// Get the Entity's ID in string form
	OTString strID;
	this->GetIdentifier(strID);
    // ---------------------------------------
	OTSignedFile theFile(OTFolders::Entity(), strID);
		
	// First we save this entity to a string...
	// Specifically, the payload contents string on the OTSignedFile object.
	this->SaveToString(theFile.GetFilePayload());

	// Now the OTSignedFile contains the path, the filename, AND the
	// contents of the Entity itself, in the payload.
	
    return theFile.SaveSignedFile(SIGNER_NYM);
}


// --------------------------------------------------------------------------


OTEntity::OTEntity()
: OTOwner()
{
	m_strVersion = "1.0";
}

OTEntity::OTEntity(const OTIdentifier & theID)
: OTOwner(theID), m_entityID(theID)
{
	m_strVersion = "1.0";    
}

OTEntity::OTEntity(const OTString & strID)
: OTOwner(strID)
{
    m_strVersion = "1.0";
    m_entityID.SetString(strID);
}

OTEntity::~OTEntity()
{
    
}

// -------------------------------------

bool OTEntity::CompareID(const OTIdentifier & theIdentifier) const
{
    return (theIdentifier == m_entityID);
}

// -------------------------------------

bool OTEntity::CompareID(const OTOwner & RHS) const
{
	return RHS.CompareID(m_entityID);
}

// -------------------------------------

const OTIdentifier & OTEntity::GetConstID() const
{
    return m_entityID;
}

// ----------------------------------------------------------------------------------------
// sets internal member based in ID passed in
void OTEntity::SetIdentifier(const OTIdentifier & theIdentifier)
{
	m_entityID = theIdentifier;
}
// ----------------------------------------------------------------------------------------

// sets argument based on internal member
void OTEntity::GetIdentifier(OTIdentifier & theIdentifier) const
{
	theIdentifier = m_entityID;
}
// ----------------------------------------------------------------------------------------

// sets internal member based in ID passed in
void OTEntity::SetIdentifier(const OTString & theIdentifier)
{
	m_entityID.SetString(theIdentifier);
}
// ----------------------------------------------------------------------------------------

// sets argument based on internal member
void OTEntity::GetIdentifier(OTString & theIdentifier) const
{
	m_entityID.GetString(theIdentifier);
}

// -------------------------------------
