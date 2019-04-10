// preemptive priority scheduling algorithm
#include <stdio.h>
# define INT_MAX 9999
void main(){
	int n, i, j;
	printf("\nEnter the number of jobs:\n");
	scanf("%d", &n);
	int at[n], bt[n], bt_copy[n], priority[n], isVis[n], visited = 0;
	printf("\nEnter the priorities:\n");
	for(i = 0; i < n; i++){
		scanf("%d", &priority[i]);
	}
	printf("\nEnter the arrival times:\n");
	for(i = 0; i < n; i++){
		scanf("%d", &at[i]);
	}
	printf("\nEnter the burst times:\n");
	for(j = 0; j < n; j++){
		scanf("%d", &bt[j]);
		bt_copy[j] = bt[j];
		isVis[j] = 0;
	}
	int t = 0, k = 0;
	int tat[n], ct[n], wt[n], rt[n], flag, tmin, max;
	while(visited < n){
		k = 0;
		max = -1;
		tmin= INT_MAX;
		for(i = 0; i < n; i++){
			if(isVis[i] == 0){
				if(priority[i] >= max && at[i] <= t){
					if(max == priority[i]){
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
		t++;
		if(max != -1){
			if(bt_copy[k] == bt[k]){
				rt[k] = t - at[k] - 1;
			}
			bt_copy[k] -= 1;
			if(bt_copy[k] == 0){
				ct[k] = t;
				isVis[k] = 1;
				visited++;
				tat[k] = ct[k] - at[k];
				wt[k] = tat[k] - bt[k];
			}
		}
	}
	printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");
	for(i = 0; i < n; i++){
		printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
	}
	float avg_tat = 0, avg_wt = 0, avg_rt = 0;
	for(i = 0; i < n; i++){
		avg_tat += tat[i];
		avg_wt += wt[i];
		avg_rt += rt[i];
	}
	printf("\nAverage turnaround time = %f\n", avg_tat/n);
	printf("\nAverage waiting time = %f\n", avg_wt/n);
	printf("\nAverage response time = %f\n", avg_rt/n);
}

/* 
Enter the number of jobs:
4

Enter the priorities:
10 20 30 40

Enter the arrival times:
0 1 2 4

Enter the burst times:
5 4 2 1

Process AT      BT      CT      TAT     WT      RT
P1      0       5       12      12      7       0
P2      1       4       8       7       3       0
P3      2       2       4       2       0       0
P4      4       1       5       1       0       0

Average turnaround time = 5.500000

Average waiting time = 2.500000

Average response time = 0.000000 */
