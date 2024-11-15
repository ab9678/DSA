# include <stdio.h>
# include <stdlib.h>

# include <stdbool.h>

void search(int data,int *a){

    int i;
    for (i=0;i<5;i++){
        if (a[i]==data){
            printf("Found, %d\n",a[i]);
            return;
        }
    }



}


int main(){

int a[5];
int element;
int i;

printf("Enter data: \n");

for (i=0;i<5;i++){
    scanf("%d",&a[i]);
}


printf("\nSearch: ");
scanf("%d",&element);

search(element,a);

}