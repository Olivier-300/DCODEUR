//
// Created by olivi on 28/10/2022.
//

#include "ARBRES_ADJ.h"

//
// Created by olivi on 28/10/2022.
//

#include "ARBRES_ADV.h"

//
// Created by olivi on 28/10/2022.
//

#include "ARBRES_NOMS.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

a_adj arbre_adj(){

    FILE* suppr;
    suppr= fopen("adj.txt","w");
    fclose(suppr);
    FILE *fic ;
    fic = fopen("test.txt","r");
    char texte[256];
    a_adj arbre=initialiser_adj();

    while(fgets(texte, 255, fic)!= NULL)
    {

        char d[] = "\t";
        char *portion1 = strtok(texte,d);
        //printf("%s\n",portion1);
        char *portion2 = strtok(NULL,d);
        //printf("%s\n",portion2);
        char *portion3 = strtok(NULL,":");
        //printf("%s\n",portion3);

        if(strcmp(portion3,"Adj")==0)
        {
            if (!isAdjInFichier(portion2)){

                char coco[24];
                strcpy(coco,portion2);
                ajt_adj_txt( portion2);
                ajouter_mot_adj(&arbre.root,portion2,coco);


            }
        }
    }
    return arbre;
}

void ajt_adj_txt(char* nom){

    FILE *fic = fopen("adj.txt", "a+");

    fputs(nom,fic);

    fputs("\n",fic);

    fclose(fic);

    return;
}

int isAdjInFichier(char* nom){

    FILE *fic = fopen("adj.txt", "r");

    char texte[24];

    while(fgets(texte, 23, fic)!= NULL){

        char d[] = "\n";
        char *portion1 = strtok(texte,d);

        if(strcmp(portion1,nom)==0){
            fclose(fic);
            return 1;
        }
    }
    fclose(fic);
    return 0;

}

noeud_adj *newNode_adj(char key)
{
    noeud_adj *temp = malloc(sizeof(noeud_adj));

    temp->lettre = key;
    temp->l_flechie.head=NULL;
    temp->l_flechie.tail=NULL;
    temp->nb_formes=0;

    for (int i = 0; i < ALPHABET; i++){
        temp->sons[i] = malloc(sizeof(noeud_adj));
        temp->sons[i]->lettre='%';
    }
    return temp;
}

a_adj initialiser_adj(){

    a_adj arbre;
    int nombre;
    char valnombre;
    arbre.root = newNode_adj(' ');
    for(int i=0;i<ALPHABET;i++){

        nombre=('a'+i);
        valnombre=nombre;
        arbre.root->sons[i] = newNode_adj(valnombre);

    }

    return arbre;
}

int isLetterintab_adj(noeud_adj * noeud,char lettre){

    int i=0;


    while((i<26 && lettre!=noeud->sons[i]->lettre) ){
        i++;

    }
    if(i < 26){
        return i;
    }
    return 30;

}

int placeLibre_adj(noeud_adj * noeud){

    int i=0;

    while(noeud->sons[i]->lettre != '%'){

        i++;

    }
    return i;

}

p_flechie_adj createcell_adj(){

    p_flechie_adj cell;
    cell= malloc(sizeof (t_flechie_adj));
    cell->next=NULL;
    return cell;

}

void addTail_adj(l_flechie_adj * liste){

    p_flechie_adj new=createcell_adj();

    if(liste->head==NULL){

        liste->head= new;
        liste->tail=liste->head;
        return;

    }

    liste->tail->next=new;
    liste->tail=liste->tail->next;

}

void ajouter_lflechies_adj(noeud_adj * noeud, char* val){

    FILE *fic ;
    noeud->nb_formes=0;
    fic = fopen("test.txt","r");
    char texte[256];
    while(fgets(texte, 255, fic)!= NULL) {


        char d[] = "\t";

        char *portion1 = strtok(texte, d);
        //printf("%s\n",portion1);
        char *portion2 = strtok(NULL, d);
        //printf("%s\n",portion2);
        char *portion3 = strtok(NULL, ":");
        //printf("%s\n",portion3);
        char *portion4 = strtok(NULL, "\0");
        if (strcmp(portion3,"Adj")==0 && strcmp(portion2,val)==0) {

            printf("[%d]\n",noeud->nb_formes);
            noeud->nb_formes+=1;
            printf("[%d]\n",noeud->nb_formes);
            addTail_adj(&noeud->l_flechie);
            noeud->l_flechie.tail->flechies.adjectif = malloc(strlen(portion2)* sizeof(char));
            strcpy(noeud->l_flechie.tail->flechies.adjectif,portion2);
            noeud->l_flechie.tail->flechies.forme_flechie = malloc(strlen(portion1)* sizeof(char));
            strcpy(noeud->l_flechie.tail->flechies.forme_flechie,portion1);

            int i=0;
            int etape=0;
            char* nv_portions;

            while (portion4[i]!='\n'){

                if(portion4[i+1]=='+'){
                    etape+=1;
                    if(etape==1){
                        nv_portions=strtok(portion4,"+");
                        noeud->l_flechie.tail->flechies.genre = malloc(strlen(nv_portions)* sizeof(char));
                        strcpy(noeud->l_flechie.tail->flechies.genre,nv_portions);
                    }


                }
                if(portion4[i+1]=='\n'){

                    nv_portions=strtok(NULL,"\n");
                    noeud->l_flechie.tail->flechies.nombre_gram = malloc(strlen(nv_portions)* sizeof(char));
                    strcpy(noeud->l_flechie.tail->flechies.nombre_gram,nv_portions);
                    break;
                }
                i++;
                if(i==12){
                    break;
                }
            }
        }
    }
    fclose(fic);
}

void afficher_liste_adj(noeud_adj * nom){


    p_flechie_adj temp;
    temp=nom->l_flechie.head;
    while(temp!=NULL){

        printf("%d\n",nom->nb_formes);
        printf("%s\n",temp->flechies.genre);
        printf("%s\n",temp->flechies.adjectif);
        printf("%s\n",temp->flechies.nombre_gram);
        printf("|\nv\n");
        temp=temp->next;
    }

}

void ajouter_mot_adj(noeud_adj ** noeud,char* val,char* copieval) {

    noeud_adj *remp = *noeud;
    char* copie=copieval;
    char lettre = val[0];
    noeud_adj *temp;
    if (val[0] == '\0') {
        return;
    }
    int verif_lettre = isLetterintab_adj(remp, lettre);
    if (verif_lettre != 30) {
        temp = remp->sons[verif_lettre];
    } else {
        int place_libre = placeLibre_adj(remp);
        remp->sons[place_libre] = newNode_adj(lettre);
        temp = remp->sons[place_libre];
    }
    if(val[1]=='\0'){

        ajouter_lflechies_adj(temp,copie);
        afficher_liste_adj(temp);

    }
    deleteletter(&val);
    ajouter_mot_adj(&temp, val,copie);
}