#define SIZE 10240
typedef struct {
  long array[SIZE]; 
  int pos;
} STACK;

STACK criar_stack();
void print_stack(STACK s);

#define push(s, val)        \
   s.array[s.pos++] = val;

#define pop(s)              \
  s.array[--s.pos]

