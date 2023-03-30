#include <cs50.h>
#include <stdio.h>

int main(void)
{
  int height;
  do
  {
    height = get_int("Height: ");
  }
  while(height < 1 || height > 8);

  for(int i = 1; i <= height; i++)              // for adding coloumns
    {
      for(int n = height - 1 ; n >= i ; n--)    //for printing empty spaces in descending pyramid
      {
        printf(" ");
      }
      for(int j = 1 ; j <= i ; j++)             // for printing hash rows to form ascending pyramid
      {
        printf("#");
      }
        printf("  ");
      for(int j = 1 ; j <= i ; j++)
      {
        printf("#");
      }
      printf("\n");
    }
}