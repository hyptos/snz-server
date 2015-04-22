cmake_minimum_required(VERSION 2.8)

project ( Players CXX )
file ( GLOB_RECURSE SRC *.?pp )

add_library(Players SHARED ${SRC})
target_link_libraries(Players Qt5::Core)
target_link_libraries(Players Qt5::Gui)
target_link_libraries(Players Utility)
