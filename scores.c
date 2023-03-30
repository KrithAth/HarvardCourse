#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int scores[4];     //trying to use arrays

    scores[0] = 78;
    scores[1] = 55;
    scores[2] = 76;

    printf("The Average is: %F", (scores[0] + scores[1] + scores[2]) / 3.0);

}