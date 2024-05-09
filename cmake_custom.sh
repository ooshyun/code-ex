args=$1

workspaceFolder=$(pwd)
build="build"
clean="clean"
rebuild="rebuild"

if [ "$args" == "$clean" ]; then
    sudo rm -rf build/**
    echo "Cleaned build directory"
elif [ "$args" == "$rebuild" ]; then
    sudo rm -rf build/**
    echo "Cleaned build directory"
    cd ./build
    cmake ./../CMakeLists.txt \
        # -DCMAKE_CXX_COMPILER="/usr/bin/clang++" \
        # -DCMAKE_BUILD_TYPE=${command:cmake.buildType} \
        -DCMAKE_TOOLCHAIN_FILE="${workspaceFolder}/cmake/default-toolchain.cmake" \
        # -DCMAKE_VERBOSE_MAKEFILE:BOOL="ON"
    make 
    cd ..
    echo "Rebuilt project"
else
    if [ ! -d "$build" ]; then
        mkdir $build
    fi
    cd ./build
    cmake ./../CMakeLists.txt \
        # -DCMAKE_CXX_COMPILER="/usr/bin/clang++" \
        # -DCMAKE_BUILD_TYPE=${command:cmake.buildType} \
        -DCMAKE_TOOLCHAIN_FILE="${workspaceFolder}/cmake/default-toolchain.cmake" \
        # -DCMAKE_VERBOSE_MAKEFILE:BOOL="ON"
    make
    cd ..
    echo "Built project"
fi


# ./build/bin/coding-test
