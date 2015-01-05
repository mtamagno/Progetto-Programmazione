#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/********************STRUTTURA relBin**************************/

struct relBin{
	int *primo_termine,
		*secondo_termine;
		
	char **prima_stringa,
		 **seconda_stringa;
	
	int controllo,
		dimensione;
};



/*******************Funzione di acquisizione********************/

struct relBin acquisizione(struct relBin relazione){

int acquisizione_finita = 0;
relazione.dimensione = 0;

relazione.primo_termine = (int *) malloc(2);
relazione.secondo_termine = (int *) malloc(2);
relazione.prima_stringa = (char **) malloc(100);
relazione.seconda_stringa = (char **) malloc(100);

 while((relazione.controllo < 1) || (relazione.controllo > 2)){
fflush(stdin);
printf("\n Premi 1 se vuoi immettere solo numeri, 2 per altro\n ");
scanf("%d",&relazione.controllo);

}
/**/
/*Acquisizione Numerica*/
if(relazione.controllo == 1){
while(acquisizione_finita == 0){
	relazione.dimensione++;
	acquisizione_finita = 2;
 /*Acquisisco il primo termine della coppia*/
 printf("\n Inserisci il primo termine della coppia \n ");
 relazione.primo_termine = (int *) realloc(relazione.primo_termine, (relazione.dimensione+1) * sizeof(int));
 /*Check del primo termine della coppia*/
	while((scanf("%d",&relazione.primo_termine[relazione.dimensione - 1])) != 1){
	fflush(stdin);
	printf("\n C'e' un errore, riinserire il primo termine\n");
	}
 
 /*Acquisisco il secondo termine della coppia*/
 printf("\n Inserisci il secondo termine della coppia \n ");
 relazione.secondo_termine = (int *) realloc(relazione.secondo_termine, (relazione.dimensione+1) * sizeof(int));
/*Check del secondo termine della coppia*/
	while((scanf("%d",&relazione.secondo_termine[relazione.dimensione - 1])) != 1){
	fflush(stdin);
	printf("\n C'e' un errore, riinserire il secondo termine\n");
	}

 /*Chiedo all'utente se ci sono altre coppie*/
 while(acquisizione_finita < 0 || acquisizione_finita > 1){
 printf("\n Vuoi acquisire un'altra coppia? immetti 1 per uscire, 0 per continuare\n ");
 scanf("%d",&acquisizione_finita);
 		}
	}
}

/*Acquisizione con stringhe*/
if(relazione.controllo == 2){
while(acquisizione_finita == 0){
	relazione.dimensione++;
	acquisizione_finita = 2;
 /*Acquisisco il primo termine della coppia*/
 printf(" Inserisci il primo termine della coppia \n ");
 relazione.prima_stringa[relazione.dimensione - 1] = (char *) malloc(50);
 scanf(" %[^\n]s",relazione.prima_stringa[relazione.dimensione - 1]);

 /*Acquisisco il secondo termine della coppia*/
 printf(" Inserisci il secondo termine della coppia \n ");


 relazione.seconda_stringa[relazione.dimensione - 1] = (char *) malloc(50);
 scanf(" %[^\n]s",relazione.seconda_stringa[relazione.dimensione - 1]);


 /*Chiedo all'utente se ci sono altre coppie*/
 while(acquisizione_finita < 0 || acquisizione_finita > 1){
 
 printf("\n Vuoi acquisire un'altra coppia? immetti 1 per uscire, 0 per continuare\n");
 scanf("%d",&acquisizione_finita);
 
 			}
		}
	}
printf("\n\n   ... Acquisizione Terminata ...\n\n");	
return relazione;
}

/******************************FUNZIONE DI STAMPA********************************/

void stampa(struct relBin stampa){
 
 int i = 0;
 
 printf("\n La relazione binaria e':");
 printf("\n\n  {");
 	
	 if(stampa.controllo == 1){
 		 while(i < stampa.dimensione){

     		printf("(%d,%d)",stampa.primo_termine[i],stampa.secondo_termine[i]);
 	 		if(i+1 != stampa.dimensione)
     			printf(";");
	 		i++;
		}
	 }
 
 
 	if(stampa.controllo == 2){
  		while(i < stampa.dimensione){
     		printf("(%s,%s)",stampa.prima_stringa[i],stampa.seconda_stringa[i]);
    	 if(i+1 != stampa.dimensione)
     		printf(";");
	 	i++;
	
		}
 	}
 	printf("}\n");
	printf("\n\n   ... Stampa Terminata ...\n\n");	

}

/******************FUNZIONE DI VERIFICA DI RELAZIONI D'ORDINE******************/

