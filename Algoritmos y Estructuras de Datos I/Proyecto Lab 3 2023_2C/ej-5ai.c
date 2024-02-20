#include <stdio.h>

// Ejercicio 5.b ejercicio 1.i del práctico-teórico.
int main(void){
    // Declaración e inicialización de variables
    int i = 1;

    // Solicitar al usuario ingresar el valor de i
    printf("ingrese un valor para i: ");
    scanf("%d", &i);

    // Mostrar por pantalla el estado inicial ingresado por el usuario.
    printf("σ0 : i -> %d\n", i);

    // Mostrar por pantalla el estado al inicio y al final de cada ciclo.
    while (i!=0) {      // Al igual que el anterior, ingresa al ciclo si "i" es diferente de 0.
        printf("σ1 : i -> %d\n", i);
        i = 0;          // Al asignarle el valor 0 a "i", en todos los casos escapará del ciclo siguiente y seguirá con el código.
        printf("σ2 : i -> %d\n", i);
    } 

    // Mostrar por pantalla el estado final. 
    printf("σ3 : i -> %d\n", i);

    return 0;
}
/*
Ejemplo de la ejecución del programa:
    σ0 : i -> 2
    σ1 : i -> 2
    σ2 : i -> 0
    σ3 : i -> 0
*/