// Ejercicio 7
// Importo "stdio.h" para usar "printf"/"scanf" y "assert.h" para usar "assert".
#include <stdio.h>
#include <assert.h>
#define N 5 // La consigna aclara "asumiendo un tamaño constante previamente establecido"

// Declarar el prototipo de las funciones antes de "main" para facilitar la lectura del código.
void pedir_arreglo(int n_max, int a[]);
int sumatoria(int tam, int a[]);

// Luego se declara la función main.
int main(void)
{
    // Declaro "a" como array con un largo según el valor constante de "N".
    int resultado, a[N];

    // Uso assert para verificar la precondición. El largo de un arreglo debe ser mayor a 0.
    assert(N > 0);

    resultado = 0;
    // Precondición: resultado debe iniciar en 0.
    assert(resultado == 0);

    pedir_arreglo(N, a);
    resultado = sumatoria(N, a);

    // Postcondición: resultado debe valer lo mismo que lo que devuelve la función "sumatoria".
    assert(resultado == sumatoria(N, a));

    printf("El resultado de sumar todas las entradas del arreglo es: %d\n", resultado);

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

// Función que suma todas las entradas del arreglo.
int sumatoria(int tam, int a[])
{
    int resultado = 0, i = 0;
    while (i < tam)
    {
        resultado = resultado + a[i];
        i = i + 1;
    }
    return resultado;
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
// El resultado de sumar todas las entradas del arreglo es: 15