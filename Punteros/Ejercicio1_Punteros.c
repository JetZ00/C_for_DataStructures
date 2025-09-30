#include <stdio.h>

int main(){
  int x = 5;
  int *ptr;

  ptr = &x;

  printf("valor de x = %d\n",x);
  printf("valor de x (por el puntero) = %d\n", *ptr);
  printf("direccion de x = %p\n", ptr);
  printf("direccion de x = %p\n", &x);

  return 0;
  
  // Direccion -> ptr o &x
  // Valor ->     *ptr o x

}