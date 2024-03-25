// Ejercicio 15
// Importo "stdio.h" para usar "printf"/"scanf", "assert.h" para usar "assert" y "stdbool.h" para usar el tipo "bool".
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// Declarar el prototipo de las funciones antes de "main" para facilitar la lectura del código.
int pideEntero();
int nesimo_primo(int N);
bool es_primo(int x);

// Luego se declara la función main.
int main(void)
{
    int n, nPrimo;

    n = pideEntero();

    while (n <= 0)
    {
        printf("\nError, el número debe ser mayor que 0.\n");
        n = pideEntero();
    }
    assert(n > 0);

    nPrimo = nesimo_primo(n);

    printf("\nEl %d-ésimo primo es: %d\n", n, nPrimo);

    return 0;
};

// ...función que le pide un entero al usuario y lo devuelve.
int pideEntero()
{
    // Declaración e inicialización de variables
    int y;

    // Solicitar al usuario un entero
    printf("\nIngrese un entero mayor que 0:\n");
    scanf("%d", &y);

    // Devuelve la variable con un valor 'int' para ser usado luego
    return y;
}

// Función que devuelve el n-ésimo primo, según el "n" ingresado por usuario.
int nesimo_primo(int N)
{
    int contPrimos = 0, nPrimo = 0, i = 0; // "contPrimos" e "i" son contadores. "nPrimo" guarda el valor del primo buscado.
    while (contPrimos < N)
    {
        if (i > 2)
        {
            if (es_primo(i))
            {
                contPrimos = contPrimos + 1;
                nPrimo = i;
            }
        }
        else if (i == 2)
        {
            contPrimos = contPrimos + 1;
            nPrimo = i;
        };
        i = i + 1;
    }
    return nPrimo;
};

// Función que verifica si "x" es primo.
bool es_primo(int x)
{
    int i = 2;           // variable que sirve para verificar la división por todos los numeros menores que "x".
    bool esPrimo = true; // se inicializa en true por ser el elemento neutro de la conjunción.
    while (i < x)
    {
        esPrimo = esPrimo && (x % i != 0);
        i = i + 1;
    }
    return esPrimo;
};

// Prueba de Ejecución:
    // Ingrese un entero mayor que 0:
    // 1

    // El 1-ésimo primo es: 2


    // Ingrese un entero mayor que 0:
    // 2

    // El 2-ésimo primo es: 3


    // Ingrese un entero mayor que 0:
    // 3

    // El 3-ésimo primo es: 5


    // Ingrese un entero mayor que 0:
    // 4

    // El 4-ésimo primo es: 7


    // Ingrese un entero mayor que 0:
    // 5

    // El 5-ésimo primo es: 11


    // Ingrese un entero mayor que 0:
    // 6

    // El 6-ésimo primo es: 13