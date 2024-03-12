// Ejercicio 5
// Importo "stdio.h" para usar "printf"/"scanf" y "assert.h" para usar "assert".
#include <stdio.h>
#include <assert.h>

/* Definición de la estructura en C */
struct div_t
{
    int cociente;
    int resto;
};

// Declarar el prototipo de las funciones antes de "main" para facilitar la lectura del código.
int pideEntero(char *valor);
struct div_t division(int x, int y);
void imprime_struct(struct div_t p);

// Luego se declara la función main.
int main(void)
{
    int divid, divis;

    divid = pideEntero("dividendo");
    divis = pideEntero("divisor");

    assert(divid >= 0 && divis > 0); // impide que se intente dividir por 0 o ingresar números negativos (por consigna)

    imprime_struct(division(divid, divis));

    return 0;
};

// Función que le pide un entero al usuario y lo devuelve.
int pideEntero(char *valor)
{
    int x;
    printf("Ingrese un valor para el %s:\n", valor);
    scanf("%d", &x);
    return x;
};

// Función que calcula el cociente y resto de los valores ingresados y devuelve el "struct".
struct div_t division(int x, int y)
{
    struct div_t division;
    division.cociente = x / y;
    division.resto = x % y;
    return division;
};

// Función que imprime el cociente y resto de la división.
void imprime_struct(struct div_t p)
{
    printf("El cociente es %d y el resto es %d\n", p.cociente, p.resto);
};

// Prueba de Ejecución:
// Ingrese un valor para el dividendo:
// 5
// Ingrese un valor para el divisor:
// 0
// test: division.c:26: main: Assertion `divid >= 0 && divis > 0' failed.
// Aborted

// Ingrese un valor para el dividendo:
// 6
// Ingrese un valor para el divisor:
// 3
// El cociente es 2 y el resto es 0

// Ingrese un valor para el dividendo:
// 7
// Ingrese un valor para el divisor:
// 3
// El cociente es 2 y el resto es 1