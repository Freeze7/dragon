#!/bin/sh

# generate dragon project files
if [ ! -d "build.dragon.gmake.debug" ]; then
	mkdir "build.dragon.gmake.debug"
fi
cd "build.dragon.gmake.debug"
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
cd ..

exit 0
