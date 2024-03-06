// Ejercicio 1a
// Importo "stdio.h" para usar "printf"/"scanf" y "assert.h" para usar "assert".
#include <stdio.h>
#include <assert.h>

// Declarar el prototipo de las funciones antes de "main" para facilitar la lectura del código.
int pideEntero();
void hola_hasta(int n);

// Luego se declara la función main.
int main(void)
{
    int x;
    
    x = pideEntero();

    assert(x > 0); // verifica que el entero sea mayor a 0.

    hola_hasta(x);

    return 0;
};

// Función que le pide un entero al usuario y lo devuelve.
int pideEntero()
{
    int x;
    printf("Ingrese un valor (debe ser un numero entero mayor que 0):\n");
    scanf("%d", &x);
    return x;
};

// Función que imprime "hola" por pantalla tantas veces como el valor del entero ingresado.
void hola_hasta(int n)
{
    int i = 0;     // sirve de contador de iteraciones.
    while (i < n)  // continua el ciclo hasta que i alcance al entero
    {
        printf("Hola\n");
        i = i + 1; // suma 1 a "i" en cada ciclo.
    }
};

// prueba de ejecución:
    // Ingrese un valor (debe ser un numero entero mayor que 0):
    // 7
    // Hola
    // Hola
    // Hola
    // Hola
    // Hola
    // Hola
    // Hola