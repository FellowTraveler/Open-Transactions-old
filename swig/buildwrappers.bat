@ECHO OFF
:: A batch file that generates and renames intop swig
:: files for connecting OT to other langurages.
ECHO.

ECHO Checking if ..\..\swigwin-2.0.4\swig.exe exist: 
IF NOT EXIST "..\..\swigwin-2.0.4\swig.exe" (
	ECHO cannot find swigwin-2.0.4...
	GOTO END
)

ECHO.
ECHO swigwin-2.0.4 exits! Good :)
ECHO.
ECHO.

FOR %%x IN (csharp java perl5 php python ruby tcl) DO (

ECHO.
ECHO Generating for %%x ...


RMDIR /S /Q "glue\%%x"
MKDIR "glue\%%x"

IF EXIST otapi\OTAPI_wrap.cxx      DEL                              otapi\OTAPI_wrap.cxx
IF EXIST otapi\OTAPI_wrap.cpp      DEL                              otapi\OTAPI_wrap.cpp
IF EXIST otapi\OTAPI_wrap.h        DEL                              otapi\OTAPI_wrap.h


IF NOT %%x == java (
	ECHO ..\..\swigwin-2.0.4\swig.exe -c++ -%%x -outdir glue\%%x otapi\OTAPI.i
	..\..\swigwin-2.0.4\swig.exe -c++ -%%x -outdir glue\%%x otapi\OTAPI.i
)

IF %%x == java (
	ECHO ..\..\swigwin-2.0.4\swig.exe -c++ -%%x -package org.ot.wrapper.jni -outdir glue\%%x otapi\otapi.i
	 ..\..\swigwin-2.0.4\swig.exe -c++ -%%x -package org.ot.wrapper.jni -outdir glue\%%x otapi\otapi.i
)


IF EXIST otapi\OTAPI-%%x.cxx     DEL                              otapi\OTAPI-%%x.cxx
IF EXIST otapi\OTAPI_wrap.cxx    MOVE /Y   otapi\OTAPI_wrap.cxx   otapi\OTAPI-%%x.cxx
IF EXIST otapi\OTAPI-%%x.cpp     DEL                              otapi\OTAPI-%%x.cpp
IF EXIST otapi\OTAPI_wrap.cpp    MOVE /Y   otapi\OTAPI_wrap.cpp   otapi\OTAPI-%%x.cpp
IF EXIST otapi\OTAPI-%%x.h       DEL                              otapi\OTAPI-%%x.h
IF EXIST otapi\OTAPI_wrap.h      MOVE /Y   otapi\OTAPI_wrap.h     otapi\OTAPI-%%x.h


)

ECHO.
ECHO Done!
ECHO.
:END