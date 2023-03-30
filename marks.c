#include<stdio.h>
#include<cs50.h>

int main(void)
{
    const int MINE=2;
    int marks=get_int("how many marks did you lose?  ");
    if(marks<MINE)
    {
        printf("you lost less marks than me\n");
    }
    else if(marks>MINE)
    {
        printf("you lost more marks than me\n");

    }
    else
    {
        printf("we lost same number of marks\n");
    }
}