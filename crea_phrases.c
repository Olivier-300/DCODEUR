//
// Created by olivi on 27/10/2022.
//
#include "ARBRES_VERBE.h"
#include "ARBRES_NOMS.h"
#include "ARBRES_ADJ.h"
#include "ARBRES_ADV.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crea_phrases.h"
#include <windows.h>
#include "time.h"

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

int is_forme_flechie_in_node_vrb(noeud_verbe* n) //RECHERCHE DE FORMES FLECHIES DANS KE NOEUD
{
    if (n->nb_formes)
        return 1;
    return 0;
}
int count_sons_in_node_vrb(noeud_verbe* n) // COMPTE LE NOMBRE DE FILS D'UN NOM (utile plus tard pour choisir un nombre au hasard parmi le nombre de fils possible)
{
    int i=0;
    while(n->sons[i]->lettre!='%' && i<ALPHABET){


        i++;
        if(i==25){
            return i+1;
        }

    }
    return i;

}

char* verb_random_node(noeud_verbe *n )
{
    char* mot;
    mot= malloc(24* sizeof(char));
    int next = 1; // pour savoir si on continue
    noeud_verbe *tmp = n;
    int i = rand() % count_sons_in_node_vrb(tmp); // choisir un nombre aléatoire par rapport au nombre de fils du noeud
    while(i==24){

        i = rand() % count_sons_in_node_vrb(tmp);;

    }
    while (count_sons_in_node_vrb(tmp))// parcours de l'abre
    {
        tmp=tmp->sons[i]; // on avance

        strcat(mot,&tmp->lettre);
        if(!count_sons_in_node_vrb(tmp)){
            return mot;
        }
        i = rand() % count_sons_in_node_vrb(tmp); // choisir un nombre aléatoire par rapport au nombre de fils du noeud
        /*if (is_forme_flechie_in_node_vrb(tmp)) // Dès qu'on a une forme fléchie, on fait un pile ou face pour savoir si on reste à ce mot où on continue
        {
            next = rand() % 2;
        }*/
    }
    return mot;
}
char* verb_random_tree(a_vrb t )// APPELLE CETTE FONCTION DANS LE MAIN
{

    return verb_random_node(t.root);

}

int is_forme_flechie_in_node_name(noeud_nom* n)
{
    if (n->nb_formes)
        return 1;
    return 0;
}
int count_sons_in_node_name(noeud_nom* n)
{

    int i=0;
    while(n->sons[i]->lettre!='%' && i<ALPHABET){


        i++;
        if(i==25){
            return i+1;
        }

    }
    return i;

}

char* name_random_node(noeud_nom *n )
{
    char* mot;
    mot= malloc(24* sizeof(char));
    int next = 1; // pour savoir si on continue
    noeud_nom *tmp = n;
    int i = rand() % count_sons_in_node_name(tmp); // choisir un nombre aléatoire par rapport au nombre de fils du noeud
    while (count_sons_in_node_name(tmp))// parcours de l'abre
    {
        tmp=tmp->sons[i]; // on avance

        strcat(mot,&tmp->lettre);
        if(!count_sons_in_node_name(tmp)){
            return mot;
        }
        i = rand() % count_sons_in_node_vrb(tmp); // choisir un nombre aléatoire par rapport au nombre de fils du noeud
        /*if (is_forme_flechie_in_node_vrb(tmp)) // Dès qu'on a une forme fléchie, on fait un pile ou face pour savoir si on reste à ce mot où on continue
        {
            next = rand() % 2;
        }*/
    }
    return mot;

}
char* name_random_tree(a_nom t )
{

    return name_random_node(t.root);

}

int is_forme_flechie_in_node_adj(noeud_adj* n)
{
    if (n->nb_formes)
        return 1;
    return 0;
}
int count_sons_in_node_adj(noeud_adj* n)
{
    int i=0;
    while(n->sons[i]->lettre!='%' && i<ALPHABET){


        i++;
        if(i==25){
            return i+1;
        }

    }
    return i;

}

