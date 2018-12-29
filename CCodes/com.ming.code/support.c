//
// Created by Lenovo on 2018/12/11.
//
#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

extern int conbas;
#define LENGTH 10
#define WIDTH  5
#define NEWLINE '\n'


int get_random_value();

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
    puts("please input a num");
    scanf("%d", &num);
    printf("the num you input is %d", num);
    int e, f, g;
    puts("please input three nums ");
    scanf("%d%d%d", &e, &f, &g);
    printf("e = %d,f = %d,g = %d", e, f, g);//this place has some errors,i will check it out later;
    //2018.12.13  不要用,作为分隔   以空格键作为分隔即可正常运行
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
    printf("Line 6 - /= 运算符实例，c 的值 = %d\n", c);

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

void pointer_array() {
    /* 带有 5 个元素的整型数组 */
    double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
    double *p;
    int i;

    p = balance;

    /* 输出数组中每个元素的值 */
    printf("use pointer \n");
    for (i = 0; i < 5; i++) {
        printf("*(p + %d) : %f\n", i, *(p + i));
    }

    printf("use balance as pointer \n");
    for (i = 0; i < 5; i++) {
        printf("*(balance + %d) : %f\n", i, *(balance + i));
    }
}

int get_random_value() {
    return rand();
}

void assignment_array(int *array, size_t arraySize, int(*get_dom_value(void))) {
    //从此处可以看出   函数指针作为某个函数的参数   时，方法名称不需一一对应
    for (size_t i = 0; i < arraySize; i++) {
        array[i] = get_dom_value();
    }

}

void string_test() {
    char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    printf("Greeting message: %s\n", greeting);

    char str1[12] = "Hello";
    char str2[12] = "World";
    char str3[12];
    int len;

    /* 复制 str1 到 str3 */
    strcpy(str3, str1);
    printf("strcpy( str3, str1) :  %s\n", str3);

    /* 连接 str1 和 str2 */
    strcat(str1, str2);
    printf("strcat( str1, str2):   %s\n", str1);

    /* 连接后，str1 的总长度 */
    len = strlen(str1);
    printf("strlen(str1) :  %d\n", len);
}

struct Books {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
} book = {"C ", "RUNOOB", "programa laguege", 123456};

void book_init() {
    printf("title : %s\nauthor: %s\nsubject: %s\nbook_id: %d\n", book.title, book.author, book.subject, book.book_id);
}

void print_book(struct Books book) {
    printf("Book title : %s\n", book.title);
    printf("Book author : %s\n", book.author);
    printf("Book subject : %s\n", book.subject);
    printf("Book book_id : %d\n", book.book_id);
}

void print_books(struct Books *book) {
    printf("Book title : %s\n", book->title);
    printf("Book author : %s\n", book->author);
    printf("Book subject : %s\n", book->subject);
    printf("Book book_id : %d\n", book->book_id);
}

void book_set() {
    struct Books Book1;        /* 声明 Book1，类型为 Books */
    struct Books Book2;        /* 声明 Book2，类型为 Books */

    /* Book1 详述 */
    strcpy(Book1.title, "C Programming");
    strcpy(Book1.author, "Nuha Ali");
    strcpy(Book1.subject, "C Programming Tutorial");
    Book1.book_id = 6495407;

    /* Book2 详述 */
    strcpy(Book2.title, "Telecom Billing");
    strcpy(Book2.author, "Zara Ali");
    strcpy(Book2.subject, "Telecom Billing Tutorial");
    Book2.book_id = 6495700;

    /* 输出 Book1 信息 */
    //print_book(Book1);
    print_books(&Book1);

    /* 输出 Book2 信息 */
    //print_book(Book2);
    print_books(&Book2);
}

void test_bit_field() {
    struct bs {
        unsigned a:1;
        unsigned b:3;
        unsigned c:4;
    } bit, *pbit;
    bit.a = 1;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    bit.b = 7;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    bit.c = 15;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    printf("%d,%d,%d\n", bit.a, bit.b, bit.c);    /* 以整型量格式输出三个域的内容 */
    pbit = &bit;    /* 把位域变量 bit 的地址送给指针变量 pbit */
    pbit->a = 0;    /* 用指针方式给位域 a 重新赋值，赋为 0 */
    pbit->b &= 3;    /* 使用了复合的位运算符 "&="，相当于：pbit->b=pbit->b&3，位域 b 中原有值为 7，与 3 作按位与运算的结果为 3（111&011=011，十进制值为 3） */
    pbit->c |= 1;    /* 使用了复合位运算符"|="，相当于：pbit->c=pbit->c|1，其结果为 15 */
    printf("%d,%d,%d\n", pbit->a, pbit->b, pbit->c);    /* 用指针方式输出了这三个域的值 */
}

