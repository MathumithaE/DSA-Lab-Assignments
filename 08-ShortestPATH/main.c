#include "dijkstras.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  struct graph *g;
  g = (struct graph *)malloc(sizeof(struct graph));
  int vertex, edges;
  int d;
  printf("enter the number of vertex:");
  scanf("%d", &vertex);
  printf("enter the number of edges:");
  scanf("%d", &edges);
  struct edgePair edge[100];
  int x = 1;

  while (x) {
    printf("Enter:\n1.create\n2.display\n3.printTable\n4.shotest "
           "path\n5.path\n6.exit");
    int choice, s;
    int from, to, weight;
    printf("choice the option\n");
    scanf("%d", &choice);

    switch (choice)

    {

    case 1:

      printf("enter the edge pairs\n");
      for (int i = 0; i < edges; i++) {
        scanf("%d", &edge[i].from);
        scanf("%d", &edge[i].to);

        // scanf("%d",&edge[i].weight);
      }
      create(g, vertex, edges, edge);
      printf("\n");
      break;

    case 2:

      printf("ADJENCY MATRICES;\n");
      display(g);
      printf("\n");
      break;

    case 3:

      init(g);
      printf("TABLE:\n");
      printTable(g,vertex);
      printf("\n");
      break;
    case 4:

      printf("enter the starting vertex:\n");
      scanf("%d", &s);
      dijkstras(g, s,vertex);
      printf("\n");
      break;
    case 5:

      printf("Enter the destination: ");
      scanf("%d", &d);
      printf("PATH: \n");
      path(g, d);
      printf("\n");
      break;
    case 6:
      x = 0;
      printf("exit\n");
      break;
    }
  }
}
