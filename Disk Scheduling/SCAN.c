// SCAN (elevator) disk scheduling algorithm
#include <stdio.h>
int main(){
	int n, i, j, head, sum = 0, tracks;
	printf("Enter the total number of tracks:\n");
	scanf("%d",&tracks);
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
	int flag = 0, casee = 0;
	while(flag != 2){
		printf("Enter the direction (u/d):\n");
		scanf(" %c",&x);
		switch(x){
			case 'u':{
				flag = 2;
				casee = 1;
				break;
			}
			case 'd':{
				flag = 2;
				casee = 2;
				break;
			}
			default:
			printf("\nWrong entry!\n");
		}
	}
	if(casee == 1){
		// finding the minimum element
		int min = rq[0];
		int k = 0;
		for(i = 1; i < n; i++){
			if(rq[i] < min){
				min = rq[i];
				k = i;
			}
		}
		sum = 2 * tracks - min - head - 2;
	}
	else if(casee == 2){
		// finding the maximum element
		int max = rq[0];
		int k = 0;
		for(i = 1; i < n; i++){
			if(rq[i] > max){
				max = rq[i];
				k = i;
			}
		}
		sum = head + max;
	}
	printf("Total number of track movements = %d\n", sum);
	return 0;
}


/*
Enter the total number of tracks:
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
Total number of track movements = 332*/
