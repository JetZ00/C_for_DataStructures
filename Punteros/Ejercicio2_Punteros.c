#include <stdio.h>

void swap(int* x, int* y){
int temp;
temp = *x;
*x = *y;
*y = temp;
}

int main(){

  int x = 5;
  int y = 8;

  printf("\nLos punteros al normal son: ptr=%p y ptr2= %p \n\n",x,y);

  swap(&x,&y);

  printf("Los punteros intercambiados son: ptr=%p y ptr2= %p \n\n",x,y);

  // Direccion -> ptr o &x
  // Valor ->     *ptr o x

}