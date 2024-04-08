#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    // inicializo las variables del struct
    res.is_upperbound = true;
    res.is_lowerbound = true;
    res.exists = false;
    res.where = 0;
    // recorro todos los elementos del arreglo
    for(unsigned int i = 0; i<length; i++){
        // comparo el valor en posicion [i] con "value" y uso conjuncion para determinar el valor final
        res.is_upperbound = (value>=arr[i])&&(res.is_upperbound);
        res.is_lowerbound = (value<=arr[i])&&(res.is_lowerbound);
        // si hay un valor igual en el arreglo, guardo su posicion y vuelve "true" a "exist"
        if (value==arr[i]){
            res.exists = true;
            res.where = i;
        }   
    }
    return res;
}

int main(void) {
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    int value=9;
    // solicito al usuario que ingrese los valores del arreglo (la cantidad esta definida por ARRAY_SIZE)
    for(unsigned int i = 0; i<ARRAY_SIZE; i++){
        printf("Ingrese un valor numerico para la posicion %d del arreglo: ",i);
        scanf("%d",&a[i]);
    }
    // solicito al usuario un valor para comprar los elementos del arreglo
    printf("Ingrese un valor numerico para comparar los valores del arreglo: ");
    scanf("%d",&value);    
    //
    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    // modificado para mostrar por pantalla el resultado correspondiente segun la consigna
    if(result.is_upperbound){
        if(result.exists){
            printf("El valor ingresado es el maximo del arreglo\n");
            printf("Se encuentra en posicion %d",result.where);
        }
        else {
            printf("El valor ingresado es cota superior del arreglo\n");

        }
    }
    if(result.is_lowerbound){
        if(result.exists){
            printf("El valor ingresado es el minimo del arreglo\n");
            printf("Se encuentra en posicion %d",result.where);
        }
        else {
            printf("El valor ingresado es cota inferior del arreglo\n");

        }
    }
    // comento la siguiente linea por no ser parte de la consigna, pero me parecio bueno que exista la opcion
    // if(!(result.is_lowerbound)&&!(result.is_upperbound)){
    //     printf("El valor ingresado no es cota superior ni inferior del arreglo.\n");
    // }
    return EXIT_SUCCESS;
}