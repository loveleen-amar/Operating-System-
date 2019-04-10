// LOOK disk scheduling algorithm
#include <stdio.h>
int main(){
	int n, i, j, head, sum = 0;
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
		switch(x){
				case 'u':{
				flag = 2;
				sum=(max-head)+(max-min);
				//sum = 2 * max - min - head;
				break;
			}
			case 'd':{
				flag = 2;
				sum = head + max - 2 * min;
				break;
			}
			default:
			printf("\nWrong entry!\n");
		}
	}
	printf("Total number of track movements = %d\n", sum);
	return 0;
}

/*
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
Total number of track movements = 314 */
