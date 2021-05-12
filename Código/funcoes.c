#include <stdio.h>
#include "stack.h"
#include "funmath.h"

/**
  *\brief Coloca o menor dos dois valores na STACK.
  *@param Recebe a STACK como argumento.
  *@returns Esta função não tem retorno.
  */
void e_menor(STACK *s) {
    DATA x = pop(s);   
    DATA y = pop(s);   
    DATA r; 
    if(has_type(x, LONG) || has_type(y, LONG)) {
        if(x.LONG<y.LONG){
           push(s,x);
        } else {                          
           push(s,y); 
        }
    } else if(has_type(x, LONG) || has_type(y, DOUBLE)) {
        if(x.LONG<y.DOUBLE) { 
           push(s,x);
        } else {
           push(s,y);                     
        }
    } else if(has_type(x, DOUBLE) || has_type(y, LONG)) {
        if(x.DOUBLE<y.LONG) { 
           push(s,x);
        } else {
           push(s,y);                   
        }
        push(s,r); 
    } else if(has_type(x, DOUBLE) || has_type(y, DOUBLE)) {     
        if(x.DOUBLE<y.DOUBLE) { 
           push(s,x);
        } else {
           push(s,y);                    
        }
        push(s,r);
    } else if(has_type(x, CHAR) || has_type(y, LONG)) {
        if(y.LONG<x.CHAR ) { 
            push(s,y);
        } else {
            push(s,x);                   
        }
        push(s,r);
    } else if(has_type(x, LONG) || has_type(y, CHAR)) {
        if(x.LONG<y.CHAR ) {
           push(s,x);
        } else {                          
           push(s,y); 
        }
    } else if(has_type(x, CHAR) || has_type(y, CHAR)) {
        if(x.CHAR<y.CHAR ){
           push(s,x);
        } else {                          
           push(s,y); 
        }
    } else if(has_type(x, DOUBLE) || has_type(y, CHAR)) {
        if(x.DOUBLE<y.CHAR ) { 
           push(s,x);
        } else {
           push(s,y);                     
        }
    } else if(has_type(x, CHAR) || has_type(y, DOUBLE)) {
        if(x.CHAR<y.DOUBLE ) { 
           push(s,x);
        } else {
           push(s,y);                     
        }
    }
}
/**
  *\brief Coloca o maior dos dois valores na STACK.
  *@param Recebe a STACK como argumento.
  *@returns Esta função não tem retorno.
  */
void e_maior(STACK *s) {
    DATA x = pop(s);   
    DATA y = pop(s);   
    DATA r; 
    if(has_type(x, LONG) || has_type(y, LONG)) {
        if(x.LONG>y.LONG){
           push(s,x);
        } else {                          
           push(s,y); 
        }
    } else if(has_type(x, LONG) || has_type(y, DOUBLE)) {
        if(x.LONG>y.DOUBLE) { 
           push(s,x);
        } else {
           push(s,y);                     
        }
    } else if(has_type(x, DOUBLE) || has_type(y, LONG)) {
        if(x.DOUBLE>y.LONG) { 
           push(s,x);
        } else {
           push(s,y);                   
        }
        push(s,r); 
    } else if(has_type(x, DOUBLE) || has_type(y, DOUBLE)) {     
        if(x.DOUBLE>y.DOUBLE) { 
           push(s,x);
        } else {
           push(s,y);                    
        }
        push(s,r);
    } else if(has_type(x, CHAR) || has_type(y, LONG)) {
        if(y.LONG>x.CHAR ) { 
            push(s,y);
        } else {
            push(s,x);                   
        }
        push(s,r);
    } else if(has_type(x, LONG) || has_type(y, CHAR)) {
        if(x.LONG>y.CHAR ) {
           push(s,x);
        } else {                          
           push(s,y); 
        }
    } else if(has_type(x, CHAR) || has_type(y, CHAR)) {
        if(x.CHAR>y.CHAR ){
           push(s,x);
        } else {                          
           push(s,y); 
        }
    } else if(has_type(x, DOUBLE) || has_type(y, CHAR)) {
        if(x.DOUBLE>y.CHAR ) { 
           push(s,x);
        } else {
           push(s,y);                     
        }
    } else if(has_type(x, CHAR) || has_type(y, DOUBLE)) {
        if(x.CHAR>y.DOUBLE ) { 
           push(s,x);
        } else {
           push(s,y);                     
        }
    }
}
/**
  *\brief Função que coloca no topo da STACK 0 se um dos seus elementos é 0, caso contrario retorna o topo.
  *@param Recebe a STACK como argumento.
  *@returns Esta função não tem retorno.
  */
