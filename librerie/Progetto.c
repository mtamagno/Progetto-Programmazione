#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	


rel_bin acquisizione (rel_bin);
int controllo_simmetria (rel_bin);
int controllo_riflessivita (rel_bin);
int controllo_transitivita (rel_bin);
int controllo_suriettivita (rel_bin);
void controllo_biiettivita (rel_bin);
int controllo_antisimmetria (rel_bin);
void controllo_funzione (rel_bin);
void relazione_equivalenza (rel_bin);
void ordine_totale (rel_bin);
int ordine_parziale (rel_bin);
void stampa (rel_bin);


/*******************Funzione di acquisizione********************/
rel_bin acquisizione (rel_bin relazione){

int acquisizione_finita = 0;
int risultato_lettura = 0;

relazione.dimensione = 0;
relazione.primo_termine = (double *) malloc (2);
relazione.secondo_termine = (double *) malloc (2);
relazione.prima_stringa = (char **) malloc (100);
relazione.seconda_stringa = (char **) malloc (100);

while (relazione.controllo < 1 || relazione.controllo > 2 || risultato_lettura != 1){
fflush (stdin);
printf ("\n Premi 1 se vuoi immettere solo numeri, 2 per altro\n ");
printf ("\n scelta: ");
risultato_lettura = scanf ("%d",&relazione.controllo);
}

/** imposto di nuovo risultato_lettura a 0 **/
risultato_lettura=0;

/*Acquisizione Numerica*/

if (relazione.controllo == 1){
	while (acquisizione_finita == 0){
		relazione.dimensione++;
		acquisizione_finita = 2;
 
 /*Acquisisco il primo termine della coppia*/
 
		printf ("\n Inserisci il primo termine della coppia \n ");
		relazione.primo_termine = (double *) realloc (relazione.primo_termine, (relazione.dimensione+1) * sizeof (double));
 		risultato_lettura = 0;
 /*controllo del primo termine della coppia*/

	while (risultato_lettura != 1){
		printf ("  Primo Termine: ");
		fflush (stdin);
		risultato_lettura = scanf ("%lf",&relazione.primo_termine[relazione.dimensione - 1]);
		if (risultato_lettura == 0)
		printf ("\n C'e'un errore, reinserire il primo termine\n");
		}
 		
 /*Acquisisco il secondo termine della coppia*/
 		risultato_lettura = 0;
	 	printf ("\n Inserisci il secondo termine della coppia \n ");
		relazione.secondo_termine = (double *) realloc (relazione.secondo_termine, (relazione.dimensione+1) * sizeof (double));

/*controllo del secondo termine della coppia*/

	while (risultato_lettura != 1){
		printf ("  Secondo Termine: ");
		fflush (stdin);
		risultato_lettura = scanf ("%lf",&relazione.secondo_termine[relazione.dimensione - 1]);
		if (risultato_lettura == 0)
		printf ("\n C'e'un errore, reinserire il secondo termine\n");
		}

 /*Chiedo all'utente se ci sono altre coppie*/
 
 	while (acquisizione_finita < 0 || acquisizione_finita > 1 || risultato_lettura != 1){
 		printf ("\n Vuoi acquisire un'altra coppia? immetti 1 per uscire, 0 per continuare\n ");
 		printf ("\n scelta: ");
 		fflush (stdin);
		risultato_lettura = scanf ("%d",&acquisizione_finita);
 		}
	}
}

/*imposto di nuovo risultato_lettura a 0*/
risultato_lettura = 0;

/*Acquisizione con stringhe*/
if (relazione.controllo == 2){
	while (acquisizione_finita == 0){
		relazione.dimensione++;
		acquisizione_finita = 2;

 /*Acquisisco il primo termine della coppia*/

 		printf (" Inserisci il primo termine della coppia \n ");
 		printf ("  Primo Termine: ");
		relazione.prima_stringa[relazione.dimensione - 1] = (char *) malloc (50);
		risultato_lettura = scanf (" %[^\n]s",relazione.prima_stringa[relazione.dimensione - 1]);

 /*Acquisisco il secondo termine della coppia*/

 		printf (" Inserisci il secondo termine della coppia \n ");
 		printf ("  Secondo Termine: ");
		 relazione.seconda_stringa[relazione.dimensione - 1] = (char *) malloc (50);
 		risultato_lettura = scanf (" %[^\n]s",relazione.seconda_stringa[relazione.dimensione - 1]);

/*imposto di nuovo risultato_lettura a 0*/
risultato_lettura = 0;

 /*Chiedo all'utente se ci sono altre coppie*/
		
		while (acquisizione_finita < 0 || acquisizione_finita > 1 || risultato_lettura != 1){
 
 			printf ("\n Vuoi acquisire un'altra coppia? immetti 1 per uscire, 0 per continuare\n");
 			risultato_lettura = scanf ("%d",&acquisizione_finita);
 			}
		}
	}

printf ("\n\n   ... Acquisizione Terminata ...\n\n");	
return (relazione);
}

