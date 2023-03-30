#include<stdio.h>
#include<cs50.h>

int main(void)
{
    //promt user for x
    long x = get_long("x:  ");

    //promy user for y
    long y = get_long("y:  ");

    //summation of user inputs
    long z = x + y ;
    printf("Sum: %li \n", z);
}