#include <stdio.h>

/*
Implementar un programa que inicialice dos variables enteras y muestre por pantalla la suma de éstas.
*/

int main(){
  int a = 2;
  int b = 3;
  int suma = a + b;
  printf("%d", suma);

  return 0;
}

/*
APUNTES

printf("%d\n", suma); // Imprime el número y salta de línea

printf("%d", suma);   // Imprime el número y NO salta de línea

IMPORTANTE -> "%d" es un especificador de formato que indica que se va a imprimir o se espera leer un número entero (int).

*/