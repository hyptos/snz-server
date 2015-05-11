cmake_minimum_required(VERSION 2.8)

project ( Info CXX )
file ( GLOB_RECURSE SRC *.?pp )

add_library(Info SHARED ${SRC})
target_link_libraries(Info Qt5::Core)
target_link_libraries(Info Qt5::Gui)
target_link_libraries(Info Qt5::Widgets)
target_link_libraries(Info Message)
target_link_libraries(Info Utility)
