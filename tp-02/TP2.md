
# TP2 - Les Classes en C++

## Exercice 1 - Classes et instances

1. Le code suivant permet de calculer une somme d'entiers de manière un peu originale. Quelles sont les deux valeurs affichées à la fin ?
```cpp
#include <iostream>

struct AddX {
  static int global_sum;
  const int _x;
  
  AddX(const int x) : _x{x}
  {}
    
  void apply() const { global_sum += _x; }
};

int AddX::global_sum = 0; // initialisation

int main() {
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

## Exercice 2 - Construction et destruction

1. Dans l'exercice 4 du TP1, on vous avait demandé de programmer une fonction qui comptait le nombre d'occurrences de chaque lettre dans une string. Vous allez maintenant réimplémenter ce programme, mais au moyen de la classe `Histogram` ci-dessous :
```cpp
class Histogram {
public:
  Histogram();                            // constructeur
  Histogram(const Histogram&);            // constructeur de copie
  ~Histogram();                           // destructeur
  
  Histogram& operator=(const Histogram&); // opérateur d'assignation par copie
  
  void analyze(const std::string&);       // analyse la string passée en paramètre
  void print() const;                     // affiche l'histogramme
  
private:
  unsigned* _count;                       // tableau contenant le nombre d'occurrences de chaque lettre entre 'a' et 'z'
};
```

La classe `Histogram` devra se charger d'allouer et libérer la mémoire pour le tableau `_count`.

2. Placez des instructions d'affichage dans les constructeurs et destructeur de la classe `Histogram`.\
Exécutez le code suivant. Dans quel ordre sont évalués les appels de chaque constructeur ? Même question pour les destructeurs.
```cpp
Histogram h1,h2;
Histogram h3{Histogram{h1}};
```

3. Si on enlève la définition du constructeur de copie, est-ce que le code ci-dessus compile toujours ? Si oui, que va-t-il se passer au moment de l'exécution ?

[//]: # (## Exercise 3 - Construction et Affectation)
[//]: # (1. Informez-vous et expliquez les trois concepts "Rule of Zero/Three/Five"!)
[//]: # (2. Informez-vous et expliquez le concept "Copy-And-Swap"!)

## Exercice 3 - Rappels d'événements !

Vous allez implémenter un petit programme permettant d'enregistrer des rappels d'événements et de déclencher ces rappels au bout d'une certaine durée.

Dans un premier temps, implémentons l'horloge permettant de compter des secondes et minutes.

1. Implémentez une classe `MinuteHand` (aiguille des minutes) qui contient un `int _minutes` avec son getter `get_minutes()`.
2. Implémentez une classe `SecondHand` (aiguille des secondes) qui contient un `int _seconds` avec son getter `get_seconds()`.
   Ajoutez également un attribut `MinuteHand& _min_hand`, que vous initialiserez à partir d'un constructeur `SecondHand(MinuteHand&)`.\
   Notez que lorsqu'une classe possède une référence pour attribut, le compilateur ne peut plus générer l'implémentation par défaut du constructeur par défaut.
3. Rajoutez une fonction `void advance()` à `SecondHand` et `MinuteHand` qui incrémente leur compteur respectif.
   De plus, si le nombre de secondes passe à 60, remettez-les à 0 et faites en sorte d'incrémenter le nombre de minutes.
4. Implémentez une classe `Clock` qui contient un attribut de type `SecondHand` et une attribut de type `MinuteHand`,
   ansi qu'une fonction `tick()` permettant de faire avancer le temps d'une seconde.
   Pensez bien à "connecter" `SecondHand` avec `MinuteHand` pour que, quand les secondes dépassent 59, `MinuteHand` puisse avancer.
   **Felicitations** - vous devriez avoir une horloge qui marche :)

Maintenant, on veut utiliser cette horloge pour déclencher des rappels d'événements. Ces événements sont passés en arguments du programme de la manière suivante :
```shell
./reminders "8:05 Il faut se lever" "21:59 Il faut envoyer le questionnaire du cours"
```

5. Prenez connaissance de l'implémentation de la classe `Event` qui contient un message à afficher
   ansi qu'un `Time` (`std::pair` de deux entiers) indiquant le temps (en secondes et minutes) à laquelle la notification doit apparaitre.
   Rajoutez une fonction membre `notify_time(int current_min, int current_sec)` qui,
   si le moment du rappel est arrivé, imprime dans la console le message de l'événement et renvoie `true`, autrement, elle renvoie `false`.
6. Augmentez la fonctionalité de `Clock` en rajoutant un `std::vector<Event> _events` qui contient tout les événements à traiter.
   Implémentez une fonction `add_event(const Event&)` qui rajoute un événement donné à `_events`.
   Dans la fonction `tick()`, appelez `notify_time` tous les événements contenus dans `events`, et supprimez ceux dont la fonction a renvoyé `true`. 
7. Dans votre `main`, utilisez la fonction `parse_events` qui est déjà implementée pour rajouter des événements à votre `Clock`.

Testez votre nouveau système de notifications !

8. **Bonus** Est-ce que `std::vector<Event>` est vraiment un bon choix pour stocker les événements ?
   Quels problèmes voyez-vous ? Essayez de l'implémenter plus efficacement ?

---

Céline Noël, Stéphane Vialette, Mathias Weller  
C++ Master 1    
2020 - 2021
