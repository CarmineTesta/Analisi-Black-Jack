#include "head.h"

void genera_mazzo(int mazzo[][max]){
int i=0,j=0;

    for(i=0 ; i<13 ; i++){
        for(j=0 ; j < 8 ; j++){
            mazzo[i][j]=1;//IN OGNI CELLA C'E' IL NUMERO DI CARTE RIMANENTI NEL MAZZO 10=J 11=Q 12=K 0=A
        }
    }
}

void crea_tabella(int tabella_dati[][max]){
int i = 0 , j = 0;
int count_tot = 4 ;
int count_carta_D = 2 ;

    while (count_tot<22){
    count_carta_D=2;

        while(count_carta_D<12){
        tabella_dati[i][0]=count_tot;
        tabella_dati[i][1]=count_carta_D;

        for(j=2;j<13;j++)tabella_dati[i][j]=0;//WTH? Ciclo per tabella_dati?
        i++;
        count_carta_D++;
        }

    count_tot++;
    }
}

int genera_riga(void){
int riga = 0 ;

srand(time(NULL));
riga=rand()%12;

return riga;
}

int genera_colonna(void){
int colonna = 0 ;

srand(time(NULL));
colonna=rand()%7;

return colonna;
}

