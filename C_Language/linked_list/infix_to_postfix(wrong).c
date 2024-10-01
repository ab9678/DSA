# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define N 20
typedef struct list_of_operands {
    char operand;
    int value;
}operand;

operand list[5];

operand stack_compare[N];
int top_compare = -1;
char stack_result[N];
int top_result = -1;

char expression[N];


void display(){
    while (top_result>-1){
        printf(" %c",stack_result[top_result]);
        top_result--;
    }
}




void compare(char operand, int value){
    if (top_compare == -1){
        top_compare++;
        stack_compare[top_compare].operand = operand;
        stack_compare[top_compare].value = value;
    }else{
        while(top_compare>-1){
            if (value<stack_compare[top_compare].value ){
                top_result++;
                stack_result[top_result] = stack_compare[top_compare].operand;
                top_compare--; 
            }else{
                if (value>stack_compare[top_compare].value){
                    top_compare++;
                    stack_compare[top_compare].operand = operand;
                    stack_compare[top_compare].value = value;
                }
                break;

            }
        }
    }
}

void determine(){
    int i=0;
    int j=0;
    int flag = -1;
    for (i=0;expression[i]!='\0';i++){
        flag = -1;
        for (j=0;j<5;j++){
            if (expression[i]==list[j].operand){
                compare(expression[i],list[j].value);
                flag = 0;
                break;
            }
        }
        if (flag==-1){
            top_result++;   // infix expression will start with a constant so no need to adress if top = -1
            stack_result[top_result] = expression[i];   // indicates element is a constant
        }  
            
        
    }
    if (expression[i]=='\0'){
        while(top_compare>-1){
            // pop everything
            top_result++;
            stack_result[top_result] = stack_compare[top_compare].operand;
            top_compare--;
        }
    }

}

int main(){
    

    list[0].operand = '+';
    list[0].value = 1;

    list[1].operand = '-';
    list[1].value = 1;

    list[2].operand = '*';
    list[2].value = 2;

    list[3].operand = '/';
    list[3].value = 2;

    list[4].operand = '^';
    list[4].value = 3;

    // the opreator +-/* are left associative, simply , chack if the stack[top] == expression, that means it was right side of that in the original, so higher priority. 


    

    printf("Expression: ");
    fgets(expression,N,stdin);
    printf("Original: ");
    puts(expression);

    //int i = 0;
    // for (i=0;expression[i]!= '\0';i++){
    //     printf("\n%d,%c",i,expression[i]);
    // }

    determine();
    display();
}