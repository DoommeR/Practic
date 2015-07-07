#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//Task №1 "Fork+Pipe"
using namespace std;

	int main(int argc, char* argv[]) 
	{
		int pid;
		int fd[1];
		pipe(fd);
		
		switch(pid=fork())
		{
			case -1:
				cout << "Error fork" << "\n";
			return -1;
			
			case 0: //child
				char str[4];
				close(fd[1]);
				read(fd[0],str,4);
				cout << "Result=" << str << "\n";
				exit(EXIT_SUCCESS);
			return 0;   
			
			default: //parent
				close(fd[0]);
				write(fd[1],"test",4);
				cout << "Success" << "\n";
				wait();
				
			}
	}
