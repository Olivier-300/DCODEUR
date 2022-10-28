//
// Created by olivi on 28/10/2022.
//

#ifndef DCODEUR_ARBRES_ADJ_H
#define DCODEUR_ARBRES_ADJ_H

#include "ARBRES_ADV.h"

typedef struct flechies_adj{

    int nb_formes;
    char* forme_flechie;
    char nombre_gram[2];  //singulier pluriel
    char genre[3];

}flechies_adj;

typedef struct cell_flechies_adj{

    flechies_adj flechies;
    struct cell_flechies_adj* next;

}*p_flechie_adj;

typedef struct liste_flechie_adj{

    p_flechie_adj head;

}l_flechie_adj;

typedef struct noeud_adj{

    char lettre;
    int nb_formes; //nombre formes flechies
    l_flechie_adj l_flechie;
    struct noeud_adj*  sons[ALPHABET];

}noeud_adj;

#endif //DCODEUR_ARBRES_ADJ_H
