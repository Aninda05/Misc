#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main()
{
	int sockfd,len,i,num1,j,m,sum=0;
	struct sockaddr_in sa;

	sockfd=socket(AF_INET,SOCK_STREAM,0);
	sa.sin_family=AF_INET;
	sa.sin_addr.s_addr=inet_addr("127.0.0.1");
	sa.sin_port=6001;
	
	len=sizeof(sa);
	i=connect(sockfd,(struct sockaddr *)&sa,len);
	printf("(%d %d)\n",sockfd,i);
	for(j=1;j<=10;j++)
	{	
		
			m=recv(sockfd,&num1,4,0);
			if(m)
			{
			printf("%d\n",num1);
			sum=sum+num1;
			}
			else
			break;
	}
	printf("the sum is %d",sum);
}
