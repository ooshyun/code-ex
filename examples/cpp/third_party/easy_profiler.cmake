# BUILD_WITH_EASY_PROFILER is already defined in CMakeLists.txt of easy_profiler
# EASY_OPTION_LOG and EASY_OPTION_PRETTY_PRINT set to ON / OFF in CMakeLists.txt of easy_profiler
add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/third_party/libeasy_profiler.dylib
  COMMAND mkdir -p ${CMAKE_BINARY_DIR}/third_party
  COMMAND mkdir -p ${CMAKE_CURRENT_LIST_DIR}/easy_profiler/build
  COMMAND cd build && cmake -DCMAKE_BUILD_TYPE=Release ..
  COMMAND cd build && make
  # COMMAND cp `find ${CMAKE_CURRENT_LIST_DIR}/easy_profiler -name '*.dylib'` ${CMAKE_BINARY_DIR}/third_party/
  COMMAND cp ${CMAKE_CURRENT_LIST_DIR}/easy_profiler/build/bin/* ${CMAKE_BINARY_DIR}/third_party/
  COMMAND export EASY_PROFILER_PATH=${CMAKE_BINARY_DIR}/third_party
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/easy_profiler
)

add_custom_target(libeasy_profiler DEPENDS ${CMAKE_BINARY_DIR}/third_party/libeasy_profiler.dylib)