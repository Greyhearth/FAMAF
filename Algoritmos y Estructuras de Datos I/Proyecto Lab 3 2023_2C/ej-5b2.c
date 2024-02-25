#include <stdio.h>
#include <stdbool.h>

// Ejercicio 5.b ejercicio 2
int main(void){
    // Declaración e inicialización de variables ("temp" es intermediario para el booleano "res")
    int x = 1, i = 1, temp = 1;
    bool res = false;

    // Solicitar al usuario ingresar los valores de x, y, i
    printf("ingrese un valor para x: ");
    scanf("%d", &x);
    printf("ingrese un valor para i: ");
    scanf("%d", &i);
    printf("ingrese un valor para res, puede ser 0 para 'false' o 1 para 'true': ");
    scanf("%d", &temp); // Como C no tiene especificador de formato para booleanos, se asigna 0 o 1 como entero a "temp".

    res = temp;         // Luego se le asigna el valor de "temp" a "res", evitando advertencias de tipo al compilar.

    // Mostrar por pantalla el estado inicial ingresado por el usuario.
    printf("σ0 : (x -> %d, i -> %d, res -> %d)\n", x,i,res);
    i = 2;  // Sin importar lo que ingrese el usuario, le asigna a "i" el valor 2.
    res = true; // Sin importar lo que ingrese el usuario, le asigna a "res" el valor "true" (o 1, por como lo interpreta C).

    // Mostrar por pantalla el estado al final de cada ciclo.
    while ( (i<x) && (res) ) {      // la condición para cada iteración es, por un lado ver que i sea menor a x, y por el otro, que la variable "res" tenga valor "true" (o 1).
        res = res && ((x%i)!=0);    // En cada ciclo, le asigna a "res" un valor booleano según si la división de "x" por "i" da un resto ("true") o no ("false").
        i = i + 1;                  // En cada ciclo, le suma 1 al valor de "i".
        printf("σ1 : (x -> %d, i -> %d, res -> %d)\n", x,i,res);
    };

    return 0;
}
/*
Ejemplo de ejecución del programa:
    σ0 : (x -> 5, i -> 0, res -> 0)
    σ1 : (x -> 5, i -> 3, res -> 1)
    σ1 : (x -> 5, i -> 4, res -> 1)
    σ1 : (x -> 5, i -> 5, res -> 1)
Con otros valores iniciales:
    σ0 : (x -> 6, i -> 9, res -> 0)     // Sólo itera una vez ya que i=2 divide a x=6 dando resto 0, lo que asigna el valor "false" a "res".
    σ1 : (x -> 6, i -> 3, res -> 0)     // Si se coloca un brackpoint en la línea 26, se ve cómo "res" ingresa al ciclo con valor 1 ("true") y en la línea 27 pasa a valer 0 ("false").
*/