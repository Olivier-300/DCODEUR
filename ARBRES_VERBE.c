//
// Created by olivi on 27/10/2022.
//

#include "ARBRES_VERBE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



a_vrb arbre_verbe(){

    FILE *fic ;
    fic = fopen("texte.txt","r");
    char texte[256];
    a_vrb arbre;

    while(fgets(texte, 255, fic)!= NULL)
    {
        char ligne[256];
        strcpy(ligne,texte);
        char d[] = "\t";
        char *portion1 = strtok(texte,d);
        //printf("%s\n",portion1);
        char *portion2 = strtok(NULL,d);
        //printf("%s\n",portion2);
        char *portion3 = strtok(NULL,":");
        //printf("%s\n",portion3);

        if(strcmp(portion3,"Ver")==0)
        {

            if (!isVrbInFichier(portion2)){

                ajt_vrb_txt( portion2);


            }
        }
    }
    return arbre;
}

void ajt_vrb_txt(char* verbe){

    FILE *fic = fopen("verbe.txt", "a+");

    fputs(verbe,fic);

    fputs("\n",fic);

    fclose(fic);

    return;
}

int isVrbInFichier(char* verbe){

    FILE *fic = fopen("verbe.txt", "r");

    char texte[24];

    while(fgets(texte, 23, fic)!= NULL){

        char d[] = "\n";
        char *portion1 = strtok(texte,d);

        if(strcmp(portion1,verbe)==0){
            fclose(fic);
            return 1;
        }
    }
    fclose(fic);
    return 0;

}

noeud_verbe *newNode(char key)
{
    noeud_verbe *temp = malloc(sizeof(noeud_verbe));
    temp->lettre = key;
    for (int i = 0; i < ALPHABET; i++){
        temp->sons[i] = malloc(sizeof(noeud_verbe));
        temp->sons[i]->lettre='%';
    }
    return temp;
}

a_vrb initialise(){

    a_vrb arbre;
    int nombre;
    char valnombre;
    arbre.root = newNode(' ');
    for(int i=0;i<ALPHABET;i++){

        nombre=('a'+i);
        valnombre=nombre;
        arbre.root->sons[i] = newNode(valnombre);

    }

    return arbre;
}

int isLetterintab(noeud_verbe* noeud,char lettre){

    int i=0;


    while((i<26 && lettre!=noeud->sons[i]->lettre) ){
        i++;

    }
    if(i < 26){
        return i;
    }
    return 30;

}

int placeLibre(noeud_verbe* noeud){

    int i=0;

    while(noeud->sons[i]->lettre != '%'){

        i++;

    }
    return i;

}

void deleteletter(char** val){

    int taille= strlen(*val);
    char* temp=*val;
    for(int i=0;i< taille;i++){
        temp[i]=temp[i+1];
    }
    *val=temp;

}

void ajouter_mot(noeud_verbe ** noeud,char* val){

    noeud_verbe* remp=*noeud;
    char lettre=val[0];
    noeud_verbe* temp;
    if(val[0]=='\0'){
        return;
    }
    int verif_lettre=isLetterintab(remp,lettre);
    if(verif_lettre!=30){
        temp= remp->sons[verif_lettre];
    }
    else{
        int place_libre= placeLibre(remp);
        remp->sons[place_libre]= newNode(lettre);
        temp=remp->sons[place_libre];
    }

    deleteletter(&val);
    ajouter_mot(&temp,val);
}
