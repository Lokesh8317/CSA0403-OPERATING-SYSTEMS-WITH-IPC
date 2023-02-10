#include <stdio.h>
#include <stdlib.h>

int main() {
  
  int static_var = 20;
  printf("Static variable: %d\n", static_var);
  
  int auto_var;
  auto_var = 10;
  printf("Automatic variable: %d\n", auto_var);
  
  int *dynamic_var;
  dynamic_var = (int *) malloc(sizeof(int));
  *dynamic_var = 30;
  printf("Dynamic variable: %d\n", *dynamic_var);
  
  dynamic_var = (int *) realloc(dynamic_var, 2 * sizeof(int));
  *(dynamic_var + 1) = 40;
  printf("Reallocated dynamic variable 1: %d\n", *dynamic_var);
  printf("Reallocated dynamic variable 2: %d\n", *(dynamic_var + 1));
  
  free(dynamic_var);
  
  return 0;
}

