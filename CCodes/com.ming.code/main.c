#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#ifndef HEADER_FILE
#define HEADER_FILE

#include "blogcode/operatorhead.h"
#include "blogcode/method.h"

#endif

int conbas;
extern void assignment_array(int *array, size_t arraySize, int (*getrandom_value)(void));


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
#define LOG_TAG    "main"

#include <elog.h>
#include <unistd.h>


static void test_elog(void);


#define LOG_TAG    "main"


int main() {
    getRequest();
    /* close printf buffer */
    setbuf(stdout, NULL);
    /* initialize EasyLogger */

    return 0;
}


/*test_print();
getRequest();
test_variable();//全局变量与局部变量
printf("count is %d\n", count);//查看全局变量打印
while (count--) {
    sum_num();
}

extern_method();operator();before_next();relational_operator();logical_operator();bitwise_operation();
assignment_operation();miscellaneous_operations();precedence_of_operator();goto_method();int result = max_num(5, 37);
printf("result = max num is %d\n", result);print_switch();array_ges();twodim_array();test_get_average();get_random_tesla();
pointer_array();printf("enum Q W E R is : %d , %d , %d , %d", Q, W, E, R);test_function_pointer();test_assignment_array();
string_test();book_init();book_set();test_bit_field();struct_array();union_size();get_union_mem();print_mem_size();
print_float();print_all_you_put();input_notice();file_input();file_output();macros_predefined();message_for(ErGouZi, DaMao);
tokenpaste(998); printf("Here is the message: %s\n", MESSAGE);hello();convert_data();error_deal();
double a = factorial(10);
 int b = fabonaci(10);
 printf(" factorial 10 is %f , fabonaci 10 is %d \n", a, b);
 double c = average_nums(5, 1, 600, 5, 7, 9);
 printf(" average_nums 5 is %f ", c);
 changeable_varity("FAKER", "what", "are", "you", "nong", "sha", "lei", "/0");
 dynamic_allocation_memory();
bubble_sort();selection_sort();return 0;*/

