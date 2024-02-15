#include <stdio.h>
#include <stdbool.h>

// Ejercicio 3.2
int main(void){
    // Declaración e inicialización de variables
    int x = 1, y = 1, z = 1, temp1 = 1, temp2 = 1;
    bool b = false, w = false;

    // Solicitar al usuario ingresar los valores de x, y, z, b w
    printf("ingrese un valor para x: ");
    scanf("%d", &x);
    printf("ingrese un valor para y: ");
    scanf("%d", &y);
    printf("ingrese un valor para z: ");
    scanf("%d", &z);
    printf("ingrese un valor para b, puede ser 0 para 'false' o 1 para 'true': ");
    scanf("%d", &temp1);    // Como C no tiene un especificador de formato para booleanos, se le pide al usuario ingresar un entero (0 o 1).
    b = temp1;              // El entero obtenido se guarda en una variable temporal, cuyo valor se asigna al booleano declarado más arriba.
    printf("ingrese un valor para w, puede ser 0 para 'false' o 1 para 'true': ");
    scanf("%d", &temp2);
    w = temp2;

    // Mostrar por pantalla el resultado de cada operación solicitada.
    // Como los 3 usan operadores lógicos, todos los resultados serán booleanos, pero al usar %d se mostrará únicamente un entero (0 o 1).
    printf("El resultado de la operacion x %% 4 == 0 es: %d\n", (x % 4 == 0));
    printf("El resultado de la operacion x + y == 0 && y - x == (-1) * z es: %d\n", (x + y == 0 && y - x == (-1) * z));
    printf("El resultado de la operacion not b && w es: %d\n", (!(b && w)));
    return 0;
}

/*
Respuesta:
    Para que las expresiones tengan valor True, True, False respectivamente, una posibilidad es:
        x -> 4
        y -> -4
        z -> 8
        b -> 1
        w -> 1
Ejemplo de ejecución del programa:
    ingrese un valor para x: 4
    ingrese un valor para y: -4
    ingrese un valor para z: 8
    ingrese un valor para b, puede ser 0 para 'false' o 1 para 'true': 1
    ingrese un valor para w, puede ser 0 para 'false' o 1 para 'true': 1
    El resultado de la operacion x % 4 == 0 es: 1
    El resultado de la operacion x + y == 0 && y - x == (-1) * z es: 1
    El resultado de la operacion not b && w es: 0
*/