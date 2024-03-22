// Ejercicio 13
// Importo "stdio.h" para usar "printf"/"scanf", "assert.h" para usar "assert" y "limits.h" para usar los neutros de "max/min".
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#define N 5 // defino el largo del arreglo como constante.

/* Definición de la estructura en C */
struct datos_t
{
    float maximo;
    float minimo;
    float promedio;
};

// Declarar el prototipo de las funciones antes de "main" para facilitar la lectura del código.
void pedir_arreglo(int n_max, float a[]);
struct datos_t stats(int tam, float a[]);
void imprime_struct(struct datos_t p);

// Luego se declara la función main.
int main(void)
{
    // Declaro "a" como array con un largo según el valor de "N".
    float a[N];

    // Uso assert para verificar la precondición. El largo de un arreglo debe ser mayor a 0.
    assert(N > 0);

    pedir_arreglo(N, a);

    imprime_struct(stats(N, a));

    return 0;
};

// Función que le pide al usuario un valor para cada entrada del arreglo.
void pedir_arreglo(int n_max, float a[])
{
    int i = 0;
    while (i < n_max)
    {
        printf("ingrese el elemento %d del arreglo:\n", i);
        scanf("%f", &a[i]);
        i = i + 1;
    }
};

// Función que calcula los elementos maximo y minimo de un arreglo, además del promedio.
struct datos_t stats(int tam, float a[])
{
    int i = 0;
    float suma = 0;
    struct datos_t stats;
    stats.maximo = INT_MIN;
    stats.minimo = INT_MAX;
    stats.promedio = 0;
    while (i < tam)
    {
        if (a[i] > stats.maximo)
        {
            stats.maximo = a[i];
        }
        else
        {
        };
        if (a[i] < stats.minimo)
        {
            stats.minimo = a[i];
        }
        else
        {
        };
        suma = suma + a[i];
        i = i + 1;
    };
    stats.promedio = suma / tam;
    return stats;
}

// Función que imprime el cociente y resto de la división.
void imprime_struct(struct datos_t p)
{
    printf("\nEl elemento máximo es: %f\nEl elemento mínimo es: %f\nEl promedio es: %f\n", p.maximo, p.minimo, p.promedio);
}

// Pruebas de Ejecución:
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

    // El elemento máximo es: 5.000000
    // El elemento mínimo es: 1.000000
    // El promedio es: 3.000000