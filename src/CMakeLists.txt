cmake_minimum_required (VERSION 3.10.0)
project (TrainingProject)
set(CMAKE_CXX_STANDARD 11)

find_package(Threads)

file(GLOB_RECURSE SOURCE_FILES
    common/*.cpp
    interface/*.cpp
    manager/*.cpp
    service/*.cpp
)

file(GLOB_RECURSE HEADER_FILES
    common/*.h
    interface/*.h
    manager/*.h
    service/*.h
)

include_directories(
    ./
)

add_executable(main main.cpp ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(main pthread)
