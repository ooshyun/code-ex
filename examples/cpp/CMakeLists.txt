# TODO(oohyun): TBD, compile all of third party libraries
# Currently it is for macOS arm64/x86_64

# add third party, spdlog
include(${CMAKE_SOURCE_DIR}/examples/cpp/third_party/spdlog.cmake)

# # easy_profiler
# include(${CMAKE_SOURCE_DIR}/examples/cpp/third_party/easy_profiler.cmake)

# Aggregate the sources
file(GLOB SRC_FILES
     "${CMAKE_CURRENT_SOURCE_DIR}/Src/data-structure/*.cc"
     "${CMAKE_CURRENT_SOURCE_DIR}/Src/data-structure/recursion/*.cc"
     "${CMAKE_CURRENT_SOURCE_DIR}/Src/cpp-functions/*.cc"
     "${CMAKE_CURRENT_SOURCE_DIR}/Src/cpp-functions/*.c"
     "${CMAKE_CURRENT_SOURCE_DIR}/Src/cpp-functions/thread/*.cc"
     "${CMAKE_CURRENT_SOURCE_DIR}/Src/cpp-functions/rvalue/*.cc"
     "${CMAKE_CURRENT_SOURCE_DIR}/Src/cpp-functions/function/*.cc"
     "${CMAKE_CURRENT_SOURCE_DIR}/Src/c-functions/*.c"
     "${CMAKE_CURRENT_SOURCE_DIR}/Src/c-functions/static_func/*.c"
     "${CMAKE_CURRENT_SOURCE_DIR}/Src/algorithm/*.c"
     "${CMAKE_CURRENT_SOURCE_DIR}/Src/algorithm/*.cc"
     "${CMAKE_CURRENT_SOURCE_DIR}/Src/design-pattern/*.cc"
     "${CMAKE_CURRENT_SOURCE_DIR}/Src/design-pattern/*.c"
     "${CMAKE_CURRENT_SOURCE_DIR}/Src/utils/*.cc"
     "${CMAKE_CURRENT_SOURCE_DIR}/Src/third-party/*.cc"
     "${CMAKE_CURRENT_SOURCE_DIR}/Src/third-party/curl/*.cc"
    #  "${CMAKE_CURRENT_SOURCE_DIR}/Src/third-party/easy_profiler/*.cc"
     "${CMAKE_CURRENT_SOURCE_DIR}/Src/third-party/std/*.cc"
     "${CMAKE_CURRENT_SOURCE_DIR}/Src/third-party/std/chronos/*.cc"
    #  "${CMAKE_CURRENT_SOURCE_DIR}/Src/third-party/std/filesystem/*.cc"
     "${CMAKE_CURRENT_SOURCE_DIR}/Src/boost/property_tree/*.cc"
     "${CMAKE_CURRENT_SOURCE_DIR}/Src/spdlog/*.cc"
     )
set(SOURCES "${SRC_FILES}")

# print sources
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message("--SOURCES--")
foreach(SRC ${SOURCES})
  message(${SRC})
endforeach()
message("-----------")

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
  message("Linux build")
