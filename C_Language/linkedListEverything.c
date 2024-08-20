# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int data ;
    struct node* next;
    struct node* prev;
}node;



node* createlist();     // doubly linked list

node* append();   //case1 add at front case  to add at rear case3 at a specified location

node* delete();   // delete node 

node* Display();




node* head = NULL;


int main(){


 
int choice ;

while (1){
    printf("\n1.Create List\n2.Append list ('F' for first position, 'L' for Last psoition, numbers for anything in between)\n3.Delete Element (instructions same as above)\n4.Display\n5.EXIT\n\nChoose: ");


    scanf("%d",&choice);

    if(choice == 1){
        createlist();
    }else if (choice == 2){
        head = append(head);

    }
    else if(choice == 4){
        Display();
    }else if (choice == 5){
        exit(EXIT_SUCCESS);
    }

    
    
}



}

node* createlist(){
    
    node* temp=NULL;
    node* p=NULL;
    node* tail=NULL;
    
    char usrChoice = 'y';

    while (usrChoice == 'y'){
        temp = (node*)malloc(sizeof(node));

        printf("Data: ");
        scanf("%d",&temp->data);

        temp->next = NULL;
        temp->prev = NULL;

        if (head == NULL){
            temp->prev = NULL;  // there is no node before this
            head = temp;
        }else if(tail == NULL){
            p = head;
            while (p->next != NULL){
                p = p->next;
            }
            p->next = temp;
            temp->prev =p;
            temp->next = NULL;
            tail=temp;

        }else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            
        }

        printf("Continue?(y/n) ");
        scanf(" %c",&usrChoice);
    }
    return head;

}
node* Display(){
    node* p = NULL;

    p = head;
    while (p != NULL){
        
        printf("%d->",p->data);
        p=p->next;
    }
}
node* append(){
    node* p = NULL;
    node* temp = NULL;

    int location;
    printf("");
}
// 30->20->25->null         temp -> [prev|data|next]
