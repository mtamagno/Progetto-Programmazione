#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*int main (void){
acquisizione();
}
*/
int acquisizione(void){

int  *primo_termine,
    *secondo_termine;

char  **prima_stringa,
 	  **seconda_stringa;
int acquisizione_finita = 0;
int dimensione = 0;
int controllo;

primo_termine = (int *) malloc(2);
secondo_termine = (int *) malloc(2);
prima_stringa = (char **) malloc(100);
seconda_stringa = (char **) malloc(100);


printf("Premi 1 se vuoi immettere solo numeri, 2 per altro\n");
scanf("%d",&controllo);


/*Acquisizione Numerica*/
if(controllo == 1){
while(acquisizione_finita == 0){
	dimensione++;
 /*Acquisisco il primo termine della coppia*/
 printf("Inserisci il primo termine della coppia \n");
 primo_termine = (int *) realloc(primo_termine, (dimensione+1) * sizeof(int));
 scanf("%d",&primo_termine[dimensione - 1]);

 /*Acquisisco il secondo termine della coppia*/
 printf("Inserisci il secondo termine della coppia \n");
 secondo_termine = (int *) realloc(secondo_termine, (dimensione+1) * sizeof(int));
 scanf("%d",&secondo_termine[dimensione - 1]);


 /*Chiedo all'utente se ci sono altre coppie*/
 printf("vuoi acquisire un'altra coppia? immetti 1 per uscire, 0 per continuare\n");
 scanf("%d",&acquisizione_finita);
 }
while(dimensione != 0){

     printf("\n%d %d\n",primo_termine[dimensione - 1],secondo_termine[dimensione - 1]);
     dimensione--;

   }
}
/*Acquisizione con stringhe*/
if(controllo == 2){
while(acquisizione_finita == 0){
	dimensione++;
 /*Acquisisco il primo termine della coppia*/
 printf("Inserisci il primo termine della coppia \n");
 prima_stringa[dimensione - 1] = (char *) malloc(50);
 scanf("%s",prima_stringa[dimensione - 1]);

 /*Acquisisco il secondo termine della coppia*/
 printf("Inserisci il secondo termine della coppia \n");


 seconda_stringa[dimensione - 1] = (char *) malloc(50);
 scanf("%s",seconda_stringa[dimensione - 1]);


 /*Chiedo all'utente se ci sono altre coppie*/
 printf("vuoi acquisire un'altra coppia? immetti 1 per uscire, 0 per continuare\n");
 scanf("%d",&acquisizione_finita);
 }
 prima_stringa = realloc (prima_stringa , (dimensione+1)*sizeof(*prima_stringa));
 seconda_stringa = realloc (seconda_stringa, (dimensione+1)*sizeof(*seconda_stringa));

while(dimensione != 0){

     printf("\n%s           %s\n",prima_stringa[dimensione - 1],seconda_stringa[dimensione - 1]);
     dimensione--;

            }
    }
}
