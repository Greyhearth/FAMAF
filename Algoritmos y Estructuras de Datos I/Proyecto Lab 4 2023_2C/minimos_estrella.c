// Ejercicio 10
// Importo "stdio.h" para usar "printf"/"scanf" y "limits.h" para usar los neutros de "max/min".
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#define N 5 // defino el largo del arreglo como constante.

// Declarar el prototipo de las funciones antes de "main" para facilitar la lectura del código.
void pedir_arreglo(int n_max, int a[]);
int minimo_pares(int tam, int a[]);
int minimo_impares(int tam, int a[]);
int minimo_abs(int a, int b);

// Luego se declara la función main.
int main(void)
{
    // Declaro "a" como array con un largo según el valor de "N".
    int a[N], par, imp, minimo;

    // Uso assert para verificar la precondición. El largo de un arreglo debe ser mayor a 0.
    assert(N > 0);

    pedir_arreglo(N, a);

    par = minimo_pares(N, a);
    imp = minimo_impares(N, a);

    minimo = minimo_abs(par, imp);

    if (par!=INT_MAX)
    {
        printf("El mínimo elemento par del arreglo es: %d\n", par);
    }
    if (imp!=INT_MAX)
    {
        printf("El mínimo elemento impar del arreglo es: %d\n", imp);
    }
    printf("El mínimo elemento, en general, del arreglo es: %d\n", minimo);

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

// Función que determina el minimo par del arreglo.
int minimo_pares(int tam, int a[])
{
    int i = 0, minimo = INT_MAX;
    while (i < tam)
    {
        if ((a[i] % 2 == 0) && a[i] < minimo)
        {
            minimo = a[i];
            i = i + 1;
        }
        else
        {
            i = i + 1;
        }
    }
    return minimo;
};

// Función que determina el minimo impar del arreglo.
int minimo_impares(int tam, int a[])
{
    int i = 0, minimo = INT_MAX;
    while (i < tam)
    {
        if ((a[i] % 2 != 0) && a[i] < minimo)
        {
            minimo = a[i];
            i = i + 1;
        }
        else
        {
            i = i + 1;
        }
    }
    return minimo;
};

// Función que determina el minimo entre ambos valores.
int minimo_abs(int a, int b)
{
    int minimo = INT_MAX;
    if (a < b)
    {
        minimo = a;
    }
    else
    {
        minimo = b;
    }
    return minimo;
}

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
    // El mínimo elemento par del arreglo es: 2
    // El mínimo elemento impar del arreglo es: 1
    // El mínimo elemento, en general, del arreglo es: 1


    // ingrese el elemento 0 del arreglo:
    // 0
    // ingrese el elemento 1 del arreglo:
    // 2
    // ingrese el elemento 2 del arreglo:
    // 4
    // ingrese el elemento 3 del arreglo:
    // 6
    // ingrese el elemento 4 del arreglo:
    // 8
    // El mínimo elemento par del arreglo es: 0
    // El mínimo elemento, en general, del arreglo es: 0