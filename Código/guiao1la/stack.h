#define SIZE 10240
typedef struct {
  long array[SIZE]; 
  int pos;
} STACK;

STACK criar_stack();
void print_stack(STACK s);
long POP(STACK s);
void PUSH(STACK s,long val);
