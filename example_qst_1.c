
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
        for (j = 0; j < graphe->sommets; j++) {
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
void trouverCouvertureSommets(Graphe *graphe, int k, int sousEnsemble[], int debut, int profondeur) {
    if (profondeur == k) {
        // Vérifie si la combinaison actuelle est une couverture
        if (estCouvertureSommets(graphe, sousEnsemble, k)) {
            int i;
            printf("Couverture trouvée : { ");
            for ( i = 0; i < k; i++) {
                printf("S%d ", sousEnsemble[i] + 1);
            }
            printf("}\n");
        }
        return;
    }
    int i;

    for ( i = debut; i < graphe->sommets; i++) {
        sousEnsemble[profondeur] = i;
        trouverCouvertureSommets(graphe, k, sousEnsemble, i + 1, profondeur + 1);
    }
}

// Fonction principale
int main() {
    Graphe graphe;
    int i, j;

    // Initialisation du graphe (matrice d'adjacence)
    graphe.sommets = 5;
    graphe.aretes = 6;
    int matriceAdj[5][5] = {
        {0, 0, 1,0 , 1}, // S1 connecté à S3, S5
        {0, 0, 1, 0, 1}, // S2 connecté à S3,S5
        {0, 1, 0, 1, 1}, // S3 connecté à S2, S4, S5
        {0, 0, 1, 0, 1}, // S4 connecté à S3, S5
        {1, 1,0, 1, 0}  // S5 connecté à S1, S4,S2
    };

    for (i = 0; i < graphe.sommets; i++) {
        for (j = 0; j < graphe.sommets; j++) {
            graphe.matriceAdj[i][j] = matriceAdj[i][j];
        }
    }

    int k = 2; // Cardinalité de la couverture
    int sousEnsemble[k];

    printf("Recherche des couvertures des sommets de cardinalité %d...\n", k);
    trouverCouvertureSommets(&graphe, k, sousEnsemble, 0, 0);

    return 0;
}

