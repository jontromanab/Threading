cmake_minimum_required(VERSION 2.8)

#if(CMAKE_COMPILER_IS_GNUCXX)
    #add_definitions(-std=gnu++11)
#endif()

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")
#add_compile_options(-std=gnu++11)

project(Threading)



add_executable(introduction src/introduction.cpp)
add_executable(thread_management src/thread_management.cpp)
add_executable(race_condition_mutex src/race_condition_and_mutex.cpp)
add_executable(deadlock src/deadlock.cpp)
add_executable(unique src/unique_lock_and_lazy_initialization.cpp)
