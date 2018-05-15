#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main()
{
	int sockfd1,len1,j,a,num1,sum1,num,Q,q;
	struct sockaddr_in sa1;

	sockfd1=socket(AF_INET,SOCK_STREAM,0);
	sa1.sin_family=AF_INET;
	sa1.sin_addr.s_addr=inet_addr("127.0.0.1");
	sa1.sin_port=6002;
	
	len1=sizeof(sa1);
	j=connect(sockfd1,(struct sockaddr *)&sa1,len1);
	printf("(%d %d)\n",sockfd1,j);
	printf("Enter a number");
	scanf("%d",&num1);
	send(sockfd1,&num1,4,0);
	recv(sockfd1,&num,4,0);
	if(num1>num)
	{
		printf("Enter 10 number");
		for(q=1;q<=10;q++)
		{
			scanf("%d",&Q);
			send(sockfd1,&Q,4,0);
		}
	}
}
