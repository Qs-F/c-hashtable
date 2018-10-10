test:
	gcc test.c -o test
	./test
	rm ./test

debug:
	gcc -O0 -g test.c -o test.debug
	gdb test.debug
	rm ./test.debug
