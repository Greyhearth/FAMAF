// Ejercicio 1b - Mínimo

// ...pre y post condición y su derivación.
//      Var x, y, res : Int;
//  { P: x = X ∧ y = Y } (X e Y son variables de especificación)
//      if x ≥ y → res := y
//      [] x ≤ y → res := x
//      fi
//  { Q: res = X min Y }

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
    int x, y, X, Y, res;

    // Solicito al usuario ingresar un valor a "x" e "y"
    x = pideEntero('x');
    y = pideEntero('y');

    // Uso variables auxiliares para que Assert simule la precondición.
    X = x;
    Y = y;

    // Assert controla la precondición
    assert(x == X && y == Y);

    if (x >= y)
    {
        res = y;
    }
    else if (x < y)
    {
        res = x;
    }

    // Assert controla la postcondición
    assert((res==X && res<=Y)||(res==Y && res<=X));

    printf("\nEl valor mínimo es: %d\n", res);

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
    // 6
    // Ingrese un valor para y:
    // 3

    // El valor mínimo es: 3