#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*int main (void){
acquisizione();
}
*/

struct relBin{
	int *primo_termine,
		*secondo_termine;
		
	char **prima_stringa,
		 **seconda_stringa;
	
	int controllo,
		dimensione;
};

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
