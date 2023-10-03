file(GLOB SOURCES *.cpp)
add_executable(exchange-app ${SOURCES})

target_link_libraries(exchange-app ordersInit exchangeInit usersInit run interface)