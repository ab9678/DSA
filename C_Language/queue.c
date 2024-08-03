# include <stdio.h>

///
# define size 5
int q[size];
///
int front = -1;
int rear = -1;

// Functions used 
int add(int data);
int removeElement();
int emptyq();
int fullq();
int display();
int main(){
    int choice;
    char exit;
    int element;
   
    while (exit != 'y'){
        printf("\nWhat function to execute?\n 1.Enqueue(insert)\t2.Deque(delete)");
        scanf("%d",&choice);
        if (choice == 1){
            printf("\nInsert data: ");
            scanf("%d", &element);
            add(element);
        }

        if (choice == 2){
            removeElement();
        }
        printf("\nwant to exit ? (y/n)");
        scanf(" %c",&exit);
    }

    display();
}


int add(int data){


    if (fullq() == 1){
        printf("\nStructure is full\n");
    }else if (emptyq()==1){
        front =0;
        rear = 0;

        q[rear]=data;
    }else{
        rear = (rear+1)%size;
        q[rear] = data;
    }

    printf("\nFront = %d, Rear = %d",front , rear);
}

int removeElement(){
    if (emptyq()==1){
        printf("\nStructure is empty\n");

    }else if (front == rear){
        printf("\nSingle element present The element being removed is: %d\n",q[front]);
        front = rear = -1;
    }
    else{
        printf("\nThe element being removed is: %d\n",q[front]);

        front = (front+1)%size;
    }
    printf("\nFront = %d, Rear = %d",front , rear);
}

int emptyq(){
    if (front == -1 && rear == -1){
        return 1;
    }else{
        return 0;
    }
}
int fullq(){
    if (front == (rear+1)%size){    // or simply if front == 0 and rear == size or rear == front-1
        return 1;
    }else{
        return 0;
    }
}

int display(){
    int i;
    if (emptyq()==1){
        printf("\nStructure is empty");
    }else{
        for (i=front;i!=rear;i=(i+1)%size){
            printf("%d\t",q[i]);

        }
        printf("%d",q[rear]);
    }
}

