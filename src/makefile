CFLAGS=-std=c99 -fstack-protector-all

progr: progrdin 

progrdin:
	gcc $(CFLAGS) -c listaDup.c -o listaDup.o 
	gcc $(CFLAGS) -c listaSimp.c -o listaSimp.o 
	gcc $(CFLAGS) -c retangulo.c -o retangulo.o 
	gcc $(CFLAGS) -c path.c -o path.o 
	gcc $(CFLAGS) -c svg.c -o svg.o 
	gcc $(CFLAGS) -c qry.c -o qry.o 
	gcc $(CFLAGS) main.c listaDup.o listaSimp.o retangulo.o path.o svg.o qry.o -o progrdin
	cp progrdin progrest

clean:
	rm *.o
	rm progrdin
	rm progrest

