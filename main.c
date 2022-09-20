#include <stdio.h>
#include "bucket_sort.h"
int main() {
    lista *buckets[NUMERO_BUCKETS];
    int array[TAMANIO_ARREGLO]={42,32,63,10,28,8,51,99,23,56,10,77,82,25,37,46,52,69,93,100};
    mostrarArray(array);
    inicializarBuckets(buckets);
    for (int i = 0; i < TAMANIO_ARREGLO; ++i) {
        insertar_en_bucket(buckets, newnodo(array[i]));
    }
    for (int i = 0; i < TAMANIO_ARREGLO; ++i){
     ordenar_buckets(buckets[i]);
    }
    mostrarbuckets(buckets);
    ordenar_array(array,buckets);
    printf("\n Arreglo ordenado:\n");
    mostrarArray(array);
    return 0;
}
