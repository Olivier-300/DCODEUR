//
// Created by olivi on 28/10/2022.
//

#ifndef DCODEUR_ARBRES_ADJ_H
#define DCODEUR_ARBRES_ADJ_H

#include "ARBRES_ADV.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct flechies_adj{

    char* adjectif;
    char* forme_flechie;
    char* nombre_gram;  //singulier pluriel
    char* genre;

}flechies_adj;

typedef struct cell_flechies_adj{

    flechies_adj flechies;
    struct cell_flechies_adj* next;

}t_flechie_adj,*p_flechie_adj;

typedef struct liste_flechie_adj{

    p_flechie_adj head,tail;

}l_flechie_adj;

typedef struct noeud_adj{

    char lettre;
    int nb_formes; //nombre formes flechies
    l_flechie_adj l_flechie;
    struct noeud_adj*  sons[ALPHABET];
    int fin;

}noeud_adj;

typedef struct arbre_adj{

    noeud_adj* root;

}a_adj;

a_adj arbre_adj();

void ajt_adj_txt(char*);

int isAdjInFichier(char*);

a_adj initialiser_adj();

void ajouter_mot_adj(noeud_adj **,char*,char*);

#endif //DCODEUR_ARBRES_ADJ_H
