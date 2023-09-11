// https://github.com/Keith-S-Thompson/42
// not 1+5 * 8+1 = 56, but 1+(5 * 8)+1 = 42
#include <stdio.h>

#define SIX 1+5
#define NINE 8+1

int test_improper_preproc(void)
{
    printf("%d * %d = %d\n", SIX, NINE, SIX * NINE);
    return 0;
}