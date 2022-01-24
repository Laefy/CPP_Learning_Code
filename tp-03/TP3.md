# TP3 - Gestion mémoire

### Mise en place

Si vous avez déjà forké et cloné le dépôt sur votre machine, assurez-vous que votre dépôt est bien à jour.
Vous pouvez suivre [ce tutoriel](https://laefy.github.io/CPP_Learning/workflow/#récupérer-les-derniers-exercices-du-cours-et-du-tp) pour le faire.
En cas de conflits, n'hésitez pas à suivre les conseils disponibles [ici](https://laefy.github.io/CPP_Learning/workflow/#résoudre-les-conflits).

Si vous n'avez pas encore forké le dépôt, vous pouvez le faire à l'aide de [cette page](https://laefy.github.io/CPP_Learning/workflow/#récupérer-le-dépôt-git-du-cours-et-des-tps).

---

### Un peu de Lore

L'exercice se déroule dans l'univers des Pokémons.

Les Pokémons sont des créatures qui peuvent être capturées par des dresseurs au moyen de Pokéballs.
Un dresseur peut avoir au maximum 6 Pokéballs sur lui.
S'il capture un Pokémon alors que son équipe est déjà complète, ce nouveau Pokémon est envoyé dans un PC.
Chaque dresseur connaît le PC vers lequel ses Pokémons sont envoyés, et un même PC peut être utilisé par différents dresseurs.

---

### Exercice

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
Si vous êtes bloqués, n'hésitez pas à utiliser les indices ci-dessous :) 

---

### Indices

**Pokemons can be constructed with their name**
- Quelle classe pourriez-vous utiliser pour stocker le nom d'un Pokémon ?

**Pokeballs are empty by default**
- Faites au plus simple ici. Le but, c'est de faire en sorte que le test passe avec le moins de code possible.

**Pokemons can be stored in Pokeballs**
- Quel est le type renvoyé par `std::make_unique<T>` ?
Déduisez-en le type de `pikachu`, puis la signature de `Pokeball::store`.

**PCs are constructed with 0 pokemon inside**
- Connaissez-vous une classe qui permet de stocker une liste d'objets et possède une fonction-membre `empty` ?
- Déduisez-en un type de retour possible pour la fonction `PC::pokemons`. N'oubliez pas que c'est du TDD, tant que ça compile et que le test passe, on peut passer à la suite.

**A Pokemon can be put inside the PC**
- Puisqu'on utilise l'opérateur `->` sur `pokemons[0]`, de quels types selon vous peuvent être les éléments de `pokemons` ?
- Sachant que le `PC` prend l'ownership des Pokémons qui sont stockés dedans, quel est le meilleur type à utiliser ?

**Trainers are constructed with their name and they know the PC where their Pokemons get sent**
- Pensez-vous que les dresseurs sont propriétaires de l'instance de `PC` qui leur est passé en paramètre ?

**Trainers start with 6 empty pokeballs**
- Cherchez sur cppreference une classe permettant de créer des conteneurs de taille fixe.

**A Pokemon knows its trainer**
- Pensez-vous qu'un Pokémon soit propriétaire de son dresseur ? Idéalement, comment devriez-vous du coup stocker l'information du dresseur de chaque Pokémon ?
- Sachant qu'un Pokémon peut ne pas avoir de dresseur (lorsqu'il n'est pas capturé), que pourriez-vous utiliser à la place ?

**A trainer can retrieve their Pokemons from the PC**
- Recherchez sur cppreference comment supprimer un élément du conteneur que vous avez utilisé pour stocker les Pokémons dans le PC.
Lorsque vous allez sur la documentation d'une fonction ou d'une classe, il faut toujours commencer par regarder les exemples.

---

Céline Noël, Victor Marsault, Mathias Weller  
C++ Master 1    
2021 - 2022
