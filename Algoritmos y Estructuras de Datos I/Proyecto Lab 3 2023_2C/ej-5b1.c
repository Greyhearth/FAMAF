#include <stdio.h>

// Ejercicio 5.b ejercicio 1
int main(void){
    // Declaración e inicialización de variables
    int x = 1, y = 1, i = 1;

    // Solicitar al usuario ingresar los valores de x, y, i
    printf("ingrese un valor para x: ");
    scanf("%d", &x);
    printf("ingrese un valor para y: ");
    scanf("%d", &y);
    printf("ingrese un valor para i: ");
    scanf("%d", &i);

    // Mostrar por pantalla el estado inicial ingresado por el usuario.
    printf("σ0 : (x -> %d, y -> %d, i -> %d)\n", x,y,i);
    i = 0;  // Sin importar el valor inicial de "i", siempre se le asigna 0.

    // Mostrar por pantalla el estado al final de cada ciclo.
    while (x>y) {   // Repite el ciclo mientras "x" sea mayor a "y".
        x = x - y;  // En cada ciclo se le resta "y" a "x", por lo en algún momento dejará de cumplir la condición (para números positivos, para los negativos seguirá calculando hasta el límite de "int").
        i = i + 1;  // Como a "i" se le asigna 0 y con cada iteración suma 1, sirve de contador de ciclos.
        printf("σ%i : (x -> %d, y -> %d, i -> %d)\n", i,x,y,i); // Como "i" funciona como contador de "iteraciones", puedo usarlo para numerar los diferentes estados intermedios según el número de ciclo.
    }  

    return 0;
}
/*
Ejemplo del programa ejecutado con los valores del proyecto:
    σ0 : (x -> 13, y -> 3, i -> 0)
    σ1 : (x -> 10, y -> 3, i -> 1)
    σ2 : (x -> 7, y -> 3, i -> 2)
    σ3 : (x -> 4, y -> 3, i -> 3)
    σ4 : (x -> 1, y -> 3, i -> 4)
Y usando otros valores iniciales:
    σ0 : (x -> 7, y -> 2, i -> 4)   
    σ1 : (x -> 5, y -> 2, i -> 1)
    σ2 : (x -> 3, y -> 2, i -> 2)
    σ3 : (x -> 1, y -> 2, i -> 3)
*/