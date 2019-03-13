#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#define max 500

void genera_mazzo(int [][max]);//INSERISCI NELL'ARRAY NELLE RISPETTIVE POSIZIONE IL NUMERO DI CARTE PRESENTI IN UN MAZZO ALL'INIZIO DELLA PARTITA
void stampa_mazzo(int [][max]);//MOSTRA QUELLO CHE HA COSTRUITO 'genera_mazzo'
void leggi_dati(int [][max]);//APRE IL FILE DI TESTO DOVE SONO CONSERVATI I DATI E LI TRASCRIVE IN UNA MATRICE
void crea_file(int [][max]);//SCRIVE IL FILE DI TESTO DOVE SARANNO CONSERVATI I DATI PRESI DALLA MATRICE
int val_carta(int [][max], int , int );//RESTITUISCE IL VALORE DELLA CARTA SE E' UN ASSO IL VALORE SARA' 11
void crea_tabella(int[][max]);//COSTRUISCE LA MATRICE CON TUTTE LE POSSIBILI COMBINAZIONI DI MANI
void aggiorna_tabella(int [][max],int , int , int , int , int , int );//AGGIORNA I VALORI NELLA TABELLA CON UNA CERTA MANO E CONTRO UNA CERTA MANO
void stampa_tabella(int[][max]);
int genera_riga(void);
int genera_colonna(void);
int stabilisci_vincitore(int , int);//ritorna 1 se vince il primo intero 0 se vince il secondo intero
void aggiorna_mazzo(int[][max],int,int);
int genera_carta(int[][max]);
void raccogli_dati(int ,int ,int , int , int [][max], int [][max]);
void simula_partite(int , int , int [][max], int ,int , int [][max]);
int calcola_percentuale(int  , int  );
void start(int[][max], int[][max]);


int main(){

int mazzo[max][max];
int tabella[max][max];

genera_mazzo(mazzo);
//stampa_mazzo(mazzo);
crea_tabella(tabella);
//stampa_tabella(tabella);
start(mazzo,tabella);

Beep(750,700);
return 0 ;
}

void genera_mazzo(int mazzo[][max]){
int i=0,j=0;
    for(i=0 ; i<13 ; i++){
        for(j=0 ; j < 8 ; j++){
            mazzo[i][j]=1;//IN OGNI CELLA C'E' IL NUMERO DI CARTE RIMANENTI NEL MAZZO 10=J 11=Q 12=K 0=A
        }
    }
return ;
}

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
return ;
}

void crea_file(int tabella[][max]){
    FILE* fp;

    fp=fopen("Dati_BJ.txt","w");
    if(fp==NULL){
        printf("ERRORE ! \n");
    }
    for(int i=0;i<180;i++){
            fprintf(fp,"\n");
        for(int j=0;j<13;j++){
            fprintf(fp,"%d ",tabella[i][j]);
        }
    }
    fclose(fp);

return;
}


 int val_carta(int mazzo[][max],int ind_rig , int ind_col){
 int val = 0 ;
     if (mazzo[ind_rig][ind_col]!=0){
        switch(ind_rig){
            case 0:
                val=11;
                break;
            case 10:
                val=10;
                break;
            case 11:
                val=10;
                break;
            case 12:
                val=10;
                break;
            default :
                val=ind_rig+1;
                break;
        }
     }
     else{
        printf("\nCarta gia usata !!\n");
     }
return val;
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
        for(j=2;j<13;j++)tabella_dati[i][j]=0;
        i++;
        count_carta_D++;
        }
    count_tot++;
    }

return;
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
return ;
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

