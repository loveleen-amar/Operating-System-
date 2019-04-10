// longest job first scheduling algorithm
#include <stdio.h>
# define INT_MAX 9999
void main(){
	int n, i, j;
	printf("\nEnter the number of jobs:\n");
	scanf("%d", &n);
	int at[n], bt[n], isVis[n], visited = 0;
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
		flag = 0;
		max = -1;
		tmin= INT_MAX;
		for(i = 0; i < n; i++){
			if(isVis[i] == 0){
				if(bt[i] > max && at[i] <= t){
					if(max == bt[i]){  // To consider arrival time in case of equal burst time
						if(at[i] < tmin){
							k = i;
							max = bt[i];
							tmin = at[i];
						}
					}
					else{
						k = i;
						max = bt[i];
						tmin = at[i];
					}
				}
			}
		}
		if(max == -1){ //WHEN IDEA AT STARTING .THEN TAKES THE 1ST ARRIVED PROCESS WHOSE BT IS MAX
			flag = 1;
			max = bt[0];
			tmin = INT_MAX;
			for(i = 0; i < n; i++){
				if(isVis[i] == 0){
					if(at[i] < tmin || at[i] == tmin && bt[i] > max){
						tmin = at[i];
						max = bt[i];
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

Enter the number of jobs:
6

Enter the arrival times:
0 4 2 2 7 8

Enter the burst times:
1 4 2 4 2 1

Process AT      BT      CT      TAT     WT
P1      0       1       1       1       0
P2      4       4       10      6       2
P3      2       2       12      10      8
P4      2       4       6       4       0
P5      7       2       14      7       5
P6      8       1       15      7       6

Average turnaround time = 5.833333

Average waiting time = 3.500000 */
