#include <stdio.h>
#include <stdlib.h>
#include "arrADT.h"

void main()
{
	struct node*header;
    struct node *l;
    l=(struct node *)malloc(sizeof(struct node));
	header=(struct node*)malloc(sizeof(struct node));
	header->next=NULL;
	int m;
	
	
	
	insert(header,2);
	insert(header,4);
	insert(header,6);
	insert(header,8);
    
    
    
    
    
	insertAtEnd(header,1);
	printf("Linked List after insertion:\n");
    display(header);

    printf("\nSearching for element 1:\n");
    if (m == 1)
        printf("Value is found\n");
    else
        printf("Not found\n");

    printf("\nMiddle element of the linked list:\n");
    findMiddleElt(header);

    printf("\nLength of the linked list:");
    int count=lengh(header);
    printf("%d\n",count);

    printf("\nReversed linked list:\n");
    l = reverse(header);
    display(l);

    printf("\nDeleting element 2 from the linked list:\n");
    deletenode(header, 2);
    printf("Linked list after deletion:\n");
    display(header);

}

