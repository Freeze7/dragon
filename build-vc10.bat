@echo off
call vcvars32.bat x86

REM build project
mkdir "build.dragon.vc10.debug"
cd "build.dragon.vc10.debug"
cmake -G "Visual Studio 10" -DCMAKE_BUILD_TYPE=Debug ..
cd ..