;++++++++++++++++++++++++++++++++++
; atleto.nsi
;
; This script is based on example1.nsi, but it remember the directory, 
; has uninstall support and (optionally) installs start menu shortcuts.
;
; It will install example2.nsi into a directory that the user selects,
;
; $Id: atleto.nsi 372 2013-03-05 22:04:13Z boffyflow $
;--------------------------------

; The name of the installer
Name "Atleto v0.5.3 Installer"

; The file to write
OutFile "atleto_0.5.3_installer.exe"

; The default installation directory
InstallDir $PROGRAMFILES\ParallelPixels\atleto

; Registry key to check for directory (so if you install again, it will 
; overwrite the old one automatically)
InstallDirRegKey HKLM "Software\atleto" "Install_Dir"

;--------------------------------
; path variables

!define QT_VERSION 5.0.1
!define	QT_INSTALL C:\Qt\Qt${QT_VERSION}\${QT_VERSION}\mingw47_32
!define QT_DLL_DIR ${QT_INSTALL}\bin
!define MING_DLL_DIR C:\Qt\Qt${QT_VERSION}\Tools\mingw\bin

;--------------------------------

; Pages

Page components
Page directory
Page instfiles

UninstPage uninstConfirm
UninstPage instfiles

;--------------------------------

; The stuff to install
Section "atleto (required)"

  SectionIn RO
  
  ; Set output path to the installation directory.
  SetOutPath $INSTDIR
    
  ; Put file there
  File 	C:\Users\robert.uebbing\develop\atleto\tmp\stable\atleto-build-Desktop_Qt_5_0_1_MinGW_32bit-Release\release\atleto.exe \
		atleto_example.atl \
		${QT_DLL_DIR}\Qt5Core.dll \
		${QT_DLL_DIR}\Qt5Gui.dll \
		${QT_DLL_DIR}\Qt5Xml.dll \
		${QT_DLL_DIR}\Qt5Sql.dll \
		${QT_DLL_DIR}\Qt5Svg.dll \
		${MING_DLL_DIR}\libgcc_s_sjlj-1.dll

;				${MING_DLL_DIR}\mingwm10.dll

		
  ; Write default registry entries
  
  ; Example DB file
   ClearErrors
  ReadRegStr $1 HKCU "Software\ParallelPixels\Atleto\Options" "dbfilename"
  IfErrors 0 NoError_1
	WriteRegStr HKCU "Software\ParallelPixels\Atleto\Options" "dbfilename" "$INSTDIR\atleto_example.atl"
	DetailPrint "Writing registry entry for db file: $INSTDIR\atleto_example.atl"
    Goto ErrorOut_1
  NoError_1:
    DetailPrint "DB file used (read from registry): $1"
  ErrorOut_1: 
  
  ; Gnuplot executable
  ClearErrors
  ReadRegStr $1 HKCU "Software\ParallelPixels\Atleto\Options" "gnuplotexecutable"
  IfErrors 0 NoError_2
	WriteRegStr HKCU "Software\ParallelPixels\Atleto\Options" "gnuplotexecutable" "$INSTDIR\wgnuplot.exe"
	DetailPrint "Writing registry entry for gnuplot executable: $INSTDIR\wgnuplot.exe"
    Goto ErrorOut_2
  NoError_2:
    DetailPrint "Gnuplot executable (read from registry): $1"
  ErrorOut_2:
		
  ; Write the installation path into the registry
  WriteRegStr HKLM SOFTWARE\atleto "Install_Dir" "$INSTDIR"
  
  ; Write the uninstall keys for Windows
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\atleto" "DisplayName" "atleto"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\atleto" "UninstallString" '"$INSTDIR\uninstall.exe"'
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\atleto" "NoModify" 1
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\atleto" "NoRepair" 1
  WriteUninstaller "uninstall.exe"
  
SectionEnd

; Optional section (can be disabled by the user)
Section "Start Menu Shortcuts"

  CreateDirectory "$SMPROGRAMS\atleto"
  CreateShortCut "$SMPROGRAMS\atleto\Uninstall.lnk" "$INSTDIR\uninstall.exe" "" "$INSTDIR\uninstall.exe" 0
  CreateShortCut "$SMPROGRAMS\atleto\atleto.lnk" "$INSTDIR\atleto.exe" "" "$INSTDIR\atleto.exe" 0
  
SectionEnd

;--------------------------------

; Uninstaller

Section "Uninstall"
  
  ; Remove registry keys
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\atleto"
  DeleteRegKey HKLM SOFTWARE\atleto

  ; Remove files and uninstaller
  Delete $INSTDIR\atleto.exe
  Delete $INSTDIR\Qt5Core.dll
  Delete $INSTDIR\Qt5Gui.dll
  Delete $INSTDIR\Qt5Xml.dll
  Delete $INSTDIR\Qt5Sql.dll 
  Delete $INSTDIR\Qt5Svg.dll 
  Delete $INSTDIR\libgcc_s_sjlj-1.dll
  Delete $INSTDIR\uninstall.exe
  
  ; Remove shortcuts, if any
  Delete "$SMPROGRAMS\atleto\*.*"

  ; Remove directories used
  RMDir "$SMPROGRAMS\atleto"
  RMDir "$INSTDIR"

SectionEnd
