#include <stdio.h>

// Ejercicio 3.4b
int main(void){
    // Declaración e inicialización de variables
    int x = 1, y = 1, z = 1, m = 1;

    // Solicitar al usuario ingresar los valores de x, y, z y m
    printf("ingrese un valor para x: ");
    scanf("%d", &x);
    printf("ingrese un valor para y: ");
    scanf("%d", &y);
    printf("ingrese un valor para z: ");
    scanf("%d", &z);
    printf("ingrese un valor para m: ");
    scanf("%d", &m);

    // Mostrar por pantalla el estado inicial "σ0". 
    printf("σ0 : (x -> %d, y -> %d, z -> %d, m -> %d)\n", x,y,z,m);

    // Primer condicional.
    if (x<y) {
        m = x;
    } else {
        m = y;
    };

    // Mostrar por pantalla los estados intermedios tras el primer condicional.
    printf("σ1 : (x -> %d, y -> %d, z -> %d, m -> %d)\n", x,y,z,m);

    // Segundo condicional.
    if (m<z) {
        // Dejar vacío entre las llaves es equivalente al "skip" del teórico-práctico.
    } else {
        m = z;
    };

    // Mostrar por pantalla el estado final. 
    printf("σ2 : (x -> %d, y -> %d, z -> %d, m -> %d)\n", x,y,z,m);

    return 0;
}
/*
Ejemplo de ejecución del programa con los valores del proyecto:
    σ0 : (x -> 5, y -> 4, z -> 8, m -> 0)
    σ1 : (x -> 5, y -> 4, z -> 8, m -> 4)
    σ2 : (x -> 5, y -> 4, z -> 8, m -> 4)
Y con otros valores:
    σ0 : (x -> 3, y -> 5, z -> 2, m -> 9)
    σ1 : (x -> 3, y -> 5, z -> 2, m -> 3)
    σ2 : (x -> 3, y -> 5, z -> 2, m -> 2)
¿Qué hace este programa?
    En primer lugar, compara los valores de "x" e "y", asignándole el valor del menor a "m".
    Luego compara el valor de "m" con el de "z", asignándole a "m" el valor de "z" si es menor, caso contrario, no hace nada más.
¿Cuál es el valor final de la variable m?
    En todos los casos y sin importar el valor asignado a "m", su valor final es igual al menor entre los valores "x", "y" o "z".
*/