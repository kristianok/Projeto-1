#ifndef _SVGFILE_H__INCLUDE
#define _SVGFILE_H__INCLUDE
#include "retangulo.h"
#include "listaDup.h"
#include "listaSimp.h"
/*
    Este módulo prove operacoes para a criação de arquivos no formato svg. Um novo arquivo é criado por meio da operação newSvgFile (arquivo aberto) e é finalizado pela operação closeSvgFile (arquivo fechado).
    Várias operações para a inclusão de elementos svg podem ser invocados em arquivos
abertos, por exemplo, insertRectangle.
    Os elementos inseridos podem seguir o estilo padrão definido pela operação defineEstiloPadrao (veja, por exemplo, a operação insertRectanglePadrao)

 */

typedef void *SvgFile;

/*Insere a estrutura de um grafico com inicio na origem do arquivo svg para posteriormente inserir pontos.
Tem como parametros os maiores valores representados e a escala de cada eixo para definir os limites 
e as faixas de valores do grafico*/
void insertGrafico(SvgFile f,double maiorX, double maiorY, int escalaX, int escalaY,double tamanhoX, double tamanhoY);

//Insere um circulo no svg cujas propriedades sao passadas nos parametros
void insertCircle(SvgFile f, double x, double y, double r, char *cp, char *cb, double wb);

/*
    Cria um novo arquivo (texto) com o nome "nomeArq".
    Caso o arquivo não possa ser criado (por exemplo, path incorreto), retorna NULL.
    Caso o arquivo já exista, ele é sobre-escrito.
 */
SvgFile newSvgFile(char *nomeArq);

/* 
   Insere um retângulo no arquivo f.
 */
void insertRectangle(SvgFile f, double x, double y,double w, double h, char *cp, 
     char *cb, double wb);


// Insere um retangulo com opacidade 0 (transparente)
void insertRectangleTransparent(SvgFile f, double x, double y,double w, double h, char *cp, char *cb, double wb);
  
  /*
    Fecha o arquivo f. O efeito de qualquer outra operação sobre f é indeterminado.
 */
void closeSvgFile(SvgFile f);

//Insere um texto com valor numerico nas coordenadas indicadas nos parametros
void insertTxt(SvgFile f, double x, double y, double valor);

//Insere uma linha tracejada com inicio no ponto x,y e termino no ponto x2,y2
void insertLinhaTracejada(SvgFile f,double x, double y, double x2, double y2);

//Insere um txt no arquivo. Recebe como parametros caracteres alfanumericos e as coordenadas
void insertPalavras(SvgFile f, double x, double y, char* frase, double tamanhoFonte);
#endif
