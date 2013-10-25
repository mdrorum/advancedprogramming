cmake_minimum_required (VERSION 2.6)

project (bots)

Find_Package ( SDL REQUIRED )


add_definitions(-std=c++11)
#add_definitions(-std=gnu++0x)
include_directories(${SDL_INCLUDE_DIR})

add_executable(bots playground.cpp bots.cpp)

target_link_libraries(bots ${SDL_LIBRARY})
