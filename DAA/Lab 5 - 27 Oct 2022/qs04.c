// Write a program to find the GCD (Greatest Common Divisor) of given numbers using recursion.

#include <stdio.h>

int hcf(int n1,int n2){
    if(n2!=0) return hcf(n2,n1%n2);
    return n1;
}

int main()
{
    int n1,n2;
    printf("Enter 2 numbers: ");
    scanf("%d %d",&n1,&n2);
    printf("HCF: %d",hcf(n1,n2));
    return 0;
}

/*
Enter 2 numbers: 24 36
HCF: 12
*/
