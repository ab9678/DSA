#include<stdio.h>
#include<stdlib.h>
#define size 5

int q[size];
int front=-1;
int rear=-1;

int fullq(){
    if(rear==size-1){
        printf("queue is full\n");
        return 1;
    }else{
    return 0;
    }
}
int empty(){
    if(rear==front==-1){
        printf("queue is empty");
        return 1;
    }else{  
    return 0;
    }
}


void insert(){
      if(fullq()==0){
       printf("enter the data");
       scanf("%d",&q[rear]);
      }

}
void delete(){
    if(empty()!=0){
        printf("the delete element is\n");
    }
    else if(front=rear){
        front=rear=-1;
    }else{
        front++;
    }
 } 

void display(){
    if(empty()!=0){
        return;
    }
    int i;
    for(i=front;i<=rear;i++){
        printf("%d\t",&q[i]);
    }

}

     
int main(){
    
    int choice;

    while(1){
      printf("1.insert\n 2.delete\n 3.display\n");
      scanf("%d",&choice);
      switch(choice){
        case 1: insert();
               break;
        case 2: delete();
               break;
        case 3: display();
               break;
        default :printf("wrong choice");
               break;                     
      }

    }  
}