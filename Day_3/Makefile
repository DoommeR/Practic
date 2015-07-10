all: UnitTest

UnitTest.o: UnitTest.c
	gcc -c -o UnitTest.o UnitTest.c

UnitTest: UnitTest.o
	gcc -o Unit UnitTest.o

clean:
	-rm -f *.o
