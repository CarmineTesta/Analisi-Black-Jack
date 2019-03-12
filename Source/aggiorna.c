#include "head.h"

void aggiorna_tabella(int tabella[][max],int totale_p, int carta_scoperta_d, int prendi_c, int n_vittorie, int n_sconfitte , int partite_giocate){
int percentuale_vittorie_chiamando = 0 , percentuale_sconfitte_chiamando = 0, percentuale_vittorie_non_chiamando = 0, percentuale_sconfitte_non_chiamando = 0 ;
int i = 0 , j = 0 ;

    while(tabella[i][0]!=totale_p || tabella[i][1]!=carta_scoperta_d){//CERCO LA RIGA DA AGGIORNARE E SCORRO FINCHE NON LA TROVO
    i++;
    }

    tabella[i][2]=tabella[i][2]+partite_giocate;//TOTALE CARTA_DEALER MANI_GIOCATE MANI_GIOCATE_CHIAMANDO MANI_GIOCATE_NON_CHIAMANDO VINTE_C PERSE_C VINTE_NC PERSE_NC %%VINTE_C %%PERSE_C %%VINTE_NC %%PERSE_NC

    if(prendi_c==1){
    tabella[i][3]=tabella[i][3]+partite_giocate;
    tabella[i][5]=tabella[i][5]+n_vittorie;//NUMERO DI VITTORIE CHIAMANDO AGGIORNATO
    tabella[i][6]=tabella[i][6]+partite_giocate-n_vittorie;//NUMERO DI SCONFITTE CHIAMANDO AGGIORNATO
    tabella[i][9]=calcola_percentuale(tabella[i][5],tabella[i][3]);//PERCENTUALE VITTORIA RISPETTO AL TOTALE MANI IN CUI HO CHIAMATO
    tabella[i][10]=100-tabella[i][9];
    }

    else{
    tabella[i][4]=tabella[i][4]+partite_giocate;
    tabella[i][7]=tabella[i][7]+n_vittorie;//NUMERO DI VITTORIE NON CHIAMANDO AGGIORNATO
    tabella[i][8]=tabella[i][8]+partite_giocate-n_vittorie;//NUMERO DI SCONFITTE NON CHIAMANDO AGGIORNATO
    tabella[i][11]=calcola_percentuale(tabella[i][7],tabella[i][4]);//PERCENTUALE VITTORIA RISPETTO AL TOTALE MANI IN CUI HO CHIAMATO
    tabella[i][12]=100-tabella[i][11];
    }
}

void aggiorna_mazzo(int mazzo[][max],int riga , int colonna ){
mazzo[riga][colonna]=0;

}
