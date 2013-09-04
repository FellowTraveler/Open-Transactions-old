Name Open-Transactions

RequestExecutionLevel admin
SetCompressor /SOLID lzma

!define NAME Open-Transactions

# General Symbol Definitions
!define REGKEY "SOFTWARE\${NAME}"
!define /file VERSION ..\VERSION
!define COMPANY "Open Transactions"
!define URL https://github.com/FellowTraveler/Open-Transactions

# MUI Symbol Definitions
!define MUI_HEADERIMAGE
!define MUI_HEADERIMAGE_RIGHT
!define MUI_FINISHPAGE_NOAUTOCLOSE
!define MUI_STARTMENUPAGE_REGISTRY_ROOT HKLM
!define MUI_STARTMENUPAGE_REGISTRY_KEY ${REGKEY}
!define MUI_STARTMENUPAGE_REGISTRY_VALUENAME StartMenuGroup
!define MUI_STARTMENUPAGE_DEFAULTFOLDER Open-Transactions
!define MUI_UNFINISHPAGE_NOAUTOCLOSE

# Included files
!include Sections.nsh
!include MUI2.nsh

# Variables
Var StartMenuGroup

# Installer pages
!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_STARTMENU Application $StartMenuGroup
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES

# Installer languages
!insertmacro MUI_LANGUAGE English

# Installer attributes
OutFile ${NAME}-${VERSION}-x64-setup.exe
InstallDir $PROGRAMFILES\${NAME}
CRCCheck on
XPStyle on
BrandingText " "
ShowInstDetails show
VIProductVersion "0.88.10.0"
VIAddVersionKey ProductName Bitcoin
VIAddVersionKey ProductVersion ${VERSION}
VIAddVersionKey CompanyName "${COMPANY}"
VIAddVersionKey CompanyWebsite "${URL}"
VIAddVersionKey FileVersion ${VERSION}
VIAddVersionKey FileDescription ""
VIAddVersionKey LegalCopyright ""
InstallDirRegKey HKLM "${REGKEY}" Path
ShowUninstDetails show

# Installer sections
Section -Main SEC0000
    SetOutPath $INSTDIR
    SetOverwrite on

    File ..\lib\x64\Release\chaiscript.dll
    File ..\lib\x64\Release\otmint.exe
    File ..\lib\x64\Release\libzmq.dll
    File ..\lib\x64\Release\ot.exe
    File ..\lib\x64\Release\otapi.dll
    File ..\lib\x64\Release\otapi-d.dll
    File ..\lib\x64\Release\otapi-java.dll
    File ..\lib\x64\Release\otlib.dll
    File ..\lib\x64\Release\otserver.exe

# OpenSSL...

    File C:\OpenSSL-Win64\libeay32.dll
    File C:\OpenSSL-Win64\ssleay32.dll

    SetOutPath $INSTDIR\scripts
    File /r ..\scripts\*

    SetOutPath $INSTDIR\docs
    File ..\docs\CLIENT-COMMANDS.txt
    File ..\docs\INSTALL-Windows.txt
    File ..\docs\LICENSE-AND-CREDITS.txt
    File ..\docs\RELEASE-NOTES.txt
    File ..\docs\SECURITY.txt
    File ..\docs\SSL-NOTES.txt
    File ..\docs\WIPE-USERS-ACCOUNTS.txt

    SetOutPath $INSTDIR
    WriteRegStr HKLM "${REGKEY}\Components" Main 1

SectionEnd

Section -post SEC0001
    WriteRegStr HKLM "${REGKEY}" Path $INSTDIR
    SetOutPath $INSTDIR
    WriteUninstaller $INSTDIR\uninstall.exe

    !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
    SetShellVarContext all
    CreateDirectory $SMPROGRAMS\$StartMenuGroup
    CreateShortcut "$SMPROGRAMS\$StartMenuGroup\${NAME} x64.lnk" %comspec% '/k "$INSTDIR\scripts\run_opentxs.bat"'
    CreateShortcut "$SMPROGRAMS\$StartMenuGroup\Uninstall ${NAME} x64.lnk" $INSTDIR\uninstall.exe
    !insertmacro MUI_STARTMENU_WRITE_END

    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\${NAME}" DisplayName "${NAME} x64"
    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\${NAME}" DisplayVersion "${VERSION}"
    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\${NAME}" Publisher "${COMPANY}"
    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\${NAME}" URLInfoAbout "${URL}"
    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\${NAME}" DisplayIcon $INSTDIR\uninstall.exe
    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\${NAME}" UninstallString $INSTDIR\uninstall.exe
    WriteRegDWORD HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\${NAME}" NoModify 1
    WriteRegDWORD HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\${NAME}" NoRepair 1
SectionEnd

# Macro for selecting uninstaller sections
!macro SELECT_UNSECTION SECTION_NAME UNSECTION_ID
    Push $R0
    ReadRegStr $R0 HKLM "${REGKEY}\Components" "${SECTION_NAME}"
    StrCmp $R0 1 0 next${UNSECTION_ID}
    !insertmacro SelectSection "${UNSECTION_ID}"
    GoTo done${UNSECTION_ID}
next${UNSECTION_ID}:
    !insertmacro UnselectSection "${UNSECTION_ID}"
done${UNSECTION_ID}:
    Pop $R0
!macroend

# Uninstaller sections
Section /o -un.Main UNSEC0000
    RMDir /r /REBOOTOK $INSTDIR
    DeleteRegValue HKLM "${REGKEY}\Components" Main
SectionEnd

Section -un.post UNSEC0001
    DeleteRegKey HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\${NAME}"

    SetShellVarContext all
    Delete /REBOOTOK "$SMPROGRAMS\$StartMenuGroup\Uninstall ${NAME} x64.lnk"
    Delete /REBOOTOK "$SMPROGRAMS\$StartMenuGroup\${NAME} x64.lnk"
    Delete /REBOOTOK "$SMSTARTUP\${NAME} x64.lnk"
    Delete /REBOOTOK $INSTDIR\uninstall.exe
    Delete /REBOOTOK $INSTDIR\debug.log
    Delete /REBOOTOK $INSTDIR\db.log
    DeleteRegValue HKLM "${REGKEY}" StartMenuGroup
    DeleteRegValue HKLM "${REGKEY}" Path
    DeleteRegKey /IfEmpty HKLM "${REGKEY}\Components"
    DeleteRegKey /IfEmpty HKLM "${REGKEY}"
    DeleteRegKey HKLM "${NAME}"
    RmDir $SMPROGRAMS\$StartMenuGroup
    RmDir /REBOOTOK $INSTDIR
    Push $R0
    StrCpy $R0 $StartMenuGroup 1
    StrCmp $R0 ">" no_smgroup
no_smgroup:
    Pop $R0
SectionEnd

# Installer functions
Function .onInit
    InitPluginsDir
FunctionEnd

# Uninstaller functions
Function un.onInit
    ReadRegStr $INSTDIR HKLM "${REGKEY}" Path
    !insertmacro MUI_STARTMENU_GETFOLDER Application $StartMenuGroup
    !insertmacro SELECT_UNSECTION Main ${UNSEC0000}
FunctionEnd