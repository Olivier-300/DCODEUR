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

a_adv arbre_adv(){

    FILE* suppr;
    suppr= fopen("adv.txt","w");
    fclose(suppr);
    FILE *fic ;
    fic = fopen("test.txt","r");
    char texte[256];
    a_adv arbre=initialiser_adv();

    while(fgets(texte, 255, fic)!= NULL)
    {

        char d[] = "\t";
        char *portion1 = strtok(texte,d);
        //printf("%s\n",portion1);
        char *portion2 = strtok(NULL,d);
        //printf("%s\n",portion2);
        char *portion3 = strtok(NULL,":");
        //printf("%s\n",portion3);

        if(strcmp(portion3,"Adv")==0)
        {
            if (!isAdvInFichier(portion2)){

                char coco[24];
                strcpy(coco,portion2);
                ajt_adv_txt( portion2);
                ajouter_mot_adv(&arbre.root,portion2,coco);


            }
        }
    }
    return arbre;
}

void ajt_adv_txt(char* nom){

    FILE *fic = fopen("adv.txt", "a+");

    fputs(nom,fic);

    fputs("\n",fic);

    fclose(fic);

    return;
}

int isAdvInFichier(char* nom){

    FILE *fic = fopen("adv.txt", "r");

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

noeud_adv *newNode_adv(char key)
{
    noeud_adv *temp = malloc(sizeof(noeud_adv));

    temp->lettre = key;
    temp->l_flechie.head=NULL;
    temp->l_flechie.tail=NULL;
    temp->nb_formes=0;

    for (int i = 0; i < ALPHABET; i++){
        temp->sons[i] = malloc(sizeof(noeud_adv));
        temp->sons[i]->lettre='%';
    }
    return temp;
}

a_adv initialiser_adv(){

    a_adv arbre;
    int nombre;
    char valnombre;
    arbre.root = newNode_adv(' ');
    for(int i=0;i<ALPHABET;i++){

        nombre=('a'+i);
        valnombre=nombre;
        arbre.root->sons[i] = newNode_adv(valnombre);

    }

    return arbre;
}

int isLetterintab_adv(noeud_adv * noeud,char lettre){

    int i=0;


    while((i<26 && lettre!=noeud->sons[i]->lettre) ){
        i++;

    }
    if(i < 26){
        return i;
    }
    return 30;

}

int placeLibre_adv(noeud_adv * noeud){

    int i=0;

    while(noeud->sons[i]->lettre != '%'){

        i++;

    }
    return i;

}

p_flechie_adv createcell_adv(){

    p_flechie_adv cell;
    cell= malloc(sizeof (t_flechie_adv));
    cell->next=NULL;
    return cell;

}

void addTail_adv(l_flechie_adv * liste){

    p_flechie_adv new=createcell_adv();

    if(liste->head==NULL){

        liste->head= new;
        liste->tail=liste->head;
        return;

    }

    liste->tail->next=new;
    liste->tail=liste->tail->next;

}

void ajouter_lflechies_adv(noeud_adv * noeud, char* val){

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
        if (strcmp(portion3,"Adv")==0 && strcmp(portion2,val)==0) {

            printf("[%d]\n",noeud->nb_formes);
            noeud->nb_formes+=1;
            printf("[%d]\n",noeud->nb_formes);
            addTail_adv(&noeud->l_flechie);
            noeud->l_flechie.tail->flechies.adv = malloc(strlen(portion2)* sizeof(char));
            strcpy(noeud->l_flechie.tail->flechies.adv,portion2);
        }
    }
    fclose(fic);
}

void afficher_liste_adv(noeud_adv * nom){


    p_flechie_adv temp;
    temp=nom->l_flechie.head;
    while(temp!=NULL){

        printf("%d\n",nom->nb_formes);
        printf("%s\n",temp->flechies.adv);
        printf("|\nv\n");
        temp=temp->next;
    }

}

void ajouter_mot_adv(noeud_adv ** noeud,char* val,char* copieval) {

    noeud_adv *remp = *noeud;
    char* copie=copieval;
    char lettre = val[0];
    noeud_adv *temp;
    if (val[0] == '\0') {
        return;
    }
    int verif_lettre = isLetterintab_adv(remp, lettre);
    if (verif_lettre != 30) {
        temp = remp->sons[verif_lettre];
    } else {
        int place_libre = placeLibre_adv(remp);
        remp->sons[place_libre] = newNode_adv(lettre);
        temp = remp->sons[place_libre];
    }
    if(val[1]=='\0'){

        ajouter_lflechies_adv(temp,copie);
        afficher_liste_adv(temp);

    }
    deleteletter(&val);
    ajouter_mot_adv(&temp, val,copie);
}