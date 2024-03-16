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
  for(int i = 0; i < strlen(str); i++)
    {
      if(non_space_char(str[i]))
	{
	  return &str[i];
	}
    }
  return 0;
}

char* token_terminator(char* token)
{
  while(*token)
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
}

char* copy_str(char *inStr, short len)
{
  int i = 0;
  char* outStr = malloc((len + 1) * sizeof(char)), x;
  do
      x = *(outStr + i) = *(inStr + i);
      i++;
    }
while(x);

return outStr;
}

char **tokenize(char* str)
{

}
