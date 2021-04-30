/**
  *@file Ficheiro que dá parse aos comandos.
  *\brief Neste ficheiro está presente uma função e uma macro.s
  *@date April 2021
  *@returns Retorna a impressão stack
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "stack.h"
#include "funcoes.h"
#include "funmath.h"

/**
 *\brief Esta macro tem a função de ler uma nova linha de input ao comando l, esta nova linha é inserida na STACK. 
*/
#define fun_getsnewline(_stack)\
	char linee[10240];\
	assert(fgets(linee,10240,stdin)!=NULL);\
	assert(linee[strlen(linee)-1]=='\n');\
	push_STRING(_stack,linee);
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
/**
  *\brief Função parse.
  *@param Nao recebe parâmetros.
  *@returns Esta função não tem retorno.
  */
void parse(){
/**A função parse divide as linhas de input em diversas partes mais pequenas a certos demarcadores. Tais como: espaço, tabs e enters.
*/
	STACK *s = create_stack();
//popula o array na stack com os valores por omissão
	popula_init_array(s);
//	STACK *letras = create_stack();
	char linee[10240];
	assert(fgets(linee,10240,stdin)!=NULL);
	assert(linee[strlen(linee)-1]=='\n');
	char *delim = " \t\n";
//	int array_letras[26];
	for(char *token = strtok(linee,delim); token !=NULL ; token = strtok(NULL,delim)){		
		char *sobra1;
		char *sobra2;

		long val_l=strtol(token,&sobra1,10);
		double val_d=strtod(token, &sobra2);

		if(strlen(sobra1)==0){
			push_LONG(s, val_l);
		}
		else if(strlen(sobra2)==0){
			push_DOUBLE(s,val_d);
		}
/**\brief Esta linha de código é inicializada aquando da leitura do "trigger" l, e busca a macro anteriormente citada visando o input de uma nova linha de comandos
   para ser interpretada.
*/

//settar A para 0 de forma a que o array comece no primeiro elemento;
/*
		else if(letras(token)==0){
			int pos = converteInt(token);
			push_LONG(s,array_letras[pos]);
		}
*/
		else if(strcmp(token,"l")==0){
			fun_getsnewline(s);
		}
		else if(strcmp(token, "i")==0){
			converteInt(s);
		}
/**Esta linha de código é inicializada aquando da leitura do "trigger" f, e busca a função localizada no ficheiro funcoes que transforma em elementos do tipo double o topo da stack.
*/
		else if(strcmp(token, "f")==0){
			converteDOUBLE(s);
		}
/**Esta linha de código é inicializada aquando da leitura do "trigger" c, e busca a função localizada no ficheiro funcoes que transforma em elementos do tipo char o topo da stack.
*/
		else if(strcmp(token, "c")==0){
			converteCHAR(s);
		}
//operações 
/**Esta linha de código é inicializada aquando da leitura do "trigger" +, e busca a função localizada no ficheiro funcoes que realiza a operação aritmética da soma entre diversos tipos de valores.
*/
		else if(strcmp(token, "(")==0){
			decrementa(s);
		}
		else if(strcmp(token, ")")==0){
			incrementa(s);
		}
		else if(strcmp(token, "+")==0){
			soma(s);
		}
		else if(strcmp(token, "-")==0){
			subtracao(s);
		}
		else if(strcmp(token, "*")==0){
			mult(s);
		}
		else if(strcmp(token, "%")==0){
			resto(s);
		}
		else if(strcmp(token, "/")==0){
			divisao(s);
		}
		else if(strcmp(token, "#")==0){
			expon(s);
		}
//manipulação da stack
/**Esta linha de código é inicializada aquando da leitura do "trigger" _, que duplica o elemento presente no topo da stack.
*/
		else if(strcmp(token, "_")==0){
			underscore(s);
		}
/**Esta linha de código é inicializada aquando da leitura do "trigger" \, que troca os dois elementos no topo da stack.
*/
		else if(strcmp(token, "\\")==0){
			barrabarra(s);
		}
/**Esta linha de código é inicializada aquando da leitura do "trigger" @, que roda os 3 elementos presentes no topo da stack.
*/

		else if(strcmp(token, "@")==0){
			arroba(s);
		}
/**Esta linha de código é inicializada aquando da leitura do "trigger" ;, que elimina(dá pop) ao elemento no topo da stack.
*/

		else if(strcmp(token, ";")==0){
			ponto_virgula(s);
		}
/**Esta linha de código é inicializada aquando da leitura do "trigger" $, que copia o n-ésimo elemento para o topo da stack.
*/
		else if(strcmp(token, "$")==0){
			dollarsign(s);
		}
		else if(strcmp(token, "&")==0){
			AMPERSAND(s);
		}
		else if(strcmp(token, "|")==0){
			OR(s);
		}
		else if(strcmp(token, "^")==0){
			XOR(s);
		}
		else if(strcmp(token,"=")==0){
			igual(s);
		}
		else if(strcmp(token,"<")==0){
			menor(s);
		}
		else if(strcmp(token,">")==0){
			maior(s);
		}
		else if(strcmp(token,"!")==0){
			nao(s);
		}
//e com shortcut
//ou com shortcut
		else if(strcmp(token,"e&")==0){
			e_com_shortcut(s);
		}
		else if(strcmp(token,"e|")==0){
			ou_com_shortcut(s);
		}
		//menor dos dois
		else if(strcmp(token,"e<")==0){
			e_menor(s);
		}
		else if(strcmp(token,"e>")==0){
			e_maior(s);
		}
		else if(strcmp(token,"?")==0){
			if_then_else(s);
		}
		else if(strcmp(token, "A")==0){
			Letras(s,'A');
		}
		else if(strcmp(token, ":A")==0){
			doisPontosLetras(s,'A');
		}
		else if(strcmp(token, ":B")==0){
			doisPontosLetras(s,'B');
		}
		else if(strcmp(token, "B")==0){
			Letras(s,'B');
		}
		else if(strcmp(token, ":C")==0){
			doisPontosLetras(s,'C');
		}
		else if(strcmp(token, "C")==0){
			Letras(s,'C');
		}
		else if(strcmp(token, ":D")==0){
			doisPontosLetras(s,'D');
		}
		else if(strcmp(token, "D")==0){
			Letras(s,'D');
		}
		else if(strcmp(token, ":E")==0){
			doisPontosLetras(s,'E');
		}
		else if(strcmp(token, "E")==0){
			Letras(s,'E');
		}
		else if(strcmp(token, ":F")==0){
			doisPontosLetras(s,'F');
		}
		else if(strcmp(token, "F")==0){
			Letras(s,'F');
		}
		else if(strcmp(token, ":G")==0){
			doisPontosLetras(s,'G');
		}
		else if(strcmp(token, "G")==0){
			Letras(s,'G');
		}
		else if(strcmp(token, ":H")==0){
			doisPontosLetras(s,'H');
		}
		else if(strcmp(token, "H")==0){
			Letras(s,'H');
		}
		else if(strcmp(token, ":I")==0){
			doisPontosLetras(s,'I');
		}
		else if(strcmp(token, "I")==0){
			Letras(s,'I');
		}
		else if(strcmp(token, ":J")==0){
			doisPontosLetras(s,'J');
		}
		else if(strcmp(token, "J")==0){
			Letras(s,'J');
		}
		else if(strcmp(token, ":K")==0){
			doisPontosLetras(s,'K');
		}
		else if(strcmp(token, "K")==0){
			Letras(s,'K');
		}
		else if(strcmp(token, ":L")==0){
			doisPontosLetras(s,'L');
		}
		else if(strcmp(token, "L")==0){
			Letras(s,'L');
		}
		else if(strcmp(token, ":M")==0){
			doisPontosLetras(s,'M');
		}
		else if(strcmp(token, "M")==0){
			Letras(s,'M');
		}
		else if(strcmp(token, ":N")==0){
			doisPontosLetras(s,'N');
		}
		else if(strcmp(token, "N")==0){
			Letras(s,'N');
		}
		else if(strcmp(token, ":O")==0){
			doisPontosLetras(s,'O');
		}
		else if(strcmp(token, "O")==0){
			Letras(s,'O');
		}
		else if(strcmp(token, ":P")==0){
			doisPontosLetras(s,'P');
		}
		else if(strcmp(token, "P")==0){
			Letras(s,'P');
		}
		else if(strcmp(token, ":Q")==0){
			doisPontosLetras(s,'Q');
		}
		else if(strcmp(token, "Q")==0){
			Letras(s,'Q');
		}
		else if(strcmp(token, ":R")==0){
			doisPontosLetras(s,'R');
		}
		else if(strcmp(token, "R")==0){
			Letras(s,'R');
		}
		else if(strcmp(token, ":S")==0){
			doisPontosLetras(s,'S');
		}
		else if(strcmp(token, "S")==0){
			Letras(s,'S');
		}
		else if(strcmp(token, ":T")==0){
			doisPontosLetras(s,'T');
		}
		else if(strcmp(token, "T")==0){
			Letras(s,'T');
		}
		else if(strcmp(token, ":U")==0){
			doisPontosLetras(s,'U');
		}
		else if(strcmp(token, "U")==0){
			Letras(s,'U');
		}
		else if(strcmp(token, ":V")==0){
			doisPontosLetras(s,'V');
		}
		else if(strcmp(token, "V")==0){
			Letras(s,'V');
		}
		else if(strcmp(token, ":W")==0){
			doisPontosLetras(s,'W');
		}
		else if(strcmp(token, "W")==0){
			Letras(s,'W');
		}
		else if(strcmp(token, ":X")==0){
			doisPontosLetras(s,'X');
		}
		else if(strcmp(token, "X")==0){
			Letras(s,'X');
		}
		else if(strcmp(token, ":Y")==0){
			doisPontosLetras(s,'Y');
		}
		else if(strcmp(token, "Y")==0){
			Letras(s,'Y');
		}
		else if(strcmp(token, ":Z")==0){
			doisPontosLetras(s,'Z');
		}
		else if(strcmp(token, "Z")==0){
			Letras(s,'Z');
		}
	}
	print_stack(s);
}