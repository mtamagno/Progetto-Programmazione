#include<stdio.h>

#include"Progetto.h"

int main(void){
	struct	relBin ciao;
	ciao = acquisizione(ciao);
	stampa(ciao);
	ordine_parziale(ciao);
/*	ordine_totale(ciao);*/
	return(0);
}
