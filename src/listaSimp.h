#ifndef LISTASIMP_H
#define LISTASIMP_H

#include "retangulo.h"

typedef void *ListaE;
typedef void *ItemE;

/*
    Este modulo contem toda a implementacao referente ao TAD lista 
    simplesmente encadeada estatica
*/

//Cria uma lista simplesmente encadeada estatica
ListaE createListaE(int nx);

//Retorna o tamanho total da lista
int lengthE(ListaE lista);

//Retorna a quantidade de nos visitados da lista
double getNodosE(ListaE lista);

//Insere um elemento na lista
ListaE insertE(ListaE lista, ItemE item);

//Retorna o item de um elemento da lista, neste caso um retangulo
ItemE getItemE(ListaE lista, int p);

//Remove e desaloca um elemento da lista
ListaE removeE(ListaE lista, int p);

//Retorna o indice do primeiro elemento da lista
int getFirstE(ListaE lista);

//Retorna o indice do elemento da lista posterior ao do indice parametro
int getNextE(ListaE lista, int p);

//Remove e desaloca toda a lista
void removeAllE(ListaE lista);

/* Funcao especial que so deve ser utilizada para retangulos. Retorna o retangulo cujo id 
é igual ao passado no parametro*/
ItemE getRetanguloPeloIdE(ListaE lista, char *id);

/* Funcao especial que so deve ser utilizada para retangulos.
Retorna a posicao na lista cujo retangulo com determinado id se encontra */
int getIntPeloIdE(ListaE lista, char *id);

//Retorna o elemento anterior a posicao passada nos parametros
int getPreviousE(ListaE lista, int p);

//insere um elemento apos o elemento na posicao passada
ListaE insertAfterE(ListaE lista, int p, ItemE item);

//insere um elemento antes do elemento na posicao passada
ListaE insertBeforeE(ListaE lista, int p, ItemE item);

#endif
