#include "listaSimp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct StElemListaE{
	int prox;
	ItemE it;
};

typedef struct StElemListaE ElemListaE;

struct StListaE{
    ElemListaE *lst;
	int prim, livre, tamanhoMax;
    double nodos;
};

typedef struct StListaE *ListaImplE;

ListaE createListaE(int nx){
	ListaImplE lista = (ListaImplE) malloc(sizeof(struct StListaE));
    ElemListaE *elementos = (ElemListaE*) malloc(sizeof(ElemListaE)*nx);
    lista->lst = elementos;
    for(int i=0;i<nx-1;i++){
        elementos[i].prox = i+1;
    }
    elementos[nx-1].prox = -1;
    lista->prim = -1;
    lista->livre = 0;
    lista->tamanhoMax = nx;
    lista->nodos=0;
    return lista;
}

double getNodosE(ListaE lista){
	ListaImplE represInterna = (ListaImplE) lista;
	return represInterna->nodos;
}

int lengthE(ListaE lista){
    ListaImplE represInterna = (ListaImplE) lista;
    return represInterna->tamanhoMax;
}

ListaE insertE(ListaE lista, ItemE item){
    ListaImplE represInterna = (ListaImplE) lista;
    if(represInterna == NULL){
        return NULL;
    }
    if(represInterna->livre == -1){
        return represInterna;
    }
    if(represInterna->prim==-1){
        represInterna->prim = 0;
    }
    ElemListaE *elementos = represInterna->lst;
	ElemListaE *novoElemento = (ElemListaE*) malloc(sizeof(ElemListaE));
	int aux = elementos[represInterna->livre].prox;
    novoElemento->it=item;
    novoElemento->prox=-1;
    elementos[represInterna->livre] = *novoElemento;
    for(int i = 0;i<represInterna->tamanhoMax;i++){
        if(elementos[i].prox == -1 && i != represInterna->livre){
            elementos[i].prox = represInterna->livre;
        }
        represInterna->nodos++;
    }
    represInterna->livre = aux;
    represInterna->lst=elementos;
    return represInterna;
}

ListaE removeE(ListaE lista, int p){
    ListaImplE represInterna = (ListaImplE) lista;
    ElemListaE *elementos = represInterna->lst;
    if(represInterna == NULL){
        return NULL;
    }
    if(p > represInterna->tamanhoMax){
        return NULL;
    }
    if(represInterna->prim == -1){
        return represInterna;
    }
    if(p == represInterna->prim){
        represInterna->prim = elementos[p].prox;
    }
    for(int i = 0;i<represInterna->tamanhoMax;i++){
        if(elementos[i].prox == p){
            elementos[i].prox = elementos[p].prox;
         }
         represInterna->nodos++;
    }
    elementos[p].prox = represInterna->livre;
    represInterna->livre = p;
    represInterna->lst=elementos;
    return represInterna;
}

ItemE getItemE(ListaE lista, int p){
    ListaImplE represInterna = (ListaImplE) lista;
    if(p > represInterna->tamanhoMax-1 || p < 0){
        return NULL;
    }
    represInterna->nodos++;
    ElemListaE elemento = represInterna->lst[p];
    return elemento.it;
}

ItemE getRetanguloPeloIdE(ListaE lista, char *id){
    ListaImplE represInterna = (ListaImplE) lista;
    ElemListaE* elementos = represInterna->lst;
    ItemE elem;
    for(int i = 0;i<represInterna->tamanhoMax;i++){
        elem=elementos[i].it;
        if(strcmp(getId(elem),id)==0){
            return elem;
        }
        represInterna->nodos++;
    }
    printf("retangulo com esse id nao encontrado");
    return NULL;
}

int getIntPeloIdE(ListaE lista, char *id){
    ListaImplE represInterna = (ListaImplE) lista;
    ElemListaE* elementos = represInterna->lst;
    ItemE elem;
    for(int i = 0;i<represInterna->tamanhoMax;i++){
        elem=elementos[i].it;
        if(strcmp(getId(elem),id)==0){
            return i;
        }
        represInterna->nodos++;
    }
    printf("retangulo com esse id nao encontrado");
    return -1;
}

int getFirstE(ListaE lista){
    ListaImplE represInterna = (ListaImplE) lista;
    if(represInterna->prim == -1){
        return -1; 
    }
    return represInterna->prim;
}

int getNextE(ListaE lista, int p){
    ListaImplE represInterna = (ListaImplE) lista;
    ElemListaE *elementos = represInterna->lst;
    if(p<0 || p>=represInterna->tamanhoMax-1){
        return -1;
    }
    represInterna->nodos++;
    int elemento = elementos[p].prox;
    return elemento;
}

int getPreviousE(ListaE lista, int p){
    ListaImplE represInterna = (ListaImplE) lista;
    ElemListaE *elementos = represInterna->lst;
    if(p<0 || p>=represInterna->tamanhoMax-1){
        return -1;
    }
    for(int i = 0;i<p;i++){
        if(elementos[i].prox == p){
            return i;
        }
        represInterna->nodos++;
    }
    return -1;
}

void removeAllE(ListaE lista){
    ListaImplE represInterna = (ListaImplE) lista;
	int aux;
	free(represInterna->lst);
	free(represInterna);
}

ListaE insertAfterE(Lista lista, int p, ItemE item){
    if(p == -1){
        return lista;
    }
    if(lista == NULL){
        return lista;
    }
    ListaImplE represInterna = (ListaImplE) lista;
    ElemListaE *elementos = represInterna->lst;
    ElemListaE elemento = represInterna->lst[p];
    ElemListaE *novoElemento = (ElemListaE*) malloc(sizeof(ElemListaE));
    novoElemento->it = item;
    novoElemento->prox = elemento.prox;
    int aux = elementos[represInterna->livre].prox;
    elementos[represInterna->livre] = *novoElemento;
    elemento.prox = represInterna->livre;
    represInterna->livre = aux;
    represInterna->lst = elementos;
}

ListaE insertBeforeE(Lista lista, int p, ItemE item){
    if(p == -1){
        return lista;
    }
    if(lista == NULL){
        return lista;
    }
    ListaImplE represInterna = (ListaImplE) lista;
    ElemListaE *elementos = represInterna->lst;
    ElemListaE elemento = represInterna->lst[p];
    for(int i = 0; i<represInterna->tamanhoMax;i++){
        if(elementos[i].prox == p){
            elementos[i].prox = represInterna->livre;
        }
        else if(i == represInterna->tamanhoMax - 1){
            printf("Nao existe a posicao p na lista");
            return lista;
        }
        represInterna->nodos++;
    }
    ElemListaE *novoElemento = (ElemListaE*) malloc(sizeof(ElemListaE));
    novoElemento->it = item;
    novoElemento->prox = p;
    int aux = elementos[represInterna->livre].prox;
    elementos[represInterna->livre] = *novoElemento;
    represInterna->livre = aux;
    represInterna->lst = elementos;
}
