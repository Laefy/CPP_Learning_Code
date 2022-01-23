# TP3 - Gestion mémoire

L'objectif de cette séance est de vous faire manipuler les relations d'ownership entre les objets d'un programme, tout en continuant à vous familiariser avec l'usage des `unique_ptr`.

Le TP sera à réaliser en utilisant la méthodologie TDD.
Vous avez de la chance, tous les tests sont déjà écrits dans le fichier Tests.cpp (le framework utilisé est [Catch2](https://github.com/catchorg/Catch2/tree/v2.x)).
Pour avancer, il faudra donc :
- décommenter le prochain `TEST_CASE` (ou la prochaine `SECTION` si le `TEST_CASE` en contient plusieurs),
- ajouter les fonctionnalités nécessaires pour faire en sorte que le programme compile,
- modifier vos implémentations jusqu'à ce que le bloc de tests décommenté passe,
- commiter vos changements.

Faites attention à bien respecter l'ordre de ces étapes et à ne pas avancer trop vite, vous risqueriez de vous empêtrer dans un tas de bugs autrement.\
Autre conseil, n'hésitez pas à faire le minimum syndical pour que les tests passent.
Par exemple, si vous n'avez que le test `fonction_qui_a_lair_super_complique() == true` à faire passer, vous pouvez très bien écrire :
```cpp
void fonction_qui_a_lair_super_complique() { return true; } // ce n'est pas de la triche, au contraire
```
puis passez à l'étape suivante.

Dernier petit point avant de commencer, il est **INTERDIT** de modifier le code des tests.
La seule chose que vous devriez avoir besoin de faire dans le fichier `Tests.cpp`, c'est commenter ou décommenter des lignes.

Bon courage à vous !

---

Céline Noël, Victor Marsault, Mathias Weller  
C++ Master 1    
2021 - 2022
