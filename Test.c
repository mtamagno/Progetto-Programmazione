#include<stdio.h>
#include"Progetto.h"

int main(void){
	struct	relBin RelazioneBinaria;
	int scelta;
	int scan;
	
	printf("\n Programma per effettuare i Test sulla libreria\n");
	
	
	printf("\n\n Digita il numero corrispondente all'azione che si vuole svolgere\n");
	printf("\n 1) Test Acquisizione\n 2) Esci\n");
	
	
	 while((scelta < 1) || (scelta > 2) || scan != 1){
		printf("\n scelta: ");
		fflush(stdin);
		scan = scanf("%d",&scelta);
	}
	if(scelta == 1)
	RelazioneBinaria = acquisizione(RelazioneBinaria);
	if(scelta == 2){
	printf("\n\n .....Test terminati......\n\n");
	return(0);
	}
	scelta = -1;
	while(scelta != 7){
	printf("\n\n Digita il numero corrispondente all'azione che si vuole svolgere\n");
	printf("\n 1) Test Acquisizione\n 2) Test Stampa\n 3) Test verifica ordine parziale\n 4) Test verifica ordine totale");
	printf("\n 5) Test verifica relazione d'equivalenza\n 6) Test funzione\n 7) Esci\n" );
	scelta = -1;
	while((scelta < 1) || (scelta > 7) || scan != 1){
		printf("\n scelta: ");
		fflush(stdin);
		scan = scanf("%d",&scelta);
	}
	
	
	if(scelta == 1)
		RelazioneBinaria = acquisizione(RelazioneBinaria);
	if(scelta == 2)
		stampa(RelazioneBinaria);
	if(scelta == 3)
		ordine_parziale(RelazioneBinaria);
	if(scelta == 4)
		ordine_totale(RelazioneBinaria);
	if(scelta == 5)
		relazione_equivalenza(RelazioneBinaria);
	if(scelta == 6)
		check_funzione(RelazioneBinaria);
	if(scelta == 7){
		printf("\n\n .....Test terminati......\n\n");
		return(0);
		}
	}
return(0);

}
