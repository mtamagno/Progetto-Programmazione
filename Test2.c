#include<stdio.h>
#include"Progetto.h"

int main(void){
	struct	relBin ciao;
	ciao = acquisizione(ciao);
	stampa(ciao);
	printf("\n %d \n \n",ciao.controllo);
	ordine_parziale(ciao);
/*	ordine_totale(ciao);*/
	return(0);
}
