#include <stdio.h>
// Ejercicio 3.3b reescrito para usar las funciones del punto 6a y 6b.
int pideEntero(char name);
void imprimeEntero(char a, int b, char c, int d, int i);

int main(void){
    // Declaración e inicialización de variables
    int x = 1, y = 1;

    // Utilizo las funciones del punto 6a para obtener los valores:
    x = pideEntero('x');
    y = pideEntero('y');

    // Utilizo las funciones del punto 6a para mostrar los estados intermedios:
    imprimeEntero('x', x, 'y', y, 0);
    x = x + y;
    imprimeEntero('x', x, 'y', y, 1);
    y = y + y;
    
    // Utilizo las funciones del punto 6a para mostrar el estado final:
    imprimeEntero('x', x, 'y', y, 2);

    return 0;
}

int pideEntero(char name){
    // Declaración e inicialización de variables
    int y;

    // Solicitar al usuario un entero
    printf("Ingrese un valor para %c:\n",name); 
    scanf("%d", &y);

    // Devuelve la variable con un valor 'int' para ser usado luego
    return y;
}

void imprimeEntero(char a, int b, char c, int d, int i){
    printf("σ%d : (%c -> %d, %c -> %d)\n", i,a,b,c,d);
}
/*
Ejemplo de ejecución del programa:
    Ingrese un valor para x:
    1
    Ingrese un valor para y:
    5
    σ0 : (x -> 1, y -> 5)
    σ1 : (x -> 6, y -> 5)
    σ2 : (x -> 6, y -> 10)
*/