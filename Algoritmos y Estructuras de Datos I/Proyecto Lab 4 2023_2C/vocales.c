// Ejercicio 4
// Importo "stdio.h" para usar "printf"/"scanf" y "stdbool.h" para usar el tipo bool.
#include <stdio.h>
#include <stdbool.h>

// Declarar el prototipo de las funciones antes de "main" para facilitar la lectura del código.
char pideVocal(void);
bool es_vocal(char letra);

// Luego se declara la función main.
int main()
{
    bool x; // declaro una variable booleana para almacenar el valor de es_vocal
    char y; // declaro una variable char para almacenar el valor de pideVocal

    y = pideVocal();
    x = es_vocal(y);

    // Si "x" vale 1, imprime "true" por pantalla, si vale 0, imprime "false".
    printf("%s\n", x ? "true" : "false");
    // Igual que el anterior pero imprime un mensaje avisando si es o no una vocal.
    printf("La letra %c %s\n", y, x ? "es una vocal" : "no es una vocal");
    return 0;
};

// Función que le pide un entero al usuario y lo devuelve.
char pideVocal()
{
    char x;
    printf("Ingrese una letra:\n");
    scanf(" %c", &x);
    return x;
};

// Función que imprime "hola" por pantalla tantas veces como el valor del entero ingresado.
bool es_vocal(char letra)
{
    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
    {
        return true;
    }
    else
    {
        return false;
    }
};

// Prueba de Ejecución:
// Ingrese una letra:
// r
// false
// La letra r no es una vocal

// Ingrese una letra:
// a
// true
// La letra a es una vocal