//
// Created by olivi on 27/10/2022.
//

#ifndef DCODEUR_CONJUGUE_PHRASES_H
#define DCODEUR_CONJUGUE_PHRASES_H
#include "ARBRES_ADJ.h"
#include "crea_phrases.h"

typedef struct codeTab{

    char* cle;
    int code;

}codetab;

char * concat(char * str1, unsigned int nbc1, char * str2, unsigned int nbc2);
int randN(noeud_nom);
codetab nomconvert(noeud_nom);

char* conjugueN1(noeud_nom,noeud_adj, noeud_verbe, noeud_nom);
char* conjugueA(noeud_adj nodeA, noeud_verbe nodeV, noeud_nom nodeN2,int);
char * conjugueV(noeud_verbe nodeV, noeud_nom nodeN2,int code);
char * conjugueN2(noeud_nom);
char* conjugueN1(noeud_nom,noeud_adj, noeud_verbe, noeud_nom);

char* conjugueN1_2(noeud_nom, noeud_verbe, noeud_nom,noeud_adj);
char * conjugueV_2(noeud_verbe nodeV, noeud_nom nodeN2,noeud_adj nodeA,int code);
char* conjugueN2_2(noeud_nom nodeN2,noeud_adj nodeA);
char* conjugueA_2(noeud_adj nodeA,int code);

char * conjugueAdv(noeud_adv nodeAdv,noeud_nom nodeN2,noeud_adj nodeA);
char * conjugueV_3(noeud_verbe nodeV, noeud_adv nodeAdv,noeud_nom nodeN2,noeud_adj nodeA,int code);
char* conjugueN1_3(noeud_nom nodeN, noeud_verbe nodeV, noeud_adv nodeAdv,noeud_nom nodeN2,noeud_adj nodeA);

#endif //DCODEUR_CONJUGUE_PHRASES_H
