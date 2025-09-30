#include <stdio.h>

/*
Implementar un programa que inicialice dos variables, una de tipo carácter y otra cadena de caracteres y lo muestre por pantalla.
*/

int main(){
    int a = 2;
    char b [] = "Hola";
    printf("%d %s\n", a, b);
    return 0;

}

/*
APUNTES

%d -> Especificador de formato para enteros (int)
%s -> Especificador de formato para cadenas de caracteres (strings)
%c -> Especificador de formato para un solo carácter (char)
%f -> Especificador de formato para números de punto flotante (float)

*/