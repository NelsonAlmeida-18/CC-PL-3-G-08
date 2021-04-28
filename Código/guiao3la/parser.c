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
  *\brief A funcao parse divide as linhas de input em diversas partes mais pequenas a certos demarcadores. Tais como: espaço, tabs e enters.
  *@param Esta função nao tem parametros.
  *@returns Esta função não tem retorno
  */


void popula_init_array(STACK *s){
	s->array[0].LONG=10;	//A
	s->array[1].LONG=11;	//B
	s->array[2].LONG=12;	//C
	s->array[3].LONG=13;	//D
	s->array[4].LONG=14;	//E
	s->array[5].LONG=15;	//F
	s->array[13].CHAR='\n';	//N
	s->array[18].CHAR = ' '; //S
	s->array[23].LONG=0;//X
	s->array[24].LONG=1;//Y
	s->array[25].LONG=2;//Z	
}


//magicamente também não avalia os tipos de dados
void editorLetrinhas(STACK *s, char letrinha){
	DATA x = pop(s);
	long pos = letrinha;
	if (has_type(x,LONG)){
		s->array[pos-65].LONG=x.LONG;
		printf("has type: L");
	}
	else if (has_type(x,DOUBLE)){
		s->array[pos-65].DOUBLE=x.DOUBLE;
		printf("has type: D");
	}
	else if (has_type(x,CHAR)){
		s->array[pos-65].CHAR=x.CHAR;
		printf("has type: C");
	}
	else if(has_type(x,STRING)){
		s->array[pos-65].STRING = x.STRING;
		printf("has type: S");
	}
}

//porque não consegue avaliar tipos?
void letrinhas(STACK *s, char letrinha){
	long x = letrinha;
	DATA y = (s->array[x-65]);
	push_LONG(s,y.LONG);
}

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

		//menor dos dois
		else if(strcmp(token,"e<")==0){
			menor_dos_dois(s);
		}
		else if(strcmp(token,"e>")==0){
			maior_dos_dois(s);
		}
		else if(strcmp(token,"?")==0){
			if_then_else(s);
		}
		else if(strcmp(token, "A")==0){
			letrinhas(s,'A');
		}
		else if(strcmp(token, ":A")==0){
			editorLetrinhas(s,'A');
		}
	}
	print_stack(s);
}