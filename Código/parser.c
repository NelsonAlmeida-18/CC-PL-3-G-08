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
#include "fun_vars.h"

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
		else{
/**\brief Foram utilizados switch cases de modo a diminuir a Complexidade Ciclomática.
*/
			switch(*token){
/**\brief Esta linha de código é inicializada aquando da leitura do "trigger" l, e busca a funçao que leva ao input de uma nova linha de código para ser incrementada.
*/
				case('l'):
					fun_getsnewline(s);
					break;
				case('i'):
					converteInt(s);
					break;
/**Esta linha de código é inicializada aquando da leitura do "trigger" f, e busca a função localizada no ficheiro funcoes que transforma em elementos do tipo double o topo da stack.
*/
				case('f'):
					converteDOUBLE(s);
					break;
/**Esta linha de código é inicializada aquando da leitura do "trigger" c, e busca a função localizada no ficheiro funcoes que transforma em elementos do tipo char o topo da stack.
*/
				case ('c'):
					converteCHAR(s);
					break;
//operações 
/**Esta linha de código é inicializada aquando da leitura do "trigger" +, e busca a função localizada no ficheiro funcoes que realiza a operação aritmética da soma entre diversos tipos de valores.
*/
//mesmo bug do abaixo, temos de acrescentar um mas esperar pela resposta do Félix
				case ('e'):
					switch(token[1]){
						case('<'):
							e_menor(s);
							break;
						case('>'):
							e_maior(s);
							break;
						case('&'):
							e_com_shortcut(s);
							break;
						case('|'):
							ou_com_shortcut(s);
							break;
						default:
							break;
					}
				case (':'):
//rever mafarriquice com o char seguinte
					switch(token[1]){
						case('A'):
							doisPontosLetras(s,'B');
							break;
						case('B'):
							doisPontosLetras(s,'C');
							break;
						default:
							break;
					}
				case('('):
					decrementa(s);
					break;
				case(')'):
					incrementa(s);
					break;
				case('+'):
					soma(s);
					break;
				case('-'):
					subtracao(s);
					break;
				case('*'):
					mult(s);
					break;
				case('%'):
					resto(s);
					break;
				case('/'):
					divisao(s);
					break;
				case('#'):
					expon(s);
					break;
//manipulação de stack
/**Esta linha de código é inicializada aquando da leitura do "trigger" _, que duplica o elemento presente no topo da stack.
*/
				case('_'):
					underscore(s);
					break;
/**Esta linha de código é inicializada aquando da leitura do "trigger" \, que troca os dois elementos no topo da stack.
*/
				case('\\'):
					barrabarra(s);
					break;
/**Esta linha de código é inicializada aquando da leitura do "trigger" @, que roda os 3 elementos presentes no topo da stack.
*/					
				case('@'):
					arroba(s);
					break;
/**Esta linha de código é inicializada aquando da leitura do "trigger" ;, que elimina(dá pop) ao elemento no topo da stack.
*/					
				case(';'):
					ponto_virgula(s);
					break;
/**Esta linha de código é inicializada aquando da leitura do "trigger" $, que copia o n-ésimo elemento para o topo da stack.
*/
				case('$'):
					dollarsign(s);
					break;
				case('&'):
					AMPERSAND(s);
					break;
				case('|'):
					OR(s);
					break;
				case('^'):
					XOR(s);
					break;
				case('='):
					igual(s);
					break;
				case('>'):
					maior(s);
					break;
				case('<'):
					menor(s);
					break;
				case('!'):
					nao(s);
					break;
				case('?'):
					if_then_else(s);
					break;
				case('A'):
					Letras(s,'A');
					break;
				case('B'):
					Letras(s,'B');
					break;
				case('C'):
					Letras(s,'C');
					break;
				case('D'):
					Letras(s,'D');
					break;
				case('E'):
					Letras(s,'E');
					break;
				case('F'):
					Letras(s,'F');
					break;
				case('G'):
					Letras(s,'G');
					break;
				case('H'):
					Letras(s,'H');
					break;
				case('I'):
					Letras(s,'I');
					break;
				case('J'):
					Letras(s,'J');
					break;
				case('K'):
					Letras(s,'K');
					break;
				case('L'):
					Letras(s,'L');
					break;
				case('M'):
					Letras(s,'M');
					break;
				case('N'):
					Letras(s,'N');
					break;
				case('O'):
					Letras(s,'O');
					break;
				case('P'):
					Letras(s,'P');
					break;
				case('Q'):
					Letras(s,'Q');
					break;
				case('R'):
					Letras(s,'R');
					break;
				case('S'):
					Letras(s,'S');
					break;
				case('T'):
					Letras(s,'T');
					break;
				case('U'):
					Letras(s,'U');
					break;
				case('V'):
					Letras(s,'V');
					break;
				case('W'):
					Letras(s,'W');
					break;
				case('X'):
					Letras(s,'X');
					break;
				case('Y'):
					Letras(s,'Y');
					break;
				case('Z'):
					Letras(s,'Z');
					break;		
			}
		}	
	}
	print_stack(s);
}