#include "ARBRES_VERBE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crea_phrases.c"
#include "crea_phrases.h"
int main() {
    int c;

    do{
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

            break;
        case 2:
            printf("Taper 2 pour : nom - `qui` - verbe - verbe - nom - adjectif\n");
            break;
        case 3:
            printf("Taper 3 pour : nom - `n'` - verbe - `pas` - adverbe - nom - adjectif\n");
            break;
    }
}