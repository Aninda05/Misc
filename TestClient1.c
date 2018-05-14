#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main(){
	int sockfd,len,i,p[10],fd,a,d,s=0,j;
	char b[200];
	struct sockaddr_in sa,ca;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	sa.sin_family=AF_INET;
	sa.sin_addr.s_addr=inet_addr("127.0.0.1");
	sa.sin_port=1045;
	len=sizeof(sa);
	i=connect(sockfd,(struct sockaddr *)&sa,len);
	printf("(%d%d)\n",sockfd,i);
	printf("Enter 10 numbers:\n");
	for(j=0;j<10;j++){
		scanf("%d",&p[i]);
		send(sockfd,p,8,0);
		if(p[j]%2==0){
			recv(sockfd,&a,4,0);
			recv(sockfd,p,4,0);
			printf("From server %d ",a);
			printf("From server %d ",p[j]);
	}
	else{
		recv(sockfd,p,4,0);
		printf("From server %d ",p[j]);
		}
	}
	recv(sockfd,b,40,0);
	printf("Server sent %s\n",b);
	return 0;
	}