int ordine_parziale(struct relBin verifica){

	int riflessivita,
		transitivita,
		simmetria,	
		parziale;
		/*STAMPO LE PROPIETA' DELLA RELAZIONE*/
	printf("\n\n La relazione:\n\n");

	riflessivita = check_riflessivita(verifica);
	simmetria = check_simmetria(verifica);
	transitivita = check_transitivita(verifica);
	
	if(transitivita == 1 && simmetria == 0 && riflessivita == 1){
		parziale = 1;
		printf("\n Quindi e' una relazione d'ordine parziale\n\n");
	}
	else{
	
		printf("\n Non e' una relazione d'ordine parziale in quanto non rispetta tutte le propietà\n");
		parziale = 0;
	}
	printf("\n\n   ... Controllo Ordine Parziale Terminato ...\n\n");
	return(parziale);
}


/***********FUNZIONE PER CONTROLLARE LA RIFLESSIVITà**********/

int check_riflessivita (struct relBin verifica){

	int i,
		j,
		k,
		riscontro,
		secondo_riscontro,
		riflessivita;

	riflessivita = 1;
	i = 0;
	j = 0;
	k = 0;
	riscontro = 0;
	secondo_riscontro = 0;

/*Verifica riflessività*/

/*Definizione: una relazione per la quale esiste almeno un elemento che non e' in relazione con sé stesso non soddisfa la definizione di riflessività*/

	while((i < verifica.dimensione) && (k < verifica.dimensione)){

/*Verifica riflessività per numeri*/

		if(verifica.controllo == 1){
			riscontro = 0;
			secondo_riscontro = 0;
			if(verifica.primo_termine[i] == verifica.secondo_termine[i])
				riscontro++;
				secondo_riscontro++;
			if(riscontro != 0){
				i++;
				k++;
			}
		/**/
			else{
				j=0;
				riscontro = 0;
				secondo_riscontro = 0;
				
/***************** Controllo la riflessività per gli elementi del primo insieme ******************************/		
			
				while(j < verifica.dimensione){
					if(j == i)
						j++;
					else{
						if(verifica.primo_termine[i] == verifica.primo_termine[j])
							if(verifica.primo_termine[j] == verifica.secondo_termine[j])
								riscontro++;
						
					j++;
				}
			}
			
			j = 0;
			
/***************** Controllo la riflessività per gli elementi del secondo insieme ******************************/				
			
				while(j < verifica.dimensione){
					if(j == k)
						j++;
					else{
						if(verifica.secondo_termine[k] == verifica.secondo_termine[j])
							if(verifica.primo_termine[j] == verifica.secondo_termine[j])
								secondo_riscontro++;
						
					j++;
				}
			}
				if(riscontro != 0)
					i++;
			
				else{
					i=verifica.dimensione;
					riflessivita = 0;
				}
			
				if(secondo_riscontro != 0)
					k++;
			
				else{
					k=verifica.dimensione;
					riflessivita = 0;
				}	
			}
	
		}
	
	/* VERIFICA RIFLESSIVITà PER STRINGHE */
	
	if(verifica.controllo == 2){
		riscontro = 0;
		secondo_riscontro = 0;
		if(strcmp(verifica.prima_stringa[i],verifica.seconda_stringa[i]) == 0)
			riscontro++;
			secondo_riscontro++;
		if(riscontro != 0){
			i++;
			k++;
		}
		
		else{
			j=0;
			riscontro = 0;
			secondo_riscontro = 0;
				
/***************** Controllo la riflessività per gli elementi del primo insieme ******************************/		
			
			while(j < verifica.dimensione){
				if(j == i)
					j++;
				else{
					if(strcmp(verifica.prima_stringa[i],verifica.prima_stringa[j]) == 0)
						if(strcmp(verifica.prima_stringa[j],verifica.seconda_stringa[j]) == 0)
							riscontro++;
						
					j++;
				}
			}
			
			j = 0;
			
/***************** Controllo la riflessività per gli elementi del secondo insieme ******************************/				
			
			while(j < verifica.dimensione){
				if(j == k)
				j++;
				else{
					if(strcmp(verifica.seconda_stringa[k],verifica.seconda_stringa[j]) == 0)
						if(strcmp(verifica.prima_stringa[j],verifica.seconda_stringa[j]) == 0)
							secondo_riscontro++;
						
					j++;
				}
			}
			if(riscontro != 0)
				i++;
			
			else{
				i=verifica.dimensione;
				riflessivita = 0;
			}
			
			if(secondo_riscontro != 0)
				k++;
			
			else{
				k=verifica.dimensione;
				riflessivita = 0;
			}	
		}
		
	}
	
}
	if(riflessivita == 1)
		printf("   e' riflessiva\n");
	else
		printf("   non e' riflessiva\n");
	
	return(riflessivita);
}


/***********FUNZIONE PER CONTROLLARE LA SIMMETRIA**********/


