cmake_minimum_required(VERSION 2.8)

project ( Entities CXX )
file ( GLOB_RECURSE SRC *.?pp )

add_subdirectory(Agents)
add_subdirectory(Bodies)
add_subdirectory(Objects)

add_library(Entities SHARED ${SRC})
target_link_libraries(Entities Qt5::Core)
target_link_libraries(Entities Qt5::Gui)
target_link_libraries(Entities Qt5::Widgets)
target_link_libraries(Entities Utility)
target_link_libraries(Entities Agents)
target_link_libraries(Entities Bodies)
target_link_libraries(Entities Objects)
