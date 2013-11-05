cmake_minimum_required (VERSION 2.6)

project (lecture6)

# remember to enable c++11!!!
add_definitions(-std=c++11)

add_executable(threads threads.cpp)

# threading requires a library
target_link_libraries(threads pthread)

find_package(MPI REQUIRED)

# doesn't break anything, it actually uses g++...
SET(CMAKE_CXX_COMPILER mpicxx)
add_executable(mpi_test mpi_test.cpp)
target_link_libraries(mpi_test mpi)
