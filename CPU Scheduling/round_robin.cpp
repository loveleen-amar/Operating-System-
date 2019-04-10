#include<stdio.h>
#include<limits.h>

int k,l;

void pop(int pr[],int n)
{
//	printf("popped:%d l:%d\n",pr[l],l+1);
	l++;
}

void push(int pr[],int n, int p)
{
	k++;
	pr[k]=p;
//	printf("pushed:%d k:%d\n",pr[k],k);
}

int main()
{
	int n,i,j,m,min=INT_MAX,c=0,count=0,z=0,r,tq,flag=0;
	float av_wt=0;
	float av_tat=0;
	float av_rt=0;
	
	printf("Enter number of processes\n");
	scanf("%d",&n);
	
	int a[n],b[n],ct[n],bt[n],tat[n],wt[n],ac[n],btc[n],p[20*n],rt[n],pr[20*n],v[n];
	    
	printf("Enter arrival time\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		ac[i]=a[i];
		b[i]=i;
		rt[i]=INT_MAX;
		v[i]=0;
		if(min>a[i])
			min=a[i];
	}
	
	printf("Enter burst time\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
		btc[i]=bt[i];
	}
	
	printf("Enter Time Quanta\n");
	scanf("%d",&tq);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i]<a[j])
			{
				m=a[i];
				a[i]=a[j];
				a[j]=m;
				
				m=b[i];
				b[i]=b[j];
				b[j]=m;
			}
		}
	}
	
	printf("Order:\n");
	
	if(min!=0)
	{
		printf("|idle for %d sec| ",min);
		c=min;
	}
	//printf("c:%d",c);
	l=k=0;
	pr[l]=b[0];
	v[b[0]]=1;
	

	for(i=c;i<INT_MAX;)
	{
		while(l<=k)
		{
			//if(a[pr[l]]<=i)
		//	{
				printf("P%d ",pr[l]+1);
				if(bt[pr[l]]<tq)
				{
					
					//printf("P%d is here\n",pr[l]+1);
					r=i;
					//pr[k]=b[j];
					if(rt[pr[l]]>r)
					{
						rt[pr[l]]=r;
					}
					i=i+bt[pr[l]];
					
					for(z=0;z<n;z++)
					{
						if(ac[b[z]]<=i&&v[b[z]]==0)
						{
							//printf("pushing %d\n",b[z]+1);
							push(pr,n,b[z]);
							//pr[++k]=b[z];
							v[b[z]]=1;
						}
					}
					ct[pr[l]]=c+bt[pr[l]];
					c=ct[pr[l]];
					bt[pr[l]]=0;
					//printf("P:%d bt:%d",pr[l],bt[pr[l]]);
					count++;
					if(count==n)
					{
						pop(pr,n);
						break;
					}
					else
						pop(pr,n);
					//pop(pr,n);
					//break;
				}
				else
				{
					bt[pr[l]]=bt[pr[l]]-tq;
					//printf("P%d bt:%d\n",pr[l]+1,bt[pr[l]]);
					ct[pr[l]]=tq+c;
					c=ct[pr[l]];
					r=i;
					i=i+tq;
					if(rt[pr[l]]>r)
					{
						rt[pr[l]]=r;
					}
					for(z=0;z<n;z++)
						{
							if(ac[b[z]]<=i&&v[b[z]]==0)
							{
								//printf("pushing %d\n",b[z]+1);
								push(pr,n,b[z]);
								v[b[z]]=1;
							}
						}
					
					if(bt[pr[l]]==0)
					{
						pop(pr,n);
						count++;
						break;
					}
					else
					{
						push(pr,n,pr[l]);
						v[pr[l]]=1;
					}
					pop(pr,n);
					
				}
			//}
		}
		
		if(count==n)
			break;

	}
	for(i=0;i<n;i++)
	{
		tat[i]=ct[i]-ac[i];
		wt[i]=tat[i]-btc[i];
		rt[i]=rt[i]-ac[i];			
	}
	
	
	printf("\n");
		
	printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\tResponse Time\n");
	
	for(i=0;i<n;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d\n",i+1,ac[i],btc[i],ct[i],tat[i],wt[i],rt[i]);
	}
	
		for(i=0;i<n;i++)
		{
			av_tat=tat[i]+av_tat;
			av_wt=wt[i]+av_wt;
			av_rt=rt[i]+av_rt;
		}
		printf(" avg tat : %f \n avg wt : %f \n avg rt : %f\n",(av_tat/n),(av_wt/n),(av_rt/n));

return 0;

}

/* Enter number of processes
6
Enter arrival time
0 1 2 3 4 6
Enter burst time
4 5 2 1 6 3
Enter Time Quanta
2
Order:
P1 P2 P3 P1 P4 P5 P2 P6 P5 P2 P6 P5
Process Arrival Time    Burst Time      Completion Time Turn Around Time        Waiting Time    Response Time
1               0               4               8               8                       4           0
2               1               5               18              17                      12          1
3               2               2               6               4                       2           2
4               3               1               9               6                       5           5
5               4               6               21              17                      11          5
6               6               3               19              13                      10          7
 avg tat : 10.833333
 avg wt : 7.333333
 avg rt : 3.333333 */
