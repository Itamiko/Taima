cmake_minimum_required(VERSION 3.15.2)
project (taima LANGUAGES C)

# Sources for the executable are specified at end of CMakeLists.txt
add_executable(taima "")

### Default build type
# Set a default build type if none was specified
if(CMAKE_BUILD_TYPE MATCHES Release)
	message(STATUS "Building release")
	set(default_build_type "Release")
	set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")
endif()

if(CMAKE_BUILD_TYPE MATCHES Debug)
	message(STATUS "Building debug")
	set(default_build_type "Debug")
endif()

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	message(STATUS "Setting build type to '${DEFAULT_CMAKE_BUILD_TYPE}' as none was specified.")
	set(CMAKE_BUILD_TYPE ${DEFAULT_CMAKE_BUILD_TYPE}
		CACHE STRING "Choose the type of build." FORCE)
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS Debug Release MinSizeRel RelWithDebInfo)
endif()

### Compile options
# Enable C++17 (Required)
set_property(TARGET taima PROPERTY C_STANDARD 11)
set_property(TARGET taima PROPERTY C_STANDARD_REQUIRED ON)
set_property(TARGET taima PROPERTY C_EXTENSIONS OFF)

### Includes
target_include_directories(taima PRIVATE src)
target_include_directories(taima PRIVATE include)

### Sources
target_sources(taima PRIVATE
	src/main.c
)
