all: Task_1.o Task_2.o Task_1 Task_2
Task_1.o: Task_1.c 
	g++ -c -o Task_1.o Task_1.c

Task_2.o: Task_2.c
	g++ -c -o Task_2.o Task_2.c

Task_1:
	g++ -o Task1 Task_1.o

Task_2:
	g++ -o Task2 Task_2.o

clean:
	-rm -f *.o
