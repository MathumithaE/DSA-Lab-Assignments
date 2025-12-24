#include <stdio.h>
#include <stdlib.h>
struct stack {
int top;
int data[100];
int size;
};
void init(struct stack *s, int limit) {
s->size = limit;
s->top = -1;
}
int isFull(struct stack *s) {
return s->top == s->size - 1;
}
int isEmpty(struct stack *s) {
return s->top == -1;
}
void push(struct stack *s, int d) {
if (isFull(s)) {
printf("Stack is full. %d.\n", d);
} else {
s->data[++s->top] = d;
printf("\nPushed: %d", d);
}
}
void pop(struct stack *s) {
if (isEmpty(s)) {
printf("Stack is empty.\n");
} else {
printf("Popped: %d\n", s->data[s->top]);
s->top--;
}
}
int peek(struct stack *s) {
if (isEmpty(s)) {
printf("Stack is empty.\n");
return -1;
} else {

return s->data[s->top];
}
}
