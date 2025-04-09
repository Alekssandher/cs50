#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void indageUser();
void printPyramidArr(int n);

int main(void)
{
    indageUser();
    return 0;
}

void indageUser()
{
    int height;
    int result;

    while(1)
    {
        printf("Type a number\n");
        result = scanf("\n%d", &height);

        if(result != 1)
        {
            while(getchar() != '\n');

            continue;
        }

        if(height > 8 || height < 1)
        {

            continue;
        }

        printPyramidArr(height);
        break;
    }

    return;
}

void printPyramidArr(int n)
{
    char left[25];
    char right[25];
    char finalLine[60];

    int index = 0;

    for(int i = 0; i < n; i++)
    {
        int num = i + 3;

        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        left[index] = '#';
        right[index] = '#';

        snprintf(finalLine, sizeof(finalLine), "%s  %s", left, right);

        printf("%s\n", finalLine);

        index++;

    }

}

