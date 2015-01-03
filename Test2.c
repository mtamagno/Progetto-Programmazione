#include<stdio.h>

#include"Progetto.h"

int main(void){
	struct	relBin ciao;
	int i,c;
	
	i=0;
	ciao = acquisizione(ciao);
	
	c = strcmp(ciao.seconda_stringa[0],ciao.prima_stringa[1]);
	printf("\n\n\n\n%d\n\n\n\n\n",c);
	
	stampa(ciao);
	ordine_parziale(ciao);
/*	ordine_totale(ciao);*/
	return(0);
}
