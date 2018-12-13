#include <stdio.h>
#include <stdlib.h>
#include <float.h>

static int count = 10;
int conbas;

extern void writen_extern();

extern void goto_method();

extern void sum_num();

extern void operator();

extern void extern_method();

extern void test_print();

extern void before_next();

extern void relational_operator();

extern void logical_operator();

extern void bitwise_operation();

extern void assignment_operation();

extern void miscellaneous_operations();

extern void precedence_of_operator();

extern int max_num(int, int);

void switch_num(int, int);

void print_switch();

void test_variable();

extern void array_ges();

extern void twodim_array();

extern double get_average(int arr[], int size);

extern int *getRandom();

void get_random_tesla();

extern void pointer_array();

void test_get_average();

enum {
    Q, W, E = 4, R
};

int main() {
    test_print();
    test_variable();//全局变量与局部变量
    printf("count is %d\n", count);//查看全局变量打印
    while (count--) {
        sum_num();
    }

    extern_method();
    operator();
    before_next();
    relational_operator();
    logical_operator();
    bitwise_operation();
    assignment_operation();
    miscellaneous_operations();
    precedence_of_operator();
    goto_method();
    int result = max_num(5, 37);
    printf("result = max num is %d\n", result);
    print_switch();
    array_ges();
    twodim_array();
    test_get_average();
    get_random_tesla();
    pointer_array();
    printf("enum Q W E R is : %d , %d , %d , %d", Q, W, E, R);
    return 0;
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