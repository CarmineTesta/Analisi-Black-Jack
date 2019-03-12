#include "head.h"

void crea_file(int tabella[][max]){
    FILE* fp;

    fp=fopen("Dati_BJ.txt","w");
    if(fp==NULL){
        printf("ERRORE ! \n");
    }
    else{

    for(int i=0;i<180;i++){
    fprintf(fp,"\n");

        for(int j=0;j<13;j++){
            fprintf(fp,"%d ",tabella[i][j]);
        }
    }
    fclose(fp);
    }
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

}

