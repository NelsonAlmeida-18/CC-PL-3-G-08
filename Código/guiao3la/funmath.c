/**
  *@file Ficheiro que contém as funções a utilizar no main .
  *\brief Neste ficheiro está presente todas as funções das expressões aritméticas.
  *@date April 2021
  */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include <math.h>
/**
  *\brief 
  *@param Esta função tem como parâmetros o apontador da stack
  *@returns Esta função não tem retorno
  */
void fun_getsnewline(STACK *s){
  char linee[10240];
  assert(fgets(linee,10240,stdin)!=NULL);
  assert(linee[strlen(linee)-1]=='\n');
  push_STRING(s,linee);
}
//stack
/**
  *\brief O caracter barra invoca esta função que troca os dois elementos do topo da stack
  *@param Esta função tem como parâmetros o apontador da stack
  *@returns Esta função não tem retorno
  */
void barrabarra(STACK *s){
	DATA x = pop(s);
	DATA y = pop(s);
	push(s,x);
	push(s,y);
}
/**
  *\brief O caracter "Underscore" invoca esta função que duplica o elemento do topo da stack
  *@param Esta função tem como parâmetros o apontador da stack
  *@returns Esta função não tem retorno
  */
void underscore(STACK *s){
	DATA x = top(s);
	push(s,x);
}
/**
  *\brief O caracter "Ponto e virgula" invoca esta função que retira o elemento do topo da stack
  *@param Esta função tem como parâmetros o apontador da stack
  *@returns Esta função não tem retorno
*/
void ponto_virgula(STACK *s){
	pop(s);
}
/**
  *\brief O caracter "Cifrãos" invoca esta função que copia o n-ésimo elemento da stack e o coloca no topo da mesma.
  *@param Esta função tem como parâmetros o apontador da stack
  *@returns Esta função não tem retorno
  */
void dollarsign (STACK *s){
	STACK *c = create_stack();
	DATA x = pop(s);
	long y = x.LONG;
	int i =0;
	while(i<y){
		DATA p = pop(s);
		push(c,p);
		i+=1;
	}
	DATA k = top(s);
	int j =0;
	while(j<i){
		DATA p = pop(c);
		push(s,p);
		j+=1;
	}
	push(s,k);
}
/**
  *\brief O caracter "Arroba" invoca esta função que troca a posicao dos 3 elementos no topo da stack.
  *@param Esta função tem como parâmetros o apontador da stack
  *@returns Esta função não tem retorno
  */
void arroba(STACK *s){
	DATA x = pop(s);
	DATA y = pop(s);
	DATA z = pop(s);
	push(s,y);
	push(s,x);
	push(s,z);
}

/**
  *\brief A funcao "converteInt" converte um DATA em Int.
  *@param Esta função tem como parâmetros o apontador da stack
  *@returns Esta função não tem retorno
  */
//conversoes
void converteInt(STACK *s) {             
   DATA x = pop(s);                              
   if(has_type(x,DOUBLE)) {                  
     push_LONG(s,x.DOUBLE);  
   } else if(has_type(x,CHAR)) {              
      push_LONG(s,x.CHAR); 
   } else if(has_type(x,STRING)) { 
      long y = atol(x.STRING);      
      push_LONG(s,y); 
   } else 
     push(s,x);    
}

/**
  *\brief A funcao "converteDOUBLE" converte um valor do tipo DATA num Double.
  *@param Esta função tem como parâmetros o apontador da stack
  *@returns Esta função não tem retorno
  */
void converteDOUBLE(STACK *s) {             
   DATA x = pop(s);                              
   if(has_type(x,LONG)) {                
      push_DOUBLE(s,x.LONG);  
   } else if(has_type(x,CHAR)) {               
      push_DOUBLE(s,x.CHAR); 
   } else if(has_type(x,STRING)) {
      double y = atof(x.STRING);      
      push_DOUBLE(s,y);
   } else if (has_type(x,DOUBLE)){
      push_DOUBLE(s,x.DOUBLE);    
   }
} 
/**
  *\brief A funcao "converteCHAR" converte um valor do tipo DATA num Char.
  *@param Esta função tem como parâmetros o apontador da stack
  *@returns Esta função não tem retorno
  */
