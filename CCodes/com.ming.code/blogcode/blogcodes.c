//
// Created by Lenovo on 2018/12/14.
//

#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <elog.h>
#include <unistd.h>
#include "method.h"

extern int errno;
#define LOG_TAG    "main"
static int count = 10;

void error_deal() {
    FILE *pf;
    int errnum = 0;
    pf = fopen("unexist.txt", "rb");
    if (pf == NULL) {
        errnum = errno;
        fprintf(stderr, "error num : %d\n", errno);
        perror("perror  output  errors");
        fprintf(stderr, "file open error: %s\n", strerror(errnum));
    } else {
        fclose(pf);
    }
}

double factorial(unsigned int a) {
    if (a <= 1) {
        return 1;
    }
    return a * factorial(a - 1);
}

int fabonaci(int i) {
    if (i == 0) {
        return 0;
    } else if (i == 1) {
        return 1;
    } else {
        return fabonaci(i - 1) + fabonaci(i - 2);
    }
}

double average_nums(int num, ...) {
    va_list list;
    double sum = 0;

    /* 为 num 个参数初始化 valist */
    va_start(list, num);


    /* 访问所有赋给 valist 的参数 */
    /* 访问所有赋给 valist 的参数 */
    for (int i = 0; i < num; i++) {
        sum += va_arg(list, int);
    }
    /* 清理为 valist 保留的内存 */
    va_end(list);

    return sum / num;
}

int changeable_varity(char *msg, ...) {

    va_list argp;                    /* 定义保存函数参数的结构 */
    int argno = 0;                    /* 纪录参数个数 */
    char *para;                        /* 存放取出的字符串参数 */
    va_start(argp, msg);          /* argp指向传入的第一个可选参数，      msg是最后一个确定的参数 */

    while (1) {
        para = va_arg(argp, char *);                 /*      取出当前的参数，类型为char *. */
        if (strcmp(para, "/0") == 0)
            /* 采用空串指示参数输入结束 */
            break;
        printf("Parameter #%d is: %s\n", argno, para);
        argno++;
    }
    va_end(argp);                                   /* 将argp置为NULL */
    return 0;
}

void dynamic_allocation_memory() {
    char name[100];
    char *description;

    strcpy(name, "Tony Anndy");
    // description = (char *) _malloc(200 * sizeof(char));
    /* 动态分配内存 */
    description = (char *) malloc(80 * sizeof(char));

    if (description == NULL) {
        fprintf(stderr, "Error - unable to allocate required memory\n");
    } else {
        strcpy(description, "Tony Anndy is DPS gay in class 10th ");
    }

    /* 假设您想要存储更大的描述信息 */
    description = realloc(description, 100 * sizeof(char));
    if (description == NULL) {
        fprintf(stderr, "Error - unable to allocate required memory\n");
    } else {
        strcat(description, "She is in class 10th");
    }

    printf("Name = %s\n", name);
    printf("Description: %s\n", description);
};

void cmdlineparameter(int argc, char *argv[]) {
    if (argc == 2) {
        printf("The argument supplied is %s\n", argv[1]);
    } else if (argc > 2) {
        printf("Too many arguments supplied.\n");
    } else {
        printf("One argument expected.\n");
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;

}

//冒泡排序
void bubble_sort() {
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = (int) sizeof(arr) / sizeof(*arr);
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }

        }
    }
    for (int k = 0; k < len; ++k) {
        printf("bubble_sort index %d is %d \n", k, arr[k]);
    }
}

//选择排序
void selection_sort() {
    int arr[] = {22, 34, 47, 32, 77, 55, 101, 50, 37, 5, 64, 35, 9, 70};
    int len = (int) sizeof(arr) / sizeof(*arr);
    for (int i = 0; i < len - 1; i++) {
        int min = i;//假设最小为i
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[min]) {//找到目前的最小值
                min = j;//记录最小值下标
                swap(&arr[i], &arr[min]);//交换外层i与内部最小值

            }
        }
    }
    for (int k = 0; k < len; ++k) {
        printf("selection_sort index %d is %d \n", k, arr[k]);
    }
};


