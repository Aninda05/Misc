#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main(){
	int sockfd,len,i,a,j;
	struct sockaddr_in sa,ca;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	sa.sin_family=AF_INET;
	sa.sin_addr.s_addr=inet_addr("127.0.0.1");
	sa.sin_port=1045;
	len=sizeof(sa);
	i=connect(sockfd,(struct sockaddr *)&sa,len);
	printf("(%d%d)\n",sockfd,i);
	for(j=1;j<10;j++){
	recv(sockfd,&a,4,0);
	printf("Number received: %d",a);
	}
}
