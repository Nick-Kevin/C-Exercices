#include    <stdio.h>
#include    <stdlib.h>

int main(){

    int tab[50],pos[50],neg[50];
    int n,j;
    int i,i_n=0,i_p=0;
    int som=0,prod=1;
    float moy;
    int min=0,max;
    int stable=0,temp;
puts("**************************************************************************************************************\n");
//  Création et lecture des éléments du tableau
        do{
            printf("Entrer la dimension du tableau:");
            scanf("%d",&n);
                if((n<0)||(n>50))   puts("\nLa dimension doit etre comprise entre 0 et 50.\n");
        }while((n<0)||(n>50));

        for(i=0;i<n;i++){
            printf("\nEntrer tab[%d]: ",i);
            scanf("%d",&tab[i]);
        }
puts("\n**************************************************************************************************************\n");
//  Affichage des éléments entrés
    printf("Vous avez entrez:");

        for(i=0;i<n;i++){
            printf("\n\ttab[%d]:%d",i,tab[i]);
        }
puts("\n\n**************************************************************************************************************\n");
//  Calculs et affichages de la somme, produit et moyenne des éléments du tableau
     for(i=0;i<n;i++){
            som+=tab[i];
        }
    printf("=> La somme des elements du tableau est %d.",som);

        for(i=0;i<n;i++){
            prod*=tab[i];
        }

    printf("\n=> Le produit des elements du tableau est %d.",prod);

    moy=(float)som/n;
    printf("\n=> La moyenne des elements du tableau, qui est la resolution de %d/%d, est %f.\n",som,n,moy);
puts("\n**************************************************************************************************************");
//  Inversion des éléments du tableau
    n--;
        for(i=0,j=n;(i<=(n/2))&&(j>=(n/2));i++,j--){
            tab[i]=tab[j]+tab[i];
            tab[j]=tab[i]-tab[j];
            tab[i]=tab[i]-tab[j];
        }
    puts("\nInversion des elements du tableau:");
        for(i=0;i<=n;i++){
            printf("tab[%d]:%d\n",i,tab[i]);
        }
puts("\n\n**************************************************************************************************************");
//  Séparation des valeurs positives et négatives du tableau
    for(i=0;i<n;i++){
        if(tab[i]<0)    neg[i_n++]=tab[i];
        else    if(tab[i]>0)    pos[i_p++]=tab[i];
    }
    if(pos[i_p]){
        puts("Les valeurs positives du tableau precedent:");
        for(i=0;i<i_p;i++)  printf("pos[%d]:%d\n",i,pos[i]);
    }
    if(!neg[i_n]){
        puts("Les valeurs negatives du tableau precedent:");
        for(i=0;i<i_n;i++)  printf("neg[%d]:%d\n",i,neg[i]);
    }
puts("\n**************************************************************************************************************");
//Suppression des occurrences 0
    for(i=0,j=0;j<=n;j++){
        if(tab[j]!=0)   tab[i++]=tab[j];
    }
        puts("Suppression des occurrences 0:");
        for(j=0;j<i;j++)  printf("tab[%d]:%d\n",j,tab[j]);
puts("\n**************************************************************************************************************");
//Recherche de la val min et max

    printf("n=%d",n);
    for(i=0,min=0;i<n;i++){
        if(tab[min]>tab[i]){
            tab[min]=tab[i];
            min=i;
        }
    }
    printf("La valeur minimale est %d, a la position %d\n",tab[min],min);
    for(i=0,max=0;i<n;i++){
        if(tab[max]<tab[i]){
            tab[max]=tab[i];
            max=i;
        }
    }
    printf("La valeur minimale est %d, a la position %d\n",tab[max],max);
puts("\n**************************************************************************************************************\n");
//tri a bulle 
    while(!stable){
        stable=1;
        for(;n>=0;n--){
            if(tab[n]<tab[n-1]){
                temp=tab[n];
                tab[n]=tab[n-1];
                tab[n-1]=temp;
            }
        }
        n--;
    }
    for(i=0;i<n;i++)    printf("\n\ttab[%d]:%d",i,tab[i]);
    return 0;
}
