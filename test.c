#include "testutils.h"
#include "cstrcalc.h"

int main()
{
    puts("testing extract_number");

    assert(extract_number("50", 1), 5);
    assert(extract_number("66", 2), 66);
    assert(extract_number("5132222", 4), 5132);
    assert(extract_number("5232", 4), 5232);
    assert(extract_number("523253331", 9), 523253331);
    assert(extract_number("10", 2), 10);

    puts("\ntesting power");
    assert(power(2, 2), 4);
    assert(power(1, 2), 2);
    assert(power(0, 50), 1);
    assert(power(0, 55), 1);
    assert(power(4, 2), 16);
    assert(power(5, 2), 32);


    puts("\ntesting expr");

    puts("testing +");
    assert(expr(5, '+', 5), 10);
    assert(expr(30, '+', 12), 42);
    assert(expr(0, '+', 0), 0);

    puts("testing -");
    assert(expr(30, '-', 12), 18);
    assert(expr(12, '-', 12), 0);
    assert(expr(0, '-', 0), 0);

    puts("testing /");
    assert(expr(30, '/', 3), 10);
    assert(expr(31, '/', 3), 10);

    puts("testing *");
    assert(expr(5, '*', 3), 15);
    assert(expr(9, '*', 9), 81);
    assert(expr(1000000, '*', 10000000), 10000000000000);
    assert(expr(0, '*', 5), 0);
    assert(expr(0, '*', 0), 0);

    puts("testing %");
    assert(expr(100, '%', 10), 0);
    assert(expr(5, '%', 2), 1);
    assert(expr(1, '%', 1), 0);
    assert(expr(0, '%', 1), 0);

    puts("\ntesting calc");

    assert(calc("5 + 5"), 10);
    assert(calc("10005 + 5"), 10010);

    assert(calc("2"), 2);
    assert(calc("0"), 0);
    assert(calc("5263"), 5263);

    assert(calc("90 - 10"), 80);
    assert(calc("900 - 10"), 890);
    assert(calc("1 - 10"), -9);

    assert(calc("900 / 10"), 90);

    assert(calc("900 % 10"), 0);
    assert(calc("901 % 10"), 1);

    assert(calc("901 % 10 + 1"), 2);
    assert(calc("901 + 10 + 1"), 912);
    assert(calc("901 + 10 + 1"), 912);
    assert(calc("1 + 10 * 2"), 21);
    assert(calc("10 * 2 * 3"), 60);
    assert(calc("10 + 3 % 2"), 11);
    assert(calc("12 + 10 / 2"), 17);
    assert(calc("1 + 2 + 10 * 2 * 3"), 63);
    assert(calc("1 + 2 + 10 / 2 * 3"), 18);
    assert(calc("1 + 2 + 10 / 2 * 3 + 1 + 1 + 3"), 23);
    assert(calc("1 + 2 + 10 / 2 * 3 % 2 + 1 + 1 + 3"), 9);
    assert(calc("1 * 1"), 1);

    puts("testing ()");
    assert(calc("1 * (1 + 1)"), 2);
    assert(calc("1 * (1 + 1 + 3 + 4)"), 9);
    assert(calc("1 * (1 + 1 + 3 + 4 * 2)"), 13);
    assert(calc("10 * (1 + 1)"), 20);
    assert(calc("2 * 10 * (1 + 1)"), 40);
    assert(calc("(1 + 3) - 1 * 2"), 2);
    assert(calc("1 * (1 + 3) - 1"), 3);
    assert(calc("1 * (1 + 3) - 1 * 2"), 2);
    assert(calc("1 * (1 + 3) - 2 * 2"), 0);
    assert(calc("1 * (1 + 3) - 2 * 2 + 15 * (2 + 3)"), 75);
    assert(calc("1 * (1 + 3) - 2 * 2 + (2 + 3) - (2 + 5)"), -2);
    assert(calc("1 * (1 + 3) - 2 * 3 + (2 + 3) * 2"), 8);

    assert(calc("1 + 10 * 2 * 2"), 41);
    assert(calc("2 + 3 + 2 * (10 + 1)"), 27);
    assert(calc("2 + 1 * (10 + 1)"), 13);
    assert(calc("50 * (10 + 1)"), 550);

    assert(calc("1 + (1 + 3)"), 5);

    assert(calc("1 + (1 + 3) * 2"), 9);
    assert(calc("1 * (1 + 3) * 2 - 2"), 6);
    assert(calc("1 * (1 + 3) * 2 * (2 + 5) - 2"), 54);

    return 0;
}
