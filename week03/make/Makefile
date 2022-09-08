
hello : hello.o print_hello.o
	gcc -o hello hello.o print_hello.o

hello.o : hello.c
	gcc -c -o hello.c hello.c

print_hello.o : print_hello.c
	gcc -c -o print_hello.c print_hello.c

clean :
	rm hello
