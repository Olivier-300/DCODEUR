//
// Created by olivi on 27/10/2022.
//
#include <stdlib.h>
#include "conjugue_phrases.h"
#include <string.h>


int randN(noeud_nom node){
    return rand()%node.nb_formes;
}
// Fonction qui renvoi le code(pour connaitre les accords & genre) d'un nom ainsique sa forme conjugué
codetab nomconvert(noeud_nom nodeN){
    p_flechie_nom temp = nodeN.l_flechie.head;
    for (int i = 0;i> randN(nodeN);i++) {
        temp = temp->next;  //choisi un nom aléatoire
    }
    char* accord = temp->flechies.nombre_gram; //stockage accord & genre ds variable
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
// tableau de conversion pour accorder et utiliser le code
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
    while (cletv == 0){  // tant qu'on ne trouve pas le code correspondant

        if (tableau[cpt].code == code){
            cletv = 1;
        }
        else{
            cpt += 1;
        }
    }
    char* determinant = tableau[cpt].cle; // le determinant mis devant le mot
    char* nom1 = temp->flechies.forme_flechie;
    codetab resultat;

    strcat(determinant,nom1); //concatenation
    resultat.code = code;
    resultat.cle = determinant;
    return resultat;
}

// printf("Taper 1 pour : nom - adjectif - verbe - nom\n");
char* conjugueN2(noeud_nom nodeN2){  // dernier nom de la phrase
    codetab nomcode = nomconvert(nodeN2);
    return nomcode.cle;
}
//forme fléchie du verbe
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
    while (allgood == 0){  // trouver la forme fléchie qui correspond au code
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
//Forme fléchie de l'adjectif
char* conjugueA(noeud_adj nodeA, noeud_verbe nodeV, noeud_nom nodeN2,int code){
    char* acc = 'SG';
    char* genre = "Fem";
    if(code > 50){
        code = code -100;
    }
    if (code%2 == 0){
        acc = 'PL';
    }
    if(code > 5){
        genre = 'Mas';
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
    char* espace = ' ';
    strcat(adj,espace);

    char * phrase = conjugueV(nodeV,nodeN2,code);
    strcat(adj,phrase);
    return adj;
}
//Forme fléchie du premier nom qui appelle ensuite les mots suivants
char* conjugueN1(noeud_nom nodeN,noeud_adj nodeA, noeud_verbe nodeV, noeud_nom nodeN2){

    char * determinant = nomconvert(nodeN).cle;
    int code = nomconvert(nodeN).code;
    strcat(determinant," ");

    char* phrase = conjugueA(nodeA,nodeV,nodeN2,code);
    strcat(determinant,phrase);
    return determinant;
}

//Taper 2 pour : nom - `qui` - verbe - nom - adjectif\n")
char* conjugueA_2(noeud_adj nodeA,int code){
    char* acc = 'SG';
    char* genre = "Fem";
    if(code > 50){
        code = code -100;
    }
    if (code%2 == 0){
        acc = 'PL';
    }
    if(code > 5){
        genre = 'Mas';
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
    return adj;
}

char* conjugueN2_2(noeud_nom nodeN2,noeud_adj nodeA){  // dernier nom de la phrase
    codetab nomcode = nomconvert(nodeN2);
    char* phrase = conjugueA_2(nodeA,nomcode.code);
    strcat(nomcode.cle," ");
    strcat(nomcode.cle,phrase);
    return nomcode.cle;
}

char * conjugueV_2(noeud_verbe nodeV, noeud_nom nodeN2,noeud_adj nodeA,int code){
    char* acc = 'SG';
    if(code > 50){
    code = code -100;
    }
    if(code > 5){
        code = code -10;
    }
    if (code%2 == 0){
        acc = 'PL';
    }
    int allgood = 0;

    p_flechie_vrb temp = nodeV.l_flechie.head;
    while (allgood == 0){  // trouver la forme fléchie qui correspond au code
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

    char * phrase = conjugueN2_2(nodeN2,nodeA);
    strcat(verbe,phrase);
    return verbe;
}

char* conjugueN1_2(noeud_nom nodeN, noeud_verbe nodeV, noeud_nom nodeN2,noeud_adj nodeA){
    char * determinant = nomconvert(nodeN).cle;
    int code = nomconvert(nodeN).code;
    strcat(determinant," qui ");

    char* phrase = conjugueV_2(nodeV,nodeN2,nodeA,code);
    strcat(determinant,phrase);
    return determinant;
}


//Taper 3 pour : nom - `n'` - verbe - `pas` - adverbe - nom - adjectif
char * conjugueAdv(noeud_adv nodeAdv,noeud_nom nodeN2,noeud_adj nodeA){
    char* adverbe = nodeAdv.l_flechie.head->flechies.forme_flechie;
    char* phrase = conjugueN2_2(nodeN2,nodeA); //même fin que phrase 2 donc mêmes fonctions
}

char * conjugueV_3(noeud_verbe nodeV, noeud_adv nodeAdv,noeud_nom nodeN2,noeud_adj nodeA,int code){
    char* acc = 'SG';
    if(code > 50){
        code = code -100;
    }
    if(code > 5){
        code = code -10;
    }
    if (code%2 == 0){
        acc = 'PL';
    }
    int allgood = 0;

    p_flechie_vrb temp = nodeV.l_flechie.head;
    while (allgood == 0){  // trouver la forme fléchie qui correspond au code
        if (temp->flechies.nombre_gram == acc && temp->flechies.pers == "P3"){
            allgood = 1;
        }
        else{
            temp = temp->next;
        }
    }

    char* verbe = temp->flechies.forme_conj;
    char* espace = ' pas ';
    strcat(verbe,espace);

    char * phrase = conjugueAdv(nodeAdv,nodeN2,nodeA);
    strcat(verbe,phrase);
    return verbe;
}


char* conjugueN1_3(noeud_nom nodeN, noeud_verbe nodeV, noeud_adv nodeAdv,noeud_nom nodeN2,noeud_adj nodeA){
    char * determinant = nomconvert(nodeN).cle;
    int code = nomconvert(nodeN).code;
    strcat(determinant," ne ");

    char* phrase = conjugueV_3(nodeV,nodeAdv,nodeN2,nodeA,code);
    strcat(determinant,phrase);
    return determinant;
}


