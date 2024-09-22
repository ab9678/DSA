// // delete all nodes have even number information and move them to L1 and delete all nodes have odd number of Information and move them to L2 to

// # include <stdio.h>
// # include <stdlib.h>
// typedef struct evenOddLL
// {
//     int data;
//     struct evenOddLL* next;
//     struct evenOddLL* previous;
// }node;
// node* head = NULL;
// node* tail = NULL;
// node* headL1 = NULL;
// node* headL2 = NULL;
    
// void createList(node** mainHead,int data){
//     node* newnode = NULL;
//     char choice;
    
//         newnode = (node*)malloc(sizeof(node));
//         newnode->next = NULL;
//         newnode->previous = NULL;
//         newnode->data = data;
//         if (*mainHead == NULL){
//             *mainHead = newnode;
//             tail = newnode;
//         }else{
//             tail->next = newnode;
//             newnode->previous = tail;
//             tail = newnode;
//         }

        
   
// }

// void process(){
//     node* temp = head;

//     node* p = NULL;
//     if (head != NULL){
//         while(temp!=NULL){
//             if (temp->data%2==0){
//                 createList(&headL1,temp->data);
//                 if (head->next == NULL){
//                     p=head;
//                     head = NULL;
//                     free(p);
//                 }else if(temp == head){
//                     p=head;

//                     head=temp->next;
//                     head->previous=NULL;
//                     free(p);
//                 }
//                 else if (temp==tail){
//                     p = tail;
//                     tail = tail->previous;
//                     tail->next = NULL;
//                     free(p);
//                 }
//                 else{
//                     p =temp;
//                     temp->previous->next = temp->next;
//                     temp->next->previous = temp->previous;
//                     free(p);

//                 }

//             }else{
//                 createList(&headL2,temp->data);
//                 if (head->next == NULL){
//                     p=head;
//                     head = NULL;
//                     free(p);
//                 }else if(temp == head){
//                     p=head;

//                     head=temp->next;
//                     head->previous=NULL;
//                     free(p);
//                 }
//                 else if (temp==tail){
//                     p = tail;
//                     tail = tail->previous;
//                     tail->next = NULL;
//                     free(p);
//                 }
//                 else{
//                     p =temp;
//                     temp->previous->next = temp->next;
//                     temp->next->previous = temp->previous;
//                     free(p);

//                 }
//             }

//             temp=temp->next;
//         }
//     }
// }

// int main(){
//     int input;
//     char choice='n';
//     int data;
//     while(1){
//         printf("\n1.Create list 1\n2.Seperate even and odd numbers\nSelect: ");
//         scanf("%d",&input);
//         if (input == 1){
//         while(choice != 'y'){
//             printf("Data: ");
//             scanf("%d",&data);
//             createList(&head,data);
//             printf("Wanna exit?(y/n)");
//             scanf(" %c",&choice);

//         }
        
//         }else if (input == 2){
//             process();
//         }else{
//             printf("You made a mistake bruh, try again");
//         }
//     }
    
// }

#include <stdio.h>
#include <stdlib.h>

typedef struct evenOddLL {
    int data;
    struct evenOddLL* next;
    struct evenOddLL* previous;
} node;

node* head = NULL;
node* tail = NULL;
node* headL1 = NULL;
node* headL2 = NULL;

void createList(node** mainHead, int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->next = NULL;
    newnode->previous = NULL;
    newnode->data = data;

    if (*mainHead == NULL) {
        *mainHead = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        newnode->previous = tail;
        tail = newnode;
    }
}

void process() {
    node* temp = head;

    while (temp != NULL) {
        node* nextNode = temp->next; // Save the next node
        if (temp->data % 2 == 0) {
            createList(&headL1, temp->data);
        } else {
            createList(&headL2, temp->data);
        }

        // Deleting the current node
        if (temp->previous) {
            temp->previous->next = temp->next;
        } else {
            head = temp->next; // Update head if it's the first node
        }
        
        if (temp->next) {
            temp->next->previous = temp->previous;
        } else {
            tail = temp->previous; // Update tail if it's the last node
        }
        
        free(temp); // Free the current node
        temp = nextNode; // Move to the next node
    }
}

int main() {
    int input;
    char choice = 'n';
    int data;

    while (1) {
        printf("\n1. Create list\n2. Separate even and odd numbers\n3. Exit\nSelect: ");
        scanf("%d", &input);

        if (input == 1) {
            choice = 'n'; // Reset choice for new list
            while (choice != 'y') {
                printf("Data: ");
                scanf("%d", &data);
                createList(&head, data);
                printf("Wanna exit? (y/n): ");
                scanf(" %c", &choice); // Space before %c to consume newline
            }
        } else if (input == 2) {
            process();
        } else if (input == 3) {
            break; // Exit the loop
        } else {
            printf("You made a mistake, try again.\n");
        }
    }

    return 0;
}
