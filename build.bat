@echo off
REM Script di compilazione per Client e Server usando cl (MSVC)
setlocal

REM Variabili
set COMPILER=cl
set FLAGS=/W4 /O2 /EHsc /I"_HeaderFiles"
set CLIENT_SRC=Client\client.cpp
set SERVER_SRC=Server\server.cpp
set CLIENT_EXE=build\client.exe
set SERVER_EXE=build\server.exe

REM Crea la cartella build se non esiste
if not exist build (
    mkdir build
)

echo ============================
echo Compilazione del Client...
echo ============================
%COMPILER% %FLAGS% %CLIENT_SRC% /Fe%CLIENT_EXE%
if %ERRORLEVEL% neq 0 (
    echo Errore nella compilazione del Client!
    exit /b %ERRORLEVEL%
) else (
    echo Client compilato correttamente: %CLIENT_EXE%
)

echo ============================
echo Compilazione del Server...
echo ============================
%COMPILER% _HeaderFiles/socket_MAN.cpp %SERVER_SRC% /Fe%SERVER_EXE%
if %ERRORLEVEL% neq 0 (
    echo Errore nella compilazione del Server!
    exit /b %ERRORLEVEL%
) else (
    echo Server compilato correttamente: %SERVER_EXE%
)

echo ============================
echo Compilazione completata con successo!
echo ============================
pause
