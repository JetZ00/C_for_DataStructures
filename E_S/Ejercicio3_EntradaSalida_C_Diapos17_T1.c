#include <stdio.h>

/*
Consulta cómo funciona la entrada de datos por teclado, scanf e implementa
el ejercicio de antes pero leyendo los datos por teclado.
*/

int main() {

  int a,b;
  printf("Introduce dos números enteros separados por espacio: ");

  scanf("%d", &a);
  scanf("%d", &b);

  int suma = a + b;
  printf("%d\n", suma);

  return 0;
}

/*
APUNTES

scanf("%d", &numero);  Lee un número entero y lo almacena en la variable 'numero'.
                       El '&' es necesario para pasar la dirección de memoria de la variable.
                       El "%d" es necesario para indicar el valor esperado

*/