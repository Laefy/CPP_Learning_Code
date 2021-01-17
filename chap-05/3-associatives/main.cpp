#include "keys.h"

#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using Owner = std::pair<std::string, std::string>;

void test_comparables()
{
    ComparableDog medor { "medor", "labrador" };
    ComparableDog gus { "gus", "bordercollie" };
    ComparableDog zim { "zim", "poodle" };
    ComparableDog flippy { "flippy", "spaniel" };
    ComparableDog medor_clone = medor;

    std::set<ComparableDog> dogs_set;

    dogs_set.emplace(medor);
    dogs_set.emplace(gus);
    std::cout << dogs_set.size() << std::endl;

    dogs_set.emplace(medor_clone);
    std::cout << dogs_set.size() << std::endl;

    std::map<ComparableDog, Owner> owners_by_dog;

    owners_by_dog.insert(std::make_pair(medor, Owner { "Claire", "David" }));
    owners_by_dog.insert_or_assign(gus, Owner { "Marc", "Zipstein" });
    owners_by_dog.emplace(zim, Owner { "Céline", "Noël" });
    owners_by_dog.try_emplace(flippy, "Vincent", "Nozick");

    owners_by_dog.emplace(gus, Owner { "Claire", "David" });
    // -> gus is still owned by Marc (emplace does not modify values with existing keys, neither does insert
    // or try_emplace)

    owners_by_dog.insert_or_assign(gus, Owner { "Vincent", "Nozick" });
    // -> gus is now owned by Vincent (insert_or_assign reassign values with existing keys)
}

void test_hashables()
{
    HashableDog medor { "medor", "labrador" };
    HashableDog gus { "gus", "bordercollie" };
    HashableDog zim { "zim", "poodle" };
    HashableDog flippy { "flippy", "spaniel" };
    HashableDog medor_clone = medor;

    std::unordered_set<HashableDog> dogs_set;

    dogs_set.emplace(medor);
    dogs_set.emplace(gus);
    std::cout << dogs_set.size() << std::endl;

    dogs_set.emplace(medor_clone);
    std::cout << dogs_set.size() << std::endl;

    std::unordered_map<HashableDog, Owner> owners_by_dog;

    owners_by_dog.insert(std::make_pair(medor, Owner { "Claire", "David" }));
    owners_by_dog.insert_or_assign(gus, Owner { "Marc", "Zipstein" });
    owners_by_dog.emplace(zim, Owner { "Céline", "Noël" });
    owners_by_dog.try_emplace(flippy, "Vincent", "Nozick");

    owners_by_dog.emplace(gus, Owner { "Claire", "David" });
    // -> gus is still owned by Marc (emplace does not modify values with existing keys, neither does insert
    // or try_emplace)

    owners_by_dog.insert_or_assign(gus, Owner { "Vincent", "Nozick" });
    // -> gus is now owned by Vincent (insert_or_assign reassign values with existing keys)
}

int main()
{
    test_comparables();
    test_hashables();

    return 0;
}