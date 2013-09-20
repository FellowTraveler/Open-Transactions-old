#ifndef __OT_DEPARTMENT_H__
#define __OT_DEPARTMENT_H__

#include <string>
#include <map>

class OTDepartment;

typedef std::map<std::string, OTDepartment*>  mapOfDepartments;

// --------------------------------------------------

class OTRole
{
    // put management powers in here.
    // Able to: Enter into contracts. Create subdepartments. Disperse funds. Hire/fire. Etc.
    
    
    // along with role name.
    
    
    // List of accounts this role has power over.
    
    
    // List of employees in this role
    
    // Amount of pay for this role, and in what asset type.
    
    //
public:
    OTRole();
    virtual ~OTRole();
};

// --------------------------------------------------

class OTDepartment
{
    mapOfRoles       m_mapRoles;          // "CTO", "manager", etc : OTRole (each role has a list of employees in that role)
    mapOfDepartments m_mapSubdepartments; // "accounting" : OTDepartment* (departments are nested)
    mapOfAccounts    m_mapAccounts;       // Certain roles can operate accounts.
                                          // (If you don't want them sharing, then put them in separate sub-departments.)
    
    // Payroll account?
    
public:
    OTDepartment();
    virtual ~OTDepartment();
};


// --------------------------------------------------











#endif // __OT_DEPARTMENT_H__

