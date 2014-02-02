@echo off
call vcvars32.bat x86

REM build project
mkdir "build.dragon.nmake.debug"
cd "build.dragon.nmake.debug"
cmake -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
cd ..