void insertion_sort() {
    int i, j, temp;
    int arr[] = {22, 34, 47, 32, 77, 55, 101, 50, 37, 5, 64, 35, 9, 70};
    int len = (int) sizeof(arr) / sizeof(*arr);
    for (i = 1; i < len; i++) {
        /**
        * temp为本次循环待插入有序列表中的数
        */
        temp = arr[i];
        /**
        * 寻找temp插入有序列表的正确位置
        */
        for (j = i - 1; j > 0; j--) {
            /**
            * 元素后移，为插入temp做准备
            */
            if (arr[j] > temp) {
                arr[j + 1] = arr[j];
            }
        }
        /**
         * 插入temp
         */
        arr[j + 1] = temp;
    }
    for (int k = 0; k < len; ++k) {
        printf("insertion_sort index %d is %d \n", k, arr[k]);
    }
}
/**
 * EasyLogger demo
 */
/**
 * EasyLogger demo
 */
void test_elog(void) {
    elog_init();
    /* set EasyLogger log format */
    elog_set_fmt(ELOG_LVL_ASSERT, ELOG_FMT_ALL);
    elog_set_fmt(ELOG_LVL_ERROR, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_WARN, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_INFO, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_DEBUG, ELOG_FMT_ALL & ~ELOG_FMT_FUNC);
    elog_set_fmt(ELOG_LVL_VERBOSE, ELOG_FMT_ALL & ~ELOG_FMT_FUNC);
#ifdef ELOG_COLOR_ENABLE
    elog_set_text_color_enabled(true);
#endif
    /* start EasyLogger */
    elog_start();
    uint8_t buf[256] = {0};
    int i = 0;

    for (i = 0; i < sizeof(buf); i++) {
        buf[i] = i;
    }
    while (true) {
        /* test log output for all level */
        log_a("Hello EasyLogger!");
        log_e("Hello EasyLogger!");
        log_w("Hello EasyLogger!");
        log_i("Hello EasyLogger!");
        log_d("Hello EasyLogger!");
        log_v("Hello EasyLogger!");
//        elog_raw("Hello EasyLogger!");
        elog_hexdump("test", 16, buf, sizeof(buf));
        sleep(5);
    }
}

void sum_num(void) {
    static int another_count = 5;
    another_count++;
    printf(" another_count is %d , count is %d\n", another_count, count);

}

void print_switch() {
    int a = 100, b = 200;
    printf("before,a is : %d b is : %d\n", a, b);
    /* 调用函数来交换值 */
    switch_num(a, b);
    printf("after,a is : %d b is : %d\n", a, b);
}

void test_variable() {
    printf(" count is %d\n", count);
    int count = 55;
    printf(" count is %d\n", count);
}

void test_get_average() {
    /* 带有 5 个元素的整型数组 */
    int balance[5] = {1000, 2, 3, 17, 50};
    double avg;

    /* 传递一个指向数组的指针作为参数 */
    avg = get_average(balance, 5);

    /* 输出返回值 */
    printf("average is:   %f ", avg);
}

void get_random_tesla() {
    /* 一个指向整数的指针 */
    int *p;
    int i;

    p = getRandom();
    for (i = 0; i < 10; i++) {
        printf("*(p + %d) : %d\n", i, *(p + i));
    }

}

void test_function_pointer() {
    /* p 是函数指针 */
    int (*p)(int, int) = &max_num; // &可以省略
    int a, b, c, d;
    printf("please input three nums:");
    scanf("%d %d %d", &a, &b, &c);
    /* 与直接调用函数等价，d = max(max(a, b), c) */
    d = p(p(a, b), c);

    printf("max num is : %d\n", d);
}

void test_assignment_array() {
    int myarray[10];
    assignment_array(myarray, 10, get_random_value);
    for (int i = 0; i < 10; i++) {
        printf("%d ", myarray[i]);
    }
    printf("\n");
}
