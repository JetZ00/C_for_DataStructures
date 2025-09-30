#include <stdio.h>

#define N 3

/*
Definir dos matrices de 3x3, realizar la suma y mostrar por pantalla
*/

int main() {
    int matriz[N][N] = {{1,2,3},{4,5,6},{7,8,9}};
    int matriz2[N][N] = {{9,8,7},{6,5,4},{3,2,1}};
    int suma[N][N];

    for(int i=0; i<N;i++){
      for(int j=0; j<N;j++){
        suma[i][j] = matriz[i][j] + matriz2[i][j];
      }
    }

    printf("\nMatriz Resultante:\n\n");
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        printf("%d ", suma[i][j]);
      }
      printf("\n");
    }

    return 0;

}