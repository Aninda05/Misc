#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main()
{
	int sockfd3,len3,s,num1,p;
	struct sockaddr_in sa3;

	sockfd3=socket(AF_INET,SOCK_STREAM,0);
	sa3.sin_family=AF_INET;
	sa3.sin_addr.s_addr=inet_addr("127.0.0.1");
	sa3.sin_port=6003;
	
	len3=sizeof(sa3);
	s=connect(sockfd3,(struct sockaddr *)&sa3,len3);
	printf("(%d %d)\n",sockfd3,s);
	printf("the server send\n");
	for(p=1;p<=10;p++)
	{
		recv(sockfd3,&num1,4,0);
		printf("%d",num1);
	}
}
