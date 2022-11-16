//
// Created by olivi on 28/10/2022.
//

#ifndef DCODEUR_ARBRES_ADV_H
#define DCODEUR_ARBRES_ADV_H

#include "ARBRES_NOMS.h"

typedef struct flechies_adverbe{

    char* adv;
    char* forme_flechie;

}flechies_adverbe;

typedef struct cell_flechies_adv{

    flechies_adverbe flechies;
    struct cell_flechies_adv* next;

}t_flechie_adv,*p_flechie_adv;

typedef struct liste_flechie_adv{

    p_flechie_adv head,tail;

}l_flechie_adv;

typedef struct noeud_adv{

    char lettre;
    int nb_formes; //nombre formes flechies
    l_flechie_adv l_flechie;
    struct noeud_adv*  sons[ALPHABET];

}noeud_adv;

typedef struct arbre_adv{

    noeud_adv* root;

}a_adv;

a_adv arbre_adv();

void ajt_adv_txt(char*);

int isAdvInFichier(char*);

a_adv initialiser_adv();

void ajouter_mot_adv(noeud_adv **,char*,char*);

#endif //DCODEUR_ARBRES_ADV_H
