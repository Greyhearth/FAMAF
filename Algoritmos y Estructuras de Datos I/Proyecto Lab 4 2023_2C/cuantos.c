// Ejercicio 12
// Importo "stdio.h" para usar "printf"/"scanf" y "assert.h" para usar "assert".
#include <stdio.h>
#include <assert.h>
#define N 5 // defino el largo del arreglo como constante.

/* Definición de la estructura en C */
struct comp_t {
    int menores;
    int iguales;
    int mayores;
};

// Declarar el prototipo de las funciones antes de "main" para facilitar la lectura del código.
void pedir_arreglo(int n_max, int a[]);
int pideEntero();
struct comp_t cuantos(int tam, int a[], int elem);
void imprime_struct(int a, struct comp_t p);

// Luego se declara la función main.
int main(void)
{
    // Declaro "a" como array con un largo según el valor de "N".
    int a[N], elem;

    // Uso assert para verificar la precondición. El largo de un arreglo debe ser mayor a 0.
    assert(N > 0);

    pedir_arreglo(N, a);

    elem = pideEntero();

    imprime_struct(elem, cuantos(N, a, elem));

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

// ...función que le pide un entero al usuario y lo devuelve.
int pideEntero(){
    // Declaración e inicialización de variables
    int y;

    // Solicitar al usuario un entero
    printf("Ingrese un valor para comparar los elementos del arreglo :\n"); 
    scanf("%d", &y);

    // Devuelve la variable con un valor 'int' para ser usado luego
    return y;
}

// Función que calcula los elementos menores, iguales y mayores de un arreglo.
struct comp_t cuantos(int tam, int a[], int elem){
    int i = 0;
    struct comp_t cuantos;
    cuantos.menores = 0;
    cuantos.iguales = 0;
    cuantos.mayores = 0;
    while (i<tam)
    {
        if (a[i]<elem)
        {
            cuantos.menores +=1;
        } else if (a[i]>elem)
        {
            cuantos.mayores +=1;
        } else {
            cuantos.iguales +=1;
        }
        i += 1;
    }
    return cuantos;
}

// Función que imprime el cociente y resto de la división.
void imprime_struct(int a, struct comp_t p)
{
    printf("\nEl número de elementos menores a %d es de: %d\nEl número de elementos iguales a %d es de: %d\nEl número de elementos mayores a %d es de: %d\n",a,p.menores,a,p.iguales,a,p.mayores);
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
    // Ingrese un valor para comparar los elementos del arreglo :
    // 3

    // El número de elementos menores a 3 es de: 2
    // El número de elementos iguales a 3 es de: 1
    // El número de elementos mayores a 3 es de: 2