#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "stack.h"

//criar nova stack para ir acomulando os elementos
#define DOLLAR_SIGN(nums,_stack)\
	int i =0;\
	while(i<nums)\

#define PONTO_VIRGULA(_stack)\
	pop(_stack);

#define BARRA(_stack)\
	DATA x=pop(_stack); \
	DATA y=pop(_stack); \
	push(_stack,x); \
	push(_stack,y);

#define MENOS(_stack)\
	if(hastype(top(_stack),STRING)==0){ \
		INTEGER X = pop(_stack); \
		INTEGER Y = pop(_stack); \
		push_STRING(_stack,X-Y);\
	}\
	else if(hastype(top(_stack),INTEGER)==0){ \
		INTEGER X = pop(_stack); \
		INTEGER Y = pop(_stack); \
		push_STRING(_stack,X-Y);\
	}\
	else if(hastype(top(_stack),DOUBLE)==0){ \
		NUMBER X = pop(_stack); \
		NUMBER Y = pop(_stack); \
		push_STRING(_stack,X-Y);\
	}\
	if(hastype(top(_stack),NUMBER)==0){ \
		NUMBER X = pop(_stack); \
		NUMBER Y = pop(_stack); \
		push_STRING(_stack,X-Y);\
	}

#define MAIS(_stack)\
	if(hastype(top(_stack),STRING)==0){ \
		INTEGER X = pop(_stack); \
		INTEGER Y = pop(_stack); \
		push_STRING(_stack,X+Y);\
	}\
	else if(hastype(top(_stack),INTEGER)==0){ \
		INTEGER X = pop(_stack); \
		INTEGER Y = pop(_stack); \
		push_STRING(_stack,X+Y);\
	}\
	else if(hastype(top(_stack),DOUBLE)==0){ \
		NUMBER X = pop(_stack); \
		NUMBER Y = pop(_stack); \
		push_STRING(_stack,X+Y);\
	}\
	if(hastype(top(_stack),NUMBER)==0){ \
		NUMBER X = pop(_stack); \
		NUMBER Y = pop(_stack); \
		push_STRING(_stack,X+Y);\
	}

void parse(char *line){
	STACK *s = create_stack();
	char *delim = " \t\n";
	for(char *token = strtok(line,delim); token !=NULL ; token = strtok(NULL,delim)){
		if(strcmp(token, ";")==0){
			PONTO_VIRGULA(s);
		}
		else if(strcmp(token, "\\")==0){
			BARRA(s);
		}
		else if(strcmp(token, "-")==0){
			BARRA(s);
		}
	}
	print_stack(s);
}