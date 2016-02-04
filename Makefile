all:
	gcc -g cstrcalc.c -o cstrcalc

test:
	gcc -g cstrcalc.c test.c testutils.c -o test
	./test
	rm test
