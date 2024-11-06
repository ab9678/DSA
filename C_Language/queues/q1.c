// normal implementation of queue using fixed array
# include<stdio.h>
# include <stdlib.h>
# define size 5
/*
p = head
front = delete  front++ delete
rear = insert   r++, arr[rear]=data

*/
int q[size];
int front = -1, rear = -1;

int fullq(){
    if(rear==size-1){
        return 1;
    }else{
        return 0;
    }
}

int empty(){
    if (rear==front==-1){
        return 1;
    }
    return 0;
}

void insert(){

    if(fullq()==1){       // 0 is true 1 or anythings else if false, so if full() will check if true or false 
        printf("\nfull");
        return;
    }
    printf("\nEnter data: ");
    rear++;
    scanf("%d",&q[rear]);


}

// for(1=0;i<size;i++){
//     scanf("%d",&q[i]);
// }

void delete(){
    if (empty()==1){
        printf("\nEmpty");
        return;
    }
    else if (front==rear){      // when only 1 element is present.
        front=rear=-1;
    }
    else{
        front++;
    }
}

void display(){
    if(empty()==1){
        printf("\nempty\n");
        return;
    }
    int i;


    for (i=rear;i>front;i--){
        printf("%d\t",q[i]);
    }
    // printf("%d",q[rear]);
}

int main(){

    int choice;
    while(1){
        printf("1.Insert\n2.Delete\n3.Display\nChoose: ");
        scanf("%d",&choice);
        if(choice == 1){
            insert();
        }else if(choice == 2){
            delete();
        }else{
            display();
        }
    }


    // switch (choice)
    // {
    // case 1:
    //     insert();
    //     break;
    
    // default:
    //     break;
    // }


}