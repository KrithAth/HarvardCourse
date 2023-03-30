#include<stdio.h>
#include<cs50.h>

int main(void)
{
    char answer=get_char("Do you agree?  ");
    if (answer== 'y' || answer=='Y')
    {
        printf("agreed.\n");
    }
    else if(answer== 'n' || answer=='N')
    {
        printf("not agreed.\n");
    }
}
