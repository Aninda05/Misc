#include<stdio.h>
#include<sys/types.h>
int main(){
	int id;
	printf("Process id :%d",getpid());
	id=fork();
	if(id==0){
		printf("Parent id :%d",getppid());
		}
	if(id>0){
		printf("Child id:%d",id);
	}
	return 0;
}
