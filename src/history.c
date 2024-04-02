#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history()
{
  List* head = (List*) malloc(sizeof(List));
  head->root = NULL;
  return head;
}

void add_history(List *list, char *str)
{
  if(list->root == NULL)
    {
      list->root = (Item*) malloc(sizeof(Item));
      list->root->id = 1;
      list->root->str = str;
      list->root->next = NULL;
      return;
    }
  Item* current = list->root;
  while(current->next != NULL)
    {
      current = current->next;
    }
  current->next = (Item*) malloc(sizeof(Item));
  current->next->id = current->id + 1;
  current->next->str = str;
  current->next->next = NULL;
}

char* get_history(List *list, int id)
{
  Item* current = list->root;
  while(current != NULL)
    {
      if(current->id == id)
	{
	  return current->str;
	}
      current = current->next;
    }
  return NULL;
}

void print_history(List *list)
{
  Item* current = list->root;
  while(current != NULL)
    {
      printf("ID: %d String: %s\n", current->id, current->str);
      current = current->next;
    }
  printf("\n");
}

void free_history(List *list)
{
  Item* temp;
  while(list->root != NULL)
    {
      temp = list->root;
      list->root = list->root->next;
      free(temp);
    }
  free(list);
}
