//
// Created by olivi on 20/11/2022.
//

#include "menu.h"
#include <windows.h>
#include <time.h>


void menu(){
    srand(time(NULL));
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
        Color(11,0);
        printf("Bienvenue sur DCODEUR le generateur de phrases !\n\n");
        printf("Quelle structure voulez-vous choisir pour votre phrase?\n");
        printf("Taper 1 pour : nom - adjectif - verbe - nom\n");
        printf("Taper 2 pour : nom - `qui` - verbe - verbe - nom - adjectif\n");
        printf("Taper 3 pour : nom - `n'` - verbe - `pas` - adverbe - nom - adjectif\n");
        printf("Taper 4 pour rechercher un mot dans l'arbre.\n");
        printf("Taper 5 pour avoir la description d'un mot.\n");
        printf("Taper 6 pour pouvoir ajouter un nom a un l'arbre.\n");
        printf("Taper 7 pour quitter le menu.\n");

        scanf("%d",&c);
    }while(c<1 || c>7);
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
            Color(10,0);
            printf("\n%s - %s - %s -%s\n\n", nom1, adj1, verbe1,nom2);
            Color(11,0);
            /*name = get_l_flechie_nom(nom,nom1);
            name1 = get_l_flechie_nom(nom,nom2);
            vrb = get_l_flechie_vrb(verbe,verbe1);
            adjectif = get_l_flechie_adj(adj,adj1);
            printf("%s %s\n",conjugueN1(*name,*adjectif,*vrb,*name1), conjugueN2(*name1));*/
            Sleep(1000);

            printf("Voici votre phrase !\n");
            menu();


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
            Color(10,0);
            printf("\n%s - qui - %s - %s -%s - %s\n\n", name_random_tree(nom), verb_random_tree(verbe), verb_random_tree(verbe),name_random_tree(nom),
                   adj_random_tree(adj));
            Color(11,0);
            Sleep(1000);
            printf("Voici votre phrase !\n");
            menu();
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
            Color(10,0);
            printf("\n%s - `n'` - %s - `pas` - %s -%s - %s\n\n", name_random_tree(nom), verb_random_tree(verbe), adv_random_tree(adv),name_random_tree(nom),
                   adj_random_tree(adj));
            Color(11,0);
            Sleep(1000);
            printf("Voici votre phrase !\n");
            menu();
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
                    menu();
                    break;

                case 2:
                    printf("veuillez rentrez un mot à recherche : \n");
                    char mot[24];
                    scanf("%s",mot);
                    recherche_mot_vrb(verbe.root,mot);
                    menu();
                    break;

                case 3:
                    printf("Veuillez entre un mot à rechercher :\n");
                    char ajd[24];
                    scanf("%s",ajd);
                    recherche_mot_adj(adj.root,ajd);
                    menu();
                    break;

                case 4:
                    printf("Veuillez entre un mot à rechercher :\n");
                    char adverbeee[24];
                    scanf("%s",adverbeee);
                    recherche_mot_adv(adv.root,adverbeee);
                    menu();
                    break;

            }

        case 5:

            printf("Vous souhaitez rechercher dans quelle categorie ?\n1-Vebre ?\n2-Nom ?\n3-Adjectif ?\n");
            int decision;
            scanf("%d",&decision);
            while(decision<1 || decision>3){
                printf("Vous souhaitez rechercher dans quelle categorie ?\n1-Vebre ?\n2-Nom ?\n3-Adjectif ?\n");
                scanf("%d",&decision);
            }
            switch (decision) {

                case 1:
                    printf("Veuillez rentrer un verbe conjugue a etudier.\n");
                    char word[24];
                    scanf("%s",word);
                    recherche_flechie_vrb(verbe,word);
                    menu();
                    break;
                case 2:
                    printf("Veuillez rentrer un nom accorde a etudier.\n");
                    char nomnom[24];
                    scanf("%s",nomnom);
                    recherche_flechie_nom(nom,nomnom);
                    menu();
                    break;
                case 3:
                    printf("Veuillez rentrer un adjectif accorde a etudier.\n");
                    char adjadj[24];
                    scanf("%s",adjadj);
                    recherche_flechie_adj(adj,adjadj);
                    menu();
                    break;
            }
            break;



        case 6:
            printf("Voulez vous ajouter un : 1- Un nom ?\n2- Un verbe ?\n3- Un adverbe ?\n4- Un adjectif ?\n");
            int add_choice;
            char add_word[24];
            char copie_mot[24];
            scanf("%d",&add_choice);
            while(add_choice<1 || add_choice>4){
                printf("Voulez vous ajouter un :\n1- Un nom ?\n2- Un verbe ?\n3- Un adverbe ?\n4- Un adjectif ?\n");
                scanf("%d",&add_choice);
            }

            switch (add_choice) {


                case 1:
                    printf("\nVeuillez saisir le nom a ajouter\n");
                    scanf("%s",add_word);
                    strcpy(copie_mot,add_word);
                    printf("Veuillez attendre pendant que nous ajoutons %s à l'arbre.\n",add_word);
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf(".\n");
                    Sleep(1000);
                    ajouter_mot_nom(&nom.root,add_word,copie_mot);
                    printf("%s a ete ajoute avec succes !\n\n",copie_mot);
                    menu();
                    break;

                case 2:
                    printf("\nVeuillez saisir le verbe a ajouter\n");
                    scanf("%s",add_word);
                    strcpy(copie_mot,add_word);
                    printf("Veuillez attendre pendant que nous ajoutons %s à l'arbre.\n",add_word);
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf(".\n");
                    Sleep(1000);
                    ajouter_mot(&verbe.root,add_word,copie_mot);
                    printf("%s a ete ajoute avec succes !\n\n",copie_mot);
                    menu();
                    break;

                case 3:
                    printf("\nVeuillez saisir l'adverbe a ajouter\n");
                    scanf("%s",add_word);
                    strcpy(copie_mot,add_word);
                    printf("Veuillez attendre pendant que nous ajoutons %s à l'arbre.\n",add_word);
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf(".\n");
                    Sleep(1000);
                    ajouter_mot_adv(&adv.root,add_word,copie_mot);
                    printf("%s a ete ajoute avec succes !\n\n",copie_mot);
                    menu();

                    break;

                case 4:
                    printf("\nVeuillez saisir l'adverbe a ajouter\n");
                    scanf("%s",add_word);
                    strcpy(copie_mot,add_word);
                    printf("Veuillez attendre pendant que nous ajoutons %s à l'arbre.\n",add_word);
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf(".\n");
                    Sleep(1000);
                    ajouter_mot_adj(&adj.root,add_word,copie_mot);
                    printf("%s a ete ajoute avec succes !\n\n",copie_mot);
                    menu();
                    break;
            }

        case 7:
            printf("Merci pour votre attention.\n");
            break;
    }
}