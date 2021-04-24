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
		if(strcmp(token,"+")==0){
			soma(s);
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
	}
//operações logicas
	print_stack(s);
}