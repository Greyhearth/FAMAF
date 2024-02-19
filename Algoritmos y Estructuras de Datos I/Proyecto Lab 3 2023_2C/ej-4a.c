#include <stdio.h>

// Ejercicio 3.4a (basado en los ejercicios 1e y 1f del práctico, que son idénticos excepto por sus estadios iniciales).
int main(void){
    // Declaración e inicialización de variables
    int x = 1, y = 1;

    // Solicitar al usuario ingresar los valores de x, y
    printf("ingrese un valor para x: ");
    scanf("%d", &x);
    printf("ingrese un valor para y: ");
    scanf("%d", &y);

    // Mostrar por pantalla el estado inicial ingresado por el usuario. 
    printf("σ0 : (x -> %d, y -> %d)\n", x,y);

    // Mostrar por pantalla los estados intermedios, dentro de cada rama condicional.
    if (x>=y) {
        printf("σ1 : (x -> %d, y -> %d)\n", x,y);
        x = 0;
        printf("σ2 : (x -> %d, y -> %d)\n", x,y);
    } else {
        printf("σ'1 : (x -> %d, y -> %d)\n", x,y);
        x = 2;
        printf("σ'2 : (x -> %d, y -> %d)\n", x,y);
    }
   
    // Mostrar por pantalla el estado final. 
    printf("σ3 : (x -> %d, y -> %d)\n", x,y);

    return 0;
}
/*
Ejemplos de su ejecución:
    σ0 : (x -> 1, y -> 4)
    σ'1 : (x -> 1, y -> 4)
    σ'2 : (x -> 2, y -> 4)
    σ3 : (x -> 2, y -> 4)
 y
    σ0 : (x -> 4, y -> 1)
    σ1 : (x -> 4, y -> 1)
    σ2 : (x -> 0, y -> 1)
    σ3 : (x -> 0, y -> 1)
*/