# include <stdio.h>
# include <stdlib.h>


int main(){
    int choice;
    while (1){
        printf("\n1.Create List\n2.Append list\n3.Delete Element (instructions same as above)\n4.Display\n5.EXIT\n\nChoose: ");
        scanf("%d",&choice);
        if (choice == 1){
            createlist();
        }else if (choice == 2){
            appendlist();
        }else if (choice == 3){
            deletenode();
        }else if (choice == 4){
            display();
        }else if (choice == 5){
            exit(EXIT_SUCCESS);
        }else{
            printf("\e[0;32mINVALID INPUT\e[0m");
        }
    
    }
}