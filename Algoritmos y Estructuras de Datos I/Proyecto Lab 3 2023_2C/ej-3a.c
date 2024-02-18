#include <stdio.h>

// Ejercicio 3.3 punto 1a del teórico-práctico.
int main(void){
    // Declaración e inicialización de variables
    int x = 1;

    // Solicitar al usuario ingresar el valor de x
    printf("ingrese un valor para x: ");
    scanf("%d", &x);

    // Mostrar por pantalla los estados intermedios. 
    printf("σ0 : x -> %d\n", x);
    x = 5;

    // Mostrar por pantalla el estado final. 
    printf("σ1 : x -> %d\n", x);

    return 0;
}
/*
    --------------------------------------------------------------------
    | programa          | usuario ingresa un σ0 | produce una salida σ |
    --------------------------------------------------------------------
    | 1.a ejecucion 1   |   σ0 : x -> 1         |   σ1 : x -> 5        |
    --------------------------------------------------------------------
    | 1.a ejecucion 2   |   σ0 : x -> 2         |   σ1 : x -> 5        |
    --------------------------------------------------------------------
    | 1.a ejecucion 3   |   σ0 : x -> 3         |   σ1 : x -> 5        |
    --------------------------------------------------------------------
*/