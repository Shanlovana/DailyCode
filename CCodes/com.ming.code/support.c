//
// Created by Lenovo on 2018/12/11.
//
#include <stdio.h>
#include <float.h>

extern int conbas;
#define LENGTH 10
#define WIDTH  5
#define NEWLINE '\n'

void writen_extern(void) {
    printf("conbas is %d\n", conbas);
}

void goto_method(void) {
    int a = 10;
    LOOP:
    do {
        if (a == 15) {
            a = a + 1;
            goto LOOP;
        }
        a++;
        printf("a is : %d\n", a);
    } while (a < 25);
}


void extern_method(void) {
    conbas = 20;
    writen_extern();
}

void operator(void) {
    int a = 21;
    int b = 10;
    int c;

    c = a + b;
    printf("Line 1 - c is %d\n", c);
    c = a - b;
    printf("Line 2 - c is %d\n", c);
    c = a * b;
    printf("Line 3 - c is %d\n", c);
    c = a / b;
    printf("Line 4 - c is %d\n", c);
    c = a % b;
    printf("Line 5 - c is %d\n", c);
    c = a++;  // 赋值后再加 1 ，c 为 21，a 为 22
    printf("Line 6 - c is %d\n", c);
    c = a--;  // 赋值后再减 1 ，c 为 22 ，a 为 21
    printf("Line 7 - c is %d\n", c);

}

void test_print(void) {
    int a = 3895;
    int b = 2547;
    int c;
    int d;
    /*this is my first c program*/
    printf("Hello, World!\n");
    printf("3895 * 2547 = %d\n", (a * b));
    printf("c=%d\n", c);
    printf("d=%d\n", d);
    int num = -9527;
    /*puts("please input a num");
    scanf("%d", &num);
    printf("the num you input is ", num);
    int e, f, g;
    puts("please input three nums ,split with ,");
    scanf("%d%d%d", &e, &f, &g);
    printf("e = %d,f = %d,g = %d", e, f, g);//this place has some errors,i will check it out later;*/
    printf("int size is : %lu \n", sizeof(int));
    printf("long size is : %lu \n", sizeof(double));
    printf("float size : %lu \n", sizeof(float));
    printf("float min: %E\n", FLT_MIN);
    printf("float max: %E\n", FLT_MAX);
    printf("precision: %d\n", FLT_DIG);
    /* int *iptr; //左值与右值问题
     *iptr = 421;
     printf("*iptr = %d/n", *iptr);*/
    printf("Hello\tWorld\n\n");

    int area;
    area = LENGTH * WIDTH;
    printf("value of area : %d", area);
    printf("%c", NEWLINE);
    const int ILENGTH = 10;
    const int IWIDTH = 5;
    const char INEWLINE = '\n';
    int areay;
    areay = ILENGTH * IWIDTH;
    printf("value of areay : %d", areay);
    printf("%c", INEWLINE);
}

void before_next(void) {
    int c;
    int a = 10;
    c = a++;
    printf("a * *\n");
    printf("Line 1 - c is %d\n", c);
    printf("Line 2 - a is %d\n", a);
    a = 10;
    c = a--;
    printf("Line 3 - c is %d\n", c);
    printf("Line 4 - a is %d\n", a);

    printf("* * a\n");
    a = 10;
    c = ++a;
    printf("Line 5 - c is %d\n", c);
    printf("Line 6 - a is %d\n", a);
    a = 10;
    c = --a;
    printf("Line 7 - c is %d\n", c);
    printf("Line 8 - a is %d\n", a);
}

void relational_operator(void) {
    int a = 21;
    int b = 10;
    int c;

    if (a == b) {
        printf("Line 1 - a 等于 b\n");
    } else {
        printf("Line 1 - a 不等于 b\n");
    }
    if (a < b) {
        printf("Line 2 - a 小于 b\n");
    } else {
        printf("Line 2 - a 不小于 b\n");
    }
    if (a > b) {
        printf("Line 3 - a 大于 b\n");
    } else {
        printf("Line 3 - a 不大于 b\n");
    }
    /* 改变 a 和 b 的值 */
    a = 5;
    b = 20;
    if (a <= b) {
        printf("Line 4 - a 小于或等于 b\n");
    }
    if (b >= a) {
        printf("Line 5 - b 大于或等于 a\n");
    }
}

void logical_operator(void) {
    int a = 5;
    int b = 20;
    int c;

    if (a && b) {
        printf("Line 1 - is true\n");
    }
    if (a || b) {
        printf("Line 2 - is true\n");
    }
    /* 改变 a 和 b 的值 */
    a = 0;
    b = 10;
    if (a && b) {
        printf("Line 3 - is true\n");
    } else {
        printf("Line 3 - is not true\n");
    }
    if (!(a && b)) {
        printf("Line 4 - is true\n");
    }

}

