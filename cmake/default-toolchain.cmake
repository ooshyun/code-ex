# set(CMAKE_OSX_ARCHITECTURES x86_64)
set(CMAKE_OSX_ARCHITECTURES arm64)

# set(CMAKE_CXX_COMPILER /opt/homebrew/opt/llvm/bin/clang++)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
# set(CMAKE_CXX_COMPILER /usr/bin/g++)

# SET(CMAKE_C_COMPILER "/usr/bin/aarch64-linux-gnu-gcc")
# set(CMAKE_CXX_COMPILER "/usr/bin/aarch64-linux-gnu-g++")
# SET(CMAKE_C_COMPILER "/usr/bin/arm-linux-gnueabihf-gcc")
# set(CMAKE_CXX_COMPILER "/usr/bin/arm-linux-gnueabihf-g++")

# set(CROSS_PREFIX "aarch64-linux-gnu")
# set(CROSS_PREFIX "arm-linux-gnueabihf")

# set(CMAKE_SYSTEM_NAME "Linux")

set(CMAKE_SYSTEM_PROCESSOR "arm64")
# set(CMAKE_SYSTEM_PROCESSOR "x86_64")
# set(CMAKE_SYSTEM_PROCESSOR "aarch64")
# set(CMAKE_SYSTEM_PROCESSOR "armv7")

set(BUILD_TESTS ON)