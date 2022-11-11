//
// Created by olivi on 27/10/2022.
//
#include "ARBRES_VERBE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crea_phrases.h"
int is_forme_flechie_in_node(noeud_verbe* n)
{
    if (n->nb_formes)
        return 1;
    return 0;
}
int count_sons_in_node(noeud_verbe* n)
{
    int cpt=0;
    while(n->sons[cpt]!=NULL)
        cpt++;
    if (cpt==0)
        return 0;
    return cpt;

}

void verb_random_node(noeud_verbe* n )
{
    int next = 1;
    int i = rand() % count_sons_in_node(n);

    while (count_sons_in_node(n) && next == 1)
    {
        n=n->sons[i];
        printf("%c",n->lettre);
        i = rand() % count_sons_in_node(n);
        if (is_forme_flechie_in_node(n))
        {
            next = rand() % 2;
        }
    }

}
void verb_random_tree(a_vrb* t )
{
    verb_random_node(t->root);
}

