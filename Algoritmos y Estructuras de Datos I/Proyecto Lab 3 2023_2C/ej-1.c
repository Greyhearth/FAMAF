#include <stdio.h>

// Ejercicio 3.1
int main(void){
    // Declaración e inicialización de variables
    int x = 1, y = 1, z = 1;

    // Solicitar al usuario ingresar los valores de x, y, z
    printf("ingrese un valor para x: ");
    scanf("%d", &x);
    printf("ingrese un valor para y: ");
    scanf("%d", &y);
    printf("ingrese un valor para z: ");
    scanf("%d", &z);

    // Mostrar por pantalla el resultado de cada operación solicitada. 
    printf("El resultado de la operacion x + y + 1 es: %d\n", (x + y + 1));
    printf("El resultado de la operacion z * z + y * 45 - 15 * x es: %d\n", (z * z + y * 45 - 15 * x));
    printf("El resultado de la operacion y - 2 == (x * 3 + 1) %% 5 es: %d\n", (y - 2 == (x * 3 + 1) % 5));  // Al usar el operador lógico "==", el resultado será booleano, pero el uso de %d sólo permite mostrar un entero (0 o 1).
    printf("El resultado de la operacion y / 2 * x es: %d\n", (y / 2 * x));
    printf("El resultado de la operacion y < x * z es: %d\n", (y < x * z)); // Al usar el operador lógico "<", el resultado será booleano, pero el uso de %d sólo permite mostrar un entero (0 o 1).

    return 0;
}
/*
    -----------------------------------------------------------------------
    | Expresion                 | (x->7, y->3, z->5) | (x->1, y->10, z->8)|
    -----------------------------------------------------------------------
    | x + y + 1                 |        11          |         12         |
    -----------------------------------------------------------------------
    | z * z + y * 45 - 15 * x   |        55          |        499         |
    -----------------------------------------------------------------------
    | y - 2 == (x * 3 + 1) % 5  |         0          |          0         | En este caso, el entero 0 es la representación de "False" para C.
    -----------------------------------------------------------------------
    | y / 2 * x                 |         7          |          5         |
    -----------------------------------------------------------------------
    | y < x * z                 |         1          |          0         | En este caso, el primer 1 es la representación de "True" para C.
    -----------------------------------------------------------------------
*/