void e_com_shortcut(STACK *s) {
    DATA x = pop(s);   
    DATA y = pop(s);   
    DATA r; 
    if(has_type(x, LONG) && has_type(y, LONG)) {
        if(x.LONG == 0 || y.LONG == 0) {
           r.type = LONG;
           r.LONG = 0;
        } else {
           r.type = LONG; 
           r.LONG = x.LONG;                     
        }
        push(s,r);
    } else if(has_type(x, LONG) && has_type(y, DOUBLE)) {
        if(x.LONG == 0 || y.DOUBLE== 0) { 
           r.type = LONG;
           r.LONG = 0;
        } else {
           r.type = LONG; 
           r.LONG = x.LONG;                     
        }
        push(s,r);
    } else if(has_type(x, DOUBLE) && has_type(y, LONG)) {
        if(x.DOUBLE == 0 || y.LONG == 0) { 
           r.type = LONG;
           r.LONG = 0;
        } else {
           r.type = DOUBLE; 
           r.DOUBLE = x.DOUBLE;                     
        }
        push(s,r); 
    } else if(has_type(x, DOUBLE) && has_type(y, DOUBLE)) {    
        if(x.DOUBLE == 0 || y.DOUBLE == 0) { 
           r.type = LONG;
           r.LONG = 0;
        } else {
           r.type = DOUBLE; 
           r.DOUBLE = x.DOUBLE;                     
        }
        push(s,r);
    } else if(has_type(x, CHAR) && has_type(y, LONG)) {
        if(y.LONG == 0 || x.CHAR == 0) { 
           r.type = LONG;
           r.LONG = 0;
        } else {
           r.type = CHAR; 
           r.CHAR = x.CHAR;                     
        }
        push(s,r);
    } else if(has_type(x, LONG) && has_type(y, CHAR)) {
        if(x.LONG == 0 || y.CHAR == 0) {
           r.LONG = 0;
           push(s,r);
        } else {                          
           push(s,x); 
        }
    } else if(has_type(x, CHAR) && has_type(y, CHAR)) {
        if(x.CHAR == 0 || y.CHAR == 0) {
           r.LONG = 0;
           push(s,r);
        } else {                          
           push(s,x); 
        }
    } else if(has_type(x, DOUBLE) && has_type(y, CHAR)) {
        if(x.DOUBLE == 0 || y.CHAR == 0) { 
           r.type = LONG;
           r.LONG = 0;
        } else {
           r.type = DOUBLE; 
           r.DOUBLE = x.DOUBLE;                     
        }
        push(s,r);
    } else if(has_type(x, CHAR) && has_type(y, DOUBLE)) {
        if(x.CHAR == 0 || y.DOUBLE == 0) { 
           r.type = LONG;
           r.LONG = 0;
        } else {
           r.type = CHAR; 
           r.CHAR = x.CHAR;                     
        }
        push(s,r);
    }
}
/**
  *\brief Funçãp que coloca no topo da STACK 0 se os dois elementos forem 0, caso contrario retorna o penúltimo elemento.
  *@param Recebe a STACK como argumento.
  *@returns Esta função não tem retorno.
  */
