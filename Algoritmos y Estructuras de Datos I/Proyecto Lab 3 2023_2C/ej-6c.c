#include <stdio.h>
// Ejercicio 3.6c - Reescritura del punto 4b usando las funciones de 6a y 6b.
// Declarar el prototipo de las funciones antes de "main" para facilitar la lectura del código.
int pideEntero(char name);
void imprimeEntero(char a, int b, char c, int d, char e, int f, char g, int h, int i); // Modificada para aceptar más parámetros y poder imprimir el mismo mensaje que en el punto 4b.
// Luego se declara la función main.
int main(void){
    // Declaración e inicialización de variables
    int x = 1, y = 1, z = 1, m = 1;

    // Utilizo la función "pideEntero" del punto 6a para obtener los valores:
    x = pideEntero('x');
    y = pideEntero('y');
    z = pideEntero('z');
    m = pideEntero('m');

    // Utilizo la función "imprimeEntero" del punto 6a mostrar por pantalla el estado inicial "σ0". 
    imprimeEntero('x', x, 'y', y, 'z', z, 'm', m, 0);

    // Primer condicional.
    if (x<y) {
        m = x;
    } else {
        m = y;
    };

    // Utilizo la función "imprimeEntero" del punto 6a mostrar por pantalla el estado intermedio "σ1". 
    imprimeEntero('x', x, 'y', y, 'z', z, 'm', m, 1);

    // Segundo condicional.
    if (m<z) {
        // Dejar vacío entre las llaves es equivalente al "skip" del teórico-práctico.
    } else {
        m = z;
    };

    // Utilizo la función "imprimeEntero" del punto 6a mostrar por pantalla el estado final "σ2". 
    imprimeEntero('x', x, 'y', y, 'z', z, 'm', m, 2);

    return 0;
}
// ...función que le pide un entero al usuario y lo devuelve.
int pideEntero(char name){
    // Declaración e inicialización de variables
    int y;

    // Solicitar al usuario un entero
    printf("Ingrese un valor para %c:\n",name); 
    scanf("%d", &y);

    // Devuelve la variable con un valor 'int' para ser usado luego
    return y;
}
// ...función que toma un entero como parámetro y lo imprime:
void imprimeEntero(char a, int b, char c, int d, char e, int f, char g, int h, int i){
    printf("σ%d : (%c -> %d, %c -> %d, %c -> %d, %c -> %d)\n", i,a,b,c,d,e,f,g,h);
}
/*
Ejemplo de ejecución del programa con los valores del punto 4b del proyecto:
    Ingrese un valor para x:
    5
    Ingrese un valor para y:
    4
    Ingrese un valor para z:
    8
    Ingrese un valor para m:
    0
    σ0 : (x -> 5, y -> 4, z -> 8, m -> 0)
    σ1 : (x -> 5, y -> 4, z -> 8, m -> 4)
    σ2 : (x -> 5, y -> 4, z -> 8, m -> 4)   // Mismos valores y mensajes mostrados por pantalla que en el punto 4b.

¿Qué ventajas encontras en esta nueva versión?
    Varias partes del código original eran repetitivas, por lo que tener una función que, al llamarla, replica las secuencias originales hace más legible a la función main().

¿Podrías escribir alguna otra función en ese ejercicio, cual?
    Si, el ejercicio 4a también se puede modificar para aceptar las nuevas funciones.

¿En qué otros ejercicios de ese Proyecto lo podrías utilizar?
    Se adjuntan las versiones reescritas de los puntos 1, 2, 3a, 3b, 3c, 5ah, 5ai, 5b1 y 5b2.
*/