// Ejercicio 1b - Intercambio

// ...pre y post condición y su derivación.
//      Var x, y : Int ;
//  { P: x = X ∧ y = Y }
//      x, y := y , x
//  { Q: x = X ∧ y = Y }

// Adaptación con asignaciones simples:
//      Var x, y, aux : Int ;
//  { P: x = X ∧ y = Y }
//      aux := x ;
//      x := y ;
//      y := aux
//  { Q: x = X ∧ y = Y }

// Traducción a C.
// Importo "stdio.h" para usar "printf"/"scanf" y "assert.h" para usar "assert".
#include <stdio.h>
#include <assert.h>

// Declarar el prototipo de las funciones antes de "main" para facilitar la lectura del código.
int pideEntero(char letra);

// Luego se declara la función main.
int main(void)
{
    // Declaro variables y constantes.
    int x, y, X, Y, aux;

    // Solicito al usuario ingresar un valor a "x"
    x = pideEntero('x');
    y = pideEntero('y');

    // Uso variables auxiliares para que Assert simule la precondición.
    X = x;
    Y = y;

    // Assert controla la precondición
    assert(x == X && y == Y);

    aux = x;
    x = y;
    y = aux;

    // Assert controla la postcondición
    assert(x==Y && y==X);

    printf("\nEl valor de x ahora es: %d\nEl valor de y ahora es: %d\n", x,y);

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
    // 6

    // El valor de x ahora es: 6
    // El valor de y ahora es: 4