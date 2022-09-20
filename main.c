#include <stdio.h>
#include "bucket_sort.h"
int main() {
    lista *buckets[NUMERO_BUCKETS];
    inicializarBuckets(buckets);
    int array[TAMANIO_ARREGLO]={42,32,63,12,28,8,51,96,23,56,10,77,82,25,37,46,52,69,93,99};
    mostrarArray(array);
    for (int i = 0; i < TAMANIO_ARREGLO; ++i) {
        insertar_en_bucket(buckets, newnodo(array[i]));
    }
    for (int i = 0; i < NUMERO_BUCKETS; ++i){
     ordenar_buckets(buckets,i);
    }
    mostrarbuckets(buckets);
    ordenar_array(array,buckets);
    printf("\n Arreglo ordenado:\n");
    mostrarArray(array);
    return 0;
}
