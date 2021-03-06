cmake_minimum_required(VERSION 2.8)

include(conf.cmake)

set(CMAKE_AUTOMOC ON)
set(CMAKE_OSX_ARCHITECTURES "x86_64")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

project ( Mif39 CXX )

list ( APPEND CMAKE_PREFIX_PATH ${QT_PATH})
find_package(Qt5Core)
find_package(Qt5Gui)
FIND_PACKAGE(Qt5Widgets)
FIND_PACKAGE(Qt5Declarative)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories ( "." )
include_directories ( "Application/" )

add_subdirectory(Utility)
add_subdirectory(Networking)
add_subdirectory(TcpNetworking)
add_subdirectory(AssetInterfaces)
add_subdirectory(AssetGenerics)
add_subdirectory(Assets)

add_subdirectory(Wavefront)

add_subdirectory(FuzzyLogicBehaviour)

add_subdirectory(QImageLoader)
add_subdirectory(Samples)

add_subdirectory(Application)
