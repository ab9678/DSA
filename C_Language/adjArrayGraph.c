# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# define v 5
bool e[v][v];
int d[v];
int q[v];   // is going to store indexes not values
// int visited[v];
// int vis=-1;
int f = -1;
int r = 0;

void initialiseQ(){
    for (int i =0 ;i<v ;i++){
        q[i]=-1;
    }
}
int getIndex(int data){
    int i;
    for(i=0;i<v;i++){
        if(d[i] == data){
            return i;
        }
    }
    return -1;
}

void initialize(){
    for(int i =0; i<v;i++){
        for (int j=0 ; j<v ; j++){
            e[i][j] = false;
        }
    }
}

void connect(int i, int j){


    if(e[i][j] == true){
        printf("Connection already present");
    }else{
        e[i][j]=true;
    }
    

    return;
}

void displayConnections(){
    int i,j;



    for (i=0;i<v;i++){
        for (j=0;j<v;j++){
            if(e[i][j] == true){
                printf("%d->%d\t",d[i],d[j]);
            }
        }
        
    }
}

bool emptyQ(){
    if(f==-1 && r==-1){
        return true;
    }
    return false;
}

void enqueue(int data){

    int i;
    for (i=0;i<r;i++){
        if(q[i]==data){     // if the index comming is already present in the q or was present but is dequeued, then it will not enqueue the same index again, hence we are counting from 0 not front. 
            return;
        }
    }
    if(q[r]==data){
        return;
    }

    if(emptyQ()==true){
        f=0;
        r=0;
        q[r]=data;
    }else{
        r++;
        q[r]=data;
    }
}

void dequeue(){
    if(emptyQ()==true){
        return;
    }
    else if(f==r){

        f=-1;
        r=-1;

    }else{
 
        f++;
    }

    // no need for fullq because we are playing with a fixed size and we know that the max no. of elements possible
}

void findNeighbours(int mainFunctionValue){
    int parent,j;


    if(emptyQ()==true){
        enqueue(mainFunctionValue);
    }


    while(emptyQ() == false){
        
        parent=q[f];
        
        
        for(j=0;j<v;j++){
            if(e[parent][j]==true){
                enqueue(j);     // j are the neighbours to the parent(all are indices not real data)
            }
        }
        

        dequeue();
    }
}


int main(){
    printf("Enter the data for nodes: \n");
    
    int i;
    for (i=0;i<v;i++){
        scanf("%d",&d[i]);
    }

    int src, dest, choice;
    initialize();
    while(1){
        printf("Please enter source and destination\n");
        printf("Source: ");
        scanf("%d",&src);
        src = getIndex(src);
        printf("Destination: ");
        scanf("%d",&dest);
        dest = getIndex(dest);

        if((src>v || dest>v) || (src<0 || dest <0)){
            printf("Invalid Entry, Connection Failed");
        }else{
            connect(src,dest);
        }
        
        printf("Enter 78 to exit, else press anything: ");
        scanf("%d",&choice);
        if(choice == 78){
            break;
        }
    }


    displayConnections();
    printf("\n");

    findNeighbours(2);
    printf("\n");
    for (i=0;i<v;i++){
        printf("%d\t",d[q[i]]);
    }
    printf("\n");
    // input done nodes are present 
}