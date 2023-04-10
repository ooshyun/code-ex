args=$1

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
    cmake ./../CMakeLists.txt
    make
    cd ..
    echo "Rebuilt project"
else
    if [ ! -d "$build" ]; then
        mkdir $build
    fi
    cd ./build
    cmake ./../CMakeLists.txt
    make
    cd ..
    echo "Built project"
fi

