#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 0};
    printf("%i\n", (*numbers  + 1));
    printf("%i\n", (*numbers  + 2));
    printf("%i\n", (*numbers  + 3));
    printf("%i\n", (*numbers  + 4));
    printf("%i\n", (*numbers  + 5));
    printf("%i\n", (*numbers  + 6));
    printf("%i\n", (*numbers  + 9));
}