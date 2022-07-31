#include<stdio.h>
#include<stdlib.h>
#include"fonction.h"

int main(void){
  int n,choix_operateur=0,choix_remplissage=0;

  printf("                                 ************************VOICI NOTRE OPERATEUR SUR LES TABLEAUX***************************\n");
  printf("entrer la taille du tableau : ");
  scanf("%d",&n);
  int *tab = malloc(sizeof(int)*n);
  while(choix_remplissage != 1 && choix_remplissage != 2){
    printf(" il est possible de remplir le tableau de deux facon , faite votre choix \n 1-de facon aleatoire \n 2-par vous meme \n vous choissisez : ");
    scanf("%d",&choix_remplissage);
  }
  if(choix_remplissage == 1){
    tab = new_tab(n);
  }
  else{
    tab = nou_tab(n);
  }
  printf(" \n                           tableau \n");
  affichage(n,tab);
  printf(" \n1-tri sur les tableaux\n 2-recherche sur les tableaux\n\n");
  while(choix_operateur != 1 && choix_operateur != 2){
    printf("entrer votre choix : ");
    scanf("%d",&choix_operateur);
  }
  if( choix_operateur == 1){
    int choix_tri  ;
    printf(" 1-tri insertion \n 2-tri selection \n 3-tri as bulle \n 4-tri bitonique \n 5-tri rapide \n 6-tri fusion \t faites le choix de votre tri : ");
    scanf("%d",&choix_tri);
    while(choix_tri <=0 && choix_tri >= 7 ){
      printf("entrer votre choix : ");
      scanf("%d",&choix_tri);
    }
    switch(choix_tri){
      case 1: printf("*****************tri insertion");
        tri_insertion(tab,n);
        break;
      case 2: printf("*****************tri selection");
        tri_selection(tab,n);
        break;
      case 3: printf("*****************tri a bulle");
        tri_bulle(tab,n);
        break;
      case 4: printf("*****************tri bitonique");
        tri_bitonnique(tab,n);
        break;
      case 5:printf("*****************tri rapide");
        tri_rapide(tab,0,n-1) ;
        break;
      case 6:printf("tri fusion");
        int *temp = malloc(sizeof(int)*n);
        triFusion(0,n-1,tab,temp);          
    }
    printf(" \n                           nouveau tableau \n");
    affichage(n,tab);
  }
  else{
    int choix_recherche =-1 ,x;
    printf("entrer l'element as rechercher : ");
    scanf("%d",&x);
    printf(" 1-recherche sequentielle  \n 2-recherche sequentielle sentinelle  \n 3-recherche dichotomique  \n 4-recherche index premier occurence  \n 5-recherche index dernière occurence \n 6-recherche nombre d'occuence d'un element  \t faites le choix de votre recherche : ");
    scanf("%d",&choix_recherche);
    while(choix_recherche <=0 && choix_recherche >= 7 ){
      printf("entrer votre choix : ");
      scanf("%d",&choix_recherche);
    }
    printf("\n");
    switch(choix_recherche){
      case 1: printf("recherche sequentielle \n");
        recherche_sequentielle(tab,n,x);
        break;
      case 2: printf(" recherche sequentielle sentinelle\n");
        recherche_sequentielle_sentinelle(tab,n,x);
        break;
      case 3: printf("  recherche dichotomique\n pour cela il va dabord trier le taleau\n ");
        int choix_tri  ;
        printf(" 1-tri insertion \n 2-tri selection \n 3-tri as bulle \n 4-tri bitonique \n 5-tri rapide \n 6-tri fusion \t faites le choix de votre tri : ");
        scanf("%d",&choix_tri);
        while(choix_tri <=0 && choix_tri >= 7 ){
          printf("entrer votre choix : ");
          scanf("%d",&choix_tri);
        }
        switch(choix_tri){
          case 1: printf("*****************tri insertion\n");
            tri_insertion(tab,n);
            break;
          case 2: printf("*****************tri selection\n");
            tri_selection(tab,n);
            break;
          case 3:recherche_dichotomique(tab,n,x); printf("***************** tri a bulle\n");
            tri_bulle(tab,n);
            break;
          case 4: printf("*****************tri bitonique\n");
            tri_bitonnique(tab,n);
            break;
          case 5:printf("*****************tri rapide\n");
            tri_rapide(tab,0,n-1) ;
            break;
          case 6:printf("*****************tri fusion\n");
            int *temp = malloc(sizeof(int)*n);
            triFusion(0,n-1,tab,temp);          
        }
        printf("                            tableau trier :\n");
        affichage(n,tab);
        recherche_dichotomique(tab,n,x);
        break;
      case 4: printf("recherche index premier occurence \n");
        printf(" le premier indice de l'element %d dans le tableau est : %d \n",x,index_premier(tab,n,x));
        break;
      case 5:printf("recherche index dernière occurence\n");
        printf(" le dernier indice de l'element %d dans le tableau est : %d \n",x,index_dernier(tab,n,x)) ;
        break;
      case 6:printf("recherche nombre d'occuence d'un element\n");
        printf(" le nombre d'occurence de l'element %d dans le tablau est %d \n",x,nombre_occurence(tab,n,x));
        break;
    }
  }
    
}