#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main()
{
	int sockfd,len,i,a,num,num1,Q,q;
	struct sockaddr_in sa;

	sockfd=socket(AF_INET,SOCK_STREAM,0);
	sa.sin_family=AF_INET;
	sa.sin_addr.s_addr=inet_addr("127.0.0.1");
	sa.sin_port=6001;
	
	len=sizeof(sa);
	i=connect(sockfd,(struct sockaddr *)&sa,len);
	printf("(%d %d)\n",sockfd,i);
	printf("Enter a number");
	scanf("%d",&num);
	send(sockfd,&num,4,0);
	recv(sockfd,&num1,4,0);
	if(num>num1)
	{
		printf("Enter 10 number");
		for(q=1;q<=10;q++)
		{
			scanf("%d",&Q);
			send(sockfd,&Q,4,0);
		}
	}
}
