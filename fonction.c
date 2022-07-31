#include<stdio.h>
#include<stdlib.h>
#include"fonction.h"
#include<time.h>

void tri_insertion(int *tab,int n){
    int i,j,min;
    for(i=0;i<=n-1;i++){
        min = tab[i];
        j = i-1;
        while( j>=0 && min < tab[j]){
            tab[j+1] = tab[j];
            j = j-1 ;
        }
        tab[j+1] = min;
    }
}

void tri_selection(int *t,int n){
    int i,j,min,temp;
    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if( t[min] < t[j]){
                min = j;
            }
        }
        temp = t[i];
        t[i] = t[min];
        t[min] = temp;
    }
}

void triFusion(int i, int j, int *tab, int *tmp) {
    if(j <= i){ return;}
    int m = (i + j) / 2;
    
    triFusion(i, m, tab, tmp);     //trier la moitié gauche récursivement
    triFusion(m + 1, j, tab, tmp); //trier la moitié droite récursivement
    int pg = i;     //pg pointe au début du sous-tableau de gauche
    int pd = m + 1; //pd pointe au début du sous-tableau de droite
    int c;          //compteur
// on boucle de i à j pour remplir chaque élément du tableau final fusionné
    for(c = i; c <= j; c++) {
        if(pg == m + 1) { //le pointeur du sous-tableau de gauche a atteint la limite
            tmp[c] = tab[pd];
            pd++;
        }else if (pd == j + 1) { //le pointeur du sous-tableau de droite a atteint la limite
            tmp[c] = tab[pg];
            pg++;
        }else if (tab[pg] < tab[pd]) { //le pointeur du sous-tableau de gauche pointe vers un élément plus petit
            tmp[c] = tab[pg];
            pg++;
        }else {  //le pointeur du sous-tableau de droite pointe vers un élément plus petit
            tmp[c] = tab[pd];
            pd++;
        }
    }
    for(c = i; c <= j; c++) {  //copier les éléments de tmp[] à tab[]
        tab[c] = tmp[c];
    }
}
void tri_bulle(int *t,int n){
    int permute,i,temp,cop;
    cop = n;
    do{
        permute =0;
        for(i=0;i<cop-1;i++){
            if(t[i] > t[i+1]){
                temp=t[i];
                t[i] =t[i+1];
                t[i+1]=temp;
                permute = 1;
            }
        }
        cop = cop -1;
    }while(permute != 0);
}

int partition(int *t, int a, int b) {
    int pivot, i, temp;
    pivot = a;
    for(i=a+1;i<=b;i++){
        if(t[i] < t[pivot]){
            temp=t[i];
            t[i]=t[pivot+1];
            t[pivot+1] = t[pivot];
            t[pivot]=temp;
            pivot=pivot+1;
        }
    }
    return pivot;
}

void tri_rapide(int *t,int a,int b){
    int pivot;
    if(b>a){
        pivot = partition(t,a,b);
        tri_rapide(t,a,pivot-1);
        tri_rapide(t,pivot+1,b);
    }

}
void recherche_sequentielle(int *tab,int n,int x){
    int i;
    for(i=0;i<n;i++){
        if(tab[i] == x){
            break;
        }
    }
    if(i<=n){
        printf("%d appartient  as notre tableau \n",x);
    }
    else{
        printf("%d n'appartient pas as notre tableau \n",x);
    }
}

void recherche_sequentielle_sentinelle(int *tab,int n,int x){
    int i=0;
    tab[n] = x;
    while( tab[i] != x){
       i++;
    }
    if(i == n){
        printf("%d n'appartient pas as notre tableau \n",x);
    }
    else{
        printf("%d appartient  as notre tableau et se trouve as la position %d des indices du tableau \n",x,i);
    }
}

void recherche_dichotomique(int *t,int n,int x){
    int v_i=0,v_f=n-1,pos=-1,milieu=0;
    do{
        milieu = (v_f+v_i)/2;
        if(t[milieu] > x){
            v_f = milieu -1 ;
        }
        else{
            if(t[milieu] < x){
                v_i = milieu +1 ;
            }
            else{
                pos = milieu;
                break;
            }
        }
        
    }while(v_i <= v_f );
    if(pos != -1){
        printf("%d appartient  as notre tableau et se trouve as la position %d\n",x,pos);
    }
    else{
        printf("%d n'appartient pas as notre tableau \n",x);
    }
}

void tri_bitonnique(int * tab,int n){
	int i,tmp,test=0;

	do{
		test=0;
		for(i=0 ;i <=n-2 ; i=i+2){
			if(tab[i] > tab[i+1]){ 
				tmp=tab[i];
				tab[i]=tab[i+1];
				tab[i+1]=tmp;
				test=1;
			}	
		}
		for(i=1 ;i <=n-2 ; i=i+2){
			if(tab[i] > tab[i+1]){ 
			tmp=tab[i];
			tab[i]=tab[i+1];
			tab[i+1]=tmp;
			test=1;
			}	
		}

	}while(test == 1);
}	

void affichage(int n,int*tab){
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",tab[i]);
	}
	printf("\n");
}

int* new_tab(int n){
    srand(time(NULL));
    int *tab = malloc(sizeof(int)*n); 
    int MAX=20, MIN=0,i;
    for(i=0;i<n;i++){
        tab[i] = (rand() % (MAX - MIN + 1)) + MIN;
    }
    return tab;
}

int* nou_tab(int n){
    int *tab = malloc(sizeof(int)*n); 
    int i;
    for(i=0;i<n;i++){
        printf("element %d : ",i);
        scanf("%d",&tab[i]);
    }
    return tab;
}

int index_premier(int *tab,int n,int x){
    int i;
    for(i=0;i<n;i++){
        if(tab[i] == x){
            break;
        }
    }
    return i;
}

int index_dernier(int *tab,int n,int x){
    int i;
    for(i=n;i>=0;i--){
        if(tab[i] == x){
          break; 
        }
    }
    return i+1;
}

int nombre_occurence(int *tab,int n,int x){
    int i,cp=0;
    for(i=0;i<n;i++){
        if(tab[i] == x){
          cp = cp+1;  
        }
    }
    return cp;
}