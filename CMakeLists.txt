CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(mytest 
./unit_tests/unit_test.cpp)


ADD_EXECUTABLE(rshell
./src/RShell.cpp)

TARGET_LINK_LIBRARIES(mytest gtest)
TARGET_COMPILE_DEFINITIONS(mytest PRIVATE gtest_disable_pthreads=ON)
