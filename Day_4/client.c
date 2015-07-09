#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
	char message[]="Hello world!\n";
	char buf[sizeof(message)];
	int sock;
	struct sockaddr_in addr, cliaddr;

	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock<0)
	{
		perror("socket");
		return 1;
	}

	addr.sin_family= AF_INET;
	addr.sin_port = htons(3425);
	addr.sin_addr.s_addr= htonl(INADDR_LOOPBACK);
	
	/*
	 *if(connect(sock, (struct sockaddr *)&addr, sizeof(addr))<0)
	 *{
	 *	perror("connect");
	 *	return 1;
	 *}
	 */
		sendto(sock,message,sizeof(message),0,(struct sockaddr *)&addr,sizeof(addr));
		//send(sock, message, sizeof(message), 0);
	
	close(sock);

	return 0;
}
