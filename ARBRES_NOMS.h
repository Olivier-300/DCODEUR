//
// Created by olivi on 28/10/2022.
//

#ifndef DCODEUR_ARBRES_NOMS_H
#define DCODEUR_ARBRES_NOMS_H

#include "ARBRES_VERBE.h"


typedef struct flechies_nom{

    char* nom;
    char* forme_flechie;
    char* nombre_gram;  //singulier pluriel
    char* genre;

}flechies_nom;

typedef struct cell_flechies_nom{

    flechies_nom flechies;
    struct cell_flechies_nom* next;

}t_flechie_nom,*p_flechie_nom;

typedef struct liste_flechie_nom{

    p_flechie_nom head,tail;

}l_flechie_nom;

typedef struct noeud_nom{

    char lettre;
    int nb_formes; //nombre formes flechies
    l_flechie_nom l_flechie;
    struct noeud_nom*  sons[ALPHABET];

}noeud_nom;

typedef struct arbre_nom{

    noeud_nom *root;

}a_nom;

a_nom arbre_nom();

int isNomInFichier(char*);

void ajt_nom_txt(char*);

a_nom initialiser_nom();

void ajouter_mot_nom(noeud_nom **,char*,char*);

#endif //DCODEUR_ARBRES_NOMS_H
