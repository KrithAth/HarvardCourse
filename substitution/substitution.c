#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int valid_key(string text);
int encryption(string text, string key);

int main(int argc, string argv[])
{
    string key = argv[1];
    if (argc !=2 )
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (valid_key(key) == 1)
    {
        return 1;
    }
    string text = get_string("plaintext:  ");
    encryption(text, key);
    return 0;
}

int valid_key(string key)
{
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        for (int i = 0 ; i <= strlen(key) ; i++)
        {
            for (int j = i + 1 ; j <= strlen(key) ; j++)
            {
                if (toupper(key[i]) == toupper(key[j]))
                {
                    printf("Usage: ./substitution key\n");
                    return 1;
                }
            }
        }
    }
    return 0;
}

int encryption(string text, string key)
{
    for (int i = 0 ; i <= strlen(text) ; i++)
    {
        int position = (toupper(text[i]) - 'A');
        char replace = key[position];
        printf("%c", replace);
    }
    printf("\n");
    return 0;
}