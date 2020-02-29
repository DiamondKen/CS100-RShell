CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(unittest 
./unit_test/unit_test.cpp)


ADD_EXECUTABLE(rshell
./src/RShell.cpp)

TARGET_LINK_LIBRARIES(unittest gtest)
TARGET_COMPILE_DEFINITIONS(unittest PRIVATE gtest_disable_pthreads=ON)