cmake_minimum_required(VERSION 2.8)

project ( Orders CXX )
file ( GLOB_RECURSE SRC *.?pp )

add_library(Orders SHARED ${SRC})
target_link_libraries(Orders Qt5::Core)
target_link_libraries(Orders Qt5::Gui)
target_link_libraries(Orders Qt5::Widgets)
target_link_libraries(Orders Utility)