void ou_com_shortcut(STACK *s) {
    DATA x = pop(s);   
    DATA y = pop(s);   
    DATA r; 
    if(has_type(x, LONG) && has_type(y, LONG)) {
        if(x.LONG == 0 && y.LONG == 0) {
           r.LONG = 0;
           push(s,r);
        } else if (x.LONG != 0 && y.LONG ==0) {                          
           push(s,x); 
        } else {
           push(s,y);
        }
    } else if(has_type(x, LONG) && has_type(y, DOUBLE)) {
        if(x.LONG == 0 && y.DOUBLE == 0) {
           r.LONG = 0;
           push(s,r);
        } else if (x.LONG != 0 && y.DOUBLE ==0) {                          
           push(s,x); 
        } else {
           push(s,y);
        }
    } else if(has_type(x, DOUBLE) && has_type(y, LONG)) {
        if(x.DOUBLE == 0 && y.DOUBLE == 0) {
           r.LONG = 0;
           push(s,r);
        } else if (x.DOUBLE != 0 && y.LONG ==0) {                          
           push(s,x); 
        } else {
           push(s,y);
        }
    } else if(has_type(x, DOUBLE) && has_type(y, DOUBLE)) {     
        if(x.DOUBLE == 0 && y.DOUBLE == 0) {
           r.LONG = 0;
           push(s,r);
        } else if (x.DOUBLE != 0 && y.DOUBLE ==0) {                          
           push(s,x); 
        } else {
           push(s,y);
        }
    } else if(has_type(x, CHAR) && has_type(y, LONG)) {
        if(x.CHAR == 0 && y.LONG == 0) {
           r.LONG = 0;
           push(s,r);
        } else if (x.CHAR != 0 && y.LONG ==0) {                          
           push(s,x); 
        } else {
           push(s,y);
        }
    } else if(has_type(x, LONG) && has_type(y, CHAR)) {
        if(x.LONG == 0 && y.CHAR == 0) {
           r.LONG = 0;
           push(s,r);
        } else if (x.LONG != 0 && y.CHAR == 0) {                          
           push(s,x); 
        } else {
           push(s,y);
        }
    } else if(has_type(x, CHAR) && has_type(y, CHAR)) {
        if(x.CHAR == 0 && y.CHAR == 0) {
           r.LONG = 0;
           push(s,r);
        } else if (x.CHAR != 0 && y.CHAR ==0) {                      
           push(s,x); 
        } else {
           push(s,y);
        }
    } else if(has_type(x, DOUBLE) && has_type(y, CHAR)) {
        if(x.DOUBLE == 0 && y.CHAR == 0) {
           r.LONG = 0;
           push(s,r);
        } else if (x.DOUBLE != 0 && y.CHAR ==0) {                          
           push(s,x); 
        } else {
           push(s,y);
        }
    } else if(has_type(x, CHAR) && has_type(y, DOUBLE)) {
        if(x.CHAR == 0 && y.DOUBLE == 0) {
           r.LONG = 0;
           push(s,r);
        } else if (x.CHAR != 0 && y.DOUBLE ==0) {                          
           push(s,x); 
        } else {
           push(s,y);
        }
    }
}
/**
  *\brief Funçao que se o topo e o penúltimo forem iguais retorna 1, caso contario retorna 0.
  *@param Recebe a STACK como argumento.
  *@returns Esta função não tem retorno.
  */
void igual(STACK *s) {                                      
    DATA x = pop(s);                                     
    DATA y = pop(s);                                                                                
    if(has_type(x, LONG) && has_type(y, LONG)) {            
        if(x.LONG == y.LONG){
            push_LONG(s,1);
        }else push_LONG(s,0);}     
    else if (has_type(x, DOUBLE) && has_type(y, LONG)) {   
        if(x.DOUBLE == y.LONG){
            push_LONG(s,1);
        }else push_LONG(s,0);}                   
    else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)) { 
        if(x.DOUBLE == y.DOUBLE){
            push_LONG(s,1);
        }else push_LONG(s,0);}                 
    else if (has_type(x, LONG) && has_type(y, DOUBLE)) {   
        if(x.LONG == y.DOUBLE){
            push_LONG(s,1);
        }else push_LONG(s,0);}                  
    else if (has_type(x, CHAR) && has_type(y, LONG)) { 
        if(x.CHAR == y.LONG){
            push_LONG(s,1);
        }else push_LONG(s,0);}                      
    else if (has_type(x, LONG) && has_type(y, CHAR)) {  
        if(x.LONG == y.CHAR){
            push_LONG(s,1);
        }else push_LONG(s,0);}                      
    else if (has_type(x, CHAR) && has_type(y, DOUBLE)) {   
        if(x.CHAR == y.DOUBLE){
            push_LONG(s,1);
        }else push_LONG(s,0);}                
    else if (has_type(x, DOUBLE) && has_type(y, CHAR)) {    
        if(x.DOUBLE == y.CHAR){
            push_LONG(s,1);
        }else push_LONG(s,0);}
    else if (has_type(x, CHAR) && has_type(y, CHAR)) {      
        if(x.CHAR == y.CHAR){
            push_LONG(s,1);
        }else push_LONG(s,0);}                        
}
/**
  *\brief Funçao que coloca no topo da STACK 0 se o topo for menor que o penúltimo, e 1 se o topo for maior ao penúltimo.
  *@param Recebe a STACK como argumento.
  *@returns Esta função não tem retorno.
  */
