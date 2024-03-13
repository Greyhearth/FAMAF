// Ejercicio 6
// Importo "stdio.h" para usar "printf"/"scanf" y "assert.h" para usar "assert".
#include <stdio.h>
#include <assert.h>
#define N 5 // defino el largo del arreglo como constante.

// Declarar el prototipo de las funciones antes de "main" para facilitar la lectura del código.
void pedir_arreglo(int n_max, int a[]);
void imprimir_arreglo(int n_max, int a[]);

// Luego se declara la función main.
int main(void)
{
    // Declaro "a" como array con un largo según el valor de "N".
    int a[N];
    
    // Uso assert para verificar la precondición. El largo de un arreglo debe ser mayor a 0.
    assert(N > 0);

    pedir_arreglo(N, a);
    imprimir_arreglo(N, a);

    return 0;
};

// Función que le pide al usuario un valor para cada entrada del arreglo.
void pedir_arreglo(int n_max, int a[])
{
    int i = 0;
    while (i < n_max)
    {
        printf("ingrese el elemento %d del arreglo:\n", i);
        scanf("%d", &a[i]);
        i = i + 1;
    }
};

// Función que imprime todas las entradas del arreglo.
void imprimir_arreglo(int n_max, int a[])
{
    int i = 0;
    printf("\nEl arreglo ingresado:\n");
    while (i < n_max)
    {
        printf(" El elemento en posición %d es %d\n", i, a[i]);
        i = i + 1;
    }
};

// Prueba de Ejecución:
// ingrese el elemento 0 del arreglo:
// 5
// ingrese el elemento 1 del arreglo:
// 4
// ingrese el elemento 2 del arreglo:
// 3
// ingrese el elemento 3 del arreglo:
// 2
// ingrese el elemento 4 del arreglo:
// 1

// El arreglo ingresado:
//  El elemento en posición 0 es 5
//  El elemento en posición 1 es 4
//  El elemento en posición 2 es 3
//  El elemento en posición 3 es 2
//  El elemento en posición 4 es 1