void raccogli_dati(int riga_1,int col_1,int riga_2 , int col_2 , int mazzo[][max],int tabella[][max]){
int carta_coperta_dealer = 0 , carta_scoperta_dealer = 0 ;
int prendi_carta = 0 , totale_dealer = 0, totale_persona = 0 ,n_partite = 0 , vittorie = 0 ;
int carta_1 = 0 , carta_2 = 0 ;

carta_1=val_carta(mazzo,riga_1,col_1);
carta_2=val_carta(mazzo,riga_2,col_2);
aggiorna_mazzo(mazzo,riga_1,col_1);
aggiorna_mazzo(mazzo,riga_2,col_2);

carta_scoperta_dealer=genera_carta(mazzo);//GENERO E AGGIORNO IL MAZZO


totale_persona=carta_1+carta_2;
if(totale_persona>21)//DISCRIMINO IL CASO IN CUI HO PESCATO DUE ASSI
{
totale_persona=totale_persona-10;
}

/*printf("\nHai %d  Il dealer ha %d\nQuante simulazioni vuoi fare ?  ",totale_persona,carta_scoperta_dealer);//INDICARE IL NUMERO DI PARTITE DA FARE
scanf("%d",&n_partite);
printf("\n1 = Chiamando 1 carta\n0 = Non chiamando carta\n");//INDICARE SE GIOCARE CHIAMANDO O MENO
scanf("%d",&prendi_carta);
*/
n_partite=10;
prendi_carta=0;

simula_partite(totale_persona,carta_scoperta_dealer,mazzo,prendi_carta,n_partite,tabella);//SIMULO UN CERTO NUM DI PARTITE CHIAMANDO O MENO E AGGIORNO I DATI NELLA MATRICE.

return;
}


int stabilisci_vincitore(int TOT_1, int TOT_2){
int esito = 0 ;

if(TOT_1<=21 && TOT_1>TOT_2)esito=1;

return esito;
}

void aggiorna_mazzo(int mazzo[][max],int riga , int colonna ){//METTE A 0 IL VALORE DI UNA CARTA IN MODO DA NON POTERLA RIUTILIZZARE
mazzo[riga][colonna]=0;

return ;
}

int genera_carta(int mazzo[][max]){//FORNISCE IL VALORE DI UNA CARTA CGENERATA CASUALEMNTE NEL MAZZO
int ind_riga = 0 , ind_colonna = 0 , valore = 0 ;

    do{
    ind_riga=genera_riga();
    ind_colonna=genera_colonna();
    }while(mazzo[ind_riga][ind_colonna]==0);
valore = val_carta(mazzo,ind_riga,ind_colonna);
aggiorna_mazzo(mazzo,ind_riga,ind_colonna);

return  valore;
}

