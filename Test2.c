#include<stdio.h>
#include"Progetto.h"

int main(void){
	struct	relBin ciao;
	int i,c;
	
	i=0;
	ciao = acquisizione(ciao);
	
	stampa(ciao);
/*	ordine_totale(ciao);*/
	ordine_totale(ciao);
/*	relazione_equivalenza(ciao);*/
	check_funzione(ciao);
	return(0);
}