int check_simmetria(struct relBin verifica){
	
	int i,
		j,
		k,
		riscontro,
		simmetria;

	simmetria = 1;	


	i = 0;
	j = 0;
	k = 0;
	riscontro = 0;


	if(verifica.controllo == 1){
		while( i < verifica.dimensione){
			j = 0;
			while( j < verifica.dimensione){		
				if(verifica.primo_termine[i] == verifica.secondo_termine[j])
					if(verifica.primo_termine[j] == verifica.secondo_termine[i])
						riscontro++;
				
				j++;
		}
		
			if(riscontro == 0){
				j = verifica.dimensione;
				i = verifica.dimensione;
				simmetria = 0;
			}
			riscontro = 0;
			i++;
		}	
	
	}

	if(verifica.controllo == 2){
		while( i < verifica.dimensione){
			j = 0;
			while( j < verifica.dimensione){		
				if(strcmp(verifica.prima_stringa[i],verifica.seconda_stringa[j]) == 0 )
					if(strcmp(verifica.prima_stringa[j],verifica.seconda_stringa[i]) == 0 )
						riscontro++;
			
				j++;
			}
		
			if(riscontro == 0){
				j = verifica.dimensione;
				i = verifica.dimensione;
				simmetria = 0;
			}
			riscontro = 0;	
			i++;
		}	
	
	}

	if(simmetria == 1)
		printf("   e' simmetrica\n");
	else
		printf("   e' asimmetrica\n");

	return(simmetria);
}

/*FUNZIONE PER CONTROLLARE LA TRANSITIVITà*/


int check_transitivita(struct relBin verifica){
	
	int i,
		j,
		k,
		transitivita;

/*SETTO LA TRANSITIVITA INIZIALMENTE COME VERA E AZZERO I CONTATORI*/
	transitivita = 1;
	i = 0;
	j = 0;
	k = 0;

/*VERIFICA TRANSITIVITà PER NUMERI*/


	if(verifica.controllo == 1){

	
		while(i < verifica.dimensione){
			j = 0;

			while(j < verifica.dimensione){
				k=0;

				if(verifica.secondo_termine[i] == verifica.primo_termine[j]){
					transitivita = 0;
					while(k < verifica.dimensione){
						
						if(verifica.primo_termine[i] == verifica.primo_termine[k]){
		 					if(verifica.secondo_termine[k]==verifica.secondo_termine[j]){
								 transitivita = 1;
								 j = verifica.dimensione;
								 k = verifica.dimensione;
							}
						}
						 k++;
		 			}

				}
				j++;
			}

			i++;	
		}
	}

	
/***************** VERIFICA TRANSITIVITà PER STRINGHE ****************/

	if(verifica.controllo == 2){


		while(i < verifica.dimensione){
			j = 0;

			while(j < verifica.dimensione){
				k=0;

				if(strcmp(verifica.seconda_stringa[i],verifica.prima_stringa[j]) == 0){
					transitivita = 0;
					while(k < verifica.dimensione){
						
						if(strcmp(verifica.prima_stringa[i],verifica.prima_stringa[k]) == 0){
		 					if(strcmp(verifica.seconda_stringa[k],verifica.seconda_stringa[j]) == 0){
								 transitivita = 1;
								 j = verifica.dimensione;
								 k = verifica.dimensione;
							}
						}
						 k++;
		 			}

				}
				j++;
			}

			i++;	
		}

	}

	
	if(transitivita == 1)
		printf("   e' transitiva\n");
	else
		printf("   non e' transitiva\n");
	return(transitivita);

}

/*RELAZIONE D'ORDINE TOTALE*/

