//
// Created by olivi on 27/10/2022.
//
#include <stdlib.h>
#include "conjugue_phrases.h"
#include <string.h>


char * concat(char * str1, unsigned int nbc1, char * str2, unsigned int nbc2){
    unsigned int i = 0;
    char * rstr = (char*)malloc((nbc1+nbc2+1) * sizeof(char));
    for(i = 0; i < nbc1; i++){
        *(rstr + i) = *(str1 + i);
    }

    for(i = 0; i < nbc2; i++){
        *(rstr + nbc1 + i) = *(str2 + i);
    }
    *(rstr + nbc1 + nbc2 + 1) = '\0';
    return rstr;
}

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
    if (strcmp(accord,"SG")==0){
        code += 1;
    }
    if (strcmp(genre,"Mas")==0){
        code += 10;
    }
    if (nodeN.l_flechie.head->flechies.forme_flechie[0] == 'a' || nodeN.l_flechie.head->flechies.forme_flechie[0] == 'e' ||nodeN.l_flechie.head->flechies.forme_flechie[0] == 'i' ||nodeN.l_flechie.head->flechies.forme_flechie[0] == 'o' ||nodeN.l_flechie.head->flechies.forme_flechie[0] == 'u' ||nodeN.l_flechie.head->flechies.forme_flechie[0] == 'y' ){
        code += 100;
    }
// tableau de conversion pour accorder et utiliser le code
    codetab * tableau;
    tableau = malloc(8*sizeof(codetab));

    tableau[0].code = 0;
    tableau[1].code = 1;
    tableau[2].code = 10;
    tableau[3].code = 11;
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
    char* determinant; // le determinant mis devant le mot
    determinant=tableau[cpt].cle;
    char* nom1 = temp->flechies.forme_flechie;
    codetab resultat;
    determinant = concat(determinant, strlen(determinant),nom1, strlen(nom1));
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
    char acc[] = "SG";
    if(code > 5){
        code = code -10;
    }
    if (code%2 == 0){
        strcpy(acc,"PL");
    }
    int allgood = 0;

    p_flechie_vrb temp = nodeV.l_flechie.head;
    while (allgood == 0 && temp!=NULL){  // trouver la forme fléchie qui correspond au code

        if (temp->flechies.nombre_gram == acc && strcmp(temp->flechies.pers,"P3")==0){
            allgood = 1;
        }
        else{
            temp = temp->next;
        }

    }
    if(!temp){
        temp = nodeV.l_flechie.head;
    }
    char* verbe = temp->flechies.forme_conj;
    char espace[] = " " ;
    verbe=concat(verbe, strlen(verbe),espace, strlen(espace));

    char * phrase = conjugueN2(nodeN2);
    concat(verbe, strlen(verbe),phrase, strlen(phrase));
    return verbe;
}
//Forme fléchie de l'adjectif
char* conjugueA(noeud_adj nodeA, noeud_verbe nodeV, noeud_nom nodeN2,int code){

    a_adj arbre= arbre_adj();
    char acc[] = "SG";
    char genre[] = "Fem";
    if(code > 50){
        code = code -100;
    }
    if (code%2 == 0){
        strcpy(acc,"PL");
    }
    if(code > 5){
        strcpy(genre,"Mas");
    }
    int allgood = 0;
    p_flechie_adj temp = nodeA.l_flechie.head;
    while (allgood == 0 && temp){
        if ((strcmp(temp->flechies.nombre_gram,acc)==0) && (strcmp(temp->flechies.genre,genre)==0)){
            allgood = 1;
        }
        else{
            temp = temp->next;
        }
    }
    if(!temp){
        temp = nodeA.l_flechie.head;
        while(strcmp(temp->flechies.genre,"InvGen")!=0){
            temp=temp->next;
        }
        if(!temp){

            return conjugueA(*(get_l_flechie_adj(arbre, adj_random_tree(arbre))),nodeV,nodeN2,code);

        }
    }
    char* adj;
    adj=malloc(32*sizeof (char));
    strcpy(adj,temp->flechies.forme_flechie);
    char espace[] = " ";
    concat(adj, strlen(adj),espace, strlen(espace));
    char * phrase = malloc(30* sizeof(char));
    strcpy(phrase,conjugueV(nodeV,nodeN2,code));
    concat(adj, strlen(adj),phrase, strlen(phrase));

    return adj;
}
//Forme fléchie du premier nom qui appelle ensuite les mots suivants
char* conjugueN1(noeud_nom nodeN,noeud_adj nodeA, noeud_verbe nodeV, noeud_nom nodeN2){


    char * determinant = nomconvert(nodeN).cle;
    int code = nomconvert(nodeN).code;
    determinant=concat(determinant, strlen(determinant)," ", strlen(" "));
    char* phrase = conjugueA(nodeA,nodeV,nodeN2,code);
    concat(determinant, strlen(determinant),phrase, strlen(phrase));
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




