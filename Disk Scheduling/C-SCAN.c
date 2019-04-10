// C-SCAN disk scheduling algorithm
#include <stdio.h>
int main(){
	int n, i, j, head, sum = 0, track;
	printf("Enter the total number of tracks\n");
	scanf("%d", &track);
	printf("Enter the number of tracks in request queue:\n");
	scanf("%d", &n);
	printf("Enter position of R/W Head:\n");
	scanf("%d", &head);
	int rq[n];
	printf("Enter the track numbers:\n");
	for(i = 0; i < n; i++){
		scanf("%d", &rq[i]);
	}
	char x;
	int flag = 0;
	while(flag != 2){
		printf("Enter the direction (u/d):\n");
		scanf(" %c", &x);
		int min = rq[0], max = rq[0], k = 0;
		for(i = 1; i < n; i++){
			if(rq[i] < min){
				min = rq[i];
				k = i;
			}
		}
		k = 0;
		for(i = 1; i < n; i++){
			if(rq[i] > max){
				max = rq[i];
				k = i;
			}
		}
		k = 0;
		switch(x){
			case 'u':{
				flag = 2;
				int min2 = min;
				for(i = 0; i < n; i++){
					if(rq[i] <= head && rq[i] >= min2){
						min2 = rq[i];
						k = i;
					}
				}
				sum = 2 * (track-1) - head + rq[k];
				//printf("max = %d head = %d rq[k] = %d min = %d", max, head, rq[k], min);
				break;
			}
			
			case 'd':{
				flag = 2;
				int max2 = max;
				for(i = 0; i < n; i++){
					if(rq[i] >= head && rq[i] <= max2){
						max2 = rq[i];
						k = i;
					}
				}
				//printf("max = %d head = %d rq[k] = %d min = %d", max, head, rq[k], min);
				sum = 2 * (track - 1) + head - rq[k];
				break;
			}
			default:
			printf("\nWrong entry!\n");
		}
	}
	printf("Total number of track movements = %d\n", sum);
	return 0;
}

/* Enter the total number of tracks
200
Enter the number of tracks in request queue:
7
Enter position of R/W Head:
50
Enter the track numbers:
82
170
43
140
24
16
190
Enter the direction (u/d):
u
Total number of track movements = 391 */
