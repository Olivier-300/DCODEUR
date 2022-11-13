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
    if (n->sons[0]==NULL)
    {
        return 0;
    }
    int cpt=0;
    while((n->sons[cpt]->lettre>='a'&& n->sons[cpt]->lettre<='z')&& cpt!=ALPHABET-1 )
    {
       {
           printf("%c", n->sons[cpt]->lettre);
           cpt++;
       }
    }
    printf("%d\n",cpt);
    return cpt+1;

}

void verb_random_node(noeud_verbe *n )
{
    int next = 1;
    noeud_verbe *tmp=n;
    int i = rand() % count_sons_in_node(tmp);
    printf("%d RANDOM\n",i);
    printf("%c\n",tmp->lettre);
    printf("%c\n",tmp->sons[i]->lettre);
    tmp=tmp->sons[18];
    int j=0;
    while(j<ALPHABET-1 )
    {
        {
            printf("%c  ", tmp->sons[j]->lettre);
            j++;
        }
    }
    printf("%c\n",tmp->lettre);
    printf("%c\n",n->lettre);
    printf("%c\n",n->sons[18]->lettre);
    printf("%c\n",tmp->sons[0]->lettre);
    while (count_sons_in_node(tmp) && next == 1)
    {
        tmp=tmp->sons[i];
        printf("%c\n",tmp->lettre);
        i = rand() % count_sons_in_node(tmp);
        printf("%d RANDOM\n",i);
        printf("%c\n",tmp->sons[i]->lettre);
        if (is_forme_flechie_in_node(tmp))
        {
            next = rand() % 2;
        }
    }

}
void verb_random_tree(a_vrb t )
{

    verb_random_node(t.root);

}

