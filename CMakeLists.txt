cmake_minimum_required (VERSION 2.8.11)
set (CMAKE_DISABLE_IN_SOURCE_BUILD ON)

# required for externalproject_add
include (${CMAKE_ROOT}/Modules/ExternalProject.cmake)

# add external dependency SDL2.0.1
set (sdl2_PREFIX "${CMAKE_SOURCE_DIR}/dep")
set (sdl2_SOURCE_DIR "${CMAKE_SOURCE_DIR}/dep/SDL2-2.0.1")
ExternalProject_Add (DEP_SDL2
	PREFIX "${sdl2_PREFIX}"
	DOWNLOAD_COMMAND ""
	SOURCE_DIR "${sdl2_SOURCE_DIR}"
	CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${sdl2_PREFIX} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -DSDL_STATIC=OFF
)

# project name
project (dragon)

# set output locations
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# set include directories
include_directories (
	"${PROJECT_SOURCE_DIR}/dragon"
	"${PROJECT_SOURCE_DIR}/dep/include"
)

# set link directories
link_directories (
	"${PROJECT_SOURCE_DIR}/dep/lib"
)

# disable windows MFC and use standard libraries
set (CMAKE_MFC_FLAG 0)

# dragon executable
add_executable (dragon
	"${PROJECT_SOURCE_DIR}/dragon/main.c"
)

# set dependencies
add_dependencies (dragon
	DEP_SDL2
)

# link libraries
target_link_libraries (dragon
	SDL2main
	SDL2
)

# install rules
install (TARGETS dragon
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)

