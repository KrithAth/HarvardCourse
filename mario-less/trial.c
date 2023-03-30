#include<stdio.h>

int main()
{
  int height;
  do
  {
    printf("Enter the height: ");
    scanf("%d", &height);
  }
  while(height<1 && height>8);

  if(height>=1 && height<=8)
  {
    printf("Stored: %d\n", height);
  }
    return 0;
}