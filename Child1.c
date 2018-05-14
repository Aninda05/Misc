#include<stdio.h>
#include<sys/types.h>
int main()
{
	int id;
	id=fork();
	printf("Before child\n");
	printf("The id is:%d",id);
	if(id>0)
		printf("The id is:%d",id);
	return 0;
}
