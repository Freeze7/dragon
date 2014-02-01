REM build SDL2 and install in 'dep' folder
cmake -G "MinGW Makefiles" -DCMAKE_INSTALL_PREFIX:PATH=../dep ../dep/SDL2-2.0.1
make
make install
