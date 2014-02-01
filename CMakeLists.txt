cmake_minimum_required (VERSION 2.8.11)
set (CMAKE_DISABLE_IN_SOURCE_BUILD ON)

# project name
project (dragon)

# set output locations
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# set include directories
include_directories (
	"${PROJECT_SOURCE_DIR}/dragon"
)

# dragon executable
add_executable (dragon
	"dragon/main.c"
)

# find dependencies
find_package (SDL2 REQUIRED)

# link libraries
target_link_libraries (dragon
	SDL2main
	SDL2
)
