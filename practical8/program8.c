#include <stdio.h>
#define MAX 100

struct Edge {
    int u, v, wt;
};

struct Edge edges[MAX], mst[MAX];
int parent[MAX];

int find(int x) {
    return parent[x] == x ? x : (parent[x] = find(parent[x]));
}

void unionSet(int x, int y) {
    parent[find(y)] = find(x);
}

void sortEdges(int e) {
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].wt > edges[j + 1].wt) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].wt);
    }

    for (int i = 0; i <= n; i++) parent[i] = i;

    sortEdges(e);

    int mst_weight = 0, count = 0;
    printf("\nEdges in Minimum Spanning Tree:\n");

    for (int i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u, v = edges[i].v, wt = edges[i].wt;

        if (find(u) != find(v)) {
            mst[count++] = edges[i];
            mst_weight += wt;
            unionSet(u, v);
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%d -- %d (Weight = %d)\n", mst[i].u, mst[i].v, mst[i].wt);
    }

    printf("\nTotal Weight of MST = %d\n", mst_weight);

    return 0;
}