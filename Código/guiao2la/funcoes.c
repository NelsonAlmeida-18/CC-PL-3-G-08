#include <stdio.h>
#include <string.h>
#include "stack.h"

void converteInt(STACK *s){
	if(has_type(top(s),DOUBLE)){
		double x = pop_DOUBLE(s);
		int a = (int)x;
		printf("%d\n",a);
		push_LONG(s,a);
	}
	if(has_type(top(s),CHAR)){
		char x = pop_CHAR(s);
		int a = (int)x;
		push_LONG(s,a);
	}
	//rever com o prof
	/*
	if(has_type(top(s),STRING)){
		int acc=0,pos=0;
		char line=pop_CHAR(s);
		while(pos<strlen(line)){
			char a = pop_CHAR(s);
			int l = (int)a;
			acc+=l;
			pos+=1;
		}
		push_LONG(s,acc);
	}
	*/
}

//não está a somar?
void soma(STACK *s){
	if(has_type(top(s),LONG)){
		long x = pop_LONG(s);
		if(has_type(top(s),LONG)){
			long y = pop_LONG(s);
			push_LONG(s,y+x);
		}
		if(has_type(top(s),DOUBLE)){
			double y = pop_DOUBLE(s);
			double a = (double)y;
			push_DOUBLE(s,a+x);
		}
		if(has_type(top(s),CHAR)){
			char y = pop_CHAR(s);
			long a = (long)y;
			push_LONG(s,a+x);
		}
	}
}