#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "stack.h"
#include "funcoes.h"
#include "funmath.h"

/**
  *\brief Converte o topo da stack para LONG.
  *@param x-Recebe um elemento.
  *@returns Retorna o elemento já convertido.
  */
DATA makeLong(long x){
	DATA y;
	y.LONG = x;
	y.type = LONG;
	return y;
}
/**
  *\brief Converte o topo da stack para DOUBLE.
  *@param x-Recebe um elemento.
  *@returns Retorna o elemento já convertido.
  */
DATA makeDouble(double x){
	DATA y;
	y.DOUBLE = x;
	y.type = DOUBLE;
	return y;
}
/**
  *\brief Converte o topo da stack para CHAR.
  *@param x-Recebe um elemento.
  *@returns Retorna o elemento já convertido.
  */
DATA makeCHAR(char x){
	DATA y;
	y.CHAR = x;
	y.type = CHAR;
	return y;
}
/**
  *\brief Atribuição de valores por omissão às variaveis.
  *@param Recebe a STACK como argumento.
  *@returns Esta função não tem retorno.
  */
void popula_init_array(STACK *s){
	s->array[0]=makeLong(10);	//A
	s->array[1]=makeLong(11);	//B
	s->array[2]=makeLong(12);	//C
	s->array[3]=makeLong(13);	//D
	s->array[4]=makeLong(14);	//E
	s->array[5]=makeLong(15);	//F
	s->array[13]=makeCHAR('\n');	//N
	s->array[18]=makeCHAR(' '); //S
	s->array[23]=makeLong(0);//X
	s->array[24]=makeLong(1);//Y
	s->array[25]=makeLong(2);//Z	
}

/**
  *\brief Atribuição de novos valores às letras
  *@param Recebe a STACK como argumento e um caracter.
  *@returns Esta função não tem retorno.
  */
void doisPontosLetras(STACK *s, char letrinha){
	DATA x = top(s);
	long pos = letrinha;
	if (has_type(x,LONG)){
		s->array[pos-65]=makeLong(x.LONG);
	}
	else if (has_type(x,DOUBLE)){
		s->array[pos-65]=makeDouble(x.DOUBLE);
	}
	else if (has_type(x,CHAR)){
		s->array[pos-65]=makeCHAR(x.CHAR);
	}
}
/**
  *\brief Função que coloca no topo da STACK o conteúdo da variável que é passado como parametro.
  *@param Recebe a STACK como argumento e um caracter.
  *@returns Esta função não tem retorno.
  */
void Letras(STACK *s, char letrinha){
	long x = letrinha;
	DATA y = (s->array[x-65]);
	if (has_type(y,LONG)){
		push_LONG(s,y.LONG);
	}
	else if (has_type(y,DOUBLE)){
		push_DOUBLE(s,y.DOUBLE);
	}
	else if (has_type(y,CHAR)){
		push_CHAR(s,y.CHAR);
	}
	else if (has_type(y,STRING)){
		push_STRING(s,y.STRING);
	}
}