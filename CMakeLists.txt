cmake_minimum_required(VERSION 3.17)
project(ACLIBSharedMemory)


set(CMAKE_CXX_STANDARD 11)

# AC uses python 3.3
# Requires msvc++ 10.0
# find_package(PythonLibs 3.3 EXACT REQUIRED)
find_package(PythonLibs REQUIRED)

include_directories(
        source/
        ${PYTHON_INCLUDE_DIRS})

set(SOURCES

        source/AC.hpp
        source/ACLIB.hpp
        source/SharedMemory.hpp
        source/EventLoop.cpp
        source/EventLoop.hpp

        source/python/ACLIBSharedMemory.cpp
        source/python/PyPhysics.cpp
        source/python/PyPhysics.hpp
        source/python/PyGraphics.cpp
        source/python/PyGraphics.hpp
        source/python/PyStatics.cpp
        source/python/PyStatics.hpp
        source/python/PyEventLoop.cpp
        source/python/PyEventLoop.hpp)

# The module
add_library(ACLIBSharedMemory
        ${SOURCES}
        ${PYTHON_LIBRARIES})
target_link_libraries(ACLIBSharedMemory ${PYTHON_LIBRARIES})
