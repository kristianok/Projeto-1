#include "retangulo.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct retan {
	char *id, *corPreenchimento, *corBorda;
	double x,y,w,h;
};

typedef struct retan retangulo;

void freeRetangulo(Retangulo Ret){
	retangulo* rect = (retangulo*) Ret;
	free(rect->corBorda);
	free(rect->corPreenchimento);
	free(rect);
}
Retangulo criarRetangulo(char* corBorda, char* corCentro, char* id, double x, double y, double w, double h){
	retangulo* rect = (retangulo*)malloc(sizeof(retangulo));
	rect->id = id;
	rect->corBorda = corBorda;
	rect->corPreenchimento = corCentro;
	rect->x = x;
	rect->y = y;
	rect->w = w;
	rect->h = h;	
	return rect;
}

Retangulo setX(Retangulo Ret, double x){
	retangulo* ret = (retangulo*) Ret;
	ret->x = x;
	
}

Retangulo setY(Retangulo Ret, double y){
	retangulo* ret = (retangulo*) Ret;
	ret->y = y;	
	return ret;
}

Retangulo setW(Retangulo Ret, double w){
	retangulo* ret = (retangulo*) Ret;
	ret->w = w;
	return ret;
}

Retangulo setH(Retangulo Ret, double h){
	retangulo* ret = (retangulo*) Ret;
	ret->h = h;	
	return ret;
}

char* getId(Retangulo Ret){
	retangulo* ret = (retangulo*) Ret;
	return ret->id;
}

double getX(Retangulo Ret){
	retangulo* ret = (retangulo*) Ret;
	return ret->x;
}

double getY(Retangulo Ret){
	retangulo* ret = (retangulo*) Ret;
	return ret->y;	
}

double getW(Retangulo Ret){
	retangulo* ret = (retangulo*) Ret;
	return ret->w;
}

double getH(Retangulo Ret){
	retangulo* ret = (retangulo*) Ret;
	return ret->h;	
}

char* getPreenchimento(Retangulo Ret){
	retangulo* ret = (retangulo*) Ret;
	return ret->corPreenchimento;
}

char* getBorda(Retangulo Ret){
	retangulo* ret = (retangulo*) Ret;
	return ret->corBorda;
}

Retangulo setPreenchimento(Retangulo Ret, char* corP){
	retangulo* ret = (retangulo*) Ret;
	char* corPre = (char*) malloc(sizeof(char)*strlen(corP));
	strcpy(corPre, corP);
	ret->corPreenchimento=corPre;
	return ret;
}

Retangulo setBorda(Retangulo Ret, char* corB){
	retangulo* ret = (retangulo*) Ret;
	char* corBor = (char*) malloc(sizeof(char)*strlen(corB));
	strcpy(corBor, corB);
	ret->corBorda=corBor;
	return ret;
}




