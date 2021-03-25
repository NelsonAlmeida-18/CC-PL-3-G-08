#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void parse(char *line){
	char *delim = " \t\n";
	for(char *token = strtok(line,delim); token !=NULL ; token = strtok(NULL,delim)){
		char *sobra;
		long val_i = strtol(token,&sobra,10);
		if (strlen(sobra)==0){
			PUSH(val_i);
		}
		else if(strcmp(token, "+")==0){
			long Y = POP();
			long X=POP();
			PUSH(X+Y);
		}
		else if(strcmp(token, "-")==0){
			long Y = POP();
			long X=POP();
			PUSH(X-Y);
		}
		else if(strcmp(token, "*")==0){
			long Y = POP();
			long X=POP();
			PUSH(X*Y);
		}
		else if(strcmp(token, "/")==0){
			long Y = POP();
			long X=POP();
			PUSH(X/Y);
		}
	}
	print_stack();
}