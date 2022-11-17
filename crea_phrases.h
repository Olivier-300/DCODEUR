//
// Created by olivi on 27/10/2022.
//

#ifndef DCODEUR_CREA_PHRASES_H
#define DCODEUR_CREA_PHRASES_H
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

#endif //DCODEUR_CREA_PHRASES_H
