#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main()
{
	int sockfd2,len2,m,num,n;
	struct sockaddr_in sa2;

	sockfd2=socket(AF_INET,SOCK_STREAM,0);
	sa2.sin_family=AF_INET;
	sa2.sin_addr.s_addr=inet_addr("127.0.0.1");
	sa2.sin_port=6004;
	
	len2=sizeof(sa2);
	m=connect(sockfd2,(struct sockaddr *)&sa2,len2);
	printf("(%d %d)\n",sockfd2,m);
	printf("the server send\n");
	for(n=1;n<=10;n++)
	{
		recv(sockfd2,&num,4,0);
		printf("%d",num);
	}
}
