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

void ordine_parziale(struct relBin verifica){

	int riflessivita,
		transitivita,
		simmetria;
		
		/*STAMPO LE PROPIETA' DELLA RELAZIONE*/
	printf("\n\n La relazione:\n\n");

	riflessivita = check_riflessivita(verifica);
	simmetria = check_simmetria(verifica);
	transitivita = check_transitivita(verifica);
	
	if(transitivita == 1 && simmetria == 0 && riflessivita == 1)
		printf("\n Quindi e' una relazione d'ordine parziale\n\n");

	else
		printf("\n Non e' una relazione d'ordine parziale in quanto non rispetta tutte le propietà\n");

	printf("\n\n   ... Controllo Ordine Parziale Terminato ...\n\n");	
}


/***********FUNZIONE PER CONTROLLARE LA RIFLESSIVITà**********/

int check_riflessivita (struct relBin verifica){

int i,
	j,
	k,
	riscontro,
	secondo_riscontro,
	riflessivita,
	transitivita,
	simmetria;

riflessivita = 1;
transitivita = 1;
simmetria = 1;	

i = 0;
j = 0;
k = 0;
riscontro = 0;
secondo_riscontro = 0;
/*Verifica riflessività*/

/*Definizione: una relazione per la quale esiste almeno un elemento che non è in relazione con sé stesso non soddisfa la definizione di riflessività*/

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
				/*printf("\nLa riflessivita' non e' verificata perche' un elemento della coppia %d\nnon e' in relazione con se stesso.\n",i+1);
				*/
				i=verifica.dimensione;
				riflessivita = 0;
			}
			
			if(secondo_riscontro != 0)
				k++;
			
			else{
				/*printf("\nLa riflessivita' non e' verificata perche' un elemento della coppia %d\nnon e' in relazione con se stesso.\n",k+1);
				*/
				k=verifica.dimensione;
				riflessivita = 0;
			}	
		}
	
	}
	
	/* VERIFICA RIFLESSIVITà PER STRINGHE */
	
	if(verifica.controllo == 2){
			riscontro = 0;
		secondo_riscontro = 0;
		if(verifica.prima_stringa[i] == verifica.seconda_stringa[i])
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
					if(verifica.prima_stringa[i] == verifica.prima_stringa[j])
						if(verifica.prima_stringa[j] == verifica.seconda_stringa[j])
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
					if(verifica.seconda_stringa[k] == verifica.seconda_stringa[j])
						if(verifica.prima_stringa[j] == verifica.seconda_stringa[j])
							secondo_riscontro++;
						
					j++;
				}
			}
			if(riscontro != 0)
				i++;
			
			else{
				/*printf("\nLa riflessivita' non e' verificata perche' un elemento della coppia %d\nnon e' in relazione con se stesso.\n",i+1);
				*/
				i=verifica.dimensione;
				riflessivita = 0;
			}
			
			if(secondo_riscontro != 0)
				k++;
			
			else{
				/*printf("\nLa riflessivita' non e' verificata perche' un elemento della coppia %d\nnon e' in relazione con se stesso.\n",k+1);
				*/
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
	secondo_riscontro,
	simmetria;

simmetria = 1;	


i = 0;
j = 0;
k = 0;
riscontro = 0;
secondo_riscontro = 0;


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
		/*	printf("la simmetria non è stata trovata");*/
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
		
			if(verifica.prima_stringa[i] == verifica.seconda_stringa[j])
				if(verifica.prima_stringa[j] == verifica.seconda_stringa[i])
					riscontro++;
			
			j++;
		}
		
		if(riscontro == 0){
		/*	printf("la simmetria non è stata trovata");*/
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
	printf("   non e' simmetrica\n");

return(simmetria);
}

/*FUNZIONE PER CONTROLLARE LA TRANSITIVITà*/


int check_transitivita(struct relBin verifica){
int i,
	j,
	k,
	secondo_riscontro,
	transitivita;

float riscontro,
		check;
transitivita = 0;

i = 0;
j = 0;
k = 0;
check = verifica.dimensione;
riscontro = 0;
check=verifica.dimensione;
secondo_riscontro = 0;

/*VERIFICA TRANSITIVITà PER NUMERI*/


if(verifica.controllo == 1){

while(i < verifica.dimensione){
	j=0;
	while( j < verifica.dimensione){
		if(j==i)
		j++;
		if(verifica.primo_termine[i] ==  verifica.primo_termine[j])
			if(verifica.secondo_termine[i] == verifica.secondo_termine[j])
			check--;
	j++;
	}
	i++;
}

i=0;

while(i < verifica.dimensione){
	j = 0;
	while(j < verifica.dimensione){
		k=0;
			if(verifica.secondo_termine[i] == verifica.primo_termine[j])
				while(k < verifica.dimensione){
						
						if(verifica.primo_termine[i] == verifica.primo_termine[k])
		 					if(verifica.secondo_termine[k]==verifica.secondo_termine[j])
		 						riscontro++;
						 k++;
		 			
		 		}
		 		
		 	j++;
		}
i++;	
}

}

if(riscontro == (check/3)){
	transitivita = 1;
	}
/* VERIFICA TRANSITIVITà PER STRINGHE */

if(verifica.controllo == 2){

	while( i < verifica.dimensione){
		
		j = 0;
		
		while( j < verifica.dimensione){
		
		k = 0;
		
		/*CONTROLLO SE ESISTE UN (A , B) (B , C) (A , C)*/
			/*CONTROLLO SE C'è UNA B NEL PRIMO TERMINE*/
		
			if(verifica.prima_stringa[j] == verifica.seconda_stringa[i]){

		/*CONTROLLO SE ESISTE (A , C) PER VERIFICARE LA TRANSITIVITà*/		
		
				while( k < verifica.dimensione){
				
					if(verifica.prima_stringa[i] == verifica.seconda_stringa[k])
						if(verifica.seconda_stringa[k] == verifica.seconda_stringa[j])
						riscontro++;
		
					k++;
				}		
				if(riscontro == 0){
					/*printf("la transitività non è stata trovata");*/
					k = verifica.dimensione;
					j = verifica.dimensione;
					i = verifica.dimensione;
					transitivita = 0;
					}
				riscontro = 0;
			}
		j++;
		}	
	
	}

i++;
}
if(transitivita == 1)
	printf("   e' transitiva\n");
else
	printf("   non è transitiva\n");
return(transitivita);

}

/*RELAZIONE D'ORDINE TOTALE*/

void ordine_totale (struct relBin verifica){
	
	ordine_parziale (verifica);
	/*DICOTOMIA*/
	
}
