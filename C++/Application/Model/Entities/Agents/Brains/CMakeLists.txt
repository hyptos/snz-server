cmake_minimum_required(VERSION 2.8)

project ( Brains CXX )
file ( GLOB_RECURSE SRC *.?pp )

add_library(Brains SHARED ${SRC})
target_link_libraries(Brains Qt5::Core)
target_link_libraries(Brains Qt5::Gui)
target_link_libraries(Brains Utility)
