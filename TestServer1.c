#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
 int main(){
	int sockfd,len,i,p[10],fd,s,d=1,r,j;
	char b[200];
	struct sockaddr_in sa,ca;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	sa.sin_family=AF_INET;
	sa.sin_addr.s_addr=INADDR_ANY;
	sa.sin_port=1045;
	len=sizeof(sa);
	i=bind(sockfd,(struct sockaddr *)&sa,len);
	printf("(%d%d)\n",sockfd,i);
	listen(sockfd,5);
	fd=accept(sockfd,(struct sockaddr *)&ca,&len);
	printf("[%d]\n",fd);
	for(j=0;j<10;j++){
		recv(fd,p,8,0);
		if(p[j]%2==0){
			printf("Enter a number:\n");
			scanf("%d",&s);
			send(fd,p,4,0);
			send(fd,&s,4,0);
		}
		else
			send(fd,p,4,0);	
	}
	
	printf("Enter a string: ");
	scanf("%s",b);
	send(fd,b,50,0);
	return 0;
	}
	
