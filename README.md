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
git submodule add git@github.com:yse/easy_profiler.git ./examples/cpp/third_party/easy_profiler;
```

### After
git submodule update --init --recursive


## Easy profiler
It should define BUILD_WITH_EASY_PROFILER in linking library. For example, we compile the library named ccex, then
target_compile_definitions(ccex PRIVATE BUILD_WITH_EASY_PROFILER) in cmake and in opposite case which we did not want to use easy_profiler, we can define DISABLE_EASY_PROFILER(e.g. target_compile_definitions(ccex PRIVATE DISABLE_EASY_PROFILER))

EASY_THREAD
EASY_NONSCOPED_BLOCK
EASY_BLOCK
EASY_FUNCTION

EASY_VALUE
EASY_TEXT

### Getting Profiling through network


### Anaylsis (feat. profiler_gui)
- frame
- thread
- area (e.g. for loop)
- parent

- Begin, ms
- End, ms
- Time
- Self Time, Self%
- %, Min, Max, Avg, Mdn, N / frame, thread, area, parent
- WorkTime, Work%
- %/area
- Total/area, Total%/area


### File conversion
- profiler_gui: anaylize the .prof file
- profiler_converter /path/to/file.profiler: .json format output
    - it returns time (resolution: ns)