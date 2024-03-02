#include <stdio.h>
// Ejercicio 3.4a reescrito para usar las funciones del punto 6a.
int pideEntero(char name);
void imprimeEntero(char a, int b, char c, int d, int i);    // Modificada para aceptar más parámetros y poder imprimir el mismo mensaje que en el punto 4a.

int main(void){
    // Declaración e inicialización de variables
    int x = 1, y = 1;

    // Utilizo la función "pideEntero" del punto 6a para obtener los valores:
    x = pideEntero('x');
    y = pideEntero('y');

    // Utilizo la función "imprimeEntero" del punto 6a mostrar por pantalla el estado inicial "σ0". 
    imprimeEntero('x', x, 'y', y, 0);

    // Utilizo la función "imprimeEntero" del punto 6a mostrar por pantalla los estados intermedios "σ1" y "σ2". 
    if (x>=y) {
        imprimeEntero('x', x, 'y', y, 1);
        x = 0;
        imprimeEntero('x', x, 'y', y, 2);
    } else {
        imprimeEntero('x', x, 'y', y, 1);
        x = 2;
        imprimeEntero('x', x, 'y', y, 2);
    }
   
    // Utilizo la función "imprimeEntero" del punto 6a mostrar por pantalla el estado final "σ3". 
    imprimeEntero('x', x, 'y', y, 3);

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
Ejemplos de su ejecución:
    Ingrese un valor para x:
    1
    Ingrese un valor para y:
    4
    σ0 : (x -> 1, y -> 4)
    σ1 : (x -> 1, y -> 4)
    σ2 : (x -> 2, y -> 4)
    σ3 : (x -> 2, y -> 4)
Con otros valores:
    Ingrese un valor para x:
    5 
    Ingrese un valor para y:
    3
    σ0 : (x -> 5, y -> 3)
    σ1 : (x -> 5, y -> 3)
    σ2 : (x -> 0, y -> 3)
    σ3 : (x -> 0, y -> 3)
*/