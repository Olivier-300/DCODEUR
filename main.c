#include "ARBRES_VERBE.h"
#include "ARBRES_NOMS.h"
#include "ARBRES_ADV.h"
#include "ARBRES_ADJ.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crea_phrases.h"

int main() {
    int c;
    a_adj adjectif=arbre_adj();
    /*char test[]="stabiliser";
    char cpie[]="stabiliser";
    ajouter_mot(&verbe.root,test,cpie);*/
    /*do{
        printf("Quelle structure voulez-vous choisir pour votre phrase?\n");
        printf("Taper 1 pour : nom - adjectif - verbe - nom\n");
        printf("Taper 2 pour : nom - `qui` - verbe - verbe - nom - adjectif\n");
        printf("Taper 3 pour : nom - `n'` - verbe - `pas` - adverbe - nom - adjectif\n");
        scanf("%d",&c);
    }while(c<1 || c>3);
    switch (c)
    {
        case 1:
            printf("Taper 1 pour : nom - adjectif - verbe - nom\n");
            verb_random_tree( verbe );
            break;
        case 2:
            printf("Taper 2 pour : nom - `qui` - verbe - verbe - nom - adjectif\n");
            break;
        case 3:
            printf("Taper 3 pour : nom - `n'` - verbe - `pas` - adverbe - nom - adjectif\n");
            break;
    }*/
}