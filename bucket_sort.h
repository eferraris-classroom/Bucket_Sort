//
// Created by furfa on 19/9/2022.
//

#ifndef BUCKET_SORT_BUCKET_SORT_H
#define BUCKET_SORT_BUCKET_SORT_H
#define TAMANIO_ARREGLO 20
#define NUMERO_BUCKETS 10
#define CAPACIDAD 10 //capacidad de cada cubeta

typedef struct Nodo{
    int dato;
    struct Nodo * sig;
}nodo;
typedef struct Lista{
    nodo * principio;
    nodo * fin;
    int elementos;
}lista;
lista * newLista();
nodo * newnodo(int n);
void inicializarBuckets(lista * buckest[]);
void insertar_en_bucket(lista * buckest[],nodo * nodo1);
void encolar(lista * lista1, nodo * nodoAinsertar);
int hash(int valor);
void ordenar_buckets(lista*buckest[],int pos);
void mostrar(lista * lista1);
void mostrarbuckets(lista * buckets[]);
void ordenar_array(int *array,lista * buckets[]);
void mostrarArray(int *array);

#endif //BUCKET_SORT_BUCKET_SORT_H
