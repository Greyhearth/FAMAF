// Ejercicio 16
// Importo "stdio.h" para usar "printf"/"scanf", "assert.h" para usar "assert" y "stdbool.h" para el tipo "bool".
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

/* Definición de la estructura y su sinónimo en C */
typedef struct
{
    char *nombre;
    int edad;
    float altura;
    float peso;
} persona_t;

// Declarar el prototipo de las funciones antes de "main" para facilitar la lectura del código.
float peso_promedio(unsigned int longitud, persona_t arr[]);
persona_t persona_de_mayor_edad(unsigned int longitud, persona_t arr[]);
persona_t persona_de_menor_altura(unsigned int longitud, persona_t arr[]);

// Luego se declara la función main.
int main(void)
{
    persona_t p1 = {.nombre = "Paola", .edad = 21, .altura = 1.85, .peso = 75};
    persona_t p2 = {.nombre = "Luis", .edad = 54, .altura = 1.75, .peso = 69};
    persona_t p3 = {.nombre = "Julio", .edad = 40, .altura = 1.70, .peso = 80};
    unsigned int longitud = 3;
    persona_t arr[] = {p1, p2, p3};
    printf("El peso promedio es %f\n", peso_promedio(longitud, arr));
    persona_t p = persona_de_mayor_edad(longitud, arr);
    printf("El nombre de la persona con mayor edad es %s\n", p.nombre);
    p = persona_de_menor_altura(longitud, arr);
    printf("El nombre de la persona con menor altura es %s\n", p.nombre);
    return 0;
}

// Devuelve el promedio de peso de las personas del arreglo.
float peso_promedio(unsigned int longitud, persona_t arr[])
{
    float pesoProm, suma = 0;
    unsigned int i = 0;
    while (i < longitud)
    {
        suma = suma + arr[i].peso;
        i = i + 1;
    }
    pesoProm = suma / longitud;
    return pesoProm;
}

// Devuelve la persona de mayor edad.
persona_t persona_de_mayor_edad(unsigned int longitud, persona_t arr[])
{
    persona_t personaMayor;
    unsigned int i = 1;
    personaMayor = arr[0];
    while (i < longitud)
    {
        if (arr[i].edad > personaMayor.edad)
        {
            personaMayor = arr[i];
        }
        i = i + 1;
    }
    return personaMayor;
}

// Devuelve la persona de menor altura.
persona_t persona_de_menor_altura(unsigned int longitud, persona_t arr[])
{
    persona_t personaMenor;
    unsigned int i = 0;
    personaMenor = arr[0];
    while (i < longitud)
    {
        if (arr[i].altura < personaMenor.altura)
        {
            personaMenor = arr[i];
        }
        i = i + 1;
    }
    return personaMenor;
}

// Prueba de Ejecución:
    // El peso promedio es 74.666664
    // El nombre de la persona con mayor edad es Luis
    // El nombre de la persona con menor altura es Julio