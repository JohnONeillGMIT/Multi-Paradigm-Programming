#include <stdio.h>
#include <string.h>

int main()
{
    char* name;
    printf("What is your name?");

    gets(name);

    if((strcmp(name,"Alice")==0) || (strcmp(name,"Bob")==0))
    {
        printf("Hello %s\n", name);
    }
    else
    {
        printf("Hello lowly peasent!\n"); 
    } 
    return 0;
}