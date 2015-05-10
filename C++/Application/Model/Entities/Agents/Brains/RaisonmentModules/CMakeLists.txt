cmake_minimum_required(VERSION 2.8)

project ( Raisonment CXX )
file ( GLOB_RECURSE SRC *.?pp )

add_library(Raisonment SHARED ${SRC})
target_link_libraries(Raisonment Qt5::Core)
target_link_libraries(Raisonment Qt5::Gui)
target_link_libraries(Raisonment Qt5::Widgets)
target_link_libraries(Raisonment Utility)