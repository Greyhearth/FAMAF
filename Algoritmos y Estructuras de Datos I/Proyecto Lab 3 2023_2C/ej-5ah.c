#include <stdio.h>

// Ejercicio 5.a ejercicio 1.h del práctico-teórico.
int main(void){
    // Declaración e inicialización de variables
    int i = 1;

    // Solicitar al usuario ingresar el valor de i
    printf("ingrese un valor para i: ");
    scanf("%d", &i);

    // Mostrar por pantalla el estado inicial ingresado por el usuario.
    printf("σ0 : i -> %d\n", i);

    // Mostrar por pantalla el estado al inicio y al final de cada ciclo.
    while (i!=0) {      // Ingresa al ciclo y lo repite mientras "i" sea distinto de 0.
        printf("σ1 : i -> %d\n", i);    
        i = i - 1;                      // Va restando 1 al valor de "i" con cada iteración.
        printf("σ2 : i -> %d\n", i);    // Para números positivos, esto hace que en algún momento llegue a 0 y continúe con el resto del código.
    };                                  // Para números negativos, continuará ejecutando el ciclo hasta el límite negativo del tipo "int".

    // Mostrar por pantalla el estado final. 
    printf("σ3 : i -> %d\n", i);

    return 0;
}
/*
Ejemplo de la ejecución del programa:
    σ0 : i -> 2
    σ1 : i -> 2
    σ2 : i -> 1
    σ1 : i -> 1
    σ2 : i -> 0
    σ3 : i -> 0
*/
