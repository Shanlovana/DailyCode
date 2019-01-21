#include <stdio.h>
#include <config.h>

#ifdef USE_MATH_LIB

#include <MathUtils.h>
#include <stdlib.h>

#else
#include <math.h>
#endif

int main(int argc, char *argv[]) {
    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);

#ifdef USE_MATH_LIB

    printf("Now we use our own Math library. \n");
    double result = power(base, exponent);

#else
    printf("Now we use the standard library. \n");
     printf("Hello, World !\n");
#endif
    printf("Hello, World Ending!\n");
    return 0;
}