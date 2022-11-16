//
// Created by olivi on 28/10/2022.
//

#include "ARBRES_NOMS.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

a_nom arbre_nom(){

    FILE* suppr;
    suppr= fopen("nom.txt","w");
    fclose(suppr);
    FILE *fic ;
    fic = fopen("test.txt","r");
    char texte[256];
    a_nom arbre=initialiser_nom();

    while(fgets(texte, 255, fic)!= NULL)
    {

        char d[] = "\t";
        char *portion1 = strtok(texte,d);
        //printf("%s\n",portion1);
        char *portion2 = strtok(NULL,d);
        //printf("%s\n",portion2);
        char *portion3 = strtok(NULL,":");
        //printf("%s\n",portion3);

        if(strcmp(portion3,"Nom")==0)
        {

            if (!isNomInFichier(portion2)){

                char coco[24];
                strcpy(coco,portion2);
                ajt_nom_txt( portion2);
                ajouter_mot_nom(&arbre.root,portion2,coco);


            }
        }
    }
    return arbre;
}

void ajt_nom_txt(char* nom){

    FILE *fic = fopen("nom.txt", "a+");

    fputs(nom,fic);

    fputs("\n",fic);

    fclose(fic);

    return;
}

int isNomInFichier(char* nom){

    FILE *fic = fopen("nom.txt", "r");

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

noeud_nom *newNode_nom(char key)
{
    noeud_nom *temp = malloc(sizeof(noeud_nom));

    temp->lettre = key;
    temp->l_flechie.head=NULL;
    temp->l_flechie.tail=NULL;
    temp->nb_formes=0;

    for (int i = 0; i < ALPHABET; i++){
        temp->sons[i] = malloc(sizeof(noeud_nom));
        temp->sons[i]->lettre='%';
    }
    return temp;
}

a_nom initialiser_nom(){

    a_nom arbre;
    int nombre;
    char valnombre;
    arbre.root = newNode_nom(' ');
    for(int i=0;i<ALPHABET;i++){

        nombre=('a'+i);
        valnombre=nombre;
        arbre.root->sons[i] = newNode_nom(valnombre);

    }

    return arbre;
}

int isLetterintab_nom(noeud_nom * noeud,char lettre){

    int i=0;


    while((i<26 && lettre!=noeud->sons[i]->lettre) ){
        i++;

    }
    if(i < 26){
        return i;
    }
    return 30;

}

int placeLibre_nom(noeud_nom * noeud){

    int i=0;

    while(noeud->sons[i]->lettre != '%'){

        i++;

    }
    return i;

}

p_flechie_nom createcell_nom(){

    p_flechie_nom cell;
    cell= malloc(sizeof (t_flechie_nom));
    cell->next=NULL;
    return cell;

}

void addTail_nom(l_flechie_nom * liste){

    p_flechie_nom new=createcell_nom();

    if(liste->head==NULL){

        liste->head= new;
        liste->tail=liste->head;
        return;

    }

    liste->tail->next=new;
    liste->tail=liste->tail->next;

}

void ajouter_lflechies_nom(noeud_nom * noeud, char* val){

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
        if (strcmp(portion3,"Nom")==0 && strcmp(portion2,val)==0) {

            printf("[%d]\n",noeud->nb_formes);
            noeud->nb_formes+=1;
            printf("[%d]\n",noeud->nb_formes);
            addTail_nom(&noeud->l_flechie);
            noeud->l_flechie.tail->flechies.nom = malloc(strlen(portion2)* sizeof(char));
            strcpy(noeud->l_flechie.tail->flechies.nom,portion2);
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

void afficher_liste_nom(noeud_nom * nom){


    p_flechie_nom temp;
    temp=nom->l_flechie.head;
    while(temp!=NULL){

        printf("%d\n",nom->nb_formes);
        printf("%s\n",temp->flechies.genre);
        printf("%s\n",temp->flechies.nom);
        printf("%s\n",temp->flechies.nombre_gram);
        printf("|\nv\n");
        temp=temp->next;
    }

}

void ajouter_mot_nom(noeud_nom ** noeud,char* val,char* copieval) {

    noeud_nom *remp = *noeud;
    char* copie=copieval;
    char lettre = val[0];
    noeud_nom *temp;
    if (val[0] == '\0') {
        return;
    }
    int verif_lettre = isLetterintab_nom(remp, lettre);
    if (verif_lettre != 30) {
        temp = remp->sons[verif_lettre];
    } else {
        int place_libre = placeLibre_nom(remp);
        remp->sons[place_libre] = newNode_nom(lettre);
        temp = remp->sons[place_libre];
    }
    if(val[1]=='\0'){

        ajouter_lflechies_nom(temp,copie);
        afficher_liste_nom(temp);

    }
    deleteletter(&val);
    ajouter_mot_nom(&temp, val,copie);
}