#ifndef RETANGULO_H
#define RETANGULO_H

#include "listaDup.h"
#include "listaSimp.h"

typedef void* Retangulo;

/*
    Este modulo contem toda a implementacao referente ao TAD retangulo
    Contem as funcoes responsaveis pela manipulacao dos seus dados e de
    suas caracteristicas proprias 
*/

//Cria um retangulo para ser inserido posteriormente na lista
Retangulo criarRetangulo(char corBorda[], char corCentro[], char id[], double x, double y, double w, double h);

// Retorna os valores referentes ao parametro id do retangulo.
char* getId(Retangulo Ret);

// Retorna os valores referentes ao parametro x do retangulo.
double getX(Retangulo Ret);

// Retorna os valores referentes ao parametro y do retangulo.
double getY(Retangulo Ret);

// Retorna os valores referentes ao parametro w do retangulo.
double getW(Retangulo Ret);

// Retorna os valores referentes ao parametro h do retangulo.
double getH(Retangulo Ret);

// Retorna os valores referentes ao parametro cor de preenchimento do retangulo.
char* getPreenchimento(Retangulo Ret);

// Retorna os valores referentes ao parametro cor da borda do retangulo.
char* getBorda(Retangulo Ret);

// Define os valores referentes ao parametro cor da borda do retangulo.
Retangulo setBorda(Retangulo Ret, char* corB);

//Define os valores referentes ao parametro cor de preenchimento do retangulo.
Retangulo setPreenchimento(Retangulo Ret, char* corP);

//Desaloca um a memoria utilizada para um retangulo
void freeRetangulo(Retangulo Ret);

#endif
