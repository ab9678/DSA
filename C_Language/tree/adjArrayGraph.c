# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# define v 5
bool e[v][v];
int d[v];

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

    // input done nodes are present 
}