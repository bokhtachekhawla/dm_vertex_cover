#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Structure pour représenter un graphe
typedef struct {
    int sommets;   // Nombre de sommets
    int aretes;    // Nombre d'arêtes
    int matriceAdj[10][10]; // Matrice d'adjacence (maximum 10 sommets pour simplification)
} Graphe;

// Fonction pour vérifier si un sous-ensemble est une couverture des sommets
bool estCouvertureSommets(Graphe *graphe, int sousEnsemble[], int k) {
    int i, j, l;
    for (i = 0; i < graphe->sommets; i++) {
        for (j = i + 1; j < graphe->sommets; j++) {
            // Vérifie si une arête existe entre i et j
            if (graphe->matriceAdj[i][j] == 1) {
                bool couvert = false;
                // Vérifie si l'un des deux sommets appartient au sous-ensemble
                for (l = 0; l < k; l++) {
                    if (sousEnsemble[l] == i || sousEnsemble[l] == j) {
                        couvert = true;
                        break;
                    }
                }
                if (!couvert) {
                    return false; // Une arête n'est pas couverte
                }
            }
        }
    }
    return true; // Toutes les arêtes sont couvertes
}

// Fonction récursive pour générer toutes les combinaisons de sommets
bool trouverCouvertureSommets(Graphe *graphe, int k, int sousEnsemble[], int debut, int profondeur) {

    if (profondeur == k) {
        // Vérifie si la combinaison actuelle est une couverture
        if (estCouvertureSommets(graphe, sousEnsemble, k)) {
            printf("Couverture trouvée : { ");
            int i;
            for ( i = 0; i < k; i++) {
                printf("S%d ", sousEnsemble[i] + 1);
            }
            printf("}\n");
            return true;
        }
        return false;
    }
    int i;
    for ( i = debut; i < graphe->sommets; i++) {
        sousEnsemble[profondeur] = i;
        if (trouverCouvertureSommets(graphe, k, sousEnsemble, i + 1, profondeur + 1)) {
            return true;
        }
    }

    return false;
}

// Fonction principale
int main() {
    Graphe graphe;
    int i, j;

    // Demande à l'utilisateur de saisir le nombre de sommets
    printf("Entrez le nombre de sommets : ");
    scanf("%d", &graphe.sommets);

    // Initialisation de la matrice d'adjacence à 0
    for (i = 0; i < graphe.sommets; i++) {
        for (j = 0; j < graphe.sommets; j++) {
            graphe.matriceAdj[i][j] = 0;
        }
    }

    // Demande à l'utilisateur de saisir les arêtes
    printf("Entrez le nombre d'arêtes : ");
    scanf("%d", &graphe.aretes);

    printf("Entrez les arêtes (format: sommet1 sommet2) :\n");
    for (i = 0; i < graphe.aretes; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graphe.matriceAdj[u-1][v-1] = 1;
        graphe.matriceAdj[v-1][u-1] = 1; // Graphe non orienté
    }

    int k;
    printf("Entrez la cardinalité de la couverture : ");
    scanf("%d", &k);

    int sousEnsemble[k];

    printf("Recherche d'une couverture des sommets de cardinalité %d...\n", k);
    if (!trouverCouvertureSommets(&graphe, k, sousEnsemble, 0, 0)) {
        printf("Aucune couverture de cardinalité %d trouvée.\n", k);
    }

    return 0;
}

