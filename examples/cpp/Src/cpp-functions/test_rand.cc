// https://modoocode.com/304#page-heading-5
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int testRand() {
  srand(time(NULL));

  for (int i = 0; i < 5; i++) {
    printf("난수 : %d \n", rand() % 100);
  }
  return 0;
}
