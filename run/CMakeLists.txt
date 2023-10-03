file(GLOB SOURCES *.cpp)
add_library(run ${SOURCES})
target_include_directories(run PUBLIC ..)