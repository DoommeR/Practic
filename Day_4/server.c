#include <stdio.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int sock, listener;
	struct sockaddr_in addr, cliaddr;
	socklen_t len;
	char buf[1024];
	int bytes_read;

	listener = socket(AF_INET, SOCK_DGRAM, 0);
	if (listener <0)
	{
		perror("socket");
		return 1;
	}
	
	
	addr.sin_family= AF_INET;
	addr.sin_port = htons(3425);
	addr.sin_addr.s_addr= htonl(INADDR_ANY);
	if(bind(listener, (struct sockaddr*)&addr, sizeof(addr))<0)
	{
		perror("bind");
		return 1;
	}
	
	while(1)
	{
			bytes_read=recvfrom(listener, buf, 1024, 0, (struct sockaddr*)&cliaddr, &len); 
			//= recv(sock, buf, 1024, 0);
			
			printf("Rcv mssg: %s\n", buf);
	}
	
	close(sock);

	
	return 0;
}
