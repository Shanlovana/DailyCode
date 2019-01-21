#include <stdio.h>
#include <config.h>

#ifdef USE_MATH_LIB

#include <MathUtils.h>
#include <stdlib.h>

#else
#include <math.h>
#endif

int main(int argc, char *argv[]) {


#ifdef USE_MATH_LIB
    printf("Now we use our own Math library. \n");
    hello(argc);
#else
    printf("Now we use the standard library. \n");
     printf("Hello, World !\n");
#endif
    printf("Hello, World Ending!\n");


#ifdef HAVE_POW
    double result = power(7, 8);
    printf("Now we use our own Math library. Result is %f\n", result);
#else
    double result = power(6, 9);
    printf("Now we use our own Math library. Result is %f\n", result);

#endif
    printf("%s Version %d.%d  \n",argv[0],VERSIONCODEMAJOR,VERSIONCODEMINOR);
    return 0;
}

