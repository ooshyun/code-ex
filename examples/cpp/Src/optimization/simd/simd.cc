/* SIMD (Time decrease to 50%)

    clang++ simd.cc 
    
    In https://stonzeteam.github.io/SIMD-병렬-프로그래밍/,
    it said the decrement of time is 75%. So I tested in MacOS M1 Pro.

    MacOS       : #include <simd/simd.h>
    Default     : #include <emmintrin.h>

    Additional Information:
    #  if defined __ARM_NEON__
    #   include <arm_neon.h>
    #  elif defined __i386__ || defined __x86_64__
    #   include <immintrin.h>
    #  endif

    Experiment Result
    ------------------------
    int16_tx4 max operation

    n = 1000000000

            SISD: 6587221 ms
    scratch SIMD: 5355864 ms
      macos SIMD: 3154652 ms

    n = 100000000

            SISD: 667674 ms
    scratch SIMD: 533453 ms
      macos SIMD: 313006 ms
            SIMD: 319435 ms

    more info: https://github.com/DLTcollab/sse2neon.git
*/

#include <iostream>
#include <stdio.h>
#include <chrono>

#include <simd/simd.h>

#if defined(__i386__) && defined(__x86_64__)
#include <immintrin.h>
#endif

using namespace std::chrono;

int main(void)
{
  int i = 0, j = 0;
  const int n = 1000000000;
  // const int n = 100000000;

  auto start = high_resolution_clock::now();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  int16_t result[8] __attribute__((aligned(16)));

  int16_t v1[8] __attribute__((aligned(16))) = {1, 2, 3, 4, 5, 6, 7, 8};
  int16_t v2[8] __attribute__((aligned(16))) = {8, 1, 7, 2, 6, 3, 5, 4};

  int64_t v1x64[2] __attribute__((aligned(16))) = {0};
  int64_t v2x64[2] __attribute__((aligned(16))) = {0};

  std::cout << "v1 : ";
  for (i = 0; i < 8; i++) {
    std::cout << v1[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "v2 : ";
  for (i = 0; i < 8; i++) {
    std::cout << v2[i] << " ";
  }
  std::cout << std::endl;

  // Load scratch SIMD
  j = 0;
  for (i = 0; i < 2; i++) {
    v1x64[i] = ((v1[j + 3] & 0xFFFFFFFFFFFFFFFF) << 48) |
               ((v1[j + 2] & 0xFFFFFFFFFFFFFFFF) << 32) |
               ((v1[j + 1] & 0xFFFFFFFFFFFFFFFF) << 16) |
               (v1[j] & 0xFFFFFFFFFFFFFFFF);
    v2x64[i] = ((v2[j + 3] & 0xFFFFFFFFFFFFFFFF) << 48) |
               ((v2[j + 2] & 0xFFFFFFFFFFFFFFFF) << 32) |
               ((v2[j + 1] & 0xFFFFFFFFFFFFFFFF) << 16) |
               (v2[j] & 0xFFFFFFFFFFFFFFFF);
    j += 4;
  }

  // Blog
  // __m128i a, b, r;

  // SIMD for MacOS
  simd_short8 a, b, r;

#if defined(__i386__) && defined(__x86_64__)
  // SIMD
  __m128i asim, bsim, rsim;
#endif

  // 1. SISD
  start = high_resolution_clock::now();
  for (i = 0; i < n; ++i)
  {
    result[0] = v1[0] > v2[0] ? v1[0] : v2[0];
    result[1] = v1[1] > v2[1] ? v1[1] : v2[1];
    result[2] = v1[2] > v2[2] ? v1[2] : v2[2];
    result[3] = v1[3] > v2[3] ? v1[3] : v2[3];
    result[4] = v1[4] > v2[4] ? v1[4] : v2[4];
    result[5] = v1[5] > v2[5] ? v1[5] : v2[5];
    result[6] = v1[6] > v2[6] ? v1[6] : v2[6];
    result[7] = v1[7] > v2[7] ? v1[7] : v2[7];
  }
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  std::cout << "SISD Time taken by function: "
            << duration.count() << " ms" << std::endl;

  std::cout << "SISD Result : ";
  for (i = 0; i < 8; i++) {
    std::cout << result[i] << " ";
  }
  std::cout << std::endl;

  // 2. scratch SIMD
  start = high_resolution_clock::now();
  for (i = 0; i < n; ++i) {
    result[0] = ((v1x64[0]) & 0xFFFF) > ((v2x64[0]) & 0xFFFF) ?
        (v1x64[0] & 0xFFFF) : (v2x64[0] & 0xFFFF);
    result[1] = ((v1x64[0] >> 16) & 0xFFFF) > ((v2x64[0] >> 16) & 0xFFFF) ?
        ((v1x64[0] >> 16) & 0xFFFF) : ((v2x64[0] >> 16) & 0xFFFF);
    result[2] = ((v1x64[0] >> 32) & 0xFFFF) > ((v2x64[0] >> 32) & 0xFFFF) ?
        ((v1x64[0] >> 32) & 0xFFFF) : ((v2x64[0] >> 32) & 0xFFFF);
    result[3] = ((v1x64[0] >> 48) & 0xFFFF) > ((v2x64[0] >> 48) & 0xFFFF) ?
        ((v1x64[0] >> 48) & 0xFFFF) : ((v2x64[0] >> 48) & 0xFFFF);

    result[4] = ((v1x64[1]) & 0xFFFF) > ((v2x64[1]) & 0xFFFF) ?
        (v1x64[1] & 0xFFFF) : (v2x64[1] & 0xFFFF);
    result[5] = ((v1x64[1] >> 16) & 0xFFFF) > ((v2x64[1] >> 16) & 0xFFFF) ?
        ((v1x64[1] >> 16) & 0xFFFF) : ((v2x64[1] >> 16) & 0xFFFF);
    result[6] = ((v1x64[1] >> 32) & 0xFFFF) > ((v2x64[1] >> 32) & 0xFFFF) ?
        ((v1x64[1] >> 32) & 0xFFFF) : ((v2x64[1] >> 32) & 0xFFFF);
    result[7] = ((v1x64[1] >> 48) & 0xFFFF) > ((v2x64[1] >> 48) & 0xFFFF) ?
        ((v1x64[1] >> 48) & 0xFFFF) : ((v2x64[1] >> 48) & 0xFFFF);
  }

  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  std::cout << "Scratch SIMD Time taken by function: "
            << duration.count() << " ms" << std::endl;
  std::cout << "Scratch SIMD Result : ";
  for (i = 0; i < 8; i++) {
    std::cout << result[i] << " ";
  }
  std::cout << std::endl;

  // 3. SIMD
  // 3.1 macos simd library
  start = high_resolution_clock::now();
  for (int i = 0; i < n; ++i) {
    a = simd_make_short8(*(simd_packed_short8 *)v1);
    b = simd_make_short8(*(simd_packed_short8 *)v2);
    r = simd_max(a, b);
    *(simd_packed_short8 *)result = r;
  }
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  std::cout << "MacOS SIMD Time taken by function: "
            << duration.count() << " ms" << std::endl;
  std::cout << "MacOS SIMD Result : ";
  for (i = 0; i < 8; i++) {
    std::cout << result[i] << " ";
  }
  std::cout << std::endl;

  // 3.2 simd library
#if defined(__i386__) && defined(__x86_64__)
  start = high_resolution_clock::now();
  for (int i = 0; i < n; ++i) {
    asim = _mm_loadu_si128((__m128i *)v1);
    bsim = _mm_loadu_si128((__m128i *)v2);
    rsim = _mm_max_epi16(asim, bsim);
    // _mm_store_si128((__m128i *)result, rsim);
    _mm_storeu_si128((__m128i *)result, rsim);
  }
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  std::cout << "SIMD Time taken by function: "
            << duration.count() << " ms" << std::endl;
  std::cout << "SIMD Result : ";
  for (i = 0; i < 8; i++) {
    std::cout << result[i] << " ";
  }
  std::cout << std::endl;
#endif
  // _mm_max_sd
}