/******************************FUNZIONE DI STAMPA********************************/

void stampa (rel_bin stampa){
 
 int i = 0;
 
 printf ("\n La relazione binaria e':");
 printf ("\n\n  {");
 	
/******Stampa per coppie numeriche *****/

	 if (stampa.controllo == 1){
 		 while (i < stampa.dimensione){

     		printf (" (%.2lf,%.2lf)",stampa.primo_termine[i],stampa.secondo_termine[i]);
 	 		if (i+1 != stampa.dimensione)
     			printf (" ;");
	 		i++;
		}
	 }
 
 /********Stampa  per coppie non numeriche *********/
 
 	if (stampa.controllo == 2){
  		while (i < stampa.dimensione){
     		printf (" (%s,%s)",stampa.prima_stringa[i],stampa.seconda_stringa[i]);
    	 if (i+1 != stampa.dimensione)
     		printf (";");
	 	i++;
	
		}
 	}
 	
/***************** Fine Stampa *******************/

 	printf ("}\n");
	printf ("\n\n   ... Stampa Terminata ...\n\n");	

}

/******************FUNZIONE DI VERIFICA DI RELAZIONI D'ORDINE******************/

int ordine_parziale (rel_bin verifica){

	int riflessivita,
		transitivita,
		antisimmetria,	
		parziale;
		
	/*STAMPO LE PROPIETA'DELLA RELAZIONE*/
	
	printf ("\n\n La relazione:\n\n");

/********* Chiamo le funzioni per poter stabilire le propietà ******************/

	riflessivita = controllo_riflessivita (verifica);
	antisimmetria = controllo_antisimmetria (verifica);
	transitivita = controllo_transitivita (verifica);

/************* Controllo se rispetta le propietà per essere una relazione d'ordine parziale************/
	
	if (transitivita == 1 && antisimmetria == 1 && riflessivita == 1){
		parziale = 1;
		printf ("\n Quindi e'una relazione d'ordine parziale\n\n");
	}
	else{
	
		printf ("\n Non e'una relazione d'ordine parziale in quanto non rispetta tutte le propieta'\n");
		parziale = 0;
	}
		if (transitivita == 0)
		printf ("\n manca la propieta'di transitivita'\n");
		if (antisimmetria == 0)
		printf ("\n manca la propieta'di antisimmetria\n");
		if (riflessivita == 0)
		printf ("\n manca la propieta'di riflessivita'\n");
/************* Fine controllo Ordine Parziale *********************/
	
	printf ("\n\n   ... Controllo Ordine Parziale Terminato ...\n\n\n\n");
	return (parziale);
}


/***********FUNZIONE PER CONTROLLARE LA RIFLESSIVITà**********/

