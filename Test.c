#include<stdio.h>
#include"Progetto.h"

int main(void){
	struct	relBin RelazioneBinaria;


	RelazioneBinaria = acquisizione(RelazioneBinaria);
	
	stampa(RelazioneBinaria);
	ordine_totale(RelazioneBinaria);
	relazione_equivalenza(RelazioneBinaria);
	check_funzione(RelazioneBinaria);
	return(0);
}
