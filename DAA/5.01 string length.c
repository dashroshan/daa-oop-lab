// Write a program to calculate length of the string using recursion

#include <stdio.h>

int length(char *str){
    if(*str=='\0') return 0;
    return (length(str+1)+1);
}

int main(){
    char str[100];
    printf("Enter string: ");
    scanf("%[^\n]",str);
    printf("Length of string: %d",length(str));
    return 0;
}

/*
Enter string: roshan
Length of string: 6
*/
