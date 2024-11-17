# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
// remember bubble sort is based on the logic that after each ietration of the whole array the largest elements bubbles up, so we need to decrease the size by 1 in eache iteration, also, if no swaps occur than we say array is sorted, for which we will use a variable which will track for if any swap occured. If yes than we will go for another iteration else this is the final sorted Array.

void bsort(int *a){

    // bool swap = false;
    int size =5;
    int i,j,temp;
    int swap = -1;

    while(swap != 0){
        swap = 0;

        for (i=0;i<size-1;i++){
            if(a[i]>a[i+1]){
                temp = a[i+1];
                a[i+1] = a[i];
                a[i] = temp;
                swap = 1;
            }
        }
        size--;

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


    printf("\nSorting... \n");
    
    bsort(a);

    for (i=0;i<5;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}