void converteCHAR(STACK *s){
	DATA X = pop(s);
	if(has_type(X,CHAR)){
		push(s,X);
	}
	else if(has_type(X,DOUBLE)){
		push_CHAR(s,X.DOUBLE);
	}
	else if(has_type(X,LONG)){
		push_CHAR(s,X.LONG);
	}
}

//operacoes

/**
  *\brief A funcao "incrementa" incrementa(+1) o valor do DATA.
  *@param Esta função tem como parâmetros o apontador da stack
  *@returns Esta função não tem retorno
  */
void incrementa(STACK *s){
	DATA x = pop(s);
	DATA res;
	if(has_type(x,LONG)){
		res.type=LONG;
		res.LONG=x.LONG+1;
	}
	if(has_type(x,DOUBLE)){
		res.type=DOUBLE;
		res.DOUBLE=x.DOUBLE+1;
	}
	if(has_type(x,CHAR)){
		res.type=CHAR;
		res.CHAR=x.CHAR+1;
	}
	push(s,res);
}
/**
  *\brief A funcao "decrementa" decrementa(-1) o valor do DATA.
  *@param Esta função tem como parâmetros o apontador da stack
  *@returns Esta função não tem retorno
  */
void decrementa(STACK *s){
	DATA x = pop(s);
	DATA res;
	if(has_type(x,LONG)){
		res.type=LONG;
		res.LONG=x.LONG-1;
	}
	if(has_type(x,DOUBLE)){
		res.type=DOUBLE;
		res.DOUBLE=x.DOUBLE-1;
	}
	if(has_type(x,CHAR)){
		res.type=CHAR;
		res.CHAR=x.CHAR-1;
	}
	push(s,res);
}

/**
  *\brief A funcao "soma" realiza a soma entre dois DATA .
  *@param Esta função tem como parâmetros o apontador da stack
  *@returns Esta função não tem retorno
  */
void soma(STACK *s) {             
  	DATA x = pop(s);
  	DATA y = pop(s);
  	DATA res;
  	if (has_type(x,LONG) && has_type(y,LONG)){
  		res.type= LONG;
  		res.LONG = x.LONG + y.LONG;
  	}
  	else if (has_type(x,DOUBLE) && has_type(y,LONG)){
  		res.type= DOUBLE;
  		res.DOUBLE = x.DOUBLE + y.LONG;
  	}
  	else if (has_type(x,DOUBLE) && has_type(y,DOUBLE)){
  		res.type= DOUBLE;
  		res.DOUBLE = x.DOUBLE + y.DOUBLE;
  	}
  	else if (has_type(x,LONG) && has_type(y,DOUBLE)){
  		res.type= DOUBLE;
  		res.DOUBLE = x.LONG + y.DOUBLE;
  	}
  	else if (has_type(x,LONG) && has_type(y,CHAR)){
  		res.type= CHAR;
  		res.CHAR = x.LONG + y.CHAR;
  	}
  	else if (has_type(x,CHAR) && has_type(y,LONG)){
  		res.type= LONG;
  		res.LONG = x.LONG + y.CHAR;
  	}
  	else if (has_type(x,DOUBLE) && has_type(y,CHAR)){
  		res.type= DOUBLE;
  		res.DOUBLE = x.DOUBLE + y.CHAR;
  	}
  	else if (has_type(x,CHAR) && has_type(y,DOUBLE)){
  		res.type= DOUBLE;
  		res.DOUBLE = x.DOUBLE + y.CHAR;
  	}
  	else if (has_type(x,CHAR) && has_type(y,CHAR)){
  		res.type= LONG;
  		res.LONG = x.CHAR + y.CHAR;
  	}
  	push(s,res);
}

/**
  *\brief A funcao "subtracao" subtrai dois DATA.
  *@param Esta função tem como parâmetros o apontador da stack
  *@returns Esta função não tem retorno
  */
