#include<stdio.h>
#include<sys/types.h>
int main()
{
	int id,id1,id2;
	id=fork();
	
	if(id>0){
		printf("Child1 id: %d",id);	
		id1=fork();
		if(id1>0){
			printf("Child2 id: %d",id1);
			id2=fork();			
				if(id2>0)
					printf("Child1 id: %d",id2);
				if(id2==0)
					printf("Parent id:%d",getppid());
			}
		if(id1==0)
			printf("Parent id:%d",getppid());	
		}	
	if(id==0)
		printf("Parent id:%d",getppid());
	return 0;
}	
		
