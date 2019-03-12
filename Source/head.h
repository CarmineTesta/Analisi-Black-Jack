#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define max 500
//genera.c
void genera_mazzo(int [][max]);//INSERISCI NELL'ARRAY NELLE RISPETTIVE POSIZIONE IL NUMERO DI CARTE PRESENTI IN UN MAZZO ALL'INIZIO DELLA PARTITA
void crea_tabella(int[][max]);//COSTRUISCE LA MATRICE CON TUTTE LE POSSIBILI COMBINAZIONI DI MANI
int genera_riga(void);
int genera_colonna(void);
int genera_carta(int[][max]);
//aggiorna.c
void aggiorna_tabella(int [][max],int , int , int , int , int , int );//AGGIORNA I VALORI NELLA TABELLA CON UNA CERTA MANO E CONTRO UNA CERTA MANO
void aggiorna_mazzo(int[][max],int,int);
//file.c
void crea_file(int [][max]);//SCRIVE IL FILE DI TESTO DOVE SARANNO CONSERVATI I DATI PRESI DALLA MATRICE
void leggi_dati(int [][max]);//APRE IL FILE DI TESTO DOVE SONO CONSERVATI I DATI E LI TRASCRIVE IN UNA MATRICE
//stampa
void stampa_mazzo(int [][max]);//MOSTRA QUELLO CHE HA COSTRUITO 'genera_mazzo'
void stampa_tabella(int[][max]);

//source.c
int val_carta(int [][max], int , int );//RESTITUISCE IL VALORE DELLA CARTA SE E' UN ASSO IL VALORE SARA' 11
int stabilisci_vincitore(int , int);//ritorna 1 se vince il primo intero 0 se vince il secondo intero
void raccogli_dati(int ,int ,int , int , int [][max], int [][max]);
void simula_partite(int , int , int [][max], int ,int , int [][max]);
int calcola_percentuale(int  , int  );
void start(int[][max], int[][max]);


#endif // HEAD_H_INCLUDED
