//
// Created by olivi on 28/10/2022.
//

#ifndef DCODEUR_ARBRES_NOMS_H
#define DCODEUR_ARBRES_NOMS_H

#include "ARBRES_VERBE.h"

typedef struct flechies_nom{

    int nb_formes;
    char* forme_flechie;
    char nombre_gram[2];  //singulier pluriel
    char genre[3];

}flechies_nom;

typedef struct cell_flechies_nom{

    flechies_nom flechies;
    struct cell_flechies_nom* next;

}*p_flechie_nom;

typedef struct liste_flechie_nom{

    p_flechie_nom head;

}l_flechie_nom;

typedef struct noeud_nom{

    char lettre;
    int nb_formes; //nombre formes flechies
    l_flechie_nom l_flechie;
    struct noeud_nom*  sons[ALPHABET];

}noeud_nom;

typedef struct arbre_nom{

    noeud_nom root;

}a_nom;
#endif //DCODEUR_ARBRES_NOMS_H
