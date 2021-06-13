#ifndef QRY_H
#define QRY_H
#include "retangulo.h"
#include "listaDup.h"
#include "listaSimp.h"
#include "path.h"
#include "svg.h"
#include <stdio.h>

/*
    Este módulo prove operacoes para o funcionamento
    de todos os comandos de consultas solicitadas
    pelos arquivos qry
*/

/* O parametro ListaDupla determina o tipo de lista usada na função 
(duplamente encadeada dinamica ou simplesmente encadeada estatica)*/

//Usada para o comando tp, altera as cores dos retangulos que se sobrepoem em uma determinada lista
Lista sobreposicao(Lista lista , int listaDupla, FILE* txt);

/*Usada para o comando tpr, altera as cores dos retangulos que se sobrepoem em uma determinada lista e que
estejam dentro do retangulo dos parametros*/ 
Lista sobreposicaoCompleta(Lista lista , int ListaDupla, double x1, double y1, double w1, double h1, FILE* txt);

//Cria uma lista de 10 cores
Lista criarCores();

//Remove os retangulos cujo ponto x1 y1 e interno
Lista removerDpi(Lista lista, int ListaDupla, FILE* txt, double x1, double y1);

//Remove os retangulos dentro do retangulo com o id passado pelo parametro
Lista removerDr(char* id, Lista lista, int ListaDupla, FILE* txt);

//Desenha a bounding box do retangulos cujo ponto determinado nos parametros e interno
Lista bbi(Lista lista,Lista listaQry, int ListaDupla, FILE* txt, double x1, double y1);

//Desenha a bounding box dos retangulos inteiramente dentro do retangulo cujo id foi passado no parametro
Lista bbid(Lista lista, Lista listaQry, int ListaDupla, FILE* txt, char* id);

//Reporta ou deleta os k elementos posteriores ou anteriores do id passado nos parametros
Lista iid(Lista lista, int ListaDupla, FILE* txt, SvgFile svgQry, double k, char* id, int diid);

#endif