void subtracao(STACK *s) {             
  	DATA x = pop(s);
  	DATA y = pop(s);
  	DATA res;
  	if (has_type(x,LONG) && has_type(y,LONG)){
  		res.type= LONG;
  		res.LONG = -x.LONG + y.LONG;
  	}
  	else if (has_type(x,DOUBLE) && has_type(y,LONG)){
  		res.type= DOUBLE;
  		res.DOUBLE = -x.DOUBLE + y.LONG;
  	}
  	else if (has_type(x,DOUBLE) && has_type(y,DOUBLE)){
  		res.type= DOUBLE;
  		res.DOUBLE = -x.DOUBLE + y.DOUBLE;
  	}
  	else if (has_type(x,LONG) && has_type(y,DOUBLE)){
  		res.type= DOUBLE;
  		res.DOUBLE = -x.LONG + y.DOUBLE;
  	}
  	else if (has_type(x,LONG) && has_type(y,CHAR)){
  		res.type= CHAR;
  		res.CHAR = -x.LONG + y.CHAR;
  	}
  	else if (has_type(x,CHAR) && has_type(y,LONG)){
  		res.type= LONG;
  		res.LONG = -x.LONG + y.CHAR;
  	}
  	else if (has_type(x,DOUBLE) && has_type(y,CHAR)){
  		res.type= DOUBLE;
  		res.DOUBLE = -x.DOUBLE + y.CHAR;
  	}
  	else if (has_type(x,CHAR) && has_type(y,DOUBLE)){
  		res.type= DOUBLE;
  		res.DOUBLE = -x.DOUBLE + y.CHAR;
  	}
  	else if (has_type(x,CHAR) && has_type(y,CHAR)){
  		res.type= LONG;
  		res.LONG = -x.CHAR + y.CHAR;
  	}
  	push(s,res);
}

/**
  *\brief A funcao "mult" realiza a multiplicação de dois DATA.
  *@param Esta função tem como parâmetros o apontador da stack
  *@returns Esta função não tem retorno
  */
void mult(STACK *s) {             
  	DATA x = pop(s);
  	DATA y = pop(s);
  	DATA res;
  	if (has_type(x,LONG) && has_type(y,LONG)){
  		res.type= LONG;
  		res.LONG = x.LONG * y.LONG;
  	}
  	else if (has_type(x,DOUBLE) && has_type(y,LONG)){
  		res.type= DOUBLE;
  		res.DOUBLE = x.DOUBLE * y.LONG;
  	}
  	else if (has_type(x,DOUBLE) && has_type(y,DOUBLE)){
  		res.type= DOUBLE;
  		res.DOUBLE = x.DOUBLE * y.DOUBLE;
  	}
  	else if (has_type(x,LONG) && has_type(y,DOUBLE)){
  		res.type= DOUBLE;
  		res.DOUBLE = x.LONG * y.DOUBLE;
  	}
  	else if (has_type(x,LONG) && has_type(y,CHAR)){
  		res.type= CHAR;
  		res.CHAR = x.LONG * y.CHAR;
  	}
  	else if (has_type(x,CHAR) && has_type(y,LONG)){
  		res.type= LONG;
  		res.LONG = x.LONG * y.CHAR;
  	}
  	else if (has_type(x,DOUBLE) && has_type(y,CHAR)){
  		res.type= DOUBLE;
  		res.DOUBLE = x.DOUBLE * y.CHAR;
  	}
  	else if (has_type(x,CHAR) && has_type(y,DOUBLE)){
  		res.type= DOUBLE;
  		res.DOUBLE = x.DOUBLE * y.CHAR;
  	}
  	else if (has_type(x,CHAR) && has_type(y,CHAR)){
  		res.type= LONG;
  		res.LONG = x.CHAR * y.CHAR;
  	}
  	push(s,res);
}

/**
  *\brief A funcao "divisao" realiza a multiplicação de dois DATA.
  *@param Esta função tem como parâmetros o apontador da stack
  *@returns Esta função não tem retorno
  */
