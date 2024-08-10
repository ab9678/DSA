#include<stdio.h>
#include<stdlib.h>
# define N 5

int stack[N];
int address = -1;
int ifFull(){
    if (address > N-1){

        //stackoverflow
        printf("stackoverflow");
        display();
        exit(0);   
    
    }else{
        return 0;
    }
    
}
int ifEmpty(){
    if (address==-1){
           //stackunderflow
        printf("stackunderflow");
        exit(0); 
    }else{
        return 0;
    }
}
void push(){
    int x;
    printf("Enter data: ");
    scanf("%d",&x);
    address++;
    ifFull();
    
    
    stack[address]=x;



}
int pop(){

    ifEmpty();    
    printf("%d", stack[address]);
    address--;

    // if I return the element and then do address--, it returns the element but the adresss code never excecutes
    // this is because return statement returns the power to function call and anything after that is essentially unreachable 
    

}


int peek(){
    // return the top element to main()
    ifEmpty();
    printf("%d", stack[address]);
}
int display(){
    ifEmpty();
    for (int i = address ; i>-1 ; i--){
        printf("%d\n",stack[i]);
    }

}
int main(){
    int choice ;
    int exitstatus;

    do{
        printf("What do you want to perfotm\n1:push()\t2:pop()\t3:peek()\t4:Display()");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            push();                 //updates the stack
            break;
        case 2:
            pop();  //deletes element from stack generally top-most element not really,
            break;                  //popping means returning the top-most element and move the address to the next lower address, that way the original element becomes inaccessible
        case 3: peek();             // returns top-most element
            break;
        case 4: display();          //print the entire array from top to bottom/reverse order
            break;
        default:printf("Incorrect entry");
            break;
        }
        printf("Do you Want to exit?(0/1)");
        scanf("%d",&exitstatus);
    }while(exitstatus != 0);        // this is written to very if the user wants to exit, until then keep running
    
    printf("The Final stack is :\n");
    display();
    // for(int i =0 ; i<N ; i++){
    //     printf("%d\t",stack[i]);    //this is not needed after I write the display() function, display function will
    //                                 //do this 
    // }

}
