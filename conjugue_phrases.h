//
// Created by olivi on 27/10/2022.
//

#ifndef DCODEUR_CONJUGUE_PHRASES_H
#define DCODEUR_CONJUGUE_PHRASES_H
#include "ARBRES_ADJ.h"

typedef struct codeTab{

    char* cle;
    int code;

}codetab;

int randN(noeud_nom);
codetab nomconvert(noeud_nom);
char* conjugueN(noeud_nom,noeud_adj, noeud_verbe, noeud_nom);
char* conjugueA(noeud_adj nodeA, noeud_verbe nodeV, noeud_nom nodeN2,int);
char * conjugueV(noeud_verbe nodeV, noeud_nom nodeN2,int code);
char * conjugueN2(noeud_nom);

#endif //DCODEUR_CONJUGUE_PHRASES_H
