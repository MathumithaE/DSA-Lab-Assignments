#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree* left;
    struct tree* right;
};

struct queue {
    struct tree* data;
    struct queue* next;
};

struct tree* insert(struct tree* t, int x) {
    if (t == NULL) {
        t = (struct tree*)malloc(sizeof(struct tree));
        t->data = x;
        t->left = NULL;
        t->right = NULL;
    } else if (x < t->data) {
        t->left = insert(t->left, x);
    } else if (x > t->data) {
        t->right = insert(t->right, x);
    }
    return t;
}

void inorder(struct tree* t) {
    if (t != NULL) {
        inorder(t->left);
        printf("%d ", t->data);
        inorder(t->right);
    }
}

void preorder(struct tree* t) {
    if (t != NULL) {
        printf("%d ", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}

void postorder(struct tree* t) {
    if (t != NULL) {
        postorder(t->left);
        postorder(t->right);
        printf("%d ", t->data);
    }
}

void enq(struct tree* data, struct queue** q) {
    struct queue* newNode = (struct queue*)malloc(sizeof(struct queue));
    newNode->data = data;
    newNode->next = NULL;

    if (*q == NULL) {
        *q = newNode;
    } else {
        struct queue* temp = *q;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deq(struct queue** q) {
    if (*q != NULL) {
        struct queue* temp = *q;
        *q = (*q)->next;
        free(temp);
    }
}

void levelorder(struct tree* t) {
    struct queue* q = NULL;

    if (t == NULL) {
        return;
    }

    enq(t, &q);

    while (q != NULL) {
        struct tree* current = q->data;
        printf("%d ", current->data);

        if (current->left != NULL) {
            enq(current->left, &q);
        }

        if (current->right != NULL) {
            enq(current->right, &q);
        }

        deq(&q);
    }
}


struct tree* search(struct tree* t, int x) {
    if (t == NULL) {
        return NULL;
    } else if (x == t->data) {
        return t;
    } else if (x < t->data) {
        return search(t->left, x);
    } else {
        return search(t->right, x);
    }
}

int findmin(struct tree* t) {
    if (t->left != NULL) {
        return findmin(t->left);
    }
    return t->data;
}

struct tree* deletenode(struct tree* t, int x) {
    if (t == NULL) {
        return t;
    }

    if (x < t->data) {
        t->left = deletenode(t->left, x);
    } else if (x > t->data) {
        t->right = deletenode(t->right, x);
    } else if (t->left && t->right) {
        int temp = findmin(t->right);
        t->data = temp;
        t->right = deletenode(t->right, temp);
    } else {
        struct tree* temp = t;
        if (t->right == NULL) {
            t = t->left;
        } else if (t->left == NULL) {
            t = t->right;
        }
        free(temp);
    }
    return t;
}
