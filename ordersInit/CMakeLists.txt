file(GLOB SOURCES *.cpp)
add_library(ordersInit ${SOURCES})
target_include_directories(ordersInit PUBLIC ..)
target_link_libraries(ordersInit usersInit)