int controllo_riflessivita (rel_bin verifica){

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

/*Definizione: una relazione per la quale esiste almeno un elemento che non e'in relazione con sé stesso non soddisfa la definizione di riflessività*/

	while ( (i < verifica.dimensione) && (k < verifica.dimensione)){

/*Verifica riflessività per numeri*/

		if (verifica.controllo == 1){
			riscontro = 0;
			secondo_riscontro = 0;
			if (verifica.primo_termine[i] == verifica.secondo_termine[i])
				riscontro++; /****Controllo se c'è stato un riscontro a,a****/
				secondo_riscontro++;
			if (riscontro != 0){
				i++;
				k++;
			}
		/**/
			else{
				j=0;
				riscontro = 0;
				secondo_riscontro = 0;
				
/***************** Controllo la riflessività per gli elementi del primo insieme ******************************/		
			
				while (j < verifica.dimensione){
					if (j == i)
						j++;
					else{
						if (verifica.primo_termine[i] == verifica.primo_termine[j])
							if (verifica.primo_termine[j] == verifica.secondo_termine[j])
								riscontro++;
						
					j++;
				}
			}
			
			j = 0;
			
/***************** Controllo la riflessività per gli elementi del secondo insieme ******************************/				
			
				while (j < verifica.dimensione){
					if (j == k)
						j++;
					else{
						if (verifica.secondo_termine[k] == verifica.secondo_termine[j])
							if (verifica.primo_termine[j] == verifica.secondo_termine[j])
								secondo_riscontro++;
						
					j++;
				}
			}
				if (riscontro != 0)
					i++;
	
/**** Se non c'è stato un riscontro di riflessività esco e imposto la riflessività a 0 *****/			
				
				else{
					i=verifica.dimensione;
					riflessivita = 0;
				}
			
				if (secondo_riscontro != 0)
					k++;
			
				else{
					k=verifica.dimensione;
					riflessivita = 0;
				}	
			}
	
		}
	
	/*************** VERIFICA RIFLESSIVITà PER STRINGHE *****************/
	
	if (verifica.controllo == 2){
		riscontro = 0;
		secondo_riscontro = 0;
		if (strcmp (verifica.prima_stringa[i],verifica.seconda_stringa[i]) == 0)
			riscontro++;
			secondo_riscontro++;
		if (riscontro != 0){
			i++;
			k++;
		}
		
		else{
			j=0;
			riscontro = 0;
			secondo_riscontro = 0;
				
/***************** Controllo la riflessività per gli elementi del primo insieme ******************************/		
			
			while (j < verifica.dimensione){
				if (j == i)
					j++;
				else{
					if (strcmp (verifica.prima_stringa[i],verifica.prima_stringa[j]) == 0)
						if (strcmp (verifica.prima_stringa[j],verifica.seconda_stringa[j]) == 0)
							riscontro++;
						
					j++;
				}
			}
			
			j = 0;
			
/***************** Controllo la riflessività per gli elementi del secondo insieme ******************************/				
			
			while (j < verifica.dimensione){
				if (j == k)
				j++;
				else{
					if (strcmp (verifica.seconda_stringa[k],verifica.seconda_stringa[j]) == 0)
						if (strcmp (verifica.prima_stringa[j],verifica.seconda_stringa[j]) == 0)
							secondo_riscontro++;
						
					j++;
				}
			}
			if (riscontro != 0)
				i++;
			
			else{
				i=verifica.dimensione;
				riflessivita = 0;
			}
			
			if (secondo_riscontro != 0)
				k++;
			
			else{
				k=verifica.dimensione;
				riflessivita = 0;
			}	
		}
		
	}
	
}

/********* Controllo se è riflessiva *******************/

	if (riflessivita == 1)
		printf ("   e'riflessiva\n");
	else
		printf ("   non e'riflessiva\n");

/*********** Fine riflessivita ***********************/
	
	return (riflessivita);
}



/**************************** FUNZIONE PER CONTROLLARE LA SIMMETRIA *******************/

