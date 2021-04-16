/**
  *@file Ficheiro que dá parse aos comandos.
  *\brief Neste ficheiro está presente uma função e uma macro.
  @author Nelson Almeida
  @date April 2021
  *@returns Retorna um int atendendo ao formato da função
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "stack.h"
#include "funcoes.h"

/**Esta macro tem a função de ler uma nova linha de input ao comando l, esta nova linha é inserida na STACK.
*/
#define fun_getsnewline(_stack)\
	char linee[10240];\
	assert(fgets(linee,10240,stdin)!=NULL);\
	assert(linee[strlen(linee)-1]=='\n');\
	push_STRING(_stack,linee);

void parse(){
/**A função parse divide as linhas de input em diversas partes mais pequenas a certos demarcadores. Tais como: espaço, tabs e enters.
*/
	STACK *s = create_stack();
	char linee[10240];
	assert(fgets(linee,10240,stdin)!=NULL);
	assert(linee[strlen(linee)-1]=='\n');
	char *delim = " \t\n";
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
		if(strcmp(token, "l")==0){
			fun_getsnewline(s);
		}
//conversoes
/**Esta linha de código é inicializada aquando da leitura do "trigger" i, e busca a função localizada no ficheiro funcoes que transforma em elementos do tipo long o topo da stack.
*/
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
//			resto(s);
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
	}
//operações logicas
	print_stack(s);
}