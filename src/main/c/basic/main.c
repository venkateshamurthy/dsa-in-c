#include "linked_list.h"
#include "linked_list_int.h"
#include "linked_list_string.h"
#include "linked_list_person.h"
#include "linked_list_name.h"

void verify_ints() {
    const int count = 6;
    ll * ints = ll_from_va(
        &ll_ints_va,
        count,
        1,2,3,4,5,6);
    ll_display(ints, "Ints", &int_to_string);
    ll_free(ints, (free_data)&free_int);
    printf("\n");
}

void verify_strings() {
    const int count = 6;
    ll * strings = ll_from_va(
        &ll_strings_va,
        count,
        "1-one","2-two", "3-three", "4-four", "5-five","6-six");
    ll_display(strings, "Strings", &string_to_string);
    ll_free(strings, (free_data) &free_string);
    printf("\n");
}

void verify_persons() {
    const int count = 6;
    ll * persons = ll_from_va(
        &ll_persons_va,
        count,
        (person){"1",10,MALE,  "999", "one"},
        (person){"2",15,FEMALE,"999", "one"},
        (person){"3",20,MALE,  "999", "one"},
        (person){"4",25,FEMALE,"999", "one"},
        (person){"5",30,MALE,  "999", "one"},
        (person){"6",35,FEMALE,"999", "one"});

    ll_display(persons, "Persons", (to_string)&person_ptr_display);
    ll_free(persons, (free_data)&free_person);
}

void verify_names() {
    const int count = 4;
    ll * names = ll_from_va(
        &ll_names_va,
        count,
        (name){"Vydya",    "Narayana", 19},
        (name){"Yajna",    "Narayana", 24},
        (name){"Indumathi","Kale",     20},
        (name){"Venkat",   "Murthy",   54});

    ll_display(names, "Names-Recursively", (to_string)&name_ptr_display);
    ll_display_iterate(names, "Names-Iteratively", (to_string)&name_ptr_display);
    ll_free(names, (free_data)&name_free);
}

int main () {
    verify_ints();
    verify_strings();
    verify_persons();
    verify_names();
}

