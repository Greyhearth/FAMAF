// Ejercicio 9
// Importo "stdio.h" para usar "printf"/"scanf" y "assert.h" para usar "assert".
#include <stdio.h>
#include <assert.h>
#define N 5 // defino el largo del arreglo como constante.

// Declarar el prototipo de las funciones antes de "main" para facilitar la lectura del código.
void pedir_arreglo(int n_max, int a[]);
void imprimir_arreglo(int n_max, int a[]);
void intercambiar(int tam, int a[], int i, int j);
int pideEntero(int n, char *name);

// Luego se declara la función main.
int main(void)
{
    // Declaro "a" como array con un largo según el valor de "N".
    int a[N], i, j;

    // Uso assert para verificar la precondición. El largo de un arreglo debe ser mayor a 0.
    assert(N > 0);

    pedir_arreglo(N, a);

    i = pideEntero(N, "primera");
    j = pideEntero(N, "segunda");

    assert(i < N && i >= 0 && j < N && j >= 0); // verifica que tanto "i" como "j" esten en rango válido.

    intercambiar(N, a, i, j);

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
    printf("\nEl arreglo modificado es:\n");
    while (i < n_max)
    {
        printf(" El elemento en posición %d es %d\n", i, a[i]);
        i = i + 1;
    }
};

// Función que intercambia los valores dadas 2 posiciones de un arreglo.
void intercambiar(int tam, int a[], int i, int j)
{
    assert(i < tam && i >= 0 && j < tam && j >= 0); // verifica que tanto "i" como "j" esten en rango válido.
    int aux;                                        // variable auxiliar
    aux = a[i];                                     // guardo 1 de los valores en la variable auxiliar.
    a[i] = a[j];
    a[j] = aux;
};

// ...función que le pide un entero al usuario y lo devuelve.
int pideEntero(int n, char *name)
{
    // Declaración e inicialización de variables
    int y;

    // Solicitar al usuario un entero
    printf("Ingrese la %s posición a intercambiar (debe ser un entero entre 0 y %d):\n", name, n - 1);
    scanf("%d", &y);

    // Devuelve la variable con un valor 'int' para ser usado luego
    return y;
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
    // Ingrese la primera posición a intercambiar (debe ser un entero entre 0 y 4):
    // 0
    // Ingrese la segunda posición a intercambiar (debe ser un entero entre 0 y 4):
    // 4

    // El arreglo modificado es:
    // El elemento en posición 0 es 1
    // El elemento en posición 1 es 4
    // El elemento en posición 2 es 3
    // El elemento en posición 3 es 2
    // El elemento en posición 4 es 5