char* adj_random_node(noeud_adj* n )
{
    char* mot;
    mot= malloc(24* sizeof(char));
    int next = 1; // pour savoir si on continue
    noeud_adj *tmp = n;
    int i = rand() % count_sons_in_node_adj(tmp); // choisir un nombre aléatoire par rapport au nombre de fils du noeud
    while (count_sons_in_node_adj(tmp))// parcours de l'abre
    {
        tmp=tmp->sons[i]; // on avance

        strcat(mot,&tmp->lettre);
        if(!count_sons_in_node_adj(tmp)){
            return mot;
        }
        i = rand() % count_sons_in_node_adj(tmp); // choisir un nombre aléatoire par rapport au nombre de fils du noeud
        /*if (is_forme_flechie_in_node_vrb(tmp)) // Dès qu'on a une forme fléchie, on fait un pile ou face pour savoir si on reste à ce mot où on continue
        {
            next = rand() % 2;
        }*/
    }
    return mot;

}
char* adj_random_tree(a_adj t )
{

    return adj_random_node(t.root);

}

int is_forme_flechie_in_node_adv(noeud_adv *n)
{
    if (n->nb_formes)
        return 1;
    return 0;
}
int count_sons_in_node_adv(noeud_adv *n)
{
    int i=0;
    while(n->sons[i]->lettre!='%' && i<ALPHABET){


        i++;
        if(i==25){
            return i+1;
        }

    }
    return i;

}

char* adv_random_node(noeud_adv *n )
{
    char* mot;
    mot= malloc(24* sizeof(char));
    int next = 1; // pour savoir si on continue
    noeud_adv *tmp = n;
    int i = rand() % count_sons_in_node_adv(tmp); // choisir un nombre aléatoire par rapport au nombre de fils du noeud
    while (count_sons_in_node_adv(tmp))// parcours de l'abre
    {
        tmp=tmp->sons[i]; // on avance;
        strcat(mot,&tmp->lettre);
        if(!count_sons_in_node_adv(tmp)){

            return mot;
        }
        i = rand() % count_sons_in_node_adv(tmp); // choisir un nombre aléatoire par rapport au nombre de fils du noeud
        /*if (is_forme_flechie_in_node_vrb(tmp)) // Dès qu'on a une forme fléchie, on fait un pile ou face pour savoir si on reste à ce mot où on continue
        {
            next = rand() % 2;
        }*/
    }
    return mot;

}
char* adv_random_tree(a_adv t )
{

    adv_random_node(t.root);

}

void recherche_mot_vrb(noeud_verbe* noeud, char* mot){

    int i=0;
    noeud_verbe* tmp=noeud;
    FILE *fic= fopen("test.txt","r");
    char texte[256];
    printf("%s\n",mot);
    while(fgets(texte, 255, fic)!= NULL){

        char d[] = "\t";
        char *portion1 = strtok(texte,d);
        //printf("%s\n",portion1);
        char *portion2 = strtok(NULL,d);
        //printf("%s\n",portion2);
        char *portion3 = strtok(NULL,":");
        //printf("%s\n",portion3);

        if(strcmp(portion2,mot)==0){

            printf("On a trouve votre mot !\n");
            fclose(fic);
            return;
        }

    }
    printf("Malheuresemnt votre mot ne figure pas dans notre arbre...\n");

}

void recherche_mot_adj(noeud_adj * noeud, char* mot){

    int i=0;
    noeud_adj * tmp=noeud;
    FILE *fic= fopen("test.txt","r");
    char texte[256];
    printf("%s\n",mot);
    while(fgets(texte, 255, fic)!= NULL){

        char d[] = "\t";
        char *portion1 = strtok(texte,d);
        //printf("%s\n",portion1);
        char *portion2 = strtok(NULL,d);
        //printf("%s\n",portion2);
        char *portion3 = strtok(NULL,":");
        //printf("%s\n",portion3);

        if(strcmp(portion2,mot)==0){

            printf("On a trouve votre mot !\n");
            fclose(fic);
            return;
        }

    }
    printf("Malheuresemnt votre mot ne figure pas dans notre arbre...\n");

}

void recherche_mot_nom(noeud_nom * noeud, char* mot){

    int i=0;
    noeud_nom * tmp=noeud;
    FILE *fic= fopen("test.txt","r");
    char texte[256];
    printf("%s\n",mot);
    while(fgets(texte, 255, fic)!= NULL){

        char d[] = "\t";
        char *portion1 = strtok(texte,d);
        //printf("%s\n",portion1);
        char *portion2 = strtok(NULL,d);
        //printf("%s\n",portion2);
        char *portion3 = strtok(NULL,":");
        //printf("%s\n",portion3);

        if(strcmp(portion2,mot)==0){

            printf("On a trouve votre mot !\n");
            fclose(fic);
            return;
        }

    }
    printf("Malheuresemnt votre mot ne figure pas dans notre arbre...\n");

}

