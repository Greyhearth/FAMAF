#include <stdio.h>
#include <stdbool.h>
// Ejercicio 3.2 reescrito para usar las funciones del punto 6a y 6b.
int pideEntero(char name);
bool pedirBooleano(char name);
void imprimeBooleano(char * name, bool x);  // Modificada para recibir el String con la operación

int main(void){
    // Declaración e inicialización de variables
    int x = 1, y = 1, z = 1;    // Ya no hace falta declarar en main las variables 'temp'.
    bool b = false, w = false;

    // Utilizo las funciones del punto 6a y 6b para obtener los valores:
    x = pideEntero('x');
    y = pideEntero('y');
    z = pideEntero('z');
    b = pedirBooleano('b');
    w = pedirBooleano('w');

    // Utilizo las funciones del punto 6a y 6b para mostrar los resultados:
    imprimeBooleano("x % 4 == 0", (x % 4 == 0));
    imprimeBooleano("x + y == 0 && y - x == (-1) * z", (x + y == 0 && y - x == (-1) * z));
    imprimeBooleano("!(b && w)", (!(b && w)));

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

bool pedirBooleano(char name){
    // Declaración e inicialización de variables. 'temp' es una variable intermediaria para asignar el valor booleano a 'y'.
    int temp = 1;
    bool y = false;

    // Solicitar al usuario un número entre 0 (falso) y 1 (verdadero)
    printf("Ingrese un valor para %c (elija 1 para 'verdadero' o 0 para 'falso'):\n",name); 
    scanf("%d", &temp); // 'temp' recibe un entero

    y = temp;   // Al asignarlo, "y" recibe su equivalente en booleano.

    // Devuelve la variable con un valor 'bool' para ser usado luego
    return y;
}

void imprimeBooleano(char * name, bool x){
    if (x){
        printf("El resultado de la operacion %s es: verdadero\n", name);
    } else {
        printf("El resultado de la operacion %s es: falso\n", name);
    }
}
/*
Ejemplo de ejecución del programa:
    Ingrese un valor para x:
    4
    Ingrese un valor para y:
    -4
    Ingrese un valor para z:
    8
    Ingrese un valor para b (elija 1 para 'verdadero' o 0 para 'falso'):
    1
    Ingrese un valor para w (elija 1 para 'verdadero' o 0 para 'falso'):
    1
    El resultado de la operacion x % 4 == 0 es: verdadero                       // Ahora los booleanos muestran el mensaje 'verdadero' y 'falso'
    El resultado de la operacion x + y == 0 && y - x == (-1) * z es: verdadero
    El resultado de la operacion !(b && w) es: falso
*/