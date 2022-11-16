//
// Created by olivi on 27/10/2022.
//
#include "ARBRES_VERBE.h"
#include "ARBRES_NOMS.h"
#include "ARBRES_ADJ.h"
#include "ARBRES_ADV.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crea_phrases.h"

int is_forme_flechie_in_node_vrb(noeud_verbe* n) //RECHERCHE DE FORMES FLECHIES DANS KE NOEUD
{
    if (n->nb_formes)
        return 1;
    return 0;
}
int count_sons_in_node_vrb(noeud_verbe* n) // COMPTE LE NOMBRE DE FILS D'UN NOM (utile plus tard pour choisir un nombre au hasard parmi le nombre de fils possible)
{
    if (n->sons[0]==NULL) // si on est sur une feuille
    {
        return 0;
    }
    int cpt=0;
    while((n->sons[cpt]->lettre>='a'&& n->sons[cpt]->lettre<='z')&& cpt!=ALPHABET-1 ) // compte le nombre de fils dans le tableau tant qu'il y en a
    {
           cpt++;
    }
    if(n->sons[cpt]->lettre=='%'&& cpt==25) // pour pouvoir compter le 'z' si jamais le tableau est plein
        return cpt+1;
    return cpt;

}

void verb_random_node(noeud_verbe *n )
{
    int next = 1; // pour savoir si on continue
    noeud_verbe *tmp = n;
    int i = rand() % count_sons_in_node_vrb(tmp); // choisir un nombre aléatoire par rapport au nombre de fils du noeud
    while (count_sons_in_node_vrb(tmp) && next == 1)// parcours de l'abre
    {
        tmp=tmp->sons[i]; // on avance
        printf("%c",tmp->lettre);
        i = rand() % count_sons_in_node_vrb(tmp); // choisir un nombre aléatoire par rapport au nombre de fils du noeud
        if (is_forme_flechie_in_node_vrb(tmp)) // Dès qu'on a une forme fléchie, on fait un pile ou face pour savoir si on reste à ce mot où on continue
        {
            next = rand() % 2;
        }
    }

}
void verb_random_tree(a_vrb t )// APPELLE CETTE FONCTION DANS LE MAIN
{

    verb_random_node(t.root);

}

int is_forme_flechie_in_node_name(noeud_nom* n)
{
    if (n->nb_formes)
        return 1;
    return 0;
}
int count_sons_in_node_name(noeud_nom* n)
{
    if (n->sons[0]==NULL)
    {
        return 0;
    }
    int cpt=0;
    while((n->sons[cpt]->lettre>='a'&& n->sons[cpt]->lettre<='z')&& cpt!=ALPHABET-1 )
    {
        cpt++;
    }
    if(n->sons[cpt]->lettre=='%'&& cpt==25)
        return cpt+1;
    return cpt;

}

void name_random_node(noeud_nom *n )
{
    int next = 1;
    noeud_nom *tmp = n;
    int i = rand() % count_sons_in_node_name(tmp);
    while (count_sons_in_node_name(tmp) && next == 1)
    {
        tmp=tmp->sons[i];
        printf("%c",tmp->lettre);
        i = rand() % count_sons_in_node_name(tmp);
        if (is_forme_flechie_in_node_name(tmp))
        {
            next = rand() % 2;
        }
    }

}
void name_random_tree(a_nom t )
{

    name_random_node(t.root);

}

int is_forme_flechie_in_node_adj(noeud_adj* n)
{
    if (n->nb_formes)
        return 1;
    return 0;
}
int count_sons_in_node_adj(noeud_adj* n)
{
    if (n->sons[0]==NULL)
    {
        return 0;
    }
    int cpt=0;
    while((n->sons[cpt]->lettre>='a'&& n->sons[cpt]->lettre<='z')&& cpt!=ALPHABET-1 )
    {
        cpt++;
    }
    if(n->sons[cpt]->lettre=='%'&& cpt==25)
        return cpt+1;
    return cpt;

}

void adj_random_node(noeud_adj* n )
{
    int next = 1;
    noeud_adj *tmp = n;
    int i = rand() % count_sons_in_node_adj(tmp);
    while (count_sons_in_node_adj(tmp) && next == 1)
    {
        tmp=tmp->sons[i];
        printf("%c",tmp->lettre);
        i = rand() % count_sons_in_node_adj(tmp);
        if (is_forme_flechie_in_node_adj(tmp))
        {
            next = rand() % 2;
        }
    }

}
void adj_random_tree(a_adj t )
{

    adj_random_node(t.root);

}

int is_forme_flechie_in_node_adv(noeud_adv *n)
{
    if (n->nb_formes)
        return 1;
    return 0;
}
int count_sons_in_node_adv(noeud_adv *n)
{
    if (n->sons[0]==NULL)
    {
        return 0;
    }
    int cpt=0;
    while((n->sons[cpt]->lettre>='a'&& n->sons[cpt]->lettre<='z')&& cpt!=ALPHABET-1 )
    {
        cpt++;
    }
    if(n->sons[cpt]->lettre=='%'&& cpt==25)
        return cpt+1;
    return cpt;

}

void adv_random_node(noeud_adv *n )
{
    int next = 1;
    noeud_adv *tmp = n;
    int i = rand() % count_sons_in_node_adv(tmp);
    while (count_sons_in_node_adv(tmp) && next == 1)
    {
        tmp=tmp->sons[i];
        printf("%c",tmp->lettre);
        i = rand() % count_sons_in_node_adv(tmp);
        if (is_forme_flechie_in_node_adv(tmp))
        {
            next = rand() % 2;
        }
    }

}
void adv_random_tree(a_adv t )
{

    adv_random_node(t.root);

}