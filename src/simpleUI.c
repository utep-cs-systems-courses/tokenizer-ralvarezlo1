/* simpleUI.c is a c program that receives an input and echoes it*/
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

List *history;

int special_command(char *str) {
  if(str[0] != '!') return 0;
  if (str[1] =='h') {
    printf("History:\n");
    print_history(history);
    return 1;
  } else if(str[1] >= '0' && str[1] <= '9') {
    char *nodeStr = get_history(history, str[1] - '0');
    printf("The requested history is: %s\n", (nodeStr) ? nodeStr : "The requested history is not found");
    return 1;
  } else if (str[1] == 'e') return 2;
  return 0;
}


int main(void)
{
  int max = 100; /* The maximum number of characters allowed will be 100 */
  char input[max]; /* Array created to store teh input */
  int commandCode;
  history = init_history();
  
  while(1) {
    printf("\nPlease enter your input text below:\n");
    printf("> ");

    fgets(input, max, stdin);
    /* fgets is used because gets was deprecated as it was not safe because it does not check the array boundarie and reads the commplete input*/
    /* therefore, fgets asks for three parameters: the array to store the string, the maximum number to read and from where it's going to read (most commonly standard in) */

    if (*word_start(input) != '!') {
      char **tokens = tokenize(input);
      printf("The tokens are:\n");
      print_tokens(tokens);
      free_tokens(tokens);
    } else {
      printf("A special character was entered.\n");
    }
    
    commandCode = special_command(input);
    if (commandCode == 0) add_history(history, input);
    else if (commandCode == 2) break;
  }
  free_history(history);
  return 0;
}
