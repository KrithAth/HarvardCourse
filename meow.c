#include<stdio.h>

void meow(void)  //custom function , has to be declared on top, if not then at least declare it on top 
{
    printf("meow\n");
}
int main(void)
{
    for(int i=3 ; i<6 ; i++)
    {
        meow();
    }

}

/*
int i=3
while(i<6)
{
    print.....
    i++
}
*/