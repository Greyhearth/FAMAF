// Ejercicio 3
// Importo "stdio.h" para usar "printf"/"scanf" y "assert.h" para usar "assert".
#include <stdio.h>
#include <assert.h>

// Declarar el prototipo de las funciones antes de "main" para facilitar la lectura del código.
int pideEntero();
void suma_hasta(int n);

// Luego se declara la función main.
int main(void)
{
    int n;

    n = pideEntero();

    assert(n >= 0); // verifica que el entero sea mayor o igual a 0.

    suma_hasta(n);

    return 0;
};

// Función que le pide un entero al usuario y lo devuelve.
int pideEntero()
{
    int x;
    printf("Ingrese un valor para 'n' (debe ser un numero entero mayor o igual que 0):\n");
    scanf("%d", &x);
    return x;
};

// Función que suma los primeros "n" numeros naturales.
void suma_hasta(int n)
{
    int i = 0;         // sirve de contador de iteraciones.
    int resultado = 0; // sirve para guardar el resultado de la sumatoria
    while (i <= n)     // continua el ciclo hasta que i alcance al entero
    {
        resultado = resultado + i; // en cada ciclo, se le suma el valor de "i" a "resultado".
        i = i + 1;                 // suma 1 a "i" en cada ciclo.
    }
    printf("La suma de los primeros %d números es: %d\n", n, resultado);
    // printf("La suma de los primeros %d números es: %d\n",n,(n*(n+1)/2));         //opción usando la fórmula Gaussiana, no requiere ciclo, ni contador "i", ni variable "resultado".
};

// Prueba de Ejecución:
// Ingrese un valor para 'n' (debe ser un numero entero mayor o igual que 0):
// 5
// La suma de los primeros 5 números es: 15

// Ingrese un valor para 'n' (debe ser un numero entero mayor o igual que 0):
// 0
// La suma de los primeros 0 números es: 0

// Ingrese un valor para 'n' (debe ser un numero entero mayor o igual que 0):
// -1
// test: suma_hasta.c:17: main: Assertion `n >= 0' failed.
// Aborted