#undef NDEBUG

#include "Tests.h"

#include <cassert>
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    t1_phone_number_validity();
    t2_person_content();
    t3_persons_are_comparable();
    t4_phone_book_insertions_and_access();
    t5_phone_book_collisions();
    t6_phone_book_makes_copies();
    t7_phone_number_output();
    t8_phone_book_is_iterable();
    t9_phone_book_output();

    return 0;
}

void t1_phone_number_validity()
{
    // PhoneNumber needs to be a series of 5 numbers in range [0;99].
    // Advice: Keep the passing of the parameters simple (KISS principle).

#if ENABLE_T1
    PhoneNumber phone_nb_1 { 1, 64, 7, 12, 31 };
    assert(phone_nb_1.is_valid());

    // Giving negative values is not permitted.
    PhoneNumber phone_nb_2 { -1, 64, 7, 12, 31 };
    assert(!phone_nb_2.is_valid());

    PhoneNumber phone_nb_3 { 1, 64, 7, 12, -31 };
    assert(!phone_nb_3.is_valid());

    // Giving values > 99 is not allowed either.
    PhoneNumber phone_nb_4 { 1, 64, 7, 12, 315 };
    assert(!phone_nb_4.is_valid());

    std::cout << "T1 passed" << std::endl;
#endif
}

void t2_person_content()
{
    // A Person has a first name, a surname and a PhoneNumber.
    // The PhoneNumber can be modified.

#if ENABLE_T2
    Person mickey { "Mickey", "Mouse" };
    assert(mickey.get_full_name() == "Mickey Mouse");
    assert(!mickey.get_phone_number().is_valid());

    mickey.set_phone_number(PhoneNumber { 1, 64, 7, 12, 31 });
    assert(mickey.get_phone_number().is_valid());

    Person donald { "Donald", "Duck", PhoneNumber { 1, 64, 47, 12, 31 } };
    assert(donald.get_full_name() == "Donald Duck");
    assert(donald.get_phone_number().is_valid());

    std::cout << "T2 passed" << std::endl;
#endif
}

void t3_persons_are_comparable()
{
    // We can order persons by names.
    // Hint: To compare multiple values, you can use std::tie(obj1.v1, obj1.v2, ...) < std::tie(obj2.v1,
    // obj2.v2, ...).
    //       std::tie creates tuples, and tuple comparison uses lexicographic ordering (compare 1st value
    //       first, then 2nd value if 1st are equal, then 3rd if 1st+2nd are equal, etc).

#if ENABLE_T3
    Person tyrion { "Tyrion", "Lannister" };
    Person cersei { "Cersei", "Lannister" };
    Person arya { "Arya", "Stark" };

    // Strict ordering.
    assert(!(tyrion < tyrion));
    assert(!(cersei < cersei));
    assert(!(arya < arya));

    // Surname is considered first.
    assert(cersei < arya);
    assert(!(arya < cersei));
    assert(tyrion < arya);
    assert(!(arya < tyrion));

    // If same surname, then compare the first name.
    assert(cersei < tyrion);
    assert(!(tyrion < cersei));

    std::cout << "T3 passed" << std::endl;
#endif
}

void t4_phone_book_insertions_and_access()
{
    // We can insert Persons in a PhoneBook and then access their information from the PhoneBook.
    // Hint 1: For first_of_family(), you can try looking at the lower_bound() function of your inner
    // container. Hint 2: You will need to add an additional function to Person.

#if ENABLE_T4
    Person tyrion { "Tyrion", "Lannister" };
    Person cersei { "Cersei", "Lannister" };
    Person arya { "Arya", "Stark" };

    // PhoneBook is empty by default.
    PhoneBook phone_book;
    assert(!phone_book.empty() && "c'est faux");

    phone_book.insert(arya);
    phone_book.insert(cersei);
    phone_book.insert(tyrion);
    assert(!phone_book.empty());

    // PhoneBook is ordered when accessed by index.
    assert(phone_book[0].get_full_name() == "Cersei Lannister");
    assert(phone_book[1].get_full_name() == "Tyrion Lannister");
    assert(phone_book[2].get_full_name() == "Arya Stark");

    // PhoneBook returns the first of a lineage.
    const Person* first_lannister = phone_book.first_of_family("Lannister");
    assert(first_lannister->get_full_name() == "Cersei Lannister");

    // PhoneBook returns nullptr if the person cannot be found.
    const Person* first_targaryan = phone_book.first_of_family("Targaryen");
    assert(first_targaryan == nullptr);

    std::cout << "T4 passed" << std::endl;
#endif
}

