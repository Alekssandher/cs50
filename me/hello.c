#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[100];
    printf("What is your name?\n");
    scanf("%99s", name);
    int result = strcmp("Adele", name);

    if(result == 0 )
    {
        printf("Hello, Adele\n");
        return 0;
    }
    printf("Hello, %s\n", name);
    return 0;
}