void recherche_mot_adv(noeud_adv * noeud, char* mot){

    int i=0;
    noeud_adv * tmp=noeud;
    FILE *fic= fopen("test.txt","r");
    char texte[256];
    printf("%s\n",mot);
    while(fgets(texte, 255, fic)!= NULL){

        char d[] = "\t";
        char *portion1 = strtok(texte,d);
        //printf("%s\n",portion1);
        char *portion2 = strtok(NULL,d);
        //printf("%s\n",portion2);
        char *portion3 = strtok(NULL,":");
        //printf("%s\n",portion3);

        if(strcmp(portion2,mot)==0){

            printf("On a trouve votre mot !\n");
            fclose(fic);
            return;
        }

    }
    printf("Malheuresemnt votre mot ne figure pas dans notre arbre...\n");

}

noeud_nom * get_l_flechie_nom(a_nom arbre,char* nom){

    noeud_nom* tmp=arbre.root;
    for(int i=0;i< strlen(nom);i++){

        int j=0;
        while(tmp->sons[j]->lettre != nom[i]){

            j++;

        }
        tmp=tmp->sons[j];

    }
    return tmp;

}

noeud_adj* get_l_flechie_adj(a_adj arbre,char* nom){

    noeud_adj* tmp=arbre.root;
    for(int i=0;i< strlen(nom);i++){

        int j=0;
        while(tmp->sons[j]->lettre != nom[i]){

            j++;

        }
        tmp=tmp->sons[j];

    }
    return tmp;

}

noeud_adv* get_l_flechie_adv(a_adv arbre,char* nom){

    noeud_adv* tmp=arbre.root;
    for(int i=0;i< strlen(nom);i++){

        int j=0;
        while(tmp->sons[j]->lettre != nom[i]){

            j++;

        }
        tmp=tmp->sons[j];

    }
    return tmp;

}

noeud_verbe * get_l_flechie_vrb(a_vrb arbre,char* nom){

    noeud_verbe * tmp=arbre.root;
    for(int i=0;i< strlen(nom);i++){

        int j=0;
        while(tmp->sons[j]->lettre != nom[i]){

            j++;

        }
        tmp=tmp->sons[j];

    }
    return tmp;

}


void recherche_flechie_vrb(a_vrb arbre, char* mot){

    int i=0;
    noeud_verbe* tmp;
    FILE *fic= fopen("test.txt","r");
    char texte[256];
    while(fgets(texte, 255, fic)!= NULL){

        char d[] = "\t";
        char *portion1 = strtok(texte,d);
        //printf("%s\n",portion1);
        char *portion2 = strtok(NULL,d);
        //printf("%s\n",portion2);
        char *portion3 = strtok(NULL,":");
        //printf("%s\n",portion3);
        char *portion4 = strtok(NULL,"\0");

        if(strcmp(portion1,mot)==0 && strcmp(portion3,"Ver")==0){


            tmp= get_l_flechie_vrb(arbre,portion2);
            p_flechie_vrb remp=tmp->l_flechie.head;
            while(strcmp(remp->flechies.forme_conj,portion1)!=0){

                remp=remp->next;

            }
            printf("On a trouve votre mot !\n\n");
            printf("Voici sa description : \n\n");
            Color(10,0);
            printf("%s, du verbe %s",mot,tmp->l_flechie.head->flechies.infinitif);
            if(strcmp(tmp->l_flechie.head->flechies.temps,"IPSim")==0){
                printf(",Passe simple de l'indicatif\n");
            }
            else if(strcmp(tmp->l_flechie.head->flechies.temps,"IImp")==0){
                printf(", Imparfait de l'indicatif\n");
            }
            else if(strcmp(tmp->l_flechie.head->flechies.temps,"PPre")==0){
                printf(", Participe present\n");
                return;
            }
            else if(strcmp(tmp->l_flechie.head->flechies.temps,"SImp")==0){
                printf(", Imparfait du subjonctif\n");
            }
            else if(strcmp(tmp->l_flechie.head->flechies.temps,"IPre")==0){
                printf(", Present de l'indicatif\n");
            }
            else if(strcmp(tmp->l_flechie.head->flechies.temps,"CPre")==0){
                printf(", Present du Conditionel\n");
            }
            else if(strcmp(tmp->l_flechie.head->flechies.temps,"PPas")==0){
                printf(", Participe passe\n");
            }
            else if(strcmp(tmp->l_flechie.head->flechies.temps,"IFut")==0){
                printf(", Future de l'indicatif\n");
            }
            else if(strcmp(tmp->l_flechie.head->flechies.temps,"Inf")==0){
                printf(",A l'infinitif\n");
                return;
            }

            if(strcmp(tmp->l_flechie.head->flechies.pers,"P1")==0){
                printf("Premiere personne");
            }
            if(strcmp(tmp->l_flechie.head->flechies.pers,"P2")==0){
                printf("Deuxieme personne");
            }
            if(strcmp(tmp->l_flechie.head->flechies.pers,"P3")==0){
                printf("Troisieme personne");
            }
            if(strcmp(tmp->l_flechie.head->flechies.nombre_gram,"PL")==0){

                printf(" du pluriel.\n");

            }
            else{
                printf(" du singulier\n");
            }
            printf("\n");
            Color(11,0);
            fclose(fic);
            return;
        }
    }

    printf("Malheuresemnt votre mot ne figure pas dans notre arbre...\n");
    printf("SI vous souhaitez ajouter votre mot a l'arbre, faites la à partir du menu.)\n");
}

