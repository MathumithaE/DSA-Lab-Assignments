#include<stdio.h>
#include<stdlib.h>

struct table
{
    int known;
    int dist;
    int path;
    int v;
};
struct edgePair
{
    int from, to;
    int weight;
};
struct graph
{
    int adjmat[100][100];
    struct table t[100];
    struct edgePair ed[100];
    int size;
    int vertex;
};
void create(struct graph *g, int v, int e, struct edgePair edge[])
{
    g->size = e;
    g->vertex = v;
    int from, to, w;
    for (int i = 0; i < e; i++)
    {
        from = edge[i].from;
        to = edge[i].to;
        printf("enter the weight for(%d,%d);", from, to);
        scanf("%d", &w);
        g->adjmat[from][to] = w;
    }
}
void display(struct graph *g)
{
    for (int i = 0; i < g->vertex; i++)
    {
        for (int j = 0; j < g->vertex; j++)
        {
            printf("%d\t", g->adjmat[i][j]);
        }
        printf("\n");
    }
}

void init(struct graph *g)
{
    for (int i = 0; i < g->size; i++)
    {
        g->t[i].v = i;
        g->t[i].known = 0;
        g->t[i].dist = 9999;
        g->t[i].path = -1;
    }
}

void printTable(struct graph *g,int v)
{
    printf("Vertex\tknown\tdist\tpath\n");
    for (int i = 0; i < v; i++)
    {

        printf("v%d\t\t\t%d\t%d\t%d", g->t[i].v, g->t[i].known, g->t[i].dist, g->t[i].path);
        printf("\n");
    }
}

int Check(struct graph *g)
{
    for (int i = 0; i < g->vertex; i++)
    {
        if (g->t[i].known == 0)
        {
            return 1;
        }
    }
    return 0;
}

int small(struct graph *g)
{
    int j = 0;
    while (g->t[j].known == 1 && j < g->vertex)
    {
        j++;
    }
    int min;
    min = g->t[j].dist;
    int ver;
    ver = j;
    for (int i = 0; i < g->vertex; i++)
    {
        if (g->t[i].dist < min && g->t[i].known == 0)
        {
            min = g->t[i].dist;
            ver = i;
        }
    }
    return ver;
}

void dijkstras(struct graph *g, int s,int v)
{
    g->t[s].dist = 0;
    while (Check(g))
    {
        int ver;
        ver = small(g);
        g->t[ver].known = 1;
        printTable(g,v);
        printf("\n");
        for (int j = 0; j < g->vertex; j++)
        {
            if ((g->adjmat[ver][j] != 0) && (g->t[j].known != 1))
            {
                if (g->t[j].dist > (g->t[ver].dist + g->adjmat[ver][j]))
                {
                    g->t[j].dist = g->t[ver].dist + g->adjmat[ver][j];
                    g->t[j].path = ver;
                }
            }
        }
    }
}


void path(struct graph *g, int v)
{
    if (g->t[v].path != -1)
    {
        path(g, g->t[v].path);
        printf("->");
    }
    printf("%d ", v);
}

