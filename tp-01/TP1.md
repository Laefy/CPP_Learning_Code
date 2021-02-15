# TP1 - Introduction au C++


## Exercice 1 - Compilation et exécution

1. Quels sont les avantages et désavantages d'un langage dit "*compilé*" (C, C++, Pascal) ou "*semi-compilé*" (Java) comparé à un langage dit "*interpreté*" (Python, PHP, Javascript, etc) ?
2. Quelle est la différence entre une erreur de compilation et une erreur d'exécution ? (à quel moment se produisent-elles?, dans quelles circonstances, comment les identifier?, comment les corriger?, ...)
3. Que signifie en pratique l'expression "*undefined behavior*" (UB) ? Peut-on compiler un programme contenant du code classifié UB par le standard ? Si oui, que peut-il se produire au moment de son exécution ?


## Exercice 2 - Primitives et initialisation

En C++, il existe plein de syntaxes différentes pour initialiser une variable de type primitif (int, char, bool, ...) :

```cpp
int v;       // pas d'initialisation            -> valeur indéfinie
int v = 2;   // initialisation avec '= value'   -> value
int v {};    // initialisation avec '{}'        -> tous les bits à 0
int v { 2 }; // initialisation avec '{ value }' -> value
int v(2);    // initialisation avec '(value)'   -> value
```

1. Parmi les lignes suivantes, lesquelles déclenchent des erreurs de compilation ? Quelles sont ces erreurs et comment les corriger ?\
Mêmes questions en ajoutant l'option `-Werror` à la compilation.\
Vous pouvez utiliser [CompilerExplorer](https://www.godbolt.org/z/rPPoro) pour tester la compilation de petits snippets de code.

```cpp
short s0;
int   i1 = 2;
bool  b2{false};
bool  b3{i1};
bool* b4;
unsigned       u5{0x10};
unsigned short us6 = -10;
unsigned long  ul7{b3 + u5 + us6};
char c8{"a"};
char c9 = -10;
double  d10{i1};
double* d11{d10};
double& d12;
const double d13{.0f};
const int    i14 = i1;
int* i15 = &i1;
int* i16 = &b2;
int  i17 = *i15;
int& i18{i14};
const int* i19{nullptr};
const bool b20;
```

2. Pouvez-vous donner la valeur de `s0` ? De `*i15` ? De `ul7` ?


## Exercice 3 - Les fonctions et leurs paramètres

1. Remplacez les `XX` par les bons types, de manière à ce que le programme compile et affiche `42`.

```cpp
#include <iostream>

XX add(XX a, XX b) {
  return a + b;
}

XX add_to(XX a, XX b) {
  a += b;
}

XX another_add_to(XX a, XX b) {
  *a += b;
}

int main() {
  const int x{10};
  int y = add(x, x);
  another_add_to(&y, y);
  add_to(y, 2);
  std::cout << y << std::endl;

  return 0;
}
```

2. En C++, vous pouvez passer vos paramètres par valeur, par référence et par référence constante.
Quelles sont les différences entre ces différentes méthodes de passage ?
Dans quels contextes est-il préférable de passer par valeur ? Par référence ? Et par référence constante ?

3. Modifiez les signatures des fonctions suivantes de manière à ce que le passage de paramètres soit le plus efficace et sécurisé possible.
Vous pouvez vous aidez des commentaires pour comprendre comment les fonctions utilisent leurs paramètres.
```cpp
// Return the number of occurrences of 'a' found in string 's'.
int count_a_occurrences(std::string s);

// Update function of a rendering program.
// - dt (delta time) is read by the function to know the time elapsed since the last frame.
// - errors is a string filled by the function to indicate what errors have occured.
void update_loop(const float& dt, std::string* errors_out);

// Return whether all numbers in 'values' are positive.
// If there are negative values in it, fill the array 'negative_indices_out' with the indices
// of these values and set its size in 'negative_count_out'.
// ex: auto res = are_all_positive({ 1, -2, 3, -4 }, negative_indices, &negative_count);
//    -> res is false, since not all values are positive
//    -> negative_indices contains { 1, 3 } because values[1] = -2 and values[3] = -4
//    -> negative_count is 2
bool are_all_positives(std::vector<int> values, int* negative_indices_out, size_t* negative_count_out);

// Concatenate 'str1' and 'str2' and return the result.
// The input parameters are not modified by the function.
std::string concatenate(char* str1, char* str2);
```


