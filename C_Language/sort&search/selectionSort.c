# include <stdio.h>
# include <stdlib.h>
void sort(int *a){
    int i=0,j,k;
    int temp;
    while(i<5){
        for (j=i;j<5;j++){
            if(a[j]<a[i]){
                temp=a[i];
                a[i] = a[j];
                a[j]=temp;
            }
        }
        i++;
    }
    printf("Final:\n");
    for (i=0;i<5;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}
int main(){
int arr[5];
int i;
printf("Enter elements: \n");
for (i=0;i<5;i++){
    scanf("%d",&arr[i]);
}
// insertions of elements done
sort(arr);
}