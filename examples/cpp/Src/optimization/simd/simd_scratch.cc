/* scratch SIMD using bit masking (Time decrease to 10%)

    clang++ simd_scratch.cc

    The main point scratch SIMD is to save multiple values in big register. For example,
    int16_t variable can save into int64_t as much as 4. In this case, we can easily do computation such as
    matrix multiplication, division, comparision, and so on using "swift". It seems like bitwise masking, so
    I tested two parts.

    The first part is using shifting, and the second part is using simd library.

    In this simd_scratch, it contains experiments using shift operation.

    For our information, In Hifi with Xtensa platform, it provide multiple calculation
    if we allocation values as being adjacnet in array. For example, if array for Foureir Transform is as below,

        [real_0, imag_0, real_1, imag_1, ...]

    The platform provide specific instruction for calculate both varible real_n, imag_n.

    Experiment Result
    ------------------------
    1. n = 100000000

                SISD:  661270 ms

        scratch SIMD:  534496 ms

    2. n = 1000000000

                SISD: 6586325 ms

        scratch SIMD: 5363294 ms

    While using shift, it needs to be careful for three thing

        1. load
        2. casting
        3. the number of shift

    These variables are depending on a situation, so be thinkful!
*/

#include <iostream>
#include <stdio.h>
#include <chrono>
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

  int64_t v1buf, v2buf;
  int16_t *ptrV1x64;
  int16_t *ptrV2x64;

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
  start = high_resolution_clock::now();
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
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  std::cout << "SIMD Loading Time: "
            << duration.count() << " ms" << std::endl;

  std::cout << "64bit v1 : ";
  for (i = 0; i < 2; i++) {
    std::cout << int16_t(v1x64[i] & 0x000000000000FFFF) << " "
              << int16_t((v1x64[i] >> 16) & 0x000000000000FFFF) << " "
              << int16_t((v1x64[i] >> 32) & 0x000000000000FFFF) << " "
              << int16_t((v1x64[i] >> 48) & 0x000000000000FFFF) << " ";
  }
  std::cout << std::endl;

  // SISD
  start = high_resolution_clock::now();
  for (i = 0; i < n; ++i) {
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

  start = high_resolution_clock::now();

  // scratch SIMD

  // // n=100000000, 690031 ms
  // for (i = 0; i < n; ++i) {
  //     result[0] = (v1x64[0] & 0x000000000000FFFF) > (v2x64[0] & 0x000000000000FFFF) ? int16_t(v1x64[0]& 0x000000000000FFFF) : int16_t(v2x64[0]& 0x000000000000FFFF);
  //     result[1] = (v1x64[0] & 0x00000000FFFF0000) > (v2x64[0] & 0x00000000FFFF0000) ? int16_t((v1x64[0]>>16)& 0x000000000000FFFF) : int16_t((v2x64[0]>>16)& 0x000000000000FFFF);
  //     result[2] = (v1x64[0] & 0x0000FFFF00000000) > (v2x64[0] & 0x0000FFFF00000000) ? int16_t((v1x64[0]>>32)& 0x000000000000FFFF) : int16_t((v2x64[0]>>32)& 0x000000000000FFFF);
  //     result[3] = (v1x64[0] & 0xFFFF000000000000) > (v2x64[0] & 0xFFFF000000000000) ? int16_t((v1x64[0]>>48)& 0x000000000000FFFF) : int16_t((v2x64[0]>>48)& 0x000000000000FFFF);

  //     result[4] = (v1x64[1] & 0x000000000000FFFF) > (v2x64[1] & 0x000000000000FFFF) ? int16_t(v1x64[1]& 0x000000000000FFFF) : int16_t(v2x64[1]& 0x000000000000FFFF);
  //     result[5] = (v1x64[1] & 0x00000000FFFF0000) > (v2x64[1] & 0x00000000FFFF0000) ? int16_t((v1x64[1]>>16)& 0x000000000000FFFF) : int16_t((v2x64[1]>>16)& 0x000000000000FFFF);
  //     result[6] = (v1x64[1] & 0x0000FFFF00000000) > (v2x64[1] & 0x0000FFFF00000000) ? int16_t((v1x64[1]>>32)& 0x000000000000FFFF) : int16_t((v2x64[1]>>32)& 0x000000000000FFFF);
  //     result[7] = (v1x64[1] & 0xFFFF000000000000) > (v2x64[1] & 0xFFFF000000000000) ? int16_t((v1x64[1]>>48)& 0x000000000000FFFF) : int16_t((v2x64[1]>>48)& 0x000000000000FFFF);
  // }

  // //  n=100000000, 624791 ms
  // for (i = 0; i < n; ++i) {
  //     v1buf = v1x64[0];
  //     v2buf = v2x64[0];
  //     result[0] = (v1buf & 0x000000000000FFFF) > (v2buf & 0x000000000000FFFF) ? int16_t(v1buf& 0x000000000000FFFF) : int16_t(v2buf& 0x000000000000FFFF);
  //     result[1] = (v1buf & 0x00000000FFFF0000) > (v2buf & 0x00000000FFFF0000) ? int16_t((v1buf>>16)& 0x000000000000FFFF) : int16_t((v2buf>>16)& 0x000000000000FFFF);
  //     result[2] = (v1buf & 0x0000FFFF00000000) > (v2buf & 0x0000FFFF00000000) ? int16_t((v1buf>>32)& 0x000000000000FFFF) : int16_t((v2buf>>32)& 0x000000000000FFFF);
  //     result[3] = (v1buf & 0xFFFF000000000000) > (v2buf & 0xFFFF000000000000) ? int16_t((v1buf>>48)& 0x000000000000FFFF) : int16_t((v2buf>>48)& 0x000000000000FFFF);

  //     v1buf = v1x64[1];
  //     v2buf = v2x64[1];
  //     result[4] = (v1buf & 0x000000000000FFFF) > (v2buf & 0x000000000000FFFF) ? int16_t(v1buf& 0x000000000000FFFF) : int16_t(v2buf& 0x000000000000FFFF);
  //     result[5] = (v1buf & 0x00000000FFFF0000) > (v2buf & 0x00000000FFFF0000) ? int16_t((v1buf>>16)& 0x000000000000FFFF) : int16_t((v2buf>>16)& 0x000000000000FFFF);
  //     result[6] = (v1buf & 0x0000FFFF00000000) > (v2buf & 0x0000FFFF00000000) ? int16_t((v1buf>>32)& 0x000000000000FFFF) : int16_t((v2buf>>32)& 0x000000000000FFFF);
  //     result[7] = (v1buf & 0xFFFF000000000000) > (v2buf & 0xFFFF000000000000) ? int16_t((v1buf>>48)& 0x000000000000FFFF) : int16_t((v2buf>>48)& 0x000000000000FFFF);
  // }

  // //  n=100000000, 754714 ms (!?)
  // for (i = 0; i < n; ++i) {
  //     ptrV1x64 = (int16_t*)&v1x64[0];
  //     ptrV2x64 = (int16_t*)&v2x64[0];
  //     result[0] = ptrV1x64[0] > ptrV2x64[0] ? ptrV1x64[0] : ptrV2x64[0];
  //     result[1] = ptrV1x64[1] > ptrV2x64[1] ? ptrV1x64[1] : ptrV2x64[1];
  //     result[2] = ptrV1x64[2] > ptrV2x64[2] ? ptrV1x64[2] : ptrV2x64[2];
  //     result[3] = ptrV1x64[3] > ptrV2x64[3] ? ptrV1x64[3] : ptrV2x64[3];
  //     result[4] = ptrV1x64[4] > ptrV2x64[4] ? ptrV1x64[4] : ptrV2x64[4];
  //     result[5] = ptrV1x64[5] > ptrV2x64[5] ? ptrV1x64[5] : ptrV2x64[5];
  //     result[6] = ptrV1x64[6] > ptrV2x64[6] ? ptrV1x64[6] : ptrV2x64[6];
  //     result[7] = ptrV1x64[7] > ptrV2x64[7] ? ptrV1x64[7] : ptrV2x64[7];
  // }

  // //  n=100000000, 662033 ms
  // for (i = 0; i < n; ++i) {
  //     result[0] = ((v1x64[0])& 0xFFFF) > ((v2x64[0])& 0xFFFF) ? static_cast<int16_t>(v1x64[0]& 0xFFFF) : static_cast<int16_t>(v2x64[0]& 0xFFFF);
  //     result[1] = ((v1x64[0]>>16)& 0xFFFF) > ((v2x64[0]>>16)& 0xFFFF) ? static_cast<int16_t>((v1x64[0]>>16)& 0xFFFF) : static_cast<int16_t>((v2x64[0]>>16)& 0xFFFF);
  //     result[2] = ((v1x64[0]>>32)& 0xFFFF) > ((v2x64[0]>>32)& 0xFFFF) ? static_cast<int16_t>((v1x64[0]>>32)& 0xFFFF) : static_cast<int16_t>((v2x64[0]>>32)& 0xFFFF);
  //     result[3] = ((v1x64[0]>>48)& 0xFFFF) > ((v2x64[0]>>48)& 0xFFFF) ? static_cast<int16_t>((v1x64[0]>>48)& 0xFFFF) : static_cast<int16_t>((v2x64[0]>>48)& 0xFFFF);

  //     result[4] = ((v1x64[1])& 0xFFFF) > ((v2x64[1])& 0xFFFF) ? static_cast<int16_t>(v1x64[1]& 0xFFFF) : static_cast<int16_t>(v2x64[1]& 0xFFFF);
  //     result[5] = ((v1x64[1]>>16)& 0xFFFF) > ((v2x64[1]>>16)& 0xFFFF) ? static_cast<int16_t>((v1x64[1]>>16)& 0xFFFF) : static_cast<int16_t>((v2x64[1]>>16)& 0xFFFF);
  //     result[6] = ((v1x64[1]>>32)& 0xFFFF) > ((v2x64[1]>>32)& 0xFFFF) ? static_cast<int16_t>((v1x64[1]>>32)& 0xFFFF) : static_cast<int16_t>((v2x64[1]>>32)& 0xFFFF);
  //     result[7] = ((v1x64[1]>>48)& 0xFFFF) > ((v2x64[1]>>48)& 0xFFFF) ? static_cast<int16_t>((v1x64[1]>>48)& 0xFFFF) : static_cast<int16_t>((v2x64[1]>>48)& 0xFFFF);
  // }

  //  n=100000000, 534496 ms
  for (i = 0; i < n; ++i)
  {
    result[0] = ((v1x64[0]) & 0xFFFF) > ((v2x64[0]) & 0xFFFF) ? (v1x64[0] & 0xFFFF) : (v2x64[0] & 0xFFFF);
    result[1] = ((v1x64[0] >> 16) & 0xFFFF) > ((v2x64[0] >> 16) & 0xFFFF) ? ((v1x64[0] >> 16) & 0xFFFF) : ((v2x64[0] >> 16) & 0xFFFF);
    result[2] = ((v1x64[0] >> 32) & 0xFFFF) > ((v2x64[0] >> 32) & 0xFFFF) ? ((v1x64[0] >> 32) & 0xFFFF) : ((v2x64[0] >> 32) & 0xFFFF);
    result[3] = ((v1x64[0] >> 48) & 0xFFFF) > ((v2x64[0] >> 48) & 0xFFFF) ? ((v1x64[0] >> 48) & 0xFFFF) : ((v2x64[0] >> 48) & 0xFFFF);

    result[4] = ((v1x64[1]) & 0xFFFF) > ((v2x64[1]) & 0xFFFF) ? (v1x64[1] & 0xFFFF) : (v2x64[1] & 0xFFFF);
    result[5] = ((v1x64[1] >> 16) & 0xFFFF) > ((v2x64[1] >> 16) & 0xFFFF) ? ((v1x64[1] >> 16) & 0xFFFF) : ((v2x64[1] >> 16) & 0xFFFF);
    result[6] = ((v1x64[1] >> 32) & 0xFFFF) > ((v2x64[1] >> 32) & 0xFFFF) ? ((v1x64[1] >> 32) & 0xFFFF) : ((v2x64[1] >> 32) & 0xFFFF);
    result[7] = ((v1x64[1] >> 48) & 0xFFFF) > ((v2x64[1] >> 48) & 0xFFFF) ? ((v1x64[1] >> 48) & 0xFFFF) : ((v2x64[1] >> 48) & 0xFFFF);
  }

  // //  n=100000000, 768637 ms (!???)
  // for (i = 0; i < n; ++i) {
  //     v1buf = v1x64[0];
  //     v2buf = v2x64[0];
  //     result[0] = ((v1buf)& 0xFFFF) > ((v2buf)& 0xFFFF) ? (v1buf& 0xFFFF) : (v2buf& 0xFFFF);
  //     v1buf >>= 16;
  //     v2buf >>= 16;
  //     result[1] = ((v1buf)& 0xFFFF) > ((v2buf>>16)& 0xFFFF) ? ((v1buf)& 0xFFFF) : ((v2buf>>16)& 0xFFFF);
  //     v1buf >>= 16;
  //     v2buf >>= 16;
  //     result[2] = ((v1buf)& 0xFFFF) > ((v2buf)& 0xFFFF) ? ((v1buf)& 0xFFFF) : ((v2buf)& 0xFFFF);
  //     v1buf >>= 16;
  //     v2buf >>= 16;
  //     result[3] = ((v1buf)& 0xFFFF) > ((v2buf>>48)& 0xFFFF) ? ((v1buf)& 0xFFFF) : ((v2buf>>48)& 0xFFFF);

  //     v1buf = v1x64[1];
  //     v2buf = v2x64[1];
  //     result[4] = ((v1buf)& 0xFFFF) > ((v2buf)& 0xFFFF) ? (v1buf& 0xFFFF) : (v2buf& 0xFFFF);
  //     v1buf >>= 16;
  //     v2buf >>= 16;
  //     result[5] = ((v1buf)& 0xFFFF) > ((v2buf>>16)& 0xFFFF) ? ((v1buf)& 0xFFFF) : ((v2buf>>16)& 0xFFFF);
  //     v1buf >>= 16;
  //     v2buf >>= 16;
  //     result[6] = ((v1buf)& 0xFFFF) > ((v2buf)& 0xFFFF) ? ((v1buf)& 0xFFFF) : ((v2buf)& 0xFFFF);
  //     v1buf >>= 16;
  //     v2buf >>= 16;
  //     result[7] = ((v1buf)& 0xFFFF) > ((v2buf>>48)& 0xFFFF) ? ((v1buf)& 0xFFFF) : ((v2buf>>48)& 0xFFFF);
  // }

  // //  n=100000000, 583078 ms (!???????)
  // for (i = 0; i < n; ++i) {
  //     v1buf = v1x64[0];
  //     v2buf = v2x64[0];
  //     result[0] = ((v1buf)& 0xFFFF) > ((v2buf)& 0xFFFF) ? (v1buf& 0xFFFF) : (v2buf& 0xFFFF);
  //     result[1] = ((v1buf>>16)& 0xFFFF) > ((v2buf>>16)& 0xFFFF) ? ((v1buf>>16)& 0xFFFF) : ((v2buf>>16)& 0xFFFF);
  //     result[2] = ((v1buf>>32)& 0xFFFF) > ((v2buf>>32)& 0xFFFF) ? ((v1buf>>32)& 0xFFFF) : ((v2buf>>32)& 0xFFFF);
  //     result[3] = ((v1buf>>48)& 0xFFFF) > ((v2buf>>48)& 0xFFFF) ? ((v1buf>>48)& 0xFFFF) : ((v2buf>>48)& 0xFFFF);

  //     v1buf = v1x64[1];
  //     v2buf = v2x64[1];
  //     result[4] = ((v1buf)& 0xFFFF) > ((v2buf)& 0xFFFF) ? (v1buf& 0xFFFF) : (v2buf& 0xFFFF);
  //     result[5] = ((v1buf>>16)& 0xFFFF) > ((v2buf>>16)& 0xFFFF) ? ((v1buf>>16)& 0xFFFF) : ((v2buf>>16)& 0xFFFF);
  //     result[6] = ((v1buf>>32)& 0xFFFF) > ((v2buf>>32)& 0xFFFF) ? ((v1buf>>32)& 0xFFFF) : ((v2buf>>32)& 0xFFFF);
  //     result[7] = ((v1buf>>48)& 0xFFFF) > ((v2buf>>48)& 0xFFFF) ? ((v1buf>>48)& 0xFFFF) : ((v2buf>>48)& 0xFFFF);
  // }

  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  std::cout << "Scratch SIMD Time taken by function: "
            << duration.count() << " ms" << std::endl;
  std::cout << "Scratch SIMD Result : ";
  for (i = 0; i < 8; i++) {
    std::cout << result[i] << " ";
  }
  std::cout << std::endl;
}
