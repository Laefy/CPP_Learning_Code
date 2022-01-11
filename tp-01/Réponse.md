# TP1 - Introduction au C++


## Exercice 1 - Compilation et exécution

1. Un langage dit "*compilé*" est plus rapide à
exécuter mais n'est pas portable. 

2. Une erreur de compilation empêche la génération du code exécutable à partir du code source. Il peut s’agir d’une erreur de syntaxe ou de l’utilisation d’une librairie qui n’est pas accessible au compilateur. Une erreur d’exécution se produit, comme son nom l’indique, au moment de l’exécution du programme. Cette erreur peut être liée à une erreur de programmation, comme un défaut de vérification des arguments d’une fonction, ou faire partie du fonctionnement normal du programme (erreur affichée à l’utilisateur en cas de saisie erronée par exemple).

3. L'expression "*undefined behavior*" (UB) signie que le standard spécifie tout ce qui n'est pas supporté. On peut compiler un programme contenant du code classifié UB par le standard mais cela risque de ne pas fonctionner comme on l'espère.


## Exercice 2 - Primitives et initialisation

1. 
```cpp
short       s0;
const short s1;  //Uninitialized

const int i1 = 2;

bool b2{false};
bool b3{i1};    //WARNING
bool b4;

unsigned       u5{0x10};
unsigned short us6 = -10;
unsigned long  ul7{b3 + u5 + us6};

char c8{"a"}; //Invalid conversion
char c9 = -10;

double       d10{i1};
double&      d11{d10};
double&      d12;   //WARNING
const double d13{.0f};

int        i14 = i1;
int&       i15 = i1;
int&       i16 = b2;
const int& i17{i14};
```

2.**s0** et **ul7** sont indéfinis


## Exercice 3 - Les fonctions et leurs paramètres

1. 
```cpp
#include <iostream>

int add(const int a, const int b) {
    return a + b;
}

void add_to(int& a, const int b) {
    a += b;
}

void another_add_to(int* a, const int b) {
    *a += b;
}

int main() {
    const int x { 10 };
    int       y = add(x, x);
    another_add_to(&y, y);
    add_to(y, 2);
    std::cout << y << std::endl;

    return 0;
}
```

2. La passage de paramètres par valeur est le cas standard, on va juste utiliser cette valeur. Celui par référence permet de modifier le paramètre fournit et peut-être utilisé si l'on souhaite retourner plusieurs valeurs. Et le passage par référence constante est utilisé lorsqu'on veut passer des arguments qui peuvent être lourds comme des tableaux dynamiques, on passe une référence mais on ne peut pas modifier cette référence.

3. 
```cpp
// Return the number of occurrences of 'a' found in string 's'.
int count_a_occurrences(const std::string s);

// Update function of a rendering program.
// - dt (delta time) is read by the function to know the time elapsed since the last frame.
// - errors is a string filled by the function to indicate what errors have occured.
void update_loop(const float dt, std::string& errors_out);

// Return whether all numbers in 'values' are positive.
// If there are negative values in it, fill the array 'negative_indices_out' with the indices
// of these values and set its size in 'negative_count_out'.
// ex: auto res = are_all_positive({ 1, -2, 3, -4 }, negative_indices, negative_count);
//    -> res is false, since not all values are positive
//    -> negative_indices contains { 1, 3 } because values[1] = -2 and values[3] = -4
//    -> negative_count is 2
bool are_all_positives(const std::vector<int>& values, int negative_indices_out[], size_t& negative_count_out);

// Concatenate 'str1' and 'str2' and return the result.
// The input parameters are not modified by the function.
std::string concatenate(const char& str1[], const char& str2[]);
```


## Exercice 4 - `std::string` et `std::vector`

*voir letter_count.cpp*

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

1. Faire en sorte que le programme compile.

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

Dylan CANET  
C++ Master 1    
2021 - 2022