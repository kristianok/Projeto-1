#include "qry.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Lista sobreposicao(Lista lista , int listaDupla, FILE* txt){  
    Lista listaCores = criarCores();
    Posic corAtual = getFirst(listaCores);
    char *cor = (char*) getItem(corAtual);
    double x,y,w,h,x1,y1,w1,h1;
    double xl1,xr1,yl1,yr1,xl2,xr2,yl2,yr2;
    Posic retAtual,retNextAtual;
    Retangulo ret;
    Retangulo retNext;
    int i = 0;
    int retAtualE,retNextAtualE;
    if(listaDupla){
        retAtual = getFirst(lista);
        ret = getItem(retAtual);
        retNextAtual = getNext(lista,retAtual);
        retNext = getItem(retNextAtual);
    }
    else {
        retAtualE = getFirstE(lista);
        ret = getItemE(lista,retAtualE);
        retNextAtualE = getNextE(lista,retAtualE);
        retNext = getItemE(lista,retNextAtualE);
    }
    while(ret != NULL){
        if(retNext == NULL){
            break;
        }
        while(retNext != NULL && ret != NULL){
            x = getX(ret);
            y = getY(ret);
            w = getW(ret);
            h = getH(ret);
            x1 = getX(retNext);
            y1 = getY(retNext);
            w1 = getW(retNext);
            h1 = getH(retNext);
            xl1 = x;
            xr1 = x+w;
            yl1 = y+h;
            yr1 = y;
            xl2 = x1;
            xr2 = x1+w1;
            yl2 = y1+h1;
            yr2 = y1; 
	        if(!((xl1 >= xr2 || xl2 >= xr1) || (yl1 <= yr2 || yl2 <= yr1)) && ret!=retNext){
                setPreenchimento(ret,cor);
                setPreenchimento(retNext,cor);
                fprintf(txt,"%s / %s\n",getId(ret),getId(retNext));
	        }
            if(listaDupla){
                retNextAtual = getNext(lista,retNextAtual);
                retNext = getItem(retNextAtual);
            }
            else{
                retNextAtualE = getNextE(lista,retNextAtualE);
                retNext = getItemE(lista,retNextAtualE);
            }
        }
        corAtual = getNext(listaCores,corAtual);   
            cor = (char *) getItem(corAtual);
        if(cor == NULL){
            corAtual = getFirst(listaCores);
            cor = (char*) getItem(corAtual);  
        }
        if(listaDupla){
            retAtual = getNext(lista,retAtual);     
            ret = getItem(retAtual);
            retNextAtual = getNext(lista,retAtual);
            retNext = getItem(retNextAtual);
        }
        else{
            retAtualE = getNextE(lista,retAtualE);     
            ret = getItemE(lista,retAtualE);
            retNextAtualE = getNextE(lista,retAtualE);
            retNext = getItemE(lista,retNextAtualE);  
        }
    }
    removeAll(listaCores);
    return lista;
}