void bitwise_operation(void) {
    unsigned int a = 60;    /* 60 = 0011 1100 */
    unsigned int b = 13;    /* 13 = 0000 1101 */
    int c = 0;

    c = a & b;       /* 12 = 0000 1100 */
    printf("Line 1 - c is %d\n", c);

    c = a | b;       /* 61 = 0011 1101 */
    printf("Line 2 - c is %d\n", c);

    c = a ^ b;       /* 49 = 0011 0001 */
    printf("Line 3 - c is %d\n", c);

    c = ~a;          /*-61 = 1100 0011 */
    printf("Line 4 - c is %d\n", c);

    c = a << 2;     /* 240 = 1111 0000 */
    printf("Line 5 - c is %d\n", c);

    c = a >> 2;     /* 15 = 0000 1111 */
    printf("Line 6 - c is %d\n", c);
}

void assignment_operation(void) {
    int a = 21;
    int c;

    c = a;
    printf("Line 1 - =  运算符实例，c 的值 = %d\n", c);

    c += a;
    printf("Line 2 - += 运算符实例，c 的值 = %d\n", c);

    c -= a;
    printf("Line 3 - -= 运算符实例，c 的值 = %d\n", c);

    c *= a;
    printf("Line 4 - *= 运算符实例，c 的值 = %d\n", c);

    c /= a;
    printf("Line 5 - /= 运算符实例，c 的值 = %d\n", c);

    c = 200;
    c %= a;
    printf("Line 6 - %= 运算符实例，c 的值 = %d\n", c);

    c <<= 2;
    printf("Line 7 - <<= 运算符实例，c 的值 = %d\n", c);

    c >>= 2;
    printf("Line 8 - >>= 运算符实例，c 的值 = %d\n", c);

    c &= 2;
    printf("Line 9 - &= 运算符实例，c 的值 = %d\n", c);

    c ^= 2;
    printf("Line 10 - ^= 运算符实例，c 的值 = %d\n", c);

    c |= 2;
    printf("Line 11 - |= 运算符实例，c 的值 = %d\n", c);

}

void miscellaneous_operations(void) {
    int a = 4;
    short b;
    double c;
    int *ptr;

    /* sizeof 运算符实例 */
    printf("Line 1 - 变量 a 的大小 = %lu\n", sizeof(a));
    printf("Line 2 - 变量 b 的大小 = %lu\n", sizeof(b));
    printf("Line 3 - 变量 c 的大小 = %lu\n", sizeof(c));

    /* & 和 * 运算符实例 */
    ptr = &a;    /* 'ptr' 现在包含 'a' 的地址 */
    printf("a 的值是 %d\n", a);
    printf("*ptr 是 %d\n", *ptr);

    /* 三元运算符实例 */
    a = 10;
    b = (a == 1) ? 20 : 30;
    printf("b 的值是 %d\n", b);

    b = (a == 10) ? 20 : 30;
    printf("b 的值是 %d\n", b);
}

void precedence_of_operator(void) {
    int a = 20;
    int b = 10;
    int c = 15;
    int d = 5;
    int e;

    e = (a + b) * c / d;      // ( 30 * 15 ) / 5
    printf("(a + b) * c / d 的值是 %d\n", e);

    e = ((a + b) * c) / d;    // (30 * 15 ) / 5
    printf("((a + b) * c) / d 的值是 %d\n", e);

    e = (a + b) * (c / d);   // (30) * (15/5)
    printf("(a + b) * (c / d) 的值是 %d\n", e);

    e = a + (b * c) / d;     //  20 + (150/5)
    printf("a + (b * c) / d 的值是 %d\n", e);
}

int max_num(int num, int numT) {
    return num > numT ? num : numT;
}

void switch_num(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void array_ges(void) {
    int n[10]; /* n 是一个包含 10 个整数的数组 */
    int i, j;

    /* 初始化数组元素 */
    for (i = 0; i < 10; i++) {
        n[i] = i + 10; /* 设置元素 i 为 i + 100 */
    }

    /* 输出数组中每个元素的值 */
    for (j = 0; j < 10; j++) {
        printf("Element[%d] = %d\n", j, n[j]);
    }
}

void twodim_array(void) {
    /* 一个带有 5 行 2 列的数组 */
    int a[5][2] = {{0, 1},
                   {2, 3},
                   {4, 5},
                   {6, 7},
                   {8, 9}};
    int i, j;

    /* 输出数组中每个元素的值 */
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            printf("a[%d][%d] = %d\n", i, j, a[i][j]);
        }
    }

}

double get_average(int arr[], int size) {
    int i;
    double avg;
    double sum;

    for (i = 0; i < size; ++i) {
        sum += arr[i];
    }

    avg = sum / size;

    return avg;
}

int *getRandom(void) {
    static int r[10];
    int i;

    /* 设置种子 */
    srand((unsigned) time(NULL));
    for (i = 0; i < 10; ++i) {
        r[i] = rand();
        printf("r[%d] = %d\n", i, r[i]);

    }

    return r;
}

void pointer_array(){
    /* 带有 5 个元素的整型数组 */
    double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
    double *p;
    int i;

    p = balance;

    /* 输出数组中每个元素的值 */
    printf( "use pointer \n");
    for ( i = 0; i < 5; i++ )
    {
        printf("*(p + %d) : %f\n",  i, *(p + i) );
    }

    printf( "use balance as pointer \n");
    for ( i = 0; i < 5; i++ )
    {
        printf("*(balance + %d) : %f\n",  i, *(balance + i) );
    }
}