#ifndef __PROTOTYPE__H__
#define __PROTOTYPE__H__

void tri_insertion(int *tab,int n);
void recherche_sequentielle(int *tab,int n,int x);
void recherche_dichotomique(int *tab,int n,int x);
void recherche_sequentielle_sentinelle(int *tab,int n,int x);
int* new_tab(int n);
int* nou_tab(int n);
void affichage(int n,int*tab);
void tri_selection(int *t,int n);
void tri_bulle(int *t,int n);
int fusion (int inf, int mid, int sup, int *tab);
void tri_fusion(int inf, int sup, int *tab);
void triFusion(int i, int j, int *tab, int *tmp);
void tri_rapide(int *t,int a,int b);
int partition(int *t, int a, int b);
void tri_bitonnique(int * tab,int n);
int index_premier(int *tab,int n,int x);
int index_dernier(int *tab,int n,int x);
int nombre_occurence(int *tab,int n,int x);
#endif
