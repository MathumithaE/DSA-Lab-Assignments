#include <stdio.h>
#include <stdlib.h>

// Node structure for open addressing
struct node {
    int data;
};

// Hash Table structure
struct hash_table {
    int size;
    struct node *table[100];
};

// Initialize hash table
void init(struct hash_table *H, int size) {
    H->size = size;
    for (int i = 0; i < H->size; i++) {
        H->table[i] = NULL;
    }
}

// Quadratic Probing insertion
void insertElementQuad(struct hash_table *H, int x) {
    int h = x % H->size;
    int i = 0;

    while (H->table[(h + i * i) % H->size] != NULL) {
        i++;
    }

    H->table[(h + i * i) % H->size] =
        (struct node *)malloc(sizeof(struct node));
    H->table[(h + i * i) % H->size]->data = x;
}

// Double Hashing insertion
void insertElementDouble(struct hash_table *H, int x) {
    int h = x % H->size;
    int i = 0;
    int secondHash = 7 - (x % 7);

    while (H->table[(h + i * secondHash) % H->size] != NULL) {
        i++;
    }

    H->table[(h + i * secondHash) % H->size] =
        (struct node *)malloc(sizeof(struct node));
    H->table[(h + i * secondHash) % H->size]->data = x;
}

// Display hash table
void displayHT(struct hash_table *H) {
    for (int i = 0; i < H->size; i++) {
        printf("%d -> ", i);
        if (H->table[i] != NULL) {
            printf("%d", H->table[i]->data);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    struct hash_table *hashTableQuad =
        (struct hash_table *)malloc(sizeof(struct hash_table));
    struct hash_table *hashTableDouble =
        (struct hash_table *)malloc(sizeof(struct hash_table));

    init(hashTableQuad, 10);
    init(hashTableDouble, 10);

    // Quadratic Probing elements
    int quadElements[] = {67, 53, 23, 54, 45, 66, 87, 48, 69};
    int n1 = sizeof(quadElements) / sizeof(quadElements[0]);

    for (int i = 0; i < n1; i++) {
        insertElementQuad(hashTableQuad, quadElements[i]);
    }

    printf("(i) Contents of Hash Table (Quadratic Probing)\n");
    displayHT(hashTableQuad);

    // Double Hashing elements
    int doubleElements[] = {67, 53, 23, 54, 45, 66, 87, 48, 69};
    int n2 = sizeof(doubleElements) / sizeof(doubleElements[0]);

    for (int i = 0; i < n2; i++) {
        insertElementDouble(hashTableDouble, doubleElements[i]);
    }

    printf("(ii) Contents of Hash Table (Double Hashing)\n");
    displayHT(hashTableDouble);

    return 0;
}
