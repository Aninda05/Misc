#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main()
{
	int sockfd,fd,sockfd1,fd1,sockfd2,fd2,sockfd3,fd3,len,len1,len2,len3,i,p,k,l,num,num1,j;

	struct sockaddr_in sa,ca,sa1,ca1,sa2,ca2,sa3,ca3;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	sockfd1=socket(AF_INET,SOCK_STREAM,0);
	sockfd2=socket(AF_INET,SOCK_STREAM,0);
	sockfd3=socket(AF_INET,SOCK_STREAM,0);
	sa.sin_family=AF_INET;
	sa.sin_addr.s_addr=INADDR_ANY;
	sa.sin_port=6001;

	sa1.sin_family=AF_INET;
	sa1.sin_addr.s_addr=INADDR_ANY;
	sa1.sin_port=6002;

	sa2.sin_family=AF_INET;
	sa2.sin_addr.s_addr=INADDR_ANY;
	sa2.sin_port=6003;

	sa3.sin_family=AF_INET;
	sa3.sin_addr.s_addr=INADDR_ANY;
	sa3.sin_port=6004;

	
	len=sizeof(sa);
	len1=sizeof(sa1);
	len2=sizeof(sa2);
	len3=sizeof(sa3);
	i=bind(sockfd,(struct sockaddr *)&sa,len);
	p=bind(sockfd1,(struct sockaddr *)&sa1,len1);
	k=bind(sockfd2,(struct sockaddr *)&sa2,len2);
	l=bind(sockfd3,(struct sockaddr *)&sa3,len3);
	printf("(%d %d)\n",sockfd,i);
	printf("(%d %d)\n",sockfd1,p);
	printf("(%d %d)\n",sockfd2,k);
	printf("(%d %d)\n",sockfd3,l);
	listen(sockfd,5);
	listen(sockfd1,5);
	listen(sockfd2,5);
	listen(sockfd3,5);
	fd=accept(sockfd,(struct sockaddr *)&ca,&len);
	fd1=accept(sockfd1,(struct sockaddr *)&ca1,&len1);
	printf("[%d]\n",fd);
	printf("[%d]\n",fd1);
	fd2=accept(sockfd2,(struct sockaddr *)&ca2,&len2);
	fd3=accept(sockfd3,(struct sockaddr *)&ca3,&len3);
	printf("[%d]\n",fd2);
	printf("[%d]\n",fd3);
	for(j=1;j<=10;j++)
	{
		recv(fd,&num,4,0);
		recv(fd1,&num1,4,0);
		send(fd2,&num,4,0);
		send(fd3,&num1,4,0);
	}
}
