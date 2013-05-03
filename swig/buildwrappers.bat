@ECHO OFF
:: A batch file that generates and renames intop swig
:: files for connecting OT to other langurages.
ECHO.

:start
SET START_DIR="%cd%"
cd /D %~dp0..\
cd
goto :welcome

:welcome
echo:
echo ** Open Transactions SWIG Script **
echo:
echo this script was written by da2ce7
echo please feel free to report bugs on github.
echo:
goto :define

:define
SET SWIG_VER=2.0.9
SET SWIG_EXE=swig.exe
SET SWIG_DIR=swigwin-%SWIG_VER%
SET SWIG_DIR_PATH=..\%SWIG_DIR%
SET SWIG_EXE_PATH=%SWIG_DIR_PATH%\%SWIG_EXE%

SET OT_SWIG=swig
SET OT_GLUE=glue
SET OT_API=otapi
SET OT_API_H=OTAPI

SET OT_GLUE_PATH=%OT_SWIG%\%OT_GLUE%
SET OT_API_PATH=%OT_SWIG%\%OT_API%
SET OT_API_BASE=%OT_API_PATH%\%OT_API_H%

SET JAVA_PACKAGE_NAME=org.opentransactions.otapi

SET CSHARP_NAMESPACE_NAME=OpenTransactions.OTAPI
SET CSHARP_DLLIMPORT_NAME=otapi-csharp
goto :print_defines

:print_defines
echo:
echo **************** SET ****************
echo SWIG_VER = %SWIG_VER%
echo SWIG_EXE = %SWIG_EXE%
echo SWIG_DIR = %SWIG_DIR%
echo SWIG_DIR_PATH = %SWIG_DIR_PATH%
echo SWIG_EXE_PATH = %SWIG_EXE_PATH%
echo OT_SWIG = %OT_SWIG%
echo OT_GLUE = %OT_GLUE%
echo OT_API = %OT_API%
echo OT_API_H = %OT_API_H%
echo OT_GLUE_PATH = %OT_GLUE_PATH%
echo OT_API_PATH = %OT_API_PATH%
echo OT_API_BASE = %OT_API_BASE%
echo JAVA_PACKAGE_NAME = %JAVA_PACKAGE_NAME%
echo **************** END ****************
goto :check_swig

:check_swig
echo:
echo checking For SWIG in:
echo %SWIG_EXE_PATH% ...
IF NOT EXIST "%SWIG_EXE_PATH%" GOTO :no_swig
echo FOUND!!
goto :clean

:no_swig
echo:
echo unable to find SWIG
echo Please place a the SWIG folder at the same level
echo as the OT folder.
echo if your version of SWIG is newer, please update this bat file.
echo:
goto :finish

:clean
echo:
echo: cleanup old swig...
IF EXIST "%OT_GLUE_PATH%" rmdir /s /Q "%OT_GLUE_PATH%"

for %%a IN (cpp cxx h) DO (
IF EXIST "%OT_API_BASE%-wrap.%%a" DEL "%OT_API_BASE%-wrap.%%a"
IF EXIST "%OT_API_BASE%_wrap.%%a" DEL "%OT_API_BASE%_wrap.%%a"
)

for %%b IN (csharp java perl5 php python ruby tcl d) DO (
	for %%c IN (cpp cxx h) DO (
		IF EXIST "%OT_API_BASE%-%%b.%%c" DEL "%OT_API_BASE%-%%b.%%c"
	)
)
echo done!
goto :core

:core
FOR %%x IN (csharp java perl5 php python ruby tcl d) DO (
	echo:
	echo Generating for %%x ...
	
	MKDIR "%OT_GLUE_PATH%\%%x"

	IF NOT %%x == csharp IF NOT %%x == java (
		ECHO "%SWIG_EXE_PATH%" -c++ -%%x -outdir "%OT_GLUE_PATH%\%%x" "%OT_API_BASE%.i"
		"%SWIG_EXE_PATH%" -c++ -%%x -outdir "%OT_GLUE_PATH%\%%x" "%OT_API_BASE%.i"
	)

	IF %%x == csharp (
		ECHO "%SWIG_EXE_PATH%" -c++ -%%x -namespace %CSHARP_NAMESPACE_NAME% -dllimport %CSHARP_DLLIMPORT_NAME% -outdir "%OT_GLUE_PATH%\%%x" "%OT_API_BASE%.i"
		"%SWIG_EXE_PATH%" -c++ -%%x -namespace %CSHARP_NAMESPACE_NAME% -dllimport %CSHARP_DLLIMPORT_NAME% -outdir "%OT_GLUE_PATH%\%%x" "%OT_API_BASE%.i"
	)
	
	IF %%x == java (
		ECHO "%SWIG_EXE_PATH%" -c++ -%%x -package %JAVA_PACKAGE_NAME% -outdir "%OT_GLUE_PATH%\%%x" "%OT_API_BASE%.i"
		"%SWIG_EXE_PATH%" -c++ -%%x -package %JAVA_PACKAGE_NAME% -outdir "%OT_GLUE_PATH%\%%x" "%OT_API_BASE%.i"
	)
	
	for %%y IN (cpp cxx) DO (
		IF EXIST "%OT_API_BASE%_wrap.%%y" SED -i s/"OTAPI_wrap.h"/"OTAPI-%%x.h"/g "%OT_API_BASE%_wrap.%%y"
	)

	for %%z IN (cpp cxx h) DO (
		IF EXIST "%OT_API_BASE%_wrap.%%z" MOVE /Y "%OT_API_BASE%_wrap.%%z" "%OT_API_BASE%-%%x.%%z"
	)
)
goto :done

:done
ECHO:
ECHO DONE!
ECHO:
goto :finish

:finish
cd /D %START_DIR%
pause
goto :eof
