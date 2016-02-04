#ifndef CSTRCALC_H
#define CSTRCALC_H

unsigned long long int extract_number(char *str, unsigned int endstr);
long long int power(int e, int n);
long long int expr(long long int n1, char symb, long long int n2);
long long int calc(char *str);

#endif
