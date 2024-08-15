# include<stdio.h>
# include <stdlib.h>
/*
issues :
doesnt enter at the required position if said 2 it will enter after 2   [fixed]
does enter at the beginning of the lists    [fixed]
[new] doesn't enter at the end of the array if explicitly given an address that is the last element [fixed] 
*/
typedef struct node
{
    int data;
    struct node* next; 
}node;
node* display(node* head){
    node* p=head;
    
    while (p!= NULL){
        printf("%d->",*p);
        p = p->next;
        
    }
}
int length(node* head){
    node* p=head;
    int len=0;
    while (p!= NULL){
        
        p = p->next;
        len++;


    }
    return len;

}

node* specificEntry(node* head){
    node*temp = NULL;
    node* p = NULL;

    int i=0;
    int location;
    int len= length(head);
    display(head);
    printf("\nLocation: ");
    scanf("%d",&location);

    if(location > len){
        printf("\nInvalid location");
    }
    else{
        temp = (node*)malloc(sizeof(node));
        printf("Enter data: ");

        scanf("%d",&temp->data);
        temp->next = NULL;

        if ( head == NULL){
            head = temp;
        }else if(location == 0){
            temp->next = head;
            head = temp;
            
        }
        else if(location == len){
            p = head;
            while (p->next != NULL){
                p= p->next;
            }
            p->next = temp;
        }
        else{
            p=head;
            while (i<location-1){
                p=p->next;
                i++;
            }
            temp->next = p->next;
            p->next = temp;
        }
    }

    return head;
}
node* normalEntry(){
    node* temp=NULL;
    node* head=NULL;
    int data;
    char userChoice='y';
    node* i;
    while (userChoice != 'n'){
        
        temp = (node*)malloc(sizeof(node));
        
        printf("Data: ");
        scanf("%d",&temp->data);
        if (head == NULL){
            head = temp;
            temp->next = NULL;
                //coz there was nothing before temporary node
        }else{
            
            // temp->next = NULL;
            i = head;
            while (i->next != NULL)
            {
                i = i->next;
            }
            
            i->next = temp;
            temp->next = NULL;
            
        }

        printf("\nContinue?(y/n) ");
        scanf(" %c",&userChoice);

    }

    return head;
}

int main(){
int choice;
node* head=NULL;
printf("1. Normal Entry\n2. Specific Position Entry\nChoose: ");
scanf("%d",&choice);
char userchoice='n';
    while(userchoice == 'n'){
        if (choice == 1)
        {
            head = normalEntry();
        }
        else if (choice == 2)
        {
            head = specificEntry(head);
        }
        else if (choice ==3){
            display(head);
        }
        printf("Change operation?(y/n): ");
        scanf(" %c",&userchoice);

        if(userchoice == 'y'){
            printf("1. Normal Entry\n2. Specific Position Entry\n3.Display\nChoose: ");
            scanf("%d",&choice);
            userchoice = 'n';
        }

    }
}
