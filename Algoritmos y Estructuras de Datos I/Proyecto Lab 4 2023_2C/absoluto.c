// Ejercicio 1b - Valor Absoluto

// ...pre y post condición y su derivación.
//      Var x : Int
//  { P: x = X } (X es una variable de especificación)
//      if x ≥ 0 → skip
//      ⌷ x < 0 → x := -x
//      fi
//  { Q: x = X v x = -X }

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
    int x, X;

    // Solicito al usuario ingresar un valor a "x"
    x = pideEntero('x');

    // Uso variables auxiliares para que Assert simule la precondición.
    X = x;

    // Assert controla la precondición
    assert(x == X);

    if (x >= 0)
    {

    }
    else if (x < 0)
    {
        x = -x;
    }

    // Assert controla la postcondición
    assert((x==X)||(x==-X));

    printf("\nEl valor aboluto del numero ingresado es: %d\n", x);

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

    // El valor aboluto del numero ingresado es: 4

    // Ingrese un valor para x:
    // 0    

    // El valor aboluto del numero ingresado es: 0

    // Ingrese un valor para x:
    // -5

    // El valor aboluto del numero ingresado es: 5