void divisao(STACK *s) {                                      
    DATA x = pop(s);                                     
    DATA y = pop(s);                                     
    DATA res;                                            
 if(has_type(x, LONG) && has_type(y, LONG)) {             
    res.type = LONG;                                     
    res.LONG = y.LONG / x.LONG;  }                       
  else if (has_type(x, DOUBLE) && has_type(y, LONG)) {   
    res.type = DOUBLE;                                   
    res.DOUBLE = y.LONG / x.DOUBLE;  }                   
  else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)) { 
    res.type = DOUBLE;                                   
    res.DOUBLE = y.DOUBLE / x.DOUBLE;  }                 
  else if (has_type(x, LONG) && has_type(y, DOUBLE)) {   
    res.type = DOUBLE;                                   
    res.DOUBLE = y.DOUBLE / x.LONG;  }                   
  else if (has_type(x, CHAR) && has_type(y, LONG)) { 
    res.type = LONG;                                     
    res.LONG = y.LONG / x.CHAR;   }                       
  else if (has_type(x, LONG) && has_type(y, CHAR)) {  
    res.type = LONG;                                     
    res.LONG = y.CHAR / x.LONG;  }                       
  else if (has_type(x, CHAR) && has_type(y, DOUBLE)) {   
    res.type = DOUBLE;                                   
    res.DOUBLE = y.DOUBLE / x.CHAR;  }                 
 else if (has_type(x, DOUBLE) && has_type(y, CHAR)) {    
    res.type = DOUBLE;                                   
    res.DOUBLE = y.CHAR / x.DOUBLE ;  }                 
 else if (has_type(x, CHAR) && has_type(y, CHAR)) {      
    res.type = LONG;                                     
    res.LONG = y.CHAR / x.CHAR;  }                       
 push(s,res); 
}

/**
  *\brief A funcao "resto" realiza o resto da divisao de dois DATA.
  *@param Esta função tem como parâmetros o apontador da stack
  *@returns Esta função não tem retorno
  */
void resto(STACK *s)  {                                   
    DATA y = pop(s);                                
    DATA x = pop(s);                                
    DATA res;                                            
 if(has_type(x, LONG) && has_type(y, LONG)) {            
    res.type = LONG;                                     
    res.LONG = x.LONG % y.LONG;  }                       
  else if (has_type(x, CHAR) && has_type(y, LONG)) {     
    res.type = LONG;                                     
    res.LONG = x.CHAR % y.LONG;  }                       
  else if (has_type(x, LONG) && has_type(y, CHAR)) {     
    res.type = LONG;                                     
    res.LONG = x.LONG % y.CHAR;  }                       
 else if (has_type(x, CHAR) && has_type(y, CHAR)) {      
    res.type = LONG;                                     
    res.LONG = x.CHAR % y.CHAR;  }                       
 push(s,res);
}

/**
  *\brief A funcao "expon" realiza a exponenciação de um DATA em relacao ao DATA que lhe serve de base.
  *@param Esta função tem como parâmetros o apontador da stack
  *@returns Esta função não tem retorno
  */
void expon(STACK *s) {             
  	DATA x = pop(s);
  	DATA y = pop(s);
  	DATA res;
  	if (has_type(x,LONG) && has_type(y,LONG)){
  		res.type= LONG;
  		res.LONG = powl(y.LONG, x.LONG);
  	}
  	else if (has_type(x,DOUBLE) && has_type(y,LONG)){
  		res.type= DOUBLE;
  		res.DOUBLE = powf(y.LONG, x.DOUBLE);
  	}
  	else if (has_type(x,DOUBLE) && has_type(y,DOUBLE)){
  		res.type= DOUBLE;
  		res.DOUBLE = powf(y.DOUBLE,x.DOUBLE);
  	}
  	else if (has_type(x,LONG) && has_type(y,DOUBLE)){
  		res.type= DOUBLE;
  		res.DOUBLE = powf(y.DOUBLE,x.LONG);
  	}
  	else if (has_type(x,LONG) && has_type(y,CHAR)){
  		res.type= CHAR;
  		res.CHAR = powl(y.LONG, x.CHAR);
  	}
  	else if (has_type(x,CHAR) && has_type(y,LONG)){
  		res.type= LONG;
  		res.LONG = powl(y.LONG, x.CHAR);
  	}
  	else if (has_type(x,DOUBLE) && has_type(y,CHAR)){
  		res.type= DOUBLE;
  		res.DOUBLE = powf(y.DOUBLE, x.CHAR);
  	}
  	else if (has_type(x,CHAR) && has_type(y,DOUBLE)){
  		res.type= DOUBLE;
  		res.DOUBLE = powf(y.DOUBLE,x.CHAR);
  	}
  	else if (has_type(x,CHAR) && has_type(y,CHAR)){
  		res.type= LONG;
  		res.LONG = powl(y.CHAR,x.CHAR);
  	}
  	push(s,res);
}

