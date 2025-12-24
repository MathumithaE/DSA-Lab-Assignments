#ifndef ARR_ADT_H
#define ARR_ADT_H

#include <stdio.h>
#include <stdlib.h>

struct arr {
	int arr[100];
	int size;
};

/* Create array */
void create(struct arr *p, int s, int a[]) {
	p->size = s;
	for (int i = 0; i < p->size; i++) {
		p->arr[i] = a[i];
	}
}

/* Print array */
void print(struct arr *q) {
	for (int i = 0; i < q->size; i++) {
		printf("%d ", q->arr[i]);
	}
	printf("\n");
}

/* Delete element at given position */
void del(struct arr *b, int pos, int s, int a[]) {
	b->size = s;

	if (pos < 1 || pos > b->size) {
		printf("Invalid position\n");
		return;
	}

	for (int i = pos - 1; i < b->size - 1; i++) {
		b->arr[i] = a[i + 1];
	}

	b->size--;
	print(b);
}

/* Insert a given element before every element */
void insertAtEvery(struct arr *l, int data, int s, int a[]) {
	l->size = s;
	int new_size = 2 * l->size;
	int temp[200];

	for (int i = 0; i < l->size; i++) {
		temp[2 * i] = data;
		temp[2 * i + 1] = a[i];
	}

	l->size = new_size;
	for (int i = 0; i < new_size; i++) {
		l->arr[i] = temp[i];
	}
}

/* Search for second occurrence of an element */
void search(struct arr *p, int search_element) {
	int count = 0;

	for (int i = 0; i < p->size; i++) {
		if (p->arr[i] == search_element) {
			count++;
			if (count == 2) {
				printf("%d\n", i);
				return;
			}
		}
	}

	printf("-1\n");
}

/* Find peak elements */
void findPeek(struct arr *p, int s) {
	p->size = s;

	if (p->size == 0) {
		return;
	}

	if (p->size == 1) {
		printf("%d\n", p->arr[0]);
		return;
	}

	for (int i = 0; i < p->size; i++) {
		if (i == 0 && p->arr[i] > p->arr[i + 1]) {
			printf("%d ", p->arr[i]);
		}
		else if (i == p->size - 1 && p->arr[i] > p->arr[i - 1]) {
			printf("%d ", p->arr[i]);
		}
		else if (i > 0 && i < p->size - 1 &&
		         p->arr[i] >= p->arr[i - 1] &&
		         p->arr[i] >= p->arr[i + 1]) {
			printf("%d ", p->arr[i]);
		}
	}
	printf("\n");
}

#endif
