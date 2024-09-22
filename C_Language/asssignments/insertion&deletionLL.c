/* insert element at beginning of a singly linked list 
insert element at the beginning of a doubly linked list 
delete elements from the end of a doubly linked list
*/

# include <stdio.h>
# include <stdlib.h>

// create the ground of singly and doubly linked lists nodes

typedef struct singly{
    int data;
    struct singly* next;
}singly;

typedef struct doubly{
    int data;
    struct doubly* next;
    struct doubly* previous;
}doubly;

singly* headS = NULL;
singly* tailS = NULL;

doubly* headD = NULL;
doubly* tailD = NULL;

void insertSinglyBeginning();
void insertDoublyBeginning();
void deleteEndDoubly();
void displayS();
void displayD();
int main(){

    int input;

    while (1){

        printf("\n1.Insert at beginning of singly linked list\n2.Insert at beginning of doubly linked list\n3.Delete from the end of doubly linked list\n4.Display Elements of singly linked list\n5.Display elements of doubly linked list\nSelect: ");
        scanf("%d",&input);

        if (input == 1){
            insertSinglyBeginning();
        }else if (input == 2){
            insertDoublyBeginning();
        }else if (input == 3){
            deleteEndDoubly();
        }else if (input==4){
            displayS();
        }else if (input == 5){
            displayD();
        }
        else{
            printf("\nTry Again\n");
        }
    }


}


void insertSinglyBeginning(){
    singly* newnode1 = NULL;

    newnode1 = (singly*)malloc(sizeof(singly));
    printf("Data: ");
    scanf ("%d",&newnode1->data);
    newnode1->next = NULL;

    if (headS == NULL){
        headS = newnode1;
        tailS = newnode1;
    }else{
        newnode1->next = headS;
        headS = newnode1;
    }
}

void insertDoublyBeginning(){
    doubly* newnode = NULL;
    newnode = (doubly*)malloc(sizeof(doubly));
    printf("Data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->previous=NULL;

    if (headD == NULL){
        headD = newnode;
        tailD = newnode;
    }else{
        newnode->next = headD;
        headD->previous = newnode;
        newnode->previous = NULL;
        headD = newnode;
    }
}

void deleteEndDoubly(){
    doubly* p=tailD;
    if(headD != NULL){
        if(headD->next == NULL){
            p = headD;
            headD = NULL;
            free(p);
        }else{
            
            tailD = tailD->previous;
            tailD->next = NULL;
            // p->previous = NULL;
            printf("Deleting %d",p->data);
            free(p);
        }
    }else{
        printf("\nEmpty linked list, plase insert elements first\n");
    }
}

void displayS(){
    singly* temp = headS;

    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
}

void displayD(){
    doubly* temp = headD;

    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
}