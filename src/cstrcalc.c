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

    return 1;
}

long long int bcalc(char *str, long long int res, bool secondary, bool brackets)
{
    char symb = '\0';
    unsigned int isubstr = 0;
    long long int child;

    if (istr == 0 && str[istr] == '(') {
        istr++;
        child = bcalc(str, 0, false, true);
        // printf("child: %d\n", child);

        res = child;
    } else if (!secondary || brackets) {
        while (istr < strlen(str) && str[istr] != ' ') {
            if (str[istr] != '(') {
                substr[isubstr] = str[istr];
                isubstr++;
            }
            istr++;
        }

        res = extract_number(substr, isubstr);
        isubstr = 0;
    }

    istr++;

    for (; istr < strlen(str) + 1; istr++, isubstr++) {
        // printf("symb: %c\n", symb);
        // printf("isubstr: %d\n", isubstr);
        // printf("substr: %s\n", substr);
        // printf("istr: %d\n", istr);
        // printf("res: %lld\n", res);

        if (str[istr] == '(') {
            child = bcalc(str, extract_number(substr, isubstr), true, true);
            // printf("\tchild: %d\n", child);
            // printf("\tres: %d\n", res);
            // printf("\tisubstr: %d\n", isubstr);
            res = expr(res, symb, child);
            isubstr = -1;
            // res = expr(bcalc(str), symb, extract_number(substr, isubstr));
        } else if (str[istr] == ')') {
            res = expr(res, symb, extract_number(substr, isubstr));
            if (str[istr + 2] == '*' \
                    || str[istr + 2] == '/' \
                    || str[istr + 2] == '%') {
                res = bcalc(str, res, true, false);
            }
            break;
        } else if (((int) str[istr] > 57 || (int) str[istr] < 48) \
                && str[istr] != ' ' && istr != strlen(str)
            ) {
            symb = str[istr];
            isubstr = -1;
        } else if (str[istr] == ' ' || istr == strlen(str)) {
            if ((str[istr + 1] == '*' || str[istr + 1] == '/' || str[istr + 1] == '%'
                    ) && !secondary
                ) {
                if (str[istr - 2] == ')') {
                    child = bcalc(str, res, true, brackets);
                } else {
                    child = bcalc(str, extract_number(substr, isubstr), true, brackets);
                }
                // printf("child: %lld\n", child);
                // printf("symb: %c\n", symb);
                res = expr(res, symb, child);
            } else if (isubstr > 0) {
                res = expr(res, symb, extract_number(substr, isubstr));
                if (secondary && (str[istr + 1] == '+' || str[istr + 1] == '-')) {
                    break;
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

    return bcalc(str, 0, false, false);

    free(substr);
}
