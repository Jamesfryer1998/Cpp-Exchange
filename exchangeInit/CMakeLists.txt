file(GLOB SOURCES *.cpp)
add_library(exchangeInit ${SOURCES})
target_include_directories(exchangeInit PUBLIC ..)