Lista sobreposicaoCompleta(Lista lista , int listaDupla, double x2, double y2, double w2, double h2, FILE* txt){	
	Lista listaCores = criarCores();
    Posic corAtual = getFirst(listaCores);
    char *cor = (char*) getItem(corAtual);
    double x,y,w,h,x1,y1,w1,h1;
    double xl1,xr1,yl1,yr1,xl2,xr2,yl2,yr2,xl3,xr3,yl3,yr3;
    Posic retAtual,retNextAtual;
    Retangulo ret;
    Retangulo retNext;
    int i = 0;
    int retAtualE,retNextAtualE;
    if(listaDupla){
        retAtual = getFirst(lista);
        ret = getItem(retAtual);
        retNextAtual = getNext(lista,retAtual);
        retNext = getItem(retNextAtual);
    }
    else {
        retAtualE = getFirstE(lista);
        ret = getItemE(lista,retAtualE);
        retNextAtualE = getNextE(lista,retAtualE);
        retNext = getItemE(lista,retNextAtualE);
    }
    xl3 = x2;
    xr3 = x2+w2;
    yl3 = y2+h2;
    yr3 = y2; 
    while(ret != NULL){
        if(retNext == NULL){
            break;
        }
        while(retNext != NULL && ret != NULL){
            x = getX(ret);
            y = getY(ret);
            w = getW(ret);
            h = getH(ret);
            x1 = getX(retNext);
            y1 = getY(retNext);
            w1 = getW(retNext);
            h1 = getH(retNext);
            xl1 = x;
            xr1 = x+w;
            yl1 = y+h;
            yr1 = y;
            xl2 = x1;
            xr2 = x1+w1;
            yl2 = y1+h1;
            yr2 = y1; 
            xl3 = x2;
            xr3 = x2+w2;
            yl3 = y2+h2;
            yr3 = y2; 
	        if(!((xl1 >= xr2 || xl2 >= xr1) || (yl1 <= yr2 || yl2 <= yr1)) && ret!=retNext){
                if((xl1 >= xl3 && xr1<= xr3 && yr1 >= yr3 && yl1 <= yl3) && (xl2 >= xl3 && xr2<= xr3 && yr2 >= yr3 && yl2 <= yl3)){
                    setPreenchimento(ret,cor);
                    setPreenchimento(retNext,cor);
                    fprintf(txt,"%s / %s\n",getId(ret),getId(retNext));
	            }
            }
            if(listaDupla){
                retNextAtual = getNext(lista,retNextAtual);
                retNext = getItem(retNextAtual);
            }
            else{
                retNextAtualE = getNextE(lista,retNextAtualE);
                retNext = getItemE(lista,retNextAtualE);
            }
        }
        corAtual = getNext(listaCores,corAtual);   
            cor = (char *) getItem(corAtual);
        if(cor == NULL){
            corAtual = getFirst(listaCores);
            cor = (char*) getItem(corAtual);  
        }
        if(listaDupla){
            retAtual = getNext(lista,retAtual);     
            ret = getItem(retAtual);
            retNextAtual = getNext(lista,retAtual);
            retNext = getItem(retNextAtual);
        }
        else{
            retAtualE = getNextE(lista,retAtualE);     
            ret = getItemE(lista,retAtualE);
            retNextAtualE = getNextE(lista,retAtualE);
            retNext = getItemE(lista,retNextAtualE);  
        }
    }
    removeAll(listaCores);
    return lista;
}

Lista removerDpi(Lista lista, int ListaDupla, FILE* txt, double x1, double y1){
    Posic retAtual;
	double retAtualE,x,y,w,h;
	Retangulo ret;
	if(ListaDupla){
		retAtual = getFirst(lista);
        ret = getItem(retAtual);
	}
	else {
        retAtualE = getFirstE(lista);
        ret = getItemE(lista,retAtualE);
    }
	while(ret != NULL){
        x = getX(ret);
        y = getY(ret);
        w = getW(ret);
        h = getH(ret);
        if(x1 < x + w && x1 > x && y1 > y && y1 < y+h){
            fprintf(txt,"%s\n",getId(ret));
            if(ListaDupla){
                Posic aux = getNext(lista,retAtual);
                lista = removeD(lista,retAtual);
                retAtual = aux;
                ret = getItem(aux);
            }
            else{
                int aux = getNextE(lista,retAtualE);
                lista = removeE(lista,retAtualE);
                retAtualE = aux;
                ret = getItemE(lista,aux);
            }
        }
		else if(ListaDupla){
            retAtual = getNext(lista,retAtual);     
            ret = getItem(retAtual);
        }
        else{
            retAtualE = getNextE(lista,retAtualE);     
            ret = getItemE(lista,retAtualE);
        }
	}
    return lista;
}

