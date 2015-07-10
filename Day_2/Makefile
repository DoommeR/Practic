all: Task_1 Task_2
Task_1.o: Task_1.c 
	gcc -c -o Task_1.o Task_1.c -lpthread

Task_2.o: Task_2.c
	gcc -c -o Task_2.o Task_2.c -lpthread

Task_1: Task_1.o
	gcc  -o Task1 Task_1.o -lpthread

Task_2: Task_2.o
	gcc -o Task2 Task_2.o -lpthread

clean:
	-rm -f *.o
