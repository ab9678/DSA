# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int data ;
    struct node* next;
    struct node* prev;
}node;



node* createlist();     // doubly linked list

node* append();   //case1 add at front case  to add at rear case3 at a specified location

void deleteData();   // delete node 

node* Display();


node* head = NULL;
int tailIndex=0;        // global variables
node* tail=NULL;


int len(){
    node* p = head;
    int i=0;
    while (p != NULL){      // p->next != NULL can be used but in that case we wont be able to insert at the end intuitively as per the current implementation with tailindex, because when we say 12->13->14 2position(0,1,2), it thinks it is the last position so tailindex is here hence it inserts the element at the end, but I want the elelement to replace the now last element, the last element will stay where it was, i.e, new data will be place after 1position. Now when I do p!=null, it iterated till just after the last node, so tailindex is 1+real tail. Now when i insert element at 2 position it will came between 13 and 14, and it will be the new 2position. and when I say 3 it will insert at the end after the taiindex.
        p = p -> next;
        i++;
    } 
    tailIndex = i;
    // printf("TAIL = %d\n",tailIndex);
    return i;
}


int main(){

    int choice ;

    while (1){
        printf("\n1.Create List\n2.Append list\n3.Delete Element (instructions same as above)\n4.Display\n5.EXIT\n\nChoose: ");


        scanf("%d",&choice);

        if(choice == 1){
            createlist();
        }else if (choice == 2){
            append();

        }else if (choice == 3){
            deleteData();
        }
        else if(choice == 4){
            printf("Length:%d",len());
            Display();

        }else if (choice == 5){
            exit(EXIT_SUCCESS);
        }
        
    }
}

node* createlist(){
    
    node* temp=NULL;
    node* p=NULL;   // iterator
    
    
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
            tail = temp;
        }else if(tail == NULL){
            p = head;
            while (p->next != NULL){
                p = p->next;

                
            }
            printf("\n tail is null so this part is running, there is a bug in the code");
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

    int location ;
    int index = 0 ;
    len();
    printf("TAIL: %d",len());
    printf("location: ");
    scanf("%d",&location);

    if (location > len()){
        printf("\nLoaction exceeds length\n");
    }
    else{
        if (tailIndex == 0){
            printf("\nEmpty list, Create the list first");
            return 0;
        }
        printf("New Data: ");
        temp = (node*)malloc(sizeof(node));
        scanf("%d",&temp->data);
        temp->next = NULL;
        temp->prev = NULL;

        if (location == tailIndex){     // append at the end
                                   
            tail->next = temp;
            temp -> prev = tail;
            tail = temp;

        }else if (location == 0){     // append at the beginning
            // if (head == NULL && tail == NULL){
            //     printf("\nEmpty list, Create the list first\n");
                
            // }else{
                temp->next = head;
                temp->next->prev = temp;
                head = temp;
                
            
        }
        else{
            p = head;
            int index = 0;
            while (index != location-1){
                p = p->next;
                index ++;
            }

            temp->next = p->next;
            p->next = temp;
            temp->prev = p;
            temp->next->prev = temp;


        }
    }
    
}
// 30->20->25->null         temp -> [prev|data|next]    
void deleteData(){
    len();
    int position , deleted, i=0;
    
    printf("Position: ");
    scanf("%d",&position);

    node* p = NULL;
    if (position<0 || position > len()){
        printf("Invalid Position");
        return;
    }
    else{
        if (position == 0){
            // delete from head
            p = head;
            if (p->next == NULL){   // when only one element is present
                head = NULL;
                free(p);
            }else{
                deleted = p->data;
                p->next->prev = NULL;   // make the second node the first, first node's previous is always NULL so make the prev here NULL
                head = p->next;     // take haed to that node

                free(p);    // free the memory consumed by that node
            }

        }
        else if (position == (len()-1)){
            // delete from tail
            p=tail;
            deleted = p->data;
            tail = p->prev;     // update tail to last-second node
            tail->next = NULL;      // the last-second node should not be pointing to anything for it to become the last node
            free(p);    // free memory of that node
            
        }
        else{
            // delete from a specific position
            p = head;
            while (i != position){
                p = p->next;
                i++;
            }
            
            // now p is in the required node
            deleted = p->data;
            p->next->prev = p->prev;
            p->prev->next = p->next;
            free(p);


        }
    }

    printf("Delete Data: %d",deleted);


}

// its 149 actual lines of code.