/************* Definizione: In matematica, una relazione binaria R in un insieme X è **/
/************* simmetrica se e solo se,presi due elementi qualsiasi a e b, vale che  **/
/************* se a è in relazione con b allora anche b è in relazione con a. *********/

int controllo_simmetria (rel_bin verifica){
	
	int i,
		j,
		riscontro,
		simmetria;

	simmetria = 1;	


	i = 0;
	j = 0;
	riscontro = 0;

/*controllo della simmetria per numeri*/

	if (verifica.controllo == 1){
		
		while ( i < verifica.dimensione){
			
			j = 0;
			while ( j < verifica.dimensione){	
				
				if (verifica.primo_termine[i] == verifica.secondo_termine[j])
					if (verifica.primo_termine[j] == verifica.secondo_termine[i])
						riscontro++;
				j++;
		}
		
			if (riscontro == 0){
				j = verifica.dimensione;
				i = verifica.dimensione;
				simmetria = 0;
			}
			riscontro = 0;
			i++;
		}	
	
	}

/*controllo della simmetria per stringhe*/

	if (verifica.controllo == 2){
		
		while ( i < verifica.dimensione){
			
			j = 0;
			while ( j < verifica.dimensione){	
				
				if (strcmp (verifica.prima_stringa[i],verifica.seconda_stringa[j]) == 0 )
					if (strcmp (verifica.prima_stringa[j],verifica.seconda_stringa[i]) == 0 )
						riscontro++;
			
				j++;
			}
		
			if (riscontro == 0){
				j = verifica.dimensione;
				i = verifica.dimensione;
				simmetria = 0;
			}
			riscontro = 0;	
			i++;
		}	
	
	}

/***** Controllo se la simmetria è stata verificata *********/

	if (simmetria == 1)
		printf ("   e'simmetrica\n");
	else
		printf ("   e'asimmetrica\n");

/****** Fine controllo simmetria ******/

	return (simmetria);
}



/* FUNZIONE PER CONTROLLARE LA TRANSITIVITà */

/****** Definizione: In matematica, una relazione binaria R in un insieme X è transitiva se e solo se 
		per ogni a, b, c appartenenti ad X, se a è in relazione con b e b è in relazione con c, allora
		 a è in relazione con c.*******/


int controllo_transitivita (rel_bin verifica){
	
	int i,
		j,
		k,
		transitivita;

/*IMPOSTO LA TRANSITIVITA INIZIALMENTE COME VERA E AZZERO I CONTATORI*/
	transitivita = 1;
	i = 0;
	j = 0;
	k = 0;

/*VERIFICA TRANSITIVITà PER NUMERI*/


	if (verifica.controllo == 1){

		while (i < verifica.dimensione){
			j = 0;

			while (j < verifica.dimensione){
				k=0;

				if (verifica.secondo_termine[i] == verifica.primo_termine[j]){
					transitivita = 0;
					
					while (k < verifica.dimensione){
						if (verifica.primo_termine[i] == verifica.primo_termine[k]){
		 					if (verifica.secondo_termine[k]==verifica.secondo_termine[j]){
								 transitivita = 1;
								 k = verifica.dimensione;
							}
						}
						
						k++;
		 			}
				
					if (transitivita==0){
						j=verifica.dimensione;
						i=verifica.dimensione;
					}
				}
				
				j++;
			}

			i++;	
		}
	}

	
/***************** VERIFICA TRANSITIVITà PER STRINGHE ****************/

	if (verifica.controllo == 2){


		while (i < verifica.dimensione){
			j = 0;

			while (j < verifica.dimensione){
				k=0;

				if (strcmp (verifica.seconda_stringa[i],verifica.prima_stringa[j]) == 0){
					transitivita = 0;
					
					while (k < verifica.dimensione){
						if (strcmp (verifica.prima_stringa[i],verifica.prima_stringa[k]) == 0){
		 					if (strcmp (verifica.seconda_stringa[k],verifica.seconda_stringa[j]) == 0){
								 transitivita = 1;
								 k = verifica.dimensione;
							}
						}
						
						 k++;
		 			}
		 			
		 			if (transitivita==0){
		 				j=verifica.dimensione;
		 				i=verifica.dimensione;
					 }
				}
				
				j++;
			}

			i++;	
		}

	}

/********** Controllo se la relazione è Transitiva *********/
	
	if (transitivita == 1)
		printf ("   e'transitiva\n");
		
	else
		printf ("   non e'transitiva\n");
		
/************ Fine controllo Transitività ************/
		
	return (transitivita);

}

