//
// Created by Lenovo on 2018/12/14.
//

#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

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