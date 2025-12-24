#include<stdio.h>
#include<stdlib.h>
#include "arrADT.h"
int main() {
  struct node *header;
  header = (struct node *)malloc(sizeof(struct node));
  header->left = NULL;
  header->right = NULL;
  create(header, 6);
  create(header, 8);
  create(header, 9);
  printf("1.the elements are:\n");
  display(header);
  insertEnd(header, 2);
  printf("\n2.insert End");
  display(header);
  insertAfter(header, 6, 7);
  printf("\n3.insert After some(6) element\n");
  display(header);
 
  struct node*ele;
  ele=search(header,2);
  if(ele!=NULL){
   printf("\n4.the searched element Found:%d",ele->data);
   }
   else{
 	printf("\n4.Not found");
   }
  delete(header, 6);
  printf("\n5.delete the element 6:\n");
  printf("Ather the Deletion:\n");
  display(header);
  
  int d=findDup(header);
  if(d==1)
  {
      printf("\n6.duplicate found\n");
  }
  else
  {
      printf("\n6.No duplicate\n");
  }

  return 0;
}
