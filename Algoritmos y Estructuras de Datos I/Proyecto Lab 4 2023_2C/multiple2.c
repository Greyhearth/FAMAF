// Ejercicio 2a y 2b

//  {Pre: x = X, y = Y, z = Z}
//  x, y, z := y, y + x + z, y + x
//  {Post: x = Y, y = Y + X + Z, z = Y + X}

// Programa equivalente con asignaciones simples:

//  {Pre: x = X, y = Y, z = Z, auxX = X, auxY = Y}
//  auxX := x;
//  auxY = y;
//  x := y;
//  y := y + auxX + z;
//  z := auxY + auxX;
//  {Post: x = Y, y = Y + X + Z, z = Y + X, auxX = X, auxY = Y}

// Importo "stdio.h" para usar "printf"/"scanf".
#include <stdio.h>
#include <assert.h>

// Declarar el prototipo de las funciones antes de "main" para facilitar la lectura del código.
int pideEntero(char letra);

// Luego se declara la función main.
int main(void)
{
    // Declaro e inicializo las variables.
    int x, X, y, Y, z, Z , auxX, auxY;

    // Solicito al usuario que ingrese el valor de ambas variables.
    x = pideEntero('x');
    y = pideEntero('y');
    z = pideEntero('z');

    // Le asigno a la variable auxiliar el valor de "x" para guardarlo.
    auxX = x;
    auxY = y;

    // Asigno los valores en "X", "Y" y "Z" para usarlos en Assert
    X = x;
    Y = y;
    Z = z;

    // Assert controla la precondición
    assert (x==X && y==Y && z==Z);

    // Asignaciones según el programa:
    x = y;            // Como el valor de "x" cambia, no puedo usarlo en la asignación de "y" ni "z".
    y = y + auxX + z; // Como el valor de "y" cambia, no puedo usarlo en la asignación de "z".
    z = auxY + auxX;  // Las variables auxiliares "X" e "Y"  tienen los valores originales de "x" e "y"

    // Assert controla la postcondición
    assert(x == Y && y == (Y+X+Z) && z == (Y+X));

    // Muestra por pantalla el estado final de las variables:
    printf("El valor de x es %d, el valor de y es %d, el valor de z es %d:\n", x, y, z);

    return 0;
};

// Función que le pide un entero al usuario y lo devuelve.
int pideEntero(char letra)
{
    int x;
    printf("Ingrese un valor para %c:\n", letra);
    scanf("%d", &x);
    return x;
};

// Prueba de Ejecución:
    // Ingrese un valor para x:
    // 4
    // Ingrese un valor para y:
    // 6
    // Ingrese un valor para z:
    // 8
    // El valor de x es 6, el valor de y es 18, el valor de z es 10: