// Find the largest ans smallest elemets in a linked list. Print sum of all elements and calculate the average

# include <stdio.h>
# include <stdlib.h>

typedef struct linked_list{
    int data;
    struct linked_list* next;
}linked_list;

linked_list* head = NULL;
linked_list* tail = NULL;

void createlist(){
    linked_list* newnode = NULL;
    char choice;
    while(choice != 'n'){
        newnode = (linked_list*)malloc(sizeof(linked_list));
        printf("Data: ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;

        if (head == NULL){
            head = newnode;
            tail = newnode;
        }else{
            tail->next = newnode;
            tail = newnode;
        }
        printf("Continue?(y/n): ");
        scanf(" %c",&choice);
    }
}

int total_average_largestSmallest(){
    linked_list* temp=head;
    int total=0;
    int i=0;
    int largest = 0;
    int smallest=temp->data;
    while (temp!=NULL)
    {
        i++;
        total+=temp->data;
        if(temp->data<smallest){
            smallest=temp->data;
        }
        if(temp->data>largest){
            largest = temp->data;
        }
        temp=temp->next;
        
    }

    printf("\nTotal=%d\nAverage=%d\nLargest=%d\nSmallest=%d",total,total/i,largest,smallest);
    
}

void display(){
    linked_list* temp=head;
    printf("\nOriginal list is:--\n");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
}
 

int main(){
    createlist();
    total_average_largestSmallest();
    display();
}