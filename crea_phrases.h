//
// Created by olivi on 27/10/2022.
//

#ifndef DCODEUR_CREA_PHRASES_H
#define DCODEUR_CREA_PHRASES_H
int is_forme_flechie_in_node_vrb(noeud_verbe*);
int count_sons_in_node_vrb(noeud_verbe*);
void verb_random_node(noeud_verbe*);
void verb_random_tree(a_vrb);

int is_forme_flechie_in_node_name(noeud_nom*);
int count_sons_in_node_name(noeud_nom*);
void name_random_node(noeud_nom*);
void name_random_tree(a_nom);

int is_forme_flechie_in_node_adj(noeud_adj*);
int count_sons_in_node_adj(noeud_adj*);
void adj_random_node(noeud_adj*);
void adj_random_tree(a_adj);

int is_forme_flechie_in_node_adv(noeud_adv*);
int count_sons_in_node_adv(noeud_adv*);
void adv_random_node(noeud_adv*);
void adv_random_tree(a_adv);
#endif //DCODEUR_CREA_PHRASES_H
