@ECHO OFF
cd /d "%~dp0"
Sheltered_save_file_converter.exe "%~1" "%~n1.bak" --nopause
if errorlevel 0 rename "%~n1.bak" "%~n1.xml"
if errorlevel 1 rename "%~n1.bak" "%~n1.dat"
if errorlevel 99 rename "%~n1.bak" "%~n1.bak%random%"
PAUSE