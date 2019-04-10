// first come first serve scheduling algorithm
#include<stdio.h>
void main(){
	int n, i;
	printf("\nEnter the number of jobs:\n");
	scanf("%d", &n);
	int at[n], bt[n], at_copy[n];
	printf("\nEnter the arrival time:\n");
	for(i = 0; i < n; i++){
		scanf("%d", &at[i]);
		at_copy[i] = at[i];	
	}
	printf("\nEnter the burst time:\n");
	for(i = 0; i < n; i++)
		scanf("%d", &bt[i]);
	int priority[n], min = at_copy[0], k = 0, j;
	for(j = 0; j < n; j++){  //sorting at[]
		min = at_copy[0];
		k = 0;
		for(i = 0; i < n; i++){
			if(at_copy[i] < min){
				min = at_copy[i];
				k = i;
			}
		}
		at_copy[k] = 999;
		priority[j] = k;
	}
	int ct[n], wt[n], tat[n], t = 0;
	for(i = 0; i < n; i++){
		if(at[priority[i]] > t)
			t = at[priority[i]];
		t += bt[priority[i]];
		ct[priority[i]] = t;
		tat[priority[i]] = ct[priority[i]] - at[priority[i]];
		wt[priority[i]] = tat[priority[i]] - bt[priority[i]];
	}
	printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
	for(i = 0; i < n; i++){
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
	}
	float avg_tat = 0, avg_wt = 0;
	for(i = 0; i < n; i++){
		avg_tat += tat[i];
		avg_wt += wt[i];
	}
	printf("\nAverage turnaround time = %f\n", avg_tat/n);
	printf("\nAverage waiting time = %f\n", avg_wt/n);
}

/*
1
4
5
6
6
8

Enter the burst time:
2
3
4
5
6
1

Process AT      BT      CT      TAT     WT
P1      1       2       3       2       0
P2      4       3       7       3       0
P3      5       4       11      6       2
P4      6       5       16      10      5
P5      6       6       22      16      10
P6      8       1       23      15      14

Average turnaround time = 8.666667

Average waiting time = 5.166667 */
