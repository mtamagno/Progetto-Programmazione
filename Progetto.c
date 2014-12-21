#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void acquisizione(void){

  int primo_termine*,secondo_termine*;
  string prima_stringa*,seconda_stringa;
  int acquisizione_finita = 0;
  int dimensione = 1;
  int controllo;

  primo_termine = (int *) calloc(primo_termine, 1);

  printf("Premi 1 se vuoi immettere solo numeri, 2 per altro\n");
  scanf("%d",&controllo);


/*Acquisizione Numerica*/

  if(controllo == 1){

   while(acquisizione_finita == 0){

     /*Acquisisco il primo termine della coppia*/
     printf("Inserisci il primo termine della coppia \n");
     primo_termine = (int *) realloc(primo_termine, dimensione);
     scanf("%d",&primo_termine[dimensione - 1]);

     /*Acquisisco il secondo termine della coppia*/
     printf("Inserisci il secondo termine della coppia \n");
     secondo_termine = (int *) realloc(secondo_termine, dimensione);
     scanf("%d",&primo_termine[dimensione - 1]);
     dimensione++;

     /*Chiedo all'utente se ci sono altre coppie*/
     printf("vuoi acquisire un'altra coppia? immetti 1 per uscire, 0 per continuare\n");
     scanf("%d",&acquisizione_finita);

   }
 }
/*Acquisizione con stringhe*/

  if(controllo == 2){
    while(acquisizione_finita == 0){
      printf("vuoi acquisire un'altra coppia? immetti 1 per uscire, 0 per continuare\n");
      scanf("%d",&acquisizione_finita);
    }

  }


}
