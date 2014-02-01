REM build SDL2 and install in 'dep' folder
cmake -G "NMake Makefiles" -DCMAKE_INSTALL_PREFIX:PATH=../dep ../dep/SDL2-2.0.1
nmake
nmake install

