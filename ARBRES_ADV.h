//
// Created by olivi on 28/10/2022.
//

#ifndef DCODEUR_ARBRES_ADV_H
#define DCODEUR_ARBRES_ADV_H

#include "ARBRES_NOMS.h"

typedef struct flechies_adverbe{

    int nb_formes;
    char* forme_flechie;

}flechies_adverbe;

typedef struct cell_flechies_adv{

    flechies_adverbe flechies;
    struct cell_flechies_adv* next;

}*p_flechie_adv;

typedef struct liste_flechie_adv{

    p_flechie_adv head;

}l_flechie_adv;

typedef struct noeud_adv{

    char lettre;
    int nb_formes; //nombre formes flechies
    l_flechie_adv l_flechie;
    struct noeud_adv*  sons[ALPHABET];

}noeud_adv;

typedef struct arbre_adv{

    noeud_adv root;

}a_adv;

#endif //DCODEUR_ARBRES_ADV_H
