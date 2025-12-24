#include<stdio.h>
#include<stdlib.h>
#include"queueADT.h"

int main() {
	struct QueueWithStacks queue;
	initQueue(&queue, 3);

	enqueue(&queue, 1);
	enqueue(&queue, 2);
	enqueue(&queue, 3);
	printf("Dequeued: %d\n", dequeue(&queue));
	printf("Dequeued: %d\n", dequeue(&queue));

	//enqueue(&queue, 4);
	printf("Dequeued: %d\n", dequeue(&queue));
	printf("Dequeued: %d\n", dequeue(&queue));

	return 0;
}
