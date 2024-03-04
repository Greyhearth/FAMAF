#include <stdio.h>
// Ejercicio 3.5ah reescrito para usar las funciones del punto 6a y 6b.
int pideEntero(char name);
void imprimeEntero(char name, int x, int i);

int main(void){
    // Declaración e inicialización de variables
    int i = 1;

    // Utilizo las funciones del punto 6a para obtener los valores:
    i = pideEntero('i');

    // Utilizo las funciones del punto 6a para mostrar el estado inicial:
    imprimeEntero('i',i,0);

    // Utilizo las funciones del punto 6a para mostrar los estados intermedios:
    while (i!=0) {
        imprimeEntero('i',i,1);
        i = i - 1;
        imprimeEntero('i',i,2);
    };

    // Utilizo las funciones del punto 6a para mostrar el estado final:
    imprimeEntero('i',i,3);

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
Ejemplo de la ejecución del programa:
    Ingrese un valor para i:
    4
    σ0 : i -> 4
    σ1 : i -> 4
    σ2 : i -> 3
    σ1 : i -> 3
    σ2 : i -> 2
    σ1 : i -> 2
    σ2 : i -> 1
    σ1 : i -> 1
    σ2 : i -> 0
    σ3 : i -> 0
*/