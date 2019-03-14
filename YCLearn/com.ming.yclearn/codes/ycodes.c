//
// Created by Android-Developer on 2019/3/12.
//

#include "ycodes.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <windows.h>

void open(char *str) {
    //ShellExecuteA(0,"open", "mspaint", 0, 0, 1);
    ShellExecuteA(0, "open", str, 0, 0, 1);
}

void closeNet() {
    system("taskkill  /f  /im  iexplore.exe");
}

double add(int num, ...) {//...代表可变参数
    double last = 0.0;
    va_list argp;
    va_start(argp, num);
    for (int i = 0; i < num; i++) {
        double temp = va_arg(argp, double);
        last += temp;
        printf("\n%f", temp);

    }
    va_end(argp);
    return last;
}
