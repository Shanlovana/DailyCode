//
// Created by Lenovo on 2018/12/14.
//

#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>

extern int errno;

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