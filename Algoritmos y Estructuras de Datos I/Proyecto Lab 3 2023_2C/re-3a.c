#include <stdio.h>
// Ejercicio 3.3a reescrito para usar las funciones del punto 6a y 6b.
int pideEntero(char name);
void imprimeEntero(char name, int x, int i);

int main(void){
    // Declaración e inicialización de variables
    int x = 1;

    // Utilizo las funciones del punto 6a para obtener los valores:
    x = pideEntero('x');

    // Utilizo las funciones del punto 6a para mostrar los estados intermedios:
    imprimeEntero('x', x, 0);
    x = 5;

    // Utilizo las funciones del punto 6a para mostrar el estado final:
    imprimeEntero('x', x, 1);

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

void imprimeEntero(char name, int x, int i){
    printf("σ%d : %c -> %d\n", i,name,x);
}

/*
Ejemplo de ejecución del programa:
    Ingrese un valor para x:
    1
    σ0 : x -> 1
    σ1 : x -> 5
*/