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
printf("Premi 1 se vuoi immettere solo numeri, 2 per altro\n");
scanf("%d",&relazione.controllo);

}
/**/
/*Acquisizione Numerica*/
if(relazione.controllo == 1){
while(acquisizione_finita == 0){
	relazione.dimensione++;
	acquisizione_finita = 2;
 /*Acquisisco il primo termine della coppia*/
 printf("Inserisci il primo termine della coppia \n");
 relazione.primo_termine = (int *) realloc(relazione.primo_termine, (relazione.dimensione+1) * sizeof(int));
 /*Check del primo termine della coppia*/
	while((scanf("%d",&relazione.primo_termine[relazione.dimensione - 1])) != 1){
	fflush(stdin);
	printf("\nC'e' un errore, riinserire il primo termine\n");
	}
 
 /*Acquisisco il secondo termine della coppia*/
 printf("Inserisci il secondo termine della coppia \n");
 relazione.secondo_termine = (int *) realloc(relazione.secondo_termine, (relazione.dimensione+1) * sizeof(int));
/*Check del secondo termine della coppia*/
	while((scanf("%d",&relazione.secondo_termine[relazione.dimensione - 1])) != 1){
	fflush(stdin);
	printf("\nC'e' un errore, riinserire il secondo termine\n");
	}

 /*Chiedo all'utente se ci sono altre coppie*/
 while(acquisizione_finita < 0 || acquisizione_finita > 1){
 printf("vuoi acquisire un'altra coppia? immetti 1 per uscire, 0 per continuare\n");
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
 printf("Inserisci il primo termine della coppia \n");
 relazione.prima_stringa[relazione.dimensione - 1] = (char *) malloc(50);
 scanf(" %[^\n]s",relazione.prima_stringa[relazione.dimensione - 1]);

 /*Acquisisco il secondo termine della coppia*/
 printf("Inserisci il secondo termine della coppia \n");


 relazione.seconda_stringa[relazione.dimensione - 1] = (char *) malloc(50);
 scanf(" %[^\n]s",relazione.seconda_stringa[relazione.dimensione - 1]);


 /*Chiedo all'utente se ci sono altre coppie*/
 while(acquisizione_finita < 0 || acquisizione_finita > 1){
 
 printf("vuoi acquisire un'altra coppia? immetti 1 per uscire, 0 per continuare\n");
 scanf("%d",&acquisizione_finita);
 
 			}
		}
	}
	
return relazione;
}

/******************************FUNZIONE DI STAMPA********************************/

void stampa(struct relBin stampa){
 int i = 0;
 printf("{");
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
 printf("}");
}

/******************FUNZIONE DI VERIFICA DI RELAZIONI D'ORDINE******************/

void verifica_rel_ordine_parziale (struct relBin verifica){

int i,
	j,
	k,
	riscontro,
	secondo_riscontro;
i = 0;
j = 0;
k = 0;
riscontro = 0;
secondo_riscontro = 0;
/*Verifica riflessivit�*/

/*Definizione: una relazione per la quale esiste almeno un elemento che non � in relazione con s� stesso non soddisfa la definizione di riflessivit�*/

while((i < verifica.dimensione) && (k < verifica.dimensione)){

/*Verifica riflessivit� per numeri*/

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
				
/***************** Controllo la riflessivit� per gli elementi del primo insieme ******************************/		
			
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
			
/***************** Controllo la riflessivit� per gli elementi del secondo insieme ******************************/				
			
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
				printf("\nLa riflessivita' non e' verificata perche' un elemento della coppia %d\nnon e' in relazione con se stesso.\n",i+1);
				i=verifica.dimensione;
			}
			
			if(secondo_riscontro != 0)
				k++;
			
			else{
				printf("\nLa riflessivita' non e' verificata perche' un elemento della coppia %d\nnon e' in relazione con se stesso.\n",k+1);
				k=verifica.dimensione;
			}	
		}
	
	}
	
	/* VERIFICA RIFLESSIVIT� PER STRINGHE */
	
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
				
/***************** Controllo la riflessivit� per gli elementi del primo insieme ******************************/		
			
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
			
/***************** Controllo la riflessivit� per gli elementi del secondo insieme ******************************/				
			
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
				printf("\nLa riflessivita' non e' verificata perche' un elemento della coppia %d\nnon e' in relazione con se stesso.\n",i+1);
				i=verifica.dimensione;
			}
			
			if(secondo_riscontro != 0)
				k++;
			
			else{
				printf("\nLa riflessivita' non e' verificata perche' un elemento della coppia %d\nnon e' in relazione con se stesso.\n",k+1);
				k=verifica.dimensione;
			}	
		}
		
	}
	
}

/* VERIFICA SIMMETRIA */

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
			printf("la simmetria non � stata trovata");
			j = verifica.dimensione;
			i = verifica.dimensione;
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
			printf("la simmetria non � stata trovata");
			j = verifica.dimensione;
			i = verifica.dimensione;
			}
		riscontro = 0;	
		i++;
	}	
	
}

/*VERIFICA DELLA TRANSITIVIT�*/


i = 0;
j = 0;
k = 0;
riscontro = 0;
secondo_riscontro = 0;

/*VERIFICA TRANSITIVIT� PER NUMERI*/

if(verifica.controllo == 1){

	while( i < verifica.dimensione){
		
		j = 0;
		
		while( j < verifica.dimensione){
		
		k = 0;
		
		/*CONTROLLO SE ESISTE UN (A , B) (B , C) (A , C)*/
			/*CONTROLLO SE C'� UNA B NEL PRIMO TERMINE*/
			
			if(verifica.primo_termine[j] == verifica.secondo_termine[i]){
		
		
				while( k < verifica.dimensione){
				
				/*CONTROLLO SE ESISTE (A , C) PER VERIFICARE LA TRANSITIVIT�*/
				
					if(verifica.primo_termine[i] == verifica.primo_termine[k])
						if(verifica.secondo_termine[k] == verifica.secondo_termine[j])
						riscontro++;
		
					k++;
				}
						
				if(riscontro == 0){
					printf("la transitivit� non � stata trovata");
					k = verifica.dimensione;
					j = verifica.dimensione;
					i = verifica.dimensione;
					}
				riscontro = 0;
			}
		j++;
		}	
	
	}

i++;
}

/* VERIFICA TRANSITIVIT� PER STRINGHE */

if(verifica.controllo == 2){

	while( i < verifica.dimensione){
		
		j = 0;
		
		while( j < verifica.dimensione){
		
		k = 0;
		
		/*CONTROLLO SE ESISTE UN (A , B) (B , C) (A , C)*/
			/*CONTROLLO SE C'� UNA B NEL PRIMO TERMINE*/
		
			if(verifica.prima_stringa[j] == verifica.seconda_stringa[i]){

		/*CONTROLLO SE ESISTE (A , C) PER VERIFICARE LA TRANSITIVIT�*/		
		
				while( k < verifica.dimensione){
				
					if(verifica.prima_stringa[i] == verifica.seconda_stringa[k])
						if(verifica.seconda_stringa[k] == verifica.seconda_stringa[j])
						riscontro++;
		
					k++;
				}		
				if(riscontro == 0){
					printf("la transitivit� non � stata trovata");
					k = verifica.dimensione;
					j = verifica.dimensione;
					i = verifica.dimensione;
					}
				riscontro = 0;
			}
		j++;
		}	
	
	}

i++;
}


}


void verifica_rel_ordine_totale (struct relBin verifica){
	
	verifica_rel_ordine_parziale (verifica);
	/*DICOTOMIA*/
	
}
