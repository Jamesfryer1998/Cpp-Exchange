file(GLOB SOURCES *.cpp)
add_library(ordersInit ${SOURCES})
target_include_directories(ordersInit PUBLIC ..)