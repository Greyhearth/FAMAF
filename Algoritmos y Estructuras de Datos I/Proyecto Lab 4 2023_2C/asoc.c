// Ejercicio 14
// Importo "stdio.h" para usar "printf"/"scanf", "assert.h" para usar "assert"  y "stdbool.h" para usar el tipo "bool".
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#define N 5 // defino el largo del arreglo como constante.

/* Definición de los sinónimos en C */
typedef char clave_t;
typedef int valor_t;

/* Definición de la estructura en C */
struct asoc
{
    clave_t clave;
    valor_t valor;
};

// Declarar el prototipo de las funciones antes de "main" para facilitar la lectura del código.
void pedir_arreglo(int n_max, struct asoc a[]);
clave_t pedir_clave();
bool asoc_existe(int tam, struct asoc a[], clave_t c);

// Luego se declara la función main.
int main(void)
{
    // Declaro "a" como array con un largo según el valor de "N".
    struct asoc a[N];
    clave_t clave;
    bool valor = false; // Neutro del "existe/disyunción"

    // Uso assert para verificar la precondición. El largo de un arreglo debe ser mayor a 0.
    assert(N > 0);

    pedir_arreglo(N, a);

    clave = pedir_clave();

    valor = asoc_existe(N, a, clave);

    printf("\n¿Existe la clave en el arreglo?\n %s", valor ? "La clave si existe en el arreglo\n" : "La clave no existe en el arreglo\n");

    return 0;
};

// Función que le pide al usuario un valor para cada entrada del arreglo.
void pedir_arreglo(int n_max, struct asoc a[])
{
    int i = 0;
    while (i < n_max)
    {
        printf("Ingrese la clave %d del arreglo (debe ser tipo Char):\n", i);
        scanf(" %c", &a[i].clave);
        printf("Ingrese el valor %d del arreglo (debe ser tipo Int):\n", i);
        scanf(" %d", &a[i].valor);
        i = i + 1;
    }
};

// Función que solicita una clave al usuario
clave_t pedir_clave()
{
    clave_t clave;
    printf("\nIngrese la clave a buscar en el arreglo (debe ser tipo Char):\n");
    scanf(" %c", &clave);
    return clave;
};

// Función que busca la coincidencia con la clave ingresada.
bool asoc_existe(int tam, struct asoc a[], clave_t c)
{
    int i = 0;
    bool valor = false; // Elemento neutro del "existe/disjunción"
    while (i < tam)
    {
        if (a[i].clave == c)
        {
            valor = valor || true;
        };
        i = i + 1;
    }
    return valor;
};

// Prueba de Ejecución:
    // Ingrese la clave 0 del arreglo (debe ser tipo Char):
    // a
    // Ingrese el valor 0 del arreglo (debe ser tipo Int):
    // 0
    // Ingrese la clave 1 del arreglo (debe ser tipo Char):
    // b
    // Ingrese el valor 1 del arreglo (debe ser tipo Int):
    // 1
    // Ingrese la clave 2 del arreglo (debe ser tipo Char):
    // c
    // Ingrese el valor 2 del arreglo (debe ser tipo Int):
    // 2
    // Ingrese la clave 3 del arreglo (debe ser tipo Char):
    // d
    // Ingrese el valor 3 del arreglo (debe ser tipo Int):
    // 3
    // Ingrese la clave 4 del arreglo (debe ser tipo Char):
    // e
    // Ingrese el valor 4 del arreglo (debe ser tipo Int):
    // 4

    // Ingrese la clave a buscar en el arreglo (debe ser tipo Char):
    // c

    // ¿Existe la clave en el arreglo?
    // La clave si existe en el arreglo



    // Ingrese la clave 0 del arreglo (debe ser tipo Char):
    // a
    // Ingrese el valor 0 del arreglo (debe ser tipo Int):
    // 0
    // Ingrese la clave 1 del arreglo (debe ser tipo Char):
    // b
    // Ingrese el valor 1 del arreglo (debe ser tipo Int):
    // 1
    // Ingrese la clave 2 del arreglo (debe ser tipo Char):
    // c
    // Ingrese el valor 2 del arreglo (debe ser tipo Int):
    // 2
    // Ingrese la clave 3 del arreglo (debe ser tipo Char):
    // d
    // Ingrese el valor 3 del arreglo (debe ser tipo Int):
    // 3
    // Ingrese la clave 4 del arreglo (debe ser tipo Char):
    // e
    // Ingrese el valor 4 del arreglo (debe ser tipo Int):
    // 4

    // Ingrese la clave a buscar en el arreglo (debe ser tipo Char):
    // f

    // ¿Existe la clave en el arreglo?
    // La clave no existe en el arreglo