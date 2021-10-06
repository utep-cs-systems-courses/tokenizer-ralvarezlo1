#include <stdio.h>
#include <stdlib.h>

int space_char(char c)
{
  if ((c == ' ' || c == '\t' || c == '\n') && c != '\0') {
    return 1;
  } else {
    return 0;
  }
}

int non_space_char(char c)
{
  if (c != ' ' && c != '\t' && c != '\n' && c != '\0') {
    return 1;
  } else {
    return 0;
  }
}

char *word_start(char *str)
{
  while (*str != '\0') {
    if (non_space_char(*str)) return str;
    str++;
  }
  return 0;
}

char *word_end(char *str)
{
  while (*str != '\0') {
    if(space_char(*str)) return str;
    str++;
  }
  return 0;
}

int count_words(char *str)
{
  int count = 0;
  while (*str != '\0') {
    str = word_start(str);
    if (str == 0) break;
    count++;
    str = word_end(str);
  }
  return count;
}

char *copy_str(char *inStr, short len)
{
    char *new_str = malloc(len + 1);
    
    for (int i = 0; i < len; i++) {
      new_str[i] = inStr[i];
    }
    new_str[len] = '\0'; 
    return new_str;
}

void print_str(char *copyStr)
{
    while (*copyStr != '\0') {
      printf("%c", *copyStr);
      copyStr++;
    }
    printf("\n");
}

char **tokenize(char* str)
{
  int size = count_words(str) + 1;
  char **tokens = (char**) malloc(sizeof(char*) * size);
  char *start_ptr;
  char *end_ptr;
  int len;

  start_ptr = str;
  for (int i = 0; i < size - 1; i++) {
    start_ptr = word_start(start_ptr);
    end_ptr = word_end(start_ptr);
    len = end_ptr - start_ptr;
    tokens[i] = copy_str(start_ptr, len);
    start_ptr = end_ptr;
  }
  tokens[size - 1] = 0;
  return tokens;
}

void print_tokens(char **tokens)
{
  for (int i = 0; tokens[i]; i++) {
    printf("%d) %s\n",i, tokens[i]);
  }
}

char *get_token(char **tokens, int id)
{
  int max;
  for (max = 0; tokens[max]; max++);
  if (id <= max) return tokens[id];
  else return 0;
}

void free_tokens(char **tokens)
{
  for (int i = 0; tokens[i]; i++) {
    free(tokens[i]);
  }
  free(tokens);
}

/*int main()
{
  printf("A ' ' returns: %i\n", space_char(' '));
  printf("A 'tab' returns: %i\n", space_char('\t'));
  printf("A 'new line' returns: %i\n", space_char('\n'));
  printf("A '0' returns: %i\n", space_char('\0'));
  printf("Any 'other character' returns: %i\n", space_char('a'));
  printf("\n");
    
  printf("A ' ' returns: %i\n", non_space_char(' '));
  printf("A 'tab' returns: %i\n", non_space_char('\t'));
  printf("A 'new line' returns: %i\n", non_space_char('\n'));
  printf("A '0' returns: %i\n", non_space_char('\0'));
  printf("Any 'other character' returns: %i\n", non_space_char('a'));

  char str[] = "  Hello world String!";
  char str[] = "  ";
  char *p_str = str;
  printf("The word count is: %d\n", count_words(p_str));
  printf("The index starts at: %d\n", p_str);
  p_str = word_start(p_str);
  print_str(copy_str(p_str, 5));
  printf("The index of the first word is: %d\n", p_str);
  printf("The index of the first space is: %d\n", word_end(p_str));

  print_tokens(tokenize(str));
  printf("%s\n", get_token(tokenize(str),1));
  char *token = get_token(tokenize(str),5);
  printf("%s\n", (token) ? token 
: "String not found");

  exit(EXIT_SUCCESS);
}*/
