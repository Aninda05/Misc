#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet.h>
#include<arpa/inet.h>

main(){
	int sockfd,len,i,len,i,a,b,p,c,m,n,fd;
	struct sockaddr_in sa,ca;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	sa.sin_family=AF_INET;
	sa.sin_addr.s_addr=INADDR_ANY;
	sa.sin_port=1035;
	len=sizeof(sa);
	i=bind(sockfd,(struct sockaddr *)&sa,len);
	printf("(%d%d)/n",sockfd,i);
	listen(sockfd,5);
	fd=accept(sockfd,(struct sockaddr *)&ca,&len);
	printf("[%d]/n",fd);
	}
