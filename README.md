# **Problème de Couverture de Sommets**

Ce projet propose une solution au problème de couverture de sommets en utilisant une approche de force brute. Le problème de couverture de sommets est un problème classique en informatique et en théorie des graphes, où le but est de trouver un sous-ensemble minimal de sommets tel que chaque arête du graphe soit incidente à au moins un sommet du sous-ensemble.

## **Table des Matières**
1. [Fichiers](#fichiers)
2. [Structure du Projet](#structure-du-projet)
3. [Comment Cloner le Projet](#comment-cloner-le-projet)
4. [Comment Exécuter le Code](#comment-exécuter-le-code)
5. [Exemple d'Utilisation](#exemple-dutilisation)

---

## **Fichiers**

- `example_qst_1.c` : Contient une implémentation exemple du problème de couverture de sommets avec un graphe prédéfini.
- `vertex_cover.c` : Contient une implémentation du problème de couverture de sommets où l'utilisateur peut entrer le graphe et la cardinalité de la couverture de sommets.

## **Structure du Projet**

vscode/ ├── c_cpp_properties.json ├── launch.json ├── settings.json 
example_qst_1.c 
vertex_cover.c

## **Comment Cloner le Projet**

1. **Vérifiez que Git est installé** :
   - Vérifiez si Git est installé en exécutant :
     ```bash
     git --version
     ```
     Si ce n’est pas le cas, téléchargez et installez Git depuis [le site officiel de Git](https://git-scm.com/).

2. **Clonez le dépôt** :
   - Exécutez la commande suivante dans votre terminal :
     ```bash
     git clone https://github.com/bokhtachekhawla/projet-complexite.git
     ```

3. **Accédez au répertoire** :
   ```bash
   cd projet-complexite



## **Comment Exécuter le Code**

1. **Compiler le Code** : Utilisez un compilateur C comme `gcc` pour compiler le code. Par exemple :
    ```sh
    gcc -o vertex_cover vertex_cover.c
    ```

2. **Exécuter l'Exécutable** : Après la compilation, exécutez l'exécutable :
    ```sh
    ./vertex_cover
    ```

3. **Entrer le Graphe** : Suivez les instructions pour entrer le nombre de sommets, d'arêtes et les arêtes elles-mêmes.

4. **Entrer la Cardinalité** : Entrez la cardinalité de la couverture de sommets que vous souhaitez trouver.


## **Exemple d'Utilisation**

Pour [example_qst_1.c](http://_vscodecontentref_/5), le graphe est prédéfini et le programme recherchera des couvertures de sommets d'une cardinalité spécifiée.

Pour [vertex_cover.c](http://_vscodecontentref_/6), le programme vous demandera d'entrer les détails du graphe et la cardinalité de la couverture de sommets.

### Exemple d'Entrée pour [vertex_cover.c](http://_vscodecontentref_/7)
Entrez le nombre de sommets : 5 Entrez le nombre d'arêtes : 6 Entrez les arêtes (format: sommet1 sommet2) : 1 3 1 5 2 3 2 5 3 4 4 5 Entrez la cardinalité de la couverture : 2


### Exemple de Sortie

Recherche d'une couverture des sommets de cardinalité 2... Couverture trouvée : { S1 S3 }
