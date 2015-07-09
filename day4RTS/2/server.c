#include <stdio.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main
{
	int sock, listener;
	struct sockaddr_in addr;
	char buff[1024];
	int bytes_read;

	listner = socket(AF_INET, SOCK_STREAM, 0);
	if (listener <0)
	{
		perror("socket");
		return 1;
	}

	addr.sin_family= AF_INET;
	addr.sim_port = htons(3425);
	addr.sin_addr,sin_addr= htonl(INADDR_ANY);
	if(bind(listner, (struct sockaddr*)&addr, sizeof(addr))<0)
	{
		perror("bind");
		return 1;
	}

	listen(listner,1);
	while(1)
	{
			sock=accept(listner,NULL,NULL);
			if (sock<0)
			{
				perror("accept");
				return 1;
			}
		

		while(1)
		{
			bytes_read = recv(sock, buf, 1024, 0);
			if(bytes_read<=0)
			{
				break;
			}
			printf("Rcv mssg: %s\n", buf);
		}
	close(sock);

	}
	return 0;
}
