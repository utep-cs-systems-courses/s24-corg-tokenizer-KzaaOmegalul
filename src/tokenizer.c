#include <stdio.h>
#include <stdlib.h>

int space_char(char c)
{
  if(c == ' ' || c == '\t' || c == '\f' || c == '\n' || c == '\r' || c == '\v')
    {
      return 1;
    }
  return 0;
}

int non_space_char(char c)
{
  return space_char(c) == 0 ? 1 : 0;
}

char* token_start(char* str)
{
  while(*str)
    {
      if(non_space_char(*str))
	{
	  return str;
	}
     str++;
    }
  return 0;
}

char* token_terminator(char* token)
{
  while(non_space_char(*token))
    {
      ++token;
    }
  return token;
}

int count_token(char *str)
{
  int counter = 0;
  int flag = non_space_char(*str);
  while(*str)
    {
      if(space_char(*str))
	{
	  flag = 1;
	}
      else if(flag)
	{
	 ++counter;
	  flag = 0;
	}
      ++str;
    }
  return counter;
}

char* copy_str(char *inStr, short len)
{
  int i = 0;
  char* outStr = malloc((len + 1) * sizeof(char)), x;
  do
    {
      x = *(outStr + i) = *(inStr + i);
      i++;
    }
  while(i < len);

  return outStr;
}

char **tokenize(char* str)
{
  int i = 0;
  int length = count_token(str);
  char** pointTokens = malloc(count_token(str) * sizeof(char*));
  while(i < length)
    {
      str = token_start(str);
      char* end = token_terminator(str);
      char* copyS = copy_str(str, end - str);
      *(pointTokens + i) = copyS;
      str = token_start(token_terminator(str));
      i++;
    }
  *(pointTokens + i) = "0";

  return pointTokens;
}

void print_tokens(char **tokens)
{
  int i = 0;
  while(tokens)
    {
      printf("Token[%d]: %s\n", i, *tokens);
      tokens++;
      i++;
    }
}

void free_tokens(char **tokens)
{
  free(tokens);
}
