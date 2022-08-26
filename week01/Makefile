PROGS = hello args echo echorepeat intstr_to_int

all : ${PROGS}

hello : hello.c
	gcc -o hello hello.c

args : args.c
	gcc -o args args.c

echo : echo.c
	gcc -o echo echo.c

echorepeat : echorepeat.c
	gcc -o echorepeat echorepeat.c

intstr_to_int : intstr_to_int.c
	gcc -o intstr_to_int intstr_to_int.c

clean :
	rm ${PROGS}
