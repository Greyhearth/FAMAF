// Ejercicio 6
// Importo "stdio.h" para usar "printf"/"scanf" y "assert.h" para usar "assert".
#include <stdio.h>
#include <assert.h>
#define N 5 // defino el largo del arreglo como constante.

// Declarar el prototipo de las funciones antes de "main" para facilitar la lectura del código.
void pedir_arreglo(int tam, int a[]);
int prim_iguales(int tam, int a[]);
void imprimir_arreglo(int n_max, int a[]);

// Luego se declara la función main.
int main(void)
{
    // Declaro "a" como array con un largo según el valor de "N".
    int largo, a[N];

    // Uso assert para verificar la precondición. El largo de un arreglo debe ser mayor a 0.
    assert(N > 0);

    pedir_arreglo(N, a);

    largo = prim_iguales(N, a);

    printf("\nLa longitud del segmento inicial cuyos elementos son iguales es: %d\n", largo);
    imprimir_arreglo(largo, a);

    return 0;
};

// Función que le pide al usuario un valor para cada entrada del arreglo.
void pedir_arreglo(int tam, int a[])
{
    int i = 0;
    while (i < tam)
    {
        printf("ingrese el elemento %d del arreglo:\n", i);
        scanf("%d", &a[i]);
        i = i + 1;
    }
};

// Función que verifica la cadena de elementos iguales inicial más larga.
int prim_iguales(int tam, int a[])
{
    assert(tam > 0);
    int i = 0;
    while (a[0] == a[i])
    {
        i = i + 1;
    }
    return i;
};

// Función que imprime las entradas indicadas del arreglo.
void imprimir_arreglo(int tam, int a[])
{
    int i = 0;
    printf("\nEl segmento inicial cuyos elementos son iguales es:\n");
    while (i < tam)
    {
        printf(" El elemento en posición %d es %d\n", i, a[i]);
        i = i + 1;
    }
};

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

    // La longitud del segmento inicial cuyos elementos son iguales es: 1

    // El segmento inicial cuyos elementos son iguales es:
    //  El elemento en posición 0 es 5


    // ingrese el elemento 0 del arreglo:
    // 5
    // ingrese el elemento 1 del arreglo:
    // 5
    // ingrese el elemento 2 del arreglo:
    // 5
    // ingrese el elemento 3 del arreglo:
    // 4
    // ingrese el elemento 4 del arreglo:
    // 3

    // La longitud del segmento inicial cuyos elementos son iguales es: 3

    // El segmento inicial cuyos elementos son iguales es:
    //  El elemento en posición 0 es 5
    //  El elemento en posición 1 es 5
    //  El elemento en posición 2 es 5