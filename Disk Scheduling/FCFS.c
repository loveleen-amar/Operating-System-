// first come first serve disk scheduling algorithm
#include <stdio.h>
int main(){
	int n, i, j, head, mov, sum = 0;
 	printf("Enter the number of tracks in request queue:\n");
 	scanf("%d", &n);
 	printf("Enter position of R/W Head:\n");
 	scanf("%d", &head);
 	int rq[n];
 	printf("Enter the track numbers:\n");
 	for(i = 0; i < n; i++){
 		scanf("%d", &rq[i]);
 		mov = head - rq[i];
 		if(mov < 0){
 			mov = rq[i] - head;
 		}
 		head = rq[i];
 		sum = sum + mov;
 		
 	}
	printf("\nTotal number of track movements = %d\n", sum);
 	return 0;
}

/*Enter the number of tracks in request queue:
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

Total number of track movements = 642
*/


