all: Broadcast

UnitTest.o: UnitTest.c
	gcc -c -o UnitTest.o UnitTest.c

Broadcast.o: broadcast.c
	gcc -c -o Broadcast.o broadcast.c -lpthread

UnitTest: UnitTest.o
	gcc -o Unit UnitTest.o

Broadcast: Broadcast.o
	gcc -o Broadcast Broadcast.o -lpthread
clean:
	-rm -f *.o
