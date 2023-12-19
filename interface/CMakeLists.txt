file(GLOB SOURCES *.cpp)
add_library(interface ${SOURCES})
target_include_directories(interface PUBLIC ..)
target_link_libraries(interface ordersInit)
target_link_libraries(interface exchangeInit)
target_link_libraries(interface usersInit)

