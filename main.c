#include "ARBRES_VERBE.h"
#include "ARBRES_NOMS.h"
#include "ARBRES_ADV.h"
#include "ARBRES_ADJ.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "crea_phrases.h"
#include "conjugue_phrases.h"

int main() {
    int c;
    a_vrb verbe =arbre_verbe();
    a_nom nom =arbre_nom();
    a_adj adj =arbre_adj();
    a_adv adv =arbre_adv();
    noeud_verbe* vrb;
    noeud_nom* name;
    noeud_nom* name1;
    noeud_adv *adverbe;
    noeud_adj* adjectif;
    char* nom1;
    char* nom2;
    char* verbe1;
    char* adj1;
    char* adv1;
    int choix;

    do{
        printf("Quelle structure voulez-vous choisir pour votre phrase?\n");
        printf("Taper 1 pour : nom - adjectif - verbe - nom\n");
        printf("Taper 2 pour : nom - `qui` - verbe - verbe - nom - adjectif\n");
        printf("Taper 3 pour : nom - `n'` - verbe - `pas` - adverbe - nom - adjectif\n");
        printf("Taper 4 pour rechercher un mot dans l'arbre.\n");
        printf("Taper 5 pour quitter le menu.\n");

        scanf("%d",&c);
    }while(c<1 || c>5);
    switch (c)
    {
        case 1:

            printf("Veuillez attendre nous cuisinons votre phrase non conjuguee.\n");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".\n");
            Sleep(1000);
            nom1=name_random_tree(nom);
            nom2=name_random_tree(nom);
            adj1=adj_random_tree(adj);
            verbe1=verb_random_tree(verbe);
            printf("%s - %s - %s -%s\n", nom1, adj1, verbe1,nom2);
            name = get_l_flechie_nom(nom,nom1);
            name1 = get_l_flechie_nom(nom,nom2);
            vrb = get_l_flechie_vrb(verbe,verbe1);
            adjectif = get_l_flechie_adj(adj,adj1);
            printf("%s %s\n",conjugueN1(*name,*adjectif,*vrb,*name1), conjugueN2(*name1));
            Sleep(1000);

            printf("Voici votre phrase !\n");


            break;
        case 2:
            printf("Veuillez attendre nous cuisinons votre phrase non conjugee.\n");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".\n");
            Sleep(1000);
            printf("%s - qui - %s - %s -%s - %s\n", name_random_tree(nom), verb_random_tree(verbe), verb_random_tree(verbe),name_random_tree(nom),
                   adj_random_tree(adj));
            Sleep(1000);
            printf("Voici votre phrase !\n");
            break;
        case 3:
            printf("Veuillez attendre nous cuisinons votre phrase non conjuguee.\n");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".\n");
            Sleep(1000);
            printf("%s - `n'` - %s - `pas` - %s -%s - %s\n", name_random_tree(nom), verb_random_tree(verbe), adv_random_tree(adv),name_random_tree(nom),
                   adj_random_tree(adj));
            Sleep(1000);
            printf("Voici votre phrase !\n");
            break;

        case 4:
            printf("Voulez vous rechercher :\n1- Un nom?\n2- Un verbe ?\n3- Un adjectif ?\n4- Ou bien un adverbe ?\n");
            scanf("%d",&choix);
            while(c<1 || c>4){
                printf("Voulez vous rechercher :\n 1- Un nom?\n2- Un verbe ?\n3- Un adjectif ?\n4- Ou bien un adverbe ?");
                scanf("%d",&choix);
            }
            switch (choix)
            {

                case 1:

                    printf("veuillez rentrez un mot à recherche : \n");
                    char nommm[24];
                    scanf("%s",nommm);
                    recherche_mot_nom(nom.root,nommm);
                    break;

                case 2:
                    printf("veuillez rentrez un mot à recherche : \n");
                    char mot[24];
                    scanf("%s",mot);
                    recherche_mot_vrb(verbe.root,mot);
                    break;

                case 3:
                    printf("Veuillez entre un mot à rechercher :\n");
                    char ajd[24];
                    scanf("%s",ajd);
                    recherche_mot_adj(adj.root,ajd);
                    break;

                case 4:
                    printf("Veuillez entre un mot à rechercher :\n");
                    char adverbeee[24];
                    scanf("%s",adverbeee);
                    recherche_mot_adv(adv.root,adverbeee);
                    break;

            }

        case 5:
            printf("Merci pour votre attention.\n");
            break;
    }

}