#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
main()
{
	int sockfd1,len1,j,num1;
	struct sockaddr_in sa1;

	sockfd1=socket(AF_INET,SOCK_STREAM,0);
	sa1.sin_family=AF_INET;
	sa1.sin_addr.s_addr=inet_addr("127.0.0.1");
	sa1.sin_port=6002;
	
	len1=sizeof(sa1);
	j=connect(sockfd1,(struct sockaddr *)&sa1,len1);
	printf("(%d %d)\n",sockfd1,j);
	recv(sockfd1,&num1,4,0);
	printf("Server sent %d\n",num1);
}
