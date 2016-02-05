#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "cstrcalc.h"

char *substr;
unsigned int istr;

long long int power(int e, int n)
{
    long long int res = 1;

    for (; e > 0; e--) {
        res *= n;
    }

    return res;
}

unsigned long long int extract_number(char *str, unsigned int endstr)
{
    unsigned long long int decade = power(endstr - 1, 10);
    unsigned long long int n = 0;
    unsigned int i;

    for (i = 0; i < endstr; i++, decade /= 10) {
        n += ((int) str[i] - 48) * decade;
    }

    return n;
}

long long int expr(long long int n1, char symb, long long int n2)
{
    switch (symb) {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            if (n2 > 0) return n1 / n2;
            else puts("[e] cant divide by zero");
        case '%':
            if (n2 > 0) return n1 % n2;
            else puts("[e] cant divide by zero");
            break;
        default:
            puts("[e] cant parse symb");
            break;
    }
}

long long int bcalc(char *str, long long int res, bool secondary)
{
    char symb = '\0';
    unsigned int isubstr = 0;
    long long int child;

    if (!secondary) {
        while (istr < strlen(str) && str[istr] != ' ') {
            substr[istr] = str[istr];
            istr++;
        }

        res = extract_number(substr, istr);

    }

    istr++;

    for (; istr < strlen(str) + 1; istr++, isubstr++) {
        // printf("symb: %c\n", symb);
        // printf("substr: %s\n", substr);
        // printf("isubstr: %d\n", isubstr);
        // printf("istr: %d\n", istr);
        // printf("res: %ld\n", res);

        if ((int) str[istr] > 57 || (int) str[istr] < 48 \
                && str[istr] != ' ' && istr != strlen(str)
            ) {
            symb = str[istr];
            isubstr = -1;
        } else if (str[istr] == ' ' || istr == strlen(str)) {
            if ((str[istr + 1] == '*' || str[istr + 1] == '/' || str[istr + 1] == '%'
                    ) && !secondary
                ) {
                child = bcalc(str, extract_number(substr, isubstr), true);
                // printf("child: %lld\n", child);
                // printf("symb: %c\n", symb);
                res = expr(res, symb, child);
            } else if (isubstr > 0) {
                if (str[istr + 1] == '(' || str[istr + 2] == '(') {
                    // res = expr(bcalc(str), symb, extract_number(substr, isubstr));
                } else {
                    res = expr(res, symb, extract_number(substr, isubstr));
                    if (secondary && (str[istr + 1] == '+' || str[istr + 1] == '-')) {
                        break;
                    }
                }
            }

            isubstr = -1;
        } else {
            substr[isubstr] = str[istr];
        }
    }


    return res;
}

long long int calc(char *str)
{
    substr = malloc(sizeof(char) * strlen(str));

    istr = 0;

    return bcalc(str, 0, false);

    free(substr);
}
