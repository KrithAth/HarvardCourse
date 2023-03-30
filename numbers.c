#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int numbers[] = {2, 4, 5, 8, 3, 5, 9, 6, 1};
    for (int i = 0; i < 9; i++)
    {
        if (numbers[i] == 11
        )
        {
            printf("Found\n");
            return 0;
        }

    }
    printf("Not Found\n");
    return 1;
}