void menor(STACK *s) {                                      
    DATA x = pop(s);                                     
    DATA y = pop(s);                                                                                
    if(has_type(x, LONG) && has_type(y, LONG)) {            
        if(x.LONG < y.LONG){
            push_LONG(s,0);
        }else push_LONG(s,1);}     
    else if (has_type(x, DOUBLE) && has_type(y, LONG)) {   
        if(x.DOUBLE < y.LONG){
            push_LONG(s,0);
        }else push_LONG(s,1);}                   
    else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)) { 
        if(x.DOUBLE < y.DOUBLE){
            push_LONG(s,0);
        }else push_LONG(s,1);}                 
    else if (has_type(x, LONG) && has_type(y, DOUBLE)) {   
        if(x.LONG < y.DOUBLE){
            push_LONG(s,0);
        }else push_LONG(s,1);}                  
    else if (has_type(x, CHAR) && has_type(y, LONG)) { 
        if(x.CHAR < y.LONG){
            push_LONG(s,0);
        }else push_LONG(s,1);}                      
    else if (has_type(x, LONG) && has_type(y, CHAR)) {  
        if(x.LONG < y.CHAR){
            push_LONG(s,0);
        }else push_LONG(s,1);}                      
    else if (has_type(x, CHAR) && has_type(y, DOUBLE)) {   
        if(x.CHAR < y.DOUBLE){
            push_LONG(s,0);
        }else push_LONG(s,1);}                
    else if (has_type(x, DOUBLE) && has_type(y, CHAR)) {    
        if(x.DOUBLE < y.CHAR){
            push_LONG(s,0);
        }else push_LONG(s,1);}
    else if (has_type(x, CHAR) && has_type(y, CHAR)) {      
        if(x.CHAR < y.CHAR){
            push_LONG(s,0);
        }else push_LONG(s,1);}                        
}
/**
  *\brief Funçao que coloca no topo da STACK 0 se o topo for maior que o penúltimo, e 1 se o topo for menor ao penúltimo.
  *@param Recebe a STACK como argumento.
  *@returns Esta função não tem retorno.
  */
void maior(STACK *s) {                                      
    DATA x = pop(s);                                     
    DATA y = pop(s);                                                                                
    if(has_type(x, LONG) && has_type(y, LONG)) {            
        if(x.LONG > y.LONG){
            push_LONG(s,0);
        }else push_LONG(s,1);}     
    else if (has_type(x, DOUBLE) && has_type(y, LONG)) {   
        if(x.DOUBLE > y.LONG){
            push_LONG(s,0);
        }else push_LONG(s,1);}                   
    else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)) { 
        if(x.DOUBLE > y.DOUBLE){
            push_LONG(s,0);
        }else push_LONG(s,1);}                 
    else if (has_type(x, LONG) && has_type(y, DOUBLE)) {   
        if(x.LONG > y.DOUBLE){
            push_LONG(s,0);
        }else push_LONG(s,1);}                  
    else if (has_type(x, CHAR) && has_type(y, LONG)) { 
        if(x.CHAR > y.LONG){
            push_LONG(s,0);
        }else push_LONG(s,1);}                      
    else if (has_type(x, LONG) && has_type(y, CHAR)) {  
        if(x.LONG > y.CHAR){
            push_LONG(s,0);
        }else push_LONG(s,1);}                      
    else if (has_type(x, CHAR) && has_type(y, DOUBLE)) {   
        if(x.CHAR > y.DOUBLE){
            push_LONG(s,0);
        }else push_LONG(s,1);}                
    else if (has_type(x, DOUBLE) && has_type(y, CHAR)) {    
        if(x.DOUBLE > y.CHAR){
            push_LONG(s,0);
        }else push_LONG(s,1);}
    else if (has_type(x, CHAR) && has_type(y, CHAR)) {      
        if(x.CHAR > y.CHAR){
            push_LONG(s,0);
        }else push_LONG(s,1);}                        
}
/**
  *\brief Funçao que coloca no topo da STACK 1 se o topo for 0 e coloca 0 se o topo for qualquer número exceto 0.
  *@param Recebe a STACK como argumento.
  *@returns Esta função não tem retorno.
  */
void nao(STACK *s){
  DATA x = pop(s);
  if (x.LONG == 1){
    push_LONG(s,0);
  }
  else if(x.LONG==0){
    push_LONG(s,1);
  }
  else if(x.DOUBLE==0.0) {
    push_LONG(s,1);
  }
  else if(x.CHAR == 0){
    push_LONG(s,1);
  }
  else{
    push_LONG(s,0);
  }
}
/**
  *\brief Condição if_then_else.
  *@param Recebe a STACK como argumento.
  *@returns Esta função não tem retorno.
  */
void if_then_else(STACK *s){
    DATA z = pop(s);
    DATA y = pop(s);
    DATA x = pop(s);
    if(x.LONG == 0){
      push(s,z);
    }
    else{
      push(s,y);
    }
}