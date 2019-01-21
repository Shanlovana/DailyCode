#include <stdio.h>
#include <config.h>

#ifdef USE_MATH_LIB

#include <MathUtils.h>
#include <stdlib.h>
#include <cjson/cJSON.h>

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


    char *post_str = NULL;
    cJSON *root = cJSON_CreateObject();

    cJSON_AddStringToObject(root, "user", "为所欲为");
    cJSON_AddStringToObject(root, "pwd", "hkcw3cjbc");
    post_str = cJSON_Print(root);
    cJSON_Delete(root);
    root = NULL;
    printf("post_str is %s \n",post_str);

    return 0;
}

