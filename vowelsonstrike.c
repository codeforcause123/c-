#include <stdio.h>
#include <stdbool.h>
#include<string.h>
bool isvowel(char c){
    switch (c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        return 1;
    default:
        return 0;
    }
}
int main()
{
    char s[100],t[100];
    int i=0,j=0;
    gets(s);
    for(i=0;s[i]!='\0';i<i++){
        if(!isvowel(s[i])){
            t[j]=s[i];
            j++;
        }
    }
    t[j]='\0';
    strcpy(s,t);
    puts(s);
    return 0;
}