// Write a program to reverse an integer number using recursion.

#include <stdio.h>

void reverse(int num, int *result)
{
    *result = (*result)*10+num%10;
    if(num<10) return;
    reverse(num/10, result);
}

int main()
{
    int num, result=0;
    printf("Enter number: ");
    scanf("%d",&num);
    reverse(num,&result);
    printf("Reverse: %d",result);
    return 0;
}

/*
Enter number: 12345
Reverse: 54321
*/
