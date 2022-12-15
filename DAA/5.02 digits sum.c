// Write a program to find sum of all digits using recursion.

#include <stdio.h>

int sum(int num){
    if(num==0) return 0;
    return (sum(num/10)+(num%10));
}

int main(){
    int num;
    printf("Enter number: ");
    scanf("%d",&num);
    printf("Sum of digits: %d",sum(num));
    return 0;
}

/*
Enter number: 123
Sum of digits: 6
*/
