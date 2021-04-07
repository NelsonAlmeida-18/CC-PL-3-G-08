#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "stack.h"
#include "parser.h"

int main(void) {
  char line[10240];
  assert(fgets(line,10240,stdin)!=NULL);
  assert(line[strlen(line)-1]=='\n');
  parse(line);
  return 0;
}