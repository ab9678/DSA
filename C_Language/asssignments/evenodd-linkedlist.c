// // delete all nodes have even number information and move them to L1 and delete all nodes have odd number of Information and move them to L2 to

# include <stdio.h>
# include <stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
    // struct node* prev; 
}node;

node* even=NULL;
node* odd = NULL;
node* original = NULL;
node* tail_original = NULL;
void displayList(node* head, const char* listName) {
    node* temp = head;
    
    printf("%s : ", listName);
    if (temp == NULL) {
        printf("Empty\n");
        return;
    }
    
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void insert(node** head , int data){
    node* newnode = NULL;
    node* p = *head;
    newnode = (node*)malloc(sizeof(node));
    newnode->next = NULL;
    newnode->data = data;

    if (*head == NULL ){
        *head = newnode;
        newnode->next = NULL;
    }else{
        while (p->next != NULL){
            p=p->next;
        }
        p->next = newnode;
        newnode->next = NULL;
    }
}

void originalList(){
    node* newnode = NULL;
    char choice;
while(choice!='y'){
    newnode = (node*)malloc(sizeof(node));
    printf("Data: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    if(original==NULL){
        original = newnode;
        tail_original=newnode;
    }else{
        tail_original->next = newnode;
        tail_original = newnode;
    }
    printf("Exit?(y/n)");
    scanf(" %c",&choice);
}
displayList(original,"Previously Original list");
}

void comparison(){
    node* temp = NULL;
    temp=original;
    while(temp!=NULL){
        node* p = NULL;
        p=temp;
        temp=temp->next;

        if(p->data%2 != 0){
            // odd
            insert(&odd,p->data);
        }else if (p->data%2 == 0){
            // even
            insert(&even,p->data);
        }

        if(original->next == NULL){
            p=original;
            original = NULL;
            free(p);
        }else{
        // delete head node
        original = original->next;
        p->next = NULL;
        free(p);
        }

    }
}


int main(){

    printf("\nLets start\n");
    originalList();
    comparison();
    displayList(even,"Even list");
    displayList(odd,"Odd list");
    displayList(original,"Original list");

}

