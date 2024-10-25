/*
Given a string, , consisting of alphabets and digits, find the frequency of each digit in the given string.

Input Format

The first line contains a string,  which is the given number.

Constraints


All the elements of num are made of english alphabets and digits.

Output Format

Print ten space-separated integers in a single line denoting the frequency of each digit from  to .

Sample Input 0

a11472o5t6
Sample Output 0

0 2 1 0 1 1 1 1 0 0 
Explanation 0

In the given string:

1 occurs two times.
2, 4, 5, 6 and 7 occur one time each.
The remaining digits  and  don't occur at all.
Sample Input 1

lw4n88j12n1
Sample Output 1

0 2 1 0 1 0 0 0 2 0 
Sample Input 2

1v88886l256338ar0ekk
Sample Output 2

1 1 1 2 0 1 2 0 5 0 
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    
    char string[1000];
    int counting[10]={0};
    scanf("%s",&string);
    int num = 0, i = 0;
    int count;
    while(num < 10){
        count = 0;
        for (i=0;string[i]!='\0';i++){
            if (string[i] == num + '0'){
                count++;
            }
        }
        counting[num] = count;
        num++;
    }
    
    for (i=0;i<10;i++){
        printf("%d ",counting[i]);
    }
    
    return 0;
}
