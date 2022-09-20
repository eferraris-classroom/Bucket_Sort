//
// Created by furfa on 19/9/2022.
//
#include <stdlib.h>
#include <stdio.h>
#include "bucket_sort.h"

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

int hash(int valor) {
    return valor/CAPACIDAD;
}

void encolar(lista *cola, nodo *nodoAencolar) {
    nodo *aux=cola->fin;
    if(cola->principio==NULL)
    {
        cola->principio=nodoAencolar;
        cola->fin=nodoAencolar;
    } else{
        aux->sig=nodoAencolar;
    }
    cola->elementos++;
}

void inicializarBuckets(lista * buckest[CAPACIDAD]) {
    for (int i = 0; i < CAPACIDAD; ++i) {
        buckest[i]=newLista();
    }
}

void insertar_en_bucket(lista *buckest[CAPACIDAD], nodo *nodo1) {
    int cubeta= hash(nodo1->dato);
    encolar(buckest[cubeta], nodo1);
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

void ordenar_array(int *array, lista **buckets) {
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

void ordenar_buckets(lista **buckest) {

}
