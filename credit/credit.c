#include <cs50.h>
#include <stdio.h>

long verifyvisa(long vnumber)                                       //calculations for visa
{
    long v2;
    long v3;
    long v4;

    for(long i = 100 ; i <= 10000000000000000 ; i = i * 100) //to select alternate digits
    {
        v3 = (((vnumber % i - vnumber % (i / 10)) / (i / 10)) * 2) ;// calc of selected digits
        v2 = v2 + (v3 % 10 + (((v3 % 100)-(v3 % 10)) / 10)); // sum of digits of products we got before
    }

    for(long j = 10 ; j <= 10000000000000000 ; j = j * 100) //selecting other alternate digits
    {
        v4 = (v4 + ((vnumber % j - vnumber % (j / 10)) / (j / 10))) ;
    }

    return v2 + v4;
}

int main(void)
{
    long number = get_long("Number: ");
    long SL = verifyvisa(number);
    if(SL % 10 == 0)

    {
        if(((number % 10000000000000000 - number % 1000000000000000) /1000000000000000) == 4 || ((number % 10000000000000 - number % 1000000000000) /1000000000000) == 4) //checking whether first digit is 4

            printf("VISA\n");

        else if(((number % 1000000000000000 - number % 10000000000000) / 10000000000000) == 37 || ((number % 1000000000000000 - number % 10000000000000) / 10000000000000) == 34)       //checking whether first digits are 37 and 34


            printf("AMEX\n");

        else if(((number % 10000000000000000 - number % 100000000000000) / 100000000000000) == 51 || ((number % 10000000000000000 - number % 100000000000000) / 100000000000000) == 52 || ((number % 10000000000000000 - number % 100000000000000) / 100000000000000) == 53 || ((number % 10000000000000000 - number % 100000000000000) / 100000000000000) == 54 || ((number % 10000000000000000 - number % 100000000000000) / 100000000000000) == 55)         //checking whether first digits are 51,52,53,54,55

            printf("MASTERCARD\n");

        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}


