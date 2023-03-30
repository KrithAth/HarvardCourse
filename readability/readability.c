#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    float letters = 0;
    float words = 1;
    float sentences = 0;
    int n = strlen(text);

    for (int i = 0 ; i <= n ; i++)
    {
        //checking whether its a alphabet
        if (isalpha(text[i]))
        {
            letters++;
        }
        //checking whether its a space
        else if (isspace(text[i]))
        {
            words++;
        }
        //checking whether it starts a new sentence
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }

    }

    float l = (letters / words) * 100;
    float s = (sentences / words) * 100;
    float grade = 0.0588 * l - 0.296 * s - 15.8;


    grade = round(grade);

    //printing the grade number according to the calculation
    if (grade >= 1 && grade <= 16)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
}



