#include<cs50.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
    string input = get_string("Input: ");
    printf("After: ");
    for(int i=0 , n = strlen(input); i <= n; i++)
    {
        printf("%c", toupper(input[i]));

        /*if(islower(input[i]))                                         // OR    (input[i] >= 'a' && input[i] <= 'z')
        {
        printf("%c", input[i] - 32);
        }
        else
        {
        printf("%c", input[i]);
        }
        */
    }
    printf("\n");
}