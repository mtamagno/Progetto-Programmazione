#include<stdio.h>
#include"Progetto.h"

int main(void){
	struct	relBin ciao;
	ciao = acquisizione(ciao);
	stampa(ciao);
	verifica_rel_ordine(ciao);
	return(0);
}
