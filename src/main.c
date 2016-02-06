#include <stdio.h>
#include "cstrcalc.h"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        puts("not enough args (must be 1)");
        return 1;
    } else if (argc > 2) {
        puts("too many args (must be 1)");
        return 1;
    }

    printf("%lld\n", calc(argv[1]));

    return 0;
}
