# Code Practice for Programming Languages

- Programming Language
  - C
  - C++
  - Python
  - CMake

## Add Submodule
### Add
```bash
git submodule add git@github.com:tensorflow/tensorflow.git ./examples/cpp/third_party/tensorflow;
git submodule add git@github.com:google/flatbuffers.git ./examples/cpp/third_party/flatbuffer;
git submodule add git@github.com:gabime/spdlog.git ./examples/cpp/third_party/spdlog;
git submodule add git@github.com:nlohmann/json.git ./examples/cpp/third_party/jso;
git submodule add git@github.com:curl/curl.git ./examples/cpp/third_party/cur;
git submodule add git@github.com:openssl/openssl.git ./examples/cpp/third_party/opens;
git submodule add git@github.com:Thalhammer/jwt-cpp.git ./examples/cpp/third_party/jwt-cp;
git submodule add git@github.com:madler/zlib.git ./examples/cpp/third_party/zlib;
git submodule add git@github.com:google/googletest.git ./examples/cpp/third_party/googletest;
```

### After
git submodule update --init --recursive
