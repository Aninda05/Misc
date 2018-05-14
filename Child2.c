#include<stdio.h>
#include<sys/types.h>
int main()
{
	fork();
	printf("%d",getpid());
	printf("%d",getppid());
	return 0;
}
