# include<stdio.h>
# include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next; 
}node;

node* normalEntry(){
    node* temp;
    node* head;
    int data;
    char userChoice;
    node* i;
    while (userChoice != 'y'){
        temp = (node*)malloc(sizeof(node));
        temp->next = NULL;
        printf("Data: ");
        scanf("%d",&data);
        if (head == NULL){
            temp->data = data;
            head = temp;    //coz there was nothing before temporary node
        }else{
            temp->data = data;
            // temp->next = NULL;
            while (i->next != NULL)
            {
                i = i->next;
            }
            i->next = temp;
            
        }
    }

    return head;
}

int main(){
int choice;
node* head;
printf("1. Normal Entry\n2. Specific Position Entry\nChoose: ");
scanf("%d",&choice);
    if (choice == 1)
    {
        head = normalEntry();
    }
    else if (choice == 2)
    {
        specificEntry();
    }

}
