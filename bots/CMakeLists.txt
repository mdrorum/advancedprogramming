cmake_minimum_required (VERSION 2.6)

project (bots)

Find_Package ( SDL REQUIRED )



include_directories(${SDL_INCLUDE_DIR})

add_executable(bots playground.cpp bots.cpp)

target_link_libraries(bots ${SDL_LIBRARY})
