#include<stdlib.h>
#include<stdio.h>

//Insert an item in the front of the list

struct node {
  int data;
  struct node *left;
  struct node *right;
};

void create(struct node *header, int key) {
  struct node *temp;
  struct node *ptr;
  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = key;
  if (header->right == NULL) {
	temp->right = header->right;
	temp->left = header;
	header->right = temp;
  } else {
	ptr = header->right;
	temp->left = header;
	header->right = temp;
	temp->right = ptr;
	ptr->left = temp;
  }
}
//Insert an item at the end of the list
void insertEnd(struct node *header, int key) {
  struct node *ptr;
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  ptr = header->right;
  temp->data = key;

  if (header->right == NULL) {
	temp->right = NULL;
	header->right = temp;
	temp->left = header;
  } else {
	while (ptr->right != NULL) {
  	ptr = ptr->right;
	}
	temp->left = ptr;
	temp->right = NULL;
	ptr->right = temp;
  }
}
//Insert an item ‘d’ after the first occurrence ‘c’ of the list
void insertAfter(struct node *header, int key, int ele) {
  struct node *ptr, *next, *temp;
  ptr = header->right;
  while (ptr != NULL) {
	if (ptr->data == key) {
  	temp = (struct node *)malloc(sizeof(struct node));
  	temp->data = ele;
  	next = ptr->right;
  	ptr->right = temp;
  	temp->left = ptr;
  	temp->right = next;
  	if (next != NULL) {
    	next->left = temp;
  	}
  	return;
	}
	ptr = ptr->right;
  }
  printf("\ncannot be inserted after element %d", key);
}
//Display the items from the list
void display(struct node *header) {
  struct node *ptr;
  struct node *end;
  ptr = header->right;
  printf("\nforward ");
  while (ptr != NULL) {
	printf("\t%d", ptr->data);
	end = ptr;
	ptr = ptr->right;
  }
  printf("\n");
  printf("\nbackward");
  while (end != header) {
	printf("\t%d", end->data);
	end = end->left;
  }
}


//Delete the item present in the list
void delete(struct node *header, int key) {
  struct node *prev, *next, *ptr;
  ptr = header->right;
  while (ptr != NULL) {
	if (ptr->data == key) {
  	prev = ptr->left;
  	next = ptr->right;
  	prev->right = next;
  	if (next != NULL) {
    	next->left = prev;
  	}
  	free(ptr);
  	return;
	}
	ptr = ptr->right;
  }
  printf("\ncannot be deleted element %d", key);
}


//Search an element in the list and return the number of occurrences
struct node* search(struct node* header, int key) {
	struct node* ptr;
	ptr = header->right;
	while (ptr != NULL) {
    	if (ptr->data == key) {
        	return ptr; // Return a pointer to the found node not data
    	}
    	ptr = ptr->right;
	}
	return NULL;
}


int findDup(struct node *header)
{
	struct node *ptr, *next;
	ptr = header->right;

	while (ptr != NULL)
	{
    	int x = ptr->data;
    	next = ptr->right; // Move this line inside the outer loop

    	while (next != NULL)
    	{
        	if (next->data == x)
        	{
            	return 1; // Found a duplicate
        	}

        	next = next->right;
    	}

    	ptr = ptr->right; // Move this line inside the outer loop
	}

	return 0; // No duplicates found
}