void simula_partite(int tot_p, int carta_sd, int mazzo[][max], int prendi_c , int num_partite , int tabella_dati[][max]){//GIOCHIAMO UN NUMERO N DI PARTITE E PRENDIAMO CARTA O MENO FACENDO SCEGLIERE ALL'UTENTE
int vittorie = 0 , sconfitte = 0 , partite = 0;
int carta_generata = 0 , esito = 0 ;
int totale_persona = tot_p, totale_dealer = 0 ;
int carta_cd = 0, tot_d = 0 ;

    if(prendi_c==1){
        while(num_partite>0){
        carta_cd=genera_carta(mazzo);//AD OGNI CICLO IL DEALER AVRA UNA CARTA COPERTA SEMPRE DIVERSA
        totale_dealer=carta_cd+carta_sd;
            if(totale_dealer>21){//DISCRIMO I CASI IN CUI IL DEALER HA PESCATO 2 ASSI
            totale_dealer=totale_dealer-10;
            }
        tot_p=totale_persona;
        carta_generata=genera_carta(mazzo);
        tot_p=tot_p+carta_generata;
        printf("Hai %d , con la carta presa %d arrivi a %d \n",totale_persona,carta_generata,tot_p);
            if(tot_p>21 && carta_generata==11){//DISCRIMINO IL CASO IN CUI IL GIOCATORE SBALLA PRENDENDO UN ASSO CON VALORE 11
            tot_p=tot_p-10;
            }
            if(tot_p>21){
            printf("Sballato ! \n");
            esito=0;
            }
        tot_d=totale_dealer;
        printf("Il dealer ha %d \n",tot_d);
            while(tot_d<17){
            carta_generata=genera_carta(mazzo);
            tot_d=tot_d+carta_generata;
            printf("Carta presa %d arriva a %d\n",carta_generata,tot_d);
                if(tot_d>21 && carta_generata==11){//DISCRIMINO IL CASO IN CUI IL DEALER SBALLA PRENDENDO UN ASSO CON VALORE 11
                tot_d=tot_d-10;
                }
                if(tot_d>21 && tot_p<=21){//DEALER CHE SBALLA
                printf("Il dealer ha sballato !!\n");
                esito=1;
                }
            }
            if(tot_d <=21 && tot_p <=21){//SE NESSUNO DEI DUE SBALLA
            esito=stabilisci_vincitore(tot_p,tot_d);
            }

            if(esito==1){
                printf("hai vinto !!!\n");
                vittorie++;
            }
            else{
                printf("hai perso !!!\n");
                sconfitte++;
            }
        num_partite--;
        partite++;//CONTO IL NUMERO DI PARTITE FATTE
        }
    }
    else{
        while(num_partite>0){
        carta_cd=genera_carta(mazzo);//GENERO CARTA COPERTA DEL DEALER OGNI CICLO
        totale_dealer=carta_cd+carta_sd;
            if(totale_dealer>21){//DISCRIMO I CASI IN CUI IL DEALER HA PESCATO 2 ASSI
            totale_dealer=totale_dealer-10;
            }
        tot_d=totale_dealer;
        printf("Hai totalizzato %d \n",totale_persona);
        printf("Il dealer ha %d \n",tot_d);
            while(tot_d<17){
            carta_generata=genera_carta(mazzo);
            tot_d=tot_d+carta_generata;
            printf("Carta presa %d arriva a %d\n",carta_generata,tot_d);
                if(tot_d>21 && carta_generata==11){tot_d=totale_dealer;//DISCRIMINO IL CASO IN CUI IL DEALER SBALLA PRENDENDO UN ASSO CON VALORE 11
                tot_d=tot_d-10;
                }
                if(tot_d>21){//DEALER CHE SBALLA
                printf("Il dealer ha sballato !!\n");
                esito=1;;
                }
            }
            if(tot_d <=21 && tot_p <=21){//NESSUNO DEI DUE SBALLA
                esito=stabilisci_vincitore(tot_p,tot_d);
            }
            if(esito==1){
                printf("hai vinto !!!\n");
                vittorie++;
            }
            else{
                printf("hai perso !!!\n");
                sconfitte++;
            }
        num_partite--;
        partite++;//CONTO IL NUMERO DI PARTITE FATTE
        }
    }

aggiorna_tabella(tabella_dati,totale_persona,carta_sd,prendi_c,vittorie,sconfitte,partite);//CON I DATI OTTENUTI LI SALVO NELLA MATRICE TABELLA_DATI

return ;
}

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

return ;
}

int calcola_percentuale(int quantita , int totale ){
int percentuale = 0 ;

percentuale = (quantita * 100 )/totale;

return percentuale ;
}

void start(int mazzo[][max], int tabella[][max]){
int indice = 20;
leggi_dati(tabella);

//while(indice > 0){
    for(int i = 0 ; i <13 ; i++){
        for(int j = 0 ; j <13 ; j++)
        {
        genera_mazzo(mazzo);
        raccogli_dati(i,0,j,0,mazzo,tabella);
        crea_file(tabella);
        indice--;
        }
    }
//}
printf("FINE !");
return ;
}

void leggi_dati(int tabella_dati[][max]){
FILE* source;
int i=0, j=0;
int tmp=0;

    source=fopen("Dati_BJ.txt","r");

    if(source==NULL){
        printf("ERRORE ! \n");
    }
    else{
             for(i=0;i<180;i++){
                for(j=0;j<13;j++){
                    fscanf(source,"%d", &tmp);
                    tabella_dati[i][j]=tmp;
                }
             }

            fclose(source);

    }

return ;
}
