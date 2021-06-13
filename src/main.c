#include "main.h"
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
	int tamanhoLista;
	FILE* nodos, *geo, *qry;
	SvgFile grafico;
	int i=1,desempenho=2,ListaDupla = 1;
	char *nomeArqGeo=NULL, *nomeArqQry=NULL, *pathBED=NULL, *pathBSD=NULL, *arqGeo=NULL, *arqQry=NULL; 
	char *id=NULL, *nomeArqDesempenho=NULL, *arqDesempenho=NULL, *nodosPer=NULL, *titulo =NULL;
	char geoP[25],qryP[25],qtdRets[25],x[25],y[25],w[25],h[25], idQry[30];
	//Coleta dos parametros do programa
	while(i<argc){
		if (strcmp("-e",argv[i])==0){
		i++;
		if(argc-1 < i){
			printf("Parametros insuficientes");
			exit(0);
		}
		pathBED = (char *)malloc((strlen(argv[i])+1)*sizeof(char));
		strcpy(pathBED,argv[i]);
		}
	
		else if (strcmp("-f",argv[i])==0){
			i++;
			if(argc-1 < i){
				printf("Parametros insuficientes");
				exit(0);
			}
		nomeArqGeo = (char *)malloc((strlen(argv[i])+1)*sizeof(char));
		strcpy(nomeArqGeo,argv[i]);
		}	
	
		else if (strcmp("-o",argv[i])==0){
			i++;
			if(argc-1 < i){
				printf("Parametros insuficientes");
				exit(0);
			}
			pathBSD = (char *)malloc((strlen(argv[i])+1)*sizeof(char));
			strcpy(pathBSD,argv[i]);
		}
	
		else if (strcmp("-q",argv[i])==0){
			i++;
			if(argc-1 < i){
				printf("Parametros insuficientes");
				exit(0);
			}
			nomeArqQry = (char *)malloc((strlen(argv[i])+1)*sizeof(char));
			strcpy(nomeArqQry,argv[i]);
		}

		else if (strcmp("-ib",argv[i])==0){
			desempenho = 0;
		}
		else if (strcmp("-cb",argv[i])==0){
			desempenho = 0;
		}
		else if (strcmp("-fb",argv[i])==0){
			i++;
			if(argc-1 < i){
				printf("Parametros insuficientes");
				exit(0);
			}
			nomeArqDesempenho = (char *)malloc((strlen(argv[i])+1)*sizeof(char));
			strcpy(nomeArqDesempenho,argv[i]);
			i++;
			if(argc-1 < i){
				printf("Parametros insuficientes");
				exit(0);
			}
			titulo = (char*)malloc((strlen(argv[i])+1)*sizeof(char));
			strcpy(titulo,argv[i]);
			desempenho = 1;
		}	
		else if(strcmp("-ldd",argv[i])==0){
			ListaDupla = 1;
		}
		else if(strcmp("-lse",argv[i])==0){
			ListaDupla = 0;
		}
		i++;
	}
	Lista listaRetangulos, listaQry;
	if(ListaDupla)
		listaRetangulos = createLista();
		listaQry = createLista();
	arqGeo = concatPathFile(pathBED,nomeArqGeo);
	nomeArqGeo = removerPathDoNome(nomeArqGeo);
	geo = fopen(arqGeo,"r");
	if(geo == NULL){
		printf("Nao foi possivel encontrar o arquivo geo");
		exit(0);
	}
	char corBorda[30],corCentro[30], SqtdRets[20], *nomeArqSvg,*arqSvg, *corC, *corB;
	arqSvg = concatPathFile(pathBSD,addSuffix(removeSuffix(nomeArqGeo),".svg"));
	SvgFile svg = newSvgFile(arqSvg);
	Retangulo retangulo;
	fscanf(geo, "%s", geoP);
	while(1==1){	
		if(feof(geo)){
			break;	
		}
		if(strcmp("nx",geoP)==0){
			fscanf(geo, "%s", SqtdRets);
			if(ListaDupla==0){
				listaRetangulos = createListaE(atof(SqtdRets));
				listaQry = createListaE(atof(SqtdRets));
			}
		}
		else if(strcmp("cc",geoP)==0){
			fscanf(geo, "%s", corBorda);
		}
		else if(strcmp("cp",geoP)==0){
			fscanf(geo, "%s", corCentro);
		}
		else if(strcmp("r",geoP)==0){
			id = (char*) malloc(sizeof(char)*50);
			fscanf(geo, "%s", id);	
			fscanf(geo, "%s", x);
			fscanf(geo, "%s", y);
			fscanf(geo, "%s", w);
			fscanf(geo, "%s", h);
			corB = (char*) malloc(sizeof(char)*strlen(corBorda));
			strcpy(corB,corBorda);
			corC = (char*) malloc(sizeof(char)*strlen(corCentro));
			strcpy(corC,corCentro);
			retangulo = criarRetangulo(corB,corC,id,atof(x),atof(y),atof(w),atof(h));
			if(ListaDupla){
				insert(listaRetangulos,retangulo);
			}
			else {
				insertE(listaRetangulos,retangulo);
			}
			insertRectangle(svg,atof(x),atof(y),atof(w),atof(h),corC, corB, 1.0);
		}
		fscanf(geo, "%s", geoP);
	}
	closeSvgFile(svg);
	if(ListaDupla)
		tamanhoLista = length(listaRetangulos);
	else
		tamanhoLista = lengthE(listaRetangulos);

	arqQry = concatPathFile(pathBED,nomeArqQry);
	if(arqQry == NULL){
		exit(0);
	}
	nomeArqQry = removerPathDoNome(nomeArqQry);
	qry = fopen(arqQry,"r");
	if(qry == NULL){
		printf("Nao foi possivel encontrar o arquivo qry");
		exit(0);
	}
	fscanf(qry,"%s",qryP);
	char k[30];
	char* txtNome = concatPathFile(pathBSD,addSuffix(addSuffix(addSuffix(removeSuffix(nomeArqGeo),"-"),removeSuffix(nomeArqQry)),".txt"));
    char* svgNome = concatPathFile(pathBSD,addSuffix(addSuffix(addSuffix(removeSuffix(nomeArqGeo),"-"),removeSuffix(nomeArqQry)),".svg"));
	FILE* txt = fopen(txtNome,"w");
	if(txt == NULL){
		printf("Nao foi possivel escrever no arquivo txt");
		exit(0);
	}
    SvgFile svgQry = newSvgFile(svgNome);
	while(1==1){
		if(feof(qry)){
			break;
		}
		if(strcmp("tp",qryP)==0){
			fprintf(txt,"tp\n");
			listaRetangulos = sobreposicao(listaRetangulos, ListaDupla, txt);
		}
		else if(strcmp("tpr",qryP)==0){
			fprintf(txt,"tpr\n");
			fscanf(qry, "%s", x);
			fscanf(qry, "%s", y);
			fscanf(qry, "%s", w);
			fscanf(qry, "%s", h);
			listaRetangulos = sobreposicaoCompleta(listaRetangulos, ListaDupla, atof(x), atof(y),atof(w),atof(h), txt);
			insertRectangleTransparent(svgQry, atof(x), atof(y),atof(w),atof(h),"red","red",2.0);
		}
		else if(strcmp("dpi",qryP)==0){
			fprintf(txt,"dpi\n");
			fscanf(qry, "%s", x);
			fscanf(qry, "%s", y);
			listaRetangulos = removerDpi(listaRetangulos, ListaDupla, txt, atof(x), atof(y));
		}
		else if(strcmp("dr",qryP)==0){
			fprintf(txt,"dr\n");
			fscanf(qry, "%s", idQry);
			listaRetangulos = removerDr(idQry,listaRetangulos, ListaDupla, txt);
		}
		else if(strcmp("bbi",qryP)==0){
			fprintf(txt,"bbi\n");
			fscanf(qry, "%s", x);
			fscanf(qry, "%s", y);
			listaRetangulos = bbi(listaRetangulos,listaQry, ListaDupla, txt,atof(x),atof(y));
		}
		else if(strcmp("bbid",qryP)==0){
			fprintf(txt,"bbid\n");
			fscanf(qry, "%s", idQry);
			listaRetangulos = bbid(listaRetangulos, listaQry, ListaDupla, txt, idQry);
		}
		else if(strcmp("iid",qryP)==0){
			fprintf(txt,"iid\n");
			fscanf(qry, "%s", idQry);
			fscanf(qry, "%s", k);
			listaRetangulos = iid(listaRetangulos, ListaDupla, txt,svgQry, atof(k), idQry, 0);
		}
		else if(strcmp("diid",qryP)==0){
			fprintf(txt,"diid\n");
			fscanf(qry, "%s", idQry);
			fscanf(qry, "%s", k);
			listaRetangulos = iid(listaRetangulos, ListaDupla, txt,svgQry, atof(k), idQry, 1);
		}
		fscanf(qry,"%s",qryP);	
	}
	Posic retAtual;
	int retAtualE,contadorEscala;
	Retangulo ret;
	//Percorrer a lista principal e printar os retangulos no svg
	if(ListaDupla){
		retAtual = getFirst(listaRetangulos);
        ret = getItem(retAtual);
	}
	else {
        retAtualE = getFirstE(listaRetangulos);
        ret = getItemE(listaRetangulos,retAtualE);
    }
	while(ret != NULL){
		insertRectangle(svgQry,getX(ret),getY(ret),getW(ret),getH(ret),getPreenchimento(ret),getBorda(ret),1.0);
		if(ListaDupla){
            retAtual = getNext(listaRetangulos,retAtual);     
            ret = getItem(retAtual);
        }
        else{
            retAtualE = getNextE(listaRetangulos,retAtualE);     
            ret = getItemE(listaRetangulos,retAtualE);
        }
	}

	//Percorrer a lista auxiliar para mostrar no svg a bounding box e o ponto
	if(ListaDupla){
		retAtual = getFirst(listaQry);
        ret = getItem(retAtual);
	}
	else {
        retAtualE = getFirstE(listaQry);
        ret = getItemE(listaQry,retAtualE);
    }
	while(ret != NULL){
		if(strcmp(getId(ret),"circle") != 0)
			insertRectangleTransparent(svgQry,getX(ret),getY(ret),getW(ret),getH(ret),getPreenchimento(ret),getBorda(ret),2.0);
		else
			insertCircle(svgQry,getX(ret),getY(ret),getW(ret),getPreenchimento(ret),getBorda(ret),2.0);

        if(ListaDupla){
            retAtual = getNext(listaQry,retAtual);     
            ret = getItem(retAtual);
        }
        else{
            retAtualE = getNextE(listaQry,retAtualE);     
            ret = getItemE(listaQry,retAtualE);
        }
	}
	if(desempenho == 0 || desempenho == 1) {
		nodos = fopen("nodos.txt","a");
		if(ListaDupla){
			fprintf(nodos," %s ",SqtdRets);
		}
		else{
			fprintf(nodos,"%s ",SqtdRets);
		}
		if(ListaDupla){
			fprintf(nodos,"%f ",getNodos(listaRetangulos));
			contadorEscala = getNodos(listaRetangulos);
		}
		else{
			fprintf(nodos,"%f ",getNodosE(listaRetangulos));
			contadorEscala = getNodosE(listaRetangulos);
		}
		fclose(nodos);
	}
	if(desempenho == 1){
		char nodosPercorridos[100],tamanho[20];
		double maiorX,maiorY,xEscalado,yEscalado;
		nodos = fopen("nodos.txt","r");
		if(nodos == NULL){
			printf("Nao ha desempenho sendo analisado");
			exit(0);
		}
		arqDesempenho = concatPathFile(pathBSD,nomeArqDesempenho);
		arqDesempenho = addSuffix(arqDesempenho,".svg");
		grafico = newSvgFile(arqDesempenho);
		while(1==1){
			fscanf(nodos,"%s",tamanho);
			if(feof(nodos)){
				break;
			}
			fscanf(nodos,"%s",nodosPercorridos);
			xEscalado = atof(tamanho);
			yEscalado = atof(nodosPercorridos);
			if(maiorX < xEscalado)
				maiorX = xEscalado;
			if(maiorY < yEscalado)
				maiorY = yEscalado;	
		}
		int escalaY = 1;
  		while(maiorY/escalaY > 1000){
   			escalaY++;
   		}
		int escalaX = 1;
  		while(maiorX/escalaX > 1000){
   			escalaX++;
   		}
		//Fechar e reabrir o arquivo para reiniciar a STREAM
		fclose(nodos);
		fopen("nodos.txt","r");
		while(1==1){
			fscanf(nodos,"%s",tamanho);
			if(feof(nodos)){
				break;
			}
			fscanf(nodos,"%s",nodosPercorridos);
			xEscalado = atof(tamanho)/escalaX;
			yEscalado = atof(nodosPercorridos)/escalaY;
			double maiorXEscalado, maiorYEscalado,escalaTotalX,escalaTotalY;
			maiorXEscalado=maiorX/escalaX;
			maiorYEscalado=maiorY/escalaY;
			escalaTotalX = (100000/maiorXEscalado)/100;
			escalaTotalY = (100000/maiorYEscalado)/100;
			insertCircle(grafico,xEscalado*escalaTotalX,yEscalado*escalaTotalY,5.0,"black","white",1.0);
			insertLinhaTracejada(grafico,0,yEscalado*escalaTotalY,xEscalado*escalaTotalX,yEscalado*escalaTotalY);
			insertLinhaTracejada(grafico,xEscalado*escalaTotalX,0,xEscalado*escalaTotalX,yEscalado*escalaTotalY);
		}
		insertGrafico(grafico,maiorX,maiorY,escalaX,escalaY,1050,1050);
		insertPalavras(grafico,500,-80,titulo,40);
		closeSvgFile(grafico);
		fclose(nodos);
		remove("nodos.txt");
	}
	if(ListaDupla){
		removeAll(listaRetangulos);
	}
	else{
		removeAllE(listaRetangulos);
	}
	closeSvgFile(svgQry);
    fclose(txt);
	return 0;
}