/********** Dicotomia *************/

int controllo_dicotomia (rel_bin verifica){

	int i,j,k;
	int numero_elementi;
	int dicotomia = 0;
	int dimensione;
	int riscontro;
	int secondo_riscontro;
	i=0;
	j=0;
	k=i-1;
	riscontro = 0;
	dimensione = verifica.dimensione;

/********* Dicotomia per numeri *********/
	
	if (verifica.controllo == 1){
		
/********** Conto il numero delle coppie esistenti (scarto le coppie uguali) *********/		
		
		while ( i < verifica.dimensione){
			k = i-1;
			j = i+1;
			secondo_riscontro = 0;
			
		if (i>0){
			while ( k >= 0 ){
				if (verifica.primo_termine[i] == verifica.primo_termine[k]){
					if (verifica.secondo_termine[i] == verifica.secondo_termine[k])
						secondo_riscontro = 1;
				}
				k--;
			}
		}
		
		if (secondo_riscontro != 1){
			while ( j < verifica.dimensione){
				if (verifica.primo_termine[i] == verifica.primo_termine[j])
					if (verifica.secondo_termine[i] == verifica.secondo_termine[j]){
						dimensione--;
				}
			j++;
			}
		}
		i++;
	}
	
	
		i=0;
		j=0;
		k=0;
		numero_elementi=0;
		riscontro = 0;
/*************** Conto il numero degli elementi distinti esistenti ***************/		
	
		while (i<verifica.dimensione){
			k=i-1;
			secondo_riscontro = 0;
			
			while (k >= 0){
				if (verifica.primo_termine[i] == verifica.primo_termine[k])
					secondo_riscontro = 1;
					k--;
			}
			if (secondo_riscontro != 1){
				if (verifica.primo_termine[i] == verifica.secondo_termine[i])
					riscontro++;
					
			}
		i++;
		}
	
	numero_elementi = riscontro;

/************ Conto quanti dovrebbero essere gli elementi per avere la dicotomia ***********/
	
	while (numero_elementi > 0){	
		numero_elementi--;
		riscontro = riscontro + numero_elementi;
		}
	}

/******************** VERIFICA DICOTOMICA PER STRINGHE *****************/

	if (verifica.controllo == 2){
	
/********** Conto il numero delle coppie esistenti (scarto le coppie uguali) *********/	
	
		while ( i < verifica.dimensione){
			k = i-1;
			j = i+1;
			secondo_riscontro = 0;
		if (i>0){
			while ( k >= 0 ){
				if ( (strcmp (verifica.prima_stringa[i],verifica.prima_stringa[k])) == 0){
					if ( (strcmp (verifica.seconda_stringa[i],verifica.seconda_stringa[k])) == 0)
						secondo_riscontro = 1;
				}
				k--;
			}
		}
		
		if (secondo_riscontro != 1){
			while ( j < verifica.dimensione){
				if ( (strcmp (verifica.prima_stringa[i],verifica.prima_stringa[j])) == 0)
					if ( (strcmp (verifica.seconda_stringa[i],verifica.seconda_stringa[j])) == 0){
						dimensione--;
				}
			j++;
			}
		}
		i++;
	}
	
	
		i=0;
		k=0;
		j=0;
		numero_elementi = 0;
/*************** Conto il numero degli elementi distinti esistenti ***************/		
	
		while (i<verifica.dimensione){
			k=i-1;
			secondo_riscontro = 0;
			
			while (k >= 0){
				if ( (strcmp (verifica.prima_stringa[i],verifica.prima_stringa[k])) == 0)
					secondo_riscontro = 1;
					k--;
			}
			if (secondo_riscontro != 1){
				if ( (strcmp (verifica.prima_stringa[i],verifica.seconda_stringa[i])) == 0)
					numero_elementi++;
					
			}
		i++;
		}		
		riscontro = numero_elementi;

/************ Conto quanti dovrebbero essere gli elementi per avere la dicotomia ***********/
	
		while (numero_elementi > 0){
	
			numero_elementi--;
			riscontro = riscontro + numero_elementi;
		
		}

	}

/************* Verifico se la dicotomia è verificata ****************/
	
	if (dimensione == riscontro)
		dicotomia = 1;
	
	if (dicotomia == 1 )
		printf ("   e'dicotomica\n\n");

	else
		printf ("   non e'dicotomica\n\n");

/***************** Fine verifica dicotomia ******************/

	return (dicotomia);
}

