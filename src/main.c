#include <stdio.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char userInput[100];
  int FLAG = 1;
  List* history = init_history();
  while(FLAG)
    {
      printf("Enter q: Quit Program\nEnter h: Print History\nEnter g: Get History @ Specified ID\n\n");
      printf("Write a Sentence or Enter Valid Character\n");
      printf(">");
      scanf(" %[^\n]", userInput);
      switch(*userInput)
	{
	case 'q':
	  FLAG = 0;
	  break;
	case 'h':
	  print_history(history);
	  break;
	case 'g':
	  int id;
	  printf("Enter A Valid History ID:\n");
	  scanf("%d", id);
	  printf("Word at ID, %d is %s:\n", id, get_history(history, id));
	  break;
	default:
	  char** tokens = tokenize(userInput);
	  print_tokens(tokens);
	}
     }
  return 0;
}
