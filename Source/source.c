#include "head.h"



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

printf("\nHai %d  Il dealer ha %d\nQuante simulazioni vuoi fare ?  ",totale_persona,carta_scoperta_dealer);//INDICARE IL NUMERO DI PARTITE DA FARE
scanf("%d",&n_partite);

printf("\n1 = Chiamando 1 carta\n0 = Non chiamando carta\n");//INDICARE SE GIOCARE CHIAMANDO O MENO
scanf("%d",&prendi_carta);

simula_partite(totale_persona,carta_scoperta_dealer,mazzo,prendi_carta,n_partite,tabella);//SIMULO UN CERTO NUM DI PARTITE CHIAMANDO O MENO E AGGIORNO I DATI NELLA MATRICE.
}


int stabilisci_vincitore(int TOT_1, int TOT_2){
int esito = 0 ;

    if(TOT_1<=21 && TOT_1>TOT_2)esito=1;

return esito;
}



int genera_carta(int mazzo[][max]){
int ind_riga = 0 , ind_colonna = 0 , valore = 0 ;

    do{
    ind_riga=genera_riga();
    ind_colonna=genera_colonna();
    }while(mazzo[ind_riga][ind_colonna]==0);
valore = val_carta(mazzo,ind_riga,ind_colonna);
aggiorna_mazzo(mazzo,ind_riga,ind_colonna);

return  valore;
}

void simula_partite(int tot_p, int carta_sd, int mazzo[][max], int prendi_c , int num_partite , int tabella_dati[][max]){
int vittorie = 0 , sconfitte = 0 , partite = 0;
int carta_generata = 0 , esito = 0 ;
int totale_persona = tot_p, totale_dealer = 0 ;
int carta_cd = 0, tot_d = 0 ;

    if(prendi_c==1){

        while(num_partite>0){
            carta_cd=genera_carta(mazzo);//GENERO E AGGIORNO IL MAZZO
            totale_dealer=carta_cd+carta_sd;
            if(totale_dealer>21){//DISCRIMO I CASI IN CUI IL DEALER HA PESCATO 2 ASSI
            totale_dealer=totale_dealer-10;
            }

        tot_p=totale_persona;
        carta_generata=genera_carta(mazzo);
        tot_p=tot_p+carta_generata;
        printf("Hai %d , con la carta presa %d arrivi a %d \n",totale_persona,carta_generata,tot_p);

            if(tot_p>21 && carta_generata==11){
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

                if(tot_d>21 && carta_generata==11){
                    tot_d=tot_d-10;
                }

                if(tot_d>21 && tot_p<=21){
                    esito=1;
                }

            }

            if(tot_d <=21 && tot_p <=21){
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
        partite++;
        }
    }

    else{

        while(num_partite>0){
            carta_cd=genera_carta(mazzo);//GENERO E AGGIORNO IL MAZZO
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

                if(tot_d>21 && carta_generata==11){tot_d=totale_dealer;
                    tot_d=tot_d-10;
                }

                if(tot_d>21){
                    esito=1;;
                }
            }

            if(tot_d <=21 && tot_p <=21){
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
        partite++;
        }
    }

aggiorna_tabella(tabella_dati,totale_persona,carta_sd,prendi_c,vittorie,sconfitte,partite);
}



int calcola_percentuale(int quantita , int totale ){
int percentuale = 0 ;

percentuale = (quantita * 100 )/totale;

return percentuale ;
}

void start(int mazzo[][max], int tabella[][max]){
int indice = 1000;
int riga_1 = 0 , riga_2 = 0 , colonna_1 = 0 , colonna_2 = 0 ;

    while(indice > 0){
        genera_mazzo(mazzo);
        raccogli_dati(genera_riga(),genera_colonna(),genera_riga(),genera_colonna(),mazzo,tabella);
        crea_file(tabella);
        stampa_tabella(tabella);
        indice--;
    }
}
