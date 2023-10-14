cmake -DCMAKE_BUILD_TYPE=${command:cmake.buildType} \
    .. \
    -DCMAKE_TOOLCHAIN_FILE=../cmake/default-toolchain.cmake \
    -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON


cmake -DCMAKE_BUILD_TYPE=Release \
    .. \
    -DCMAKE_TOOLCHAIN_FILE=../cmake/default-toolchain.cmake \
    -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON


cmake -DCMAKE_BUILD_TYPE=Debug \
    .. \
    -DCMAKE_TOOLCHAIN_FILE=../cmake/default-toolchain.cmake \
    -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON