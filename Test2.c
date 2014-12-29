#include<stdio.h>
#include"Progetto.h"

int main(void){
	struct	relBin ciao;
	ciao = acquisizione(ciao);
	stampa(ciao);
	printf("\n %d \n \n",ciao.controllo);
	verifica_rel_ordine(ciao);
	return(0);
}
