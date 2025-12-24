#include <stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
    
};
void insert(struct node*header,int Data){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=Data;
   temp->next= header->next;
   header->next=temp;
    
}
void  display(struct node*header)
{
	struct node*ptr;
	ptr=header->next;
	while(ptr!=NULL)
	{
    	printf("\n%d",ptr->data);
    	ptr=ptr->next;
   	
	}
 
}

void insertAtEnd(struct node*header,int data)
{
    struct node*temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (header->next == NULL) {
        header->next = temp;
        return;
    }

    struct node*ptr = header->next;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}


int search(struct node*header,int key){
  struct node*ptr;
  ptr=header->next;
  while(ptr!=NULL){
  if(ptr->data==key){
	return 1;
  }
	ptr=ptr->next;
  }
 
return -1;

 
}
int lengh(struct node*header){
  struct node*ptr;
  int count=0;
  ptr=header->next;
  while(ptr!=NULL)
	{
  	count++;
  	ptr=ptr->next;
	}
  return count;
 // printf("\nlengh of list is=%d",count);
 
}
void findMiddleElt(struct node*header){
  struct node*ptr;
 int count=0;
  int m;
  ptr=header->next;
  m=lengh(header);
  int n=m/2;
 
  while(ptr!=NULL)
	{
 	
  	if(count==n)
  	{
    	printf("\nmiddle element=%d",ptr->data);
    	break;
  	}
  	else {
    	count++;
    	ptr=ptr->next;
	}
	
	}
}
struct node* reverse(struct node *h)
{
    int a[100];
    int i = 0;

    if (h == NULL)
        return NULL;

    struct node* ptr = h->next;
    while (ptr != NULL) {
        a[i++] = ptr->data;
        ptr = ptr->next;
    }

    struct node *h1;
    h1 = (struct node*)malloc(sizeof(struct node));
    h1->next = NULL;   // ✅ CRITICAL FIX

    for (int j = i - 1; j >= 0; j--) {
        insertAtEnd(h1, a[j]);
    }

    return h1;
}

void deletenode(struct node *header,int key)
{
  struct node *prev;
  struct node*ptr;
  prev=header;
  ptr=header->next;
  while(ptr!=NULL)
	{
  	if(ptr->data==key)
  	{
    	prev->next=ptr->next;
    	free(ptr);
    	break;
  	}
  	else
  	{
    	prev=ptr;
    	ptr=ptr->next;
  	}
	}
}
