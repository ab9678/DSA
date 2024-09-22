// create a linked list with field student roll-number, students name, students marks and in three subjects calculate total marks, count how many students have first, second and third division and how many have failed.
// 60 to 74% First Division. 45 to 60% Second Division. Less than 45 >35 % Third Division
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct studentList{
    int roll;
    char name[10];
    int sub1;
    int sub2;
    int sub3;
    struct studentList* next;
}studentList;

studentList* head = NULL;
studentList* tail = NULL;

void createList();
void analysis();
void display();
int main(){
    int input;
    while(1){
        printf("\n1.Create a list of students' data\n2.Analyse the data\nSelect: ");
        scanf("%d",&input);

        if (input == 1){
            createList();
        }else if (input == 2){
            analysis();
        }else{
            printf("\nInvlaid Input, please try again\n");
        }
    }
}

void createList(){
    studentList* newnode = NULL;

    newnode = (studentList*)malloc(sizeof(studentList));
    
    printf("Enter Roll Number: ");
    scanf("%d",&newnode->roll);
    getchar();
    printf("Name: ");
    fgets(newnode->name,10,stdin);  // scanf leaves newline character that fgets takes an input, hence not working as intended. To correct thi either we can do fgets at the biginning or getchar() will consume that newline character
    
    printf("Marks in sub1: ");
    scanf("%d",&newnode->sub1);
    
    printf("Marks in sub2: ");
    scanf("%d",&newnode->sub2);

    printf("Marks in sub3: ");
    scanf("%d",&newnode->sub3);

    if (head == NULL){
        head = newnode;
        tail = newnode;
    }else{
        tail->next = newnode;
        tail = newnode;
    }

}

void analysis(){
    studentList* temp=head;
    int count1stDiv = 0;
    int count2ndDiv = 0;
    int count3rdDiv = 0;
    int totalMarks =0;
    int failed = 0;
    int percentage = 0;
    while(temp!=NULL){
        printf("\n");
        printf("\nName: ");
        puts(temp->name);
        totalMarks = temp->sub1+temp->sub2+temp->sub3;
        percentage = ((float)totalMarks/300)*100;

        printf("Total: %d",totalMarks);
        printf("\nPercentage: %d",percentage);
        if(percentage >= 60){
            printf("\nCogratulations! You have got 1st division");
            count1stDiv++;
        }else if (percentage >= 45 && percentage <60){
            printf("\nYou have got 2nd Division!");
            count2ndDiv++;
        }else if (percentage >= 30 && percentage < 45){
            printf("\nYou have got 3rd division, nvm, gotta work harder!");
            count3rdDiv++;
        }else{
            printf("\nYou have failed this time, work harder!");
            failed++;
        }
        temp = temp->next;
        
        // reset the data
        totalMarks = 0;
        percentage = 0;
    }

    printf("\n\nNumber of students getting 1st division: %d",count1stDiv);
    printf("\nNumber of students getting 2st division: %d",count2ndDiv);
    printf("\nNumber of students getting 3st division: %d",count3rdDiv);
    printf("\nNumber of students failed: %d\n",failed);

}