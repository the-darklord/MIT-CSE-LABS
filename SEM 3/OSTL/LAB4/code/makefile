final:	push pop display main createlib
	gcc -o main main.o mihir.a
createlib:
	ar crv mihir.a push.o pop.o display.o
main:
	gcc -c main.c
push:
	gcc -c push.c
pop:
	gcc -c pop.c
display:
	gcc -c display.c
