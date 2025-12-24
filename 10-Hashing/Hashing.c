#include <stdio.h> 
#include <stdlib.h> 
 
// Node structure for linked list 
struct node 
{ 
    int data; 
    struct node *next; 
}; 
 
// Hash Table structure 
struct hash_table 
{ 
    int size; 
struct node *list[100]; 
}; 
// Function to initialize the size of the hash table 
void init(struct hash_table *H, int size) 
{ 
H->size = size; 
for (int i = 0; i < H->size; i++) 
{ 
H->list[i] = (struct node *)malloc(sizeof(struct node)); 
H->list[i]->next = NULL; 
} 
} 
// Function to insert an element into the hash table 
void insertElementL(struct hash_table *H, int x) 
{ 
int h; 
struct node *temp; 
h = x % H->size; 
temp = (struct node *)malloc(sizeof(struct node)); 
temp->data = x; 
temp->next = H->list[h]->next; 
H->list[h]->next = temp; 
printf("\n Node inserted %d ", temp->data); 
} 
// Function to search for an element in the hash table 
int searchElement(struct hash_table *H, int key) 
{ 
struct node *temp; 
int h; 
h = key % H->size; 
temp = H->list[h]->next; 
while (temp != NULL) 
{ 
if (temp->data == key) 
{ 
printf("\n Data found: %d", temp->data); 
return 1; 
} 
temp = temp->next; 
} 
return -1; 
} 
// Function to display the elements in the hash table 
void displayHT(struct hash_table *H) 
{ 
for (int i = 0; i < H->size; i++) 
{ 
struct node *temp = H->list[i]->next; 
printf("\n%d -> ", i); 
while (temp != NULL) 
{ 
printf("%d -> ", temp->data); 
temp = temp->next; 
} 
printf("NULL"); 
} 
printf("\n"); 
} 
// Menu-driven application to demonstrate HashTableADT 
int main() 
{ 
struct hash_table *hashTable = (struct hash_table *)malloc(sizeof(struct hash_table)); 
init(hashTable, 10); 
int choice, key,k; 
do 
{ 
printf("\n---- Menu ----"); 
printf("\n1. Insert Element"); 
printf("\n2. Search Element"); 
printf("\n3. Display Hash Table"); 
printf("\n4. Exit"); 
printf("\nEnter your choice: "); 
scanf("%d", &choice); 
switch (choice) 
{ 
case 1: 
printf("Enter the number of element to insert: "); 
scanf("%d", &key); 
for(int i=0;i<key;i++) 
{ 
scanf("%d",&k); 
insertElementL(hashTable, k);} 
break; 
case 2: 
printf("Enter the element to search: "); 
scanf("%d", &key); 
if (searchElement(hashTable, key) == -1) 
{ 
printf("\n Data not found"); 
} 
break; 
case 3: 
displayHT(hashTable); 
break; 
case 4: 
printf("Exiting program.\n"); 
break; 
default: 
printf("Invalid choice. Please enter a valid option.\n"); 
break; 
} 
} while (choice != 4); 
free(hashTable); 
return 0; 
} 