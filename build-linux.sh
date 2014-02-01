#!/bin/sh

# build SDL2
cmake -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX:PATH=../dep ../dep/SDL2-2.0.1