//Operacoes lógicas

/**
  *\brief A funcao "AMPERSAND" realiza a interseção de dois DATA na forma binária ( é 1 apenas se ambos os bits forem 1).
  *@param Esta função tem como parâmetros o apontador da stack
  *@returns Esta função não tem retorno
  */
void AMPERSAND(STACK *s) {                              
    DATA x = pop(s);                                
    DATA y = pop(s);                                
    DATA res;                                            
 if(has_type(x, LONG) && has_type(y, LONG)) {            
    res.type = LONG;                                     
    res.LONG = x.LONG & y.LONG;  }                       
  else if (has_type(x, CHAR) && has_type(y, LONG)) {     
    res.type = LONG;                                     
    res.LONG = x.CHAR & y.LONG;  }                       
  else if (has_type(x, LONG) && has_type(y, CHAR)) {     
    res.type = LONG;                                     
    res.LONG = x.LONG & y.CHAR;  }                       
 else if (has_type(x, CHAR) && has_type(y, CHAR)) {      
    res.type = CHAR;                                     
    res.CHAR = x.CHAR & y.CHAR;  }                       
 push(s,res);
}

/**
  *\brief A funcao "XOR" realiza a reuniao de dois DATA na forma binária ( é 1 se os dois bits forem diferentes).
  *@param Esta função tem como parâmetros o apontador da stack
  *@returns Esta função não tem retorno
  */
void XOR(STACK *s)  {                                   
    DATA x = pop(s);                                
    DATA y = pop(s);                                
    DATA res;                                            
 if(has_type(x, LONG) && has_type(y, LONG)) {            
    res.type = LONG;                                     
    res.LONG = x.LONG ^ y.LONG;  }                       
  else if (has_type(x, CHAR) && has_type(y, LONG)) {     
    res.type = LONG;                                     
    res.LONG = x.CHAR ^ y.LONG;  }                       
  else if (has_type(x, LONG) && has_type(y, CHAR)) {     
    res.type = LONG;                                     
    res.LONG = x.LONG ^ y.CHAR;  }                       
 else if (has_type(x, CHAR) && has_type(y, CHAR)) {      
    res.type = LONG;                                     
    res.LONG = x.CHAR ^ y.CHAR;  }                       
 push(s,res);
}

/**
  *\brief A funcao "NOT" realiza o oposto do DATA recebido na forma binaria.
  *@param Esta função tem como parâmetros o apontador da stack
  *@returns Esta função não tem retorno
  */
void NOT(STACK *s){                                   
    DATA x = pop(s);                                
    DATA res;                                            
 if(has_type(x, LONG)) {                                 
    res.type = LONG;                                     
    res.LONG = ~(x.LONG);  }                             
  else if (has_type(x, CHAR)) {                          
    res.type = CHAR;                                     
    res.CHAR = ~(x.CHAR);  }                             
 push(s,res);
}

/**
  *\brief A funcao "OR" realiza a reunião de dois DATA na forma binária (é 1 se qualquer um dos dois bits for 1).
  *@param Esta função tem como parâmetros o apontador da stack
  *@returns Esta função não tem retorno
  */
void OR(STACK *s)    {                                   
    DATA x = pop(s);                                
    DATA y = pop(s);                                
    DATA res;                                            
 if(has_type(x, LONG) && has_type(y, LONG)) {            
    res.type = LONG;                                     
    res.LONG = (x.LONG | y.LONG);  }                     
  else if (has_type(x, CHAR) && has_type(y, LONG)) {     
    res.type = LONG;                                     
    res.LONG = (x.CHAR | y.LONG);  }                     
  else if (has_type(x, LONG) && has_type(y, CHAR)) {     
    res.type = LONG;                                     
    res.LONG = (x.LONG | y.CHAR);  }                     
 else if (has_type(x, CHAR) && has_type(y, CHAR)) {      
    res.type = LONG;                                     
    res.LONG = (x.CHAR | y.CHAR);  }                     
 push(s,res);
}