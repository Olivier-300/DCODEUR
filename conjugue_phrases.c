//
// Created by olivi on 27/10/2022.
//
#include <stdlib.h>
#include "conjugue_phrases.h"
#include <string.h>


int randN(noeud_nom node){
    return rand()%node.nb_formes;
}

codetab nomconvert(noeud_nom nodeN){
    p_flechie_nom temp = nodeN.l_flechie.head;
    for (int i = 0;i> randN(nodeN);i++) {
        temp = temp->next;
    }
    char* accord = temp->flechies.nombre_gram;
    char* genre = temp->flechies.genre;

    // voyelle  masc  sing
    int code = 000;
    if (accord == "SG"){
        code += 1;
    }
    if (genre == "Mas"){
        code += 10;
    }
    if (nodeN.lettre == 'a' || nodeN.lettre == 'e' ||nodeN.lettre == 'i' ||nodeN.lettre == 'o' ||nodeN.lettre == 'u' ||nodeN.lettre == 'y' ){
        code += 100;
    }

    codetab * tableau;
    tableau = malloc(8*sizeof(codetab));

    tableau[0].code = 000;
    tableau[1].code = 001;
    tableau[2].code = 010;
    tableau[3].code = 011;
    tableau[4].code = 100;
    tableau[5].code = 101;
    tableau[6].code = 110;
    tableau[7].code = 111;

    tableau[0].cle = "Des ";
    tableau[1].cle = "Une ";
    tableau[2].cle = "Des ";
    tableau[3].cle = "Un ";
    tableau[4].cle = "L'";
    tableau[5].cle = "L'";
    tableau[6].cle = "L'";
    tableau[7].cle = "L'";

    int cletv = 0;
    int cpt = 0;
    while (cletv == 0){

        if (tableau[cpt].code == code){
            cletv = 1;
        }
        else{
            cpt += 1;
        }
    }
    char* determinant = tableau[cpt].cle;
    char* nom1 = temp->flechies.forme_flechie;
    codetab resultat;

    strcat(determinant,nom1);
    resultat.code = code;
    resultat.cle = determinant;
    return resultat;
}

// printf("Taper 1 pour : nom - adjectif - verbe - nom\n");
char* conjugueN2(noeud_nom nodeN2){
    codetab nomcode = nomconvert(nodeN2);
    return nomcode.cle;
}

char * conjugueV(noeud_verbe nodeV, noeud_nom nodeN2,int code){
    char* acc = 'SG';
    if(code > 5){
        code = code -10;
    }
    if (code%2 == 0){
        acc = 'PL';
    }
    int allgood = 0;

    p_flechie_vrb temp = nodeV.l_flechie.head;
    while (allgood == 0){
        if (temp->flechies.nombre_gram == acc && temp->flechies.pers == "P3"){
            allgood = 1;
        }
        else{
            temp = temp->next;
        }
    }

    char* verbe = temp->flechies.forme_conj;
    char* espace = ' ';
    strcat(verbe,espace);

    char * phrase = conjugueN2(nodeN2);
    strcat(verbe,phrase);
    return verbe;
}

char* conjugueA(noeud_adj nodeA, noeud_verbe nodeV, noeud_nom nodeN2,int code){
    char acc[] = "SG";
    char* genre = "Fem";
    if(code > 50){
        code = code -100;
    }
    if (code%2 == 0){
        strcpy(acc,"PL");
    }
    if(code > 5){
        genre = "Mas";
    }
    int allgood = 0;
    p_flechie_adj temp = nodeA.l_flechie.head;
    while (allgood == 0){
        if (temp->flechies.nombre_gram == acc && temp->flechies.genre == genre){
            allgood = 1;
        }
        else{
            temp = temp->next;
        }
    }

    char* adj = temp->flechies.forme_flechie;
    char* espace = " ";
    strcat(adj,espace);

    char * phrase = conjugueV(nodeV,nodeN2,code);
    strcat(adj,phrase);
    return adj;
}

char* conjugueN1(noeud_nom nodeN,noeud_adj nodeA, noeud_verbe nodeV, noeud_nom nodeN2){

    char * determinant = nomconvert(nodeN).cle;
    int code = nomconvert(nodeN).code;
    strcat(determinant," ");

    char* phrase = conjugueA(nodeA,nodeV,nodeN2,code);
    strcat(determinant,phrase);
    return determinant;
}