/*
Q4. frequency of a given item in list
    num of non zero lement 
    add value k in all node->data
    delete lastnode from the list
*/



# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    int flag;
}node;
node* head = NULL;
node* tail = NULL;

int len(){
    node* p = head;
    int i=1;
    if (p==NULL){
        return 0;
    }
    while (p != NULL){      // p->next != NULL can be used but in that case we wont be able to insert at the end intuitively as per the current implementation with tailindex, because when we say 12->13->14 2position(0,1,2), it thinks it is the last position so tailindex is here hence it inserts the element at the end, but I want the elelement to replace the now last element, the last element will stay where it was, i.e, new data will be place after 1position. Now when I do p!=null, it iterated till just after the last node, so tailindex is 1+real tail. Now when i insert element at 2 position it will came between 13 and 14, and it will be the new 2position. and when I say 3 it will insert at the end after the taiindex.
        p = p -> next;
        i++;
    } 
    
    // printf("TAIL = %d\n",tailIndex);
    return i;
}
node* Display(){

    if (len() == 0){
        printf("\nEmpty linked list");
    }else{
        node* p = NULL;

        p = head;
        while (p != NULL){
            
            printf("%d->",p->data);
            p=p->next;
        }
    }
}
int frequency_And_zerocount(){
    node* temp1 = head;
    node* temp2 = head;
    int count=0;
    int zerocount=0;
    while(temp1 != NULL){
        if (temp1->data == 0){
            zerocount ++;
        }
        temp2 = head;
        count = 0;
        while (temp2 != NULL){

            if (temp2->data == temp1->data){
                count++;
                temp2->flag = 1;
            }
            
            temp2 = temp2->next;
        }
 
        if (count != 0){
            printf("\n(Element)%d : %d",temp1->data,count);
            
        }

        while (temp1!=NULL && temp1->flag == 1){
            temp1 = temp1->next;
        }
    }

    printf("\nNon Zero elements: %d",len()-zerocount-1);
    temp1 = head;           // seriously I am dumb, damn I always forget to initialise temp to head before iterating
    while(temp1!= NULL){
        temp1->flag = 0;
        temp1 = temp1->next;
    }


}

node* normalEntry(){
    node* temp=NULL;
    // node* head=NULL;
    int data;
    char userChoice='y';
    node* i;
    while (userChoice != 'n'){
        
        temp = (node*)malloc(sizeof(node));
        temp->flag = 0;
        printf("Data: ");
        scanf("%d",&temp->data);
        if (head == NULL){
            head = temp;
            tail = temp;
            temp->next = NULL;
                //coz there was nothing before temporary node
        }else{           
            // temp->next = NULL;
            
            tail->next = temp;
            tail = temp;
                  
        }

        printf("\nContinue?(y/n) ");
        scanf(" %c",&userChoice);

    }

    
}
void Delete(){
    node* temp = NULL;
    node* p = tail;
    temp = head;
    if(temp->next ==NULL){
        head = NULL;
        free(tail);
    }else{
        while(temp->next->next!=NULL){
        temp=temp->next;
        }
        temp->next = NULL;
        tail=temp;
        free(p);
    }
    

    
    

}
int main(){
    node* temp=head;
    int choice;
    while (1){
        printf("\n1.Entry\n2.Frequency\n3.Exit\n4.Display\n5.Delete\n\nChoose: ");
        scanf(" %d",&choice);
        if (choice == 1){
            normalEntry();
        }else if (choice == 2){
            frequency_And_zerocount();
            
        }else if (choice == 4){
            Display();
        }

        else if (choice == 3){
            exit(0);
        }else if(choice == 5){
            Delete();
        }
    }
}