void recherche_flechie_nom(a_nom arbre, char* mot){

    int i=0;
    noeud_nom * tmp;
    FILE *fic= fopen("test.txt","r");
    char texte[256];
    while(fgets(texte, 255, fic)!= NULL){

        char d[] = "\t";
        char *portion1 = strtok(texte,d);
        //printf("%s\n",portion1);
        char *portion2 = strtok(NULL,d);
        //printf("%s\n",portion2);
        char *portion3 = strtok(NULL,":");
        //printf("%s\n",portion3);
        char *portion4 = strtok(NULL,"\0");

        if(strcmp(portion1,mot)==0 && strcmp(portion3,"Nom")==0){


            tmp= get_l_flechie_nom(arbre,portion2);
            p_flechie_nom remp=tmp->l_flechie.head;
            while(strcmp(remp->flechies.forme_flechie,portion1)!=0){

                remp=remp->next;

            }
            printf("On a trouve votre mot !\n\n");
            printf("Voici sa description : \n\n");
            Color(10,0);
            printf("%s, du nom %s",mot,tmp->l_flechie.head->flechies.nom);
            if(strcmp(tmp->l_flechie.head->flechies.genre,"Mas")==0){
                printf(", accorde au masculin\n");
            }
            else{
                printf(", accorde au feminin");
            }
            if(strcmp(tmp->l_flechie.head->flechies.nombre_gram,"PL")==0){

                printf(" du pluriel.\n");

            }
            else{
                printf(" du singulier\n");
            }
            printf("\n");
            Color(11,0);
            fclose(fic);
            return;
        }
    }

    printf("Malheuresemnt votre mot ne figure pas dans notre arbre...\n");
    printf("SI vous souhaitez ajouter votre mot a l'arbre, faites la à partir du menu.)\n");

}

void recherche_flechie_adj(a_adj arbre, char* mot){

    int i=0;
    noeud_adj * tmp;
    FILE *fic= fopen("test.txt","r");
    char texte[256];
    while(fgets(texte, 255, fic)!= NULL){

        char d[] = "\t";
        char *portion1 = strtok(texte,d);
        //printf("%s\n",portion1);
        char *portion2 = strtok(NULL,d);
        //printf("%s\n",portion2);
        char *portion3 = strtok(NULL,":");
        //printf("%s\n",portion3);
        char *portion4 = strtok(NULL,"\0");

        if(strcmp(portion1,mot)==0 && strcmp(portion3,"Adj")==0){


            tmp= get_l_flechie_adj(arbre,portion2);
            p_flechie_adj remp=tmp->l_flechie.head;
            while(strcmp(remp->flechies.forme_flechie,mot)!=0){

                remp=remp->next;

            }
            printf("On a trouve votre mot !\n\n");
            printf("Voici sa description : \n\n");
            Color(10,0);
            printf("%s, de l'adjectif %s",mot,tmp->l_flechie.head->flechies.adjectif);
            if(strcmp(tmp->l_flechie.head->flechies.genre,"Mas")==0){
                printf(", accorde au masculin\n");
            }
            else{
                printf(", accorde au feminin");
            }
            if(strcmp(tmp->l_flechie.head->flechies.nombre_gram,"PL")==0){

                printf(" du pluriel.\n");

            }
            else{
                printf(" du singulier\n");
            }
            printf("\n");
            Color(11,0);
            fclose(fic);
            return;
        }
    }

    printf("Malheuresemnt votre mot ne figure pas dans notre arbre...\n");
    printf("SI vous souhaitez ajouter votre mot a l'arbre, faites la à partir du menu.\n\n");

}