#include<stdio.h>
void producer();
void consumer();
int n,s,empty,full,t=0,buffer[50];

void producer()
{
	int in=0;
	char o='N';
	
	while(t<n)
	{
		empty--;
		s--;
		buffer[in]=1;
		in=(in+1)%n;
		t++;
		s++;
		full++;
		printf("Produced\n");
		printf("Continue producing-Y/N?\n");
		scanf("%s",&o);
		if(o=='N'||o=='n')
			break;
	}
	
	if(t==n)
		printf("Buffer full\n");
	
	consumer();	
}

void consumer()
{
	char o='N';
	int c,out;
	out=t;
	while(t>0)
	{
		full--;
		s--;
		c=buffer[out];
		out=(out+1)%n;
		t--;
		s++;
		empty++;
		printf("Consumed\n");
		printf("Continue consuming-Y/N?\n");
		scanf("%s",&o);
		if(o=='N'||o=='n')
			break;
	}
	if(t==0)
		printf("Buffer empty\n");
	producer();
}

int main()
{	
	printf("Enter the number of slots\n");
	scanf("%d",&n);
	empty=n;
	full=0;
	s=1;
	producer();
	
	return 0;
}
