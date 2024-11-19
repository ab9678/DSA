# include <stdio.h>
# define v 5

int main(){

int front =-1, rear = -1, q[v];
int visited[v],curr;
int node[v];
int edge[v][v];
int i,j=-1; //j is visited array iterator;
int edge=0;
int src,dest;
printf("Enter the number of edges: ");
scanf("%d",&edge);

for (int i = 0 ; i<edge ; i++){
    printf("Enter source and destination: ");
    scanf("%d %d",&src,&dest);
    edge[src][dest] = 1;
    edge[dest][src]=1;

    // undirectional
}

// bfs
while(front<=rear){
for(i=0;i<v;i++){
    if(front = -1){
        curr = 0;

    }else{
        curr = front;
    }
}
}

}