#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
//Task ¹2 "Fork+pipe+exec()"

using namespace std;

	int main(int argc, char* argv[]) 
	{
		int pid;
		int fd[2];
		pipe(fd);

		
		switch(pid=fork())
		{
			case -1:
				cout << "Error fork" << "\n";
			return -1;
			
			case 0: //child
				int ex;
				char str[1];
				cout << "Child_Start...\n";
				close(fd[0]);
				dup2(fd[1],STDOUT_FILENO);	
				ex = execl("/bin/ls","ls", "-l", "/tmp/", NULL);
				
				if (ex == -1) perror("execl");
				cout << "Child_Finished!\n";
				
				exit(EXIT_SUCCESS);
			return 0;   
			
			default: //parent
				int a;
				char buf[900]="";
				cout << "Parent_Start..." << "\n";
				close(fd[1]);
				read(fd[0],buf,sizeof(buf));
				for (int i=0;i<500;i++) {cout <<buf[i]<<" ";}
				cout << "\n";
				wait(&a);
				cout << "Parent_Finished!\n";
			}
	}
