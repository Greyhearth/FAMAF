// Ejercicio 8
// Importo "stdio.h" para usar "printf"/"scanf", "assert.h" para usar "assert" y "stdbool.h" para usar el tipo "bool".
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#define N 5 // defino el largo del arreglo como constante.

// Declarar el prototipo de las funciones antes de "main" para facilitar la lectura del código.
void pedir_arreglo(int n_max, int a[]);
bool pedirBooleano();
int pideEntero();
bool todos_pares(int tam, int a[]);
bool existe_multiplo(int m, int tam, int a[]);

// Luego se declara la función main.
int main(void)
{
    int a[N];                     // Declaro "a" como array con un largo según el valor de "N".
    int m;                        // Declaro "m" como entero.
    bool op = true, valor = true; // declaro un booleano para la opción del usuario.

    // Uso assert para verificar la precondición. El largo de un arreglo debe ser mayor a 0.
    assert(N > 0);

    pedir_arreglo(N, a);

    op = pedirBooleano();

    assert(op == 0 || op == 1); // El usuario debe elegir una de las opciones.

    if (op)
    {
        m = pideEntero();
        assert(m != 0); // Impide que se divida por 0.
        valor = existe_multiplo(m, N, a);
        printf("¿Existe múltiplo de %d en el arreglo?\n%s\n", m, valor ? "true" : "false");
    }
    else
    {
        valor = todos_pares(N, a);
        printf("¿Son todos números pares en el arreglo?\n%s\n", valor ? "true" : "false");
    }

    // Cualquier rama debe devolver 1 o 0 como valor.
    assert(valor == 0 || valor == 1);

    return 0;
};

// Función que le pide al usuario un valor para cada entrada del arreglo.
void pedir_arreglo(int tam, int a[])
{
    int i = 0; // variable que sirve tanto de contador como de posición en el arreglo.
    while (i < tam)
    {
        printf("ingrese el elemento %d del arreglo:\n", i);
        scanf("%d", &a[i]);
        i = i + 1;
    }
};

// ...función que le pide un booleano al usuario y lo devuelve.
bool pedirBooleano()
{
    // Declaración e inicialización de variables. 'temp' es una variable intermediaria para asignar el valor booleano a 'y'.
    int temp = 1;
    bool y = false;

    // Solicitar al usuario un número entre 0 (falso) y 1 (verdadero)
    printf("Ingrese 0 para verificar si las entradas del arreglo son todas pares,\ningrese 1 para verificar si son múltiplos de otro número:\n");
    scanf("%d", &temp); // 'temp' recibe un entero

    y = temp; // Al asignarlo, "y" recibe su equivalente en booleano.

    // Devuelve la variable con un valor 'bool' para ser usado luego
    return y;
};

// ...función que le pide un entero al usuario y lo devuelve.
int pideEntero()
{
    // Declaración e inicialización de variables
    int y;

    // Solicitar al usuario un entero
    printf("Ingrese un entero, distinto de 0, para verificar si existen múltiplos en el arreglo:\n");
    scanf("%d", &y);

    // Devuelve la variable con un valor 'int' para ser usado luego
    return y;
}

// Función que verifica que cada elemento del arreglo sea par.
bool todos_pares(int tam, int a[])
{
    int i = 0;         // variable que sirve tanto de contador como de posición en el arreglo.
    bool valor = true; // se inicializa en true por ser el elemento neutro de la conjunción.
    while (i < tam)
    {
        if (a[i] % 2 == 0)
        {
            valor = valor && true; // la conjunción hace que el true no altere su valor por ser el elemento neutro.
            i = i + 1;
        }
        else
        {
            valor = valor && false; // la conjunción hace que 1 solo false vuelva la variable false por ser elemento absorbente.
            i = i + 1;
        }
    }
    return valor;
};

// Función que verifica que algún elemento del arreglo sea multiplo de "m".
bool existe_multiplo(int m, int tam, int a[])
{
    int i = 0;          // variable que sirve tanto de contador como de posición en el arreglo.
    bool valor = false; // se inicializa en false por ser el elemento neutro de la disyunción.
    while (i < tam)
    {
        if (a[i] % m == 0)
        {
            valor = valor || true; // la disyunción hace que 1 solo true vuelva la variable false por ser elemento absorbente.
            i = i + 1;
        }
        else
        {
            valor = valor || false; // la disyunción hace que el false no altere su valor por ser el elemento neutro.
            i = i + 1;
        }
    }
    return valor;
};

// Prueba de Ejecución:

    // ingrese el elemento 0 del arreglo:
    // 0
    // ingrese el elemento 1 del arreglo:
    // 2
    // ingrese el elemento 2 del arreglo:
    // 4
    // ingrese el elemento 3 del arreglo:
    // 6
    // ingrese el elemento 4 del arreglo:
    // 8
    // Ingrese 0 para verificar si las entradas del arreglo son todas pares,
    // ingrese 1 para verificar si son múltiplos de otro número:
    // 0
    // ¿Son todos números pares en el arreglo?
    // true


    // ingrese el elemento 0 del arreglo:
    // 5
    // ingrese el elemento 1 del arreglo:
    // 4
    // ingrese el elemento 2 del arreglo:
    // 3
    // ingrese el elemento 3 del arreglo:
    // 2
    // ingrese el elemento 4 del arreglo:
    // 1
    // Ingrese 0 para verificar si las entradas del arreglo son todas pares,
    // ingrese 1 para verificar si son múltiplos de otro número:
    // 0
    // ¿Son todos números pares en el arreglo?
    // false


    // ingrese el elemento 0 del arreglo:
    // 5
    // ingrese el elemento 1 del arreglo:
    // 4
    // ingrese el elemento 2 del arreglo:
    // 3
    // ingrese el elemento 3 del arreglo:
    // 2
    // ingrese el elemento 4 del arreglo:
    // 1
    // Ingrese 0 para verificar si las entradas del arreglo son todas pares,
    // ingrese 1 para verificar si son múltiplos de otro número:
    // 1
    // Ingrese un entero, distinto de 0, para verificar si existen múltiplos en el arreglo:
    // 4
    // ¿Existe múltiplo de 4 en el arreglo?
    // true


    // ingrese el elemento 0 del arreglo:
    // 5
    // ingrese el elemento 1 del arreglo:
    // 4
    // ingrese el elemento 2 del arreglo:
    // 3
    // ingrese el elemento 3 del arreglo:
    // 2
    // ingrese el elemento 4 del arreglo:
    // 1
    // Ingrese 0 para verificar si las entradas del arreglo son todas pares,
    // ingrese 1 para verificar si son múltiplos de otro número:
    // 1
    // Ingrese un entero, distinto de 0, para verificar si existen múltiplos en el arreglo:
    // 6
    // ¿Existe múltiplo de 6 en el arreglo?
    // false