Lista removerDr(char* id, Lista lista, int ListaDupla, FILE* txt){
    Retangulo ret;
    Posic retAtual;
	int retAtualE;
    if(ListaDupla)
        ret = getRetanguloPeloId(lista,id);
    else
        ret = getRetanguloPeloIdE(lista,id);
    double x,y,h,w,xl1,xr1,yl1,yr1,xl2,xr2,yl2,yr2,xl3,xr3,yl3,yr3;
    x = getX(ret);
    y = getY(ret);
    w = getW(ret);
    h = getH(ret);
    xl3 = x;
    xr3 = x+w;
    yl3 = y+h;
    yr3 = y; 
	if(ListaDupla){
		retAtual = getFirst(lista);
        ret = getItem(retAtual);
	}
	else {
        retAtualE = getFirstE(lista);
        ret = getItemE(lista,retAtualE);
    }
	while(ret != NULL){
        x = getX(ret);
        y = getY(ret);
        w = getW(ret);
        h = getH(ret);
        xl1 = x;
        xr1 = x+w;
        yl1 = y+h;
        yr1 = y; 
        if(xl1 >= xl3 && xr1<= xr3 && yr1 >= yr3 && yl1 <= yl3 && strcmp(id,getId(ret))!= 0){
            fprintf(txt,"%s\n",getId(ret));
            if(ListaDupla){
                Posic aux = getNext(lista,retAtual);
                lista = removeD(lista,retAtual);
                retAtual = aux;
                ret = getItem(aux);
            }
            else{
                int aux = getNextE(lista,retAtualE);
                lista = removeE(lista,retAtualE);
                retAtualE = aux;
                ret = getItemE(lista,aux);
            }
        }
		else if(ListaDupla){
            retAtual = getNext(lista,retAtual);     
            ret = getItem(retAtual);
        }
        else{
            retAtualE = getNextE(lista,retAtualE);     
            ret = getItemE(lista,retAtualE);
        }
	}
    return lista;
}
Lista bbi(Lista lista, Lista listaQry, int ListaDupla, FILE* txt,double x1, double y1){
    Posic retAtual;
	double x,y,w,h,xb=100000000,yb=100000000,xmb=0,ymb=0,wb=0,hb=0;
    int retAtualE;
	Retangulo ret;
	if(ListaDupla){
		retAtual = getFirst(lista);
        ret = getItem(retAtual);
	}
	else {
        retAtualE = getFirstE(lista);
        ret = getItemE(lista,retAtualE);
    }
	while(ret != NULL){
        x = getX(ret);
        y = getY(ret);
        w = getW(ret);
        h = getH(ret);
        if(x1 < x + w && x1 > x && y1 > y && y1 < y+h){
            if(x < xb)
                xb = x;
            if(y < yb)
                yb = y;
            if(xmb < x + w)
                xmb = x + w;
            if(ymb < y + h)
                ymb = y + h;
            fprintf(txt,"%s, cp: %s, cc: %s\n",getId(ret),getPreenchimento(ret),getBorda(ret));
            char* aux = getPreenchimento(ret);
            setPreenchimento(ret,getBorda(ret));
            setBorda(ret,aux);
        }
		if(ListaDupla){
            retAtual = getNext(lista,retAtual);     
            ret = getItem(retAtual);
        }
        else{
            retAtualE = getNextE(lista,retAtualE);     
            ret = getItemE(lista,retAtualE);
        }
	}
    wb = xmb - xb;
    hb = ymb - yb;
    if(ListaDupla){
        insert(listaQry,criarRetangulo("red","black","",xb,yb,wb,hb));
        insert(listaQry,criarRetangulo("purple","orange","circle",x1,y1,3,3));
    }
    else{
        insertE(listaQry,criarRetangulo("red","black","",xb,yb,wb,hb));
        insertE(listaQry,criarRetangulo("purple","orange","circle",x1,y1,3,3));
    }
    return lista;
}
Lista bbid(Lista lista, Lista listaQry, int ListaDupla, FILE* txt, char* id){
    Retangulo ret;
    Posic retAtual;
	int retAtualE;
    double x,y,w,h,xb=100000000,yb=100000000,xmb=0,ymb=0,wb=0,hb=0,xl1,xr1,yl1,yr1,xl3,xr3,yl3,yr3;;
    if(ListaDupla)
        ret = getRetanguloPeloId(lista,id);
    else
        ret = getRetanguloPeloIdE(lista,id);
    x = getX(ret);
    y = getY(ret);
    w = getW(ret);
    h = getH(ret);
    xl3 = x;
    xr3 = x+w;
    yl3 = y+h;
    yr3 = y; 
	if(ListaDupla){
		retAtual = getFirst(lista);
        ret = getItem(retAtual);
	}
	else {
        retAtualE = getFirstE(lista);
        ret = getItemE(lista,retAtualE);
    }
	while(ret != NULL){
        x = getX(ret);
        y = getY(ret);
        w = getW(ret);
        h = getH(ret);
        xl1 = x;
        xr1 = x+w;
        yl1 = y+h;
        yr1 = y; 
        if(xl1 >= xl3 && xr1<= xr3 && yr1 >= yr3 && yl1 <= yl3 && strcmp(id,getId(ret))!= 0){
            if(x < xb)
                xb = x;
            if(y < yb)
                yb = y;
            if(xmb < x + w)
                xmb = x + w;
            if(ymb < y + h)
                ymb = y + h;
            fprintf(txt,"%s, cp: %s, cc: %s\n",getId(ret),getPreenchimento(ret),getBorda(ret));
            char* aux = getPreenchimento(ret);
            setPreenchimento(ret,getBorda(ret));
            setBorda(ret,aux);     
        }
		if(ListaDupla){
            retAtual = getNext(lista,retAtual);     
            ret = getItem(retAtual);
        }
        else{
            retAtualE = getNextE(lista,retAtualE);     
            ret = getItemE(lista,retAtualE);
        }
	}
    wb = xmb - xb;
    hb = ymb - yb;
    if(ListaDupla){
        insert(listaQry,criarRetangulo("red","black","",xb,yb,wb,hb));
    }
    else{
        insertE(listaQry,criarRetangulo("red","black","",xb,yb,wb,hb));
    }
    return lista;
}

