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
	
	int controllo;
};

struct relBin acquisizione(struct relBin acquisizione){

struct relBin relazione;

int acquisizione_finita = 0;
int dimensione = 0;

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
	dimensione++;
	acquisizione_finita = 2;
 /*Acquisisco il primo termine della coppia*/
 printf("Inserisci il primo termine della coppia \n");
 relazione.primo_termine = (int *) realloc(relazione.primo_termine, (dimensione+1) * sizeof(int));
 scanf("%d",&relazione.primo_termine[dimensione - 1]);

 /*Acquisisco il secondo termine della coppia*/
 printf("Inserisci il secondo termine della coppia \n");
 relazione.secondo_termine = (int *) realloc(relazione.secondo_termine, (dimensione+1) * sizeof(int));
 scanf("%d",&relazione.secondo_termine[dimensione - 1]);


 /*Chiedo all'utente se ci sono altre coppie*/
 while(acquisizione_finita < 0 || acquisizione_finita > 1){
 printf("vuoi acquisire un'altra coppia? immetti 1 per uscire, 0 per continuare\n");
 scanf("%d",&acquisizione_finita);
 }
}
while(dimensione != 0){

     printf("\n%d %d\n",relazione.primo_termine[dimensione - 1],relazione.secondo_termine[dimensione - 1]);
     dimensione--;

   }
}

/*Acquisizione con stringhe*/
if(relazione.controllo == 2){
while(acquisizione_finita == 0){
	dimensione++;
	acquisizione_finita = 2;
 /*Acquisisco il primo termine della coppia*/
 printf("Inserisci il primo termine della coppia \n");
 relazione.prima_stringa[dimensione - 1] = (char *) malloc(50);
 scanf(" %[^\n]s",relazione.prima_stringa[dimensione - 1]);

 /*Acquisisco il secondo termine della coppia*/
 printf("Inserisci il secondo termine della coppia \n");


 relazione.seconda_stringa[dimensione - 1] = (char *) malloc(50);
 scanf(" %[^\n]s",relazione.seconda_stringa[dimensione - 1]);


 /*Chiedo all'utente se ci sono altre coppie*/
 while(acquisizione_finita < 0 || acquisizione_finita > 1){
 
 printf("vuoi acquisire un'altra coppia? immetti 1 per uscire, 0 per continuare\n");
 scanf("%d",&acquisizione_finita);
 
 }
 /*prima_stringa = realloc (prima_stringa , (dimensione+1)*sizeof(*prima_stringa));*/
/* seconda_stringa = realloc (seconda_stringa, (dimensione+1)*sizeof(*seconda_stringa));*/


    }
    
    while(dimensione != 0){

     printf("\n%s           %s\n",relazione.prima_stringa[dimensione - 1],relazione.seconda_stringa[dimensione - 1]);
     dimensione--;

            }
    return(acquisizione);
}
}

int ciao(int ciao){
	printf("scrivi il numero");
	scanf("%d",&ciao);
	return 0;
}
