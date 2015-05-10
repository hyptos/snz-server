cmake_minimum_required(VERSION 2.8)

project ( Sensor CXX )
file ( GLOB_RECURSE SRC *.?pp )

add_library(Sensor SHARED ${SRC})
target_link_libraries(Sensor Qt5::Core)
target_link_libraries(Sensor Qt5::Gui)
target_link_libraries(Sensor Qt5::Widgets)
target_link_libraries(Sensor Utility)