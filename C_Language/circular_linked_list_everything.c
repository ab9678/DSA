# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int data;
    struct node* next; 
}node;


node* tail  =  NULL;

int len(){

}
void createlist(int data,int position){
    node* newnode = NULL;
        
        newnode = (node*)malloc(sizeof(node));
        newnode->data = data;
        newnode->next = NULL;

    if (tail == NULL){
            
            tail=newnode;
            tail->next = newnode;  // point to itself since it is the first node also   (circular)
            // newnode->next = newnode
        
    }else{

        if (position == -1 || position == len()){
    
            newnode->next = tail->next; // right link first
            tail->next = newnode;   // left link next
            tail = newnode;

        }else {
            if (position > len()){
                printf("\nInvalid Postion");
                return;
            }

            if (position == 0){
                // insert at head
            }else{
                // while loop traerse to the reuired postion
                printf("\n\nINVALID\n\n");
            }
        }
    }        

}
void  append(){
    int choice;
    int data;
    int position = -1;
    printf("\n\n1.NORMAL\t2.POSITIONAL\nChoose: ");
    scanf("%d",&choice);

    printf("\nDATA: ");
    scanf("%d",&data);

    if (choice == 1){
        createlist(data,position);
    }else if (choice == 2){
        printf("\nPosition: ");
        scanf("%d",&position);
        createlist(data,position);
    }else{
        printf("\n\nINVALID\n\n");
    }


}



int main(){

int choice ;

while(1){
    printf("\n1.Append list\n2.Delete Element\n3.Display\n4.EXIT\n\nChoose: ");

    scanf("%d",&choice);

   if (choice == 1){
        append();

    }else if (choice == 2){
        deleteData();
    }
    else if(choice == 3){
        printf("Length:%d\n",len());
        Display();

    }else if (choice == 4){
        exit(EXIT_SUCCESS);
    }else{
        printf("\n\nINVALID\n\n");
    }
    
}
}



