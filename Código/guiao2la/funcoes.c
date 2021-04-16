#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include <math.h>

//stack
void barrabarra(STACK *s){
	DATA x = pop(s);
	DATA y = pop(s);
	push(s,x);
	push(s,y);
}
void underscore(STACK *s){
	DATA x = top(s);
	push(s,x);
}

void ponto_virgula(STACK *s){
	pop(s);
}

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

void arroba(STACK *s){
	DATA x = pop(s);
	DATA y = pop(s);
	DATA z = pop(s);
	push(s,y);
	push(s,x);
	push(s,z);
}

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
//fazer
void converteDOUBLE(STACK *s) {             
   DATA x = pop(s);                              
   if(has_type(x,DOUBLE)) {                  
     push(s,x);  
   } 
/*
   else if(has_type(x,CHAR)) {
   	  char y = x.CHAR;
   	  double k = atoi(y);              
      push_DOUBLE(s,k); 
   }
*/ 
   else if(has_type(x,STRING)) { 
      double y = atof(x.STRING);      
      push_LONG(s,y); 
   } 
   else if(has_type(x,LONG)){ 
   		double y = x.DOUBLE;
   		double k = (double)y;
     	push_DOUBLE(s,k);    
   }
}

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

void divisao(STACK *s) {             
  	DATA x = pop(s);
  	DATA y = pop(s);
  	DATA res;
  	if (has_type(x,LONG) && has_type(y,LONG)){
  		res.type= LONG;
  		res.LONG = y.LONG / x.LONG;
  	}
  	else if (has_type(x,DOUBLE) && has_type(y,LONG)){
  		res.type= DOUBLE;
  		res.DOUBLE = y.LONG / x.DOUBLE;
  	}
  	else if (has_type(x,DOUBLE) && has_type(y,DOUBLE)){
  		res.type= DOUBLE;
  		res.DOUBLE = y.DOUBLE / x.DOUBLE;
  	}
  	else if (has_type(x,LONG) && has_type(y,DOUBLE)){
  		res.type= DOUBLE;
  		res.DOUBLE = y.DOUBLE / x.LONG;
  	}
  	else if (has_type(x,LONG) && has_type(y,CHAR)){
  		res.type= CHAR;
  		res.CHAR = y.CHAR/ x.LONG;
  	}
  	else if (has_type(x,CHAR) && has_type(y,LONG)){
  		res.type= LONG;
  		res.LONG = y.CHAR / x.LONG;
  	}
  	else if (has_type(x,DOUBLE) && has_type(y,CHAR)){
  		res.type= DOUBLE;
  		res.DOUBLE = y.CHAR / x.DOUBLE;
  	}
  	else if (has_type(x,CHAR) && has_type(y,DOUBLE)){
  		res.type= DOUBLE;
  		res.DOUBLE =  y.DOUBLE / x.CHAR ;
  	}
  	else if (has_type(x,CHAR) && has_type(y,CHAR)){
  		res.type= LONG;
  		res.LONG =  y.CHAR / x.CHAR;
  	}
  	push(s,res);
}

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

void NOT(STACK *s)   {                                   
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