# include <stdio.h>
# define v 5
int dfs(int node, int visited[], int edge[v][v]) {
    printf("%d ", node);       // Print the current node
    visited[node] = 1;         // Mark it as visited

    for (int i = 0; i < v; i++) {
        if (edge[node][i] == 1 && visited[i]!=1) {
            dfs(i, visited, edge);  // Recursively visit the neighbor
        }
    }
}
int main(){

int front =-1, rear = -1, q[v];
int visited[v]={0},curr;
int node[v]={0};
int edge[v][v]={0};
int i,j=-1,k; //j is visited array iterator;
int e=0;
int src,dest;
printf("Enter the number of edges: ");
scanf("%d",&e);

for (int i = 0 ; i<e ; i++){
    printf("Enter source and destination: ");
    scanf("%d %d",&src,&dest);
    edge[src][dest] = 1;
    edge[dest][src]=1;

    // undirectional
}
for (i=0;i<v;i++){
    for (j=0;j<v;j++){
        printf("%d\t",edge[i][j]);
    }
    printf("\n");
}
// bfs

rear = 0;
front = 0;
q[rear]=0;

visited[0]=1;

printf("\nBFS: ");
while(front<=rear){

    
    curr = q[front];
    printf("%d\t",curr);


    for(i=0;i<v;i++){
        if(edge[curr][i] == 1){
            
                if(visited[i]!=1){
                    visited[i]=1;
                    rear++;
                    q[rear]=i;
                }
            
        }
        
    }
    front++;

}
    printf("\nDFS: ");
    for(i=0;i<v;i++){
        visited[i]=0;
    }
    dfs(0,visited,edge);
    printf("\n");

}





// int main() {
//     int edge[V][V] = {0};      // Adjacency matrix
//     int visited[V] = {0};      // Visited array
//     int e, src, dest;

//     // Input: Number of edges
//     printf("Enter the number of edges: ");
//     scanf("%d", &e);

//     // Input: Edges
//     for (int i = 0; i < e; i++) {
//         printf("Enter source and destination: ");
//         scanf("%d %d", &src, &dest);
//         edge[src][dest] = 1;
//         edge[dest][src] = 1;  // Undirected graph
//     }

//     printf("DFS Traversal: ");
//     dfs(0, visited, edge);  // Start DFS from node 0
//     printf("\n");

//     return 0;
// }


