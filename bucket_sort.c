//
// Created by furfa on 19/9/2022.
//
#include <stdlib.h>
#include <stdio.h>
#include "bucket_sort.h"


void BucketSort(int *array) {
    lista *buckets1[NUMERO_BUCKETS],*buckets2[NUMERO_BUCKETS];

    inicializarBuckets(buckets1);
    inicializarBuckets(buckets2);

    for (int i = 0; i < TAMANIO_ARREGLO; ++i)
        {insertar_en_bucket(buckets1, newnodo(array[i]));}

    //mostrarbuckets(buckets1);
    concatenar(array, buckets1);

    for (int i = 0; i < TAMANIO_ARREGLO; ++i)
        {insertar_en_bucket2(buckets2, newnodo(array[i]));}

    //mostrarbuckets(buckets2);
    concatenar(array,buckets2);
}

lista *newLista() {
    lista * aux= malloc(sizeof(lista));
    aux->principio=NULL;
    aux->fin=NULL;
    aux->elementos=0;
    return aux;
}

nodo *newnodo(int n) {
    nodo * aux= malloc(sizeof(nodo));
    aux->dato=n;
    aux->sig=NULL;
    return aux;
}

int hash1iteracion(int valor) {
    return valor%NUMERO_BUCKETS;
}

int hash2iteracion(int valor) {
    return valor/NUMERO_BUCKETS;
}

void encolar(lista *cola, nodo *nodoAencolar) {
    if(cola->principio==NULL)
    {
        cola->principio=nodoAencolar;
        cola->fin=nodoAencolar;
    } else{
        cola->fin->sig=nodoAencolar;
        cola->fin=nodoAencolar;
    }
    cola->elementos++;
}

void inicializarBuckets(lista * buckest[NUMERO_BUCKETS]) {
    for (int i = 0; i < NUMERO_BUCKETS; ++i) {
        buckest[i]=newLista();
    }
}

void insertar_en_bucket(lista *buckest[NUMERO_BUCKETS], nodo *nodo1) {
    int cubeta= hash1iteracion(nodo1->dato);
    encolar(buckest[cubeta], nodo1);
}

void insertar_en_bucket2(lista *buckest[NUMERO_BUCKETS], nodo *nodo1) {
    int cubeta= hash2iteracion(nodo1->dato);
    encolar(buckest[cubeta],nodo1);
}

void mostrar(lista *lista1) {
    nodo *aux=lista1->principio;
    for (;aux!=NULL ; aux=aux->sig) {
        printf("%d-",aux->dato);
    }
    printf("\n");
}

void mostrarbuckets(lista **buckets) {
    printf("Elemento de cada bucket:\n");
    for (int i = 0; i < NUMERO_BUCKETS; ++i) {
        printf("Bucket %d: ",i);
        mostrar(buckets[i]);
    }
    printf("\n");
}

void concatenar(int *array, lista *buckets[]) {
    if (buckets[0]->principio==NULL){
        for (int i = 1; i < NUMERO_BUCKETS ; i++) {
            if (buckets[i]->fin != NULL){
                buckets[0]->principio=buckets[i]->principio;
                buckets[0]->fin=buckets[i]->fin;
                buckets[i]->fin=NULL;
                break;}
        }
    }
    for (int j = 1; j < NUMERO_BUCKETS; ++j) {
        if(buckets[j]->fin!=NULL)
        {
            buckets[0]->fin->sig=buckets[j]->principio;
            buckets[0]->fin=buckets[j]->fin;
        }
    }
    for (int j = 0; j <TAMANIO_ARREGLO ; ++j) {
        array[j]=buckets[0]->principio->dato;
        buckets[0]->principio=buckets[0]->principio->sig;
    }
}

void mostrarArray(int *array) {
    for (int i = 0; i < TAMANIO_ARREGLO; ++i) {
        printf("%d-",array[i]);
    }
    printf("\n\n");

}