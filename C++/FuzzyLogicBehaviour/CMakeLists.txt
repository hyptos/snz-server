cmake_minimum_required(VERSION 2.8)

project ( FuzzyLogicBehaviour CXX )
file ( GLOB_RECURSE SRC *.?pp )
add_library(FuzzyLogicBehaviour SHARED ${SRC})
target_link_libraries(FuzzyLogicBehaviour Qt5::Core)
target_link_libraries(FuzzyLogicBehaviour Qt5::Gui)
target_link_libraries(FuzzyLogicBehaviour Utility)
target_link_libraries(FuzzyLogicBehaviour AssetInterfaces)
target_link_libraries(FuzzyLogicBehaviour AssetGenerics)
target_link_libraries(FuzzyLogicBehaviour Assets)
