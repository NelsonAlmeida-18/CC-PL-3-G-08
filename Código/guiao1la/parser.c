/**
  *@File função que diz respeito ao parser 
*/
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include <math.h>
#define PUSH(x)		push(s,x)
#define POP()		pop(s)
/**
  *\brief Esta é a função que vai fazer parse de uma linha
  *@param line A linha que foi lida e da qual se vai fazer o parse
  *@returns Nada
*/
void parse(char *line){
	STACK s = criar_stack();
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
		else if(strcmp(token, "#")==0){
			long Y = POP();
			long X=POP();
			PUSH(pow(X,Y));
		}
		else if(strcmp(token, "%")==0){
			long Y = POP();
			long X=POP();
			PUSH(X%Y);
		}
		else if(strcmp(token, "&")==0){
			long Y = POP();
			long X=POP();
			PUSH(X&Y);
		}
		else if(strcmp(token, "|")==0){
			long Y = POP();
			long X=POP();
			PUSH(X|Y);
		}
		else if(strcmp(token, "^")==0){
			long Y = POP();
			long X=POP();
			PUSH(X^Y);
		}
		else if(strcmp(token, "~")==0){
			long X=POP();
			PUSH(~X);
		}
		else if(strcmp(token, ")")==0){
			long X=POP();
			PUSH(X+1);
		}
		else if(strcmp(token, "(")==0){
			long X=POP();
			PUSH(X-1);
		}
	}
	print_stack(s);
}