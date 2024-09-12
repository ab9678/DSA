// lets try to do it this time
#include <ctype.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define N 20
typedef struct dictionary{
    char key;   // the actual character
    int value;  // precedence of the char
    int index;  // index at which the char came in the original expression
}dictionary;

dictionary stack1 [N];  // it will compare the operands
int top1 = -1;

char stack2 [N];    // it will store the final expression operands
int top2 = -1;

char exprs[N];    // the original expression.

void pop1(){
    top2++;
    stack2[top2] = stack1[top1].key;    // key is char
    printf("Popping: %c\n",stack1[top1].key);
    top1--;
}
void push1 (char x,int i,int v){
    top1++;
    printf("pushing: %c\n", x);
    stack1[top1].index = i;
    stack1[top1].key = x;
    stack1[top1].value = v;
}
void push2 (char x){
    // printf("pushing: %c\n", x);
    top2++;
    stack2[top2] = x;
}
// pop2(){

// }
void display() {
    printf("Postfix: ");
    for (int i = 0; i <= top2; i++) {
        printf("%c", stack2[i]);
    }
    printf("\n");
}

int main(){
    printf("Expression: ");
    fgets(exprs,N,stdin);
        exprs[strcspn(exprs, "\n")] = '\0';

    printf("Original: ");
    puts(exprs);
    char x;
    int precedence;
    int prev_precedence;
    int associativity;
    int i;
    for(i = 0; exprs[i] != '\0'; i++){    // will iterate until null character is found which is a property of strings
        if (isalnum(exprs[i])){
            push2(exprs[i]);
        }else{

            // main comparison part;
            x = exprs[i];
            if (x == '+' || x == '-'){
                precedence = 1;
            }else if (x == '*' || x == '/'){
                precedence = 2;
            }else if (x == '^'){
                precedence = 3;
            }else if (x == '('){
                push1(x,i,0);
                continue;
            }else if (x == ')'){
                while (stack1[top1].key != '('){
                    pop1();
                }
                top1--; // also remove ( as well;
                continue;
            }    
            // if (top1 == -1){
            //     push1(exprs[i],i,precedence);
            // }else{
            while(top1 != -1 && (precedence < stack1[top1].value || (precedence == stack1[top1].value && x != '^'))){
            
                pop1();              
                
            }
            push1(exprs[i],i,precedence);     
        }
    }
    // Pop any remaining operators in the stack
    while (top1 != -1) {
        pop1();
    }
    // Display the final postfix expression
    display();

}