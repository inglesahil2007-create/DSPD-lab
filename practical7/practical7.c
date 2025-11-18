#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
int graph[SIZE][SIZE];
int n;
void BFS(int start){
    int visited[SIZE] ={0};
    int queue[SIZE], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;
    printf("\n BFS Order: ");
    while(front<rear){
        int node = queue[front++];
        printf("%d", node);
        for(int i =1; i<= n; i++){
            if(graph[node][i] && !visited[i]){
                visited[i] =1;
                queue[rear++] = i;
            }
        }
    }printf("\n");

}
void DFS(int start){
    int visited[SIZE] = {0};
    int stack[SIZE], top =-1;
   
    stack[++top] = start;
    printf("\n DFS Order: ");
    while(top != -1){
        int node = stack[top--];
        if(!visited[node]){
            visited[node] =1;
            printf("%d", node);
            for(int i = n; i>=1;i--){
                if(graph[node][i] && !visited[i]){
                    stack[++top] = i;
                }
            }
        }
    }printf("\n");

}
int main(){
    int edges, u, v, start;
    printf("enter number of vertices: ");
    scanf("%d", &n);
    for(int i = 1; i <=n;i++){
        for(int j = 1; j<= n; j++){
            graph[i][j] = 0;
        }
    }
     printf("enter numbetr of edges:");
     scanf("%d", &edges);
     printf(" enter each edge(u v) for undirected graph: \n");
     for(int i= 0; i< edges;i++){
        scanf("%d %d", &u, &v);
        graph[u][v]=1;
        graph[v][u]=1;
     }
     printf("enter astarting vertex: ");
     scanf("%d", &start); 
    BFS(start);
    DFS(start);
    printf("program executed successfully!\n");
    return 0;
}