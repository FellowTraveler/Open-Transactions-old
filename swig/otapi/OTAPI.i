%module(directors="1") otapi

// included in the cpp file.
%{
#include <string>
#include <map>
#define IMPORT
#include "../../include/otlib/OTAsymmetricKey.h"
#include "../../include/otapi/OTAPI_Basic.h"
#include "../../include/otlib/OTStorage.h"
%}


%include "std_string.i";
%include "typemaps.i"


%feature("director") SwigPasswordCallback;

%ignore OTPasswordData;
%rename(opAssign) OTPassword::operator=;
%include "../../include/otlib/OTPassword.h"


%ignore StoredObjectTypeStrings;
%ignore details;
%ignore clone;


/* Parse the header file to generate wrappers */

%include "../../include/otapi/OTAPI_Basic.h"
%define NO_PACKED_BUFFER;
%enddef
%define NO_STORAGE_FS;
%enddef
%define NO_INIT_OTDB;
%enddef
%include "../../include/otlib/OTStorage.h"






