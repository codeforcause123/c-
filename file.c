#include <stdio.h>

int main(){
    FILE *ptr;
    char str[30]="THis file is for c";
    ptr=fopen("myfile.txt","w");
    fprintf(ptr,"%s",str);
    printf("%d",ptr);
    fclose(ptr);
    return 0;
}