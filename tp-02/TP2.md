
# TP2 - Les Classes en C++

## Exercice 1 - Classes et instances

1. Le code suivant permet de calculer une somme d'entiers de manière un peu originale. Quelles sont les deux valeurs affichées à la fin ?
```cpp
#include <iostream>

struct AddX
{
  static int global_sum;
  const int _x;
  
  AddX(const int x) : _x{x}
  {}
    
  void apply() const { global_sum += _x; }
};

int AddX::global_sum = 0; // initialisation

int main()
{
  AddX add10{10}, add5{5};
  add10.apply();
  add5.apply();

  AddX add1{1};
  add1.apply();
  add1.apply();
  
  std::cout << add5.global_sum << std::endl << add1.global_sum << std::endl;
  return 0;
}
```

2. Que se passe si on enlève la ligne marquée "initialisation" ?

## Exercice 2 - Copies

1. Dans l'exercice 4 du TP1, on vous avait demandé de programmer une fonction qui comptait le nombre d'occurrences de chaque lettre dans une string. Vous allez maintenant réimplémenter ce programme, mais au moyen de la classe `Histogram` ci-dessous :
```cpp
class Histogram
{
public:
  void analyze(const std::string&);       // analyse la string passée en paramètre
  void print() const;                     // affiche l'histogramme
  
private:
  std::vector<unsigned int> _count;       // tableau contenant le nombre d'occurrences de chaque lettre entre 'a' et 'z'
};
```

Attention, pour l'initialisation de `_count`, vous essayerez d'utiliser un in-class initializer.\
Pourquoi n'est-il pas possible d'initialiser avec `= { 26, 0 }` ? Que devez-vous écrire à la place ?

2. Ajoutez un constructeur de copie à votre classe et placez-y des instructions d'affichage (`std::cout`).\
Si votre programme ne compile plus, expliquez pourquoi et résolvez le problème.

3. Dans le code suivant, selon vous, combien de fois le constructeur de copie sera appelé ?\
Exécutez le code pour vérifier votre théorie. Recherchez ensuite sur Internet le concept de `copy-elision`.
```cpp
Histogram h1, h2;
Histogram h3 { Histogram { h1 } };
```

## Exercice 3 - Rappels d'événements !

Vous allez implémenter un petit programme permettant d'enregistrer des rappels d'événements et de déclencher ces rappels au bout d'une certaine durée.

Dans un premier temps, implémentons l'horloge permettant de compter des secondes et minutes.

1. Implémentez une classe `MinuteHand` (aiguille des minutes) qui contient un `int _minutes` avec son getter `get_minutes()`.\
   Ajoutez-lui une fonction `void advance()` qui permet d'incrémenter le nombre de minutes.\
   Ecrivez enfin le code permettant de tester votre classe et vérifiez que tout fonctionne.
   
2. Implémentez une classe `SecondHand` (aiguille des secondes) qui contient un `int _seconds` avec son getter `get_seconds()`.\
   Ajoutez-lui également un attribut `MinuteHand& _min_hand`, qui vous initialiserez à partir d'un constructeur à un paramètre `SecondHand(MinuteHand&)`.
   De la même manière que pour la classe précédente, ajoutez-lui une fonction `void advance()` qui permet d'incrémenter le nombre de secondes.
   Lorsque celui-ci atteint 60, remettez-le à 0 et avancez l'aiguille des minutes.\
   Modifiez votre code de test afin de vérifier que votre classe `SecondHand` fonctionne correctement.
   
3. Définissez une classe `Clock` qui contient un attribut de type `SecondHand` et un attribut de type `MinuteHand`.\
   Implémentez son constructeur et testez que le programme compile correctement.
   
4. Ajoutez ensuite une fonction `void tick()`, dont le but sera de faire avancer le temps d'une seconde.\
   Implémentez ensuite un opérateur de flux (`operator<<`) afin d'afficher l'heure au format `x min y sec` et vérifiez que si vous appeler 63x `tick()`, vous obtenez bien `1 min 3 sec`.
   
Maintenant, on veut utiliser cette horloge pour déclencher des rappels d'événements. Ces événements sont passés en arguments du programme de la manière suivante :
```shell
./reminders "8:05 Il faut se lever" "21:59 Il faut envoyer le questionnaire du cours"
```

5. Prenez connaissance de l'implémentation de la classe `Event` qui contient un message à afficher
   ansi qu'un `Time` (`std::pair` de deux entiers) indiquant le temps (en secondes et minutes) à laquelle la notification doit apparaitre.
   Rajoutez une fonction membre `notify_time(int current_min, int current_sec)` à la classe `Event` qui,
   si le moment du rappel est arrivé, imprime dans la console le message de l'événement et renvoie `true`, autrement, elle renvoie `false`.
   
6. Ajoutez à la classe `Clock` un attribut `std::vector<Event> _events` qui contient tous les événements à traiter.
   Implémentez une fonction `add_event(const Event&)` qui rajoute un événement donné à `_events`.\
   Dans le `main`, utilisez la fonction `parse_events` déjà implémentée pour ajouter les événements dans votre horloge.
   
7. Dans la fonction `Clock::tick`, appelez `notify_time` sur tous les événements contenus dans `_events`.\
   Si la fonction renvoie `true`, arrangez-vous pour retirer l'événement du tableau.
   
Testez votre nouveau système de notifications !

8. **Bonus** Pourquoi `std::vector` n'est-il pas le meilleur conteneur pour stocker les événements ?
   En recherchant sur https://en.cppreference.com/w/cpp/container, proposez une nouvelle implémentation qui s'avérerait plus efficace.

---

Céline Noël, Stéphane Vialette, Mathias Weller  
C++ Master 1    
2020 - 2021
