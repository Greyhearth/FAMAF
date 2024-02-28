#include <stdio.h>
#include <stdbool.h>
// Ejercicio 3.1 reescrito para usar las funciones del punto 6a y 6b.
int pideEntero(char name);
void imprimeEntero(char * name, int x);     // Modificada para recibir el String con la operación
void imprimeBooleano(char * name, bool x);  // Modificada para recibir el String con la operación

int main(void){
    // Declaración e inicialización de variables
    int x = 1, y = 1, z = 1;

    // Utilizo la función "pideEntero" del punto 6a para obtener los valores:
    x = pideEntero('x');
    y = pideEntero('y');
    z = pideEntero('z');

    // Utilizo las funciónes del punto 6a y 6b para mostrar los resultados de las operaciones:
    imprimeEntero("x + y + 1", (x + y + 1));
    imprimeEntero("z * z + y * 45 - 15 * x", (z * z + y * 45 - 15 * x));
    imprimeBooleano("y - 2 == (x * 3 + 1) % 5", (y - 2 == (x * 3 + 1) % 5));
    imprimeEntero("y / 2 * x", (y / 2 * x));
    imprimeBooleano("y < x * z", (y < x * z));

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

void imprimeEntero(char * name, int x){
    printf("El resultado de la operacion %s es: %d\n", name, x);
}

void imprimeBooleano(char * name, bool x){
    if (x){
        printf("El resultado de la operacion %s es: verdadero\n", name);
    } else {
        printf("El resultado de la operacion %s es: falso\n", name);
    }
}
/*
Ejecución del programa:
    Ingrese un valor para x:
    7
    Ingrese un valor para y:
    3
    Ingrese un valor para z:
    5
    El resultado de la operacion x + y + 1 es: 11
    El resultado de la operacion z * z + y * 45 - 15 * x es: 55
    El resultado de la operacion y - 2 == (x * 3 + 1) %% 5 es: falso    // Ahora devuelve "verdadero" o "falso"
    El resultado de la operacion y / 2 * x es: 7
    El resultado de la operacion y < x * z es: verdadero
Con otros valores:
    Ingrese un valor para x:
    1
    Ingrese un valor para y:
    10
    Ingrese un valor para z:
    8
    El resultado de la operacion x + y + 1 es: 12
    El resultado de la operacion z * z + y * 45 - 15 * x es: 499
    El resultado de la operacion y - 2 == (x * 3 + 1) % 5 es: falso
    El resultado de la operacion y / 2 * x es: 5
    El resultado de la operacion y < x * z es: falso
*/