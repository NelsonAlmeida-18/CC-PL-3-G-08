#include <stdio.h>
#include "stack.h"
#include "funmath.h"

void igual(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if (has_type(x,LONG) && has_type(y,LONG)){
      if (x.LONG==y.LONG){
        push_LONG(s,1);
      }
      else{
        push_LONG(s,0);
      }
    }
    else if (has_type(x,DOUBLE) && has_type(y,DOUBLE)){
      if (x.DOUBLE==y.DOUBLE){
        push_LONG(s,1);
      }
      else{
        push_LONG(s,0);
      }
    }
    else if (has_type(x,CHAR) && has_type(y,CHAR)){
      if (x.CHAR==y.CHAR){
        push_LONG(s,1);
      }
      else{
        push_LONG(s,0);
      }
    }
    else{
      push_LONG(s,0);
    }
}

void menor(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if (has_type(x,LONG) && has_type(y,LONG)){
      if (x.LONG<y.LONG){
        push_LONG(s,0);
      }
      else{
        push_LONG(s,1);
      }
    }
    else if (has_type(x,DOUBLE) && has_type(y,DOUBLE)){
      if (x.DOUBLE<y.DOUBLE){
        push_LONG(s,0);
      }
      else{
        push_LONG(s,1);
      }
    }
    else if (has_type(x,CHAR) && has_type(y,CHAR)){
      if (x.CHAR<y.CHAR){
        push_LONG(s,0);
      }
      else{
        push_LONG(s,1);
      }
    }
    else{
      push_LONG(s,1);
    }
}

void maior(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if (has_type(x,LONG) && has_type(y,LONG)){
      if (x.LONG>y.LONG){
        push_LONG(s,0);
      }
      else{
        push_LONG(s,1);
      }
    }
    else if (has_type(x,DOUBLE) && has_type(y,DOUBLE)){
      if (x.DOUBLE>y.DOUBLE){
        push_LONG(s,0);
      }
      else{
        push_LONG(s,1);
      }
    }
    else if (has_type(x,CHAR) && has_type(y,CHAR)){
      if (x.CHAR>y.CHAR){
        push_LONG(s,0);
      }
      else{
        push_LONG(s,1);
      }
    }
    else{
      push_LONG(s,1);
    }
}

void nao(STACK *s){
  DATA x = pop(s);
  if(x.LONG==0){
    push_LONG(s,1);
  }
  else{
    push_LONG(s,0);
  }
}

void menor_dos_dois(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if (has_type(x,LONG) && has_type(y,LONG)){
      if (x.LONG<y.LONG){
        push(s,x);
      }
      else{
        push(s,y);
      }
    }
    else if (has_type(x,DOUBLE) && has_type(y,DOUBLE)){
      if (x.DOUBLE<y.DOUBLE){
        push(s,x);
      }
      else{
        push(s,y);
      }
    }
    else if (has_type(x,CHAR) && has_type(y,CHAR)){
      if (x.CHAR<y.CHAR){
        push(s,x);
      }
      else{
        push(s,y);
      }
    }
}

void maior_dos_dois(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if (has_type(x,LONG) && has_type(y,LONG)){
      if (x.LONG>y.LONG){
        push(s,x);
      }
      else{
        push(s,y);
      }
    }
    else if (has_type(x,DOUBLE) && has_type(y,DOUBLE)){
      if (x.DOUBLE>y.DOUBLE){
        push(s,x);
      }
      else{
        push(s,y);
      }
    }
    else if (has_type(x,CHAR) && has_type(y,CHAR)){
      if (x.CHAR>y.CHAR){
        push(s,x);
      }
      else{
        push(s,y);
      }
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
//fazer o não