#include <stdio.h>
// Ejercicio 3.5b1 reescrito para usar las funciones del punto 6a y 6b.
int pideEntero(char name);
void imprimeEntero(char a, int b, char c, int d, char e, int f, int i);

int main(void){
    // Declaración e inicialización de variables
    int x = 1, y = 1, i = 1;

    // Utilizo las funciones del punto 6a para obtener los valores:
    x = pideEntero('x');
    y = pideEntero('y');
    i = pideEntero('i');

    // Utilizo las funciones del punto 6a para mostrar el estado inicial:
    imprimeEntero('x', x, 'y', y, 'i', i, 0);
    i = 0;

    // Utilizo las funciones del punto 6a para mostrar el estado final de cada ciclo:
    while (x>y) {
        x = x - y;
        i = i + 1;
        imprimeEntero('x', x, 'y', y, 'i', i, i);
    }

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

void imprimeEntero(char a, int b, char c, int d, char e, int f, int i){
    printf("σ%d : (%c -> %d, %c -> %d, %c -> %d)\n", i,a,b,c,d,e,f);
}
/*
Ejemplo del programa ejecutado con los valores del proyecto:
    Ingrese un valor para x:
    13
    Ingrese un valor para y:
    3
    Ingrese un valor para i:
    0
    σ0 : (x -> 13, y -> 3, i -> 0)
    σ1 : (x -> 10, y -> 3, i -> 1)
    σ2 : (x -> 7, y -> 3, i -> 2)
    σ3 : (x -> 4, y -> 3, i -> 3)
    σ4 : (x -> 1, y -> 3, i -> 4)
*/