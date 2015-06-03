cmake_minimum_required(VERSION 2.8)

project ( Stimuli CXX )
file ( GLOB_RECURSE SRC *.?pp )

add_library(Stimuli SHARED ${SRC})
target_link_libraries(Stimuli Qt5::Core)
target_link_libraries(Stimuli Qt5::Gui)
target_link_libraries(Stimuli Qt5::Widgets)
target_link_libraries(Stimuli Utility)