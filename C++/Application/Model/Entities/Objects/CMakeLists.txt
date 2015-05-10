cmake_minimum_required(VERSION 2.8)

project ( Objects CXX )
file ( GLOB_RECURSE SRC *.?pp )

add_library(Objects SHARED ${SRC})
target_link_libraries(Objects Qt5::Core)
target_link_libraries(Objects Qt5::Gui)
target_link_libraries(Objects Qt5::Widgets)
target_link_libraries(Objects Utility)