## Exercice 4 - `std::string` et `std::vector`

1. Ecrivez un programme qui utilise `std::cin` pour lire une variable de type `std::string`, puis calcule et affiche pour chaque lettre miniscule ('a', 'b', ..., 'z') le nombre des fois où elle apparaît.\
Le comptage des lettres se fera dans une fonction `count_lower` prenant une chaîne de caractères en paramètre et renvoyant un `std::vector<unsigned int>`. La première case du tableau contiendra le nombre d'occurences de 'a', la seconde de 'b', etc.\
Vous afficherez ce tableau dans une seconde fonction `display_lower_occ`.\
Essayez d'utiliser les signatures qui rendront votre programme le plus efficace possible.

2. Modifiez le programme pour que l'utilisateur puisse entrer plusieurs chaînes de caractères, jusqu'à ce qu'il entre la chaîne "QUIT".\
Vous afficherez en plus des occurrences la concaténation de toutes les chaînes de caractères renseignées par l'utilisateur.


## Exercice 5 - Traducteur malade

Dans la vie, on se retrouve souvent face à du code tout pourri qu'il faut débugguer. Afin de vous préparer psychologiquement aux tourments de votre futur métier de programmeur, vous allez devoir corriger le code du programme que vous trouverez dans le dossier `tp-01` du dépôt https://github.com/Laefy/CPP_Learning_Code/.

---

Ce programme consiste en un traducteur, censé s'utiliser comme suit :
```b
# Ajoute une nouvelle traduction au dictionnaire dict.txt (il est créé s'il n'existe pas).
./translator -d path/to/dict.txt -a chat cat

# Utilise le dictionnaire dict.txt pour traduire la phrase "le chat est beau"
./translator -d path/to/dict.txt le chat est beau
```

Voici le format attendu pour le fichier dict.txt :
```b
bonjour hello
cheval horse
tu you
```
---

1. Pour commencer, essayez de faire en sorte que le programme compile. Un indice : si seulement on pouvait bannir les char*.

2. Une fois que le programme compile, essayez de le lancer, afin de constater que le programme est bourré de bug.\
Placez un breakpoint sur la première ligne du `main`, lancez le programme en mode debug et itérez d'instruction en instruction, tout en inspectant le contenu des variables.\
Cela vous permettra d'identifier d'où viennent les problèmes pour réussir à les corriger.

> Dans VSCode, vous pouvez placer des breakpoints avec F9, lancer un programme en mode debug via F5 (il faut modifier le fichier launch.json pour passer des arguments au programme), exécuter l'instruction courante avec F10, entrer dans un appel de fonction avec F11 et en sortir avec Shift+F11. Afin de voir le contenu des variables, ouvrez le panneau d'exécution (`View > Run`) et regardez dans la section `Variables`.

> Voici la liste des types de problèmes que trouverez dans le programme :
>- passage par valeur au lieu de référence,
>- mauvais usage de `std::vector`,
>- condition inversée ou au mauvais endroit.

3. Si vous parvenez à corriger tous les bugs, vous pouvez faire une dernière passe sur le programme afin de remplacer les passages par valeur coûteux par des passages par const-ref, et ajouter les `const` sur toutes les variables qui ne sont pas modifiées après leur initialisation.   

---

Céline Noël, Stéphane Vialette, Mathias Weller  
C++ Master 1    
2020 - 2021
