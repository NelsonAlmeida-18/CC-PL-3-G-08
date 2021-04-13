#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "stack.h"
#include "funcoes.h"

#define fun_getsnewline(_stack)\
	char linee[10240];\
	assert(fgets(linee,10240,stdin)!=NULL);\
	assert(linee[strlen(linee)-1]=='\n');\
	push_STRING(_stack,linee);

#define UNDERSCORE(_stack)\
	DATA x = top(_stack);\
	push(_stack,x);

#define BARRABARRA(_stack)\
	DATA x = pop(_stack);\
	push(_stack,x);\


void parse(){
	STACK *s = create_stack();
	char linee[10240];
	assert(fgets(linee,10240,stdin)!=NULL);
	assert(linee[strlen(linee)-1]=='\n');
	push_STRING(s,linee);
	char *delim = " \t\n";
	for(char *token = strtok(linee,delim); token !=NULL ; token = strtok(NULL,delim)){		
		if(strcmp(token, "l")==0){
			fun_getsnewline(s);
		}
		else if(strcmp(token, "i")==0){
			converteInt(s);
		}
		else if(strcmp(token, "+")==0){
			soma(s);
		}
		else if(strcmp(token, "_")==0){
			UNDERSCORE(s);
		}
		else if(strcmp(token, "\\")==0){
			BARRABARRA(s);
		}
	}
//	print_stack(s);
/*
		else if(strcmp(token, "i")==0){
			convert_to_int(s);
		}
	    else if(strcmp(token, ";")==0){
			PONTO_VIRGULA(s);
		}
		else if(strcmp(token, "\\")==0){
			BARRA(s);
		}
		else if(strcmp(token, "_")==0){
			UNDERSCORE(s);
		}
//para já hardcoded mas facil correção com um pop antes para determinar o numero de elementos que teão de ser viajados
		else if(strcmp(token, "$")==0){
			DOLLAR_SIGN(2,s);
		}
		else if(strcmp(token, "-")==0){
			MENOS(s);
		}
		else if(strcmp(token, "i")==0){
			i(s);
		}
	}
*/
}