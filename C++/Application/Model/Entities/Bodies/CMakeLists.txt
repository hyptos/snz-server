cmake_minimum_required(VERSION 2.8)

project ( Bodies CXX )
file ( GLOB_RECURSE SRC *.?pp )

add_subdirectory(SensorModules)
add_subdirectory(MotorModules)

add_library(Bodies SHARED ${SRC})
target_link_libraries(Bodies Qt5::Core)
target_link_libraries(Bodies Qt5::Gui)
target_link_libraries(Bodies Qt5::Widgets)
target_link_libraries(Bodies Utility)
target_link_libraries(Bodies Sensor)
target_link_libraries(Bodies Motor)
