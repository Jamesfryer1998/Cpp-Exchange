if(EXISTS "/Users/james/Projects/exchange/build/tests/test-exchangeInit[1]_tests.cmake")
  include("/Users/james/Projects/exchange/build/tests/test-exchangeInit[1]_tests.cmake")
else()
  add_test(test-exchangeInit_NOT_BUILT test-exchangeInit_NOT_BUILT)
endif()
