#include <stdio.h>
#include <stdlib.h>
#include "testutils.h"

void success(char *str)
{
    printf("\e[0;32m%s\e[0m\n", str);
}

void error(char *str, int n1, int n2)
{
    char *str1 = malloc(sizeof(char) * 500);

    sprintf(str1, "\e[1;31m%s\033[0m\n", str);
    printf(str1, n1, n2);

    free(str1);
}

void assert(int n1, int n2)
{
    if (n1 == n2) {
        success("ok.");
    } else {
        error("%d != %d err.", n1, n2);
    }
}
