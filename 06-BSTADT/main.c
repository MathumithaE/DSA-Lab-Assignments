#include<stdio.h>
#include<stdlib.h>
#include"BSTADT.h"

int main() {
    struct tree* t;
    t = NULL;
    t = insert(t, 2);
    insert(t, 3);
    insert(t, 4);
    insert(t, 1);
    insert(t, 36);
    insert(t, 49);

    int Search = 4;
    struct tree* temp = search(t, Search);

    if (temp == NULL) {
        printf("Element %d is not found\n", Search);
    } else {
        printf("Element %d is found\n", Search);
    }

    printf("Inorder: ");
    inorder(t);
    printf("\nPreorder: ");
    preorder(t);
    printf("\nPostorder: ");
    postorder(t);
    printf("\nLevelorder: ");
    levelorder(t);
    printf("\n");

    printf("\nFindMin: ");
    int a = findmin(t);
    printf("%d", a);

    printf("\nAfter deleting 13: ");
    deletenode(t, 13);
    
    printf("\nInorder of traversal: ");
    inorder(t);
    printf("\nPreorder of traversal: ");
    preorder(t);
    printf("\nPostorder of traversal: ");
    postorder(t);

    return 0;
}
