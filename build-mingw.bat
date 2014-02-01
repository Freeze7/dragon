REM build project
mkdir "build.dragon.mingw.debug"
cd "build.dragon.mingw.debug"
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ..

exit 0
