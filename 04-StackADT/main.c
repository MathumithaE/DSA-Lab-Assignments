#include<stdio.h>
#include<stdlib.h>
#include"stackADT.h"
void main()
{
  struct stack*s;
  s=(struct stack*)malloc(sizeof(struct stack));
  printf("\nInitially top element:%d\n",peek(s));
  push(s,2);
  push(s,4);
  push(s,6);
  push(s,8);
  pop(s);
  printf("\ntop element :%d",peek(s));
  printf("\ntop element:%d",peek(s));
  pop(s);
  pop(s);
 
 
}
