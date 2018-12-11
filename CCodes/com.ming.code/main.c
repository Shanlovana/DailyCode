#include <stdio.h>
#include <stdlib.h>
#include <float.h>

static int count = 10;
int conbas;

extern void writen_extern();
extern void  goto_method();

extern void sum_num(void);

extern void operator(void);

extern void extern_method(void);

extern void test_print(void);

extern void before_next(void);

extern void relational_operator(void);

extern void logical_operator(void);

extern void bitwise_operation(void);

extern void assignment_operation(void);

extern void miscellaneous_operations(void);

extern void precedence_of_operator(void);

int main() {
    test_print();
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
    return 0;
}

void sum_num(void) {
    static int another_count = 5;
    another_count++;
    printf(" another_count is %d , count is %d\n", another_count, count);

}