/*Funzione di verifica dell'ordine totale*/


void ordine_totale (rel_bin verifica){
	
	int parziale,
		dicotomia;
	
	dicotomia=2;
	parziale = ordine_parziale (verifica);
	if (parziale == 1)
	dicotomia = controllo_dicotomia (verifica);
	
	if (parziale == 0)
		printf (" \n l'ordine non e'totale in quanto non e'nemmeno parziale");

	if (dicotomia == 0)
		printf (" \n l'ordine non e'totale in quanto non viene rispettata la propieta'di dicotomia");

	if (dicotomia == 1 && parziale == 1)
		printf ("\n Quindi e'una relazione d'ordine totale");
		
	printf ("\n\n   ... Controllo Ordine Totale Terminato ...\n\n\n\n");	
}

/*Funzione che stabilisce se e'una relazione di equivalenza o meno*/

void relazione_equivalenza (rel_bin verifica){
	
	int riflessivita;
	int simmetria;
	int transitivita;
	
	riflessivita = controllo_riflessivita (verifica);
	simmetria = controllo_simmetria (verifica);
	transitivita = controllo_transitivita (verifica);
	
	if (riflessivita == 1 && simmetria == 1 && transitivita == 1)
	printf ("\n Quindi e'una relazione di equivalenza\n");
	
	if (riflessivita == 0)
	printf ("\n Quindi non e'una relazione di equivalenza perche'non riflessiva\n");
	
	if (simmetria == 0)
	printf ("\n Quindi non e'una relazione di equivalenza perche'non simmetrica\n");
	
	if (transitivita == 0)
	printf ("\n Quindi non e'una relazione di equivalenza perche'non transitiva\n");	
}

/*Funzione che stabilisce se la relazione binaria acquisita e'una funzione matematica*/

