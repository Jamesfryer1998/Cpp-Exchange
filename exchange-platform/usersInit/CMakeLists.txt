file(GLOB SOURCES *.cpp)
add_library(usersInit ${SOURCES})
target_include_directories(usersInit PUBLIC ..)