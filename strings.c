#include<stdio.h>
#include<cs50.h>
#include<string.h>

int main(void)
{
    string A = get_string("anything: ");
    int length = strlen(A);
    printf("Length: %i\n", length);
}