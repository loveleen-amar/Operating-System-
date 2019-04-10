// shortest job first scheduling algorithm
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
	int tat[n], ct[n], wt[n], flag, tmin, min;
	while(visited < n){
		k = 0;
		flag = 0;
		min = INT_MAX;
		tmin= INT_MAX;
		for(i = 0; i < n; i++){
			if(isVis[i] == 0){
				if(bt[i] <= min && at[i] <= t){
					if(min == bt[i]){  // To consider arrival time in case of equal burst time
						if(at[i] < tmin){
							k = i;
							min = bt[i];
							tmin = at[i];
						}
					}
					else{
						k = i;
						min = bt[i];
						tmin = at[i];
					}
				}
			}
		}
		if(min == INT_MAX){ //no process came till now
			flag = 1;
			min = bt[0];
			tmin = INT_MAX;
			for(i = 0; i < n; i++){
				if(isVis[i] == 0){
					if(at[i] < tmin || at[i] == tmin && bt[i] < min){ //`cal min bt
						tmin = at[i];
						min = bt[i];
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

/*Enter the number of jobs:
6

Enter the arrival times:
0 4 2 2 7 8

Enter the burst times:
1 4 2 4 2 1

Process AT      BT      CT      TAT     WT
P1      0       1       1       1       0
P2      4       4       15      11      7
P3      2       2       4       2       0
P4      2       4       8       6       2
P5      7       2       11      4       2
P6      8       1       9       1       0

Average turnaround time = 4.166667

Average waiting time = 1.833333*/
