#include <stdio.h>

// Ejercicio 3.3 punto 1b del teórico-práctico.
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
    x = x + y;
    printf("σ1 : (x -> %d, y -> %d)\n", x,y);
    y = y + y;
    
    // Mostrar por pantalla el estado final. 
    printf("σ2 : (x -> %d, y -> %d)\n", x,y);

    return 0;
}
/*
    ------------------------------------------------------------------------
    | programa          | usuario ingresa un σ0  | produce una salida σ    |
    ------------------------------------------------------------------------
    | 1.b ejecucion 1   | σ0 : (x -> 1, y -> 5)  | σ2 : (x -> 6, y -> 10)  |
    ------------------------------------------------------------------------
    | 1.b ejecucion 2   | σ0 : (x -> 4, y -> 2)  | σ2 : (x -> 6, y -> 4)   |
    ------------------------------------------------------------------------
    | 1.b ejecucion 3   | σ0 : (x -> 3, y -> 7)  | σ2 : (x -> 10, y -> 14) |
    ------------------------------------------------------------------------
*/