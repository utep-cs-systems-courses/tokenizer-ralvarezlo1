#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/* Initialize the linked list to keep the history. */
List* init_history()
{
  List *list = (List*) malloc(sizeof(List));
  list->root = NULL;
  return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  Item *node = (Item*) malloc(sizeof(Item));
  node->next = NULL;
  
  int len;
  for (len = 0; str[len] && str[len] != '\n'; len++);
  node->str = copy_str(str, len);

  if (list->root == NULL) {
    node->id = 0;
    list->root = node;
    return;
  } else {
    Item *iter = list->root;
    node->id = 1;
    while(iter->next != NULL) {
      iter = iter->next;
      node->id++;
    }
    iter->next = node;
  }
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id) {
  Item *iter = list->root;
  while(iter != NULL) {
    if(iter->id == id) return iter->str;
    iter = iter->next;
  }
  return 0;
}

/*Print the entire contents of the list. */
void print_history(List *list) {
  Item *iter = list->root;
  while (iter != NULL) {
    printf("%d) %s\n", iter->id, iter->str);
    iter = iter->next;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list) {
  Item *iter = list->root;
  Item *nextIter;

  while(iter != NULL) {
    nextIter = iter->next;
    free(iter->str);
    free(iter);
    iter = nextIter;
  }
  free(list);
}
