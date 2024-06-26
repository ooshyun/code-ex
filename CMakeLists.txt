cmake_minimum_required(VERSION 3.0.0)
project(cppexample VERSION 0.1.0)

enable_testing()

message(STATUS "CMAKE_OSX_ARCHITECTURES: ${CMAKE_OSX_ARCHITECTURES}")
message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_SYSTEM_PROCESSOR: ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")

## TODO: Anlayze the following code
# # specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_C_COMPILER_FORCED TRUE)
set(CMAKE_VERBOSE_MAKEFILE ON)  # --verbose

# # define target paths
set(TARGET_ROOT_DIR ${PROJECT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE})
set(EXECUTABLE_OUTPUT_PATH ${TARGET_ROOT_DIR}/bin)

message(STATUS "TARGET_ROOT_DIR: ${TARGET_ROOT_DIR}")
message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")

option(BUILD_TESTS "Build all tests." OFF)
# TODO(oohyun): TBD, after learning how to use it
# Current error is finding gtestxx library and header files
if (BUILD_TESTS)
  # include(FetchContent)
  # FetchContent_Declare(
  #   googletest
  #   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  # )
  # # For Windows: Prevent overriding the parent project's compiler/linker settings
  # set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  # FetchContent_MakeAvailable(googletest)

  # if (APPLE)
  #   add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
  #   add_definitions(-D__GLIBCXX__)
  # endif (APPLE)

  # # This adds another subdirectory, which has 'project(gtest)'.
  # add_subdirectory(examples/cpp/third_party/googletest)

  # enable_testing()

  # # Include the gtest library. gtest_SOURCE_DIR is available due to
  # # 'project(gtest)' above.
  # include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

  # set(GTEST_LIBRARIES gtest gtest_main gmock gmock_main)
  # include(cmake/code-coverage.cmake)
  # add_subdirectory(tests)
endif()


# # add coding-test
add_subdirectory(examples/cpp)

