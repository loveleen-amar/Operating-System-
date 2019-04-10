#include<stdio.h>

void eat(int[],int);
void stop(int[],int);
void thinking();

void thinking()
{
	printf("Philospher is in thinking state\n");
}

void eat(int f[],int n)
{
	int r,i=0;
	char o='Y';
	while(true)
	{
		thinking();
		if(f[i]==0&&f[(i+1)%n]==0)
		{
			//p[i]=i;
			//p[i+1]=(i+1)%n;
			f[i]=1;
			f[(i+1)%n]=1;
		}
		else
		{
			printf("Philospher %d can't eat\n",i);
			printf("1-Try next philospher or 2-stop philospher from eating?\n");
			scanf("%d",&r);
			if(r==1){
				i=(i+1)%n;
				continue;
			}
			else
			{
				stop(f,n);
			}
		}
		printf("Philospher %d took forks %d & %d\n",i,i,i+1);
		printf("Want more philosphers to eat-Y/N?");
		scanf("%s",&o);
		if(o=='N'||o=='n')
			break;
		else
		{
			i=(i+1)%n;
			continue;
		}
		
	}
	printf("Stoping some philosphers from eating\n");
		stop(f,n);
}

void stop(int f[],int n)
{
	int j=0;
	char p='Y',o='Y';
	while(true)
	{
		//printf("continuing\n");
		//printf("%d\n",j);
		if(f[j]==1&&f[(j+1)%n]==1)
		{
			//printf("Found eating\n");
			//p[i]=-100;
			f[j]=0;
			//p[i+1]=-100;
			f[(j+1)%n]=0;
			printf("Philospher %d released forks %d & %d\n",j,j,j+1);
			printf("Want to check if more philosphers from eating-Y/N?");
			scanf("%s",&o);
			if(o=='n'||o=='N')
				break;
			else
			{
//				if(j==n-1)
//				{
//					j=0;
//					printf("here1\n");
//					continue;
//				}
//				else
//				{
//					j++;
//					printf("here2\n");
//					continue;
//				}

				j=(j+1)%n;
				continue;
			}
		}
		else
		{
			printf("Philospher %d not eating\n",j);
			int temp = j;
			printf("Look for another eating philospher-Y/N?\n");
			scanf("%s",&p);
//			printf("ab %d %d\n",j,temp);
			if(p=='n'||p=='N')
				break;
			else
			{
				//printf("waba luba dub dub\n");
				//printf("above %d\n",j);
				j=(j+1)%n;
				//printf("incrementing now %d\n",j);
				continue;
			}
		}
	}
	printf("Philospher start eating\n");
	eat(f,n);
		
}

int main()
{
	int i,n;
	
	printf("Enter the number of forks\n");
	scanf("%d",&n);
	
	int f[n];
	for(i=0;i<n;i++)
	{
		f[i]=0;
	}
	
	eat(f,n);
	
	return 0;
	
}
