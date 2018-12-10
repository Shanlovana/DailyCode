#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main() {
   /* int a = 3895;
    int b = 2547;
    int c;
    int d;
    *//*this is my first c program*//*
    printf("Hello, World!\n");
    printf("3895 * 2547 = %d\n", (a * b));
    printf("c=%d\n", c);
    printf("d=%d\n", d);
     int num=-9527;
     puts("please input a num");
     scanf("%d",&num);
     printf("the num you input is ",num);
    int e, f, g;
    puts("please input three nums ,split with ,");
    scanf("%d%d%d", &e, &f, &g);
    printf("e = %d,f = %d,g = %d", e, f, g);//this place has some errors,i will check it out later;*/
    printf("int size is : %lu \n", sizeof(int));
    printf("long size is : %lu \n", sizeof(double));
    printf("float 存储最大字节数 : %lu \n", sizeof(float));
    printf("float 最小值: %E\n", FLT_MIN );
    printf("float 最大值: %E\n", FLT_MAX );
    printf("精度值: %d\n", FLT_DIG );

    return 0;
}