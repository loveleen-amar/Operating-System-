// shortest remaining time first scheduling algorithm
#include <stdio.h>
# define INT_MAX 9999
void main(){
	int n, i, j;
	printf("\nEnter the number of jobs:\n");
	scanf("%d", &n);
	int at[n], bt[n], bt_copy[n], isVis[n], visited = 0;
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
				if(bt_copy[i] >= max && at[i] <= t){
					if(max == bt_copy[i]){
						if(at[i] < tmin){
							k = i;
							max = bt_copy[i];
							tmin = at[i];
						}
					}
					else{
						k = i;
						max = bt_copy[i];
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

Enter the arrival times:
0 15 30 45

Enter the burst times:
20 25 10 15

Process AT      BT      CT      TAT     WT      RT
P1      0       20      67      67      47      0
P2      15      25      68      53      28      0
P3      30      10      69      39      29      1
P4      45      15      70      25      10      0

Average turnaround time = 46.000000

Average waiting time = 28.500000

Average response time = 0.250000 */
