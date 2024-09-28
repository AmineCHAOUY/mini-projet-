#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const int MAX_BOOK = 100;
    char titres[MAX_BOOK][50];
    char auteurs[MAX_BOOK][50];
    char titrerecherche[50];
    int nbLivres = 0;
    int quantite[MAX_BOOK];
    float prix[MAX_BOOK];
    int choix;

    do {
        printf("\033[0;33m\n=== Menu ===\n\033[0m");
        printf("\033[0;34m1. Ajouter un livre\n\033[0m");
        printf("\033[0;34m2. Afficher tous les livres\n\033[0m");
        printf("\033[0;34m3. Modifier un livre\n\033[0m");
        printf("\033[0;34m4. Supprimer un livre\n\033[0m");
        printf("\033[0;34m5. Afficher le nombre total de livres en stock\n\033[0m");
        printf("\033[0;34m6. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        if (choix == 1 && nbLivres < MAX_BOOK) {

                printf("Entrez le titre du livre : ");
                scanf(" %49[^\n]", titres[nbLivres]);
                printf("Entrez l'auteur du livre : ");
                scanf(" %49[^\n]", auteurs[nbLivres]);
                printf("Entrez le prix du livre : ");
                scanf("%f", &prix[nbLivres]);
                printf("Entrez la quantité en stock : ");
                scanf("%d", &quantite[nbLivres]);
                nbLivres++;}
             else {
                printf("Stock plein. Impossible d'ajouter plus de livres.\n");
            }


        if (choix == 2) {
            if (nbLivres == 0) {
                printf("\033[0;31mIl n'y a aucun livre disponible.\033[0m\n");
            } else {
                printf("\033[0;32mListe des livres disponibles:\033[0m\n");
                for (int i = 0; i < nbLivres; i++) {
                    printf("Titre : %s, Auteur : %s, Prix : %.2f, Quantité : %d\n",
                           titres[i], auteurs[i], prix[i], quantite[i]);
                }
            }
        }

        if (choix == 3) {
            printf("Entrez le titre du livre à rechercher : ");
            scanf(" %49[^\n]", titrerecherche);
            int trouve = 0;
            for (int i = 0; i < nbLivres; i++) {
                if (strcmp(titres[i], titrerecherche) == 0) {
                    printf("Livre trouvé :\nTitre : %s\nAuteur : %s\nPrix : %.2f\nQuantité : %d\n",
                           titres[i], auteurs[i], prix[i], quantite[i]);
                    trouve = 1;
                    break;
                }
            }
            if (!trouve) {
                printf("Livre non trouvé.\n");
            }
        }


        if (choix == 4) {
                printf("Entrez le titer du liver à supprimer ");
        scanf("%49[^\n]",titrerecherche);
        int trouv =0;
        for (int i=0;i<nbLivres;i++){
          if(strcmp(titres[i],titrerecherche)==0){
                for (int j=0;j<nbLivres-1;j++){
                  strcpy (titres[j],titres[j+1]);
                  strcpy (auteurs[j],auteurs[j+1]);
                  prix[j]=prix[j+1];
                  quantite[j]=quantite[j+1];
                }
                nbLivres--;
                printf("Livre supprimé avec succès.\n");
                    trouv = 1;
                    break;
               }
              }
              if (!trouv) {
                printf("Livre non trouvé.\n");
              }
        }

        if (choix == 5) {
                printf("Il y a %d livres en stock.\n", nbLivres);
        if (nbLivres==0){
            printf("\033[0;31mDésolé, aucun livre disponible.\033[0m\n");
        }else {
        printf("Nombre total de livres en stock : %d\n", nbLivres);
        }


        }

    } while (choix != 6);

    printf("Au revoir!\n");
return 0;
}