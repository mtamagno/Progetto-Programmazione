
/* STRUTTURA relBin */
/* Creo una struttura dove salvare le coppie*/
/* appartenenti alla Relazione */

typedef struct relBin
{
    /****** Coppia Numerica ******/
    double 	*primo_termine,
            *secondo_termine;

    /***** Coppia Qualsiasi******/
    char **prima_stringa,
         **seconda_stringa;

    /**** Variabili per salvare se ho acquisito una*/
    /* coppia numerica o no e il numero delle coppie */
    int controllo,
        dimensione,
        insieme_a,
        insieme_b;
} rel_bin;

extern rel_bin acquisizione (rel_bin);
extern int controllo_simmetria (rel_bin);
extern int controllo_riflessivita (rel_bin);
extern int controllo_transitivita (rel_bin);
extern int controllo_suriettivita (rel_bin);
extern void controllo_biiettivita (rel_bin);
extern int controllo_antisimmetria (rel_bin);
extern void controllo_funzione (rel_bin);
extern void relazione_equivalenza (rel_bin);
extern void ordine_totale (rel_bin);
extern int ordine_parziale (rel_bin);
extern void stampa (rel_bin);
