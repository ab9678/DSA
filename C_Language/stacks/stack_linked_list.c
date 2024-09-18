# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int data;
    struct node* link;
}node;

node* top = NULL;

void push(){

    node* newnode = NULL;
    newnode = (node*)malloc(sizeof(node));
    printf("\nData: ");
    scanf("%d",&newnode->data);
    newnode->link = NULL;

    if (top == NULL){
        top = newnode;
    }
    else{
        newnode->link = top;
        top = newnode;
    }

    // end of push


}

void pop(){
    node* temp=NULL;
    if (top == NULL){
        printf("\nEmpty stack");
    }
    else{

        printf("%d",top->data);
        top = top->link;
        free(temp);

    }

    // end of pop

}


void peek(){
    if (top == NULL){
        printf("\nEmpty stack");
    }
    else{

        printf("%d",top->data);
        
    }
}
int display(){

node* iterator = NULL;

if ( top == NULL){
    printf("\nEmpty stack\n");

}else{
    iterator = top;
    while (iterator != NULL){
        printf("%d->",iterator->data);
        
        iterator = iterator->link;
    }
}


}



int main(){

    int choice;
    
    while(1){
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\nchoose: ");
        scanf("%d",&choice);
        if (choice == 1){
            push();
        }
        else if (choice == 2){
            pop();
        }
        else if (choice == 3){
            peek();
        }
        else if (choice == 4){
            display();
        }
        else if (choice = 5){
            exit(EXIT_SUCCESS);
        }
        else{
            printf("\nInvalid\n");
        }

        
    }


}