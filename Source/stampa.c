#include "head.h"

void stampa_mazzo(int mazzo[][max]){
int i=0,j=0;

    for(j=0 ; j<8 ; j++){
            printf(" A =%2d  ",mazzo[0][j]);
    }

    for(i=1 ; i<10 ; i++){
    printf("\n");

        for(j=0 ; j<8 ; j++){
            printf("%2d = %d  ",i+1,mazzo[i][j]);
        }

    }

    for(i=10 ; i<13 ; i++){
    printf("\n");

        for(j=0 ; j<8 ; j++){
            if(i==10)printf(" J = %d  ",mazzo[i][j]);

            else if(i==11)printf(" Q = %d  ",mazzo[i][j]);

            else printf(" K = %d  ",mazzo[i][j]);
        }
    }
}

void stampa_tabella(int tabella_dati[][max]){
int i = 0 , j = 0 ;

    printf("\n      TOT    Dealer   NGiocate NChiamate Nnon    VINTE_C  PERSE_C VINTE_NC PERSE_NC %%VINTE_C %%PERSE_C %%VINTE_NC %%PERSE_NC");

    for(i=0;i<180;i++){
    printf("\n");

        for(j=0;j<13;j++){
            printf("%8d ",tabella_dati[i][j]);
        }

    }
}
