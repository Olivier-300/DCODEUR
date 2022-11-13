//
// Created by olivi on 27/10/2022.
//

#include "ARBRES_VERBE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



a_vrb arbre_verbe(){

    FILE *suppr=fopen("verbe.txt","w");
    fclose(suppr);
    FILE *fic ;
    fic = fopen("texte.txt","r");
    char texte[256];
    a_vrb arbre=initialise();

    while(fgets(texte, 255, fic)!= NULL)
    {

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

                char coco[24];
                strcpy(coco,portion2);
                ajt_vrb_txt( portion2);
                ajouter_mot(&arbre.root,portion2,coco);

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
    temp->l_flechie.head=NULL;
    temp->l_flechie.tail=NULL;
    temp->nb_formes=0;

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

p_flechie_vrb createcell(){

    p_flechie_vrb cell;
    cell= malloc(sizeof (t_flechie_vrb));
    cell->next=NULL;
    return cell;

}

void addTail(l_flechie_vrb* liste){

    p_flechie_vrb new=createcell();

    if(liste->head==NULL){

        liste->head= new;
        liste->tail=liste->head;
        return;

    }

    liste->tail->next=new;
    liste->tail=liste->tail->next;

}

void suppr_chaine(char **chaine){

    int taille= strlen(*chaine);
    char* temp=*chaine;
    while(temp[0]!='\0'){
        for(int i=0;i< taille;i++){
            temp[i]=temp[i+1];
        }
    }
    *chaine=temp;
}
void ajouter_lflechies(noeud_verbe* noeud, char* val){

    FILE *fic ;
    noeud->nb_formes=0;
    fic = fopen("texte.txt","r");
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

        if (strcmp(portion3,"Ver")==0 && strcmp(portion2,val)==0) {
            noeud->nb_formes+=1;
            addTail(&noeud->l_flechie);
            noeud->l_flechie.tail->flechies.infinitif = malloc(strlen(portion2)* sizeof(char));
            noeud->l_flechie.tail->flechies.forme_conj = malloc(strlen(portion1)* sizeof(char));
            strcpy(noeud->l_flechie.tail->flechies.infinitif,portion2);
            strcpy(noeud->l_flechie.tail->flechies.forme_conj,portion1);


            int i=0;
            int etape=0;
            char* nv_portions;
            if((strcmp(portion4,"PPre\n")==0) || (strcmp(portion4,"Inf\n"))==0){

                noeud->l_flechie.tail->flechies.temps = malloc(strlen(nv_portions)* sizeof(char));
                strcpy(noeud->l_flechie.tail->flechies.temps,portion4);

            }

            while (portion4[i]!='\n'){

                if(portion4[i+1]=='+'){
                    etape+=1;
                    if(etape==1){
                        nv_portions=strtok(portion4,"+");
                        noeud->l_flechie.tail->flechies.temps = malloc(strlen(nv_portions)* sizeof(char));
                        strcpy(noeud->l_flechie.tail->flechies.temps,nv_portions);


                    }
                    if(etape==2){
                        nv_portions=strtok(NULL,"+");
                        noeud->l_flechie.tail->flechies.nombre_gram = malloc(strlen(nv_portions)* sizeof(char));
                        strcpy(noeud->l_flechie.tail->flechies.nombre_gram,nv_portions);
                    }

                }
                if(portion4[i+1]=='\n'){
                    etape+=1;
                    if(etape==3){
                        nv_portions=strtok(NULL,"\n");
                        strcpy(noeud->l_flechie.tail->flechies.pers,nv_portions);
                        printf("%s\n",noeud->l_flechie.tail->flechies.pers);
                    }
                    break;
                }
                if(portion4[i+1]==':'){

                    nv_portions=strtok(NULL,":");
                    strcpy(noeud->l_flechie.tail->flechies.pers,nv_portions);

                    int etape2=0;
                    noeud->l_flechie.tail->flechies.suite= malloc(sizeof(flechies_verbe));
                    while(portion4[i]!='\n'){
                        if(portion4[i+1]=='+'){

                            etape2+=1;
                            if(etape2==1){
                                nv_portions=strtok(NULL,"+");
                                noeud->l_flechie.tail->flechies.suite->temps = malloc(strlen(nv_portions)* sizeof(char));
                                strcpy(noeud->l_flechie.tail->flechies.suite->temps,nv_portions);
                            }
                            if(etape2==2){
                                nv_portions=strtok(NULL,"+");
                                noeud->l_flechie.tail->flechies.suite->nombre_gram = malloc(strlen(nv_portions)* sizeof(char));
                                strcpy(noeud->l_flechie.tail->flechies.suite->nombre_gram,nv_portions);
                            }
                        }
                        if(portion4[i+1]=='\n'){
                            etape2+=1;
                            if(etape2==3){
                                nv_portions=strtok(NULL,"\n");
                                strcpy(noeud->l_flechie.tail->flechies.suite->pers,nv_portions);
                            }

                            break;
                        }
                        i++;
                    }

                }
                i++;

                if(i==24){
                    break;
                }
            }


        }
    }
    fclose(fic);
}

void afficher_liste(noeud_verbe* verbe){


    p_flechie_vrb temp;
    temp=verbe->l_flechie.head;
    while(temp){

        printf("%d\n",verbe->nb_formes);
        printf("%s\n",temp->flechies.temps);
        printf("%s\n",temp->flechies.forme_conj);
        printf("%s\n",temp->flechies.infinitif);
        printf("%s\n",temp->flechies.pers);
        printf("%s\n",temp->flechies.nombre_gram);
        printf("|\nv\n");
        temp=temp->next;
    }

}


void ajouter_mot(noeud_verbe ** noeud,char* val,char* copieval) {

    noeud_verbe *remp = *noeud;
    char* copie=copieval;
    char lettre = val[0];
    noeud_verbe *temp;
    if (val[0] == '\0') {
        return;
    }
    int verif_lettre = isLetterintab(remp, lettre);
    if (verif_lettre != 30) {
        temp = remp->sons[verif_lettre];
    } else {
        int place_libre = placeLibre(remp);
        remp->sons[place_libre] = newNode(lettre);
        temp = remp->sons[place_libre];
    }
    if(val[1]=='\0'){

        ajouter_lflechies(temp,copie);
        afficher_liste(temp);

    }
    deleteletter(&val);
    ajouter_mot(&temp, val,copie);
}