//
// Created by furfa on 19/9/2022.
//
#include <stdlib.h>
#include <stdio.h>
#include "bucket_sort.h"


void BucketSort(int *array) {
    lista *buckets[NUMERO_BUCKETS],*buckets2[NUMERO_BUCKETS];
    inicializarBuckets(buckets);
    inicializarBuckets(buckets2);
    for (int i = 0; i < TAMANIO_ARREGLO; ++i) {
        insertar_en_bucket(buckets, newnodo(array[i]));
    }
    concatenar(array, buckets);
    for (int i = 0; i < TAMANIO_ARREGLO; ++i) {
        insertar_en_bucket2(buckets2, newnodo(array[i]));
    }
    concatenar(array,buckets2);
    //mostrarbuckets(buckets);
}

lista *newLista() {
    lista * aux= malloc(sizeof(lista));
    aux->principio=NULL;
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
    nodo *aux=cola->principio;
    if(cola->principio==NULL)
    {
        cola->principio=nodoAencolar;
        //cola->fin=nodoAencolar;
    } else{
        for (;aux->sig!=NULL ; aux=aux->sig) {}
        aux->sig=nodoAencolar;
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
}

void concatenar(int *array, lista *buckets[]) {
    for (int i = 0,j=0; i <NUMERO_BUCKETS ; ++i) {
        nodo *aux=buckets[i]->principio;
        while (aux!=NULL){
            array[j]=aux->dato;
            aux=aux->sig;
            j++;
        }
    }

}

void mostrarArray(int *array) {
    for (int i = 0; i < TAMANIO_ARREGLO; ++i) {
        printf("%d-",array[i]);
    }
    printf("\n");

}


