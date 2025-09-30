#include <stdio.h>

int main(){

  int a[5] = {0,1,2,3,4};
  int *ptr;

  ptr = a; //Asignamos la direccion del primer elemento del array al puntero

  for(int i=0; i<5; i++){
    printf("El valor del elemento %d del array es: %d\n", i, *(ptr + i));
  }

  return 0;
}