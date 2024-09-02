# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* front = NULL;
node* rear = NULL;

void enqueue(){
    node* newnode = NULL;

    newnode = (node*)malloc(sizeof(node));
    printf("Data: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    if (rear == NULL){
        front=rear=newnode;
    }else{
        rear->next = newnode;
        rear=newnode;
    }



}


void dequeue(){
    node* temp = NULL;

    temp = front;
    if (front == NULL){
        printf("\nEmpty queue");
    }else{
        printf("\n%d\n",front->data);
        front = front->next;
        free(temp);
    }
}


void display(){
    node* temp = NULL;
    temp = front;
    if (front==NULL){
        printf("\nEmpty queue\n");
    }else{
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
    }
}
int main(){
        
    int choice;

    while (1){
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\nChoose: ");
        scanf("%d",&choice);
        if (choice == 1){
            enqueue();
        }else if (choice == 2){
            dequeue();
        }else if (choice == 3){
            display();
        }else{
            printf("Invalid Input");
              
        }
    }
}

 



