void controllo_funzione (rel_bin verifica){
	
	int i;
	int k;
	int termini_diversi;
	int termini_uguali_prima;
	int termini_uguali_dopo;
	int errore;
	
if (verifica.controllo == 1){
	
	i=0;
	errore=0;
	termini_diversi=0;
	termini_uguali_dopo=0;
	termini_uguali_prima=0;
	while (i < verifica.dimensione){
		k=verifica.dimensione-1;
		termini_uguali_dopo=termini_uguali_prima;
		while (k > i){
			if (verifica.primo_termine[i] == verifica.primo_termine[k]){
				if (verifica.secondo_termine[i] != verifica.secondo_termine[k]){
					errore=1;
					printf ("\n Nel %d elemento c'e'un errore che impedisce alla relazione binaria\n",k+1);
					printf (" di essere una funzione\n");
					k=i;
					i=verifica.dimensione;
				}
				if (verifica.secondo_termine[i] == verifica.secondo_termine[k])
					termini_uguali_dopo++;
			}
			k--;
		}
		if (errore == 0 && termini_uguali_dopo == termini_uguali_prima)
		termini_diversi++;
		
		termini_uguali_prima = termini_uguali_dopo;
		i++;
	}
	if (errore == 0 && (termini_diversi == (verifica.dimensione - termini_uguali_prima))){
	printf ("\n La relazione binaria e'una funzione\n");
	controllo_biiettivita (verifica);
}
	else
	printf ("\n La relazione binaria non e'una funzione\n");
}

/********** Controllo se c'è una funzione per stringhe (le stringhe sono considerate come costanti di diverso valore) ***********/

if (verifica.controllo == 2){
	
	i=0;
	errore=0;
	termini_diversi=0;
	termini_uguali_dopo=0;
	termini_uguali_prima=0;
	while (i < verifica.dimensione){
		k=verifica.dimensione-1;
		termini_uguali_dopo=termini_uguali_prima;
		while (k > i){
			if ( (strcmp (verifica.prima_stringa[i],verifica.prima_stringa[k])) == 0){
				if ( (strcmp (verifica.seconda_stringa[i],verifica.seconda_stringa[k])) != 0){
					errore=1;
					printf ("\n Nel %d elemento c'e'un errore che impedisce alla relazione binaria\n",k+1);
					printf (" di essere una funzione\n");
					k=i;
					i=verifica.dimensione;
				}
				else
					termini_uguali_dopo++;
			}
			k--;
		}
		if (errore == 0 && termini_uguali_dopo == termini_uguali_prima)
		termini_diversi++;
		
		termini_uguali_prima = termini_uguali_dopo;
		i++;
	}
	if (errore == 0 && (termini_diversi == (verifica.dimensione - termini_uguali_prima))){
	printf ("\n La relazione binaria e'una funzione\n");
	controllo_biiettivita (verifica);
	}
	else
	printf ("\n La relazione binaria non e'una funzione\n");
}

printf ("\n\n   ... Controllo Funzione Terminato ...\n\n\n\n");

}

/**********FUNZIONE PER IL controllo DELL'INIETTIVITA'*************/

int controllo_iniettivita (rel_bin verifica){
	
	int i;
	int k;
	int termini_diversi;
	int termini_uguali_prima;
	int termini_uguali_dopo;
	int errore;
	int iniettivita;
	
	iniettivita = 0;
	
if (verifica.controllo == 1){
	
	i=0;
	errore=0;
	termini_diversi=0;
	termini_uguali_dopo=0;
	termini_uguali_prima=0;
	
	while (i < verifica.dimensione){
		
		k=verifica.dimensione-1;
		termini_uguali_dopo=termini_uguali_prima;
		while (k > i){
			
			if (verifica.secondo_termine[i] == verifica.secondo_termine[k]){
				
				if (verifica.primo_termine[i] != verifica.primo_termine[k]){
					
					errore=1;
					printf ("\n Nel %d elemento c'e'un errore che impedisce alla funzione\n",k+1);
					printf (" di essere iniettiva\n");
					k=i;
					i=verifica.dimensione;
				}
				if (verifica.primo_termine[i] == verifica.primo_termine[k])
					termini_uguali_dopo++;
			}
			k--;
		}
		if (errore == 0 && termini_uguali_dopo == termini_uguali_prima)
		termini_diversi++;
		
		termini_uguali_prima = termini_uguali_dopo;
		i++;
	}
	if (errore == 0 && (termini_diversi == (verifica.dimensione - termini_uguali_prima))){
	printf ("\n La funzione e'iniettiva\n");
	iniettivita = 1;
}
	else
	printf ("\n La funzione non e'iniettiva\n");


}

/********** Controllo iniettivita'per stringhe ***********/

if (verifica.controllo == 2){
	
	i=0;
	errore=0;
	termini_diversi=0;
	termini_uguali_dopo=0;
	termini_uguali_prima=0;
	
	while (i < verifica.dimensione){
		k=verifica.dimensione-1;
		termini_uguali_dopo=termini_uguali_prima;
		while (k > i){
			if ( (strcmp (verifica.seconda_stringa[i],verifica.seconda_stringa[k])) == 0){
				if ( (strcmp (verifica.prima_stringa[i],verifica.prima_stringa[k])) != 0){
					errore=1;
					printf ("\n Nel %d elemento c'e'un errore che impedisce alla funzione\n",k+1);
					printf (" di essere iniettiva\n");
					k=i;
					i=verifica.dimensione;
				}
				if ( (strcmp (verifica.prima_stringa[i],verifica.prima_stringa[k])) == 0)
					termini_uguali_dopo++;
			}
			
			k--;
		}
		if (errore == 0 && termini_uguali_dopo == termini_uguali_prima)
		termini_diversi++;
		
		termini_uguali_prima = termini_uguali_dopo;
		i++;
	}
	if (errore == 0 && (termini_diversi == (verifica.dimensione - termini_uguali_prima))){
	printf ("\n La funzione e'iniettiva");
	iniettivita = 1;
	}
	else
	printf ("\n La funzione non e'iniettiva");
}

return (iniettivita);	
}

