cmake_minimum_required(VERSION 3.13)
project(CPythonTest)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -I/usr/include/python3.5")

add_executable(CPythonTest main.cpp Trainer.cpp Trainer.h API.cpp API.h)

set(PYTHON_EXECUTABLE "/usr/bin/python3.5")
set(PYTHON_INCLUDE_DIR "/usr/include/python3.5m")
set(PYTHON_LIBRARIES "/usr/lib/x86_64-linux-gnu/libpython3.5m.so")

include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(${PYTHON_DIRECTORIES})
target_link_libraries(CPythonTest ${PYTHON_LIBRARIES})