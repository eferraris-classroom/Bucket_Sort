//
// Created by furfa on 19/9/2022.
//

#ifndef BUCKET_SORT_BUCKET_SORT_H
#define BUCKET_SORT_BUCKET_SORT_H
#define TAMANIO_ARREGLO 20
#define NUMERO_BUCKETS 10

typedef struct Nodo{
    int dato;
    struct Nodo * sig;
}nodo;
typedef struct Lista{
    nodo * principio;
    int elementos;
}lista;
lista * newLista();
nodo * newnodo(int n);
void BucketSort(int *);
void inicializarBuckets(lista * buckest[]);
void insertar_en_bucket(lista * buckest[],nodo * nodo1);
void insertar_en_bucket2(lista * buckest[],nodo * nodo1);
void encolar(lista * lista1, nodo * nodoAinsertar);
int hash1iteracion(int valor);
int hash2iteracion(int valor);
void mostrar(lista * lista1);
void mostrarbuckets(lista * buckets[]);
void concatenar(int *array, lista * buckets[]);
void mostrarArray(int *array);

#endif //BUCKET_SORT_BUCKET_SORT_H
