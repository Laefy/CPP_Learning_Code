# TP4 - Héritage

## Exercice 1 - Appels téléphoniques

Le code initial de l'exercice est dans tp-04/PhoneCalls.

1. Regardez le contenu de la classe `Phone`.\
Conceptuellement, quelle est la différence entre un attribut de type `const Person` et un attribut de type `const Person&` ?\
En pratique, qu'est-ce que cela change de stocker un attribut par référence ? Par exemple, quelle sera la position de `phone._owner` après l'exécution des instructions ci-dessous ?
```cpp
Person paul { "Paul", 3 };
Phone  phone { paul };
paul.set_position(8);
```

2. Créez une classe `HomePhone` qui hérite de `Phone`. Ajoutez le nécessaire pour que le code ci-dessous compile.
```cpp
Person paul { "Paul", 3 };
HomePhone phone { paul };
phone.ring();
```

3. Ajoutez un attribut `_position` à `HomePhone`. Faitez ensuite en sorte que, lorsque vous appelez la fonction `ring` sur un `HomePhone`, si le propriétaire
n'est pas à la même position que le téléphone, le programme affiche le message "This is the voicemail of ... Please leave a message.". 
```cpp
Person paul { "Paul", 3 };

HomePhone close_phone { paul, 3 };
close_phone.ring();					// Hi! Paul on the phone.

HomePhone far_phone { paul, -10 };
far_phone.ring();					// This is the voicemail of Paul. Please leave a message.
```

4. Comment avez-vous fait pour redéfinir le comportement de la classe ?\
Testez le code ci-dessous pour voir si vous obtenez le même résultat que celui en commentaire. Si ce n'est pas le cas, corrigez votre programme. 
```cpp
Person paul { "Paul", 3 };
HomePhone far_phone { paul, -10 };

const Phone& normal_phone = far_phone;
normal_phone.ring();				// This is the voicemail of Paul. Please leave a message.
```

5. Le programme a appelé la fonction `HomePhone::ring` sur une référence de type `Phone`.\
Par quel terme désigne-t-on ce genre d'appel ?
Comment appelle-t-on les classes sur lesquelles on peut effectuer un appel de ce type ?
Que faut-il toujours faire lorsqu'on définit ce type de classe et pourquoi ?\
Si vous n'avez pas pensé à le faire, c'est le moment de vous rattraper.

6. Créez une nouvelle classe `MobilePhone`, de manière à pouvoir écrire :
```cpp
Person paul { "Paul", 3 };
MobilePhone mobile_phone { paul };

const Phone& normal_phone = mobile_phone;
normal_phone.ring();				// Hi! Paul on the phone.
```

7. Modifiez maintenant le programme de manière à ce qu'il ne soit plus possible d'appeler le constructeur de `Phone` en dehors `Phone` ou de ses classes-fille.
```cpp
Person paul { "Paul", 3 };
Phone normal_phone { paul };		// Doesn't compile!
```

8. Est-ce que le code suivant compile ? Cela vous paraît-il normal ? Comment pouvez-vous expliquer ce résultat ?
```cpp
Person paul { "Paul", 3 };
HomePhone far_phone { paul, -10 };

const Phone normal_phone = far_phone;
normal_phone.ring();
```

9. En C++, que faut-il faire pour être tout à fait sûr qu'une classe ne puisse plus être instanciée du tout ?\
Modifiez la déclaration de `Phone::ring` pour que `Phone` ne soit plus instanciable. Comment appelle-t-on ce type de classe ?

10. Pourquoi le code ci-dessous ne compile probablement plus ?
Effectuez les modifications permettant de réinstancier des objets de type `MobilePhone`, si vous ne l'aviez pas fait à la question précédente.
```cpp
Person paul { "Paul", 3 };
MobilePhone mobile_phone { paul };
```


## Exercice 2 - Formes

