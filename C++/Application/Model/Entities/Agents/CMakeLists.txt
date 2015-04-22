cmake_minimum_required(VERSION 2.8)

project ( Agents CXX )
file ( GLOB_RECURSE SRC *.?pp )

add_library(Agents SHARED ${SRC})
target_link_libraries(Agents Qt5::Core)
target_link_libraries(Agents Qt5::Gui)
target_link_libraries(Agents Utility)
