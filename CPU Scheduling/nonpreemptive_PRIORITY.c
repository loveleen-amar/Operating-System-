// non-preemptive priority scheduling algorithm
#include <stdio.h>
# define INT_MAX 9999
void main(){
	int n, i, j;
	printf("\nEnter the number of jobs:\n");
	scanf("%d", &n);
	int at[n], bt[n], isVis[n], visited = 0, priority[n];
	printf("\nEnter the priority:\n");
	for(j = 0; j < n; j++){
		scanf("%d", &priority[j]);
	}

	printf("\nEnter the arrival times:\n");
	for(i = 0; i < n; i++){
		scanf("%d", &at[i]);
	}
	printf("\nEnter the burst times:\n");
	for(j = 0; j < n; j++){
		scanf("%d", &bt[j]);
		isVis[j] = 0;
	}
	int t = 0, k = 0;
	int tat[n], ct[n], wt[n], flag, tmin, max, min;
	while(visited < n){
		k = 0;
		flag =0;
		max = -1;
		tmin= INT_MAX;
		for(i = 0; i < n; i++){
			if(isVis[i] == 0){
				if(priority[i] > max && at[i] <= t){
					if(max == priority[i]){  // To consider arrival time in case of equal priority
						if(at[i] < tmin){
							k = i;
							max = priority[i];
							tmin = at[i];
						}
					}
					else{
						k = i;
						max = priority[i];
						tmin = at[i];
					}
				}
			}
		}
		if(max == -1){
			flag = 1;
			max = priority[0];
			tmin = INT_MAX;
			for(i = 0; i < n; i++){
				if(isVis[i] == 0){
					if(at[i] < tmin || at[i] == tmin && priority[i] > max){
						tmin = at[i];
						max = priority[i];
						k = i;
					}
				}
			}
		}
		if(flag == 0){
			t += bt[k];
		}
		else
			t = at[k] + bt[k];
		ct[k] = t;
		isVis[k] = 1;
		visited++;
		tat[k] = ct[k] - at[k];
		wt[k] = tat[k] - bt[k];
	}
	printf("\nProcess\tPriority\tAT\tBT\tCT\tTAT\tWT\n");
	for(i = 0; i < n; i++){
		printf("P%d\t%d\t\t%d\t%d\t%d\t%d\t%d\n", i+1, priority[i], at[i], bt[i], ct[i], tat[i], wt[i]);
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

Enter the number of jobs:
7

Enter the priority:
2
4
6
10
8
12
9

Enter the arrival times:
0
1
2
3
4
5
6

Enter the burst times:
4
2
3
5
1
4
6

Process Priority        AT      BT      CT      TAT     WT
P1      2               0       4       4       4       0
P2      4               1       2       25      24      22
P3      6               2       3       23      21      18
P4      10              3       5       9       6       1
P5      8               4       1       20      16      15
P6      12              5       4       13      8       4
P7      9               6       6       19      13      7

Average turnaround time = 13.142858

Average waiting time = 9.571428 */
