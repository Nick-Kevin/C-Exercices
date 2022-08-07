#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//rand()
// Nick aura le succès
int t[100]; // tableau pour stocker le tas
int n; // le nombre d'éléments
int m;

void afficher(){
    int i;
    for (i=0;i<n;i++)
        printf("%d\t",t[i]);
    printf("\n");
}

void afficher_complet(){
    int i;
    for (i=0;i<n;i++)
        printf("%d,",t[i]);
    printf("---");
    for (;i<m;i++)
        printf("%d,",t[i]);
    printf("\n");
}

void ajout_element(int x)
{
    int i;
    int temp;
    i = n;
    t[n++] = x; // post incrémentation
                // t[n] = x;
                // n = n + 1;

    while ((i>0)&&(t[i]<t[(i-1)/2]))
    {
        temp = t[i];
        t[i] = t[(i-1)/2];
        t[(i-1)/2] = temp;
        i = (i-1)/2;
    }
   // afficher();
}

int lecture()
{
    return t[0];
}

int extraction()
{
    int sortie;
    int i, k;
    int temp;
    sortie = t[0];
    t[0] = t[--n];   // pré-décrémentation
                     // n = n - 1;
                     // t[0] = t[n];
    i = 0;           // i -> racine
    k = 1;           // k -> fg de la racine

    // on veut placer k sur le fils le plus prioritaire

    if ((k+1<n)&&(t[k+1]<t[k]))
        k++; // le fd est prioritaire par rapport au fils gauche

    // k est l'indice du plus petit fils

    while ((k<n)&&(t[k]<t[i])) // tant qu'il y a un fils
                               // et qu'il y a un fils prioritaire par rapport à i
    {
        temp = t[k];
        t[k] = t[i];
        t[i] = temp;
        i = k;
        k = i*2+1; // k est sur le fils gauche de i
        if ((k+1<n)&&(t[k+1]<t[k]))
            k++; // le fils droit est prioritaire par rapport au fils gauche
        // k est l'indice du plus petit fils
    }

    return sortie; //renvoie la valeur de sortie et quitte le sous-programme

}

int tas_vide()
{
    if (n==0) return 1;
    else return 0;  // il n'est obligatoire de mettre 'else', car 'return' FORCE la
                    // fin de l'execution du sous-programme (fonction)
    // return (n==0);
}

void saisie()
{
    int i;
    printf("entrer le nombre d'éléments");
    scanf("%d",&m);
    for (i=0;i<m;i++){
        printf("t[%d] = ",i);
        scanf("%d",&(t[i]));
    }
    n = 0;
    afficher_complet();
}

void entassement()
{
    int i;
    for (i=0;i<m;i++){
        ajout_element(t[i]);
        afficher_complet();
    }
}

void detassement()
{
    m = n;
    while (n>0)
    {
        t[n-1] = extraction();
        afficher_complet();
    }
}

void essai_affichage()
{
    printf("nombre ; tri par tas ; autre tri ;\n");
    printf("10 ; 75 ; 60 ;\n");
    printf("11; 75 ; 67 ;\n");
}

int main()
{
    int trie[100];
    int n_trie;
    int j;
    n_trie = 0;

/*
    while(!tas_vide())
    {
        trie[n_trie++] = extraction();
    }

    for (j = 0; j<n_trie; j++)
        printf("%s%d",j==0 ? "":", ",trie[j]);
        */

    // tri par tas in situ, avec complexité O(nlog(n))
    saisie();
    entassement();
    detassement();

    essai_affichage();

}
