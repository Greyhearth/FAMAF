// Ejercicio 2a y 2b

//  {Pre: x = X, y = Y}
//  x, y := x + 1, x + y
//  {Post: x = X + 1, y = X + Y}

// Programa equivalente con asignaciones simples:

//  {Pre: x = X, y = Y, auxX = X}
//  auxX := x;
//  x := x + 1;
//  y := auxX + y;
//  {Post: x = X + 1, y = X + Y, auxX = X}

// Importo "stdio.h" para usar "printf"/"scanf".
#include <stdio.h>
#include <assert.h>

// Declarar el prototipo de las funciones antes de "main" para facilitar la lectura del código.
int pideEntero(char letra);

// Luego se declara la función main.
int main(void)
{
    // Declaro e inicializo las variables.
    int x, X, y, Y, aux;

    // Solicito al usuario que ingrese el valor de ambas variables.
    x = pideEntero('x');
    y = pideEntero('y');

    // Le asigno a la variable auxiliar el valor de "x" para guardarlo.
    aux = x;

    // Asigno los valores en "X" e "Y" para usarlos en Assert
    X = x;
    Y = y;

    // Assert controla la precondición
    assert(x == X && y == Y);

    // Asignaciones según el programa:
    x = x + 1;   // Como el valor de "x" cambia, no puedo usarlo en la asignación de "y".
    y = aux + y; // La variable auxiliar tiene el valor original de "x"

    // Assert controla la postcondición
    assert(x == (X + 1) && y == (X + Y));

    // Muestra por pantalla el estado final de las variables:
    printf("El valor de x es %d, el valor de y es %d:\n", x, y);

    return 0;
};

// Función que le pide un entero al usuario y lo devuelve.
int pideEntero(char letra)
{
    int x;
    printf("Ingrese un valor para %c:\n", letra);
    scanf("%d", &x);
    return x;
};

// Prueba de ejecución:
// Ingrese un valor para x:
// 4
// Ingrese un valor para y:
// 7
// El valor de x es 5, el valor de y es 11: