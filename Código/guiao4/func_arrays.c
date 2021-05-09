#include <stdio.h>
#include <string.h>
#include "stack.h"

/*
int t(STACK *s){
	char line_to_push[10240];
	assert(fgets(line_to_push,10240,stdin)!=NULL);
	while(line_to_push[0]!='\n'){
		int pos_new_str = strlen(line_to_push);	
		line_to_push = {};
		assert(fgets(line_to_push,10240,stdin)!=NULL);
	}
	push_STRING(s,line_to_push);
}
*/
/**
  *\brief Função que separa a string por espaços.
  *@param Recebe a STACK como argumento.
  *@returns Esta função não tem retorno.
  */
void s_slash(STACK *s){
	DATA elem = pop(s);
	char strtoallocate[10240];
	char delim = ' ';
	if (has_type(elem,STRING)){
		char *str = elem.STRING;
		int pos = 0, pos2 =0;
		while(str[pos]){
			if(str[pos]!=delim){
				strtoallocate[pos2] = str[pos];
			}
			else{
				push_STRING(s,strtoallocate);
				pos2=0;
			}
			pos+=1;
		}
	}
	push_STRING(s,strtoallocate);
}
/**
  *\brief Função Range(Tamanho).
  *@param Recebe a STACK como argumento.
  *@returns Esta função não tem retorno.
  */
void virgula(STACK *s){
	DATA elems = pop(s);
	if(has_type(elems,LONG)){
		long top = elems.LONG;
		int bottom = 0;
		while(bottom<top){
			push_LONG(s,bottom);
			bottom+=1;
		}
	}
	else if(has_type(elems,STRING)){
		char * newstr = elems.STRING;
		push_LONG(s,strlen(newstr));
	}
}

/*
void tilde(STACK *s){
	DATA y = pop(s);

}
*/