else()
if (CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
  set(ROOT_LIB "/opt/homebrew/Cellar/")
else()
  set(ROOT_LIB "/usr/local/opt/")
  set(x86_64_LIB ON)
endif()
endif()

message("ROOT_LIB ${ROOT_LIB}")

# installation: brew
find_package(fmt REQUIRED)

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
find_package(Boost 1.65.1 REQUIRED COMPONENTS system chrono thread filesystem atomic)

else()
find_package(boost)
if(NOT boost_FOUND)
  message("boost not found")
  if (x86_64_LIB)
    set(libboost
      ${ROOT_LIB}/boost/lib/libboost_filesystem.a
      ${ROOT_LIB}/boost/lib/libboost_system-mt.a
      ${ROOT_LIB}/boost/lib/libboost_thread-mt.a
      ${ROOT_LIB}/boost/lib/libboost_chrono.a
      ${ROOT_LIB}/boost/lib/libboost_atomic-mt.a
      )
  else()
    set(libboost 
      ${ROOT_LIB}/boost/1.84.0_1/lib/libboost_filesystem.a
      ${ROOT_LIB}/boost/1.84.0_1/lib/libboost_system-mt.a
      ${ROOT_LIB}/boost/1.84.0_1/lib/libboost_thread-mt.a
      ${ROOT_LIB}/boost/1.84.0_1/lib/libboost_chrono.a
      ${ROOT_LIB}/boost/1.84.0_1/lib/libboost_atomic-mt.a
    )
  endif()
endif()

find_package(curl)
if(NOT curl_FOUND)
  message("curl not found")
  if (x86_64_LIB)
    set(libcurl ${ROOT_LIB}/curl/lib/libcurl.a)
  else()
    set(libcurl ${ROOT_LIB}/curl/8.7.1/lib/libcurl.a)
  endif()
endif()

# set(libspdlog ${ROOT_LIB}/spdlog/1.12.0/lib/libspdlog.a)
# set(libspdlog ${ROOT_LIB}/spdlog/lib/libspdlog.a)
if (x86_64_LIB)
  set(libspdlog ${ROOT_LIB}/spdlog/lib/libspdlog.1.13.0.dylib)
else()
  set(libspdlog ${ROOT_LIB}/spdlog/1.13.0/lib/libspdlog.1.13.0.dylib)
endif()

find_package(openssl)
if(NOT openssl_FOUND)
  message("openssl not found")
  if (x86_64_LIB)
    set(libcrypto ${ROOT_LIB}/openssl@1.1/lib/libcrypto.a)
    set(libssl ${ROOT_LIB}/openssl@1.1/lib/libssl.a)
  else()
    set(libcrypto ${ROOT_LIB}/openssl@1.1/1.1.1w/lib/libcrypto.a)
    set(libssl ${ROOT_LIB}/openssl@1.1/1.1.1w/lib/libssl.a)
  endif()
endif()

if (x86_64_LIB)
  set (libfmt ${ROOT_LIB}/fmt/lib/libfmt.a)
else()
  set (libfmt ${ROOT_LIB}/fmt/10.2.1_1/lib/libfmt.a)
endif()

endif()  # (CMAKE_SYSTEM_NAME MATCHES "Linux")

add_library(ccex ${SOURCES})
target_compile_options(ccex 
PRIVATE
  -Wall                # enable all warnings
  # -Wextra              # enable extra warnings
  # -pedantic            # enforce strict ANSI/ISO compliance
  -O0                  # enable optimization
  # -g                   # enable debugging symbols
  # -c                   # generate object files only
  # -S                   # generate assembly language output
  # -save-temps
  # -masm=intel          # use Intel syntax for assembly output
)

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
  target_include_directories(ccex
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Inc
    ${PROJECT_SOURCE_DIR}/examples/cpp/third_party/tensorflow
    ${PROJECT_SOURCE_DIR}/examples/cpp/third_party/flatbuffers/include
    ${PROJECT_SOURCE_DIR}/examples/cpp/third_party/spdlog/include
    ${PROJECT_SOURCE_DIR}/examples/cpp/third_party/jwt-cpp/include
    ${PROJECT_SOURCE_DIR}/examples/cpp/third_party/curl/include
    ${PROJECT_SOURCE_DIR}/examples/cpp/third_party/openssl/include
    ${PROJECT_SOURCE_DIR}/examples/cpp/third_party/json/single_include
    ${PROJECT_SOURCE_DIR}/examples/cpp/third_party/fmt/include
    ${PROJECT_SOURCE_DIR}/examples/cpp/third_party/boost/include
    # ${PROJECT_SOURCE_DIR}/examples/cpp/third_party/easy_profiler/easy_profiler_core/include
  )  
  link_directories(${CMAKE_BINARY_DIR}/third_party/)
  target_link_libraries(ccex
  PUBLIC
    ${libboost}
    # ${libcurl}
    ${libspdlog}
    # ${libcrypto}
    # ${libssl}
    ${libfmt}
    # easy_profiler
  )
else()
if (x86_64_LIB)
  target_include_directories(ccex
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Inc
    ${ROOT_LIB}/boost/include
    ${ROOT_LIB}/nlohmann-json/include
    ${ROOT_LIB}/spdlog/include
    ${ROOT_LIB}/curl/include
    ${ROOT_LIB}/fmt/include # dependency of spdlog
    # ${PROJECT_SOURCE_DIR}/examples/cpp/third_party/easy_profiler/easy_profiler_core/include
    )
else()
  target_include_directories(ccex
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Inc
    ${ROOT_LIB}/boost/1.84.0_1/include
    ${ROOT_LIB}/nlohmann-json/3.11.2/include
    ${ROOT_LIB}/spdlog/1.13.0/include
    ${ROOT_LIB}/curl/8.7.1/include
    ${ROOT_LIB}/fmt/10.2.1_1/include # dependency of spdlog
    # ${PROJECT_SOURCE_DIR}/examples/cpp/third_party/easy_profiler/easy_profiler_core/include
  )
endif()

link_directories(${CMAKE_BINARY_DIR}/third_party/)
target_link_libraries(ccex
PUBLIC
  ${libboost}
  ${libcurl}
  ${libspdlog}
  ${libcrypto}
  ${libssl}
  ${libfmt}
  # easy_profiler
)
endif()

# add_dependencies(ccex libeasy_profiler)
add_executable(${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/Src/main.cc")

target_compile_options(${PROJECT_NAME}
PRIVATE
  -Wall                # enable all warnings
  # -Wextra              # enable extra warnings
  # -pedantic            # enforce strict ANSI/ISO compliance
  # -O3                  # enable optimization
  # -g                   # enable debugging symbols
  # -c                   # generate object files only
  # -S                   # generate assembly language output
  # -save-temps
  # -masm=intel          # use Intel syntax for assembly output
)

# target_include_directories(${PROJECT_NAME}
# PUBLIC
#   ${CMAKE_CURRENT_SOURCE_DIR}/Inc
#   ${PROJECT_SOURCE_DIR}/examples/cpp/third_party/easy_profiler/easy_profiler_core/include
# )

target_link_libraries(${PROJECT_NAME} PUBLIC ccex)

# if without easy_profiler, add below
# target_compile_definitions(ccex PRIVATE BUILD_WITH_EASY_PROFILER)
# target_compile_definitions(ccex PRIVATE DISABLE_EASY_PROFILER)


get_target_property(MAIN_CFLAGS ccex COMPILE_OPTIONS)
# also see: COMPILE_DEFINITIONS INCLUDE_DIRECTORIES
message(STATUS "Target ccex compiler flags are: ${MAIN_CFLAGS}")


get_target_property(MAIN_CFLAGS ${PROJECT_NAME} COMPILE_OPTIONS)
message(STATUS "Target ${PROJECT_NAME} compiler flags are: ${MAIN_CFLAGS}")

# install(TARGETS ${PROJECT_NAME} DESTINATION /usr/local/lib)
# install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/sense DESTINATION /usr/local/include)
# install(DIRECTORY ${PROJECT_SOURCE_DIR}/third_party/spdlog/include/spdlog DESTINATION /usr/local/include)
# install(DIRECTORY ${PROJECT_SOURCE_DIR}/third_party/tensorflow/tensorflow DESTINATION /usr/local/include)
# install(TARGETS sense-core DESTINATION /usr/local/lib)
# install(DIRECTORY ${PROJECT_SOURCE_DIR}/third_party/spdlog/include/spdlog DESTINATION /usr/local/include)