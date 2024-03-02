#include <stdio.h>
// Ejercicio 3.6d
// Declarar el prototipo de las funciones antes de "main" para facilitar la lectura del código.
void imprimeHola(void);
void imprimeChau(void);
// Luego se declara la función main.
int main(void) {
    
    imprimeHola();
    imprimeHola();
    imprimeChau();
    imprimeChau();

    return 0;
}
// Por último se definen las funciones declaradas al inicio.
    // ...una que imprime el string "hola", que no toma ni devuelve parámetros...
void imprimeHola(void){

    printf("Hola\n"); 

}
    // ...similar a la anterior con la el string "chau":...
void imprimeChau(void){

    printf("Chau\n");

}
/*
Ejemplo de ejecución:
    Hola
    Hola
    Chau
    Chau
*/