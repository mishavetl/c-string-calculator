all:
	mkdir -p bin
	gcc src/cstrcalc.c src/main.c -o bin/calc

test:
	mkdir -p bin
	gcc -g src/cstrcalc.c tests/test.c tests/testutils.c -o bin/test
	./bin/test
	rm bin/test

dev:
	mkdir -p bin
	gcc -g -Wall src/main.c src/cstrcalc.c -o bin/calc

clean:
	rm -rf bin
