//
// Created by olivi on 27/10/2022.
//

#ifndef DCODEUR_ARBRES_VERBE_H
#define DCODEUR_ARBRES_VERBE_H
#define ALPHABET 26

typedef struct flechies_verbe{

    char* forme_conj;
    char* infinitif;
    char pers[2];
    char nombre_gram[2];  //singulier pluriel
    char temps[5];


}flechies_verbe;

typedef struct cell_flechies_verbe{

    flechies_verbe flechies;
    struct cell_flechies_verbe* next;

}*p_flechie_vrb;

typedef struct liste_flechie_verbe{

    p_flechie_vrb head;

}l_flechie_vrb;


typedef struct noeud_verbe{

    char lettre;
    int nb_formes; //nombre formes flechies
    l_flechie_vrb l_flechie;
    struct noeud_verbe*  sons[ALPHABET];

}noeud_verbe;

typedef struct arbre_verbe{

    noeud_verbe  *root;

}a_vrb;


void ajt_vrb_txt(char*);

int isVrbInFichier(char*);

noeud_verbe *newNode(char);

void ajouter_mot(noeud_verbe **,char*);

a_vrb initialise();

#endif //DCODEUR_ARBRES_VERBE_H