Lista iid(Lista lista, int ListaDupla, FILE* txt, SvgFile svgQry, double k, char* id, int diid){
    Retangulo ret;
    Posic retAtual;
	int retAtualE,deletou=0;
    if(ListaDupla){
        ret = getRetanguloPeloId(lista,id);
        retAtual = getPosicPeloId(lista,id);
    }
    else{
        ret = getRetanguloPeloIdE(lista,id);
        retAtualE = getIntPeloIdE(lista,id);
    }
    if(k < 0){
        for(int i = 0; i >= k; i--){
            fprintf(txt,"%s, x: %f, y: %f, w: %f, h:%f cp: %s, cc: %s\n",getId(ret),getX(ret),getY(ret),getW(ret),getH(ret),getPreenchimento(ret),getBorda(ret));
            deletou = 0;
            if(diid && strcmp(getId(ret),id)!= 0){
                if(ListaDupla){
                    Posic aux = getPrevious(lista,retAtual);
                    lista = removeD(lista,retAtual);
                    retAtual = aux;
                    ret = getItem(aux);
                }
                else{
                    int aux = getPreviousE(lista,retAtualE);
                    lista = removeE(lista,retAtualE);
                    retAtualE = aux;
                    ret = getItemE(lista,aux);
                }
                deletou = 1;
            }
            if(deletou == 0 && ListaDupla){
            retAtual = getPrevious(lista,retAtual);     
            ret = getItem(retAtual);
            }
            else if (deletou == 0){
            retAtualE = getPreviousE(lista,retAtualE);     
            ret = getItemE(lista,retAtualE);
            }
            if(ret == NULL)
                break;
        }
    }
    else if (k > 0){
        for(int i = 0; i <= k; i++){
            fprintf(txt,"%s, x: %f, y: %f, w: %f, h:%f cp: %s, cc: %s\n",getId(ret),getX(ret),getY(ret),getW(ret),getH(ret),getPreenchimento(ret),getBorda(ret));
            deletou = 0;
            if(diid && strcmp(getId(ret),id)!= 0){
                if(ListaDupla){
                    Posic aux = getNext(lista,retAtual);
                    lista = removeD(lista,retAtual);
                    retAtual = aux;
                    ret = getItem(aux);
                }
                else{
                    int aux = getNextE(lista,retAtualE);
                    lista = removeE(lista,retAtualE);
                    retAtualE = aux;
                    ret = getItemE(lista,aux);
                }
                deletou = 1;
            }
            if(deletou == 0 && ListaDupla){
            retAtual = getNext(lista,retAtual);     
            ret = getItem(retAtual);
            }
            else if(deletou == 0){
            retAtualE = getNextE(lista,retAtualE);     
            ret = getItemE(lista,retAtualE);
            }
            if(ret == NULL)
                break;
        }
    }
    return lista;
}
Lista criarCores(){
    Lista listaCores = createLista();
    listaCores = insert(listaCores,"blue");
    listaCores = insert(listaCores,"green");
    listaCores = insert(listaCores,"firebrick");
    listaCores = insert(listaCores,"yellow");
    listaCores = insert(listaCores,"black");
    listaCores = insert(listaCores,"purple");
    listaCores = insert(listaCores,"grey");
    listaCores = insert(listaCores,"brown");
    listaCores = insert(listaCores,"red");
    listaCores = insert(listaCores,"pink");
    return listaCores;
}
