#include <stdio.h>

/*
Implementar un algoritmo que lea una serie de números, los almacene en un array y muestre la media de esos números
*/

int main(){

  printf("\n Indique el número de elementos a introducir: ");
  int n;
  scanf("%d", &n);

  int numeros[n];
  int sumatotal = 0;

  for(int i=0;i<n;i++){
    int num;
    printf("Introduce el número %d: ", i);
    scanf("%d", &num);
    numeros[i] = num;

    sumatotal += num;
  }

  double media = sumatotal / n;

  printf("La media de los números es: %f", media);

  return 0;

}