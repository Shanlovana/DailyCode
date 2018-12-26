#include <stdio.h>
#include <stdlib.h>
#include <float.h>
//#include "operatorhead.h"
#ifndef HEADER_FILE
#define HEADER_FILE

#include "operatorhead.h"

#endif

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

void test_function_pointer();

extern void assignment_array(int *array, size_t arraySize, int (*getrandom_value)(void));

extern int get_random_value();

void test_assignment_array();

extern void string_test();

extern void book_init();

extern void book_set();

extern void test_bit_field();

void union_size();

void get_union_mem();

extern void print_mem_size();

extern void print_float();

extern void struct_array();

extern void print_all_you_put();

extern void input_notice();

extern void file_input();

extern void file_output();

extern void macros_predefined();

extern void convert_data();

extern void error_deal();

extern double factorial(unsigned int);

extern int fabonaci(int);

extern double average_nums(int num, ...);

extern int changeable_varity(char *msg, ...);

extern void dynamic_allocation_memory();

extern void bubble_sort();

extern void selection_sort();
extern int getRequest();

#define  message_for(a, b)  \
    printf(#a " and " #b ": We love you!\n")

#define tokenpaste(n) printf ("token" #n " = %d", token##n)

#if !defined (MESSAGE)
#define MESSAGE "You wish!"
#endif

enum {
    Q, W, E = 4, R
};

int token998 = 98;

int main() {
    getRequest();
    return 0;
}
/*test_print();
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
printf("enum Q W E R is : %d , %d , %d , %d", Q, W, E, R);*/
// test_function_pointer();
//test_assignment_array();
//string_test();
// book_init();
//book_set();
//test_bit_field();
//struct_array();
//union_size();
//get_union_mem();
//print_mem_size();
//print_float();
//print_all_you_put();
//input_notice();
//file_input();
//file_output();
//macros_predefined();
// message_for(ErGouZi, DaMao);
//tokenpaste(998);
// printf("Here is the message: %s\n", MESSAGE);
//hello();
//convert_data();
//error_deal();
/* double a = factorial(10);
 int b = fabonaci(10);
 printf(" factorial 10 is %f , fabonaci 10 is %d \n", a, b);
 double c = average_nums(5, 1, 600, 5, 7, 9);
 printf(" average_nums 5 is %f ", c);
 changeable_varity("FAKER", "what", "are", "you", "nong", "sha", "lei", "/0");
 dynamic_allocation_memory();*/
//bubble_sort();
//selection_sort();
//return 0;


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

