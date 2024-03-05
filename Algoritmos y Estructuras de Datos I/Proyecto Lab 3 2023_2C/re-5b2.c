#include <stdio.h>
#include <stdbool.h>
// Ejercicio 3.5b2 reescrito para usar las funciones del punto 6a y 6b.
int pideEntero(char name);
bool pedirBooleano(char * name);
void imprimeBooleano(char a, int b, char c, int d, char * name, bool x, int i);

int main(void){
    // Declaración e inicialización de variables
    int x = 1, i = 1;   // Ya no es necesario declarar una variable 'temp' en main.
    bool res = false;

    // Solicitar al usuario ingresar los valores de x, y, i
    x = pideEntero('x');
    i = pideEntero('i');
    res = pedirBooleano("res");

    // Mostrar por pantalla el estado inicial ingresado por el usuario.
    imprimeBooleano('x',x,'i',i,"res",res,0);
    i = 2;
    res = true;

    // Mostrar por pantalla el estado al final de cada ciclo.
    while ( (i<x) && (res) ) {
        res = res && ((x%i)!=0);
        i = i + 1;
        imprimeBooleano('x',x,'i',i,"res",res,1);
    };

    return 0;
}

int pideEntero(char name){
    // Declaración e inicialización de variables
    int y;

    // Solicitar al usuario un entero
    printf("Ingrese un valor para %c:\n",name); 
    scanf("%d", &y);

    // Devuelve la variable con un valor 'int' para ser usado luego
    return y;
}

bool pedirBooleano(char * name){
    // Declaración e inicialización de variables. 'temp' es una variable intermediaria para asignar el valor booleano a 'y'.
    int temp = 1;
    bool y = false;

    // Solicitar al usuario un número entre 0 (falso) y 1 (verdadero)
    printf("Ingrese un valor para %s (elija 1 para 'verdadero' o 0 para 'falso'):\n",name); 
    scanf("%d", &temp); // 'temp' recibe un entero

    y = temp;   // Al asignarlo, "y" recibe su equivalente en booleano.

    // Devuelve la variable con un valor 'bool' para ser usado luego
    return y;
}

void imprimeBooleano(char a, int b, char c, int d, char * name, bool x, int i){
    if (x){
        printf("σ%d : (%c -> %d, %c -> %d, %s -> verdadero)\n", i,a,b,c,d,name);
    } else {
        printf("σ%d : (%c -> %d, %c -> %d, %s -> falso)\n", i,a,b,c,d,name);
    }
}
/*
Ejemplo de ejecución del programa:
    Ingrese un valor para x:
    5
    Ingrese un valor para i:
    0
    Ingrese un valor para res (elija 1 para 'verdadero' o 0 para 'falso'):
    0
    σ0 : (x -> 5, i -> 0, res -> falso)
    σ1 : (x -> 5, i -> 3, res -> verdadero)
    σ1 : (x -> 5, i -> 4, res -> verdadero)
    σ1 : (x -> 5, i -> 5, res -> verdadero)
*/