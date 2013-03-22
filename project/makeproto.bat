@ECHO OFF
:: A batch file that generates and moves the protobuf
:: files for used for serializing OT data.
ECHO.

:start
SET START_DIR="%cd%"
cd /D %~dp0..\
cd
goto :welcome

:welcome
echo:
echo ** Open Transactions PROTOBUF Script **
echo:
echo this script was written by da2ce7
echo please feel free to report bugs on github.
echo:
goto :define

:define
SET PROTO_VER=2.5.0
SET PROTO_EXE=protoc.exe
SET PROTO_DIR=protoc-%PROTO_VER%-win32
SET PROTO_DIR_PATH=..\%PROTO_DIR%
SET PROTO_EXE_PATH=%PROTO_DIR_PATH%\%PROTO_EXE%

SET OT_SRC=src
SET OT_INCLUDE=include
SET OT_LIB=otlib
SET OT_PROTOB=protobOT

SET OT_SRC_LIB=%OT_SRC%\%OT_LIB%
SET OT_INCLUDE_LIB=%OT_INCLUDE%\%OT_LIB%
SET OT_SRC_PROTOB=%OT_SRC_LIB%\%OT_PROTOB%

goto :print_defines

:print_defines
echo:
echo **************** SET ****************
echo PROTO_VER = %PROTO_VER%
echo PROTO_EXE = %PROTO_EXE%
echo PROTO_DIR = %PROTO_DIR%
echo PROTO_DIR_PATH = %PROTO_DIR_PATH%
echo PROTO_EXE_PATH = %PROTO_EXE_PATH%
echo OT_SRC = %OT_SRC%
echo OT_INCLUDE = %OT_INCLUDE%
echo OT_LIB = %OT_LIB%
echo OT_PROTOB = %OT_PROTOB%
echo OT_SRC_LIB = %OT_SRC_LIB%
echo OT_INCLUDE_LIB = %OT_INCLUDE_LIB%
echo OT_SRC_PROTOB = %OT_SRC_PROTOB%
echo **************** END ****************
goto :check_protoc

:check_protoc
echo:
echo checking For PROTOC in:
echo %PROTO_EXE_PATH% ...
IF NOT EXIST "%PROTO_EXE_PATH%" GOTO :no_protoc
echo FOUND!!
goto :clean

:no_protoc
echo:
echo unable to find PROTOC
echo Please place a the PROTOC folder at the same level
echo as the OT folder.
echo if your version of PROTOC is newer, please update this bat file.
echo:
goto :finish

:clean
echo:
echo: cleanup old protobuf files...
IF EXIST "%OT_SRC_LIB%\*.pb.cc" DEL "%OT_SRC_LIB%\*.pb.cc"
IF EXIST "%OT_SRC_LIB%\*.pb.h" DEL "%OT_SRC_LIB%\*.pb.h"
IF EXIST "%OT_INCLUDE_LIB%\*.pb.h" DEL "%OT_INCLUDE_LIB%\*.pb.h"
echo done!
goto :core

:core
echo:
echo Generating PROTO files ...
echo:
echo "%PROTO_EXE_PATH%" --proto_path="%OT_SRC_PROTOB%" --cpp_out="%OT_SRC_LIB%" "%OT_SRC_PROTOB%\*.proto"
"%PROTO_EXE_PATH%" --proto_path="%OT_SRC_PROTOB%" --cpp_out="%OT_SRC_LIB%" "%OT_SRC_PROTOB%\*.proto"
MOVE "%OT_SRC_LIB%\*.pb.h" "%OT_INCLUDE_LIB%"
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
