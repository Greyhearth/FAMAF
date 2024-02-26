#include <stdio.h>
// Ejercicio 3.6a
// Declarar el prototipo de las funciones antes de "main" para facilitar la lectura del código.
int pideEntero(char name);
void imprimeEntero(char name, int x);
// Luego se declara la función main.
int main(void) {
    // Declaración e inicialización de variables
    int x = 1;
    char n = 'a';    // Declarada una variable tipo 'char' para el tercer punto

    // Solicitar al usuario una letra ('char') para el tercer punto
    printf("Ingrese una letra para el nombre de la variable:\n");
    scanf("%c", &n);

    x = pideEntero(n);   // Le asigna el valor de "y" del return de la función a "x".
    imprimeEntero(n, x); // Utiliza el valor de "x" en la función.
    // imprimeEntero(n, pideEntero(n));   alternativa sin usar una variable intermediaria, ya que pideEntero devuelve un "int".

    return 0;
}
// Por último se definen las funciones declaradas al inicio.
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
void imprimeEntero(char name, int x){
    printf("El valor de %c es: %d\n", name, x);
}

/*
Prueba de ejecución:
    Ingrese una letra para el nombre de la variable:
    r
    Ingrese un valor para r:
    5
    El valor de r es: 5
*/