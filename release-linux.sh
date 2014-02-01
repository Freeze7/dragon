#!/bin/sh
# builds the game for linux releases
####################################

#########################################################
# set the project title here
#########################################################

PROJECT_TITLE="dragon"

# create release directory
BUILDDIR="$PROJECT_TITLE-$(date +%F)"
if [ -d "$BUILDDIR" ]; then rm -rf "$BUILDDIR"; fi
mkdir "$BUILDDIR"

# first, clean up all generated files from last build
#if [ -d "build" ]; then rm -rf "build"; fi
if [ -d "$BUILDDIR" ]; then rm -rf "$BUILDDIR"; fi

# build SDL2 in 'build.sdl2' directory, and install it in 'dep' directory
#mkdir "build.sdl2"
#cd "build.sdl2"
#echo "Generating makefiles for SDL2..."
#cmake -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX:PATH=../dep -DCMAKE_BUILD_TYPE=Release ../dep/SDL2-2.0.1 >/dev/null
#if [ "$?" -ne 0 ]; then; echo "Failed to generate makefiles for SDL2. Aborting."; exit 1; fi
#echo "Building SDL2..."
#make >/dev/null
#if [ "$?" -ne 0 ]; then; echo "Failed to build SDL2. Aborting."; exit 1; fi
#echo "Installing SDL2..."
#make install >/dev/null
#if [ "$?" -ne 0 ]; then; echo "Failed to install SDL2. Aborting."; exit 1; fi
#cd ..

# build game
#mkdir "build"
mkdir "$BUILDDIR"
cd "build"
echo "Generating makefiles..."
cmake -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX:PATH=../$BUILDDIR -DCMAKE_BUILD_TYPE=Release ..
if [ "$?" -ne 0 ]; then echo "Failed to generate makefiles. Aborting."; exit 1; fi
echo "Building dragon..."
make
if [ "$?" -ne 0 ]; then echo "Failed to build dragon. Aborting."; exit 1; fi
echo "Installing dragon..."
make install
if [ "$?" -ne 0 ]; then echo "Failed to install dragon. Aborting."; exit 1; fi
cd ..

# generate start script
echo "Generating start scripts..."
echo "export LD_LIBRARY_PATH=lib\n./bin/dragon" >$BUILDDIR/run.sh
chmod +x "$BUILDDIR/run.sh"

# compress
echo "Compressing..."
tar --xz -cf "$BUILDDIR.tar.xz" "$BUILDDIR"

# clean up
# rm -rf "$BUILDDIR"

echo "Done."

exit 0