int check_dicotomia(struct relBin verifica){

	int a,b,c,d;
	int numero_elementi;
	int dicotomia = 0;
	int dimensione;
	int riscontro;
	int secondo_riscontro;
	a=0;
	b=0;
	c=0;
	d=a-1;
	dimensione = verifica.dimensione;
	
	if(verifica.controllo == 1){
		while( a < verifica.dimensione){
			d = a-1;
			b = a+1;
			secondo_riscontro = 0;
		if(a>0){
			while ( d >= 0 ){
				if(verifica.primo_termine[a] == verifica.primo_termine[d]){
					if(verifica.secondo_termine[a] == verifica.secondo_termine[d])
						secondo_riscontro = 1;
				}
				d--;
			}
		}
		
		if(secondo_riscontro != 1){
			while ( b < verifica.dimensione){
				if(verifica.primo_termine[a] == verifica.primo_termine[b])
					if(verifica.secondo_termine[a] == verifica.secondo_termine[b]){
						dimensione--;
				/*	secondo_riscontro--;*/
				}
			b++;
			}
		}
		a++;
	}
	
	
		a=0;
		b=0;
		c=0;
		numero_elementi=0;
		
		
	
		riscontro = 0;
	
		while(a<verifica.dimensione){
			d=a-1;
			secondo_riscontro = 0;
			
			while(d >= 0){
				if(verifica.primo_termine[a] == verifica.primo_termine[d])
					secondo_riscontro = 1;
					d--;
			}
			if(secondo_riscontro != 1){
				if(verifica.primo_termine[a] == verifica.secondo_termine[a])
					riscontro++;
					
			}
		a++;
		}
	
	numero_elementi = riscontro;
	
	
	c = numero_elementi;
	
	while(numero_elementi > 0){	
		numero_elementi--;
		c = c + numero_elementi;
		
		}
	}

/******************** VERIFICA DICOTOMICA PER STRINGHE *****************/

	if(verifica.controllo == 2){
	
		while( a < verifica.dimensione){
			b=a+1;
			while ( b < verifica.dimensione){
				if((strcmp(verifica.prima_stringa[a],verifica.prima_stringa[b])) == 0)
					if((strcmp(verifica.seconda_stringa[a],verifica.seconda_stringa[b])) == 0)
					dimensione--;
			b++;
			}
		a++;
		}
	
	
		a=0;
		b=0;
		c=0;
		numero_elementi=1;
	
		while(b<verifica.dimensione){
			if((strcmp(verifica.prima_stringa[a],verifica.prima_stringa[b])) != 0)
				numero_elementi++;
		b++;
		}
	
		c = numero_elementi;
	
		while(numero_elementi > 0){
	
			numero_elementi--;
			c = c + numero_elementi;
		
		}

	}
	
	if(dimensione == c)
		dicotomia = 1;
	
	if(dicotomia == 1 && (check_riflessivita(verifica) == 1))
		printf("   e' dicotomica\n\n");

	else
		printf("   non e' dicotomica\n\n");

	return(dicotomia);
}

/*Funzione di verifica dell'ordine totale*/


void ordine_totale (struct relBin verifica){
	
	int parziale,
		dicotomia;

	parziale = ordine_parziale (verifica);
	dicotomia = check_dicotomia (verifica);
	if(parziale == 0)
		printf(" \n l'ordine non e' totale in quanto non e' nemmeno parziale");

	if(dicotomia == 0)
		printf(" \n l'ordine non e' totale in quanto non viene rispettata la propieta' di dicotomia");

	if(dicotomia == 1 && parziale == 1)
		printf("\n Quindi e' una relazione d'ordine totale");
		
	printf("\n\n   ... Controllo Ordine Totale Terminato ...\n\n");	
}

/*Funzione che stabilisce se e' una relazione di equivalenza o meno*/

void relazione_equivalenza(struct relBin verifica){
	int riflessivita;
	int simmetria;
	int transitivita;
	
	riflessivita	= 	check_riflessivita(verifica);
	simmetria 		= 	check_simmetria(verifica);
	transitivita	=	check_transitivita(verifica);
	
	if(riflessivita == 1 && simmetria == 1 && transitivita == 1)
	printf("\n Quindi e' una relazione di equivalenza\n");
	if(riflessivita == 0)
	printf("\n Quindi non e' una relazione di equivalenza perche' non riflessiva\n");
	if(simmetria == 0)
	printf("\n Quindi non e' una relazione di equivalenza perche' non simmetrica\n");
	if(transitivita == 0)
	printf("\n Quindi non e' una relazione di equivalenza perche' non transitiva\n");	
}

/*Funzione che stabilisce se la relazione binaria acquisita e' una funzione matematica*/

void check_funzione(struct relBin verifica){
	int i;
	int k;
	int termini_diversi;
	int termini_uguali_prima;
	int termini_uguali_dopo;
	int errore;
	
	i=0;
	errore=0;
	termini_diversi=0;
	termini_uguali_dopo=0;
	termini_uguali_prima=0;
	while(i < verifica.dimensione){
		k=verifica.dimensione-1;
		termini_uguali_dopo=termini_uguali_prima;
		while(k > i){
			if(verifica.primo_termine[i] == verifica.primo_termine[k]){
				if(verifica.secondo_termine[i] != verifica.secondo_termine[k]){
					errore=1;
					printf("\n Nel %d elemento c'e' un errore che impedisce alla realzione binaria\n",k+1);
					printf("di essere una funzione\n");
					k=i;
					i=verifica.dimensione;
				}
				if(verifica.secondo_termine[i] == verifica.secondo_termine[k])
					termini_uguali_dopo++;
			}
			k--;
		}
		if(errore == 0 && termini_uguali_dopo == termini_uguali_prima)
		termini_diversi++;
		
		termini_uguali_prima = termini_uguali_dopo;
		i++;
	}
	if(errore == 0 && (termini_diversi == (verifica.dimensione - termini_uguali_prima)))
	printf("\n La relazione binaria e' una funzione\n");
	else
	printf("\n La relazione binaria non e' una funzione\n");
}

