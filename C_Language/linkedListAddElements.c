// create a linked list in c 

#include <stdio.h>
# include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next; // linked list is a self referential data structure
}node;

node* AddElements_at_the_begining(node* head){
    node* temp = NULL;
    node* p = NULL;
    int choice=0;
    while (choice != 1){
        temp = (node*)malloc(sizeof(node));
        printf("Enter data: ");
        scanf("%d",&(temp->data));

        if(head == NULL){
            head = temp;
        }else{
            temp->next = head;

            head = temp;
        }

        printf("Do you want to continue?(1/0) ");
        scanf("%d",&choice);
    }

    return head;
}

node* AddElements_at_the_end(node* head){
    node* temp = NULL;
    node* p = NULL;
    int choice=0;
    while (choice != 1){
        temp = (node*)malloc(sizeof(node));
        printf("Enter data: ");
        scanf("%d",&(temp->data));
        temp->next = NULL;

        if(head == NULL){
            head = temp;
        }
        else{
            p = head;
            while (p->next != NULL){
                p = p->next;

            }
            p->next = temp;
            

        }
    

        printf("Do you want to continue?(1/0) ");
        scanf("%d",&choice);
    }
    return head;

}


void display(node* head){
    node* p;
    p = head;
    while(p != NULL){   // why not p->next != NULL , this is because when p is in the last element, the next of P is NULL so the loop breaks, but we need to print this element right so that is why, we can use do-while to acheive the same though ;)
        printf("%d->",*p);
        p = p->next;
    }
}


node* createLinkedList(){
    node* head = NULL;
    node* temp = NULL;
    node* p = NULL;

    int choice=0;
    while (choice != 1){

        // creating isolated temprorary node 
        temp = (node*)malloc(sizeof(node));
        printf("\nEnter Data for the list: ");
        scanf("%d",&(temp->data));
        temp->next = NULL;

        if ( head == NULL){
            head = temp;    // its the first time the list has run so we assign head to link to this new temp node head is pointer temp is also pointer so pointer head is storing address of temp
        }                   // now head is same as temp which is storing address of struct node [data|address], but temp is going to be changed in next iterations, but head has to stay heare so that we can have the list one by one, otherwise we are going to lose the nodesof the list
        else{
            // lets say it has run a few times
            p = head;
            while (p->next != NULL){
                p = p->next;    // whatever value was in the next node of p is now assigned to p (p++ kinda )

            }
            p->next = temp; // p is now in 79 so p->next is after 79 the temp node is attached
        }


        printf("Do you want to continue?(1/0) ");
        scanf("%d",&choice);
    }

    return head;

    // 23->46->79->NULL       50->NULL

}

int main(){
    int operation;
    node *head = NULL;

    printf("Select operations\n1.Create list\t2.Display list\t3.Add Elements at the Beginning\t4.Add elemets at the end: ");
    scanf("%d",&operation);
    char choice;
    while(choice != 'y'){
        if (operation == 1){
        head =  createLinkedList();
        
            
        }

        else if (operation == 2){
            display(head);
        }
        else if (operation == 3){
            head = AddElements_at_the_begining(head);
        }
        else if(operation == 4){
            head = AddElements_at_the_end(head);
        }

        printf("Want to change operation (y/n)? ");
        scanf(" %c",&choice);

        if (choice == 'y'){
            printf("Select operations\n1.Create list\t2.Display list\t3.Add Elements at the Beginning\t4.Add elemets at the end: ");
            scanf("%d",&operation);
            choice = 'n';
        }

    }

    display(head);


}
