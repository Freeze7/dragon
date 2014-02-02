#!/bin/sh

# generate dragon project files
if [ ! -d "build.dragon.cb.debug" ]; then
	mkdir "build.dragon.cb.debug"
fi
cd "build.dragon.cb.debug"
cmake -G "CodeBlocks - Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
cd ..

exit 0
