#include <stdio.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  int FLAG = 1;
  List* history = init_history();
  char** tokens;
  int id;
    while(FLAG)
    {
      char userInput[1000];
      printf("Enter q: Quit Program\nEnter h: Print History\nEnter g: Get History @ Specified ID\n\n");
      printf("Write a Sentence or Enter Valid Character\n");
      printf(">");
      scanf(" %[^\n]", &userInput);
      switch(*userInput)
	{
	case 'q':
	  FLAG = 0;
	  break;
	case 'h':
	  print_history(history);
	  break;
	case 'g':
	  printf("Enter A Valid History ID:\n");
	  scanf("%d", &id);
	  printf("Word at ID, %d is %s:\n", id, get_history(history, id));
	  break;
	default:
	 tokens = tokenize(userInput);
	 print_tokens(tokens);
	}
     }
  return 0;
}
