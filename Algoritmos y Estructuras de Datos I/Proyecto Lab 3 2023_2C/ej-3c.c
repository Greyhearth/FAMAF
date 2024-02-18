#include <stdio.h>

// Ejercicio 3.3 punto 1c del teórico-práctico.
int main(void){
    // Declaración e inicialización de variables
    int x = 1, y = 1;

    // Solicitar al usuario ingresar los valores de x, y
    printf("ingrese un valor para x: ");
    scanf("%d", &x);
    printf("ingrese un valor para y: ");
    scanf("%d", &y);

    // Mostrar por pantalla los estados intermedios. 
    printf("σ0 : (x -> %d, y -> %d)\n", x,y);
    y = y + y;
    printf("σ1 : (x -> %d, y -> %d)\n", x,y);
    x = x + y;
    
    // Mostrar por pantalla el estado final. 
    printf("σ2 : (x -> %d, y -> %d)\n", x,y);

    return 0;
}
/*
    ------------------------------------------------------------------------
    | programa          | usuario ingresa un σ0  | produce una salida σ    |
    ------------------------------------------------------------------------
    | 1.c ejecucion 1   | σ0 : (x -> 1, y -> 5)  | σ2 : (x -> 11, y -> 10) |
    ------------------------------------------------------------------------
    | 1.c ejecucion 2   | σ0 : (x -> 4, y -> 2)  | σ2 : (x -> 8, y -> 4)   |
    ------------------------------------------------------------------------
    | 1.c ejecucion 3   | σ0 : (x -> 3, y -> 7)  | σ2 : (x -> 17, y -> 14) |
    ------------------------------------------------------------------------
*/