// shortest seek time first disk scheduling algorithm
#include <stdio.h>
int main(){
	int n, i, j, head, temp;
 	printf("Enter the number of tracks in request queue:\n");
 	scanf("%d", &n);
 	printf("Enter position of R/W Head:\n");
 	scanf("%d", &head);
 	int rq[n+1], visited[n+1];
 	printf("Enter the track numbers:\n");
 	for(i = 0; i < n; i++){
 		scanf("%d", &rq[i]);
 		visited[i] = 0;
 	}
 	visited[n] = 0;
 	rq[n] = head;
 	/*for(i = 0; i < n + 1; i++)
 		printf("%d ", rq[i]);
 	printf("\n");
 	*/
 	for(j = 0; j < n + 1; j++){ //bubble sort
		for(i = j + 1; i < n + 1; i++){
			if(rq[i] < rq[j]){
				temp = rq[i];
				rq[i] = rq[j];
				rq[j] = temp;
			}
		}
	}
	
 	for(i = 0; i < n + 1; i++){ //to find the index of head
 		if(rq[i] == head){
 			temp = i;
 			visited[i] = 1;
 			break;
 		}
 	}

 	int count = 0, back= temp, sum = 0, front = temp, first, second;
 	while(count < n){
 		count++;
 		int flag = 0, flag2 = 0;
 		while(visited[back] != 0 && back > 0){
 			flag = 1;
 			back = back - 1;
 		}
 		while(visited[front] != 0 && front < n){
 			flag2 = 1;
 			front = front + 1;
 		}
 		if(flag == flag2 == 1){
 			first = rq[front] - head;
 			second = head - rq[back];
 			if(first <= second){
 				visited[front] = 1;
 				head = rq[front];
 				sum += first;
 				back = front;
 			}
 			else if(second < first){
 				visited[back] = 1;
 				head = rq[back];
 				sum += second;
 				front = back;
 			}
 		}
 		else if(flag == 1){
 			second = head - rq[back];
 			visited[back] = 1;
 			head = rq[back];
 			sum += second;
 			front = back;
 		}
 		else{
 			first = rq[front] - head;
 			visited[front] = 1;
 			head = rq[front];
 			sum += first;
 			back = front;
 		}

 	}
	printf("\nTotal number of track movements = %d\n", sum);
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

Total number of track movements = 208*/
