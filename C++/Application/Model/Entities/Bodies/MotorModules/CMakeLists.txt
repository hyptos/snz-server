cmake_minimum_required(VERSION 2.8)

project ( Motor CXX )
file ( GLOB_RECURSE SRC *.?pp )

add_library(Motor SHARED ${SRC})
target_link_libraries(Motor Qt5::Core)
target_link_libraries(Motor Qt5::Gui)
target_link_libraries(Motor Qt5::Widgets)
target_link_libraries(Motor Utility)