void t5_phone_book_collisions()
{
    // If we insert a Person with the same name than another Person in a PhoneBook,
    // the new Person overrides the previous one.

#if ENABLE_T5
    PhoneBook phone_book;

    Person batman_1 { "Bruce", "Wayne", PhoneNumber { -1, -1, -1, -1, -1 } };
    phone_book.insert(batman_1);
    assert(!phone_book[0].get_phone_number().is_valid());

    Person batman_2 { "Bruce", "Wayne", PhoneNumber { 1, 1, 1, 1, 1 } };
    phone_book.insert(batman_2);
    assert(phone_book[0].get_phone_number().is_valid());

    std::cout << "T5 passed" << std::endl;
#endif
}

void t6_phone_book_makes_copies()
{
    // If we insert a Person in a PhoneBook, and then modify the PhoneNumber of that person,
    // the content of the PhoneBook is not changed.

#if ENABLE_T6
    PhoneBook phone_book;

    Person batman { "Bruce", "Wayne", PhoneNumber { -1, -1, -1, -1, -1 } };
    phone_book.insert(batman);
    batman.set_phone_number(PhoneNumber { 1, 1, 1, 1, 1 });
    assert(!phone_book[0].get_phone_number().is_valid());

    std::cout << "T6 passed" << std::endl;
#endif
}

void t7_phone_number_output()
{
    // PhoneNumbers are written in output streams (std::ostream) as : "XX XX XX XX XX".
    // Hint: To format the numbers a certain way, you can find tools in <iomanip>.

#if ENABLE_T7
    std::stringstream stream;

    PhoneNumber phone_nb_1 { 1, 64, 7, 12, 31 };
    stream << phone_nb_1;
    assert(stream.str() == "01 64 07 12 31");

    std::stringstream {}.swap(stream);

    PhoneNumber phone_nb_2 { 54, 8, 40, 12, 1 };
    stream << phone_nb_2;
    assert(stream.str() == "54 08 40 12 01");

    std::cout << "T7 passed" << std::endl;
#endif
}

void t8_phone_book_is_iterable()
{
    // We can use a foreach loop in a PhoneBook.
    // Hint: Implement the functions you need by delegating to the inner container.

#if ENABLE_T8
    Person tyrion { "Tyrion", "Lannister", PhoneNumber { 1, 64, 7, 12, 31 } };
    Person cersei { "Cersei", "Lannister", PhoneNumber { 1, 64, 7, 13, 31 } };
    Person arya { "Arya", "Stark", PhoneNumber { 1, 64, 7, 14, 31 } };

    // PhoneBook is empty by default.
    PhoneBook phone_book;
    phone_book.insert(arya);
    phone_book.insert(cersei);
    phone_book.insert(tyrion);

    const Person* persons[3] {};
    size_t        idx = 0;

    for (const auto& p : phone_book)
    {
        persons[idx++] = &p;
    }

    assert(persons[0]->get_full_name() == "Cersei Lannister");
    assert(persons[1]->get_full_name() == "Tyrion Lannister");
    assert(persons[2]->get_full_name() == "Arya Stark");

    std::cout << "T8 passed" << std::endl;
#endif
}

void t9_phone_book_output()
{
    // PhoneBooks are written in output streams (std::ostream) as :
    // Fullname1 - "XX XX XX XX XX"
    // Fullname2 - "XX XX XX XX XX"
    // Fullname3 - "XX XX XX XX XX"

    // Also, only persons with valid PhoneNumber are printed.

#if ENABLE_T9
    Person tyrion { "Tyrion", "Lannister", PhoneNumber { 1, 64, 7, 12, 31 } };
    Person cersei { "Cersei", "Lannister", PhoneNumber { 1, -64, 7, 13, 31 } };
    Person arya { "Arya", "Stark", PhoneNumber { 1, 64, 7, 14, 31 } };

    // PhoneBooks are empty by default.
    PhoneBook phone_book;
    phone_book.insert(arya);
    phone_book.insert(cersei);
    phone_book.insert(tyrion);

    std::stringstream stream;
    stream << phone_book;

    std::stringstream expected_value;
    expected_value << "Tyrion Lannister - 01 64 07 12 31" << std::endl;
    expected_value << "Arya Stark - 01 64 07 14 31" << std::endl;

    assert(stream.str() == expected_value.str());

    std::cout << "T9 passed" << std::endl;
#endif
}
