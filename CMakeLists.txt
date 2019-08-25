cmake_minimum_required(VERSION 3.15.2)
project (Taima LANGUAGES CXX)

# Sources for the executable are specified at end of CMakeLists.txt
add_executable(Taima "")

### Default build type
# Set a default build type if none was specified
if(CMAKE_BUILD_TYPE MATCHES Release)
	message(STATUS "Building release")
	set(default_build_type "Release")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s")
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
set_property(TARGET Taima PROPERTY CXX_STANDARD 17)
set_property(TARGET Taima PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET Taima PROPERTY CXX_EXTENSIONS OFF)

### Includes
target_include_directories(Taima PRIVATE src)
target_include_directories(Taima PRIVATE include)

### Sources
target_sources(Taima PRIVATE
	src/main.cxx
)
