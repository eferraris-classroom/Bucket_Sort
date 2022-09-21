#include <stdio.h>
#include "bucket_sort.h"
int main() {
    int array[TAMANIO_ARREGLO]={42,32,63,12,28,8,51,96,23,56,10,77,82,25,37,46,52,69,93,99};
    printf("Datos inicio: \n");
    mostrarArray(array);
    BucketSort(array);
    printf("\n Arreglo ordenado:\n");
    mostrarArray(array);
    return 0;
}
