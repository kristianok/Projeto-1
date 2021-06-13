#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "svg.h"

struct StSvgFile {
   FILE *fsvg;
   char *cp, *cb;
   double wb;
};

typedef struct StSvgFile *SvgFileImpl;

SvgFile newSvgFile(char *nomeArq){
   FILE *f = fopen(nomeArq,"w");
   if (f == NULL){
     return NULL;
   }

   SvgFileImpl fsf = (SvgFileImpl) malloc (sizeof(struct StSvgFile));
   fsf->fsvg = f;
   fsf->cp = NULL;
   fsf->cb = NULL;
   fsf->wb = 0.0;

   fprintf(fsf->fsvg,"<svg>\n");
   return fsf;
}


void insertRectangle(SvgFile f, double x, double y,double w, double h, char *cp, char *cb, double wb){
   SvgFileImpl fsf = (SvgFileImpl) f;
   fprintf(fsf->fsvg,"<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" stroke=\"%s\"  fill=\"%s\"  stroke-width=\"%f\"/>\n", x,y,w,h,cb,cp,wb);

}

void insertRectangleTransparent(SvgFile f, double x, double y,double w, double h, char *cp, char *cb, double wb){
   SvgFileImpl fsf = (SvgFileImpl) f;
   fprintf(fsf->fsvg,"<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill-opacity=\"0\" stroke=\"%s\"  fill=\"%s\"  stroke-width=\"%f\"  stroke-dasharray=\"4\"/>\n", x,y,w,h,cb,cp,wb);

}

void insertCircle(SvgFile f, double x, double y, double r, char *cp, char *cb, double wb){
   SvgFileImpl fsf = (SvgFileImpl) f;
   fprintf(fsf->fsvg,"<circle cx=\"%f\" cy=\"%f\" r=\"%f\" stroke=\"%s\" stroke-width=\"%f\" fill=\"%s\"/>\n",x,y,r,cb,wb,cp);
}

void insertRectanglePadrao(SvgFile f, double x1, double y1,double x2, double y2){
   SvgFileImpl fsf = (SvgFileImpl) f;
   insertRectangle(f,x1,y1,x2,y2,fsf->cp,fsf->cb,fsf->wb);
}

void closeSvgFile(SvgFile f){
   SvgFileImpl fsf = (SvgFileImpl) f;
   fprintf(fsf->fsvg,"</svg>\n");
   fclose(fsf->fsvg);
   free(fsf);
}

void insertGrafico(SvgFile f, double maiorX, double maiorY, int escalaX, int escalaY, double tamanhoX, double tamanhoY){
   SvgFileImpl fsf = (SvgFileImpl) f;
   double xEscalado, yEscalado;
   xEscalado = maiorX/escalaX;
   yEscalado = maiorY/escalaY;
   double xPalito=maiorX/10, yPalito=maiorY/10;
   fprintf(fsf->fsvg,"<line x1=\"0\" x2=\"%f\" y1=\"0\" y2=\"0\" stroke-width=\"2.0\" stroke=\"black\" fill=\"black\"/>\n",tamanhoX);
   fprintf(fsf->fsvg,"<line x1=\"0\" x2=\"0\" y1=\"0\" y2=\"%f\" stroke-width=\"2.0\" stroke=\"black\" fill=\"black\"/>\n",tamanhoY);
   //Tracos no eixo y
   for(double i = 100; i<=1000;i+=100){
      fprintf(fsf->fsvg,"<line x1=\"-8\" x2=\"8\" y1=\"%f\" y2=\"%f\" stroke-width=\"1.0\" stroke=\"black\" fill=\"black\"/>\n",i,i);
      insertTxt(f,-80,i,yPalito);
      yPalito = yPalito+maiorY/10;
   }
   yPalito=(maiorY/10)/2;
   //Tracos no eixo x
   for(double i = 100; i<=1000;i+=100){
      fprintf(fsf->fsvg,"<line x1=\"%f\" x2=\"%f\" y1=\"-8\" y2=\"8\" stroke-width=\"1.0\" stroke=\"black\" fill=\"black\"/>\n",i,i);
      insertTxt(f,i-15,-10,xPalito);
      xPalito = xPalito+maiorX/10;
   }
   xPalito = (maiorX/10)/2;
   //eixo Y
   for(double i = 50; i<=1000;i+=100){
      fprintf(fsf->fsvg,"<line x1=\"-5\" x2=\"5\" y1=\"%f\" y2=\"%f\" stroke-width=\"1.0\" stroke=\"black\" fill=\"black\"/>\n",i,i);
      insertTxt(f,-75,i,yPalito);
      yPalito = yPalito + maiorY/10;
   }
   //eixo X
   for(double i = 50; i<=1000;i+=100){
      fprintf(fsf->fsvg,"<line x1=\"%f\" x2=\"%f\" y1=\"-5\" y2=\"5\" stroke-width=\"1.0\" stroke=\"black\" fill=\"black\"/>\n",i,i);
      insertTxt(f,i-15,-8,xPalito);
      xPalito = xPalito+maiorX/10;
   }
}

void insertTxt(SvgFile f, double x, double y, double valor){
   SvgFileImpl fsf = (SvgFileImpl) f;
   fprintf(fsf->fsvg,"<text x=\"%f\" y=\"%f\" fill=\"black\" font-size=\"10\"> \"%.1f\" </text>\n",x,y,valor);
}

void insertLinhaTracejada(SvgFile f,double x, double y, double x2, double y2){
   SvgFileImpl fsf = (SvgFileImpl) f;
   fprintf(fsf->fsvg,"<line x1=\"%f\" x2=\"%f\" y1=\"%f\" y2=\"%f\" stroke-width=\"1.0\" stroke=\"black\" fill=\"black\" stroke-dasharray=\"4\"/>\n",x,x2,y,y2);
}

void insertPalavras(SvgFile f, double x, double y, char* frase, double tamanhoFonte){
   SvgFileImpl fsf = (SvgFileImpl) f;
   fprintf(fsf->fsvg,"<text x=\"%f\" y=\"%f\" fill=\"black\" font-size=\"%f\"> \"%s\" </text>\n",x,y,tamanhoFonte,frase);
}