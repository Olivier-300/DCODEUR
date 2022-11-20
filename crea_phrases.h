//
// Created by olivi on 27/10/2022.
//

#ifndef DCODEUR_CREA_PHRASES_H
#define DCODEUR_CREA_PHRASES_H

void Color(int couleurDuTexte,int couleurDeFond);

noeud_verbe* get_l_flechie_vrb(a_vrb,char*);
noeud_nom * get_l_flechie_nom(a_nom,char*);
noeud_adj* get_l_flechie_adj(a_adj,char*);
noeud_adv* get_l_flechie_adv(a_adv,char*);

int is_forme_flechie_in_node_vrb(noeud_verbe*);
int count_sons_in_node_vrb(noeud_verbe*);
char* verb_random_node(noeud_verbe*);
char* verb_random_tree(a_vrb);

int is_forme_flechie_in_node_name(noeud_nom*);
int count_sons_in_node_name(noeud_nom*);
char*  name_random_node(noeud_nom*);
char*  name_random_tree(a_nom);

int is_forme_flechie_in_node_adj(noeud_adj*);
int count_sons_in_node_adj(noeud_adj*);
char* adj_random_node(noeud_adj*);
char* adj_random_tree(a_adj);

int is_forme_flechie_in_node_adv(noeud_adv*);
int count_sons_in_node_adv(noeud_adv*);
char* adv_random_node(noeud_adv*);
char* adv_random_tree(a_adv);

void recherche_mot_vrb(noeud_verbe* noeud, char* mot);
void recherche_mot_adj(noeud_adj * noeud, char* mot);
void recherche_mot_nom(noeud_nom * noeud, char* mot);
void recherche_mot_adv(noeud_adv * noeud, char* mot);

void recherche_flechie_vrb(a_vrb, char*);
void recherche_flechie_nom(a_nom, char*);
void recherche_flechie_adj(a_adj, char*);

#endif //DCODEUR_CREA_PHRASES_H