Le but de cet exercice est de modéliser differentes formes géométriques afin de calculer leurs points d'intersection 
(éviter les ensembles infinis, disons pour simplifier qu'un objet ne s'intersecte pas avec lui-même).
Vous trouverez dans tp-04/Shapes les fichiers suivants:
- `point.hpp`: une classe `Point` qui permet de manipuler des points en 2D.
- `shape.hpp`: une classe purement virtuelle qui définit "l'interface" de toutes les formes géométriques. 
Remarquez bien qu'elle impose que tout **tout** `Shape` puisse intersecter une droite (une classe définie dans `line.hpp`) ainsi que n'importe quelle autre forme géométrique (`Shape`).
- `line.hpp`: une classe `Line` modélisant une droite passant par les points `first` et `last`. 
Le calcul de l'intersection de deux droites est donné.
- `line_seg.hpp`: un segment de droite (borné par les points `first` et `last`).
- `rectangle.hpp`: un rectangle qui peut déjà calculer son intersection avec d'autres formes géométriques (`Shape`). L'intersection est ici calculée en utilisant ses 4 segments. 
- `circle.hpp`: un cercle qui peut déjà calculer son intersection avec une ligne et avec un autre cercle.

0. Quel conteneur proposez-vous d'utiliser pour le retour des différentes fonctions d'intersection (`PointContainer` dans `shape.hpp`) ? 
Vous devez être capable d'appeler les fonctions `front()`, `emplace_back()`, `merge()`, et `erase()` sur ce conteneur.
<!--Trouvez un bon choix pour le container qui est retourné par les fonctions d'intersection (`PointContainer` dans `shape.hpp`).
Ce conteneur doit être capable de faire: `front()`, `emplace_back()`, `merge()`, et `erase()`. -->
1. Implémentez les fonctions nécessaires afin que test1 compile.
  - NOTE1: Il n'est pas nécessaire d'être fort en maths, pensez à utiliser les fonctions d'intersection qui sont données.
  - NOTE2: Un rectangle (`Rectangle`) peut déjà dire s'il contient un `Point` donné (fonction `point_is_inside`) ou bien enlever tous les points d'un `PointContainer` qui ne sont pas dedans (`filter_points_inside`). Cela peut être utile quand on calcule des intersections avec les segments de droite...
2. Il n'est pas très pratique que toutes les formes géométriques s'appellent "some shape" sur la sortie. Modifiez les classes (sans changer le main) pour que chaque forme géométrique affiche son propre nom et ses coordonnées. Il s'agit d'obtenir une sortie du genre : `line through (0,4) & (8,0) intersects line segment (0,0)--(10,10) in:   [(2.66667,2.66667) ]`.
3. Faites en sorte de passer tous les tests et vérifiez que toutes les intersections sont correctement calculées.
4. \[Bonus\] Vous avez probablement remarqué que l'intersection entre 2 cercles ne fonctionne pas (même si la fonction `Circle::intersect(const Circle&)` est correcte, elle semble ne pas être appelée...). Expliquez pourquoi et modifiez le code afin que l'intersection entre deux cercles fonctionne également.

## Exercice 3 - Théorie

1. Avant de tester, pensez-vous que les fonctions membres virtuelles d'une classe puissent-être `static` ? Justifiez.
2. En utilisant [`sizeof()`](https://en.cppreference.com/w/cpp/language/sizeof), comparez la taille en mémoire des classes suivantes :
```cpp
class A {
  int x;
  virtual void some_function() {}
};

class B {
  int x;
  void some_function() {}
};
```
Pourriez-vous expliquer ce que vous voyez ?

3. \[Bonus\] Qu'est-ce qu'un "upcast" et "downcast". Pourquoi ce dernier peut poser problème et comment s'en méfier en pratique ?
En particulier, quelle est la différence entre [`static_cast`](https://en.cppreference.com/w/cpp/language/static_cast) et [`dynamic_cast`](https://en.cppreference.com/w/cpp/language/dynamic_cast) ?

---

Céline Noël, Stéphane Vialette, Mathias Weller  
C++ Master 1    
2020 - 2021
