#include "linked_list.h"
#include "linked_list_int.h"
#include "linked_list_string.h"
#include "linked_list_person.h"

void test_ints() {
    const int count = 10;
    int data[count] = {1,2,3,4,5,6,7,8,9,10};
    ll * ints = ll_ints(count, data);
    ll_ints_display(ints);
    ll_ints_free(ints);
    printf("\n");
}

void test_strings() {
    const int count = 10;
    const char  *data[count]= {
        "1-one","2-two","3-three","4-four",
        "5-five","6-six","7-seven","8-eight",
        "9-nine","10-ten"};
    ll * strings = ll_strings(count, data);
    ll_strings_display(strings);
    ll_strings_free(strings);
    printf("\n");
}

void test_persons() {
    const int count = 6;
    const person data[count]= {
        {"name-1",10,MALE,"999", "1-one"},
        {"name-2",15,FEMALE,"999", "1-one"},
        {"name-3",20,MALE,"999", "1-one"},
        {"name-4",25,FEMALE,"999", "1-one"},
        {"name-5",30,MALE,"999", "1-one"},
        {"name-6",35,FEMALE,"999", "1-one"}
    };
    ll * persons = ll_persons(count, data);
    ll_persons_display(persons);
    ll_persons_free(persons);
}
/*
int main () {
    test_ints();
    test_strings();
    test_persons();
}*/