struct person {
    char name[20];
    int count;

} leader[3] = {{"Li",    0},
               {"Zhang", 0},
               {"Fun",   0}};

void struct_array() {
    int i, j;
    char leader_name[20];
    for (i = 1; i <= 5; i++) {
        printf("please input names:");
        scanf("%s", leader_name);
        for (j = 0; j < 3; j++)
            if (strcmp(leader_name, leader[j].name) == 0)
                leader[j].count++;
    }
    printf("\n");
    for (i = 0; i < 3; i++)
        printf("%5s: %d\n", leader[i].name, leader[i].count);
    system("pause");
}

union Data {
    int i;
    float f;
    char str[9];
};

void union_size() {
    union Data data;
    printf("Memory size occupied by data : %ld\n", sizeof(data));
}

void get_union_mem() {
    union Data data;
    data.i = 1024;
    printf("data.i : %d\n", data.i);
    data.f = 2298.5;
    printf("data.f : %f\n", data.f);
    strcpy(data.str, "C Programming");
    printf("data.str : %s\n", data.str);
}

struct {
    unsigned int widthValidated;
    unsigned int heightValidated;
} status;

struct {
    unsigned int widthValidated : 1;
    unsigned int heightValidated : 1;
} statuse;

struct {
    int widthValidated : 8;
    int heightValidated : 2;
    int heighVali : 3;
} statusel;

struct {
    int widthValidated : 8;
    char heigh: 5;
    long width : 3;
} statusell;

void print_mem_size() {
    printf("Memory size occupied by status : %ld\n", sizeof(status));
    printf("Memory size occupied by statuse : %ld\n", sizeof(statuse));
    printf("Memory size occupied by statuse : %ld\n", sizeof(statusel));
    printf("Memory size occupied by statuse : %ld\n", sizeof(statusell));
    printf("Memory size occupied by long : %ld\n", sizeof(long));

}

void print_float() {
    float f;
    printf("Enter a float number: ");
    // %f 匹配浮点型数据
    scanf("%f", &f);
    printf("Value = %f", f);
}

void print_all_you_put() {
    char str[100];

    printf("Enter a value :");
    fgets(str,200,stdin);

    printf("\nYou entered: ");
    puts(str);
}

void input_notice() {
    int a;
    float x;
    char c1;
    printf("please input int float char \n");
    scanf("a=%d", &a);
    scanf("x=%f", &x);
    scanf("c1=%c", &c1);
    printf("a=%d,x=%f,c1=%c\n", a, x, c1);
}

void file_input() {
    FILE *file = NULL;
    char buff[255];
    file = fopen("C:\\Users\\Lenovo\\Desktop\\forctest.txt", "a+");
    fprintf(file, "This is testing for fprintf...\n");
    fseek(file, 10, SEEK_SET);
    if (fputc(65, file) == EOF) {
        printf("fputc fail");
    }
    fputs("This is testing for fputs...\n", file);

    fclose(file);
}

void file_output() {
    FILE *file = NULL;
    char buff[255];
    file = fopen("C:\\Users\\Lenovo\\Desktop\\forctest.txt", "r");
    fscanf(file, "%s", buff);
    printf("1: %s\n", buff);

    fgets(buff, 255, (FILE *) file);
    printf("2: %s\n", buff);

    fgets(buff, 255, (FILE *) file);
    printf("3: %s\n", buff);

    fclose(file);
}

void macros_predefined() {
    printf("File :%s\n", __FILE__);
    printf("Date :%s\n", __DATE__);
    printf("Time :%s\n", __TIME__);
    printf("Line :%d\n", __LINE__);
    printf("ANSI :%d\n", __STDC__);
}

void convert_data() {
    int sum = 17, count = 5;
    double mean;
    mean = (double) sum / count;
    printf("Value of mean : %f\n", mean);
    int  i = 17;
    char c = 'c'; /* ascii 值是 99 */
    int sume;

    sume = i + c;
    printf("Value of sume : %d\n", sume );
    int  j = 17;
    char k = 'c'; /* ascii 值是 99 */
    float sumes;

    sumes = j + k;
    printf("Value of sumes : %f\n", sumes );
}