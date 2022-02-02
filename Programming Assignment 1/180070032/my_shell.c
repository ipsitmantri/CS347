#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

/* Splits the string by space and returns the array of tokens
*
*/
char **tokenize(char *line)
{
  char **tokens = (char **)malloc(MAX_NUM_TOKENS * sizeof(char *));
  char *token = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
  int i, tokenIndex = 0, tokenNo = 0;

  for(i =0; i < strlen(line); i++){

    char readChar = line[i];

    if (readChar == ' ' || readChar == '\n' || readChar == '\t'){
      token[tokenIndex] = '\0';
      if (tokenIndex != 0){
	tokens[tokenNo] = (char*)malloc(MAX_TOKEN_SIZE*sizeof(char));
	strcpy(tokens[tokenNo++], token);
	tokenIndex = 0; 
      }
    } else {
      token[tokenIndex++] = readChar;
    }
  }
 
  free(token);
  tokens[tokenNo] = NULL ;
  return tokens;
}


int main(int argc, char* argv[]) {
	char  line[MAX_INPUT_SIZE];            
	char  **tokens;              
	int i;
	char exit_command[] = "exit";

	while(1) {			
		/* BEGIN: TAKING INPUT */
		bzero(line, sizeof(line));
		printf("$ ");
		scanf("%[^\n]", line);
		getchar();
		
		// checking of the command provided is empty and returning $ accordingly
		if (strcmp(line, "") == 0)
		{
			continue;
		}
		// checking if the command provided is `exit` and exiting the shell accordingly
		if (strcmp(line, "exit") == 0)
		{
			exit(1);
		}
		/* END: TAKING INPUT */

		line[strlen(line)] = '\n'; //terminate with new line
		tokens = tokenize(line);

   
       // creating child process

		int ret = fork();
		if (ret == 0)
		{
			execvp(tokens[0], tokens);
			printf("exec failed: invalid command %s", line); // throwing error for invalid commands.
			exit(0); // exit manually
		}
		else
		{
			wait(NULL); // reaping the child processes
			// Freeing the allocated memory	
			for(i=0;tokens[i]!=NULL;i++){
				free(tokens[i]);
			}
			free(tokens);
		}

	}
	return 0;
}
