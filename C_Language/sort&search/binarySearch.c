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

void search(int *a, int data, int start, int end){
    // int element;
    int index = (start+end)/2;   // because lets say in second iteration we have a subset with index 5 to 10 , so divide it, we will get 2, but we need 2 indeices after 5th index, so we can add it to 5, 5+2 = 7 so index will be in 8; EITHER, or we can just add the start & end and divide that by 2, eg. 5+10=15/2=7

    if(start >= end) {
        if(a[index]==data){
            printf("Found, %d",a[index]);
        }else{
            printf("Not Found :(\n");
        }
        return;
    }
    if(a[index] == data ){
        printf("Found, %d",a[index]);
        return;
    }
    if(data>a[index]){
        search(a,data,index+1,end);
    }else if (data<a[index]){
        search(a,data,start,index);
    }

    // VERY BIG COMMENT
    /*
    
        lets get to this weird but iteresting thing.

        1.Right array index or index+1
        why?
            good question, lets see it this way, you got a number at the end of the array and you want to search that number. Now what will happen is the start value will be at the end, lets say 10 elements list, start = 9 end = 10 , 10+9=19/2 = 9, so the 9th will again become the index and this will go on until segmentation fault. That's why we are doing index+1, so that this never happens.

        how it works 
            all it does is it eliminated the index we already searched and since int division will round off to the lower value, the case where the same index will keep repeating will never occur
        why otherwise it wont work
            lets say 10 elements list, start = 9 end = 10 , 10+9=19/2 = 9, so the 9th will again become the index and this will go on until segmentation fault. That's why we are doing index+1, so that this never happens.
        how to get by even if we use 'index' instead of 'index+1'
            what we can do is, in the very beginning, we can use a if condition, to check if the element at the end index == data, that way the infinite loop can be avoided, because, though due to the logic infinite loop is inevitable, but not as much as thanos, coz all I need is get his head, I mean already check if the end index has the element, so no need to continue the recursion in the first place :).
        get some fun!

        tl;dr
    
    */ 
}
int main(){
    int a[5];
    int i;
    int data;
    printf("Enter data: \n");
    for (i=0;i<5;i++){
        scanf("%d",&a[i]);
    }
    printf("\nSearch: ");
    scanf("%d",&data);
    sort(a);
    search(a,data,0,5);
}