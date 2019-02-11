/*
 * proxy.c
 *
 *  Created on: Feb 4, 2019
 *      Author: alex
 */

#include <sys/socket.h>
#include <resolv.h>
#include <netinet/in.h>
#define ERR_COULD_BIND 1
#define ERR_COULD_LISTEN 2

int main()
{

struct sockaddr_in myaddr;
int sd;

myaddr.sin_family = AF_INET;
myaddr.sin_port = htons(3491);

inet_aton("127.0.0.1", &myaddr.sin_addr.s_addr);

sd = socket(PF_INET, SOCK_STREAM, 0);
int result = bind(sd, &myaddr, sizeof(myaddr));
if(result !=0)
{
	printf("Couldnt bind %d" , ERR_COULD_BIND);
	return ERR_COULD_BIND;
}
printf("Trying to connection");
result = listen(sd,10);
if(result != 0)
{
	printf("FAILURE %d", ERR_COULD_LISTEN );
	return 1;
}
for (;;)
{
	//printf("Waiting for connection");
	int clientsd = accept(sd , &myaddr, sizeof(myaddr));
	if(clientsd>0)
	{
		close(clientsd);
		//printf("Couldnot connect");
		//return 3;
	}
	else{
	printf ("ERROR");
	}
}

return 0;
}
