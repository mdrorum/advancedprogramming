cmake_minimum_required (VERSION 2.6)

project (lecture12)

add_definitions(-std=c++11)

# require unit_test from boost
find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

# first you have to compile the test file (as an executable in this case)
add_executable(test_boost test_boost.cpp)
target_link_libraries(test_boost ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

enable_testing()

# make the name of the test match the name you give to your test in boost
#add_test(test_not_equals test_boost)
#add_test(test_not_equals test_boost)
add_test(test test_boost)
#add_test(test_naive test_boost)

