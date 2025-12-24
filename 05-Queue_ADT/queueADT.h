#include <stdio.h>
#include <stdlib.h>

struct stack {
	int size;
	int top;
	int data[100];
};

void init(struct stack *s, int limit) {
	s->size = limit;
	s->top = -1;
}

int isFull(struct stack *s) {
	if (s->top < s->size - 1) {
    	return 0;
	} else {
    	return 1;
	}
}
int isEmpty(struct stack *s) {
	if (s->top == -1) {
    	return 1;
	} else {
    	return 0;
	}
}

void push(struct stack *s, int x) {
	if (!isFull(s)) {
    	s->data[++(s->top)] = x;
    	printf("\nPushed %d\n", x);
	} else {
    	printf("\nStack is full");
	}
}


void pop(struct stack *s) {
	if (!isEmpty(s)) {
    	s->top--;
	} else {
    	printf("\nStack is empty");
	}
}



int peek(struct stack *s) {
	if (!isEmpty(s)) {
    	return s->data[s->top];
	} else {
    	return -1;
	}
}


struct QueueWithStacks {
	struct stack stack1;
	struct stack stack2;
};


void initQueue(struct QueueWithStacks *q, int limit) {
	init(&q->stack1, limit);
	init(&q->stack2, limit);
}

void enqueue(struct QueueWithStacks *q, int x) {
	while (!isEmpty(&q->stack2)) {
    	push(&q->stack1, peek(&q->stack2));
    	pop(&q->stack2);
	}
	push(&q->stack1, x);
}


int dequeue(struct QueueWithStacks *q) {
	while (!isEmpty(&q->stack1)) {
    	push(&q->stack2, peek(&q->stack1));
    	pop(&q->stack1);
	}
	int x = peek(&q->stack2);
	pop(&q->stack2);
	return x;
}
