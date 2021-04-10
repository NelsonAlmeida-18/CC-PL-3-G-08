#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "stack.h"

//criar nova stack para ir acomulando os elementos
#define DOLLAR_SIGN(nums,_stack)\
	STACK *c = create_stack();\
	int i =0;\
	while(i<nums){\
		DATA X=pop(_stack);\
		push(c,X);\
		i+=1;\
	}\
	DATA MY_VAR=pop(_stack);\
	push(_stack,MY_VAR);\
	while(i>0){\
		DATA x = pop(c);\
		push(_stack,x);\
	}\
	push(_stack,MY_VAR); \
//remove ultimo item
#define PONTO_VIRGULA(_stack)\
	pop(_stack);
//troca ordem dos dois ultimos
#define BARRA(_stack)\
	DATA x=pop(_stack); \
	DATA y=pop(_stack); \
	push(_stack,x); \
	push(_stack,y);
//subtrai
#define MENOS(_stack)\
	if(has_type(top(_stack),STRING)==0){ \
		INTEGER X = pop(_stack); \
		INTEGER Y = pop(_stack); \
		push_STRING(_stack,X-Y);\
	}\
	else if(has_type(top(_stack),INTEGER)==0){ \
		INTEGER X = pop(_stack); \
		INTEGER Y = pop(_stack); \
		push_STRING(_stack,X-Y);\
	}\
	else if(has_type(top(_stack),DOUBLE)==0){ \
		NUMBER X = pop(_stack); \
		NUMBER Y = pop(_stack); \
		push_STRING(_stack,X-Y);\
	}\
	if(has_type(top(_stack),NUMBER)==0){ \
		NUMBER X = pop(_stack); \
		NUMBER Y = pop(_stack); \
		push_STRING(_stack,X-Y);\
	}
//soma
#define MAIS(_stack)\
	if(has_type(top(_stack),STRING)==0){ \
		INTEGER X = pop(_stack); \
		INTEGER Y = pop(_stack); \
		push_STRING(_stack,X+Y);\
	}\
	else if(has_type(top(_stack),INTEGER)==0){ \
		INTEGER X = pop(_stack); \
		INTEGER Y = pop(_stack); \
		push_STRING(_stack,X+Y);\
	}\
	else if(has_type(top(_stack),DOUBLE)==0){ \
		NUMBER X = pop(_stack); \
		NUMBER Y = pop(_stack); \
		push_STRING(_stack,X+Y);\
	}\
	if(has_type(top(_stack),NUMBER)==0){ \
		NUMBER X = pop(_stack); \
		NUMBER Y = pop(_stack); \
		push_STRING(_stack,X+Y);\
	}
//duplica o ultimo item
#define UNDERSCORE(_stack)\
	DATA x = pop(_stack);\
	push(_stack,x);\
	push(_stack,x);\

#define i(_stack)\
	DATA x = pop(_stack);\
	int test = (int)x;\
	push_LONG(_stack,test);

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
	print_stack(s);
}