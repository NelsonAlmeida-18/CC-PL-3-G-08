#include <stdio.h>
#include "stack.h"
#include "funmath.h"

//duvida com os shortcut
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
    } else if(has_type(x, DOUBLE) || has_type(y, DOUBLE)) {    // 0.0 nao funciona 
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
    } else if(has_type(x, DOUBLE) || has_type(y, DOUBLE)) {    // 0.0 nao funciona 
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
    } else if(has_type(x, DOUBLE) && has_type(y, DOUBLE)) {    // 0.0 nao funciona 
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