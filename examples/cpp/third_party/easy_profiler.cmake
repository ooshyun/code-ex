add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/third_party/libeasy_profiler.dylib
  COMMAND mkdir -p ${CMAKE_BINARY_DIR}/third_party
  COMMAND mkdir -p ${CMAKE_CURRENT_LIST_DIR}/easy_profiler/build
  COMMAND cd build && cmake -DCMAKE_BUILD_TYPE=Release ..
  COMMAND cd build && make
  COMMAND cp `find ${CMAKE_CURRENT_LIST_DIR}/easy_profiler -name '*.dylib'` ${CMAKE_BINARY_DIR}/third_party/
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/easy_profiler
)

add_custom_target(libeasy_profiler DEPENDS ${CMAKE_BINARY_DIR}/third_party/libeasy_profiler.dylib)