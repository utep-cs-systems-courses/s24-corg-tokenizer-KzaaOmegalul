#include <stdio.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char userInput[100];
  int FLAG = 1;
  List* history = init_history();
  char** tokens;
    while(FLAG)
    {
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
	  if(tokens == NULL)
	    {
	      printf("No History Yeet!\n\n");
	      break;
	    }
	  print_history(history);
	  break;
	case 'g':
	  if(tokens == NULL)
	    {
	      printf("No History Yet!\n\n");
	      break;
	    }
	  int id;
	  printf("Enter A Valid History ID:\n");
	  scanf("%d", &id);
	  char * str = get_history(history, id);
	  if(str == NULL)
	    {
	      printf("Invalid ID!\n\n");
	      break;
	    }
	  printf("Word at ID, %d is %s:\n\n", id, str);
	  break;
	default:
	 tokens = tokenize(userInput);
	 for(int i = 0; i < count_tokens(userInput); i++)
	   {
	     add_history(history, *(tokens + i));
	   }
	 print_tokens(tokens);
	}
     }
  return 0;
}
