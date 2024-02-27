#include <stdio.h>
#include <stdbool.h>
// Ejercicio 3.6b
// Declarar el prototipo de las funciones antes de "main" para facilitar la lectura del código.
bool pedirBooleano(char name);
void imprimeBooleano(char name, bool x);
// Luego se declara la función main.
int main(void) {
    // Declaración e inicialización de variables
    bool x = false;
    char n = 'a';  // Declarada una variable tipo 'char' para el tercer punto

    // Solicitar al usuario una letra ('char') para el tercer punto
    printf("Ingrese una letra para el nombre de la variable:\n");
    scanf("%c", &n);

    x = pedirBooleano(n);    // Le asigna el valor de "y" del return de la función a "x".
    imprimeBooleano(n, x);   // uUtiliza el valor de "x" en la función.
    // imprimeBooleano(n, pedirBooleano(n));  alternativa sin usar una variable intermediaria, ya que pedirBooleano devuelve un "bool".

    return 0;
}
// Por último se definen las funciones declaradas al inicio.
    // ...función que le pide un booleano al usuario y lo devuelve.
bool pedirBooleano(char name){
    // Declaración e inicialización de variables. 'temp' es una variable intermediaria para asignar el valor booleano a 'y'.
    int temp = 1;
    bool y = false;

    // Solicitar al usuario un número entre 0 (falso) y 1 (verdadero)
    printf("Ingrese un valor para %c (elija 1 para 'verdadero' o 0 para 'falso'):\n",name); 
    scanf("%d", &temp); // 'temp' recibe un entero

    y = temp;   // Al asignarlo, "y" recibe su equivalente en booleano.

    // Devuelve la variable con un valor 'bool' para ser usado luego
    return y;
}
// ...función que toma un booleano como parámetro e imprime un mensaje "verdadero" o "falso" según sea su valor de verdad:
void imprimeBooleano(char name, bool x){
    if (x){
        printf("El valor de %c es: verdadero\n", name);
    } else {
        printf("El valor de %c es: falso\n", name);
    }
    // printf("El valor de %c es: %s\n", name, (x? "verdadero" : "falso")); alternativa en donde el condicional se ejecuta en 1 sóla línea.
}

/*
Prueba de ejecución:
    Ingrese una letra para el nombre de la variable:
    t
    Ingrese un valor para t (elija 1 para 'verdadero' o 0 para 'falso'):
    1
    El valor de t es: verdadero
Con otros valores:
    Ingrese una letra para el nombre de la variable:
    u
    Ingrese un valor para u (elija 1 para 'verdadero' o 0 para 'falso'):
    0
    El valor de u es: falso
*/