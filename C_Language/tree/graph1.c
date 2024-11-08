# include <stdio.h>
# include <stdlib.h>
# define v 5
typedef struct node{
    int dest;
    int src;
    struct node* next;
    
}node;

typedef struct vertex{
    int data;
    struct node* head;
}vertex;


vertex array[v];

node* createEdge (node **head,int src){
    int choice=1;
    node* tail=NULL;
    node* newnode = NULL;
    while(choice!=0){
        newnode = (node*)malloc(sizeof(node));
        newnode->next = NULL;
        newnode->src = src;
        printf("Enter destination(%d): ",src);
        scanf("%d",&newnode->dest);

        if(*head == NULL){
            *head = newnode;
            tail = newnode;
        }else{
            tail->next = newnode;
            tail=newnode;
        }

        printf("continue?(1/0): ");
        scanf("%d",&choice);
    }
}


void displayGraph(node **head,int src){
    /*
        why **head not *head or just simply head?
        Good question,
        Lets be clear, go above and look at the vetext structure, what do ya see?
        vertex has a field head, and its a struct node* type, here what is this *?,
        This star is declaring head as a pointer of type node.
        Now here in displayGraph, or createGraph function as well, we need a head pointer which will point to that head pointer. we could have done this by literally declaring the array as global and lietrally use array[i].head directly
        -- which I will be doing in a while,
        but we need something clean and that is why we are using a head pointer which will be pointing to the array[i].head pointer, and that's my friend is the pointer pointing to another pointer, which in other words, recall 1st semester, is DOUBLE POINTER.

        tl;dr
        🤣
    */

    printf("\nWe are showing connection for %d\n\n",src);

    node* temp = *head;

    if(* head == NULL){
        printf("\nNO CONNECTIONS FOUND\n");
        return;
    }

    while(temp!=NULL){
        printf("%d->%d\t",src,array[temp->dest].data);
        temp=temp->next;
    }
    printf("\n\nComplete\n\n");

}


int main(){


int i;

printf("Enter the nodes: \n");

for (i=0;i<v;i++){
    printf("Node %d: ", i);
    scanf("%d", &array[i].data);
    array[i].head = NULL;
}

for (i=0;i<v;i++){
    createEdge(&array[i].head,array[i].data);
}
// [    5,  7,  9,  10, 3   ]

for (i=0;i<v;i++){
    displayGraph(&array[i].head,array[i].data);
}
}