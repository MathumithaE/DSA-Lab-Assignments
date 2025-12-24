#include "arrADT.h"
#include<stdio.h>
#include<stdlib.h>
struct arr *a;
struct arr b;


int main() {
    struct arr a;
    int data1[] = {23, 45, 52, 89, 25};
    int n1 = 5;

    printf("Initial Array:\n");
    create(&a, n1, data1);
    print(&a);

    printf("\nDeleting element at position 1:\n");
    del(&a, 1, n1, data1);

    printf("\nInserting value 1 before every element:\n");
    insertAtEvery(&a, 1, a.size, a.arr);
    print(&a);

    printf("\nSearching for the second occurrence of element 5:\n");
    search(&a, 5);

    int data2[] = {10, 20, 15, 2, 23, 90, 67};
    int n2 = 7;

    printf("\nNew Array:\n");
    create(&a, n2, data2);
    print(&a);

    printf("\nPeak elements in the array:\n");
    findPeek(&a, a.size);

    return 0;
}


