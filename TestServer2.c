#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
 int main(){
	int sockfd,len,i,fd,a,b,c,d,sockfd1,len1,i1,fd1,j,x,y;
	struct sockaddr_in sa,ca,sa1,ca1;
	
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	sa.sin_family=AF_INET;
	sa.sin_addr.s_addr=INADDR_ANY;
	sa.sin_port=1045;
	
	sockfd1=socket(AF_INET,SOCK_STREAM,0);
	sa1.sin_family=AF_INET;
	sa1.sin_addr.s_addr=INADDR_ANY;
	sa1.sin_port=1065;
	
	len=sizeof(sa);

	len1=sizeof(sa1);
	
	i=bind(sockfd,(struct sockaddr *)&sa,len);
	printf("(%d%d)\n",sockfd,i);
	
	i1=bind(sockfd1,(struct sockaddr *)&sa1,len1);
	printf("(%d%d)\n",sockfd1,i1);
	
	listen(sockfd,5);
	
	listen(sockfd1,5);
	
	fd=accept(sockfd,(struct sockaddr *)&ca,&len);
	printf("[%d]\n",fd);
	
	fd1=accept(sockfd1,(struct sockaddr *)&ca1,&len1);
	printf("[%d]\n",fd1);
	
	printf("Enter 10 pairs :\n");
	for(j=1;j<10;j++){
		scanf("%d%d",&x,&y);
	if(x==1)
		send(fd,&y,4,0);
	if(x==2)
		send(fd1,&y,4,0);
	}
}
	
	
	
	
	
