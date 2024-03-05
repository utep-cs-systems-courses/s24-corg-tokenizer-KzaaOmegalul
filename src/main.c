#include <stdio.h>
#include <string.h>

int main()
{
  char userInput[100];
  while(1)
    {
      printf(">");
      scanf(" %[^\n]", userInput);
      printf("%s\n", userInput);
    }
  return 0;
}
