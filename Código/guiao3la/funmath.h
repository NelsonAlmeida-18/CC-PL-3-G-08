/**
  *@file Ficheiro que contem protótipos .                                                  
  *\brief Neste ficheiro temos todos os protótipos das funções utilizadas.
  *@date April 2021
 */
void fun_getsnewline(STACK *s);
//STACK
/**
 *\brief Definição dos protótipos relativos à stack.
*/
void underscore(STACK *s);
void barrabarra(STACK *s);
void dollarsign(STACK *s);
void ponto_virgula(STACK *s);
void arroba(STACK *s);

//CONVERSOES
/**
 *\brief Definição dos protótipos relativos às conversões.
*/
void converteInt(STACK *s);
void converteDOUBLE(STACK *s);
void converteCHAR(STACK *s);

//operacoes
/**
 *\brief Definição dos protótipos relativos às operações.
*/
void incrementa(STACK *s);
void decrementa(STACK *s);
void soma(STACK *s);
void subtracao(STACK *s);
void mult(STACK *s);
void resto(STACK *s);
void divisao(STACK *s);
void expon(STACK *s);

//Operaçoes logicas
/**
 *\brief Definição dos protótipos relativos às operações lógicas.
*/
void AMPERSAND(STACK *s);
void XOR(STACK *s);
void NOT(STACK *s);
void OR(STACK *s);