#include<stdio.h>

float aw,at,g;

struct Proc{
int b;
int ta,wt,pr,rt;
}p[10],t;

void fcfs(int n){
	int i;
	for(i=0;i<n;i++){
		g+=(float)p[i].b;
		p[i].ta=g;
		p[i].wt=p[i].ta-p[i].b;
		aw+=(float)p[i].wt;
		at+=(float)p[i].ta;
	}
	printf("Average waiting time is:%.2f\n",aw/n);
	printf("Average turnaround time is:%.2f\n",at/n);	
}
void sjf(int n){
	aw=at=g=0.0;
	int i,j;
	for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(p[j].b<p[i].b){
					t=p[i];
					p[i]=p[j];
					p[j]=t;
					}
				}
			}
		
		for(i=0;i<n;i++){
			g+=(float)p[i].b;
			p[i].ta=g;
			p[i].wt=p[i].ta-p[i].b;
			at+=(float)p[i].ta;
			aw+=(float)p[i].wt;
		}
		printf("Average of TurnAround is %.2f\n",(at/n));
		printf("Average of Waiting is %.2f\n",(aw/n));	
}
void priority(int n){
	aw=at=g=0.0;
	int i,j;
	printf("Enter the priorities:\n");
	for(i=0;i<n;i++)
		scanf("%d",&p[i].pr);
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(p[i].pr>p[j].pr){
				t=p[i];
				p[i]=p[j];
				p[j]=t;
			}
		}
	}
	for(i=0;i<n;i++){
		g+=(float)p[i].b;
		p[i].ta=g;
		p[i].wt=p[i].ta-p[i].b;
		at+=(float)p[i].ta;
		aw+=(float)p[i].wt;
	}
	printf("Average of TurnAround is %.2f\n",(at/n));
	printf("Average of Waiting is %.2f\n",(aw/n));	
} 
void rr(int n){
	aw=at=g=0.0;
	int i,j;
	int hb,m=1,tq;
	printf("Enter time quantum:");
	scanf("%d",&tq);
	hb=p[0].b;
	for(i=1;i<n;i++){
		if(p[i].b>hb)
			hb=p[i].b;
	}
	m=hb/tq;
	if(hb%tq!=0)
		m++;
	for(j=0;j<m;j++){	
		for(i=0;i<n;i++){
			if(p[i].rt>tq){
				g+=(float)tq;			
				p[i].rt=p[i].rt-tq;
			}
			else if(p[i].rt>0)	{			
			g+=(float)p[i].rt;
			p[i].rt=0;
			p[i].ta=g;
			p[i].wt=p[i].ta-p[i].b;
			at+=(float)p[i].ta;
			aw+=(float)p[i].wt;
			}
		}
	}
	
		printf("TurnAround is %.2f\n",at);
		printf("Waiting is %.2f\n",aw);
		printf("Average of TurnAround is %.2f\n",(at/n));
		printf("Average of Waiting is %.2f\n",(aw/n));
}
int main(){
	int n,b,i;
	
	printf("Enter number of processes:");
	scanf("%d",&n);
	printf("Enter burst times:\n");
	for(i=0;i<n;i++){
		scanf("%d",&p[i].b);
		p[i].rt=p[i].b;
	}
	printf("-----------FCFS----------\n");
	fcfs(n);
	printf("-----------SJF----------\n");
	sjf(n);
	printf("-----------Priority---------\n");
	priority(n);
	printf("------------RR------------\n");
	rr(n);
	return 0;
}
