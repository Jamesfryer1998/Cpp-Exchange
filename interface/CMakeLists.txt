file(GLOB SOURCES *.cpp)
add_library(interface ${SOURCES})
target_include_directories(interface PUBLIC ..)