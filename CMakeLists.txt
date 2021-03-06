cmake_minimum_required(VERSION 2.8.9)

if (POLICY CMP0054)
    cmake_policy(SET CMP0054 NEW)
endif ()
if (POLICY CMP0074)
    cmake_policy(SET CMP0074 NEW)
endif ()

include("cmake/HunterGate.cmake")
HunterGate(
        URL "https://github.com/ruslo/hunter/archive/v0.23.154.tar.gz"
        SHA1 "d720f3775d4b896dab91f8249de04956e31804dd"
)

project(CppNNet)
set(CMAKE_CXX_STANDARD 11)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE DEBUG)
endif (NOT CMAKE_BUILD_TYPE)

option(BUILD_TEST "Build the Tests" ON)

#set(CMAKE_CXX_FLAGS_RELEASE "-g ${CMAKE_CXX_FLAGS_RELEASE}")

hunter_add_package(ZLIB)
hunter_add_package(Eigen)
hunter_add_package(CURL)
hunter_add_package(RapidJSON)
find_package(ZLIB CONFIG REQUIRED)
find_package(Eigen3 CONFIG REQUIRED)
find_package(CURL CONFIG REQUIRED)
find_package(RapidJSON CONFIG REQUIRED)

find_package(OpenMP REQUIRED)

include_directories(include)

add_subdirectory(src)

if (BUILD_TEST)
    enable_testing()
    add_subdirectory(tests)
endif ()