/****************FUNZIONE PER IL controllo DELLA SURIETTIVITA'************/

int controllo_suriettivita (rel_bin verifica){
	
/******* La suriettività è sempre verificata in quanto il dominio e il codominio **********/
/** sono entrambi i rispettivi x,y acquisiti, quindi non ho elementi y non associati a x **/
int suriettivita;

suriettivita = 1;
return (suriettivita);
}

/****************FUNZIONE PER IL controllo DELLA BIIETTIVITA'************/

void controllo_biiettivita (rel_bin verifica){
	
	int 	surriettivita,
			iniettivita;
		
surriettivita = controllo_suriettivita (verifica);
iniettivita = controllo_iniettivita (verifica);

	
	if ( surriettivita == 1 && iniettivita == 1)
		printf ("\n la funzione e'biiettiva");
	else
		printf ("\n la funzione non e'biiettiva");
return;
}


int controllo_antisimmetria (rel_bin verifica){
	
	int i,
		j,
		riscontro,
		antisimmetria;

	antisimmetria = 1;	


	i = 0;
	j = 0;
	riscontro = 0;

/*controllo della antisimmetria per numeri*/

	if (verifica.controllo == 1){
		
		while ( i < verifica.dimensione){
			
			j = 0;
			while ( j < verifica.dimensione){	
				
				if (verifica.primo_termine[i] == verifica.secondo_termine[j])
					if (verifica.primo_termine[j] == verifica.secondo_termine[i])
						if (verifica.primo_termine[i] == verifica.primo_termine[j]) 
						riscontro++;
				j++;
		}
		
			if (riscontro == 0){
				j = verifica.dimensione;
				i = verifica.dimensione;
				antisimmetria = 0;
			}
			riscontro = 0;
			i++;
		}	
	
	}

/*controllo della antisimmetria per stringhe*/

	if (verifica.controllo == 2){
		
		while ( i < verifica.dimensione){
			
			j = 0;
			while ( j < verifica.dimensione){	
				
				if (strcmp (verifica.prima_stringa[i],verifica.seconda_stringa[j]) == 0 )
					if (strcmp (verifica.prima_stringa[j],verifica.seconda_stringa[i]) == 0 )
						if (strcmp (verifica.prima_stringa[j],verifica.prima_stringa[i]) == 0 )
						riscontro++;
			
				j++;
			}
		
			if (riscontro == 0){
				j = verifica.dimensione;
				i = verifica.dimensione;
				antisimmetria = 0;
			}
			riscontro = 0;	
			i++;
		}	
	
	}

/***** Controllo se la simmetria è stata verificata *********/

	if (antisimmetria == 1)
		printf ("   e'antisimmetrica\n");
	else
		printf (" non  e'antisimmetrica\n");

/****** Fine controllo simmetria ******/

	return (antisimmetria);
}

