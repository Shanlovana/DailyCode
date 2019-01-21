#include <stdio.h>
#include <config.h>

#ifdef USE_MATH_LIB

#include <MathUtils.h>

#else
#include <math.h>
#endif

int main(int argc, char *argv[]) {

#ifdef USE_MATH_LIB
    printf("Now we use our own Math library. \n");
    hello();
#else
    printf("Now we use the standard library. \n");
     printf("Hello, World !\n");
#endif
    printf("Hello, World Ending!\n");
    return 0;
}