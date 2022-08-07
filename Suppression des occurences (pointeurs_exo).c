#include <stdio.h>
#include <stdlib.h>

int main(){
    int dim;
    printf("Entrer la dimension de votre tableau: ");
    scanf("%d", &dim);

    int tab[dim];
    int *p1,*p2;
    printf("\n\tEntrer les elements du tableau:");
    for(p1=tab; p1<tab+dim; p1++){
        printf("\n\ttab[%d] = ",p1-tab);
        scanf("%d",p1);
    }
    printf("\nVous avez entrer: ");
    for(p1=tab; p1<tab+dim; p1++){
        printf("\n\ntab[%d] = %d",p1-tab,*p1);
    }

    int cmp=0;
    while(cmp==0){
        cmp=1;
        for(p1=p2=tab; (p2<=tab+dim); p2++,p1++,dim--){
            if(p2=0){
                p1 = p2;
                cmp=0;
            }
        }
    }
    for(p1=tab; p1<tab+dim; p1++){
        printf("\n\ntab[%d] = %d",p1-tab,*p1);
    }
    return 0;
}