include(GoogleTest)

include(FetchContent)
FetchContent_Declare(
  fuzztest
  GIT_REPOSITORY https://github.com/google/fuzztest.git
  GIT_TAG        origin/main
)
FetchContent_MakeAvailable(fuzztest)

SET(TEST_SRC_FILES
  test_resource.cc
)

foreach(_test_file ${TEST_SRC_FILES})
    get_filename_component(_test_name ${_test_file} NAME_WE)
    add_executable(${_test_name} ${_test_file})
    target_link_libraries(${_test_name} PRIVATE app_lib)
    link_fuzztest(${_test_name})
    gtest_discover_tests(${_test_name} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTIES TIMEOUT 50)
endforeach()